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
      4 => 'field_files_length',
      5 => 'field_audio_year',
      6 => 'field_files_video_location',
      7 => 'field_files_album',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Audio',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
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
    'weight' => '17',
    'children' => array(
      0 => 'field_files_author_location',
      1 => 'field_files_category',
      2 => 'field_files_folder',
      3 => 'field_files_key_points',
      4 => 'field_files_original_title',
      5 => 'field_files_publication',
      6 => 'field_files_receiver',
      7 => 'field_files_receiver_location',
      8 => 'field_files_subtitle',
      9 => 'group_files_administrative',
      10 => 'group_files_source',
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
  $field_group->identifier = 'group_files_administrative|node|files|form';
  $field_group->group_name = 'group_files_administrative';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_files_additional_info';
  $field_group->data = array(
    'label' => 'Administrative',
    'weight' => '36',
    'children' => array(
      0 => 'field_files_handwritten',
      1 => 'field_files_keywords',
      2 => 'field_files_letterhead',
      3 => 'field_files_notes',
      4 => 'field_files_original_id',
      5 => 'field_files_typewritten',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Administrative',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files_administrative|node|files|form'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'field_audio_year',
      1 => 'field_files_album_poster',
      2 => 'field_files_artist',
      3 => 'field_files_audio',
      4 => 'field_files_length',
      5 => 'field_files_topics',
      6 => 'field_files_video_location',
      7 => 'field_files_album',
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
  $field_group->parent_name = 'group_files_text';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '16',
    'children' => array(
      0 => 'field_files_filed_date',
      1 => 'field_files_received_date',
      2 => 'field_files_published_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Dates',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files_dates|node|files|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_files_creation_date',
      1 => 'field_files_rating',
      2 => 'field_files_provenance',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files_general_additional|node|files|form'] = $field_group;

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
      0 => 'field_fields_photographer',
      1 => 'field_files_exif',
      2 => 'field_files_galleries',
      3 => 'field_files_image',
      4 => 'field_files_image_date',
      5 => 'field_files_images',
      6 => 'field_image_date_taken',
      7 => 'field_files_image_event',
      8 => 'field_files_image_location',
      9 => 'field_files_image_people',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_image|node|files|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files_source|node|files|form';
  $field_group->group_name = 'group_files_source';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_files_additional_info';
  $field_group->data = array(
    'label' => 'Source',
    'weight' => '35',
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
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_files_description',
      1 => 'field_files_primary_media',
      2 => 'path',
      3 => 'group_files_general_additional',
      4 => 'group_files_general_tagging',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'label' => 'General',
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
    'label' => 'Document',
    'weight' => '1',
    'children' => array(
      0 => 'field_files_author',
      1 => 'field_files_collection',
      2 => 'field_files_text',
      3 => 'field_files_file',
      4 => 'group_files_additional_info',
      5 => 'group_files_dates',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'label' => 'Document',
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
    'weight' => '5',
    'children' => array(
      0 => 'field_files_file_type',
      1 => 'field_files_youtube_media',
      2 => 'field_video_date_taken',
      3 => 'field_files_video_event',
      4 => 'field_files_video_people',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_video|node|files|form'] = $field_group;

  return $export;
}
