<?php
/**
 * @file
 * Ctools content type page title.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_social_buttons_ctools_content_types() {
    return array(
    'title' => t('Social buttons'),
    'category' => t('Library'),
    'icon' => 'social_buttons.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_social_buttons_content_type_theme',
    'render callback' => 'library_admin_social_buttons_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_social_buttons_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  $output .= theme('social_buttons');
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_social_buttons_content_type_theme(&$theme, $plugin) {
  $theme['social_buttons'] = array(
    'path' => $plugin['path'],
    'template' => 'social-buttons',
  );
}
