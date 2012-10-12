<?php

/**
 * Displays a message listing the inactive fields of a given bundle.
 */
function manage_filters_ui_inactive_message($entity_type, $bundle) {
    $inactive_instances = field_ui_inactive_instances($entity_type, $bundle);
    if (!empty($inactive_instances)) {
        $field_types = field_info_field_types();

        foreach ($inactive_instances as $field_name => $instance) {
            $list[] = t('%field (@field_name) field requires the %widget_type widget provided by %widget_module module', array(
                '%field' => $instance['label'],
                '@field_name' => $instance['field_name'],
                    ));
        }
        drupal_set_message(t('Inactive fields are not shown unless their providing modules are enabled. The following fields are not enabled: !list', array('!list' => theme('item_list', array('items' => $list)))), 'error');
    }
}

/**
 * Determines the rendering order of an array representing a tree.
 *
 * Callback for array_reduce() within manage_filters_ui_table_pre_render().
 */
function _manage_filters_ui_reduce_order($array, $a) {
    $array = !isset($array) ? array() : $array;

    if ($a['name']) {
        $array[] = $a['name'];
    }
    if (!empty($a['children'])) {
        uasort($a['children'], 'drupal_sort_weight');
        $array = array_merge($array, array_reduce($a['children'], '_manage_filters_ui_reduce_order'));
    }
    return $array;
}

/**
 * Returns the region to which a row in the 'Manage filters' screen belongs.
 *
 * This function is used as a #region_callback in
 * manage_filters_ui_field_overview_form(), and is called during
 * manage_filters_ui_table_pre_render().
 */
function manage_filters_ui_filters_overview_row_region($row) {
    switch ($row['#row_type']) {
        case 'field':
            return ($row['state']['type']['#value'] == 'hidden' ? 'hidden' : 'visible');
    }
}

/**
 * Pre-render callback for manage_filters_ui_table elements.
 */
function manage_filters_ui_table_pre_render($elements) {
    $js_settings = array();

    // For each region, build the tree structure from the weight and parenting
    // data contained in the flat form structure, to determine row order and
    // indentation.
    $regions = $elements['#regions'];
    $tree = array('' => array('name' => '', 'children' => array()));
    $trees = array_fill_keys(array_keys($regions), $tree);

    $parents = array();
    $list = drupal_map_assoc(element_children($elements));

    // Iterate on rows until we can build a known tree path for all of them.
    while ($list) {
        foreach ($list as $name) {
            $row = &$elements[$name];
            $parent = $row['parent_wrapper']['parent']['#value'];
            // Proceed if parent is known.
            if (empty($parent) || isset($parents[$parent])) {
                // Grab parent, and remove the row from the next iteration.
                $parents[$name] = $parent ? array_merge($parents[$parent], array($parent)) : array();
                unset($list[$name]);

                // Determine the region for the row.
                $function = $row['#region_callback'];
                $region_name = $function($row);

                // Add the element in the tree.
                $target = &$trees[$region_name][''];
                foreach ($parents[$name] as $key) {
                    $target = &$target['children'][$key];
                }
                $target['children'][$name] = array('name' => $name, 'weight' => $row['weight']['#value']);

                // Add tabledrag indentation to the first row cell.
                if ($depth = count($parents[$name])) {
                    $children = element_children($row);
                    $cell = current($children);
                    $row[$cell]['#prefix'] = theme('indentation', array('size' => $depth)) . (isset($row[$cell]['#prefix']) ? $row[$cell]['#prefix'] : '');
                }

                // Add row id and associate JS settings.
                $id = drupal_html_class($name);
                $row['#attributes']['id'] = $id;
                if (isset($row['#js_settings'])) {
                    $row['#js_settings'] += array(
                        'rowHandler' => $row['#row_type'],
                        'name' => $name,
                        'region' => $region_name,
                    );
                    $js_settings[$id] = $row['#js_settings'];
                }
            }
        }
    }
    // Determine rendering order from the tree structure.
    foreach ($regions as $region_name => $region) {
        $elements['#regions'][$region_name]['rows_order'] = array_reduce($trees[$region_name], '_manage_filters_ui_reduce_order');
    }

    $elements['#attached']['js'][] = array(
        'type' => 'setting',
        'data' => array('fieldUIRowsData' => $js_settings),
    );

    return $elements;
}

