<?php
/**
 * @file
 * Theme and preprocess functions for the jPlayer module.
 */

/**
 * Preprocess function for a player.
 */
function template_preprocess_jplayer_waveform(&$vars) {

  // Determine a unique player ID.
  $ids = entity_extract_ids($vars['entity_type'], $vars['entity']);
  $vars['player_id'] = _jplayer_waveform_check_id('jplayer-' . $vars['entity_type'] . '-' . $ids[0] . '-' . str_replace('_', '-', $vars['field_name']));

  // Get the field info so we can figure out what type it is.
  $player = jplayer_waveform_prepare_audio($vars['items']);
  $vars['type'] = 'audio';

  //Get waveform data from database
  $result = db_select('jplayer_waveform_audio_data', 'jplayer_db')
    ->fields('jplayer_db', array('data'))
    ->condition('fid', $player['fid'])
    ->execute();
  $result = $result->fetchAll();

  if (empty($result)) {
    $waveform_data = jplayer_waveform_generate_waveform_data($player['fid']);
  }
  else {
    $waveform_data = unserialize($result[0]->data);
  }
  //Create waveform image if that image was not created
  $public_folder_path = file_stream_wrapper_get_instance_by_uri('public://')->realpath();
  if (!file_exists($public_folder_path . '/jplayer_waveform_images/' . $player['fid'] . '.png') && $waveform_data != FALSE) {
    jplayer_waveform_create_waveform_image($waveform_data, $player['fid'], '#EEEEEE');
  }

  $vars['waveform_image'] = file_create_url("public://jplayer_waveform_images/" . $player['fid'] . '.png');
  // Add player settings
  $player = array(
    'jplayerInstances' => array(
      $vars['player_id'] => array(
        'file' => $player['file'],
        'solution' => $vars['settings']['solution'],
        'supplied' => $player['extensions'],
        'preload' => $vars['settings']['preload'],
        'volume' => $vars['settings']['volume'] / 100,
        'muted' => (boolean) $vars['settings']['muted'],
        'autoplay' => (boolean) $vars['settings']['autoplay'],
        'repeat' => $vars['settings']['repeat'],
        'backgroundColor' => '#EEEEEE',
        'continuous' => $vars['settings']['continuous'],
        'waveformData' => $waveform_data,
      ),
    ),
  );
  drupal_add_js(array('jplayer_waveform' => $player), 'setting');

  $vars['dynamic'] = jplayer_waveform_add_core_js();
}


/**
 * Prepair the audio files from node ready for jPlayer.
 *
 * @param $raw_file
 *   an audio file
 * @return
 *   a settings array of data being passed to jPlayer instance
 */
function jplayer_waveform_prepare_audio($raw_file = array()) {
  $audio_extensions = array('mp3');

  $file = array();
  $file_id3_info = array();
  $extensions = array();
  $fid = 0;

  // Look through all the files provided and see what we have
  foreach ($raw_file as $delta => $item) {
    // Get file URL
    if (!isset($item['url'])) {
      $item['url'] = file_create_url($item['uri']);
    }
    $fid = $item['fid'];
    // Get file extension
    if (!isset($item['ext'])) {
      $fileinfo = pathinfo($item['url']);
      $item['ext'] = $fileinfo['extension'];

      // Add file into correct group
      if (!isset($item['type'])) {
        if (in_array($item['ext'], $audio_extensions)) {
          $item['type'] = 'audio';
        }
      }
      if (isset($item) && $item['type'] == 'audio') {
        $file[$item['ext']] = $item['url'];
        $extensions[] = $item['ext'];
      }
    }
  }
  return array(
    'fid' => $fid,
    'file' => $file,
    'extensions' => implode(',', $extensions)
  );
}

/**
 * Return a unique ID for a jPlayer. This allows multiple embedded jPlayers to
 * point to an identical file on the same page.
 *
 * @param $id
 *   The ID to check for uniqueness.
 *
 * @return
 *   A modified ID if the ID was not unique, or the same ID passed in if it was
 *   unique.
 */
function _jplayer_waveform_check_id($id) {
  // We keep track of player IDs generated per request. This ensures that if a
  // player pointing to the same field is shown multiple times on a page, that
  // each player gets a unique ID. This is especially a problem when jPlayers
  // are embedded in hidden content such as View rendered with Quicktabs.
  static $player_ids = array();

  // Add the request time, so if the same player is inserted multiple times
  // AJAX all players are functional.
  $id = $id . '-' . $_SERVER['REQUEST_TIME'];

  // Store a count of the number of times a unique ID is used, and make it
  // unique if needed.
  if (isset($player_ids[$id])) {
    $id = $id . '-' . $player_ids[$id]++;
  }
  else {
    $player_ids[$id] = 0;
  }

  return $id;
}