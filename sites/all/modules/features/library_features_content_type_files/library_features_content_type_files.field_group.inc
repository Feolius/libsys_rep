<?php
/**
 * @file
 * library_features_content_type_files.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function library_features_content_type_files_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_audio|node|files|form';
  $field_group->group_name = 'group_files_audio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audio',
    'weight' => '58',
    'children' => array(
      0 => 'field_files_audio',
      1 => 'field_files_artist',
      2 => 'field_files_album_poster',
      3 => 'field_files_length',
      4 => 'field_audio_year',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_files_audio|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_dates|node|files|form';
  $field_group->group_name = 'group_files_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '58',
    'children' => array(),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_files_dates|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_document|node|files|form';
  $field_group->group_name = 'group_files_document';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Document',
    'weight' => '58',
    'children' => array(
      0 => 'field_files_file',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_files_document|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_general_additional|node|files|form';
  $field_group->group_name = 'group_files_general_additional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_files_start';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_files_rating',
      1 => 'field_files_creation_date',
      2 => 'field_files_provenance',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_files_general_additional|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_general_tagging|node|files|form';
  $field_group->group_name = 'group_files_general_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_files_start';
  $field_group->data = array(
    'label' => 'General Tagging',
    'weight' => '5',
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
  $export['group_files_general_tagging|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_image|node|files|form';
  $field_group->group_name = 'group_files_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '58',
    'children' => array(
      0 => 'field_files_image',
      1 => 'field_files_image_date',
      2 => 'field_files_images',
      3 => 'field_files_image_people',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_files_image|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_start|node|files|form';
  $field_group->group_name = 'group_files_start';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_files_description',
      1 => 'field_files_primary_media',
      2 => 'title',
      3 => 'group_files_general_additional',
      4 => 'group_files_general_tagging',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_files_start|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_video|node|files|form';
  $field_group->group_name = 'group_files_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '58',
    'children' => array(
      0 => 'field_files_youtube_media',
      1 => 'field_video_date_taken',
      2 => 'field_files_video_people',
      3 => 'field_files_video_location',
      4 => 'field_files_video_event',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_files_video|node|files|form'] = $field_group;

  return $export;
}