/**
 * Returns HTML for Filters UI overview tables.
 *
 * @param $variables
 *   An associative array containing:
 *   - elements: An associative array containing a Form API structure to be
 *     rendered as a table.
 *
 * @ingroup themeable
 */
function theme_filters_ui_table($variables) {
    $elements = $variables['elements'];
    $table = array();
    $js_settings = array();

    // Add table headers and attributes.
    foreach (array('header', 'attributes') as $key) {
        if (isset($elements["#$key"])) {
            $table[$key] = $elements["#$key"];
        }
    }

    // Determine the colspan to use for region rows, by checking the number of
    // columns in the headers.
    $columns_count = 0;
    foreach ($table['header'] as $header) {
        $columns_count += (is_array($header) && isset($header['colspan']) ? $header['colspan'] : 1);
    }

    // Render rows, region by region.
    foreach ($elements['#regions'] as $region_name => $region) {
        $region_name_class = drupal_html_class($region_name);

        // Add region rows.
        if (isset($region['title'])) {
            $table['rows'][] = array(
                'class' => array('region-title', 'region-' . $region_name_class . '-title'),
                'no_striping' => TRUE,
                'data' => array(
                    array('data' => $region['title'], 'colspan' => $columns_count),
                ),
            );
        }
        if (isset($region['message'])) {
            $class = (empty($region['rows_order']) ? 'region-empty' : 'region-populated');
            $table['rows'][] = array(
                'class' => array('region-message', 'region-' . $region_name_class . '-message', $class),
                'no_striping' => TRUE,
                'data' => array(
                    array('data' => $region['message'], 'colspan' => $columns_count),
                ),
            );
        }

        // Add form rows, in the order determined at pre-render time.
        foreach ($region['rows_order'] as $name) {
            $element = $elements[$name];

            $row = array('data' => array());
            if (isset($element['#attributes'])) {
                $row += $element['#attributes'];
            }

            // Render children as table cells.
            foreach (element_children($element) as $cell_key) {
                $child = &$element[$cell_key];
                // Do not render a cell for children of #type 'value'.
                if (!(isset($child['#type']) && $child['#type'] == 'value')) {
                    $cell = array('data' => drupal_render($child));
                    if (isset($child['#cell_attributes'])) {
                        $cell += $child['#cell_attributes'];
                    }
                    $row['data'][] = $cell;
                }
            }
            $table['rows'][] = $row;
        }
    }

    return theme('table', $table);
}

/**
 * Form constructor for the filters settings.
 *
 * @see manage_filters_ui_filters_overview_multistep_submit()
 * @see manage_filters_ui_filters_overview_form_submit()
 * @ingroup forms
 */
