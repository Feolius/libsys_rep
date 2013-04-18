<?php
/**
 * @file
 * Ctools content type page title.
 */

$plugin = array(
  'title' => t('Copyright'),
  'description' => t('Copyright text to display in the footer'),
  'category' => t('Library'),
  'icon' => 'copyright_block.png',
  'single' => TRUE,
  'hook theme' => 'library_admin_copyright_block_content_type_theme',
);

/**
 * Implements hook_content_type_render().
 */
function library_admin_copyright_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $results = array();
  $block = new stdClass();
  $block->content = theme('library_admin_copyright_block', array('results' => $results));
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_copyright_block_content_type_theme(&$theme, $plugin) {
  $theme['library_admin_copyright_block'] = array(
    'path' => $plugin['path'],
    'template' => 'library-admin-copyright-block',
    'arguments' => array(
      'node' => NULL,
    ),
  );
}
