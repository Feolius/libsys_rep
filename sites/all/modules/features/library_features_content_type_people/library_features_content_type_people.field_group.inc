<?php
/**
 * @file
 * library_features_content_type_people.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function library_features_content_type_people_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|people|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '31',
    'children' => array(
      0 => 'field_people_tab_events',
      1 => 'field_people_tab_images',
      2 => 'field_people_tab_location',
      3 => 'field_people_tab_received_docs',
      4 => 'field_people_tab_videos',
      5 => 'field_people_tab_written_docs',
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
  $export['group_tabs|node|people|form'] = $field_group;

  return $export;
}