function manage_filters_ui_filters_overview_form($form, &$form_state, $entity_type, $bundle) {
    $bundle = field_extract_bundle($entity_type, $bundle);

    manage_filters_ui_inactive_message($entity_type, $bundle);
    $admin_path = _field_ui_bundle_admin_path($entity_type, $bundle);

    // Gather type information.
    // $field_types = field_info_field_types();
    $bundle_instances = field_info_instances($entity_type, $bundle);
    $instances = array();
    foreach ($bundle_instances as $instance_name => $bundle_instance) {
        $field = field_info_field($bundle_instance['field_name']);
        if (is_field_filterable($field)) {
            $instances[$instance_name] = $bundle_instance;
        }
    }

    if (empty($instances)) {
        drupal_set_message(t('There are no filterable fields yet added. You can add suitable fields on the <a href="@link">Manage fields</a> page.', array('@link' => url($admin_path . '/fields'))), 'warning');
        return $form;
    }


    $form_state += array(
        'formatter_settings_edit' => NULL,
    );


    // Get common variable with data about filters states.
    // If variable doesn't set, all filters was taken as inactive.
    $filters = array();
    $filters_json = variable_get('facet_collection_filters');
    if (!empty($filters_json)) {
        $tmp_filters = drupal_json_decode($filters_json);
        if (isset($tmp_filters[$bundle])) {
            $filters = $tmp_filters[$bundle];
        }
    }

    $form += array(
        '#entity_type' => $entity_type,
        '#bundle' => $bundle,
        '#fields' => array_keys($instances),
    );



    $table = array(
        '#type' => 'filters_ui_table',
        '#tree' => TRUE,
        '#header' => array(
            t('Field'),
            t('Weight'),
            t('Parent'),
            t('Filter by'),
            array('data' => t('State'), 'colspan' => 3),
        ),
        '#regions' => array(
            'visible' => array('message' => t('No filter is activated.')),
            'hidden' => array('title' => t('Inactive'), 'message' => t('No filter is inactivated.')),
        ),
        '#parent_options' => array(),
        '#attributes' => array(
            'class' => array('field-ui-overview'),
            'id' => 'field-display-overview',
        ),
        // Add Ajax wrapper.
        '#prefix' => '<div id="field-display-overview-wrapper">',
        '#suffix' => '</div>',
    );


    // Filter rows.
    foreach ($instances as $name => $instance) {
        $field = field_info_field($instance['field_name']);
        if (is_field_filterable($field)) {
            if ($field['type'] == 'entityreference') {
                $filter_by_label = 'Node Reference';
            } elseif ($field['type'] == 'taxonomy_term_reference') {
                $vocabulary = taxonomy_vocabulary_machine_name_load($field['settings']['allowed_values'][0]['vocabulary']);
                $filter_by_label = 'Vocabulary ' . $vocabulary->name;
            } elseif ($field['type'] == 'datetime'
                    || $field['type'] == 'date'
                    || $field['type'] == 'datestamp') {
                $filter_by_label = 'Date';
            }
            $table[$name] = array(
                '#attributes' => array('class' => array('draggable', 'tabledrag-leaf')),
                '#row_type' => 'field',
                '#region_callback' => 'manage_filters_ui_filters_overview_row_region',
                '#js_settings' => array(
                    'rowHandler' => 'field',
                //'defaultFormatter' => $field_types[$field['type']]['default_formatter'],
                ),
                'human_name' => array(
                    '#markup' => check_plain($instance['label']),
                ),
                'weight' => array(
                    '#type' => 'textfield',
                    '#title' => t('Weight for @title', array('@title' => $instance['label'])),
                    '#title_display' => 'invisible',
                    '#default_value' => 0,
                    '#size' => 3,
                    '#attributes' => array('class' => array('field-weight')),
                ),
                'parent_wrapper' => array(
                    'parent' => array(
                        '#type' => 'select',
                        '#title' => t('Label filter for @title', array('@title' => $instance['label'])),
                        '#title_display' => 'invisible',
                        '#options' => $table['#parent_options'],
                        '#empty_value' => '',
                        '#attributes' => array('class' => array('field-parent')),
                        '#parents' => array('fields', $name, 'parent'),
                    ),
                    'hidden_name' => array(
                        '#type' => 'hidden',
                        '#default_value' => $name,
                        '#attributes' => array('class' => array('field-name')),
                    ),
                ),
                'filter_by' => array(
                    '#markup' => check_plain($filter_by_label),
                ),
            );

            $filter_states['hidden'] = t('Inactive');
            $filter_states['visible'] = t('Acvite');
            $filter_current_state = 'hidden';
            if (isset($filters[$instance['field_name']]['state'])) {
                $filter_current_state = $filters[$instance['field_name']]['state'];
            }

            $table[$name]['state'] = array(
                'type' => array(
                    '#type' => 'select',
                    '#title' => t('States for @title', array('@title' => $instance['label'])),
                    '#title_display' => 'invisible',
                    '#options' => $filter_states,
                    '#default_value' => $filter_current_state,
                    '#parents' => array('fields', $name, 'type'),
                    '#attributes' => array('class' => array('field-formatter-type')),
                ),
                'settings_edit_form' => array(),
            );

            if (isset($form_state['formatter_settings'][$name])) {
                $tmp_settings = $form_state['formatter_settings'][$name];
                $node_reference_filters_settings = array();
                foreach ($tmp_settings as $ref_type_name => $ref_filters) {
                    foreach ($ref_filters['filters'] as $ref_filter) {
                        if (!empty($ref_filter)) {
                            $node_reference_filters_settings[$ref_type_name][$ref_filter] = array();
                        }
                    }
                }
            } else {
                if (isset($filters[$name])) {
                    $node_reference_filters_settings = $filters[$name]['referenced_filters'];
                } else {
                    $node_reference_filters_settings = array();
                }
            }

            $base_button = array(
                '#submit' => array('manage_filters_ui_filters_overview_multistep_submit'),
                '#ajax' => array(
                    'callback' => 'manage_filters_ui_filters_overview_multistep_js',
                    'wrapper' => 'field-display-overview-wrapper',
                    'effect' => 'fade',
                ),
                '#field_name' => $name,
            );

            if ($form_state['formatter_settings_edit'] == $name) {
                // We are currently editing this filters's settings. Display the
                // settings form and submit buttons.
                $table[$name]['state']['settings_edit_form'] = array();

                $settings_form = manage_filters_ui_filter_settings_form($field, $node_reference_filters_settings, $form, $form_state);

                if ($settings_form) {
                    $table[$name]['state']['#cell_attributes'] = array('colspan' => 3);
                    $table[$name]['state']['settings_edit_form'] = array(
                        '#type' => 'container',
                        '#attributes' => array('class' => array('field-formatter-settings-edit-form')),
                        '#parents' => array('fields', $name, 'settings_edit_form'),
                        'label' => array(
                            '#markup' => t('Filter settings:') . ' <span class="formatter-name">' . $instance['label'] . '</span>',
                        ),
                        'settings' => $settings_form,
                        'actions' => array(
                            '#type' => 'actions',
                            'save_settings' => $base_button + array(
                        '#type' => 'submit',
                        '#name' => $name . '_formatter_settings_update',
                        '#value' => t('Update'),
                        '#op' => 'update',
                            ),
                            'cancel_settings' => $base_button + array(
                        '#type' => 'submit',
                        '#name' => $name . '_formatter_settings_cancel',
                        '#value' => t('Cancel'),
                        '#op' => 'cancel',
                        // Do not check errors for the 'Cancel' button, but make sure we
                        // get the value of the filter state select.
                        '#limit_validation_errors' => array(array('fields', $name, 'type')),
                            ),
                        ),
                    );
                    $table[$name]['#attributes']['class'][] = 'field-formatter-settings-editing';
                }
            } else {
                // Display a summary of the current formatter settings.
                $summary = manage_filters_ui_filter_settings_summary($field, $node_reference_filters_settings, $form_state, $filters);
                $table[$name]['settings_summary'] = array();
                $table[$name]['settings_edit'] = array();
                if ($summary) {
                    $table[$name]['settings_summary'] = array(
                        '#markup' => '<div class="field-formatter-summary">' . $summary . '</div>',
                        '#cell_attributes' => array('class' => array('field-formatter-summary-cell')),
                    );
                    $table[$name]['settings_edit'] = $base_button + array(
                        '#type' => 'image_button',
                        '#name' => $name . '_formatter_settings_edit',
                        '#src' => 'misc/configure.png',
                        '#attributes' => array('class' => array('field-formatter-settings-edit'), 'alt' => t('Edit')),
                        '#op' => 'edit',
                        // Do not check errors for the 'Edit' button, but make sure we get
                        // the value of the 'formatter type' select.
                        '#limit_validation_errors' => array(array('fields', $name, 'type')),
                        '#prefix' => '<div class="field-formatter-settings-edit-wrapper">',
                        '#suffix' => '</div>',
                    );
                }
            }
        }
    }



    $form['fields'] = $table;

// In overviews involving nested rows from contributed modules (i.e
// field_group), the 'format type' selects can trigger a series of changes in
// child rows. The #ajax behavior is therefore not attached directly to the
// selects, but triggered by the client-side script through a hidden #ajax
// 'Refresh' button. A hidden 'refresh_rows' input tracks the name of
// affected rows.
    $form['refresh_rows'] = array('#type' => 'hidden');
    $form['refresh'] = array(
        '#type' => 'submit',
        '#value' => t('Refresh'),
        '#op' => 'refresh_table',
        '#submit' => array('manage_filters_ui_filters_overview_multistep_submit'),
        '#ajax' => array(
            'callback' => 'manage_filters_ui_filters_overview_multistep_js',
            'wrapper' => 'field-display-overview-wrapper',
            'effect' => 'fade',
            // The button stays hidden, so we hide the Ajax spinner too. Ad-hoc
// spinners will be added manually by the client-side script.
            'progress' => 'none',
        ),
    );

    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save'));

    $form['#attached']['js'][] = drupal_get_path('module', 'field_ui') . '/field_ui.js';
    $form['#attached']['css'][] = drupal_get_path('module', 'field_ui') . '/field_ui.css';

// Add tabledrag behavior.
    $form['#attached']['drupal_add_tabledrag'][] = array('field-display-overview', 'order', 'sibling', 'field-weight');
    $form['#attached']['drupal_add_tabledrag'][] = array('field-display-overview', 'match', 'parent', 'field-parent', 'field-parent', 'field-name');

    return $form;
}

