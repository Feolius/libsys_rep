<?php
/**
 * @file
 * library_features_content_type_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function library_features_content_type_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_connections|node|events|form';
  $field_group->group_name = 'group_events_connections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Connections',
    'weight' => '15',
    'children' => array(
      0 => 'field_events_author',
      1 => 'field_events_receiver',
      2 => 'field_events_place_nodes',
      3 => 'field_events_main_character',
      4 => 'field_events_route_to',
      5 => 'field_events_route_start',
      6 => 'field_events_original_place',
      7 => 'field_events_related_topic',
      8 => 'field_events_documents',
      9 => 'field_events_images',
      10 => 'field_events_videos',
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
  $export['group_events_connections|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_delete|node|events|form';
  $field_group->group_name = 'group_events_delete';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Delete?',
    'weight' => '17',
    'children' => array(),
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
  $export['group_events_delete|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|events|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '21',
    'children' => array(
      0 => 'field_events_tab_documents',
      1 => 'field_events_tab_images',
      2 => 'field_events_tab_map',
      3 => 'field_events_tab_timeline',
      4 => 'field_events_tab_videos',
      5 => 'field_events_tab_people',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Tabs',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_tabs|node|events|form'] = $field_group;

  return $export;
}
