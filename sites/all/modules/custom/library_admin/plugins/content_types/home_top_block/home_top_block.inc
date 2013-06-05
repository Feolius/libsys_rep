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
    'render callback' => 'library_admin_home_top_block_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_home_top_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = array();

  if (!empty($conf['home_region'])) {
  $node = library_admin_home_get_node($conf);
    if (!empty($node)) {
      $output = $node;
    }
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function library_admin_home_top_block_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $options = library_admin_get_terms_home_region();
  $form['home_region'] = array(
    '#title' => t('Select menu'),
    '#type' => 'select',
    '#default_value' => (!empty($conf['home_region'])) ? $conf['home_region'] : '',
    '#options' => $options,
    '#multiple' => FALSE,
  );

  return $form;
}

/**
 * Submit handler for settigs form.
 */
function library_admin_home_top_block_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('override_title', 'override_title_text', 'home_region') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Implements hook_content_type_admin_info().
 */
function library_admin_home_top_block_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $terms = library_admin_get_terms_home_region();
  $block->title = (!empty($conf['home_region'])) ? $terms[$conf['home_region']] : '';
  return $block;
}
