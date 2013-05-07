<?php
/**
 * @file
 * library_features_content_type_topics.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_topics_node_info() {
  $items = array(
    'topics' => array(
      'name' => t('Topics'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
