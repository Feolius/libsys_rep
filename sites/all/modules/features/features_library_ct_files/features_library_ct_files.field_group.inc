<?php
/**
 * @file
 * features_library_ct_files.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_library_ct_files_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audio|node|files|form';
  $field_group->group_name = 'group_audio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audio',
    'weight' => '5',
    'children' => array(
      0 => 'field_files_audio',
      1 => 'field_files_artist',
      2 => 'field_files_topics',
      3 => 'field_files_album_poster',
      4 => 'field_files_year',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => '',
    ),
  );
  $export['group_audio|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_additional_info|node|files|form';
  $field_group->group_name = 'group_files_additional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_files_text';
  $field_group->data = array(
    'label' => 'Additional info',
    'weight' => '3',
    'children' => array(
      0 => 'field_files_author_location',
      1 => 'field_files_category',
      2 => 'field_files_collection',
      3 => 'field_files_creation_date',
      4 => 'field_files_folder',
      5 => 'field_files_handwritten',
      6 => 'field_files_key_points',
      7 => 'field_files_keywords',
      8 => 'field_files_letterhead',
      9 => 'field_files_notes',
      10 => 'field_files_original_id',
      11 => 'field_files_original_title',
      12 => 'field_files_publication',
      13 => 'field_files_receiver',
      14 => 'field_files_receiver_location',
      15 => 'field_files_subtitle',
      16 => 'field_files_typewritten',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files_additional_info|node|files|form'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'field_files_exif',
      1 => 'field_files_galleries',
      2 => 'field_files_image',
      3 => 'field_files_image_date',
      4 => 'field_fields_photographer',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_image|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_misc|node|files|form';
  $field_group->group_name = 'group_files_misc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Misc',
    'weight' => '9',
    'children' => array(
      0 => 'field_files_date',
      1 => 'field_files_file_type',
      2 => 'field_files_images',
      3 => 'field_files_rating',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_misc|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_source|node|files|form';
  $field_group->group_name = 'group_files_source';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_files_text';
  $field_group->data = array(
    'label' => 'Source',
    'weight' => '4',
    'children' => array(
      0 => 'field_files_source_chapter',
      1 => 'field_files_source_number',
      2 => 'field_files_source_page',
      3 => 'field_files_source_title',
      4 => 'field_files_source_volume',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Source',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files_source|node|files|form'] = $field_group;

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
    'label' => 'Start',
    'weight' => '0',
    'children' => array(
      0 => 'field_files_description',
      1 => 'field_files_primary_media',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_start|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_text|node|files|form';
  $field_group->group_name = 'group_files_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '1',
    'children' => array(
      0 => 'field_files_author',
      1 => 'field_files_file',
      2 => 'field_files_text',
      3 => 'group_files_additional_info',
      4 => 'group_files_source',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_text|node|files|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_files_youtube_media',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_video|node|files|form'] = $field_group;

  return $export;
}
