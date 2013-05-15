<?php
/**
 * @file
 * Ctools content type page faq_search_block.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_faq_menu_block_ctools_content_types() {
    return array(
    'title' => t('Block menu faq'),
    'description' => t('Block for display menu-faq'),
    'category' => t('Library'),
    'icon' => 'faq_menu_block.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_faq_menu_block_content_type_theme',
    'render callback' => 'library_admin_faq_menu_block_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_faq_menu_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  $items = array();
  if ($items['menu'] = menu_tree('menu-faq')) {
    $items['title'] = t('Browse');
    $output .= theme('faq_menu_block', array('items' => $items));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_faq_menu_block_content_type_theme(&$theme, $plugin) {
  $theme['faq_menu_block'] = array(
    'path' => $plugin['path'],
    'template' => 'faq-menu-block',
  );
}
