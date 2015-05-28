<?php
/**
 * @file
 * god_s_messenger_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function god_s_messenger_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'god_s_messenger_meeting_kids_needs';
  $page->task = 'page';
  $page->admin_title = 'God’s Messenger: Meeting Kids’ Needs';
  $page->admin_description = '';
  $page->path = 'godpassenger';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'God\'s',
    'name' => 'menu-god-s-messenger',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_god_s_messenger_meeting_kids_needs__panel_context_62a9520c-637c-413e-a21a-d5d01a493888';
  $handler->task = 'page';
  $handler->subtask = 'god_s_messenger_meeting_kids_needs';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'header' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2c59a7d3-a3cc-4a1c-afe2-a574a454f01c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e73efe87-06dd-4a68-9a32-9ec5abbc4881';
    $pane->panel = 'center';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1397952',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e73efe87-06dd-4a68-9a32-9ec5abbc4881';
    $display->content['new-e73efe87-06dd-4a68-9a32-9ec5abbc4881'] = $pane;
    $display->panels['center'][0] = 'new-e73efe87-06dd-4a68-9a32-9ec5abbc4881';
    $pane = new stdClass();
    $pane->pid = 'new-12cff990-a044-43b2-8055-b9151956267c';
    $pane->panel = 'header';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-god-s-messenger';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12cff990-a044-43b2-8055-b9151956267c';
    $display->content['new-12cff990-a044-43b2-8055-b9151956267c'] = $pane;
    $display->panels['header'][0] = 'new-12cff990-a044-43b2-8055-b9151956267c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e73efe87-06dd-4a68-9a32-9ec5abbc4881';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['god_s_messenger_meeting_kids_needs'] = $page;

  return $pages;

}
