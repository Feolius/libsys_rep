<?php
/**
 * @file
 * Ctools content type language block.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_language_block_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Language list'),
    'description' => t(''),
    'category' => t('Library'),
    'icon' => 'language_block.png',
    'hook theme' => 'library_admin_language_block_content_type_theme',
  );
}

/**
 * Implements hook_content_types_render().
 */
function library_admin_language_block_content_types_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  $flags = array();
  $output .= theme('language_block', array('results' => $flags));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

function library_admin_language_block_content_types_theme(&$teme, $plugin) {
  $theme['language_block'] = array(
    'path' => $plugin['path'],
    'template' => 'library-admin-language-block',
  );
}
