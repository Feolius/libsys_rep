<?php
/**
 * @file
 * to_home.features.inc
 */

/**
 * Implements hook_node_info().
 */
function to_home_node_info() {
  $items = array(
    'files' => array(
      'name' => t('Files'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'people' => array(
      'name' => t('People'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
