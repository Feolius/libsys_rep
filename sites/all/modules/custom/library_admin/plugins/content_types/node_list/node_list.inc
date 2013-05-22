<?php
/**
 * @file
 * Ctools content type page title.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_node_list_ctools_content_types() {
    return array(
    'title' => t('Node list'),
    'description' => t('Node list'),
    'category' => t('Library'),
    'icon' => 'node_list.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_node_list_content_type_theme',
    'render callback' => 'library_admin_node_list_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_node_list_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = array();

  if ($output = node_page_default()) {
    $output .= theme('node_list', array('nodes' => (array) $output));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_node_list_content_type_theme(&$theme, $plugin) {
  $theme['node_list'] = array(
    'path' => $plugin['path'],
    'template' => 'node-list',
  );
}
