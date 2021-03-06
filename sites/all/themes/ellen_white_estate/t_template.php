<?php

/**
 * Preprocesses variables for node--people-full.tpl.php.
 */
function ellen_white_estate_preprocess_node__people_full(&$vars) {
 $node = $vars['node'];
  $vars['full_name_people'] = '';
  if (!empty($node->title)) {
    $vars['full_name_people'] .= "{$node->title} ";
  }
  if (!empty($vars['field_people_first_name'])) {
    $vars['full_name_people'] .= "{$vars['field_people_first_name'][0]['safe_value']} ";
  }
  if (!empty($vars['field_people_middle_name'])) {
    $vars['full_name_people'] .= "{$vars['field_people_middle_name'][0]['safe_value']} ";
  }
  if (!empty($vars['field_people_last_name'])) {
    $vars['full_name_people'] .= "{$vars['field_people_last_name'][0]['safe_value']} ";
  }
  if (!empty($vars['field_people_maiden_name']) AND isset($vars['field_people_maiden_name'][0]) AND strlen($vars['field_people_maiden_name'][0]['value']) > 0) {
    $vars['full_name_people'] .= "({$vars['field_people_maiden_name'][0]['safe_value']})";
  }
  if (!empty($vars['field_people_degree']) AND isset($vars['field_people_degree'][0]) AND strlen($vars['field_people_degree'][0]['value']) > 0) {
    $vars['full_name_people'] .= ", {$vars['field_people_degree'][0]['safe_value']} ";
  }
}

/**
 * Preprocesses variables for node--files-full.tpl.php.
 */
function ellen_white_estate_preprocess_node__files_full(&$vars) {
  $node = $vars['node'];
  $multiple_media = _ellen_white_estate_preprocess_node__tabs_files($vars);

  $field_language = field_language('node', $node, 'field_files_primary_media');
  if ($node->field_files_primary_media[$field_language][0]['value']) {
    $primary_media = $node->field_files_primary_media[$field_language][0]['value'];
    if (!$multiple_media) {
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

        case 'url':
          $vars['output'] = _ellen_white_estate_preprocess_node__files_primary_url($vars);
          break;
      }
    }
    else {
      $vars['output'] = $multiple_media;
    }
  }
}

/**
 * Preprocesses variables for files with primary media url.
 */
function _ellen_white_estate_preprocess_node__files_primary_url($vars) {
  return $vars['content'];
}

/**
 * Preprocesses variables for files with primary media video.
 */
function _ellen_white_estate_preprocess_node__files_primary_video($vars) {
  $output = array();
  $node = $vars['node'];
  if (isset($vars['content']['field_files_subtitle'])) {
    $output['subtitle'] = $vars['content']['field_files_subtitle'];
  }
  if (isset($vars['content']['field_files_youtube_media'])) {
    $output['video'] = $vars['content']['field_files_youtube_media'];
  }
  if (isset($vars['content']['field_files_description'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }

  // General tagging.
  // Peoples.
  if (!empty($node->field_files_people_tags)) {
    $items = field_get_items('node', $node, 'field_files_people_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $peoples[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_people_tags', $node->type);
      $output['peoples'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-people-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $peoples),
        '#suffix' => '</div>',
      );
    }
  }

  // Locations.
  if (!empty($node->field_files_location_tags)) {
    $items = field_get_items('node', $node, 'field_files_location_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $locations[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_location_tags', $node->type);
      $output['locations'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-location-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $locations),
        '#suffix' => '</div>',
      );
    }
  }

  // Events.
  if (!empty($node->field_files_event_tags)) {
    $items = field_get_items('node', $node, 'field_files_event_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $events[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_event_tags', $node->type);
      $output['events'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-event-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $events),
        '#suffix' => '</div>',
      );
    }
  }

  // Topics.
  if (!empty($node->field_files_topic_tags)) {
    $items = field_get_items('node', $node, 'field_files_topic_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $topics[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_topic_tags', $node->type);
      $output['topics'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-topic-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $topics),
        '#suffix' => '</div>',
      );
    }
  }
  if (isset($vars['content']['field_files_creation_date'])) {
    $output['creation_date'] = $vars['content']['field_files_creation_date'];
  }

  // Copiright.
  /*
  if (module_exists('library_admin') && $copiright = library_admin_return_copiright()) {
    $output['copiright'] = array(
      '#access' => TRUE,
      '#prefix' => "<div class='copiright'>",
      '#markup' => $copiright,
      '#suffix' => '</div>',
    );
  }
  */

  return $output;
}

/**
 * Preprocesses variables for files with primary media image.
 */
