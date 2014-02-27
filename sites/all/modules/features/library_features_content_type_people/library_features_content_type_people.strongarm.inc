<?php
/**
 * @file
 * library_features_content_type_people.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function library_features_content_type_people_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_people';
  $strongarm->value = '0';
  $export['comment_anonymous_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_people';
  $strongarm->value = 1;
  $export['comment_default_mode_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_people';
  $strongarm->value = '50';
  $export['comment_default_per_page_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_people';
  $strongarm->value = 1;
  $export['comment_form_location_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_people';
  $strongarm->value = '2';
  $export['comment_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_people';
  $strongarm->value = '0';
  $export['comment_preview_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_people';
  $strongarm->value = 1;
  $export['comment_subject_field_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__people';
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
      'library_snippet' => array(
        'custom_settings' => TRUE,
      ),
      'map_overlay' => array(
        'custom_settings' => FALSE,
      ),
      'thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'connections' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '65',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_people';
  $strongarm->value = '1';
  $export['language_content_type_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_people';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_people';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_people';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_people';
  $strongarm->value = '1';
  $export['node_preview_people'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_people';
  $strongarm->value = 0;
  $export['node_submitted_people'] = $strongarm;

  return $export;
}
