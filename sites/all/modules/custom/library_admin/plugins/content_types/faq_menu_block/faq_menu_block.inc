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
  if ($items['menu'] = menu_tree($conf['menu'])) {
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

/**
 * Implements hook_content_type_edit_form().
 */
function library_admin_faq_menu_block_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $options = menu_get_menus();
  $form['menu'] = array(
    '#title' => t('Select menu'),
    '#type' => 'select',
    '#default_value' => (!empty($conf['menu'])) ? $conf['menu'] : '',
    '#options' => $options,
    '#multiple' => FALSE,
  );

  return $form;
}

/**
 * Submit handler for settigs form.
 */
function library_admin_faq_menu_block_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('override_title', 'override_title_text', 'menu') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Implements hook_content_type_admin_info().
 */
function library_admin_faq_menu_block_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $menus = menu_get_menus();
  $block->title = $menus[$conf['menu']];
  return $block;
}
