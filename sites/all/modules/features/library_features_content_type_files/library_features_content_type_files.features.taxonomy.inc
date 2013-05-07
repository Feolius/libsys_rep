<?php
/**
 * @file
 * library_features_content_type_files.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function library_features_content_type_files_taxonomy_default_vocabularies() {
  return array(
    'audio_albums' => array(
      'name' => 'Audio Albums',
      'machine_name' => 'audio_albums',
      'description' => 'Albums from audio files',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'file_category' => array(
      'name' => 'File category',
      'machine_name' => 'file_category',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'source' => array(
      'name' => 'Provenance',
      'machine_name' => 'source',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
