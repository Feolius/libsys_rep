<?php
/**
 * @file
 * features_library_ct_files.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function features_library_ct_files_taxonomy_default_vocabularies() {
  return array(
    'file_category' => array(
      'name' => 'File category',
      'machine_name' => 'file_category',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
