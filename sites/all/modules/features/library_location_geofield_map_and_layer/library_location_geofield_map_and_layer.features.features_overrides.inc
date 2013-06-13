<?php
/**
 * @file
 * library_location_geofield_map_and_layer.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function library_location_geofield_map_and_layer_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: openlayers_layers
  $overrides["openlayers_layers.geofield_formatter.disabled"] = FALSE;

  // Exported overrides for: openlayers_maps
  $overrides["openlayers_maps.geofield_formatter_map.disabled"] = FALSE;

 return $overrides;
}
