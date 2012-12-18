<?php
/**
 * @file
 * Theme and preprocess functions for the jPlayer module.
 */

/**
 * Preprocess function for a player.
 */
function template_preprocess_jplayer_waveform(&$vars)
{
    // Determine a unique player ID.
    $ids = entity_extract_ids($vars['entity_type'], $vars['entity']);
    $vars['player_id'] = _jplayer_waveform_check_id('jplayer-' . $vars['entity_type'] . '-' . $ids[0] . '-' . str_replace('_', '-', $vars['field_name']));

    // Get the field info so we can figure out what type it is.
    $field_info = field_info_field($vars['field_name']);
    $player = jplayer_waveform_prepair_audio($vars['items']);
    $vars['type'] = 'audio';
    foreach ($player['file'] as $file_path) {
        $vars['waveform_image'] = file_create_url("public://jplayer_waveform_images/" . urldecode(drupal_basename($file_path)) . '.png');
        break;
    }

    $vars['media_info'] = $player['file_meta_info'];
    // Add player settings
    $player = array(
        'jplayerInstances' => array(
            $vars['player_id'] => array(
                'file' => $player['file'],
                'solution' => $vars['settings']['solution'],
                'supplied' => $player['extensions'],
                'preload' => $vars['settings']['preload'],
                'volume' => $vars['settings']['volume'] / 100,
                'muted' => (boolean)$vars['settings']['muted'],
                'autoplay' => (boolean)$vars['settings']['autoplay'],
                'repeat' => $vars['settings']['repeat'],
                'backgroundColor' => $vars['settings']['backgroundColor'],
                'continuous' => $vars['settings']['continuous'],
            ),
        ),
    );
    drupal_add_js($player, 'setting');

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
function jplayer_waveform_prepair_audio($raw_file = array())
{
    $audio_extensions = array('mp3', 'm4a', 'oga', 'webma', 'wav');

    $file = array();
    $file_meta_info = array();
    $extensions = array();


    // Look through all the files provided and see what we have
    foreach ($raw_file as $delta => $item) {
        // Get file URL
        if (!isset($item['url'])) {
            $item['url'] = file_create_url($item['uri']);
        }

        // Get file extension
        if (!isset($item['ext'])) {
            $fileinfo = pathinfo($item['url']);
            $item['ext'] = $fileinfo['extension'];
        }

        // Add file into correct group
        if (!isset($item['type'])) {
            if (in_array($item['ext'], $audio_extensions)) {
                $item['type'] = 'audio';
            }
        }
        if (isset($item) && $item['type'] == 'audio') {
            $file_id3_info = getid3_analyze(drupal_realpath($item['uri']));
            if (isset($file_id3_info['tags'])) {
                $id3_data = array();
                foreach ($file_id3_info['tags'] as $tag) {
                    foreach ($tag as $key_name => $key_data) {
                        if ($key_name == 'title') {
                            $id3_data['title'] = implode(',', $key_data);
                        }
                        if ($key_name == 'artist') {
                            $id3_data['artist'] = implode(',', $key_data);
                        }
                    }
                    //The first tag will be taken.
                    break;
                }
                if (!empty($id3_data)) {
                    $file_meta_info = implode(' - ', $id3_data);
                }
            }
            $file[$item['ext']] = $item['url'];
            $extensions[] = $item['ext'];
        }
    }
    return array('file' => $file, 'file_meta_info' => $file_meta_info, 'extensions' => implode(',', $extensions));
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
function _jplayer_waveform_check_id($id)
{
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
    } else {
        $player_ids[$id] = 0;
    }

    return $id;
}
