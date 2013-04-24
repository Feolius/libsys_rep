<?php
/**
 * @file
 * library_features_content_type_publications.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_publications_node_info() {
  $items = array(
    'publications' => array(
      'name' => t('Publications'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
