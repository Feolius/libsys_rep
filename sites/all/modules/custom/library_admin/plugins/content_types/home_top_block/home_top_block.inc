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

/**
 * Implements hook_content_type_edit_form().
 */
function library_admin_home_top_block_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $options = array();
  $vocabularies = taxonomy_get_vocabularies();
  foreach ($vocabularies as $vocabulary) {
    if ($vocabulary->machine_name == LIBRARY_ADMIN_TAXONOMY_TAGS_COLLECTION) {
      $vid = $vocabulary->vid;
    }
  }
  if (isset($vid)) {
    $options = taxonomy_get_tree($vid);
  }
  $form['tags'] = array(
    '#title' => t('Select menu'),
    '#type' => 'select',
    '#default_value' => (!empty($conf['tags'])) ? $conf['tags'] : '',
    '#options' => $options,
    '#multiple' => FALSE,
  );

  return $form;
}

/**
 * Submit handler for settigs form.
 */
function library_admin_home_top_block_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('override_title', 'override_title_text', 'tags') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Implements hook_content_type_admin_info().
 */
function library_admin_home_top_block_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $menus = menu_get_menus();
  $block->title = (!empty($conf['tags'])) ? $menus[$conf['tags']] : '';
  return $block;
}