function _ellen_white_estate_preprocess_node__files_primary_image($vars) {
  $node = $vars['node'];
  $output = array();
  if (isset($vars['content']['field_files_subtitle'])
    && !empty($vars['content']['field_files_subtitle'][0]['#markup'])) {
    $output['subtitle'] = $vars['content']['field_files_subtitle'];
  }
  if (isset($vars['content']['field_files_image'])
    && !empty($vars['content']['field_files_image'][0]['#markup'])) {
    $output['image'] = $vars['content']['field_files_image'];
  }
  if (isset($vars['content']['field_files_description'])
    && !empty($vars['content']['field_files_description'][0]['#markup'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }
  // General tagging.
  // Peoples.
  if (!empty($node->field_files_people_tags)) {
    $items = field_get_items('node', $node, 'field_files_people_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $peoples[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_people_tags', $node->type);
      $output['peoples'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-people-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $peoples),
        '#suffix' => '</div>',
      );
    }
  }

  // Locations.
  if (!empty($node->field_files_location_tags)) {
    $items = field_get_items('node', $node, 'field_files_location_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $locations[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_location_tags', $node->type);
      $output['locations'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-location-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $locations),
        '#suffix' => '</div>',
      );
    }
  }

  // Events.
  if (!empty($node->field_files_event_tags)) {
    $items = field_get_items('node', $node, 'field_files_event_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $events[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_event_tags', $node->type);
      $output['events'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-event-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $events),
        '#suffix' => '</div>',
      );
    }
  }

  // Topics.
  if (!empty($node->field_files_topic_tags)) {
    $items = field_get_items('node', $node, 'field_files_topic_tags');
    if (!empty($items)) {
    foreach ($items as $item) {
        $topics[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_topic_tags', $node->type);
      $output['topics'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-topic-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $topics),
        '#suffix' => '</div>',
      );
    }
  }
  if (isset($vars['content']['field_files_creation_date'])
    && !empty($vars['content']['field_files_creation_date'][0]['#markup'])) {
    $output['creation_date'] = $vars['content']['field_files_creation_date'];
  }

  // Download's link.
  if (isset($vars['content']['field_files_image'])
    && !empty($vars['content']['field_files_image'][0]['#markup'])) {
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
    $copiright_dialog = variable_get('library_field_copyright_information', '');
    $output['download_dialog'] = array(
      '#prefix' => '<div id="download-dialog">',
      '#access' => TRUE,
      '#markup' => $copiright_dialog,
      '#suffix' => '</div>',
    );
    $output['download'] = array(
      '#access' => TRUE,
      '#markup' => $link,
      '#suffix' => '<div class="separator"></div>',
    );
  }

  // Copiright.
  /*
  if (module_exists('library_admin') && $copiright = library_admin_return_copiright()) {
    $output['copiright'] = array(
      '#access' => TRUE,
      '#prefix' => "<div class='copiright'>",
      '#markup' => $copiright,
      '#suffix' => '</div>',
    );
  }
  */

  return $output;
}

/**
 * Preprocesses variables for files with primary media audio.
 */