/**
 * Return filter settings 
 */
function manage_filters_ui_filter_settings_form($field, $ref_filters, $form, &$form_state) {
    $filterable_fields = get_referenced_filterable_fields($field);
    foreach ($filterable_fields as $ref_type => $filters_list) {
        $chosen_filters = array();
        foreach ($filters_list as $filter_name => $filter) {
            if (isset($ref_filters[$ref_type])) {
                if (array_key_exists($filter_name, $ref_filters[$ref_type])) {
                    array_push($chosen_filters, $filter_name);
                }
            }
        }
        $form[$ref_type] = array(
            '#type' => 'fieldset',
            '#title' => t('Filters for content type ' . $ref_type),
        );
        $form[$ref_type]['filters'] = array(
            '#type' => 'checkboxes',
            '#options' => $filters_list,
            '#default_value' => $chosen_filters,
            '#title' => t('Choose fields for filtering'),
        );
    }
    $context = array(
        'field' => $field,
            //'instance' => $instance,
    );
    drupal_alter('manage_filters_ui_filter_settings_form', $form, $form_state, $context);
    return $form;
}

/**
 * Return filter settings summary  
 */
function manage_filters_ui_filter_settings_summary($field, $ref_filters, $form_state, $filters) {
    $summary = "";
    if (is_filters_settings_visible($filters, $form_state, $field)) {
        if (empty($ref_filters)) {
            $summary = 'No filters are chosen';
        } else {
            $summary = "";
            foreach ($ref_filters as $ref_type_name => $ref_type_filters) {
                $filters = '';
                foreach ($ref_type_filters as $filter_name => $ref_filter) {
                    $instance = field_info_instance("node", $filter_name, $ref_type_name);
                    if ($instance) {
                        $filters = $filters . $instance['label'] . ", ";
                    }
                }
                $filters = substr($filters, 0, strlen($filters) - 2);
                $summary = $summary . "Filters for content type " . $ref_type_name . ": " . $filters . "<br>";
            }
        }
    }
    return $summary;
}

