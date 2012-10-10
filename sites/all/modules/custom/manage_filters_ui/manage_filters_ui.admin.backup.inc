<?php

//function manage_filters_ui_filters_overview_form($form, &$form_state, $entity_type, $bundle, $view_mode) {
//  $bundle = field_extract_bundle($entity_type, $bundle);
//
//  field_ui_inactive_message($entity_type, $bundle);
//  $admin_path = _field_ui_bundle_admin_path($entity_type, $bundle);
//
//  // Gather type information.
//  $instances = field_info_instances($entity_type, $bundle);
//  $field_types = field_info_field_types();
//  $extra_fields = field_info_extra_fields($entity_type, $bundle, 'display');
//
//  $extra_visibility_options = array(
//    'visible' => t('Visible'),
//    'hidden' => t('Hidden'),
//  );
//  
//  $field_label_options = array(
//    'above' => t('Above'),
//    'inline' => t('Inline'),
//    'hidden' => t('<Hidden>'),
//  );
//    
//  $form_state += array(
//    'formatter_settings_edit' => NULL,
//  );
//
//  $form += array(
//    '#entity_type' => $entity_type,
//    '#bundle' => $bundle,
//    '#view_mode' => $view_mode,
//    '#fields' => array_keys($instances),
//    '#extra' => array_keys($extra_fields),
//  );
//
//  if (empty($instances) && empty($extra_fields)) {
//    drupal_set_message(t('There are no fields yet added. You can add new fields on the <a href="@link">Manage fields</a> page.', array('@link' => url($admin_path . '/fields'))), 'warning');
//    return $form;
//  }
//  $table = array(
//    '#type' => 'field_ui_table',
//    '#tree' => TRUE,
//    '#header' => array(
//      t('Field'),
//      t('Parent'),
//      array('data' => t('Format'), 'colspan' => 3),
//    ),
//    '#regions' => array(
//      'enabled' => array('message' => t('No field is enabled.')),
//      'disabled' => array('title' => t('Disabled'), 'message' => t('No field is disabled.')),
//    ),
//    '#parent_options' => array(),
//    '#attributes' => array(
//      'class' => array('field-ui-overview'),
//      'id' => 'field-display-overview',
//    ),
//    // Add Ajax wrapper.
//    '#prefix' => '<div id="field-display-overview-wrapper">',
//    '#suffix' => '</div>',
//  );
//
//  
//  // Field rows.
//  foreach ($instances as $name => $instance) {
//    $field = field_info_field($instance['field_name']);
//    $display = $instance['display'][$view_mode];
//    $table[$name] = array(
//      '#attributes' => array('class' => array('draggable', 'tabledrag-leaf')),
//      '#row_type' => 'field',
//      '#region_callback' => 'field_ui_display_overview_row_region',
//      '#js_settings' => array(
//        'rowHandler' => 'field',
//        'defaultFormatter' => $field_types[$field['type']]['default_formatter'],
//      ),
//      'human_name' => array(
//        '#markup' => check_plain($instance['label']),
//      ),
//      'weight' => array(
//        '#type' => 'textfield',
//        '#title' => t('Weight for @title', array('@title' => $instance['label'])),
//        '#title_display' => 'invisible',
//        '#default_value' => $display['weight'],
//        '#size' => 3,
//        '#attributes' => array('class' => array('field-weight')),
//      ),
//      'parent_wrapper' => array(
//        'parent' => array(
//          '#type' => 'select',
//          '#title' => t('Label display for @title', array('@title' => $instance['label'])),
//          '#title_display' => 'invisible',
//          '#options' => $table['#parent_options'],
//          '#empty_value' => '',
//          '#attributes' => array('class' => array('field-parent')),
//          '#parents' => array('fields', $name, 'parent'),
//        ),
//        'hidden_name' => array(
//          '#type' => 'hidden',
//          '#default_value' => $name,
//          '#attributes' => array('class' => array('field-name')),
//        ),
//      ),
//      'label' => array(
//        '#type' => 'select',
//        '#title' => t('Label display for @title', array('@title' => $instance['label'])),
//        '#title_display' => 'invisible',
//       // '#options' => $field_label_options,
//        '#default_value' => $display['label'],
//      ),
//    );
//
//    $formatter_options = manage_filters_ui_field_ui_formatter_options($field['type']);
//    $formatter_options['hidden'] = t('<Hidden>');
//    $table[$name]['format'] = array(
//      'type' => array(
//        '#type' => 'select',
//        '#title' => t('Formatter for @title', array('@title' => $instance['label'])),
//        '#title_display' => 'invisible',
//        '#options' => $formatter_options,
//        '#default_value' => $display['type'],
//        '#parents' => array('fields', $name, 'type'),
//        '#attributes' => array('class' => array('field-formatter-type')),
//      ),
//      'settings_edit_form' => array(),
//    );
//
//    // Formatter settings.
//
//    // Check the currently selected formatter, and merge persisted values for
//    // formatter settings.
//    if (isset($form_state['values']['fields'][$name]['type'])) {
//      $formatter_type = $form_state['values']['fields'][$name]['type'];
//    }
//    else {
//      $formatter_type = $display['type'];
//    }
//    if (isset($form_state['formatter_settings'][$name])) {
//      $settings = $form_state['formatter_settings'][$name];
//    }
//    else {
//      $settings = $display['settings'];
//    }
//    $settings += field_info_formatter_settings($formatter_type);
//
//    $instance['display'][$view_mode]['type'] = $formatter_type;
//    $formatter = field_info_formatter_types($formatter_type);
//    $instance['display'][$view_mode]['module'] = $formatter['module'];
//    $instance['display'][$view_mode]['settings'] = $settings;
//
//    // Base button element for the various formatter settings actions.
//    $base_button = array(
//      '#submit' => array('field_ui_display_overview_multistep_submit'),
//      '#ajax' => array(
//        'callback' => 'field_ui_display_overview_multistep_js',
//        'wrapper' => 'field-display-overview-wrapper',
//        'effect' => 'fade',
//      ),
//      '#field_name' => $name,
//    );
//
//    if ($form_state['formatter_settings_edit'] == $name) {
//      // We are currently editing this field's formatter settings. Display the
//      // settings form and submit buttons.
//      $table[$name]['format']['settings_edit_form'] = array();
//
//      $settings_form = array();
//      $function = $formatter['module'] . '_field_formatter_settings_form';
//      if (function_exists($function)) {
//        $settings_form = $function($field, $instance, $view_mode, $form, $form_state);
//      }
//
//      if ($settings_form) {
//        $table[$name]['format']['#cell_attributes'] = array('colspan' => 3);
//        $table[$name]['format']['settings_edit_form'] = array(
//          '#type' => 'container',
//          '#attributes' => array('class' => array('field-formatter-settings-edit-form')),
//          '#parents' => array('fields', $name, 'settings_edit_form'),
//          'label' => array(
//            '#markup' => t('Format settings:') . ' <span class="formatter-name">' . $formatter['label'] . '</span>',
//          ),
//          'settings' => $settings_form,
//          'actions' => array(
//            '#type' => 'actions',
//            'save_settings' => $base_button + array(
//              '#type' => 'submit',
//              '#name' => $name . '_formatter_settings_update',
//              '#value' => t('Update'),
//              '#op' => 'update',
//            ),
//            'cancel_settings' => $base_button + array(
//              '#type' => 'submit',
//              '#name' => $name . '_formatter_settings_cancel',
//              '#value' => t('Cancel'),
//              '#op' => 'cancel',
//              // Do not check errors for the 'Cancel' button, but make sure we
//              // get the value of the 'formatter type' select.
//              '#limit_validation_errors' => array(array('fields', $name, 'type')),
//            ),
//          ),
//        );
//        $table[$name]['#attributes']['class'][] = 'field-formatter-settings-editing';
//      }
//    }
//    else {
//      // Display a summary of the current formatter settings.
//      $summary = module_invoke($formatter['module'], 'field_formatter_settings_summary', $field, $instance, $view_mode);
//      $table[$name]['settings_summary'] = array();
//      $table[$name]['settings_edit'] = array();
//      if ($summary) {
//        $table[$name]['settings_summary'] = array(
//          '#markup' => '<div class="field-formatter-summary">' . $summary . '</div>',
//          '#cell_attributes' => array('class' => array('field-formatter-summary-cell')),
//        );
//        $table[$name]['settings_edit'] = $base_button + array(
//          '#type' => 'image_button',
//          '#name' => $name . '_formatter_settings_edit',
//          '#src' => 'misc/configure.png',
//          '#attributes' => array('class' => array('field-formatter-settings-edit'), 'alt' => t('Edit')),
//          '#op' => 'edit',
//          // Do not check errors for the 'Edit' button, but make sure we get
//          // the value of the 'formatter type' select.
//          '#limit_validation_errors' => array(array('fields', $name, 'type')),
//          '#prefix' => '<div class="field-formatter-settings-edit-wrapper">',
//          '#suffix' => '</div>',
//        );
//      }
//    }
//  }
//
//  // Non-field elements.
//  foreach ($extra_fields as $name => $extra_field) {
//    $display = $extra_field['display'][$view_mode];
//    $table[$name] = array(
//      '#attributes' => array('class' => array('draggable', 'tabledrag-leaf')),
//      '#row_type' => 'extra_field',
//      '#region_callback' => 'field_ui_display_overview_row_region',
//      '#js_settings' => array('rowHandler' => 'field'),
//      'human_name' => array(
//        '#markup' => check_plain($extra_field['label']),
//      ),
//      'weight' => array(
//        '#type' => 'textfield',
//        '#title' => t('Weight for @title', array('@title' => $extra_field['label'])),
//        '#title_display' => 'invisible',
//        '#default_value' => $display['weight'],
//        '#size' => 3,
//        '#attributes' => array('class' => array('field-weight')),
//      ),
//      'parent_wrapper' => array(
//        'parent' => array(
//          '#type' => 'select',
//          '#title' => t('Parents for @title', array('@title' => $extra_field['label'])),
//          '#title_display' => 'invisible',
//          '#options' => $table['#parent_options'],
//          '#empty_value' => '',
//          '#attributes' => array('class' => array('field-parent')),
//          '#parents' => array('fields', $name, 'parent'),
//        ),
//        'hidden_name' => array(
//          '#type' => 'hidden',
//          '#default_value' => $name,
//          '#attributes' => array('class' => array('field-name')),
//        ),
//      ),
//      'empty_cell' => array(
//        '#markup' => '&nbsp;',
//      ),
//      'format' => array(
//        'type' => array(
//          '#type' => 'select',
//          '#title' => t('Visibility for @title', array('@title' => $extra_field['label'])),
//          '#title_display' => 'invisible',
//          '#options' => $extra_visibility_options,
//          '#default_value' => $display['visible'] ? 'visible' : 'hidden',
//          '#parents' => array('fields', $name, 'type'),
//          '#attributes' => array('class' => array('field-formatter-type')),
//        ),
//      ),
//      'settings_summary' => array(),
//      'settings_edit' => array(),
//    );
//  }
//
//  $form['fields'] = $table;
//
//  // Custom display settings.
//  if ($view_mode == 'default') {
//    $form['modes'] = array(
//      '#type' => 'fieldset',
//      '#title' => t('Custom display settings'),
//      '#collapsible' => TRUE,
//      '#collapsed' => TRUE,
//    );
//    // Collect options and default values for the 'Custom display settings'
//    // checkboxes.
//    $options = array();
//    $default = array();
//    $entity_info = entity_get_info($entity_type);
//    $view_modes = $entity_info['view modes'];
//    $view_mode_settings = field_view_mode_settings($entity_type, $bundle);
//    foreach ($view_modes as $view_mode_name => $view_mode_info) {
//      $options[$view_mode_name] = $view_mode_info['label'];
//      if (!empty($view_mode_settings[$view_mode_name]['custom_settings'])) {
//        $default[] = $view_mode_name;
//      }
//    }
//    $form['modes']['view_modes_custom'] = array(
//      '#type' => 'checkboxes',
//      '#title' => t('Use custom display settings for the following view modes'),
//      '#options' => $options,
//      '#default_value' => $default,
//    );
//  }
//
//  // In overviews involving nested rows from contributed modules (i.e
//  // field_group), the 'format type' selects can trigger a series of changes in
//  // child rows. The #ajax behavior is therefore not attached directly to the
//  // selects, but triggered by the client-side script through a hidden #ajax
//  // 'Refresh' button. A hidden 'refresh_rows' input tracks the name of
//  // affected rows.
//  $form['refresh_rows'] = array('#type' => 'hidden');
//  $form['refresh'] = array(
//    '#type' => 'submit',
//    '#value' => t('Refresh'),
//    '#op' => 'refresh_table',
//    '#submit' => array('field_ui_display_overview_multistep_submit'),
//    '#ajax' => array(
//      'callback' => 'field_ui_display_overview_multistep_js',
//      'wrapper' => 'field-display-overview-wrapper',
//      'effect' => 'fade',
//      // The button stays hidden, so we hide the Ajax spinner too. Ad-hoc
//      // spinners will be added manually by the client-side script.
//      'progress' => 'none',
//    ),
//  );
//
//  $form['actions'] = array('#type' => 'actions');
//  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save'));
//
//  $form['#attached']['js'][] = drupal_get_path('module', 'field_ui') . '/field_ui.js';
//  $form['#attached']['css'][] = drupal_get_path('module', 'field_ui') . '/field_ui.css';
//
//  // Add tabledrag behavior.
//  $form['#attached']['drupal_add_tabledrag'][] = array('field-display-overview', 'order', 'sibling', 'field-weight');
//  $form['#attached']['drupal_add_tabledrag'][] = array('field-display-overview', 'match', 'parent', 'field-parent', 'field-parent', 'field-name');
//
//  return $form;
//}
function manage_filters_ui_filters_overview_form($form, &$form_state, $entity_type, $bundle, $view_mode) {
  $bundle = field_extract_bundle($entity_type, $bundle);

  field_ui_inactive_message($entity_type, $bundle);
  $admin_path = _field_ui_bundle_admin_path($entity_type, $bundle);

  // Gather type information.
  $instances = field_info_instances($entity_type, $bundle);
  $field_types = field_info_field_types();
  $extra_fields = field_info_extra_fields($entity_type, $bundle, 'display');

  $form_state += array(
    'formatter_settings_edit' => NULL,
  );

  $form += array(
    '#entity_type' => $entity_type,
    '#bundle' => $bundle,
    '#view_mode' => $view_mode,
    '#fields' => array_keys($instances),
    '#extra' => array_keys($extra_fields),
  );

  if (empty($instances) && empty($extra_fields)) {
    drupal_set_message(t('There are no fields yet added. You can add new fields on the <a href="@link">Manage fields</a> page.', array('@link' => url($admin_path . '/fields'))), 'warning');
    return $form;
  }

  $table = array(
    '#type' => 'field_ui_table',
    '#tree' => TRUE,
    '#header' => array(
      t('Field'),
      t('Weight'),
      t('Parent'),
      t('Label'),
      array('data' => t('Format'), 'colspan' => 3),
    ),
    '#regions' => array(
      'visible' => array('message' => t('No field is displayed.')),
      'hidden' => array('title' => t('Hidden'), 'message' => t('No field is hidden.')),
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

  $field_label_options = array(
    'above' => t('Above'),
    'inline' => t('Inline'),
    'hidden' => t('<Hidden>'),
  );
  $extra_visibility_options = array(
    'visible' => t('Visible'),
    'hidden' => t('Hidden'),
  );

  // Field rows.
  foreach ($instances as $name => $instance) {
    $field = field_info_field($instance['field_name']);
    $display = $instance['display'][$view_mode];
    $table[$name] = array(
      '#attributes' => array('class' => array('draggable', 'tabledrag-leaf')),
      '#row_type' => 'field',
      '#region_callback' => 'field_ui_display_overview_row_region',
      '#js_settings' => array(
        'rowHandler' => 'field',
        'defaultFormatter' => $field_types[$field['type']]['default_formatter'],
      ),
      'human_name' => array(
        '#markup' => check_plain($instance['label']),
      ),
      'weight' => array(
        '#type' => 'textfield',
        '#title' => t('Weight for @title', array('@title' => $instance['label'])),
        '#title_display' => 'invisible',
        '#default_value' => $display['weight'],
        '#size' => 3,
        '#attributes' => array('class' => array('field-weight')),
      ),
      'parent_wrapper' => array(
        'parent' => array(
          '#type' => 'select',
          '#title' => t('Label display for @title', array('@title' => $instance['label'])),
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
      'label' => array(
        '#type' => 'select',
        '#title' => t('Label display for @title', array('@title' => $instance['label'])),
        '#title_display' => 'invisible',
        '#options' => $field_label_options,
        '#default_value' => $display['label'],
      ),
    );

    $formatter_options = manage_filters_ui_field_ui_formatter_options($field['type']);
    $formatter_options['hidden'] = t('<Hidden>');
    $table[$name]['format'] = array(
      'type' => array(
        '#type' => 'select',
        '#title' => t('Formatter for @title', array('@title' => $instance['label'])),
        '#title_display' => 'invisible',
        '#options' => $formatter_options,
        '#default_value' => $display['type'],
        '#parents' => array('fields', $name, 'type'),
        '#attributes' => array('class' => array('field-formatter-type')),
      ),
      'settings_edit_form' => array(),
    );

    // Formatter settings.

    // Check the currently selected formatter, and merge persisted values for
    // formatter settings.
    if (isset($form_state['values']['fields'][$name]['type'])) {
      $formatter_type = $form_state['values']['fields'][$name]['type'];
    }
    else {
      $formatter_type = $display['type'];
    }
    if (isset($form_state['formatter_settings'][$name])) {
      $settings = $form_state['formatter_settings'][$name];
    }
    else {
      $settings = $display['settings'];
    }
    $settings += field_info_formatter_settings($formatter_type);

    $instance['display'][$view_mode]['type'] = $formatter_type;
    $formatter = field_info_formatter_types($formatter_type);
    $instance['display'][$view_mode]['module'] = $formatter['module'];
    $instance['display'][$view_mode]['settings'] = $settings;

    // Base button element for the various formatter settings actions.
    $base_button = array(
      '#submit' => array('field_ui_display_overview_multistep_submit'),
      '#ajax' => array(
        'callback' => 'field_ui_display_overview_multistep_js',
        'wrapper' => 'field-display-overview-wrapper',
        'effect' => 'fade',
      ),
      '#field_name' => $name,
    );

    if ($form_state['formatter_settings_edit'] == $name) {
      // We are currently editing this field's formatter settings. Display the
      // settings form and submit buttons.
      $table[$name]['format']['settings_edit_form'] = array();

      $settings_form = array();
      $function = $formatter['module'] . '_field_formatter_settings_form';
      if (function_exists($function)) {
        $settings_form = $function($field, $instance, $view_mode, $form, $form_state);
      }

      if ($settings_form) {
        $table[$name]['format']['#cell_attributes'] = array('colspan' => 3);
        $table[$name]['format']['settings_edit_form'] = array(
          '#type' => 'container',
          '#attributes' => array('class' => array('field-formatter-settings-edit-form')),
          '#parents' => array('fields', $name, 'settings_edit_form'),
          'label' => array(
            '#markup' => t('Format settings:') . ' <span class="formatter-name">' . $formatter['label'] . '</span>',
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
              // get the value of the 'formatter type' select.
              '#limit_validation_errors' => array(array('fields', $name, 'type')),
            ),
          ),
        );
        $table[$name]['#attributes']['class'][] = 'field-formatter-settings-editing';
      }
    }
    else {
      // Display a summary of the current formatter settings.
      $summary = module_invoke($formatter['module'], 'field_formatter_settings_summary', $field, $instance, $view_mode);
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

  // Non-field elements.
  foreach ($extra_fields as $name => $extra_field) {
    $display = $extra_field['display'][$view_mode];
    $table[$name] = array(
      '#attributes' => array('class' => array('draggable', 'tabledrag-leaf')),
      '#row_type' => 'extra_field',
      '#region_callback' => 'field_ui_display_overview_row_region',
      '#js_settings' => array('rowHandler' => 'field'),
      'human_name' => array(
        '#markup' => check_plain($extra_field['label']),
      ),
      'weight' => array(
        '#type' => 'textfield',
        '#title' => t('Weight for @title', array('@title' => $extra_field['label'])),
        '#title_display' => 'invisible',
        '#default_value' => $display['weight'],
        '#size' => 3,
        '#attributes' => array('class' => array('field-weight')),
      ),
      'parent_wrapper' => array(
        'parent' => array(
          '#type' => 'select',
          '#title' => t('Parents for @title', array('@title' => $extra_field['label'])),
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
      'empty_cell' => array(
        '#markup' => '&nbsp;',
      ),
      'format' => array(
        'type' => array(
          '#type' => 'select',
          '#title' => t('Visibility for @title', array('@title' => $extra_field['label'])),
          '#title_display' => 'invisible',
          '#options' => $extra_visibility_options,
          '#default_value' => $display['visible'] ? 'visible' : 'hidden',
          '#parents' => array('fields', $name, 'type'),
          '#attributes' => array('class' => array('field-formatter-type')),
        ),
      ),
      'settings_summary' => array(),
      'settings_edit' => array(),
    );
  }

  $form['fields'] = $table;
  dpm($view_mode);
  // Custom display settings.
  if ($view_mode == 'default') {
    $form['modes'] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom display settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    // Collect options and default values for the 'Custom display settings'
    // checkboxes.
    $options = array();
    $default = array();
    $entity_info = entity_get_info($entity_type);
    $view_modes = $entity_info['view modes'];
    $view_mode_settings = field_view_mode_settings($entity_type, $bundle);
    foreach ($view_modes as $view_mode_name => $view_mode_info) {
      $options[$view_mode_name] = $view_mode_info['label'];
      if (!empty($view_mode_settings[$view_mode_name]['custom_settings'])) {
        $default[] = $view_mode_name;
      }
    }
    $form['modes']['view_modes_custom'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Use custom display settings for the following view modes'),
      '#options' => $options,
      '#default_value' => $default,
    );
  }

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
    '#submit' => array('field_ui_display_overview_multistep_submit'),
    '#ajax' => array(
      'callback' => 'field_ui_display_overview_multistep_js',
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
 * Returns an array of formatter options for a field type.
 *
 * If no field type is provided, returns a nested array of all formatters, keyed
 * by field type.
 */
function manage_filters_ui_field_ui_formatter_options($field_type = NULL) {
  $options = &drupal_static(__FUNCTION__);

  if (!isset($options)) {
    $field_types = field_info_field_types();
    $options = array();
    foreach (field_info_formatter_types() as $name => $formatter) {
      foreach ($formatter['field types'] as $formatter_field_type) {
        // Check that the field type exists.
        if (isset($field_types[$formatter_field_type])) {
          $options[$formatter_field_type][$name] = $formatter['label'];
        }
      }
    }
  }

  if ($field_type) {
    return !empty($options[$field_type]) ? $options[$field_type] : array();
  }
  return $options;
}

/**
 * Displays a message listing the inactive fields of a given bundle.
 */
function field_ui_inactive_message($entity_type, $bundle) {
  $inactive_instances = field_ui_inactive_instances($entity_type, $bundle);
  if (!empty($inactive_instances)) {
    $field_types = field_info_field_types();
    $widget_types = field_info_widget_types();

    foreach ($inactive_instances as $field_name => $instance) {
      $list[] = t('%field (@field_name) field requires the %widget_type widget provided by %widget_module module', array(
      '%field' => $instance['label'],
      '@field_name' => $instance['field_name'],
      '%widget_type' => isset($widget_types[$instance['widget']['type']]) ? $widget_types[$instance['widget']['type']]['label'] : $instance['widget']['type'],
      '%widget_module' => $instance['widget']['module'],
      ));
    }
    drupal_set_message(t('Inactive fields are not shown unless their providing modules are enabled. The following fields are not enabled: !list', array('!list' => theme('item_list', array('items' => $list)))), 'error');
  }
}