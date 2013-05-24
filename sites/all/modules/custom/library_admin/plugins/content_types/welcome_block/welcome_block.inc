<?php
/**
 * @file
 * Ctools content type page title.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_welcome_block_ctools_content_types() {
  return array(
    'title' => t('Welcome text'),
    'description' => t('Welcome text for display on homepage'),
    'category' => t('Library'),
    'icon' => 'welcome_block.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_welcome_block_content_type_theme',
    'render callback' => 'library_admin_welcome_block_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_welcome_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  if ($text = variable_get('library_admin_welcome_text')) {
    $output .= theme('copyright_block', array('copyright' => $text));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_welcome_block_content_type_theme(&$theme, $plugin) {
  $theme['copyright_block'] = array(
    'path' => $plugin['path'],
    'template' => 'copyright-block',
  );
}