function _ellen_white_estate_preprocess_node__files_primary_audio($vars) {
  $node = $vars['node'];
  $output = array();
  if (isset($vars['content']['field_files_subtitle'])
    && !empty($vars['content']['field_files_subtitle'][0]['#markup'])) {
    $output['subtitle'] = $vars['content']['field_files_subtitle'];
  }
  if (isset($vars['content']['field_files_album_poster'])
    && !empty($vars['content']['field_files_album_poster'][0])) {
    $output['poster'] = $vars['content']['field_files_album_poster'];
  }
  if (isset($vars['content']['field_files_audio'])
    && !empty($vars['content']['field_files_audio'][0]['#markup'])) {
    $output['audio'] = $vars['content']['field_files_audio'];
  }
  if (isset($vars['content']['field_files_description'])
    && !empty($vars['content']['field_files_description'][0]['#markup'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }

  // Artist.
  if (!empty($node->field_files_artist)) {
    $items = field_get_items('node', $node, 'field_files_artist');
    if (!empty($items)) {
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
  }

  if (isset($vars['content']['field_audio_year'])
    && !empty($vars['content']['field_audio_year'][0]['#markup'])) {
    $output['year'] = $vars['content']['field_audio_year'];
  }
  if (isset($vars['content']['field_files_length'])
    && !empty($vars['content']['field_files_length'][0]['#markup'])) {
    $output['length'] = $vars['content']['field_files_length'];
  }

  // General tagging.
  // Peoples.
  if (!empty($node->field_files_people_tags)) {
    $items = field_get_items('node', $node, 'field_files_people_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $peoples[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_people_tags', $node->type);
      $output['peoples'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-people-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $peoples),
        '#suffix' => '</div>',
      );
    }
  }

  // Locations.
  if (!empty($node->field_files_location_tags)) {
    $items = field_get_items('node', $node, 'field_files_location_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $locations[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_location_tags', $node->type);
      $output['locations'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-location-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $locations),
        '#suffix' => '</div>',
      );
    }
  }

  // Events.
  if (!empty($node->field_files_event_tags)) {
    $items = field_get_items('node', $node, 'field_files_event_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $events[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_event_tags', $node->type);
      $output['events'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-event-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $events),
        '#suffix' => '</div>',
      );
    }
  }

  // Topics.
  if (!empty($node->field_files_topic_tags)) {
    $items = field_get_items('node', $node, 'field_files_topic_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $topics[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_topic_tags', $node->type);
      $output['topics'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-topic-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $topics),
        '#suffix' => '</div>',
      );
    }
  }

  // Download's link.
  if (isset($vars['content']['field_files_audio'])
    && !empty($vars['content']['field_files_audio'][0]['#markup'])) {
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
      '#suffix' => '<div class="separator"></div>',
    );
  }

  // Copiright.
  /*
  if (module_exists('library_admin') && $copiright = library_admin_return_copiright()) {
    $output['copiright'] = array(
      '#access' => TRUE,
      '#prefix' => "<div class='copiright'>",
      '#markup' => $copiright,
      '#suffix' => '</div>',
    );
  }
  */

  return $output;
}

/**
 * Preprocesses variables for files with primary media audio.
 */
