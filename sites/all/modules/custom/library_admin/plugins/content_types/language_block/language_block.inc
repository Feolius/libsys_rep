<?php
/**
 * @file
 * Ctools content type language block.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_language_block_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Language list'),
    'description' => t(''),
    'category' => t('Library'),
    'icon' => 'language_block.png',
    'hook theme' => 'library_admin_language_block_content_types_theme',
    'render callback' => 'library_admin_language_block_content_types_render',
  );
}

/**
 * Implements hook_content_types_render().
 */
function library_admin_language_block_content_types_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  $results = array();
  if ($flags = variable_get('library_admin_language')) {
    $items = explode(',', $flags);
    if (is_array($items)) {
      foreach ($items as $item) {
        if (!empty($item) && $item !== ' ') {
          $results[] = l(
            t(''),
            '#',
            array(
              'external' => TRUE,
              'attributes' => array(
                'class' => "flag {$item}",
              ),
            )
          );
        }
      }
    }
    $output .= theme('language_block', array('results' => $results));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_types_theme().
 */
function library_admin_language_block_content_types_theme(&$theme, $plugin) {
  $theme['language_block'] = array(
    'path' => $plugin['path'],
    'template' => 'language-block',
  );
}
