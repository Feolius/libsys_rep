<?php
/**
 * @file
 * library_features_content_type_topics.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function library_features_content_type_topics_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_rating'
  $field_bases['field_rating'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rating',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'fivestar',
    'settings' => array(
      'axis' => 'vote',
    ),
    'translatable' => 0,
    'type' => 'fivestar',
  );

  // Exported field_base: 'field_topics_body'
  $field_bases['field_topics_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_body',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_topics_image'
  $field_bases['field_topics_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_image',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_topics_kind'
  $field_bases['field_topics_kind'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_kind',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'topic_kinds',
          'parent' => 0,
        ),
      ),
      'options_list_callback' => NULL,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_topics_related_event'
  $field_bases['field_topics_related_event'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_related_event',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'events' => 'events',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_topics_tab_documents'
  $field_bases['field_topics_tab_documents'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_tab_documents',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_data_collector',
    'settings' => array(
      'collecting_fields' => array(),
      'target_bundles' => array(),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'field_data_collector',
  );

  // Exported field_base: 'field_topics_tab_events'
  $field_bases['field_topics_tab_events'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_tab_events',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_data_collector',
    'settings' => array(
      'collecting_fields' => array(),
      'target_bundles' => array(),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'field_data_collector',
  );

  // Exported field_base: 'field_topics_tab_images'
  $field_bases['field_topics_tab_images'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_tab_images',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_data_collector',
    'settings' => array(
      'collecting_fields' => array(),
      'target_bundles' => array(),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'field_data_collector',
  );

  // Exported field_base: 'field_topics_tab_location'
  $field_bases['field_topics_tab_location'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_tab_location',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_data_collector',
    'settings' => array(
      'collecting_fields' => array(),
      'target_bundles' => array(),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'field_data_collector',
  );

  // Exported field_base: 'field_topics_tab_videos'
  $field_bases['field_topics_tab_videos'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topics_tab_videos',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_data_collector',
    'settings' => array(
      'collecting_fields' => array(),
      'target_bundles' => array(),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'field_data_collector',
  );

  return $field_bases;
}