/**
 * Form submission handler for buttons in manage_filters_ui_filters_overview_form().
 */
function manage_filters_ui_filters_overview_multistep_submit($form, &$form_state) {
    $trigger = $form_state['triggering_element'];
    $op = $trigger['#op'];

    switch ($op) {
        case 'edit':
// Store the field whose settings are currently being edited.
            $field_name = $trigger['#field_name'];
            $form_state['formatter_settings_edit'] = $field_name;
            break;

        case 'update':
// Store the saved settings, and set the field back to 'non edit' mode.
            $field_name = $trigger['#field_name'];
            $values = $form_state['values']['fields'][$field_name]['settings_edit_form']['settings'];
            $form_state['formatter_settings'][$field_name] = $values;
            unset($form_state['formatter_settings_edit']);
            break;

        case 'cancel':
// Set the field back to 'non edit' mode.
            unset($form_state['formatter_settings_edit']);
            break;

        case 'refresh_table':
// If the currently edited field is one of the rows to be refreshed, set
// it back to 'non edit' mode.
            $updated_rows = explode(' ', $form_state['values']['refresh_rows']);
            if (isset($form_state['formatter_settings_edit']) && in_array($form_state['formatter_settings_edit'], $updated_rows)) {
                unset($form_state['formatter_settings_edit']);
            }
            break;
    }

    $form_state['rebuild'] = TRUE;
}

