<?php
/**
 * @file
 * Plugin to provide a google geocoder.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Geonames Geocoder"),
  'description' => t('Geocodes via geonames geocoder'),
  'callback' => 'geonames_geocoder_plugin_callback',
  'field_types' => array('addressfield'),
  'field_callback' => 'geonames_geocoder_plugin_field_callback',
  'settings_callback' => 'geonames_geocoder_plugin_settings_callback',
  'terms_of_service' => 'http://www.geonames.org/export/#ws',
);

/**
 * Process Markup
 */
function geonames_geocoder_plugin_callback($address, $options = array()) {
  try {
    geophp_load();

    $query = array(
      'query' => $address,
      'maxRows' => 1
    );

    $result = geonames_query('search', $query);
    if ($result != FALSE) {
      $geometry = new Point($result->results[0]['lng'], $result->results[0]['lat']);
    }
    else {
      return;
    }
    dpm($geometry);
    return $geometry;
  } catch (Exception $e) {
    watchdog_exception('geonames_geocoder_plugin', $e);
    return FALSE;
  }
}

function geonames_geocoder_plugin_field_callback($field, $field_item, $options = array()) {
  if ($field['type'] == 'addressfield') {
    $address = geocoder_widget_parse_addressfield($field_item);
    return geonames_geocoder_plugin_callback($address, $options);
  }
}

function geonames_geocoder_plugin_settings_callback($default_values = array()) {
  $form = array();
  return $form;
}
