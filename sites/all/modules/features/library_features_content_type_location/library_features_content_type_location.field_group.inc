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
  $field_group->parent_name = 'group_location_data';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '58',
    'children' => array(
      0 => 'field_location_received_files',
      1 => 'field_location_written_files',
      2 => 'field_location_related_entities',
      3 => 'field_location_route_to_events',
      4 => 'field_location_route_start_event',
      5 => 'field_location_images',
      6 => 'field_location_topics',
      7 => 'field_location_videos',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_location_connections|node|location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_data|node|location|form';
  $field_group->group_name = 'group_location_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '0',
    'children' => array(
      0 => 'group_location_connections',
      1 => 'group_location_main',
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
  $export['group_location_data|node|location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_main|node|location|form';
  $field_group->group_name = 'group_location_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_location_data';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '56',
    'children' => array(
      0 => 'field_location_address',
      1 => 'field_location_description',
      2 => 'title_field',
      3 => 'field_location_image',
      4 => 'field_location_geofield',
      5 => 'field_location_classification',
      6 => 'field_location_director',
      7 => 'field_location_phone',
      8 => 'field_location_fax',
      9 => 'field_location_email',
      10 => 'field_location_website',
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
  $export['group_location_main|node|location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_probably_empty|node|location|form';
  $field_group->group_name = 'group_probably_empty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Probably Empty',
    'weight' => '14',
    'children' => array(
      0 => 'field_location_county',
      1 => 'field_location_link',
      2 => 'field_location_source',
      3 => 'field_location_placed_event',
      4 => 'field_location_home_date',
      5 => 'field_location_home_nodes',
      6 => 'field_location_visit_date',
      7 => 'field_location_visit_nodes',
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
  $export['group_probably_empty|node|location|form'] = $field_group;

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
    'label' => 'Misc',
    'weight' => '14',
    'children' => array(
      0 => 'field_location_tab_events',
      1 => 'field_location_tab_received_docs',
      2 => 'field_location_tab_written_docs',
      3 => 'field_location_topics_fdc',
      4 => 'field_rating',
      5 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Misc',
      'instance_settings' => array(
        'required_fields' => 0,
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
      2 => 'field_location_source',
      3 => 'field_location_related_entities',
      4 => 'field_location_home_date',
      5 => 'field_location_visit_date',
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
