<?php
/**
 * @file
 * Ctools content type welcome block.
 */

/**
 * Implements hook_ctools_content_types().
 */
function library_admin_user_menu_block_ctools_content_types() {
  return array(
    'title' => t('User menu'),
    'description' => t('User menu '),
    'category' => t('Library'),
    'icon' => 'user_menu_block.png',
    'single' => TRUE,
    'hook theme' => 'library_admin_user_menu_block_content_type_theme',
    'render callback' => 'library_admin_user_menu_block_content_type_render',
  );
}

/**
 * Implements hook_content_type_render().
 */
function library_admin_user_menu_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  $menu = array();
  if (user_is_logged_in()) {
    $menu[0] = l(
      t('My account'),
      'user'
    );
    $menu[1] = l(
      t('Log out'),
      'user/logout'
    );
  } else {
    $menu[0] = l(
      t('Log in'),
      'user/login'
    );
  }
  if (!empty($menu)) {
    $output .= theme('user_menu_block', array('menu' => $menu));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function library_admin_user_menu_block_content_type_theme(&$theme, $plugin) {
  $theme['user_menu_block'] = array(
    'path' => $plugin['path'],
    'template' => 'user-menu-block',
  );
}
