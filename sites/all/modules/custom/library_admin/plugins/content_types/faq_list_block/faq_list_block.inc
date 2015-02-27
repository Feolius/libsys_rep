<?php
/**
 * @file
 * Ctools content type page faq_nodes_list.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_faq_list_block_ctools_content_types() {
  return array(
    'title' => t('FAQ nodes list block'),
    'description' => t('Block for display list of faq nodes'),
    'category' => t('Library'),
    'icon' => 'faq_list_block.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_faq_list_block_content_type_theme',
    'render callback' => 'library_admin_faq_list_block_content_type_render',
  );
}


/**
 * Implements hook_content_type_render().
 */
function library_admin_faq_list_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  if ($form = drupal_get_form('library_admin_faq_list_form')) {
    $output .= theme('faq_list_block', array('form' => $form));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_faq_list_block_content_type_theme(&$theme, $plugin) {
  $theme['faq_list_block'] = array(
    'path' => $plugin['path'],
    'template' => 'faq-list-block',
  );
}

/**
 * Form for search by faq page.
 */
function library_admin_faq_list_form($form, $form_state) {
  drupal_add_js(drupal_get_path('module', 'library_admin') .'/plugins/content_types/faq_list_block/faq_list_block.js');
  drupal_set_title(t('FAQ'));
  $nodes = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('n.type', 'faq')
    ->execute();
  foreach ($nodes as $node) {
    $items[$node->nid]['title'] = $node->title;
    $items[$node->nid]['href'] = 'node/'.$node->nid;
  }

  $form['results'] = array(
    '#type' => 'item',
    '#title' => l(t('Show all'),'answers',array('fragment'=>'showallfaq')),
    '#markup' => theme('links',array(
      'links' => $items,
      'attributes' => array('class' => array(''),'id'=>'showallfaq','style'=>"display:none")
      )
    ),
  );

  return $form;
}