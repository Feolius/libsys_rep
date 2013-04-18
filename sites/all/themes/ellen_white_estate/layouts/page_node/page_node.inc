<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Page node'),
  'category' => t('Library'),
  'icon' => 'page_node.png',
  'theme' => 'page_node',
  'regions' => array(
    'breadcrumb' => t('Breadcrumb'),
    'content' => t('Content'),
    'sidebar' => t('Sidebar'),
  ),
);
