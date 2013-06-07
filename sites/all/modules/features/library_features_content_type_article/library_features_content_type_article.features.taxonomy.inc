<?php
/**
 * @file
 * library_features_content_type_article.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function library_features_content_type_article_taxonomy_default_vocabularies() {
  return array(
    'home_region' => array(
      'name' => 'Home region',
      'machine_name' => 'home_region',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
