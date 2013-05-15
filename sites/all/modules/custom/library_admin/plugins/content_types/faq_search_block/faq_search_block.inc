<?php
/**
 * @file
 * Ctools content type page faq_search_block.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_faq_search_block_ctools_content_types() {
    return array(
    'title' => t('Form search faq'),
    'description' => t('Form search for faq'),
    'category' => t('Library'),
    'icon' => 'faq_menu_block.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_faq_search_block_content_type_theme',
    'render callback' => 'library_admin_faq_search_block_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_faq_search_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  if ($form = drupal_get_form('library_admin_faq_form')) {
    $output .= theme('faq_search_block', array('form' => $form));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_faq_search_block_content_type_theme(&$theme, $plugin) {
  $theme['faq_search_block'] = array(
    'path' => $plugin['path'],
    'template' => 'faq-search-block',
  );
}
