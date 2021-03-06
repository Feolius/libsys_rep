<?php
/**
 * @file
 * library_features_content_type_topics.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function library_features_content_type_topics_taxonomy_default_vocabularies() {
  return array(
    'taxonomy_source' => array(
      'name' => 'Source',
      'machine_name' => 'taxonomy_source',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'topic_kinds' => array(
      'name' => 'Topic kinds',
      'machine_name' => 'topic_kinds',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
