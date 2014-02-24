<?php
/**
 * @file
 * library_features_content_type_location.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function library_features_content_type_location_taxonomy_default_vocabularies() {
  return array(
    'location_classification' => array(
      'name' => 'Location Classification',
      'machine_name' => 'location_classification',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
