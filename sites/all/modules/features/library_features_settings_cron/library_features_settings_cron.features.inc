<?php
/**
 * @file
 * library_features_settings_cron.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function library_features_settings_cron_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
}