/**
 * Ajax handler for multistep buttons on the 'Manage filters' screen.
 */
function manage_filters_ui_filters_overview_multistep_js($form, &$form_state) {
    $trigger = $form_state['triggering_element'];
    $op = $trigger['#op'];
// Pick the elements that need to receive the ajax-new-content effect.
    switch ($op) {
        case 'edit':
            $updated_rows = array($trigger['#field_name']);
            $updated_columns = array('state');
            break;

        case 'update':
        case 'cancel':
            $updated_rows = array($trigger['#field_name']);
            $updated_columns = array('state', 'settings_summary', 'settings_edit');
            break;

        case 'refresh_table':
            $updated_rows = array_values(explode(' ', $form_state['values']['refresh_rows']));
            $updated_columns = array('settings_summary', 'settings_edit');
            break;
    }

    foreach ($updated_rows as $name) {
        foreach ($updated_columns as $key) {
            $element = &$form['fields'][$name][$key];
            $element['#prefix'] = '<div class="ajax-new-content">' . (isset($element['#prefix']) ? $element['#prefix'] : '');
            $element['#suffix'] = (isset($element['#suffix']) ? $element['#suffix'] : '') . '</div>';
        }
    }

// Return the whole table.
    return $form['fields'];
}

/**
 * Form submission handler for manage_filters_ui_filters_overview_form().
 */
