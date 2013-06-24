<?php

require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'field_ui') . '/field_ui.admin.inc';

define('FIELD_DATA_COLLECTOR_PRESET_ADMIN_PATH', 'admin/config/media/field-data-collector-presets');

function field_data_collector_presets_admin_form() {
  $presets_settings = field_data_collector_load_presets();
  $table_data = array(
    'header' => array(
      array('data' => 'Preset Name'),
      array('data' => 'Preset Machine Name'),
      array('data' => 'Bundle Name'),
      array('data' => 'Description'),
      array('data' => 'Summary'),
      array('data' => 'Operations', 'colspan' => 2),
    ),
    'rows' => array(
      array(
        'data' => array(
          'There is no presets defined',
          '',
          '',
          '',
          '',
        ),
      ),
    ),
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => NULL,
    'sticky' => NULL,
    'empty' => NULL,
  );

  if (!empty($presets_settings)) {
    $table_data['rows'] = array();
  }

  $entity_info = entity_get_info('node');

  foreach ($presets_settings as $preset_name => $preset_data) {
    if (isset($entity_info['bundles'][$preset_data['bundle_name']]['label'])) {
      $table_data['rows'][] = array(
        'data' => array(
          $preset_data['label'],
          $preset_name,
          $entity_info['bundles'][$preset_data['bundle_name']]['label'],
          t(drupal_substr($preset_data['description'], 0, 40)),
          $preset_data['summary'],
          l('edit', FIELD_DATA_COLLECTOR_PRESET_ADMIN_PATH . '/edit/' . $preset_name),
          l('delete', FIELD_DATA_COLLECTOR_PRESET_ADMIN_PATH . '/delete/' . $preset_name)
        ),
      );
    }
  }
  $preset_table = theme_table($table_data);

  $add_preset_link = l('Add new preset', FIELD_DATA_COLLECTOR_PRESET_ADMIN_PATH . '/add');

  return $preset_table . '<br>' . $add_preset_link;

}

function field_data_collector_add_preset_form($form, &$form_state) {
  $settings = array();
  $form = field_data_collector_preset_form($form, $form_state, $settings);

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save preset'));
  $form['#submit'][] = 'field_data_collector_add_and_edit_preset_form_submit';
  $form['#validate'][] = 'field_data_collector_add_and_edit_preset_form_validate';
  return $form;
}

function field_data_collector_add_and_edit_preset_form_validate($form, &$form_state) {
  if ($form_state['values']['bundle_name'] == 'none') {
    form_set_error('bundle_name', t('You should choose the bundle for preset'));
  }
}

function field_data_collector_add_and_edit_preset_form_submit($form, &$form_state) {
  $form_values = $form_state['values'];

  $preset_name = $form_values['machine_name'];
  $preset_label = $form_values['label'];
  $preset_bundle = $form_values['bundle_name'];
  $preset_description = $form_values['description'];
  $preset_settings = $form_values['settings'];
  $preset_summary = field_data_collector_preset_settings_summary($form_values['settings'], $form_values['bundle_name'], 'node');

  field_data_collector_save_preset($preset_name, $preset_label, $preset_bundle, $preset_description, $preset_summary, $preset_settings);
  $form_state['redirect'] = FIELD_DATA_COLLECTOR_PRESET_ADMIN_PATH;

  drupal_set_message('The preset successfully saved');
}

