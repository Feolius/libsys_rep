<?php
/**
 * Implementation of hook_panels_layouts()
 */

$plugin = array(
  'title' => t('User layout'),
  'category' => t('Library'),
  'icon' => 'page_user_login.png',
  'theme' => 'page_user_login',
  'admin css' => 'page_user_login.css',
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