function manage_filters_ui_filters_overview_form_submit($form, &$form_state) {

    $form_values = $form_state['values'];
    $bundle = $form['#bundle'];
    $content_type_filters = array();
    //Get current version of filter list for clean facet_collection_filters_settings up 
    //from current bundle
    //variable_del('facet_collection_filters_settings');
    //variable_del('facet_collection_filters');
    $facet_filters = drupal_json_decode(variable_get('facet_collection_filters'));
    $facet_filters_settings = drupal_json_decode(variable_get('facet_collection_filters_settings'));

    //Get changed filters settings from forms
    if (!empty($form_values['fields'])) {
        foreach ($form_values['fields'] as $field_name => $field) {
            $values = $form_values['fields'][$field_name];
            // Get filters settings. They lie either directly in submitted form
            // values (if the whole form was submitted while some filter
            // settings were being edited), or have been persisted in
            // $form_state.
            $filters_list = array();
            if (isset($form_state['formatter_settings'][$field_name])) {
                $settings = $form_state['formatter_settings'][$field_name];
                foreach ($settings as $ref_type_name => $ref_type) {
                    $filters_for_ref_type = array();
                    foreach ($ref_type['filters'] as $ref_filter_name => $ref_filter) {
                        if (!empty($ref_filter)) {
                            $filters_for_ref_type[$ref_filter_name] = array();
                        }
                    }
                    if (!empty($filters_for_ref_type)) {
                        $filters_list[$ref_type_name] = $filters_for_ref_type;
                    }
                }
            } elseif (isset($facet_filters[$bundle][$field_name]['referenced_filters'])) {
                $filters_list = $facet_filters[$bundle][$field_name]['referenced_filters'];
            }
            $content_type_filters[$field_name]['state'] = $values['type'];
            $content_type_filters[$field_name]['referenced_filters'] = $filters_list;
        }
    }


    //Erase the current bundle entries from  existing version of facet_collections_filters_settings
    if (isset($facet_filters[$bundle])) {
        foreach ($facet_filters[$bundle] as $filter_name => $filter) {
            if ($filter['state'] == 'visible') {
                $field_info = field_info_field($filter_name);
                if ($field_info['type'] == 'taxonomy_term_reference') {
                    foreach ($field_info['settings']['allowed_values'] as $allowed_value) {
                        if (isset($allowed_value['vocabulary'])) {
                            if (array_key_exists($bundle, $facet_filters_settings[$field_info['type']][$allowed_value['vocabulary']])) {
                                unset($facet_filters_settings[$field_info['type']][$allowed_value['vocabulary']][$bundle]);
                            }
                        }
                    }
                } elseif ($field_info['type'] == 'entityreference' && $field_info['settings']['target_type'] == 'node') {
                    if (array_key_exists($bundle, $facet_filters_settings[$field_info['type']][$filter_name])) {
                        unset($facet_filters_settings[$field_info['type']][$filter_name][$bundle]);
                    }
                    //The alghrithm of erasing old information for associated array 
                    //for referenced filters is the same as for usual filters.
                    $entity_reference_settings = $facet_filters_settings[$field_info['type']][$filter_name]['settings'];
                    foreach ($filter['referenced_filters'] as $ref_bundle => $ref_filters) {
                        foreach ($ref_filters as $ref_filter_name => $ref_filter) {
                            $ref_field_info = field_info_field($ref_filter_name);
                            if ($ref_field_info['type'] == 'taxonomy_term_reference') {
                                foreach ($ref_field_info['settings']['allowed_values'] as $allowed_value) {
                                    if (isset($allowed_value['vocabulary'])) {
                                        if (array_key_exists($bundle, $entity_reference_settings[$ref_field_info['type']][$allowed_value['vocabulary']])) {
                                            unset($entity_reference_settings[$ref_field_info['type']][$allowed_value['vocabulary']][$bundle]);
                                        }
                                    }
                                }
                            } elseif ($ref_field_info['type'] == 'entityreference' && $fref_ield_info['settings']['target_type'] == 'node') {
                                if (array_key_exists($bundle, $entity_reference_settings[$ref_field_info['type']][$filter_name])) {
                                    unset($entity_reference_settings[$ref_field_info['type']][$filter_name][$bundle]);
                                }
                            } elseif ($ref_field_info['type'] == 'datetime' || $ref_field_info['type'] == 'datestamp' || $ref_field_info['type'] == 'date') {
                                if (array_key_exists($bundle, $entity_reference_settings[$ref_field_info['type']])) {
                                    unset($entity_reference_settings[$ref_field_info['type']][$bundle]);
                                }
                            }
                        }
                    }
                    $facet_filters_settings[$field_info['type']][$filter_name]['settings'] = $entity_reference_settings;
                } elseif ($field_info['type'] == 'datetime' || $field_info['type'] == 'datestamp' || $field_info['type'] == 'date') {
                    if (array_key_exists($bundle, $facet_filters_settings[$field_info['type']])) {
                        unset($facet_filters_settings[$field_info['type']][$bundle]);
                    }
                }
            }
        }
    }

    //Save filters setting in more convinient for apache_solr form
    //Filters settings stored in such kind of sturcture 
    //(              voc_name(for term_reference)     -> bundle_name                                    )
    //(field_type -> field_name(for entityreference)  -> content_types                   -> bundle_name )                   
    //(                                                  settings(for referenced filters)               )
    //(              bundle_name(for date types)                                                        )
    foreach ($content_type_filters as $filter_name => $filter) {
        $field_info = field_info_field($filter_name);
        if ($field_info['type'] == 'taxonomy_term_reference') {
            $vocabulary_name = $field_info['settings']['allowed_values'][0]['vocabulary'];
            $facet_filters_settings[$field_info['type']][$vocabulary_name] = array();
            if ($filter['state'] == 'visible') {
                $facet_filters_settings[$field_info['type']][$vocabulary_name][$bundle] = array();
            }
        } elseif ($field_info['type'] == 'entityreference' && $field_info['settings']['target_type'] == 'node') {
            $facet_filters_settings[$field_info['type']][$filter_name] = array();
            if ($filter['state'] == 'visible') {
                $facet_filters_settings[$field_info['type']][$filter_name]['content_types'][$bundle] = array();
            }
            $entity_reference_settings = array();
            //The structure of associated array for referenced filters is the same 
            //as for usual filters.
            //(              voc_name(for term_reference)     -> bundle_name )
            //(field_type -> field_name(for entityreference)  -> bundle_name )
            //(              bundle_name(for date types)                     )
            foreach ($filter['referenced_filters'] as $ref_bundle => $ref_filters) {
                foreach ($ref_filters as $ref_filter_name => $ref_filter) {
                    $ref_field_info = field_info_field($ref_filter_name);
                    if ($ref_field_info['type'] == 'taxonomy_term_reference') {
                        foreach ($ref_field_info['settings']['allowed_values'] as $allowed_value) {
                            if (isset($allowed_value['vocabulary'])) {
                                $entity_reference_settings[$ref_field_info['type']][$allowed_value['vocabulary']][$ref_bundle] = array();
                            }
                        }
                    } elseif ($ref_field_info['type'] == 'entityreference' && $ref_field_info['settings']['target_type'] == 'node') {
                        $entity_reference_settings[$ref_field_info['type']][$filter_name][$ref_bundle] = array();
                    } elseif ($ref_field_info['type'] == 'datetime' || $ref_field_info['type'] == 'datestamp' || $ref_field_info['type'] == 'date') {
                        $entity_reference_settings[$ref_field_info['type']][$ref_bundle] = array();
                    }
                }
            }
            $facet_filters_settings[$field_info['type']][$filter_name]['settings'] = $entity_reference_settings;
        } elseif ($field_info['type'] == 'datetime' || $field_info['type'] == 'datestamp' || $field_info['type'] == 'date') {
            $facet_filters_settings[$field_info['type']] = array();
            if ($filter['state'] == 'visible') {
                $facet_filters_settings[$field_info['type']][$bundle] = array();
            }
        }
    }

    //Save filters settings at the variables
    $facet_filters[$bundle] = $content_type_filters;
    variable_set('facet_collection_filters', drupal_json_encode($facet_filters));
    variable_set('facet_collection_filters_settings', drupal_json_encode($facet_filters_settings));

//    dpm($facet_filters);
//    dpm($facet_filters_settings);
    drupal_set_message(t('Your settings have been saved.'));
}

