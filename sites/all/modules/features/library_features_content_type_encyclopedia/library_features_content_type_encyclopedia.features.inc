<?php
/**
 * @file
 * library_features_content_type_encyclopedia.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_encyclopedia_node_info() {
  $items = array(
    'encyclopedia' => array(
      'name' => t('Encyclopedia'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