function _ellen_white_estate_preprocess_node__files_primary_document($vars) {
  $node = $vars['node'];
  $output = array();
  $vars['tabs'] = FALSE;
  if (!empty($vars['content']['field_files_subtitle'])
    && !empty($vars['content']['field_files_subtitle'][0]['#markup'])) {
    $output['subtitle'] = $vars['content']['field_files_subtitle'];
  }
  if (!empty($vars['content']['field_files_description'])
    && !empty($vars['content']['field_files_description'][0]['#markup'])) {
    $output['description'] = $vars['content']['field_files_description'];
  }
  if (!empty($vars['content']['field_files_key_points'])
    && !empty($vars['content']['field_files_key_points'][0]['#markup'])) {
    $output['key_points'] = $vars['content']['field_files_key_points'];
  }

  // Tabs.
  if (!empty($vars['content']['field_files_file'])
    && !empty($vars['content']['field_files_text'])) {
    $first_tab = l(
      t('Document'),
      '#file-tabs-1',
      array(
        'external' => TRUE
      )
    );
    $second_tab = l(
      t('Text'),
      '#file-tabs-2',
      array(
        'external' => TRUE
      )
    );
    $output['tabs_start'] = array(
      '#access' => TRUE,
      '#markup' => "<div id='file-tabs'><ul><li>{$first_tab}</li><li>{$second_tab}</li></ul>"
    );
  }
  else {

    if (!empty($vars['content']['field_files_file'])) {
      $output['file'] = $vars['content']['field_files_file'];
    }
    if (!empty($vars['content']['field_files_text'])) {
      $output['text'] = $vars['content']['field_files_text'];
    }
  }

  if (!empty($vars['content']['field_files_file'])
    && !empty($vars['content']['field_files_text'])) {
    $file = drupal_render($vars['content']['field_files_file']);
    $text = drupal_render($vars['content']['field_files_text']);
    $item_file = array(
      '#access' => TRUE,
      '#markup' => "<div id='file-tabs-1'>$file</div>"
    );
    $item_text = array(
      '#access' => TRUE,
      '#markup' => "<div id='file-tabs-2'>$text</div>"
    );
    $output['tabs'] = array(
      '#access' => TRUE,
      '#markup' => drupal_render($output['tabs_start']) . drupal_render($item_file) . drupal_render($item_text) . '</div>'
    );
  }

  // Download's link.
  if (!empty($vars['content']['field_files_file'])) {
    $field_language = field_language('node', $node, 'field_files_file');
    $file = file_load($node->field_files_file[$field_language][0]['fid']);
    if (!empty($file)) {
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
        '#suffix' => '<div class="separator"></div>',
      );
    }
  }

  if (!empty($vars['content']['field_files_author'])
    && !empty($vars['content']['field_files_author'][0]['#markup'])) {
    $output['author'] = $vars['content']['field_files_author'];
  }
  if (!empty($vars['content']['field_files_author_location'])
    && !empty($vars['content']['field_files_author_location'][0]['#markup'])) {
    $output['author_location'] = $vars['content']['field_files_author_location'];
  }
  if (!empty($vars['content']['field_files_receiver'])
    && !empty($vars['content']['field_files_receiver'][0]['#markup'])) {
    $output['receiver'] = $vars['content']['field_files_receiver'];
  }
  if (!empty($vars['content']['field_files_receiver_location'])
    && !empty($vars['content']['field_files_receiver_location'][0]['#markup'])) {
    $output['receiver_location'] = $vars['content']['field_files_receiver_location'];
  }
  if (!empty($vars['content']['field_files_creation_date'])
    && !empty($vars['content']['field_files_creation_date'][0]['#markup'])) {
    $output['creation_date'] = $vars['content']['field_files_creation_date'];
  }
  if (!empty($vars['content']['field_files_published_date'])
    && !empty($vars['content']['field_files_published_date'][0]['#markup'])) {
    $output['received_date'] = $vars['content']['field_files_published_date'];
  }
  if (!empty($vars['content']['field_files_received_date'])
    && !empty($vars['content']['field_files_received_date'][0]['#markup'])) {
    $output['received_date'] = $vars['content']['field_files_received_date'];
  }
  if (!empty($vars['content']['field_files_filed_date'])
    && !empty($vars['content']['field_files_filed_date'][0]['#markup'])) {
    $output['filed_date'] = $vars['content']['field_files_filed_date'];
  }

  // General tagging.
  // Peoples.
  if (!empty($node->field_files_people_tags)) {
    $items = field_get_items('node', $node, 'field_files_people_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $peoples[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_people_tags', $node->type);
      $output['peoples'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-people-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $peoples),
        '#suffix' => '</div>',
      );
    }
  }

  // Locations.
  if (!empty($node->field_files_location_tags)) {
    $items = field_get_items('node', $node, 'field_files_location_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $locations[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_location_tags', $node->type);
      $output['locations'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-location-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $locations),
        '#suffix' => '</div>',
      );
    }
  }

  // Events.
  if (!empty($node->field_files_event_tags)) {
    $items = field_get_items('node', $node, 'field_files_event_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $events[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_event_tags', $node->type);
      $output['events'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-event-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $events),
        '#suffix' => '</div>',
      );
    }
  }

  // Topics.
  if (!empty($node->field_files_topic_tags)) {
    $items = field_get_items('node', $node, 'field_files_topic_tags');
    if (!empty($items)) {
      foreach ($items as $item) {
        $topics[] = l(
          t($item['entity']->title),
          "node/{$item['entity']->nid}"
        );
      }
      $info = field_info_instance('node', 'field_files_topic_tags', $node->type);
      $output['topics'] = array(
        '#access' => TRUE,
        '#label_display' => 'inline',
        '#prefix' => "<div class='field field-name-field-files-topic-tags'><span class='field-label'>{$info['label']}:&nbsp;</span>",
        '#markup' => implode(', ', $topics),
        '#suffix' => '</div>',
      );
    }
  }

  // Additional information.
  if (!empty($vars['content']['field_files_folder'][0]['#markup'])
    || !empty($vars['content']['field_files_original_title'][0]['#markup'])
    || !empty($vars['content']['field_files_publication'][0]['#markup'])
    || !empty($vars['content']['field_files_source_title'][0]['#markup'])
    || !empty($vars['content']['field_files_source_volume'][0]['#markup'])
    || !empty($vars['content']['field_files_source_number'][0]['#markup'])
    || !empty($vars['content']['field_files_source_chapter'][0]['#markup'])
    || !empty($vars['content']['field_files_source_page'][0]['#markup'])
  ) {
    $information = l(
      t('Show extended information'),
      '',
      array(
        'attributes' => array(
          'class' => array('information')
        ),
      )
    );
    $output['information'] = array(
      '#access' => TRUE,
      '#prefix' => '<div class="extended">',
      '#markup' => $information,
      '#suffix' => '</div>'
    );
    $output['suffix'] = array(
      '#access' => TRUE,
      '#markup' => '<div class="information hide-me">'
    );
    if (!empty($vars['content']['field_files_folder'])
      && !empty($vars['content']['field_files_folder'][0]['#markup'])) {
      $output['folder'] = $vars['content']['field_files_folder'];
    }
    if (!empty($vars['content']['field_files_original_title'])
      && !empty($vars['content']['field_files_original_title'][0]['#markup'])) {
      $output['original_title'] = $vars['content']['field_files_original_title'];
    }
    if (!empty($vars['content']['field_files_publication'])
      && !empty($vars['content']['field_files_publication'][0]['#markup'])) {
      $output['publication'] = $vars['content']['field_files_publication'];
    }
    if (!empty($vars['content']['field_files_source_title'])
      && !empty($vars['content']['field_files_source_title'][0]['#markup'])) {
      $output['source_title'] = $vars['content']['field_files_source_title'];
    }
    if (!empty($vars['content']['field_files_source_volume'])
      && !empty($vars['content']['field_files_source_volume'][0]['#markup'])) {
      $output['source_volume'] = $vars['content']['field_files_source_volume'];
    }
    if (!empty($vars['content']['field_files_source_number'])
      && !empty($vars['content']['field_files_source_number'][0]['#markup'])) {
      $output['source_number'] = $vars['content']['field_files_source_number'];
    }
    if (!empty($vars['content']['field_files_source_chapter'])
      && !empty($vars['content']['field_files_source_chapter'][0]['#markup'])) {
      $output['source_chapter'] = $vars['content']['field_files_source_chapter'];
    }
    if (!empty($vars['content']['field_files_source_page'])
      && !empty($vars['content']['field_files_source_page'][0]['#markup'])) {
      $output['source_page'] = $vars['content']['field_files_source_page'];
    }
    $output['preffix'] = array(
      '#access' => TRUE,
      '#markup' => '</div>'
    );
  }
  return $output;
}

