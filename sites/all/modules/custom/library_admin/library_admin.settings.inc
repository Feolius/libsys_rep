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
    '#title' => t('Footer'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['copyright'] = array(
    '#type' => 'fieldset',
    '#title' => t('Copyright'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['footer']['library_admin_language'] = array(
    '#type' => 'textfield',
    '#title' => t('List language'),
    '#description' => t('Enter a comma-separated all language abbreviations, they is displayed in the footer. For example: us, fr, de.'),
    '#default_value' => variable_get('library_admin_language'),
  );

  $form['footer']['library_admin_copyright'] = array(
    '#type' => 'textfield',
    '#title' => t('Copyright text'),
    '#description' => t('Copyright text to display in the footer.'),
    '#default_value' => variable_get('library_admin_copyright'),
  );

  $form['copyright']['library_admin_text_to_copyright'] = array(
    '#type' => 'textfield',
    '#title' => t('Text to copyright'),
    '#description' => t('Text to page with copyright text.'),
    '#default_value' => variable_get('library_admin_text_to_copyright'),
  );

  $form['copyright']['library_admin_path_to_copyright'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to copyright'),
    '#description' => t('Path to page with copyright text.'),
    '#default_value' => variable_get('library_admin_path_to_copyright'),
  );

  return system_settings_form($form);
}