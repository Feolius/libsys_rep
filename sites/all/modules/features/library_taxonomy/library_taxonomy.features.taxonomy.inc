<?php
/**
 * @file
 * library_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function library_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'audio_albums' => array(
      'name' => 'Audio Albums',
      'machine_name' => 'audio_albums',
      'description' => 'Albums from audio files',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'exif' => array(
      'name' => 'Exif',
      'machine_name' => 'exif',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'file_collection' => array(
      'name' => 'File collection',
      'machine_name' => 'file_collection',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'file_folder' => array(
      'name' => 'File folder',
      'machine_name' => 'file_folder',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'file_type' => array(
      'name' => 'File Type',
      'machine_name' => 'file_type',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'galleries' => array(
      'name' => 'Galleries',
      'machine_name' => 'galleries',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'images' => array(
      'name' => 'Images',
      'machine_name' => 'images',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'publication' => array(
      'name' => 'Publication',
      'machine_name' => 'publication',
      'description' => '',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
