<?php
/**
 * @file
 * god_s_messenger_page.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function god_s_messenger_page_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-god-s-messenger.
  $menus['menu-god-s-messenger'] = array(
    'menu_name' => 'menu-god-s-messenger',
    'title' => 'God\'s messenger',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('God\'s messenger');


  return $menus;
}
