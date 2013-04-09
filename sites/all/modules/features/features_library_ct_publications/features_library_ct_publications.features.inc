<?php
/**
 * @file
 * features_library_ct_publications.features.inc
 */

/**
 * Implements hook_node_info().
 */
function features_library_ct_publications_node_info() {
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
