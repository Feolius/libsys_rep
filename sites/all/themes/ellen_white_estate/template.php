<?php
/**
 * Override or insert variables into the node template.
 */
function ellen_white_estate_preprocess_node(&$vars, $hook) {
  global $theme;

  if ($vars["type"] == "files") {
    drupal_add_library('system', 'ui.tabs');
    drupal_add_js(drupal_get_path('theme', 'ellen_white_estate') . '/js/node_files_page_tabs.js');
  }

  $view_mode = str_replace('-', '_', $vars['view_mode']);
  $type = $vars['node']->type;

  $preprocesses[] = "{$theme}_preprocess_node__$type";
  $preprocesses[] = "{$theme}_preprocess_node__$view_mode";
  $preprocesses[] = "{$theme}_preprocess_node__{$type}_$view_mode";

  foreach ($preprocesses as $preprocess) {
    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }
  }

  $vars['theme_hook_suggestions'][] = "node__{$type}";
  $vars['theme_hook_suggestions'][] = "node__$view_mode";
  $vars['theme_hook_suggestions'][] = "node__{$type}_$view_mode";
}

/**
 * Preprocesses variables for html.tpl.php.
 */
function ellen_white_estate_preprocess_html(&$variables) {
  //Delete the class 'no-sidebars'.
  if ($key = array_search('no-sidebars', $variables['classes_array'])) {
    unset($variables['classes_array'][$key]);
  }
}

/**
 * Preprocesses variables for node--people-full.tpl.php.
 */
function ellen_white_estate_preprocess_node__people_full(&$vars) {
  $node = $vars['node'];
  $vars['full_name_people'] = '';
  if (!empty($node->title)) {
    $vars['full_name_people'] .= "{$node->title} ";
  }
  if (!empty($node->field_people_first_name)) {
    $vars['full_name_people'] .= "{$node->field_people_first_name[LANGUAGE_NONE][0]['safe_value']} ";
  }
  if (!empty($node->field_people_middle_name)) {
    $vars['full_name_people'] .= "{$node->field_people_middle_name[LANGUAGE_NONE][0]['safe_value']} ";
  }
  if (!empty($node->field_people_last_name)) {
    $vars['full_name_people'] .= "{$node->field_people_last_name[LANGUAGE_NONE][0]['safe_value']} ";
  }
  if (!empty($node->field_people_maiden_name)) {
    $vars['full_name_people'] .= "({$node->field_people_maiden_name[LANGUAGE_NONE][0]['safe_value']})";
  }
  if (!empty($node->field_people_degree)) {
    $vars['full_name_people'] .= ", {$node->field_people_degree[LANGUAGE_NONE][0]['safe_value']} ";
  }
}

/**
 * Preprocesses variables for node--files-full.tpl.php.
 */
function ellen_white_estate_preprocess_node__files_full(&$vars) {
  $node = $vars['node'];
  $field_language = field_language('node', $node, 'field_files_primary_media');
  $primary_media = $node->field_files_primary_media[$field_language][0]['value'];
  switch ($primary_media) {
    case 'video':
      $vars['output'] = _ellen_white_estate_preprocess_node__files_primary_video($vars);
      break;

    case 'image':
      $vars['output'] = _ellen_white_estate_preprocess_node__files_primary_image($vars);
      break;

    case 'audio':
      $vars['output'] = _ellen_white_estate_preprocess_node__files_primary_audio($vars);
      break;

    case 'document':
      $vars['output'] = _ellen_white_estate_preprocess_node__files_primary_document($vars);
      break;
  }
}

/**
 * Preprocesses variables for files with primary media video.
 */
