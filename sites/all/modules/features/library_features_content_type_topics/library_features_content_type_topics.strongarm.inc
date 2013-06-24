<?php
/**
 * @file
 * library_features_content_type_topics.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function library_features_content_type_topics_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__topics';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'collection_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'collection_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'home_top' => array(
        'custom_settings' => TRUE,
      ),
      'home_left' => array(
        'custom_settings' => TRUE,
      ),
      'home_middle' => array(
        'custom_settings' => TRUE,
      ),
      'home_right' => array(
        'custom_settings' => TRUE,
      ),
      'home_bottom' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_topics';
  $strongarm->value = '0';
  $export['language_content_type_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_topics';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_topics';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_topics';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_topics';
  $strongarm->value = '1';
  $export['node_preview_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_topics';
  $strongarm->value = 0;
  $export['node_submitted_topics'] = $strongarm;

  return $export;
}
