<?php
/**
 * @file
 * library_features_content_type_location.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function library_features_content_type_location_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_connections|node|location|form';
  $field_group->group_name = 'group_location_connections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Connections',
    'weight' => '12',
    'children' => array(
      0 => 'field_location_placed_event',
      1 => 'field_location_received_files',
      2 => 'field_location_route_start_event',
      3 => 'field_location_route_to_events',
      4 => 'field_location_written_files',
      5 => 'field_location_images',
      6 => 'field_location_topics',
      7 => 'field_location_videos',
      8 => 'field_location_visit_nodes',
      9 => 'field_location_home_nodes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_location_connections|node|location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|location|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '23',
    'children' => array(
      0 => 'field_location_tab_images',
      1 => 'field_location_tab_written_docs',
      2 => 'field_location_tab_received_docs',
      3 => 'field_location_tab_events',
      4 => 'field_location_tab_videos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tabs|node|location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_whatsthis|node|location|form';
  $field_group->group_name = 'group_whatsthis';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What\'s this',
    'weight' => '11',
    'children' => array(
      0 => 'field_location_county',
      1 => 'field_location_link',
      2 => 'field_location_related_entities',
      3 => 'field_location_source',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_whatsthis|node|location|form'] = $field_group;

  return $export;
}
