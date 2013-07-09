<?php
/**
 * @file
 * Ctools content type page title.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_copyright_block_ctools_content_types() {
  return array(
    'title' => t('Copyright'),
    'description' => t('Copyright text to display in the footer'),
    'category' => t('Library'),
    'icon' => 'social_buttons.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_copyright_block_content_type_theme',
    'render callback' => 'library_admin_copyright_block_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_copyright_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  if ($copyright = variable_get('library_admin_copyright')) {
    $output .= theme('copyright_block', array('copyright' => $copyright));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_copyright_block_content_type_theme(&$theme, $plugin) {
  $theme['copyright_block'] = array(
    'path' => $plugin['path'],
    'template' => 'copyright-block',
  );
}
