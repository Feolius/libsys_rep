<?php

/**
 * @file
 * Administration settings for multistep_adl.
 */

/**
 * Form used for administering multistep_adl workflow settings.
 */
function multistep_adl_admin_settings_workflow_form($form, &$form_state) {
  $form = array();
  $form['multistep_adl_status_revisions'] = array(
    '#type' => 'radios',
    '#title' => t('Revisions'),
    '#description' => t('Sets how multistep_adl will interact with node revisioning, <em>if revisioning is enabled for the content type</em>.
      <ul><li><strong>Any step</strong> will follow the standard revision settings
      (i.e. new revisions will be created after each successful submission, regardless of the step).</li>
      <li><strong>Any step, after node completion</strong> will create new revisions after each successful submission, regardless of the step, only after all steps have been submitted successfully at least once
      (i.e. after the node is considered <em>complete</em>).</li>
      <li><strong>Last step</strong> will create new revisions whenever you submit the last step of the form, regardless of whether the node is considered <em>complete</em> or not.
      (i.e. it will create a new revision after the last step even if some steps were skipped).</li>
      <li><strong>Last step, after node completion</strong> will create a new revision only when subitting the last step of the form, and only if all the steps have been successfully submitted at least once
      (i.e. after the node is considered <em>complete</em>).</li></ul>'
    ),
    '#default_value' => variable_get('multistep_adl_status_revisions', 'default'),
    '#options' => array(
      'default' => t('Any step (Default)'),
      'complete' => t('Any step, after node completion'),
      'last' => t('Last step'),
      'last-complete' => t('Last step, after node completion'),
    ),
    '#weight' => -10,
  );
  $form['multistep_adl_status_publishing'] = array(
    '#type' => 'radios',
    '#title' => t('Publishing'),
    '#description' => t('Sets how multistep_adl will interact with the node published status, <em>if publishing is enabled for the content type</em>.
      <ul><li><strong>At node creation</strong> will follow the standard workflow settings
      (i.e. the node will be published when created).</li>
      <li><strong>At node completion</strong> will hold off publishing the node until all steps have been successfully submitted
      (i.e. when the node is considered <em>complete</em>).</li></ul>'
    ),
    '#default_value' => variable_get('multistep_adl_status_publishing', 'default'),
    '#options' => array(
      'default' => t('At node creation (Default)'),
      'complete' => t('At node completion'),
    ),
    '#weight' => -9,
  );
  $form['multistep_adl_workflow_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Workflow mode'),
    '#description' => t('Disables navigation block links for steps that have not been submitted') . '<br /><strong>' . t('Note: This does not remove access from those steps, it merely displays the links as static text instead.') . '</strong>',
    '#options' => array(
      'free' => t('Steps can be submitted in any order (Default)'),
      'direct' => t('Steps can be submitted only in one direction (Wizard)'),
    ),
    '#default_value' => variable_get('multistep_adl_workflow_mode', 'free'),
    '#weight' => -8,
  );
  $form['multistep_adl_show_step_numbers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show step numbers'),
    '#description' => t('Show step numbers in navigation block.'),
    '#default_value' => variable_get('multistep_adl_show_step_numbers', FALSE),
    '#weight' => -6,
  );
  return system_settings_form($form);
}

/**
 * Form used for changing multistep_adl form labels.
 */
function multistep_adl_admin_settings_design_form($form, &$form_state) {
  drupal_set_message(t('Saving these strings will disable their translation via Drupal\'s language system. Use the reset button to return them to the original state.'), 'warning');
  $form = array();
  $form['multistep_adl_button_prev'] = array(
    '#type' => 'textfield',
    '#title' => t('Previous button'),
    '#description' => t('This button will bring you back one step. To omit this button, remove any text and leave this field blank.'),
    '#default_value' => variable_get('multistep_adl_button_prev', t('< Previous')),
    '#weight' => -10,
  );
  $form['multistep_adl_button_next'] = array(
    '#type' => 'textfield',
    '#title' => t('Next button'),
    '#description' => t('This button will move you forward one step.'),
    '#default_value' => variable_get('multistep_adl_button_next', t('Next >')),
    '#required' => TRUE,
    '#weight' => -9,
  );
  $form['multistep_adl_button_save'] = array(
    '#type' => 'textfield',
    '#title' => t('Save button'),
    '#description' => t('This button will save the form while remaining in the current step. To omit this button, remove any text and leave this field blank.'),
    '#default_value' => variable_get('multistep_adl_button_save', t('Save')),
    '#weight' => -8,
  );
  $form['multistep_adl_button_done'] = array(
    '#type' => 'textfield',
    '#title' => t('Done button'),
    '#description' => t('This button will save the form and redirect you to the node view.'),
    '#default_value' => variable_get('multistep_adl_button_done', t('Done')),
    '#required' => TRUE,
    '#weight' => -7,
  );
  return system_settings_form($form);
}

