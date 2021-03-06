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

  // Titles of the homepages blocks.
  $form['home']['library_admin_left_block_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of the left block.'),
    '#description' => t('Title of the left block on the homepage.'),
    '#default_value' => variable_get('library_admin_left_block_text'),
  );

  $form['home']['library_admin_middle_block_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of the middle block.'),
    '#description' => t('Title of the middle block on the homepage.'),
    '#default_value' => variable_get('library_admin_middle_block_text'),
  );

  $form['home']['library_admin_right_block_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of the right block.'),
    '#description' => t('Title of the right block on the homepage.'),
    '#default_value' => variable_get('library_admin_right_block_text'),
  );

  $form['library_admin_clear_temp_folder'] = array(
    '#type' => 'submit',
    '#value' => t('Remove files in temp folder'),
    '#submit' => array('library_admin_clear_temp_folder_submit')
  );

  // Facet collection row number.
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

  // Collection pager settings.
  $form['collection_pager_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for library pager'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['collection_pager_settings']['collection_pager_entities_number_per_solr_query'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of entities per solr query'),
    '#description' => t('Set number of entities (nodes), which will be saved in the session to avoid often queries to solr. This number
     means, how much nodes will be retrieved per one solr query.'),
    '#default_value' => variable_get('collection_pager_entities_number_per_solr_query', 5),
  );

  // Library page content types
  $form['library_page_content_types_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Library page content types'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $content_types = node_type_get_types();
  $available_content_types = array();
  foreach($content_types as $content_type_name => $content_type) {
    $available_content_types[$content_type_name] = $content_type->name;
  }

  $form['library_page_content_types_settings']['library_page_content_types'] = array(
    '#type' => 'checkboxes',
    '#options' => $available_content_types,
    '#default_value' => variable_get('library_page_content_types', array()),
    '#description' => t('Choose content types, which will be available in the filter block.'),
  );

  // Book field.
  $form['book_field'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for Book field'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['book_field']['library_pdf2swf_path'] = array(
    '#type' => 'textfield',
    '#title' => t('pdf2swf path'),
    '#description' => t('Path to pdf2swf tool'),
    '#default_value' => variable_get('library_pdf2swf_path', '/usr/local/bin/pdf2swf'),
  );

  $form['book_field']['library_swfrender_path'] = array(
    '#type' => 'textfield',
    '#title' => t('swfrender path'),
    '#description' => t('Path to swfrender tool'),
    '#default_value' => variable_get('library_swfrender_path', '/usr/local/bin/swfrender'),
  );

  $form['book_field']['library_pdf2json_path'] = array(
    '#type' => 'textfield',
    '#title' => t('pdf2json path'),
    '#description' => t('Path to pdf2json tool'),
    '#default_value' => variable_get('library_pdf2json_path', '/usr/local/bin/pdf2json'),
  );

  // Data collector.
  $form['field_data_collector'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for Field Data Collector tabs'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['field_data_collector']['library_field_data_collector_items_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Items number'),
    '#description' => t('The number of items in each tab'),
    '#default_value' => variable_get('library_field_data_collector_items_number', '50'),
  );

  $form['field_data_collector']['library_field_data_collector_more_items_text'] = array(
    '#type' => 'textfield',
    '#title' => t('More items text'),
    '#description' => t('The text will displayed when the number of items more than limit above'),
    '#default_value' => variable_get('library_field_data_collector_more_items_text', 'Not everything shown'),
  );

  // Copyright information for images.
  $form['copyright_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for Copyright information for images'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['copyright_information']['library_field_copyright_information'] = array(
    '#type' => 'textarea',
    '#title' => t('Text'),
    '#description' => t('The text will displayed when we will click on the download button for downloading file'),
    '#default_value' => variable_get('library_field_copyright_information', ''),
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
