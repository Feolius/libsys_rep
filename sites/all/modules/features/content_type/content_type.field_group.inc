<?php
/**
 * @file
 * content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_another_fields|node|files|form';
  $field_group->group_name = 'group_files_another_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Another fields',
    'weight' => '2',
    'children' => array(
      0 => 'field_files_collection',
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
  $export['group_files_another_fields|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_default|node|files|form';
  $field_group->group_name = 'group_files_default';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Default',
    'weight' => '0',
    'children' => array(
      0 => 'field_files_folder',
      1 => 'field_files_subtitle',
      2 => 'field_files_text2',
      3 => 'field_files_file',
      4 => 'title',
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
  $export['group_files_default|node|files|form'] = $field_group;

  return $export;
}