function _ellen_white_estate_preprocess_node__files_primary_video($vars) {
  $output = array();
  if (isset($vars['content']['field_files_youtube_media'])) {
    $output['video'] = $vars['content']['field_files_youtube_media'];
  }
  if (isset($vars['content']['field_files_description'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }
  if (isset($vars['content']['field_video_date_taken'])) {
    $output['date_taken'] = $vars['content']['field_video_date_taken'];
  }
  if (isset($vars['content']['field_files_video_people'])) {
    $output['people'] = $vars['content']['field_files_video_people'];
  }
  if (isset($vars['content']['field_files_video_location'])) {
    $output['location'] = $vars['content']['field_files_video_location'];
  }
  if (isset($vars['content']['field_files_video_event'])) {
    $output['event'] = $vars['content']['field_files_video_event'];
  }

  // Copiright.
  if (module_exists('library_admin') && $copiright = library_admin_return_copiright()) {
    $output['copiright'] = array(
      '#access' => TRUE,
      '#prefix' => "<div class='copiright'>",
      '#markup' => $copiright,
      '#suffix' => '</div>',
    );
  }

  return $output;
}

/**
 * Preprocesses variables for files with primary media image.
 */
function _ellen_white_estate_preprocess_node__files_primary_image($vars) {
  $node = $vars['node'];
  $output = array();

  // Download's link.
  if (isset($vars['content']['field_files_image'])) {
    $field_language = field_language('node', $node, 'field_files_image');

    $link = l(
      t('Download'),
      file_create_url($node->field_files_image[$field_language][0]['uri']),
      array(
        'attributes' => array(
          'class' => array('download'),
          'target' => '_blank'
        )
      )
    );
    $output['download'] = array(
      '#access' => TRUE,
      '#markup' => $link,
    );
  }

  if (isset($vars['content']['field_files_image'])) {
    $output['image'] = $vars['content']['field_files_image'];
  }

  if (isset($vars['content']['field_files_description'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }
  if (isset($vars['content']['field_files_image_people'])) {
    $output['people'] = $vars['content']['field_files_image_people'];
  }
  if (isset($vars['content']['field_files_image_location'])) {
    $output['location'] = $vars['content']['field_files_image_location'];
  }
  if (isset($vars['content']['field_files_image_event'])) {
    $output['event'] = $vars['content']['field_files_image_event'];
  }
  if (isset($vars['content']['field_image_date_taken'])) {
    $output['date_taken'] = $vars['content']['field_image_date_taken'];
  }

  // Copiright.
  if (module_exists('library_admin') && $copiright = library_admin_return_copiright()) {
    $output['copiright'] = array(
      '#access' => TRUE,
      '#prefix' => "<div class='copiright'>",
      '#markup' => $copiright,
      '#suffix' => '</div>',
    );
  }

  return $output;
}

/**
 * Preprocesses variables for files with primary media audio.
 */
function _ellen_white_estate_preprocess_node__files_primary_audio($vars) {
  $node = $vars['node'];
  $output = array();
  if (isset($vars['content']['field_files_album_poster'])) {
    $output['poster'] = $vars['content']['field_files_album_poster'];
  }
  if (isset($vars['content']['field_files_audio'])) {
    $output['audio'] = $vars['content']['field_files_audio'];
  }
  if (isset($vars['content']['field_files_description'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }

  // Download's link.
  if (isset($vars['content']['field_files_audio'])) {
    $field_language = field_language('node', $node, 'field_files_audio');

    $link = l(
      t('Download'),
      file_create_url($node->field_files_audio[$field_language][0]['uri']),
      array(
        'attributes' => array(
          'class' => array('download'),
          'target' => '_blank'
        )
      )
    );
    $output['download'] = array(
      '#access' => TRUE,
      '#markup' => $link,
    );
  }

  // Artist.
  if (!empty($node->field_files_artist)) {
    $items = field_get_items('node', $node, 'field_files_artist');
    foreach ($items as $item) {
      $artists[] = l(
        t($item['entity']->title),
        "node/{$item['entity']->nid}"
      );
    }
    $info = field_info_instance('node', 'field_files_artist', $node->type);
    $output['artist'] = array(
      '#access' => TRUE,
      '#prefix' => "<div class='field field-name-field-files-topics'><span class='field-label'>{$info['label']}:&nbsp;</span>",
      '#markup' => implode(', ', $artists),
      '#suffix' => '</div>',
    );
  }

  if (isset($vars['content']['field_audio_year'])) {
    $output['year'] = $vars['content']['field_audio_year'];
  }
  if (isset($vars['content']['field_files_length'])) {
    $output['length'] = $vars['content']['field_files_length'];
  }

  // Topics.
  if (!empty($node->field_files_topics)) {
    $items = field_get_items('node', $node, 'field_files_topics');
    foreach ($items as $item) {
      $topics[] = l(
        t($item['entity']->title),
        "node/{$item['entity']->nid}"
      );
    }
    $info = field_info_instance('node', 'field_files_topics', $node->type);
    $output['topics'] = array(
      '#access' => TRUE,
      '#label_display' => 'inline',
      '#prefix' => "<div class='field field-name-field-files-topics'><span class='field-label'>{$info['label']}:&nbsp;</span>",
      '#markup' => implode(', ', $topics),
      '#suffix' => '</div>',
    );
  }

  // Copiright.
  if (module_exists('library_admin') && $copiright = library_admin_return_copiright()) {
    $output['copiright'] = array(
      '#access' => TRUE,
      '#prefix' => "<div class='copiright'>",
      '#markup' => $copiright,
      '#suffix' => '</div>',
    );
  }

  return $output;
}

/**
 * Preprocesses variables for files with primary media audio.
 */
function _ellen_white_estate_preprocess_node__files_primary_document($vars) {
  $node = $vars['node'];
  $output = array();
  $vars['tabs'] = FALSE;
  if (isset($vars['content']['field_files_subtitle'])) {
    $output['subtitle'] = $vars['content']['field_files_subtitle'];
  }
  if (isset($vars['content']['field_files_description'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }
  if (isset($vars['content']['field_files_key_points'])) {
    $output['key_points'] = $vars['content']['field_files_key_points'];
  }

  // Tabs.

  if (isset($vars['content']['field_files_file'])) {
    $output['file'] = $vars['content']['field_files_file'];
  }
  if (isset($vars['content']['field_files_text'])) {
    $output['text'] = $vars['content']['field_files_text'];
  }
  if (isset($vars['content']['field_files_file']) && isset($vars['content']['field_files_text'])) {
    $vars['tabs'] = TRUE;
  }

  // Download's link.
  if (isset($vars['content']['field_files_file'])) {
    $field_language = field_language('node', $node, 'field_files_file');
    $file = file_load($node->field_files_file[$field_language][0]['fid']);
    $link = l(
      t('Download'),
      file_create_url($file->uri),
      array(
        'attributes' => array(
          'class' => array('download'),
          'target' => '_blank'
        )
      )
    );
    $output['download'] = array(
      '#access' => TRUE,
      '#markup' => $link,
    );
  }

  if (isset($vars['content']['field_files_author'])) {
    $output['author'] = $vars['content']['field_files_author'];
  }
  elseif (isset($vars['content']['field_files_author_location'])) {
    $output['author'] = $vars['content']['field_files_author_location'];
  }
  if (isset($vars['content']['field_files_receiver'])) {
    $output['receiver'] = $vars['content']['field_files_receiver'];
  }
  elseif (isset($vars['content']['field_files_receiver_location'])) {
    $output['receiver'] = $vars['content']['field_files_receiver_location'];
  }
  if (isset($vars['content']['field_files_creation_date'])) {
    $output['creation_date'] = $vars['content']['field_files_creation_date'];
  }
  if (isset($vars['content']['field_files_published_date'])) {
    $output['received_date'] = $vars['content']['field_files_published_date'];
  }
  if (isset($vars['content']['field_files_received_date'])) {
    $output['received_date'] = $vars['content']['field_files_received_date'];
  }
  if (isset($vars['content']['field_files_filed_date'])) {
    $output['filed_date'] = $vars['content']['field_files_filed_date'];
  }

  // Additional information.
  if (isset($vars['content']['field_files_folder'])
    || isset($vars['content']['field_files_original_title'])
    || isset($vars['content']['field_files_publication'])
    || isset($vars['content']['field_files_source_title'])
    || isset($vars['content']['field_files_source_volume'])
    || isset($vars['content']['field_files_source_number'])
    || isset($vars['content']['field_files_source_chapter'])
    || isset($vars['content']['field_files_source_page'])) {
    $output['button'] = array(
      '#type' => 'button',
      '#value' => t('Show extended information'),
      '#attributes' => array(
        'id' => array('download')
      ),
    );
  }
  return $output;
}
