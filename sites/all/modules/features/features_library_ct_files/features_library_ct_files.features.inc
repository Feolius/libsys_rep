<?php
/**
 * @file
 * features_library_ct_files.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_library_ct_files_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function features_library_ct_files_node_info() {
  $items = array(
    'files' => array(
      'name' => t('Files'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
