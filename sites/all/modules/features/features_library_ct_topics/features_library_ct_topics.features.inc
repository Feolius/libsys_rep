<?php
/**
 * @file
 * features_library_ct_topics.features.inc
 */

/**
 * Implements hook_node_info().
 */
function features_library_ct_topics_node_info() {
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
