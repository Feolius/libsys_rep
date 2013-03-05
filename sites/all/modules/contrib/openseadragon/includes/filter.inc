<?php
/**
 * @file
 * Filter module integration.
 */

/**
 * Implements hook_filter_info().
 */
function openseadragon_filter_info() {
  $filters = array();

  $filters['openseadragon'] = array(
    'title' => t('OpenSeadragon'),
    'description' => t('Provides the ability to create interactively viewable high-resolution images.'),
    'process callback' => 'openseadragon_filter_openseadragon_process',
    'settings callback' => 'openseadragon_filter_openseadragon_settings',
    'default settings' => array(
      'openseadragon_image_style' => 'large',
    ),
    'tips callback' => 'openseadragon_filter_openseadragon_tips',
  );

  return $filters;
}

/**
 * OpenSeadragon Filter tips callback.
 */
function openseadragon_filter_openseadragon_tips($filter, $format, $long) {
  return t("Images with the 'openseadragon' class are converted to OpenSeadragon images: &lt;img class='openseadragon' /&gt;");
}

/**
 * OpenSeadragon Filter settings callback.
 */
function openseadragon_filter_openseadragon_settings($form, &$form_state, $filter, $format, $defaults, $filters) {
  $filter->settings += $defaults;

  $element = array();

  $element['openseadragon_image_style'] = array(
    '#title' => t('Fallback image style'),
    '#type' => 'select',
    '#default_value' => $filter->settings['openseadragon_image_style'],
    '#options' => array(),
    '#required' => TRUE,
  );
  foreach (array_keys(image_styles()) as $image_style) {
    $element['openseadragon_image_style']['#options'][$image_style] = $image_style;
  }

  return $element;
}

/**
 * OpenSeadragon Filter process callback.
 */
function openseadragon_filter_openseadragon_process($text, $filter, $format, $langcode, $cache, $cache_id) {
  if (preg_match_all('/<img(?=[^>]*src=[\'"](.*?)[\'"])(?=[^>]*class=[\'"].*?(?<=[\s\'"])openseadragon(?=[\s\'"]+).*?[\'"]).*?\/>/', $text, $matches, PREG_SET_ORDER)) {
    global $base_url;
    foreach ($matches as $match) {
      $match[1] = str_replace(file_create_url('public://'), 'public://', $match[1]);
      $match[1] = str_replace(str_replace($base_url, '', file_create_url('public://')), 'public://', $match[1]);
      if (file_valid_uri($match[1]) && file_exists($match[1])) {
        $text = str_replace($match[0], render(theme('openseadragon', array('images' => $match[1]))), $text);
      }
    }
  }
  return $text;
}
