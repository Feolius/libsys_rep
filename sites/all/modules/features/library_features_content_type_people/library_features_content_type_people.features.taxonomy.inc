<?php
/**
 * @file
 * library_features_content_type_people.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function library_features_content_type_people_taxonomy_default_vocabularies() {
  return array(
    'taxonomy_source' => array(
      'name' => 'Source',
      'machine_name' => 'taxonomy_source',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