/**
 * Preprocesses for check multiple files in CT files.
 */
function _ellen_white_estate_preprocess_node__tabs_files($vars) {
  $output = array();

  $links = array(
    'file' => '',
    'audio' => '',
    'video' => '',
    'image' => ''
  );

  if (!empty($vars['content']['field_files_file'])) {
    $links['file'] = '<li>' . l(
      t('File'),
      '#ui-tabs-1',
      array(
        'external' => TRUE
      )
    ) . '</li>';
  }
  if (!empty($vars['content']['field_files_audio'])) {
    $links['audio'] = '<li>' . l(
      t('Audio'),
      '#ui-tabs-2',
      array(
        'external' => TRUE
      )
    ) . '</li>';
  }
  if (!empty($vars['content']['field_files_youtube_media'])) {
    $links['video'] = '<li>' . l(
      t('Video'),
      '#ui-tabs-3',
      array(
        'external' => TRUE
      )
    ) . '</li>';
  }
  if (!empty($vars['content']['field_files_image'])) {
    $links['image'] = '<li>' . l(
      t('Image'),
      '#ui-tabs-4',
      array(
        'external' => TRUE
      )
    ) . '</li>';
  }

  $sum = array_sum(array_map(function ($link) {
    return empty($link) ? 0 : 1;
  }, $links));

  if ($sum > 1) {
    if (!empty($vars['content']['field_files_subtitle'])
      && !empty($vars['content']['field_files_subtitle'][0]['#markup'])) {
      $output['subtitle'] = $vars['content']['field_files_subtitle'];
      unset($vars['content']['field_files_subtitle']);
    }
    $output['container'] = array(
      '#prefix' => '<div id="ui-tabs"><ul>',
      '#markup' => $links['file'] . $links['audio'] . $links['video'] . $links['image'],
      '#suffix' => '</ul>'
    );

    if (!empty($links['file'])) {
      $file = _ellen_white_estate_preprocess_node__files_primary_document($vars);
      $output['file'] = array(
        '#prefix' => '<div id="ui-tabs-1">',
        '#markup' => drupal_render_children($file),
        '#suffix' => '</div>'
      );
    }

    if (!empty($links['audio'])) {
      $audio = _ellen_white_estate_preprocess_node__files_primary_audio($vars);
      $output['audio'] = array(
        '#prefix' => '<div id="ui-tabs-2">',
        '#markup' => drupal_render_children($audio),
        '#suffix' => '</div>',
      );
    }

    if (!empty($links['video'])) {
      $video = _ellen_white_estate_preprocess_node__files_primary_video($vars);
      $output['video'] = array(
        '#prefix' => '<div id="ui-tabs-3">',
        '#markup' => drupal_render_children($video),
        '#suffix' => '</div>'
      );
    }

    if (!empty($links['image'])) {
      $image = _ellen_white_estate_preprocess_node__files_primary_image($vars);
      $output['image'] = array(
        '#prefix' => '<div id="ui-tabs-4">',
        '#markup' => drupal_render_children($image),
        '#suffix' => '</div>'
      );
    }

    $output['footer'] = array(
      '#markup' => "</div>"
    );
  }

  return $output;
}