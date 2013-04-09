<?php
/**
 * @file
 * features_library_ct_location.features.inc
 */

/**
 * Implements hook_node_info().
 */
function features_library_ct_location_node_info() {
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
