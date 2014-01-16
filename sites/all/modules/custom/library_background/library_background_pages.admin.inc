<?php
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
function library_background_pages_settings_form () {
  $form = array();

  $form['library_background_simple_css_repeat'] = array(
    '#type' => 'radios',
    '#title' => t('Repeat'),
    '#default_value' => variable_get('library_background_simple_css_repeat') ? variable_get('library_background_simple_css_repeat') : 'repeat',
    '#options' => array(
      'repeat' => t('Repeat'),
      'repeat-x' => t('Repeat Horizontally'),
      'repeat-y' => t('Repeat Vertically'),
      'no-repeat' => t('No Repeat')
    ),
    '#required' => TRUE,
  );

  $form['library_background_simple_css_h_position'] = array(
    '#type' => 'radios',
    '#title' => t('Horizontal Position'),
    '#default_value' => variable_get('library_background_simple_css_h_position') ? variable_get('library_background_simple_css_h_position') : 'center',
    '#options' => array(
      'left' => t('Left'),
      'center' => t('Center'),
      'right' => t('Right'),
      'other' => t('Other')
    ),
    '#required' => TRUE,
  );

  $form['library_background_simple_css_h_position_other'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('library_background_simple_css_h_position_other', ''),
    '#required' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="library_background_simple_css_h_position"]' => array('value' => 'other'),
      ),
    ),
  );

  $form['library_background_simple_css_v_position'] = array(
    '#type' => 'radios',
    '#title' => t('Vertical Position'),
    '#default_value' => variable_get('library_background_simple_css_v_position') ? variable_get('library_background_simple_css_v_position') : 'center',
    '#options' => array(
      'top' => t('Top'),
      'center' => t('Center'),
      'bottom' => t('Bottom'),
      'other' => t('Other')
    ),
    '#required' => TRUE,
  );

  $form['library_background_simple_css_v_position_other'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('library_background_simple_css_v_position_other', ''),
    '#required' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="library_background_simple_css_v_position"]' => array('value' => 'other'),
      ),
    ),
  );

  $form['library_background_simple_css_attachment'] = array(
    '#type' => 'radios',
    '#title' => t('Attachment'),
    '#default_value' => variable_get('library_background_simple_css_attachment') ? variable_get('library_background_simple_css_attachment') : 'fixed',
    '#options' => array(
      'scroll' => t('Scroll'),
      'fixed' => t('Fixed'),
    ),
    '#required' => TRUE,
  );

  $form['library_background_simple_css_important'] = array(
    '#type' => 'checkbox',
    '#title' => t('!important'),
    '#default_value' => variable_get('library_background_simple_css_important') != FALSE ? variable_get('library_background_simple_css_important') : '',
  );

  $form['library_background_simple_uploaded_images'] = array(
    '#markup' => library_background_load_files(FALSE),
  );

  $form['library_background_simple_deleted_image'] = array('#type' => 'hidden', '#value' => '');

  $form['library_background_simple_image'] = array(
    '#type' => 'plupload',
    '#title' => t('Background image'),
    '#autosubmit' => FALSE,
    '#default_value' => variable_get('library_background_simple_image', ''),
    '#upload_validators' => array(
      'file_validate_extensions' => array('jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp'),
    ),
  );

  $form['library_background_simple_deleted_image'] = array(
    '#type' => 'textfield',
    '#default_value' => '',
    '#required' => FALSE,
    '#attributes' => array('class' => array('hide-me'))
  );

  // Callbacks.
  //$form['#submit'][] = 'library_background_others_image_submit';
  //$form['#submit'][] = 'library_background_homepage_uploaded_images_remove_callback';

  return $form;
}