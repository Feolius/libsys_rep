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

function ellen_white_estate_old_js_alter(&$javascript) {

  $jquery_path = drupal_get_path('theme','ellen_white_estate_old') . '/js/jquery.min.js';
  $javascript[$jquery_path] = $javascript['misc/jquery.js'];
  $javascript[$jquery_path]['version'] = '1.9.1';
  //$javascript[$jquery_path]['scope'] = 'header';
  $javascript[$jquery_path]['data'] = $jquery_path;
  //$javascript[$jquery_path]['weight'] = 19;
  dpm($javascript);
  unset($javascript['misc/jquery.js']);
}
