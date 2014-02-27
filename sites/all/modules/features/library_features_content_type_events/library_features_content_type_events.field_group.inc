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
  $field_group->identifier = 'group_events_additional|node|events|default';
  $field_group->group_name = 'group_events_additional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_events_links_heading';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '6',
    'children' => array(
      0 => 'group_events_media',
      1 => 'group_events_people',
      2 => 'group_events_locations',
      3 => 'group_events_topics',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_events_additional|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_connections|node|events|form';
  $field_group->group_name = 'group_events_connections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_events_data';
  $field_group->data = array(
    'label' => 'Connections',
    'weight' => '44',
    'children' => array(
      0 => 'group_events_media',
      1 => 'group_events_other',
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
  $export['group_events_connections|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_data|node|events|form';
  $field_group->group_name = 'group_events_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '0',
    'children' => array(
      0 => 'group_events_connections',
      1 => 'group_events_main',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => '',
      ),
    ),
  );
  $export['group_events_data|node|events|form'] = $field_group;

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
  $field_group->identifier = 'group_events_locations|node|events|default';
  $field_group->group_name = 'group_events_locations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_events_additional';
  $field_group->data = array(
    'label' => 'Locations',
    'weight' => '24',
    'children' => array(
      0 => 'field_events_tab_map',
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
  $export['group_events_locations|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_main|node|events|form';
  $field_group->group_name = 'group_events_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_events_data';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '43',
    'children' => array(
      0 => 'field_events_description',
      1 => 'field_events_time',
      2 => 'field_events_image',
      3 => 'title_field',
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
  $export['group_events_main|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_media|node|events|default';
  $field_group->group_name = 'group_events_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_events_additional';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '23',
    'children' => array(
      0 => 'field_events_media',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Media',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_events_media|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_media|node|events|form';
  $field_group->group_name = 'group_events_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_events_connections';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '43',
    'children' => array(
      0 => 'field_events_documents',
      1 => 'field_events_images',
      2 => 'field_events_videos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Media',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_events_media|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_other|node|events|form';
  $field_group->group_name = 'group_events_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_events_connections';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '44',
    'children' => array(
      0 => 'field_events_author',
      1 => 'field_events_receiver',
      2 => 'field_events_place_nodes',
      3 => 'field_events_main_character',
      4 => 'field_events_route_to',
      5 => 'field_events_route_start',
      6 => 'field_events_related_topic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Other',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_events_other|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_people|node|events|default';
  $field_group->group_name = 'group_events_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_events_additional';
  $field_group->data = array(
    'label' => 'People',
    'weight' => '25',
    'children' => array(
      0 => 'field_events_tab_people',
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
  $export['group_events_people|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_topics|node|events|default';
  $field_group->group_name = 'group_events_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_events_additional';
  $field_group->data = array(
    'label' => 'Topics',
    'weight' => '26',
    'children' => array(
      0 => 'field_events_topics',
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
  $export['group_events_topics|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_probably_empty|node|events|form';
  $field_group->group_name = 'group_probably_empty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Probably Empty',
    'weight' => '5',
    'children' => array(
      0 => 'field_events_original_place',
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
  $export['group_probably_empty|node|events|form'] = $field_group;

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
    'label' => 'Misc',
    'weight' => '6',
    'children' => array(
      0 => 'field_events_tab_map',
      1 => 'field_events_tab_people',
      2 => 'field_events_media',
      3 => 'field_events_topics',
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
  $export['group_tabs|node|events|form'] = $field_group;

  return $export;
}
