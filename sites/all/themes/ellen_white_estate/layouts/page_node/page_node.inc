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
    'content' => t('Content'),
  ),
);
