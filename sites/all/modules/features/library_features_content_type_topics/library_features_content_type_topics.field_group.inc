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
    'label' => 'Tabs',
    'weight' => '35',
    'children' => array(
      0 => 'field_topics_tab_images',
      1 => 'field_topics_tab_videos',
      2 => 'field_topics_tab_events',
      3 => 'field_topics_tab_location',
      4 => 'field_topics_tab_documents',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tabs|node|topics|form'] = $field_group;

  return $export;
}
