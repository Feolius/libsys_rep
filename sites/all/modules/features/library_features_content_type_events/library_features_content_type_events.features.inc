<?php
/**
 * @file
 * library_features_content_type_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function library_features_content_type_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function library_features_content_type_events_node_info() {
  $items = array(
    'events' => array(
      'name' => t('Events'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
