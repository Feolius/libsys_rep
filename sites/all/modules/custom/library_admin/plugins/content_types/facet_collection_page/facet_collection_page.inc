<?php
/**
 * @file
 * Ctools content type page facet_collection_page.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_facet_collection_page_ctools_content_types() {
  return array(
    'title' => t('Facet collection page'),
    'description' => t('Block for display search results'),
    'category' => t('Library'),
    'icon' => 'faq_menu_block.png',
    'single' => TRUE,
    'render callback' => 'library_admin_facet_collection_page_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_facet_collection_page_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  if (user_access('search content') == TRUE) {
    if ($page = facet_collection_page()) {
      $output = $page;
    }
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}
