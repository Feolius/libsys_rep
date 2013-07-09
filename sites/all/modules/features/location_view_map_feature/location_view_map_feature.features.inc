<?php
/**
 * @file
 * location_view_map_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function location_view_map_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function location_view_map_feature_views_api() {
  return array("version" => "3.0");
}
