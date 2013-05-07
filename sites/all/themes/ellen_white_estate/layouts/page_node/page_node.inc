<?php
/**
 * Implementation of hook_panels_layouts()
 */
$plugin = array(
  'title' => t('Page node'),
  'category' => t('Library'),
  'icon' => 'page_node.png',
  'theme' => 'page_node',
  'admin css' => 'page_node.css',
  'regions' => array(
    'breadcrumb' => t('Breadcrumb'),
    'content' => t('Content'),
    'right_sidebar' => t('Right sidebar'),
  ),
);
