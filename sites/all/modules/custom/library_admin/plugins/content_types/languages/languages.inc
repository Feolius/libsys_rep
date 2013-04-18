<?php

/**
 * @file
 * Languages content type.
 */
$plugin = array(
  'title' => t('Languages'),
  'single' => TRUE,
  'icon' => 'languages.png',
  'description' => t('Add the languages block.'),
  'category' => t('Library'),
  'hook theme' => 'library_admin_languages_content_type_theme',
);

/**
 * Output function for the 'languages' content type.
 */
function library_admin_languages_content_type_render($subtype, $conf, $panel_args) {
  $output = '';
  $results = [];
  $languages = variable_get('library_admin_language');
  if (!empty($languages)) {
    $flags = explode(',', $languages);
    foreach ($flags as $flag) {
      $results[] = l(
        t(''),
        '#',
        array(
          'attributes' => array(
            'class' => "flag {$flag}",
          ),
          'html' => FALSE,
        )
      );
    };
  }
  $output .= theme('library_admin_languages', array('results' => $results));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_languages_content_type_theme(&$theme, $plugin) {
  $theme['library_admin_languages'] = array(
    'path' => $plugin['path'],
    'template' => 'library-admin-languages',
    'arguments' => array(
      'links' => NULL,
    ),
  );
}