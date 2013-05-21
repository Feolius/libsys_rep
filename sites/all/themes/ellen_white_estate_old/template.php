<?php
/**
 * Override or insert variables into the node template.
 */
function ellen_white_estate_old_preprocess_node(&$vars) {
  if ($vars["type"] == "files") {
    drupal_add_library('system', 'ui.tabs');
    drupal_add_js(drupal_get_path('theme', 'ellen_white_estate_old') . '/js/node_files_page_tabs.js');
  }
}

/**
 * Implements hook_js_alter() to override jquery.
 */
function ellen_white_estate_old_js_alter(&$javascript) {
  $jquery_path = drupal_get_path('theme', 'ellen_white_estate_old') . '/js/jquery-1.8.3.min.js';
  if (module_exists('jquery_update')) {
    foreach ($javascript as $key => $js_info) {
      $key_arr = explode('/', $key);
      if ($key_arr[count($key_arr) - 1] == 'jquery.min.js') {
        $jquery_old_key = $key;
        break;
      }
    }
    if (isset($jquery_old_key)) {
      $javascript[$jquery_path] = $javascript[$jquery_old_key];
      $javascript[$jquery_path] = $javascript[$jquery_old_key];
      unset($javascript[$jquery_old_key]);
    }
  }
  else {
    $javascript[$jquery_path] = $javascript['misc/jquery.js'];
    $javascript[$jquery_path] = $javascript['misc/jquery.js'];
    unset($javascript['misc/jquery.js']);
  }
  $javascript[$jquery_path]['version'] = '1.8.3';
  $javascript[$jquery_path]['data'] = $jquery_path;
}
