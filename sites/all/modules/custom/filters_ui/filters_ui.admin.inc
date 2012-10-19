<?php

/**
 * Displays a message listing the inactive fields of a given bundle.
 */
//function filters_ui_inactive_message($entity_type, $bundle) {
//    $inactive_instances = field_ui_inactive_instances($entity_type, $bundle);
//    if (!empty($inactive_instances)) {
//        $field_types = field_info_field_types();
//
//        foreach ($inactive_instances as $field_name => $instance) {
//            $list[] = t('%field (@field_name) field requires the %widget_type widget provided by %widget_module module', array(
//                '%field' => $instance['label'],
//                '@field_name' => $instance['field_name'],
//                    ));
//        }
//        drupal_set_message(t('Inactive fields are not shown unless their providing modules are enabled. The following fields are not enabled: !list', array('!list' => theme('item_list', array('items' => $list)))), 'error');
//    }
//}

/**
 * Determines the rendering order of an array representing a tree.
 *
 * Callback for array_reduce() within filters_ui_table_pre_render().
 */
function _filters_ui_reduce_order($array, $a)
{
    $array = !isset($array) ? array() : $array;

    if ($a['name']) {
        $array[] = $a['name'];
    }
    if (!empty($a['children'])) {
        uasort($a['children'], 'drupal_sort_weight');
        $array = array_merge($array, array_reduce($a['children'], '_filters_ui_reduce_order'));
    }
    return $array;
}

/**
 * Returns the region to which a row in the 'Manage filters' screen belongs.
 *
 * This function is used as a #region_callback in
 * filters_ui_field_overview_form(), and is called during
 * filters_ui_table_pre_render().
 */
function filters_ui_filters_overview_row_region($row)
{
    switch ($row['#row_type']) {
        case 'field':
            return ($row['state']['type']['#value'] == 'hidden' ? 'hidden' : 'visible');
    }
}

/**
 * Pre-render callback for filters_ui_table elements.
 */
function filters_ui_table_pre_render($elements)
{
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
        $elements['#regions'][$region_name]['rows_order'] = array_reduce($trees[$region_name], '_filters_ui_reduce_order');
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
function theme_filters_ui_table($variables)
{
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
 * @see filters_ui_filters_overview_multistep_submit()
 * @see filters_ui_filters_overview_form_submit()
 * @ingroup forms
 */
function filters_ui_filters_overview_form($form, &$form_state, $entity_type, $bundle)
{
    $bundle = field_extract_bundle($entity_type, $bundle);

    //filters_ui_inactive_message($entity_type, $bundle);
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
            switch ($field['type']) {
                case 'taxonomy_term_reference':
                    $vocabulary = taxonomy_vocabulary_machine_name_load($field['settings']['allowed_values'][0]['vocabulary']);
                    $filter_by_label = 'Vocabulary ' . $vocabulary->name;
                    break;
                case  'entityreference':
                    $filter_by_label = 'Node Reference';
                    break;
                case 'date':
                case 'datetime':
                case 'datestamp':
                    $filter_by_label = 'Date';
                    break;
            }
            $table[$name] = array(
                '#attributes' => array('class' => array('draggable', 'tabledrag-leaf')),
                '#row_type' => 'field',
                '#region_callback' => 'filters_ui_filters_overview_row_region',
                '#js_settings' => array(
                    'rowHandler' => 'field',
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
                        $node_reference_filters_settings[$ref_type_name][$ref_filter] = array();
                        if (!empty($ref_filter)) {
                            $node_reference_filters_settings[$ref_type_name][$ref_filter]['state'] = 'visible';
                        } else {
                            $node_reference_filters_settings[$ref_type_name][$ref_filter]['state'] = 'hidden';
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
                '#submit' => array('filters_ui_filters_overview_multistep_submit'),
                '#ajax' => array(
                    'callback' => 'filters_ui_filters_overview_multistep_js',
                    'wrapper' => 'field-display-overview-wrapper',
                    'effect' => 'fade',
                ),
                '#field_name' => $name,
            );

            if ($form_state['formatter_settings_edit'] == $name) {
                // We are currently editing this filters's settings. Display the
                // settings form and submit buttons.
                $table[$name]['state']['settings_edit_form'] = array();

                $settings_form = array();
                $function = 'filters_ui_' . $field['type'] . '_settings_form';
                if (function_exists($function)) {
                    $settings_form = $function($field, $node_reference_filters_settings, $form, $form_state);
                }

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
                // Display a summary of the current filter settings.
                $summary = NULL;
                $function = 'filters_ui_' . $field['type'] . '_summary';
                if (function_exists($function)) {
                    $summary = $function($field, $node_reference_filters_settings);
                }
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
        '#attributes' => array('style' => 'display:none'),
        '#submit' => array('filters_ui_filters_overview_multistep_submit'),
        '#ajax' => array(
            'callback' => 'filters_ui_filters_overview_multistep_js',
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
 * Form submission handler for buttons in filters_ui_filters_overview_form().
 */
function filters_ui_filters_overview_multistep_submit($form, &$form_state)
{
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
function filters_ui_filters_overview_multistep_js($form, &$form_state)
{
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
 * Form submission handler for filters_ui_filters_overview_form().
 */
function filters_ui_filters_overview_form_submit($form, &$form_state)
{

    $form_values = $form_state['values'];
    $bundle = $form['#bundle'];
    $content_type_filters = array();
    //Get current version of filter list for clean facet_collection_filters_settings up 
    //of current bundle
    //variable_del('facet_collection_filters_settings');
    //variable_del('facet_collection_filters');
    $facet_filters = drupal_json_decode(variable_get('facet_collection_filters'));
    $facet_filters_settings = drupal_json_decode(variable_get('facet_collection_filters_settings'));

    //Get changed filters settings from forms
    if (!empty($form_values['fields'])) {
        foreach ($form_values['fields'] as $field_name => $field_info) {
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
                        $filters_for_ref_type[$ref_filter_name] = array();
                        if (!empty($ref_filter)) {
                            $filters_for_ref_type[$ref_filter_name]['state'] = 'visible';
                        } else {
                            $filters_for_ref_type[$ref_filter_name]['state'] = 'hidden';
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
            $field = field_info_field($filter_name);
            $function = 'filters_ui_' . $field['type'] . '_delete_field';
            if (function_exists($function)) {
                $function($field, $bundle, $facet_filters_settings, $filter);
            }
        }
    }

    //Save filters setting in more convenient for apache_solr form
    foreach ($content_type_filters as $filter_name => $filter) {
        $field = field_info_field($filter_name);
        $function = 'filters_ui_' . $field['type'] . '_add_field';
        if (function_exists($function)) {
            $function($field, $bundle, $facet_filters_settings, $filter);
        }

    }

    //Save filters settings at the variables
    $facet_filters[$bundle] = $content_type_filters;
    variable_set('facet_collection_filters', drupal_json_encode($facet_filters));
    variable_set('facet_collection_filters_settings', drupal_json_encode($facet_filters_settings));

    dpm($facet_filters_settings);
    dpm($facet_filters);
    drupal_set_message(t('Your settings have been saved.'));
}





