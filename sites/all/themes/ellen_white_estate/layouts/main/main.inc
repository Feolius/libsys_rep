<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Main layout'),
  'category' => t('Library'),
  'icon' => 'page_node.png',
  'theme' => 'main',
  'regions' => array(
    'header_left' => t('Header left'),
    'header_search_block' => t('Header search block'),
    'content' => t('Content'),
    'right_sidebar' => t('Right sidebar'),
    'footer' => t('Footer'),
  ),
);
