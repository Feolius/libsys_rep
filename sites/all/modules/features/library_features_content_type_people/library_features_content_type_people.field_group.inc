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
  $field_group->identifier = 'group_people_connections|node|people|form';
  $field_group->group_name = 'group_people_connections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Connections',
    'weight' => '20',
    'children' => array(
      0 => 'field_people_received_files',
      1 => 'field_people_written_files',
      2 => 'field_people_created_event',
      3 => 'field_people_received_event',
      4 => 'field_people_place',
      5 => 'field_people_related_event',
      6 => 'field_people_children',
      7 => 'field_people_parents',
      8 => 'field_people_visit_nodes',
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
  $export['group_people_connections|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_general_information|node|people|form';
  $field_group->group_name = 'group_people_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_people_description',
      1 => 'field_people_image',
      2 => 'field_people_first_name',
      3 => 'field_people_middle_name',
      4 => 'field_people_last_name',
      5 => 'field_people_maiden_name',
      6 => 'field_people_generic_name',
      7 => 'field_people_e_mail',
      8 => 'field_people_title',
      9 => 'field_people_degree',
      10 => 'field_people_official_position',
      11 => 'field_people_birthday',
      12 => 'field_people_marriage_date',
      13 => 'title_field',
      14 => 'field_people_death_date',
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
  $export['group_people_general_information|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_whatsthis|node|people|form';
  $field_group->group_name = 'group_people_whatsthis';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What\'s this?',
    'weight' => '18',
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
  $export['group_people_whatsthis|node|people|form'] = $field_group;

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
