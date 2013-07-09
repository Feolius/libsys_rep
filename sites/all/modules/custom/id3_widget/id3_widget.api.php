<?php

/**
 * @file
 * Provides API documentation for adding  new field type support at id3_widget module
 *
 * Module id3_widget allows to add new type of field for filtering.
 * To do this, you need to create new submodule.
 * That module need to implement function to get information about implemented widgets names
 * and function to handle reading information from audio file and writing to field and vice versa.
 */

/**
 * Define widget name which current id3_widget submodule implements
 *
 * @return array
 *   An array containing widget name
 */
function hook_id3_widget_widget_name_info() {
  return 'id3_text_widget';
}


/**
 *  Handle reading information from audio file
 *  and writing to field and vice versa.
 *
 * @param $instance_widget_data
 *  Associative array with information about current id3 tag field, audio file id, id3 tag field values
 * @param $node
 *  Current node object
 * @param $field_info
 *  Current node field info
 * @param $write_back_to_audio_file_data
 *  Associative array with data for writing back to audio file id3 tag
 *  That array should have exactly the same structure:
 *  [ audio file id ] -> [ id3 tag field name ]-> [ array of that id3 field values ]
 *
 */
function hook_id3_widget_handle_field($instance_widget_data, &$node, $field_info, &$write_back_to_audio_file_data) {
  $id3_field_name = $field_info['field_name'];
  if (isset($node->$id3_field_name)) {
    $instance_data = $node->$id3_field_name;
  }
  if (!drupal_validate_utf8($instance_widget_data['value'])) {
    $instance_widget_data['value'] = check_plain(utf8_encode($instance_widget_data['value']));
  }
  if (isset($instance_data['und'][0]['value'])) {
    if (trim($instance_data['und'][0]['value']) != $instance_widget_data['value']) {
      $write_back_to_audio_file_data[$instance_widget_data['audio_file_id']][$instance_widget_data['id3_tag_field']][] = trim($instance_data['und'][0]['value']);
    }
  }
  else {
    if ($instance_widget_data['value'] != NULL) {
      $instance_data['und'][0]['value'] = $instance_widget_data['value'];
    }
  }
  $node->$id3_field_name = $instance_data;
}