/**
 * Function to define is filters settings form need to be visible or not
 */
function is_filters_settings_visible($filters, $form_state, $field) {
    $filters_list = get_referenced_filterable_fields($field);
    if (!empty($filters_list)) {
//        if (isset($form_state['values'])) {
//            if (isset($form_state['values']['fields'][$field['field_name']]['type'])
//                    && $form_state['values']['fields'][$field['field_name']]['type'] == 'visible') {
//                return TRUE;
//            }
//        } elseif (isset($filters[$field['field_name']])) {
        return TRUE;
//        }
    }
    return FALSE;
}

/**
 * Return list of referenced filterable fields for each referenceable_type for some field
 */
function get_referenced_filterable_fields($field) {
    $referenced_filterable_fields = array();
    if ($field['type'] == 'entityreference' && $field['settings']['target_type'] == 'node') {
        foreach ($field['settings']['handler_settings']['target_bundles'] as $ref_type) {
            $ref_instances = field_info_instances('node', $ref_type);
            $filters_list = array();
            foreach ($ref_instances as $ref_instance) {
                $ref_field = field_info_field($ref_instance['field_name']);
                if (is_field_filterable($ref_field)) {
                    $filters_list[$ref_instance['field_name']] = $ref_instance['label'];
                }
            }
            if (!empty($filters_list)) {
                $referenced_filterable_fields[$ref_type] = $filters_list;
            }
        }
    }
    return $referenced_filterable_fields;
}

/**
 * Return TRUE if field is filterable
 */
function is_field_filterable($field) {
    if ($field['type'] == 'taxonomy_term_reference'
            || ($field['type'] == 'entityreference' && $field['settings']['target_type'] == 'node')
            || $field['type'] == 'datetime'
            || $field['type'] == 'date'
            || $field['type'] == 'datestamp') {
        return TRUE;
    }
    return FALSE;
}