<?php
/**
 * @file
 * library_features_content_type_events.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_events_node_info() {
  $items = array(
    'events' => array(
      'name' => t('Events'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