/**
 * Form used for changing multistep_adl form labels.
 */
function multistep_adl_admin_settings_reset_form($form, &$form_state) {
  $form = array();
  $form['#description'] = t('This form will reset all the step data for the selected content type. Use this if you just enabled multistep_adl for a content type that already contained nodes.') . '<br /><strong>' . t('Warning! Resetting the tables for a content type that already had multistep_adl enabled could result in the loss of the step data!') . '</strong>';
  $options = array('' => '- Select -');
  foreach (node_type_get_types() as $type) {
    if (is_multistep_adl($type)) {
      $options[$type->type] = $type->name;
    }
  }
  $form['multistep_adl_type'] = array(
    '#type' => 'select',
    '#title' => t('Content type'),
    '#options' => $options,
    '#required' => TRUE,
    '#weight' => -1,
  );
  // Show reset button if multistep_adl is enabled for this content type.
  $form['multistep_adl_reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset data'),
    '#weight' => 1,
    '#access' => user_access('administer multistep adl'),
  );
  return $form;
}

/**
 * Resets the multistep_adl table data for the selected content type.
 */
function multistep_adl_admin_settings_reset_form_submit($form, &$form_state) {
  _multistep_adl_reset_data($form_state['values']['multistep_adl_type']);
  drupal_set_message(t('Data was reset successfully.'));
}


