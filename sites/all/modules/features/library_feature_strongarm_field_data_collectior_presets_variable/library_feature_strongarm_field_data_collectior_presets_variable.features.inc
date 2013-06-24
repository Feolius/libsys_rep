<?php
/**
 * @file
 * library_feature_strongarm_field_data_collectior_presets_variable.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function library_feature_strongarm_field_data_collectior_presets_variable_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
