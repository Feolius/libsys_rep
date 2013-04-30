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
  $primary_media = $node->field_files_primary_media[LANGUAGE_NONE][0]['value'];
  switch ($primary_media) {
    case 'video':
      $vars['output'] = _ellen_white_estate_preprocess_node__files_primary_video($vars);
      break;

    case 'image':
      $vars['output'] = _ellen_white_estate_preprocess_node__files_primary_image($vars);;
      break;
  }
}

/**
 * Preprocesses variables for files with primary media video.
 */
function _ellen_white_estate_preprocess_node__files_primary_video($vars) {
  $output = array();
  if ($vars['content']['field_files_youtube_media']) {
    $output['video'] = $vars['content']['field_files_youtube_media'];
  }
  if ($vars['content']['field_files_description']) {
    $output['description'] = $vars['content']['field_files_description'];
  }
  if ($vars['content']['field_video_date_taken']) {
    $output['date_taken'] = $vars['content']['field_video_date_taken'];
  }
  if ($vars['content']['field_files_video_people']) {
    $output['people'] = $vars['content']['field_files_video_people'];
  }
  if ($vars['content']['field_files_video_location']) {
    $output['location'] = $vars['content']['field_files_video_location'];
  }
  if ($vars['content']['field_files_video_event']) {
    $output['event'] = $vars['content']['field_files_video_event'];
  }
  return $output;
}

/**
 * Preprocesses variables for files with primary media image.
 */
function _ellen_white_estate_preprocess_node__files_primary_image($vars) {
  $output = array();
  if ($vars['content']['field_files_image']) {
    $output['image'] = $vars['content']['field_files_image'];
  }
  if ($vars['content']['field_files_description']) {
    $output['description'] = $vars['content']['field_files_description'];
  }
  if ($vars['content']['field_files_image_people']) {
    $output['people'] = $vars['content']['field_files_image_people'];
  }
  if ($vars['content']['field_files_image_location']) {
    $output['location'] = $vars['content']['field_files_image_location'];
  }
  if ($vars['content']['field_files_image_event']) {
    $output['event'] = $vars['content']['field_files_image_event'];
  }
  if ($vars['content']['field_image_date_taken']) {
    $output['date_taken'] = $vars['content']['field_image_date_taken'];
  }
  return $output;
}
