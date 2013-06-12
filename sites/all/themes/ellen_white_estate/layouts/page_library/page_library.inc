<?php
/**
 * Implementation of hook_panels_layouts()
 */
$plugin = array(
  'title' => t('Page library'),
  'category' => t('Library'),
  'icon' => 'page_library.png',
  'theme' => 'page_library',
  'admin css' => 'page_library.css',
  'regions' => array(
    'breadcrumb' => t('Breadcrumb'),
    'content' => t('Content'),
    'right_sidebar' => t('Right sidebar'),
  ),
);
