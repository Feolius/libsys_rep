<?php
/**
 * @file
 * library_features_content_type_topics.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function library_features_content_type_topics_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|topics|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Misc',
    'weight' => '7',
    'children' => array(
      0 => 'field_rating',
      1 => 'field_topics_tab_documents',
      2 => 'field_topics_tab_events',
      3 => 'field_topics_tab_location',
      4 => 'path',
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
  $export['group_tabs|node|topics|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_data|node|topics|form';
  $field_group->group_name = 'group_topics_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '0',
    'children' => array(
      0 => 'group_topics_main',
      1 => 'group_topics_links',
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
  $export['group_topics_data|node|topics|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_events|node|topics|default';
  $field_group->group_name = 'group_topics_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_topics_links';
  $field_group->data = array(
    'label' => 'Events',
    'weight' => '14',
    'children' => array(
      0 => 'field_topics_tab_events',
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
  $export['group_topics_events|node|topics|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_files|node|topics|default';
  $field_group->group_name = 'group_topics_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_topics_links';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '15',
    'children' => array(
      0 => 'field_topics_tab_documents',
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
  $export['group_topics_files|node|topics|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_links|node|topics|default';
  $field_group->group_name = 'group_topics_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_topics_links_wrapper';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '5',
    'children' => array(
      0 => 'group_topics_locations',
      1 => 'group_topics_files',
      2 => 'group_topics_events',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_topics_links|node|topics|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_links|node|topics|form';
  $field_group->group_name = 'group_topics_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_topics_data';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '43',
    'children' => array(
      0 => 'field_topics_related_event',
      1 => 'field_topics_locations',
      2 => 'field_topics_files',
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
  $export['group_topics_links|node|topics|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_locations|node|topics|default';
  $field_group->group_name = 'group_topics_locations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_topics_links';
  $field_group->data = array(
    'label' => 'Locations',
    'weight' => '16',
    'children' => array(
      0 => 'field_topics_tab_location',
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
  $export['group_topics_locations|node|topics|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_main|node|topics|form';
  $field_group->group_name = 'group_topics_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_topics_data';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '42',
    'children' => array(
      0 => 'field_topics_body',
      1 => 'field_topics_kind',
      2 => 'field_topics_image',
      3 => 'title_field',
      4 => 'field_source',
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
  $export['group_topics_main|node|topics|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_tagging|node|topics|form';
  $field_group->group_name = 'group_topics_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topics';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '11',
    'children' => array(
      0 => 'field_topics_related_event',
      1 => 'field_topics_locations',
      2 => 'field_topics_files',
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
  $export['group_topics_tagging|node|topics|form'] = $field_group;

  return $export;
}
