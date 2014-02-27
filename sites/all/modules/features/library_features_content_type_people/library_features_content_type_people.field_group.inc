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
  $field_group->parent_name = 'group_people_data';
  $field_group->data = array(
    'label' => 'Connections',
    'weight' => '70',
    'children' => array(
      0 => 'field_people_received_files',
      1 => 'field_people_written_files',
      2 => 'field_people_created_event',
      3 => 'field_people_received_event',
      4 => 'field_people_place',
      5 => 'field_people_related_event',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Connections',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_people_connections|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_data|node|people|form';
  $field_group->group_name = 'group_people_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '0',
    'children' => array(
      0 => 'group_people_connections',
      1 => 'group_people_general_information',
      2 => 'group_people_main',
      3 => 'group_people_family',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Data',
      'instance_settings' => array(
        'classes' => '',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_people_data|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_dates|node|people|default';
  $field_group->group_name = 'group_people_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '2',
    'children' => array(
      0 => 'field_people_birthday',
      1 => 'field_people_death_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Dates',
      'instance_settings' => array(
        'classes' => 'people-birth-death-dates',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_people_dates|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_details|node|people|default';
  $field_group->group_name = 'group_people_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '7',
    'children' => array(
      0 => 'group_people_personal',
      1 => 'group_people_family',
      2 => 'group_people_events',
      3 => 'group_people_written_files',
      4 => 'group_people_received_files',
      5 => 'group_people_media',
      6 => 'group_people_locations',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_people_details|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_events|node|people|default';
  $field_group->group_name = 'group_people_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_people_details';
  $field_group->data = array(
    'label' => 'Events',
    'weight' => '32',
    'children' => array(
      0 => 'field_people_tab_events',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_people_events|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_family|node|people|default';
  $field_group->group_name = 'group_people_family';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_people_details';
  $field_group->data = array(
    'label' => 'Family',
    'weight' => '29',
    'children' => array(
      0 => 'field_people_children',
      1 => 'field_people_parents',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_people_family|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_family|node|people|form';
  $field_group->group_name = 'group_people_family';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_people_data';
  $field_group->data = array(
    'label' => 'Family',
    'weight' => '69',
    'children' => array(
      0 => 'field_people_children',
      1 => 'field_people_parents',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Family',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_people_family|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_general_information|node|people|form';
  $field_group->group_name = 'group_people_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_people_data';
  $field_group->data = array(
    'label' => 'Personal',
    'weight' => '68',
    'children' => array(
      0 => 'field_people_first_name',
      1 => 'field_people_middle_name',
      2 => 'field_people_last_name',
      3 => 'field_people_maiden_name',
      4 => 'field_people_generic_name',
      5 => 'field_people_e_mail',
      6 => 'field_people_title',
      7 => 'field_people_degree',
      8 => 'field_people_birthday',
      9 => 'field_people_marriage_date',
      10 => 'field_people_death_date',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Personal',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_people_general_information|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_locations|node|people|default';
  $field_group->group_name = 'group_people_locations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_people_details';
  $field_group->data = array(
    'label' => 'Locations',
    'weight' => '33',
    'children' => array(
      0 => 'field_people_tab_location',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_people_locations|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_main|node|people|form';
  $field_group->group_name = 'group_people_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_people_data';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '67',
    'children' => array(
      0 => 'field_people_description',
      1 => 'field_people_image',
      2 => 'title_field',
      3 => 'field_source',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Main',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_people_main|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_personal|node|people|default';
  $field_group->group_name = 'group_people_personal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_people_details';
  $field_group->data = array(
    'label' => 'Personal',
    'weight' => '27',
    'children' => array(
      0 => 'field_people_first_name',
      1 => 'field_people_middle_name',
      2 => 'field_people_last_name',
      3 => 'field_people_maiden_name',
      4 => 'field_people_generic_name',
      5 => 'field_people_title',
      6 => 'field_people_degree',
      7 => 'field_people_marriage_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_people_personal|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_received_files|node|people|default';
  $field_group->group_name = 'group_people_received_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_people_details';
  $field_group->data = array(
    'label' => 'Received Files',
    'weight' => '30',
    'children' => array(
      0 => 'field_people_tab_received_docs',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_people_received_files|node|people|default'] = $field_group;

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
  $field_group->identifier = 'group_people_written_files|node|people|default';
  $field_group->group_name = 'group_people_written_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_people_details';
  $field_group->data = array(
    'label' => 'Written Files',
    'weight' => '31',
    'children' => array(
      0 => 'field_people_tab_written_docs',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_people_written_files|node|people|default'] = $field_group;

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
    'label' => 'Misc',
    'weight' => '7',
    'children' => array(
      0 => 'field_people_tab_events',
      1 => 'field_people_tab_images',
      2 => 'field_people_tab_location',
      3 => 'field_people_tab_received_docs',
      4 => 'field_people_tab_videos',
      5 => 'field_people_tab_written_docs',
      6 => 'field_rating',
      7 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Misc',
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
  $export['group_tabs|node|people|form'] = $field_group;

  return $export;
}
