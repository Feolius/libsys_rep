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
    '#collapsed' => TRUE,
  );

  $form['copyright'] = array(
    '#type' => 'fieldset',
    '#title' => t('Copyright'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['home'] = array(
    '#type' => 'fieldset',
    '#title' => t('Home'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
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

  $form['home']['library_admin_welcome_text'] = array(
    '#type' => 'textarea',
    '#title' => t(''),
    '#description' => t('Welcome text for homepage.'),
    '#default_value' => variable_get('library_admin_welcome_text'),
  );

  $form['library_admin_clear_temp_folder'] = array(
    '#type' => 'submit',
    '#value' => t('Remove files in temp folder'),
    '#submit' => array('library_admin_clear_temp_folder_submit')
  );

  $form['facet_collection_rows_number_selector'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rows number selector settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['facet_collection_rows_number_selector']['facet_collection_rows_number_variants'] = array(
    '#type' => 'textfield',
    '#title' => t(''),
    '#description' => t('Space separated variants of possible numbers of results in library page. The first number will be used by default'),
    '#default_value' => variable_get('facet_collection_rows_number_variants', '25 50 100'),
  );

  $form['collection_pager_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for pager'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['collection_pager_settings']['collection_pager_entities_number_per_solr_query'] = array(
    '#type' => 'textfield',
    '#title' => t('Preloaded entites number'),
    '#description' => t('Set number of entities (nodes), which will be saved is session to avoid often queries to solr. This number
     means, how much nodes will be retrieved per one solr query.'),
    '#default_value' => variable_get('collection_pager_entities_number_per_solr_query', 5),
  );

  return system_settings_form($form);
}

function library_admin_clear_temp_folder_submit() {
  $result = db_query('SELECT fid FROM {file_managed} WHERE status <> :permanent',
    array(
      ':permanent' => FILE_STATUS_PERMANENT,
    )
  );
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
