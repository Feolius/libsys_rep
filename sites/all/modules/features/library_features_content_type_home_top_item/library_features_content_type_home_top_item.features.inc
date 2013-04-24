<?php
/**
 * @file
 * library_features_content_type_home_top_item.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_home_top_item_node_info() {
  $items = array(
    'home_top_item' => array(
      'name' => t('Home top item'),
      'base' => 'node_content',
      'description' => t('Entries for the 3 boxes on top of homepage'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
