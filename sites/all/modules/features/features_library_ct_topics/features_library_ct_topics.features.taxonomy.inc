<?php
/**
 * @file
 * features_library_ct_topics.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function features_library_ct_topics_taxonomy_default_vocabularies() {
  return array(
    'topic_kinds' => array(
      'name' => 'Topic kinds',
      'machine_name' => 'topic_kinds',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
