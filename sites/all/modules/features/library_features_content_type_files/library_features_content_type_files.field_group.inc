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
      0 => 'field_files_artist',
      1 => 'field_files_topics',
      2 => 'field_files_album_poster',
      3 => 'field_files_length',
      4 => 'field_audio_year',
      5 => 'field_files_album',
      6 => 'field_files_track_number',
      7 => 'field_files_audio',
    ),
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
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
    'weight' => '20',
    'children' => array(
      0 => 'field_files_author_location',
      1 => 'field_files_category',
      2 => 'field_files_key_points',
      3 => 'field_files_original_title',
      4 => 'field_files_publication',
      5 => 'field_files_receiver',
      6 => 'field_files_receiver_location',
      7 => 'field_files_subtitle',
      8 => 'field_files_folder',
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
      0 => 'field_files_artist',
      1 => 'field_files_album_poster',
      2 => 'field_files_length',
      3 => 'field_audio_year',
      4 => 'field_files_album',
      5 => 'field_files_track_number',
      6 => 'field_files_audio',
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
    'weight' => '19',
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
  $field_group->identifier = 'group_files_docuement_display|node|files|library_snippet';
  $field_group->group_name = 'group_files_docuement_display';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'library_snippet';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Document',
    'weight' => '3',
    'children' => array(
      0 => 'field_files_author',
      1 => 'field_files_filed_date',
      2 => 'field_files_file',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_files_docuement_display|node|files|library_snippet'] = $field_group;

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
    'weight' => '-1',
    'children' => array(
      0 => 'field_files_rating',
      1 => 'field_files_provenance',
      2 => 'field_files_creation_date',
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
  $field_group->identifier = 'group_files_general_tagging|node|files|form';
  $field_group->group_name = 'group_files_general_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_files_start';
  $field_group->data = array(
    'label' => 'General Tagging',
    'weight' => '0',
    'children' => array(
      0 => 'field_files_people_tags',
      1 => 'field_files_location_tags',
      2 => 'field_files_event_tags',
      3 => 'field_files_topic_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'General Tagging',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'weight' => '3',
    'children' => array(
      0 => 'field_files_galleries',
      1 => 'field_files_image',
      2 => 'field_fields_photographer',
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
      0 => 'field_files_source_page',
      1 => 'field_files_source_title',
      2 => 'field_files_source_chapter',
      3 => 'field_files_source_number',
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
      2 => 'title_field',
      3 => 'field_files_extended_summary',
      4 => 'group_files_general_additional',
      5 => 'group_files_general_tagging',
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
      3 => 'field_files_downloads',
      4 => 'field_files_file',
      5 => 'group_files_additional_info',
      6 => 'group_files_dates',
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
  $field_group->identifier = 'group_files_url|node|files|form';
  $field_group->group_name = 'group_files_url';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'files';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'URL',
    'weight' => '57',
    'children' => array(
      0 => 'field_files_url_link',
      1 => 'path',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'URL',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files_url|node|files|form'] = $field_group;

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
    'format_type' => 'multistep_adl',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => NULL,
    ),
  );
  $export['group_files_video|node|files|form'] = $field_group;

  return $export;
}