function field_data_collector_preset_form($form, &$form_state, $settings) {

  $form['label'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#maxlength' => 255,
    '#title' => t('Preset name'),
    '#description' => t('Enter name for the preset.'),
    '#default_value' => isset($settings['label']) ? $settings['label'] : '',
    '#required' => TRUE,
  );

  if (!isset($settings['machine_name'])) {
    $form['machine_name'] = array(
      '#title' => t('Machine name'),
      '#type' => 'machine_name',
      '#default_value' => '',
      '#machine_name' => array(
        'exists' => 'field_data_collector_preset_exists',
        'source' => array('label'),
      ),
      '#description' => t('Enter the machine name for the preset. It must be unique and contain only alphanumeric characters and underscores.'),
    );
  }
  else {
    $form['machine_name'] = array(
      '#type' => 'hidden',
      '#value' => $settings['machine_name'],
    );
  }

  $form['description'] = array(
    '#type' => 'textarea',
    '#size' => 10,
    '#title' => t('Description'),
    '#description' => t('Summary for the preset.'),
    '#default_value' => isset($settings['description']) ? $settings['description'] : '',
  );

  $target_type = 'node';
  $entity_info = entity_get_info($target_type);
  $bundles = $entity_info['bundles'];

  $bundle_name_options = array('none' => '-None-');
  foreach ($bundles as $bundle_name => $bundle_label) {
    $bundle_name_options[$bundle_name] = $bundle_label['label'];
  }


  $target_bundle = 'none';

  $target_bundle = isset($settings['bundle_name'])
    ? $settings['bundle_name']
    : $target_bundle;

  $target_bundle = isset($form_state['values']['bundle_name'])
    ? $form_state['values']['bundle_name']
    : $target_bundle;


  $form['bundle_name'] = array(
    '#type' => 'select',
    '#title' => t('Content type'),
    '#options' => $bundle_name_options,
    '#default_value' => $target_bundle,
    '#description' => t('Chose the preset bundle'),
    '#ajax' => array(
      'callback' => '_field_data_collector_bundle_select_callback',
      'wrapper' => 'bundle-settings-fieldset',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#required' => TRUE,
  );


  if ($target_bundle != 'none') {

    $bundle_instances = field_info_instances($target_type, $target_bundle);
    $optional_primary_media_fields = array('none' => '-None-');
    foreach ($bundle_instances as $bundle_instance) {
      $field_info = field_info_field($bundle_instance['field_name']);
      //The primary field could be any field with type list and widget option_select or option_buttons
      if (in_array($bundle_instance['widget']['type'], array('options_select', 'options_buttons'))
        && in_array($field_info['type'], array_keys(list_field_info()))
      ) {
        $optional_primary_media_fields[$bundle_instance['field_name']] = $bundle_instance['label'];
      }
    }

    $preset_settings = isset($settings['settings']) ? $settings['settings'] : array();

    //Get the predefined value from formatter settings if it exists.
    $default_primary_media_field = 'none';

    $default_primary_media_field = isset($preset_settings['primary_media_field'])
      ? $preset_settings['primary_media_field']
      : $default_primary_media_field;

    $default_primary_media_field = isset($form_state['values']['settings']['primary_media_field'])
      ? $form_state['values']['settings']['primary_media_field']
      : $default_primary_media_field;

    $target_bundle_label = $entity_info['bundles'][$target_bundle]['label'];
    // Display the form for the bundle if the bundle have at if (count($optional_primary_media_fields) > 1) {
    $form['settings'] = array(
      '#title' => t($target_bundle_label . ' primary media field settings'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
      '#description' => t('Set the primary field and define the field and formatter for the each field value or chose the field and formatter from bundle'),
      '#attributes' => array(
        'id' => 'bundle-settings-fieldset',
      ),

    );
    $form['settings']['primary_media_field'] = array(
      '#title' => t('Chose the primary media field'),
      '#description' => t('Choose the primary media and define the field and formmatter for this field. Only fields with "Select list" or "Check boxes/radio buttons" widgets are allowed.'),
      '#type' => 'select',
      '#tree' => TRUE,
      '#options' => $optional_primary_media_fields,
      '#default_value' => $default_primary_media_field,
      '#ajax' => array(
        'callback' => '_field_data_collector_primary_media_field_select_callback',
        'wrapper' => 'bundle-primary-media-field-values-with-fields-and-formatters',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );

    field_data_collector_build_field_values_with_fields_and_formatters_form($form, $form_state, $target_bundle, $target_type, $default_primary_media_field, $preset_settings);


  }
  else {
    $form['settings'] = array(
      '#title' => t('None content type was chosen'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
      '#description' => t('Chose the content type for preset in the select field above'),
      '#attributes' => array(
        'id' => 'bundle-settings-fieldset',
      ),
    );
  }

  return $form;
}


/**
 * Form building function for the part of entity reference primary media formatter
 *
 * @param $main_field
 *      Entity reference field info from field_info_field function
 * @param $main_instance
 *      Instance of the field described above
 * @param $view_mode
 *      The view mode of formatter
 * @param $form
 *      The whole form array of fomatter settings form
 * @param $form_state
 *      Form state of this form
 * @param $target_bundle
 *      The bundle for which this part of form is needed to build
 * @param $target_entity_type
 *      The entity type of target bundles of etity reference field
 * @param $primary_media_field_name
 *      Chosen primary media field name
 * @return mixed
 */
function field_data_collector_build_field_values_with_fields_and_formatters_form(&$form, &$form_state, $target_bundle, $target_entity_type, $primary_media_field_name, $settings) {

  if ($primary_media_field_name != 'none') {

    $primary_media_field = field_info_field($primary_media_field_name);

    if (isset ($primary_media_field['settings']['allowed_values']) && !empty($primary_media_field['settings']['allowed_values'])) {

      $allowed_values = $primary_media_field['settings']['allowed_values'];
      $form['settings']['primary_media_values_fields_with_formatters'] = array(
        '#title' => t("Fields and Formatters for primary media field values"),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#tree' => TRUE,
        '#description' => t('This table defines which field and his formatter for each current field value.'),
        '#attributes' => array(
          'id' => array(
            'bundle-primary-media-field-values-with-fields-and-formatters',
          ),
        ),
      );
      //Constract the form for each primary media field value
      foreach ($allowed_values as $key => $value) {
        field_data_collector_field_and_formatter_form($form, $form_state, $value, $key, $target_entity_type, $target_bundle, $primary_media_field_name, $settings);
      }
    }
    else {
      //If the primary field doesn't have any predefined values, display the form with link on the field settings page
      $admin_path = _field_ui_bundle_admin_path($target_entity_type, $target_bundle);
      $field_instance = field_info_instance($target_entity_type, $primary_media_field_name, $target_bundle);
      $form['settings']['primary_media_values_fields_with_formatters'] = array(
        '#title' => t("No value is already define for this field"),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#tree' => TRUE,
        '#collapsed' => TRUE,
        '#description' => t('This field have no predefined value. You could define that value on <a href="@link">@field field settings </a> page.', array(
          '@link' => url($admin_path . '/fields/' . $primary_media_field_name),
          '@field' => $field_instance['label'],
        )),
        '#attributes' => array(
          'id' => array(
            'bundle-primary-media-field-values-with-fields-and-formatters',
          ),
        ),
      );
    }
  }
  else {
    $form['settings']['primary_media_values_fields_with_formatters'] = array(
      '#type' => 'container',
      '#tree' => TRUE,
      '#attributes' => array(
        'id' => array(
          'bundle-primary-media-field-values-with-fields-and-formatters',
        ),
      ),
    );

    //If user didn't chose the primary media field, display the just form to choose
    // the field and formatter from the bundle
    field_data_collector_field_and_formatter_form($form, $form_state, 'None', 'default', $target_entity_type, $target_bundle, $primary_media_field_name, $settings);

  }

  return $form;
}

/**
 * Form building function for the field and formatter for each primary media field value
 *
 * @param $form
 *    The whole form array of fomatter settings form
 * @param $form_state
 *    Form state of this form
 * @param $value
 *    label of of primary media field value
 * @param $key
 *    machine name of primary media field value
 * @param $target_entity_type
 *    The entity type of target bundles of etity reference field
 * @param $target_bundle
 *    The bundle for which this part of form is needed to build
 * @param $primary_media_field_name
 *    Chosen primary media field name
 */
function field_data_collector_field_and_formatter_form(&$form, &$form_state, $value, $key, $target_entity_type, $target_bundle, $primary_media_field_name, $settings) {
  $form_state_target_bundle_form_values = isset($form_state['values']['settings'])
    ? $form_state['values']['settings']
    : array();

  $form['settings']['primary_media_values_fields_with_formatters'][$key] = array(
    '#title' => t($value),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
    '#description' => t('Set the fields and formatters for each primary media field values'),
    '#attributes' => array(
      'id' => 'bundle-primary-media-field-value-' . $key . '-field-and-formatter-fieldset'
    ),
  );

  //Load all possible field for current content type
  $bundle_instances = field_info_instances($target_entity_type, $target_bundle);
  $bundle_option_list = array(
    'none' => '-None-',
    'title' => 'Title'
  );
  foreach ($bundle_instances as $instance_info) {
    $bundle_option_list[$instance_info['field_name']] = $instance_info['label'];
  }
  if ($primary_media_field_name != 'none') {
    unset($bundle_option_list[$primary_media_field_name]);
  }

  $default_primary_media_field_values_field_number = 0;

  $default_primary_media_field_values_field_number = isset($settings['primary_media_values_fields_with_formatters'][$key]['field_number'])
    ? $settings['primary_media_values_fields_with_formatters'][$key]['field_number']
    : $default_primary_media_field_values_field_number;

  $default_primary_media_field_values_field_number = isset($form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['field_number'])
    ? $form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['field_number']
    : $default_primary_media_field_values_field_number;

  $form['settings']['primary_media_values_fields_with_formatters'][$key]['field_number'] = array(
    '#type' => 'select',
    '#title' => t('Chose the number of fields to display'),
    '#options' => range(1, count($bundle_option_list)),
    '#default_value' => $default_primary_media_field_values_field_number,
    '#prefix' => '<div id ="bundle-primary-media-field-value-' . $key . '-fields-number">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#ajax' => array(
      'callback' => '_field_data_collector_field_and_formatter_number_callback',
      'wrapper' => 'bundle-primary-media-field-value-' . $key . '-fields-and-formatters-container',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#attributes' => array(
      'id' => 'bundle-primary-media-field-value-' . $key . '-fields-and-formatters-container'
    ),
  );

  //Create the number of fieldsets the same as the user choose in selector above
  for ($index = 0; $index <= $default_primary_media_field_values_field_number; $index++) {

    $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index] = array(
      '#title' => t('Field ' . ($index + 1)),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
      '#description' => t('Set the field and formatter for him'),
      '#attributes' => array(
        'id' => 'bundle-primary-media-field-value-' . $key . '-field-and-formatter-' . $index . '-fieldset'
      ),
    );

    //Get stored value from formatter settings
    $default_primary_media_field_values_field_weight = $index;

    $default_primary_media_field_values_field_weight = isset($settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_weight'])
      ? $settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_weight']
      : $default_primary_media_field_values_field_weight;

    $default_primary_media_field_values_field_weight = isset($form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_weight'])
      ? $form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_weight']
      : $default_primary_media_field_values_field_weight;

    //Form to define the weight for each field for current primary media field value
    $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_weight'] = array(
      '#title' => t('Chose field weight'),
      '#type' => 'select',
      '#options' => range(1, count($bundle_option_list)),
      '#tree' => TRUE,
      '#default_value' => $default_primary_media_field_values_field_weight,
      '#attributes' => array(
        'id' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-weight',
      ),
    );


    //Get stored value from formatter settings and form state
    $default_primary_media_field_values_field_label = 0;

    $default_primary_media_field_values_field_label = isset($settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_label'])
      ? $settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_label']
      : $default_primary_media_field_values_field_label;

    $default_primary_media_field_values_field_label = isset($form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_label'])
      ? $form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_label']
      : $default_primary_media_field_values_field_label;


    //Checkbox to select does the field should be displayed or not
    $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_label'] = array(
      '#title' => t('Display the field label'),
      '#type' => 'checkbox',
      '#tree' => TRUE,
      '#attributes' => array(
        'id' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-label',
      ),
    );


    //Get stored value from formatter settings
    $default_primary_media_field_values_field = 'none';

    $default_primary_media_field_values_field = isset($settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_for_value'])
      ? $settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_for_value']
      : $default_primary_media_field_values_field;

    $default_primary_media_field_values_field = isset($form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_for_value'])
      ? $form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_for_value']
      : $default_primary_media_field_values_field;

    //Form to define the field for current primary media field value
    $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['field_for_value'] = array(
      '#title' => t('Chose the field'),
      '#type' => 'select',
      '#options' => $bundle_option_list,
      '#tree' => TRUE,
      '#default_value' => $default_primary_media_field_values_field,
      '#prefix' => '<div id ="bundle-primary-media-field-value-' . $key . '-field-' . $index . '">',
      '#suffix' => '</div>',
      '#ajax' => array(
        'callback' => '_field_data_collector_field_formatter_callback',
        'wrapper' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-formatter-container',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );


    //Container for form to chose the formatter for field chosed above
    $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field'] = array(
      '#type' => 'container',
      '#tree' => TRUE,
      '#attributes' => array(
        'id' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-formatter-container',
      ),
    );

    if ($default_primary_media_field_values_field != 'none' && $default_primary_media_field_values_field != 'title') {

      $formatters_option_list = array('none' => '-None-');
      $field_info = field_info_field($default_primary_media_field_values_field);
      $formatters_option_list += field_ui_formatter_options($field_info['type']);

      //Get stored value from formatter settings
      $default_primary_media_field_values_field_formatter = 'none';

      $default_primary_media_field_values_field_formatter = isset($settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter'])
        ? $settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter']
        : $default_primary_media_field_values_field_formatter;

      $default_primary_media_field_values_field_formatter = isset($form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter'])
        ? $form_state_target_bundle_form_values['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter']
        : $default_primary_media_field_values_field_formatter;

      //Do not display predefined field for current primary media field value if that field was deleted
      if (!in_array($default_primary_media_field_values_field_formatter, array_keys($formatters_option_list))) {
        $default_primary_media_field_values_field_formatter = 'none';
        $settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter_settings'] = array();
      }

      //Form to define the formatter for chosed field for current primary media field value
      $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter'] = array(
        '#title' => t('Chose the formatter'),
        '#type' => 'select',
        '#prefix' => '<div id ="bundle-primary-media-field-value-' . $key . '-field-' . $index . '-formatter">',
        '#suffix' => '</div>',
        '#tree' => TRUE,
        '#options' => $formatters_option_list,
        '#default_value' => $default_primary_media_field_values_field_formatter,
        '#ajax' => array(
          'callback' => '_field_data_collector_field_formatter_settings_callback',
          'wrapper' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-formatter-settings-fieldset',
          'method' => 'replace',
          'effect' => 'fade',
        ),
      );


      if ($default_primary_media_field_values_field_formatter != 'none') {

        $instance = $bundle_instances[$field_info['field_name']];

        $view_mode = 'default';

        // Fill the field instance settings by needed data considering the chosed formatter
        $instance['display'][$view_mode]['settings'] = isset($settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter_settings']['settings'])
          ? $settings['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter_settings']['settings']
          : array();

        $primary_media_value_field_formatter = field_info_formatter_types($default_primary_media_field_values_field_formatter);

        $instance['display'][$view_mode]['settings'] += field_info_formatter_settings($default_primary_media_field_values_field_formatter);
        $instance['display'][$view_mode]['type'] = $default_primary_media_field_values_field_formatter;
        $instance['display'][$view_mode]['module'] = $primary_media_value_field_formatter['module'];

        $formatter_settings_summary = array();
        $function = $primary_media_value_field_formatter['module'] . '_field_formatter_settings_summary';
        if (function_exists($function)) {
          $formatter_settings_summary = $function($field_info, $instance, $view_mode);
        }

        if (!empty($formatter_settings_summary)) {

          //Get the settings form for chosen formatter
          $settings_form = array();
          $function = $primary_media_value_field_formatter['module'] . '_field_formatter_settings_form';
          if (function_exists($function)) {
            $settings_form = $function($field_info, $instance, $view_mode, $form, $form_state);
          }
          //Wrap this settings from in fieldset
          $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter_settings'] = array(
            '#title' => t('Formatter settings for field ' . $instance['label']),
            '#type' => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            '#tree' => TRUE,
            '#attributes' => array(
              'id' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-formatter-settings-fieldset'
            ),
            'settings' => $settings_form,
          );
        }
        else {
          $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter_settings'] = array(
            '#type' => 'container',
            '#tree' => TRUE,
            '#attributes' => array(
              'id' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-formatter-settings-fieldset'
            ),
          );
        }

      }
      else {
        //If the user did not chose the formatter keep just empty contatiner for the formatter settings
        $form['settings']['primary_media_values_fields_with_formatters'][$key]['fields_and_formatters'][$index]['formatter_for_field']['formatter_settings'] = array(
          '#type' => 'container',
          '#tree' => TRUE,
          '#attributes' => array(
            'id' => 'bundle-primary-media-field-value-' . $key . '-field-' . $index . '-formatter-settings-fieldset'
          ),
        );
      }
    }
  }
}

/**
 *  AJAX callback for the bundle field selector in preset settings form
 */
function _field_data_collector_bundle_select_callback($form, $form_state) {
  return $form['settings'];
}


/**
 *  AJAX callback for the primary media field selector in preset settings form
 */
function _field_data_collector_primary_media_field_select_callback($form, $form_state) {
  $array_parents = $form_state['triggering_element']['#array_parents'];
  array_pop($array_parents);
  $temp_form = & $form;
  foreach ($array_parents as $key) {
    $temp_form = & $temp_form[$key];
  }
  return $temp_form['primary_media_values_fields_with_formatters'];
}

/**
 *  AJAX callback for the fields number selector for primary media field value in preset settings form
 */
function _field_data_collector_field_and_formatter_number_callback($form, $form_state) {
  $array_parents = $form_state['triggering_element']['#array_parents'];
  array_pop($array_parents);
  $temp_form = & $form;
  foreach ($array_parents as $key) {
    $temp_form = & $temp_form[$key];
  }
  return $temp_form['fields_and_formatters'];
}

/*
 * AJAX callback for the field selector in primary media field value fieldset preset form
 */
function _field_data_collector_field_formatter_callback($form, $form_state) {
  $array_parents = $form_state['triggering_element']['#array_parents'];
  array_pop($array_parents);
  $temp_form = & $form;
  foreach ($array_parents as $key) {
    $temp_form = & $temp_form[$key];
  }
  return $temp_form['formatter_for_field'];
}

/*
 * AJAX callback for the primary media field value preset settings
 */
function _field_data_collector_field_formatter_settings_callback($form, $form_state) {
  $array_parents = $form_state['triggering_element']['#array_parents'];
  array_pop($array_parents);
  $temp_form = & $form;
  foreach ($array_parents as $key) {
    $temp_form = & $temp_form[$key];
  }
  return $temp_form['formatter_settings'];
}

function field_data_collector_preset_settings_summary($settings, $bundle, $entity_type) {
  $summary = '';
  $entity_info = entity_get_info('node');
  if ($settings['primary_media_field'] != 'none') {
    $primary_media_field_formatter_and_field_for_values_settings = $settings['primary_media_values_fields_with_formatters'];

    $primary_media_field_instance = field_info_instance($entity_type, $settings['primary_media_field'], $bundle);
    $primary_media_field_instance_label = $primary_media_field_instance['label'];

    $summary .= "Primary media field - " . $primary_media_field_instance_label . " <br>";

    $primary_media_field = field_info_field($settings['primary_media_field']);
    $primary_media_field_allowed_values = $primary_media_field['settings']['allowed_values'];

    foreach ($primary_media_field_formatter_and_field_for_values_settings as $primary_field_value => $value_settings) {
      $primary_media_field_value_label = $primary_media_field_allowed_values[$primary_field_value];

      $primary_media_field_value_fields_and_formatters_settings = $value_settings['fields_and_formatters'];

      $dispaly_fields_summary = '';

      foreach ($primary_media_field_value_fields_and_formatters_settings as $display_field_settings) {
        if ($display_field_settings['field_for_value'] != 'none') {
          if ($display_field_settings['field_for_value'] == 'title') {
            if ($display_field_settings['field_label']) {
              $dispaly_fields_summary .= "field with label - Title, formatter - default<br>";
            }
            else {
              $dispaly_fields_summary .= "field - Title , formatter - default<br>";
            }

          }
          else {
            if ($display_field_settings['formatter_for_field']['formatter'] != 'none') {

              $field_info = field_info_field($display_field_settings['field_for_value']);
              $formatters_option_list = field_ui_formatter_options($field_info['type']);
              $formatter_label = $formatters_option_list[$display_field_settings['formatter_for_field']['formatter']];

              $field_instance = field_info_instance($entity_type, $display_field_settings['field_for_value'], $bundle);
              $field_instance_label = $field_instance['label'];

              if ($display_field_settings['field_label']) {
                $dispaly_fields_summary .= "field with label - " . $field_instance_label . " , formatter - " . $formatter_label . "<br>";
              }
              else {
                $dispaly_fields_summary .= "field - " . $field_instance_label . " , formatter - " . $formatter_label . "<br>";
              }
            }
          }
        }
      }
      if (!empty($dispaly_fields_summary)) {
        $summary .= "for value " . $primary_media_field_value_label . " :<br>" . $dispaly_fields_summary;
      }
    }
  }

  else {
    $summary .= "Primary media field - none<br>";

    $primary_media_field_value = 'default';
    $primary_media_field_formatter_and_field_for_values_settings = $settings['primary_media_values_fields_with_formatters'];
    $value_settings = $primary_media_field_formatter_and_field_for_values_settings[$primary_media_field_value];

    $primary_media_field_value_fields_and_formatters_settings = $value_settings['fields_and_formatters'];

    $dispaly_fields_summary = '';

    foreach ($primary_media_field_value_fields_and_formatters_settings as $display_field_settings) {
      if ($display_field_settings['field_for_value'] != 'none') {
        if ($display_field_settings['field_for_value'] == 'title') {
          if ($display_field_settings['field_label']) {
            $dispaly_fields_summary .= "field with label - Title, formatter - default<br>";
          }
          else {
            $dispaly_fields_summary .= "field - Title , formatter - default<br>";
          }

        }
        else {
          if ($display_field_settings['formatter_for_field']['formatter'] != 'none') {

            $field_info = field_info_field($display_field_settings['field_for_value']);
            $formatters_option_list = field_ui_formatter_options($field_info['type']);
            $formatter_label = $formatters_option_list[$display_field_settings['formatter_for_field']['formatter']];

            $field_instance = field_info_instance($entity_type, $display_field_settings['field_for_value'], $bundle);
            $field_instance_label = $field_instance['label'];

            $dispaly_fields_summary .= "field - " . $field_instance_label . " , formatter - " . $formatter_label . "<br>";

          }
        }
      }
    }
    if (!empty($dispaly_fields_summary)) {
      $summary .= $primary_media_field_value . " : <br>" . $dispaly_fields_summary;
    }
  }

  if (empty($settings)) {
    $summary = 'No settings was predefined';
  }
  return $summary;
}


function field_data_collector_edit_preset_form($form, $form_state, $preset_name) {
  $form = array();
  if (!empty($preset_name)) {
    $settings = field_data_collector_load_preset($preset_name);
    $form = field_data_collector_preset_form($form, $form_state, $settings);

    $form['actions']['#type'] = 'actions';
    $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save preset'));
    $form['#submit'][] = 'field_data_collector_add_and_edit_preset_form_submit';
    $form['#validate'][] = 'field_data_collector_add_and_edit_preset_form_validate';

  }
  return $form;
}

/**
 * Form constructor for removing a preset.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function field_data_collector_delete_preset_form($form, $form_state, $preset_name) {
  $output = '';
  if (!empty($preset_name)) {
    $preset = field_data_collector_load_preset($preset_name);

    if (!empty($preset)) {
      $form['preset_machine_name'] = array('#type' => 'value', '#value' => $preset_name);
      $output = confirm_form($form,
        t('Are you sure you want to delete the preset %preset?', array('%preset' => $preset['label'])),
        'admin/config/media/field-data-collector-presets',
        t('If you have any formatter using this preset, they settings will be lost. This action cannot be undone.'),
        t('Delete'), t('Cancel'),
        'confirm'
      );
    }
  }
  return $output;
}


/**
 * Form submission handler for field_data_collector_delete_preset_form().
 *
 * Removes a preset from a presets settings variable.
 */
function field_data_collector_delete_preset_form_submit($form, &$form_state) {

  $preset_name = isset($form_state['values']['preset_machine_name']) ? $form_state['values']['preset_machine_name'] : FALSE;

  if ($preset_name && field_data_collector_preset_exists($preset_name) && $form_state['values']['confirm']) {
    $preset = field_data_collector_load_preset($preset_name);

    field_data_collector_delete_preset($preset_name);
    drupal_set_message(t('The preset %preset has been deleted from preset storage.', array(
      '%preset' => $preset['label'],
    )));

  }
  else {
    drupal_set_message(t('There was a problem removing the preset from the presets storage.', array(), 'error'));
  }

  $form_state['redirect'] = FIELD_DATA_COLLECTOR_PRESET_ADMIN_PATH;
}

/**
 * Return true if the preset with such preset name have already exist.
 *
 * @param $preset_name
 * @return bool
 */
function field_data_collector_preset_exists($preset_name) {
  $presets_settings = field_data_collector_load_presets();
  return isset($presets_settings[$preset_name]);
}

/**
 * Load the preset with specified name
 *
 * @param $preset_name
 * @return null
 */
function field_data_collector_load_preset($preset_name) {
  $presets_settings = field_data_collector_load_presets();
  if (isset($presets_settings[$preset_name])) {
    return $presets_settings[$preset_name];
  }
  else {
    return NULL;
  }
}

/**
 * Delete the preset form presets settings.
 *
 * @param $preset_name
 */
function field_data_collector_delete_preset($preset_name) {
  $presets_settings = field_data_collector_load_presets();
  if (isset($presets_settings[$preset_name])) {
    unset($presets_settings[$preset_name]);
    _field_data_collector_save_presets_settings($presets_settings);
  }
}

/**
 * Load the presets settings from variable.
 *
 * If variable is empty, the empty array will be returned.
 *
 * @return array|mixed
 */
function field_data_collector_load_presets() {
  $presets_settings = & drupal_static(__FUNCTION__);
  if (!isset($presets_settings)) {
    $serialized_presets_settings = variable_get('field_data_collector_formatter_presets', '');
    $unserialized_presets_settings = unserialize($serialized_presets_settings);
    $presets_settings = $unserialized_presets_settings != FALSE ? $unserialized_presets_settings : array();
  }
  return $presets_settings;
}

/**
 * Save the preset settings in the variable.
 *
 * @param $preset_name
 * @param $preset_label
 * @param $preset_bundle
 * @param $preset_description
 * @param $preset_summary
 * @param $preset_settings
 */
function field_data_collector_save_preset($preset_name, $preset_label, $preset_bundle, $preset_description, $preset_summary, $preset_settings) {
  $presets_settings = field_data_collector_load_presets();
  $presets_settings[$preset_name] = array(
    'machine_name' => $preset_name,
    'label' => $preset_label,
    'description' => $preset_description,
    'bundle_name' => $preset_bundle,
    'settings' => $preset_settings,
    'summary' => $preset_summary,
  );
  _field_data_collector_save_presets_settings($presets_settings);
}

/**
 * Save the updated presets settings in variable.
 *
 * @param $presets_settings
 */
function _field_data_collector_save_presets_settings($presets_settings) {
  variable_set('field_data_collector_formatter_presets', serialize($presets_settings));
  drupal_static_reset('field_data_collector_load_presets_settings');
}

/**
 * Return the list of presets for current bundle
 *
 * @param $bundle
 */
function field_data_collection_load_presets_for_bundle($bundle) {
  $presets = field_data_collector_load_presets();
  $presets_for_bundle = array();
  foreach ($presets as $preset_machine_name => $preset) {
    if ($preset['bundle_name'] == $bundle) {
      $presets_for_bundle[$preset_machine_name] = $preset['label'];
    }
  }
  return $presets_for_bundle;
}