<?php
/**
 * @file
 * Ctools content type page title.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_home_top_block_ctools_content_types() {
    return array(
    'title' => t('Home top block'),
    'description' => t('Copyright text to display in the footer'),
    'category' => t('Library'),
    'icon' => 'node_list.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_home_top_block_content_type_theme',
    'render callback' => 'library_admin_home_top_block_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_home_top_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';

  $output .= theme('home_top_block', array('results' => $output));

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_home_top_block_content_type_theme(&$theme, $plugin) {
  $theme['home_top_block'] = array(
    'path' => $plugin['path'],
    'template' => 'home-top-block',
  );
}
