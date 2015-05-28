<?php
/**
 * @file
 * god_s_messenger_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function god_s_messenger_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
