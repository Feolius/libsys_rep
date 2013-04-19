<?php
/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Main layout'),
  'category' => t('Library'),
  'icon' => 'main.png',
  'theme' => 'main',
  'admin css' => 'main.css',
  'regions' => array(
    'header_left' => t('Header left'),
    'header_search_block' => t('Header search block'),
    'header_menu' => t('Header menu'),
    'content' => t('Content'),
    'footer' => t('Footer'),
    'footer_left' => t('Footer left'),
    'footer_right' => t('Footer right'),
  ),
);
