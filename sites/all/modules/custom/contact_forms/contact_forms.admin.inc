<?php

function contact_forms_settings_form($form, &$form_state) {
  $form = array();
  $form['contact_forms_technical_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Technical contact form email'),
    '#default_value' => variable_get('contact_forms_technical_email', 'technical@library.ellenwhite.org'),
    '#description' => t('Specify the technical contact form email.'),
  );
  $form['contact_forms_spiritual_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Spiritual contact form email'),
    '#default_value' => variable_get('contact_forms_spiritual_email', 'spiritual@library.ellenwhite.org'),
    '#description' => t('Specify the spiritual contact form email.'),
  );
  $form['contact_forms_other_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Other contact form email'),
    '#default_value' => variable_get('contact_forms_other_email', 'other@library.ellenwhite.org'),
    '#description' => t('Specify the other contact form email.'),
  );
  return system_settings_form($form);
}


function contact_forms_settings_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['contact_forms_technical_email'])) {
    form_set_error('technical_email', t('You must enter a valid e-mail address.'));
  }
  if (!valid_email_address($form_state['values']['contact_forms_spiritual_email'])) {
    form_set_error('spirital_email', t('You must enter a valid e-mail address.'));
  }
  if (!valid_email_address($form_state['values']['contact_forms_other_email'])) {
    form_set_error('other_email', t('You must enter a valid e-mail address.'));
  }

}

function contact_forms_settings_form_submit($form, &$form_state) {
  drupal_set_message('The contact forms settings successfully saved');
}