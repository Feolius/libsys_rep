<?php
/**
 * @file
 * library_features_content_type_events.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function library_features_content_type_events_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__events';
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
        'path' => array(
          'weight' => '17',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__events'] = $strongarm;

  return $export;
}