function multistep_adl_manage_steps_form($form, &$form_state, $entity_type, $bundle) {
  if (is_object($bundle)) {
    $bundle = $bundle->type;
  }
  $steps = multistep_adl_get_steps($bundle);
  $first_step = multistep_adl_get_first($bundle);
  $step_settings = drupal_json_decode(variable_get('multistep_adl_steps_settings'));
  $admin_path = _field_ui_bundle_admin_path($entity_type, $bundle);

  if (empty($steps)) {
    drupal_set_message(t('This content type has no field group with Multistep ADL formatter. You can add such field goups on <a href="@link">Manage fields</a> page.', array('@link' => url($admin_path . '/fields'))), 'warning');
    return $form;
  }

  $optional_steps = array('none' => '-None-');
  foreach ($steps as $step) {
    $optional_steps[$step->group_name] = $step->label;
  }


  $optional_fields = array('none' => '-None-');
  $first_step_fields = $steps[$first_step]->children;
  foreach ($first_step_fields as $field_name) {
    $field_instance = field_info_instance($entity_type, $field_name, $bundle);
    if (in_array($field_instance['widget']['type'], array('options_select', 'options_buttons'))) {
      $optional_fields[$field_instance['field_name']] = $field_instance['label'];
    }
  }


  if (isset($step_settings[$bundle]['determining_field']) && isset($optional_fields[$step_settings[$bundle]['determining_field']])) {
    $default_field = !empty($form_state['values']['determining_field_select']) ? $form_state['values']['determining_field_select'] : $step_settings[$bundle]['determining_field'];
  }
  else {
    $default_field = !empty($form_state['values']['determining_field_select']) ? $form_state['values']['determining_field_select'] : 'none';

  }

  $form['determining_field_fieldset'] = array(
    '#title' => t('Field From First Step "' . $optional_steps[$first_step] . '" '),
    // The prefix/suffix provide the div that we're replacing, named by
    // #ajax['wrapper'] above.
    '#prefix' => '<div id="determining-field-fieldset-div">',
    '#suffix' => '</div>',
    '#type' => 'fieldset',
    '#description' => t('Chose the field from step ' . $optional_steps[$first_step] . ' to determine the next step for each value of that field.'),
  );


  $form['determining_field_fieldset']['determining_field_select'] = array(
    '#title' => t('Chose the first step field'),
    '#description' => t('The next step will be defined by values of that field. Only fields with "Select list" or "Check boxes/radio buttons" widgets are allowed.'),
    '#type' => 'select',
    '#options' => $optional_fields,
    '#default_value' => $default_field,
    '#ajax' => array(
      'callback' => '_multistep_adl_ajax_determining_field_select_callback',
      'wrapper' => 'determining-field-values-with-steps-div',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div id="determining-field-div">',
    '#suffix' => '</div>',
  );


  if ($default_field != 'none') {

    $field = field_info_field($default_field);

    if (isset ($field['settings']['allowed_values']) && !empty($field['settings']['allowed_values'])) {
      $allowed_values = $field['settings']['allowed_values'];
      $form['determining_field_fieldset']['determining_field_values_with_steps_fieldset'] = array(
        '#title' => t("Next Step - Field Values Table"),
        // The prefix/suffix provide the div that we're replacing, named by
        // #ajax['wrapper'] above.
        '#prefix' => '<div id="determining-field-values-with-steps-div">',
        '#suffix' => '</div>',
        '#type' => 'fieldset',
        '#description' => t('This table defines which step will be the next for each current field value.'),
      );
      unset($optional_steps[$first_step]);
      $default_field_values_step = 'none';
      foreach ($allowed_values as $key => $value) {
        if (isset($step_settings[$bundle]['values'][$key]) && isset($optional_steps[$step_settings[$bundle]['values'][$key]])) {
          $default_field_values_step = $step_settings[$bundle]['values'][$key];
        }
        $form['determining_field_fieldset']['determining_field_values_with_steps_fieldset']['field_value_' . $key] = array(
          '#title' => t('Chose the next step for value - <i>' . $value . '</i>'),
          '#type' => 'select',
          '#options' => $optional_steps,
          '#default_value' => $default_field_values_step,
        );
      }
    }
    else {
      $form['determining_field_fieldset']['determining_field_values_with_steps_fieldset'] = array(
        '#title' => t("No value is already define for this field"),
        // The prefix/suffix provide the div that we're replacing, named by
        // #ajax['wrapper'] above.
        '#prefix' => '<div id="determining-field-values-with-steps-div">',
        '#suffix' => '</div>',
        '#type' => 'fieldset',
        '#description' => t('This field have no predefined value. You could define that value on <a href="@link">@field field settings </a> page.', array(
          '@link' => url($admin_path . '/fields/' . $default_field),
          '@field' => $optional_fields[$default_field]
        )),
      );
    }

  }
  else {
    $form['determining_field_fieldset']['determining_field_values_with_steps_fieldset'] = array(
      '#title' => t("The field hasn't already chosen"),
      // The prefix/suffix provide the div that we're replacing, named by
      // #ajax['wrapper'] above.
      '#prefix' => '<div id="determining-field-values-with-steps-div">',
      '#suffix' => '</div>',
      '#type' => 'fieldset',
      '#description' => t('Please chose field from fist step to define the next step for each value of this field.'),
    );
  }


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function _multistep_adl_ajax_determining_field_select_callback($form, $form_state) {
  return $form['determining_field_fieldset']['determining_field_values_with_steps_fieldset'];
}

function multistep_adl_manage_steps_form_submit($form, &$form_state) {
  if (isset($form_state['build_info']['args'][0]) && $form_state['build_info']['args'][0] = 'node') {
    $bundle = $form_state['build_info']['args'][1]->type;
    $multistep_step_settings = array();
    foreach ($form_state['values'] as $form_element_name => $value) {
      $exploded_form_element_name = explode('_', $form_element_name, 3);
      if ($exploded_form_element_name != FALSE &&
        $exploded_form_element_name[0] == 'field' &&
        $exploded_form_element_name[1] == 'value'
      ) {
        if ($value != 'none') {
          $multistep_step_settings['values'][$exploded_form_element_name[2]] = $value;
        }
      }
    }
    $multistep_step_settings['determining_field'] = $form_state['values']['determining_field_select'];
    $old_settings = drupal_json_decode(variable_get('multistep_adl_steps_settings', '{}'));
    $old_settings[$bundle] = $multistep_step_settings;
    variable_set('multistep_adl_steps_settings', drupal_json_encode($old_settings));
    drupal_set_message(t('Your settings have been successfully saved'));
  }

}

