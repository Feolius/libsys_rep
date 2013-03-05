<?php
/**
 * @file
 * Field module integration.
 */

/**
 * Implements hook_field_formatter_info().
 */
function openseadragon_field_formatter_info() {
  return array(
    'openseadragon_openseadragon' => array(
      'label' => t('OpenSeadragon'),
      'field types' => array('image'),
      'settings' => array(
        'openseadragon_image_style' => 'large'
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function openseadragon_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = '';

  if ($display['type'] == 'openseadragon_openseadragon') {
    $summary = t('Fallback image style: @image_style', array('@image_style' => $settings['openseadragon_image_style']));
  }

  return $summary;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function openseadragon_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();

  if ($display['type'] == 'openseadragon_openseadragon') {
    $element['openseadragon_image_style'] = array(
      '#title' => t('Fallback image style'),
      '#type' => 'select',
      '#default_value' => $settings['openseadragon_image_style'],
      '#options' => array(),
      '#required' => TRUE,
    );
    foreach (array_keys(image_styles()) as $image_style) {
      $element['openseadragon_image_style']['#options'][$image_style] = $image_style;
    }
  }

  return $element;
}

/**
 * Implements hook_field_formatter_view().
 */
function openseadragon_field_formatter_view($obj_type, $object, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];

  $images = array();
  foreach ($items as $item) {
    $images[md5_file($item['uri'])] = $item['uri'];
  }

  return count($images) ? theme('openseadragon', array('images' => $images, 'image_style' => $settings['openseadragon_image_style'])) : FALSE;
}
