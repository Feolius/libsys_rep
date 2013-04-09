<?php
/**
 * @file
 * features_library_ct_people.features.inc
 */

/**
 * Implements hook_node_info().
 */
function features_library_ct_people_node_info() {
  $items = array(
    'people' => array(
      'name' => t('People'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
