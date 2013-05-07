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
