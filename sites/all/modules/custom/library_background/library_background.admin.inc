<?php

/**
 * @file
 * Menu callbacks and helpers for admin part.
 */

/**
 * Provide a single block from the administration menu as a page.
 *
 * This function is often a destination for these blocks.
 * For example, 'admin/structure/types' needs to have a destination to be valid
 * in the Drupal menu system, but too much information there might be
 * hidden, so we supply the contents of the block.
 *
 * @return
 *   The output HTML.
 */
function library_background_menu_block_page() {
  $item = menu_get_item();
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
  }
  else {
    $output = t('You do not have any administrative items.');
  }
  return $output;
}

/**
 * Settings form for library background settings.
 */
function library_background_settings_form() {
  $form = array();
  $form['#tree'] = TRUE;
  $id = 0;

  // Homepage.
  $form['homepage'] = array(
    '#type' => 'fieldset',
    '#title' => t('Homepage images'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  if (empty($form_state['homepage']['library_background_homepage_num_images'])) {
    $form_state['homepage']['library_background_homepage_num_images'] = 1;
  }

  for ($i = 0; $i < $form_state['homepage']['library_background_homepage_num_images']; $i++) {
    $id = $i;
    $form['homepage']['library_background_homepage_image'][$i] = array(
      '#type' => 'managed_file',
      '#id' => $id,
      '#title' => t('Background image'),
      '#upload_location' => 'public://',
      '#default_value' => variable_get('library_background_homepage_image'),
    );
  }

  $form['homepage']['library_background_add_image_field'] = array(
    '#type' => 'submit',
    '#value' => t('Add another image'),
    '#submit' => array('library_background_add_more_add_one'),
    // See the examples in ajax_example.module for more details on the
    // properties of #ajax.
    '#ajax' => array(
      'callback' => 'field_add_more_js',
      'wrapper' => 'background_image' . $id,
      'effect' => 'fade',
    ),
  );
  $form['homepage']['library_background_remove_image_field'] = array(
    '#type' => 'submit',
    '#value' => t('Remove image'),
    '#submit' => array('library_background_add_more_remove_one'),
    // See the examples in ajax_example.module for more details on the
    // properties of #ajax.
    '#ajax' => array(
      'callback' => 'library_background_more_callback',
      'wrapper' => 'homepage-fieldset-wrapper',
    ),
  );

  // Other pages.
  $form['simple_pages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Another pages'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Callback for library_background_add_image_field.
 */
function library_background_more_callback($form, $form_state) {
  return $form['homepage'];
}

/**
 * Submit handler for the "add-one-more" button.
 *
 * Increments the max counter and causes a rebuild.
 */
function library_background_add_more_add_one(&$form, &$form_state) {
  dpm($form_state);die;
  $button = $form_state['triggering_element'];
  $form_state['homepage']['library_background_homepage_num_images']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "remove one" button.
 *
 * Decrements the max counter and causes a form rebuild.
 */
function library_background_add_more_remove_one(&$form, &$form_state) {
  if ($form_state['library_background_homepage_num_images'] > 1) {
    $form_state['library_background_homepage_num_images']--;
  }
  $form_state['rebuild'] = TRUE;
}
