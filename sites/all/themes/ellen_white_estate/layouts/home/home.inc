<?php
/**
 * Implementation of hook_panels_layouts()
 */

$plugin = array(
  'title' => t('Home'),
  'category' => t('Library'),
  'icon' => 'home.png',
  'theme' => 'home',
  'admin css' => 'home.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left'),
    'middle' => t('Middle'),
    'right' => t('Right'),
  ),
);
