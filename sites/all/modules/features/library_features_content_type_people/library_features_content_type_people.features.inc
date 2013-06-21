<?php
/**
 * @file
 * library_features_content_type_people.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_people_node_info() {
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
