<?php

/**
 * @file
 * Menu callbacks and helpers for admin part.
 */

/**
 * Settings form for library admin settings.
 */

function library_admin_settings_form() {

  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => 'Footer',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['footer']['library_admin_language'] = array(
    '#type' => 'textfield',
    '#title' => t('List language'),
    '#description' => t('Enter a comma-separated all language abbreviations, they is displayed in the footer. For example: us, fr, de'),
    '#default_value' => variable_get('library_admin_language'),
  );

  return system_settings_form($form);
}