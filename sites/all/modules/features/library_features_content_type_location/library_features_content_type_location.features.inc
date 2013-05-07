<?php
/**
 * @file
 * library_features_content_type_location.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_location_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
