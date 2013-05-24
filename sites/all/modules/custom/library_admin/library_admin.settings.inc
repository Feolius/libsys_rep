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

  $form['clear_temp_folder'] = array(
    '#type' => 'submit',
    '#value' => t('Remove files in temp folder'),
    '#submit' => array('library_admin_clear_temp_folder')
  );

  return system_settings_form($form);
}

function library_admin_clear_temp_folder(){
  $result = db_query('SELECT fid FROM {file_managed} WHERE status <> :permanent', array(
    ':permanent' => FILE_STATUS_PERMANENT,
  ));
  foreach ($result as $row) {
    if ($file = file_load($row->fid)) {
      $references = file_usage_list($file);
      if (empty($references)) {
        if (!file_delete($file)) {
          watchdog('file system', 'Could not delete temporary file "%path" during garbage collection', array('%path' => $file->uri), WATCHDOG_ERROR);
        }
      }
      else {
        watchdog('file system', 'Did not delete temporary file "%path" during garbage collection, because it is in use by the following modules: %modules.', array('%path' => $file->uri, '%modules' => implode(', ', array_keys($references))), WATCHDOG_INFO);
      }
    }
  }
}