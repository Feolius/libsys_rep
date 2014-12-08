<?php
/**
 * Override or insert variables into the node template.
 */
function ellen_white_estate_preprocess_node(&$vars, $hook) {

  global $theme;
  if ($vars["type"] == "files") {
    drupal_add_library('system', 'ui.tabs');
    drupal_add_library('system', 'ui.dialog');
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
  drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans:400italic,400,700', array('type' => 'external'));
}


function egw_remove_empty_fields(&$path, &$c) {
  $sub = array();
  $counter = 0;
  foreach($path as $k => $v) {
    if (strpos($k, '#') === false) {
      // Remove if empty
      if (
        empty($v) OR 
        (isset($v['#type']) AND $v['#type'] == 'hidden') OR 
        (isset($v['#theme']) AND $v['#theme'] == 'field' AND isset($v[0]) AND isset($v[0]['#markup']) AND empty($v[0]['#markup']))) 
      {
        unset($path[$k]);
        $c++;
        continue;
      }
      if (is_array($path[$k])) {
        $counter++;
        egw_remove_empty_fields($path[$k], $c);
      }
      if (!$path[$k] OR count($path[$k]) == 0) {
        $c++;
        unset($path[$k]);
      }
    }
  }
  if ($counter == 0 AND ((isset($path['#type']) AND preg_match("/fieldset|vertical_tabs/", $path['#type'])) OR (isset($path['#theme']) AND preg_match("/field_group_table_wrapper/", $path['#theme'])))) {
    foreach($path as $k => $v) {
      $c++;
      unset($path[$k]);
    }
  }  
}

function egw_remove_single_tabs(&$tree) {
  if (!isset($tree)) {
    return;
  }
  $counter = 0;
  $key = false;
  foreach($tree as $k => $v) {
    if (strpos($k, '#') === false) {
      $counter++;
      $key = $k;
    }
  }
  if ($counter == 1) {
    foreach($tree[$key] as $k => $v) {
      if (strpos($k, '#') === false) {
        $tree[$k] = $v;
        $tree[$k]['#weight'] = $tree[$key]['#weight'] + ($v['#weight'] / 100);
      }
    }
    unset($tree[$key]);
  }
}

function egw_set_weight_by_primary_media(&$tree, $node) {
  $map = array(
    'image' => 'group_files_image_tab'
  );
  $type = $node->{'field_files_primary_media'}['und'][0]['value'];
  if (isset($map[$type])) {
    $tree[$map[$type]]['#weight'] = 1;
  }
}

function ellen_white_estate_preprocess_node__files_full(&$vars) {
  
  // Download link for images.
  $node = $vars['node'];
  if (isset($vars['content']['group_files_media']['group_files_image_tab']['field_files_image'])) {
    $field_language = field_language('node', $node, 'field_files_image');
    $image_uri = $node->field_files_image[$field_language][0]['uri'];
    $style = image_style_load('watermark');
    $derivative_uri = image_style_path($style, $image_uri);
    $success = file_exists($derivative_uri) || image_style_create_derivative($style, $image_uri, $derivative_uri);
    $new_image_url  = file_create_url($derivative_uri);
    $link = l(
      t('Download'),
      $new_image_url,
      array(
        'attributes' => array(
          'class' => array('download', 'egw-images'),
          'target' => '_blank'
        )
      )
    );
    $copyright_dialog = variable_get('library_field_copyright_information', '');
    $vars['content']['group_files_media']['group_files_image_tab']['image_download_dialog'] = array(
      '#prefix' => '<div id="download-dialog">',
      '#access' => TRUE,
      '#markup' => $copyright_dialog,
      '#suffix' => '</div>',
      '#weight' => $vars['content']['group_files_media']['group_files_image_tab']['field_files_image']['#weight'] + 0.3
    );
    $vars['content']['group_files_media']['group_files_image_tab']['image_download_button'] = array(
      '#access' => TRUE,
      '#markup' => $link,
      '#weight' => $vars['content']['group_files_media']['group_files_image_tab']['field_files_image']['#weight'] + 0.5
    );
  }
  
  // Download link for audio files
  if (isset($vars['content']['group_files_media']['group_files_audio']['field_files_audio'])){
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
    $vars['content']['group_files_media']['group_files_audio']['audio_download_button'] = array(
      '#access' => TRUE,
      '#markup' => $link,
      '#weight' => $vars['content']['group_files_media']['group_files_audio']['field_files_audio']['#weight'] + 0.5
    );
  }
  
  // Clean up empty fields and superflous tabs
  do {
    $c = 0;
    egw_remove_empty_fields($vars['content'], $c);
  } while ($c > 0);
  if (isset($vars['content']['group_files_media']['group_files_document_tab']) AND isset($vars['content']['group_files_media']['group_files_document_tab']['group_files_doc_format_wrappre'])) {
    egw_remove_single_tabs($vars['content']['group_files_media']['group_files_document_tab']['group_files_doc_format_wrappre']);
  }
  egw_remove_single_tabs($vars['content']['group_files_media']);
  egw_set_weight_by_primary_media($vars['content']['group_files_media'], $vars['node']);
  
  //dpr($vars['content']['group_files_media']);
  //$vars['content']['group_files_media']['group_files_image_tab']['#weight'] = 1;
  
}



/**
 * Implements hook_js_alter() to override jquery.
 */

function ellen_white_estate_js_alter(&$javascript) {
  if (arg(0) != 'library') {
    $jquery_path = drupal_get_path('theme', 'ellen_white_estate') . '/js/jquery-1.8.3.min.js';
    if (module_exists('jquery_update')) {
      foreach ($javascript as $key => $js_info) {
        $key_arr = explode('/', $key);
        if ($key_arr[count($key_arr) - 1] == 'jquery.min.js') {
          $javascript[$jquery_path] = $javascript[$key];
          unset($javascript[$key]);
          break;
        }
      }
    }
    else {
      $javascript[$jquery_path] = $javascript['misc/jquery.js'];
      unset($javascript['misc/jquery.js']);
    }
    $javascript[$jquery_path]['version'] = '1.8.3';
    $javascript[$jquery_path]['data'] = $jquery_path;
 }
}

/**
 * Help preprocesses variables for templates nodes.
 */
function _ellen_white_estate_preprocess_node__home(&$vars) {
  return array(
    '#prefix' => '<span class="arrow-link">',
    '#markup' => l("&nbsp;", "node/{$vars['node']->nid}", array('html' => TRUE)),
    '#suffix' => '</span>',
    '#weight' => 3
  );
}

/**
 * Preprocesses variables for node--home-top.tpl.php.
 */
function ellen_white_estate_preprocess_node__home_top(&$vars) {
  $vars['content']['allow'] = _ellen_white_estate_preprocess_node__home($vars);
}

/**
 * Clean up the panel pane variables for the template.
 */
function ellen_white_estate_preprocess_panels_pane(&$vars) {
  $users = array('user', 'user/login', 'user/password', 'user/register');
  if ($vars['pane']->type == 'page_content'
    || ($vars['pane']->type == 'node_content' && ($vars['content']['#node']->type !== 'files'))) {
    $vars['title'] = '';
  }
}