<?php
/**
 * @file
 * library_location_geofield_map_and_layer.features.inc
 */

/**
 * Implements hook_openlayers_layers_alter().
 */
function library_location_geofield_map_and_layer_openlayers_layers_alter(&$data) {
  if (isset($data['geofield_formatter'])) {
    $data['geofield_formatter']->disabled = FALSE; /* WAS: '' */
  }
}

/**
 * Implements hook_openlayers_maps_alter().
 */
function library_location_geofield_map_and_layer_openlayers_maps_alter(&$data) {
  if (isset($data['geofield_formatter_map'])) {
    $data['geofield_formatter_map']->disabled = FALSE; /* WAS: '' */
  }
}
