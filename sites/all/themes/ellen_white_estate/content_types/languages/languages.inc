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
);

/**
 * Output function for the 'languages' content type.
 */
function ellen_white_estate_languages_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $prefix = '<div class="languages">';
  $suffix = '</div>';
  $output = [];
  $flags = array('flag us', 'flag de', 'flag fr', 'flag es', 'flag it', 'flag jp');
  foreach ($flags as $flag) {
    $output[] = l(
      t(''),
      '#',
      array(
        'attributes' => array(
          'class' => $flag,
        ),
        'html' => FALSE,
      )
    );
  };
  $block->content = array('results' => $output);

  return $block;
}
