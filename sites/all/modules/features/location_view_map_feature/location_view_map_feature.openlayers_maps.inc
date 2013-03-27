<?php
/**
 * @file
 * location_view_map_feature.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function location_view_map_feature_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'location_view_map';
  $openlayers_maps->title = 'Location View Map';
  $openlayers_maps->description = 'Map for location view on collection page';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '600px',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '35.1562494034625, 0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'feature_types' => array(
          'point' => 0,
          'path' => 0,
          'polygon' => 0,
        ),
        'allow_edit' => 1,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'sortBaseLayer' => '0',
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
        'maximizeDefault' => 0,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'location_view_openlayers_data_overlay' => 'location_view_openlayers_data_overlay',
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'google_satellite' => 'google_satellite',
      'google_hybrid' => 'google_hybrid',
      'google_normal' => 'google_normal',
      'location_view_openlayers_data_overlay' => 'location_view_openlayers_data_overlay',
    ),
    'layer_weight' => array(
      'location_view_openlayers_data_overlay' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'location_view_openlayers_data_overlay' => '0',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'location_view_openlayers_data_overlay' => '0',
    ),
    'layer_activated' => array(
      'location_view_openlayers_data_overlay' => 'location_view_openlayers_data_overlay',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
    ),
    'layer_switcher' => array(
      'location_view_openlayers_data_overlay' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['location_view_map'] = $openlayers_maps;

  return $export;
}
