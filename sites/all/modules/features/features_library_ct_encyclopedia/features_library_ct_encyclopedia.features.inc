<?php
/**
 * @file
 * features_library_ct_encyclopedia.features.inc
 */

/**
 * Implements hook_node_info().
 */
function features_library_ct_encyclopedia_node_info() {
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
