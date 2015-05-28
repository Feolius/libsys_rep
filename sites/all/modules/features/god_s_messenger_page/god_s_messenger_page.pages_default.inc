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
          1 => 'right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '69.94877786833489',
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
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '30.051222131665114',
        'width_type' => '%',
        'parent' => 'main-row',
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
      'right' => NULL,
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
      'override_title' => 1,
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
    $pane->pid = 'new-f08edc40-af22-4dda-ad0e-c40f472909aa';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Top images',
      'title' => '',
      'body' => '<div class="toplogo"><img alt="" src="sites/ellenwhite.org/files/egw_custom_images/topbnr.jpg" /></div><div class="botlogo"><img alt="" src="sites/ellenwhite.org/files/egw_custom_images/botlogo.jpg" style="width: 198px; height: 74px;" /></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f08edc40-af22-4dda-ad0e-c40f472909aa';
    $display->content['new-f08edc40-af22-4dda-ad0e-c40f472909aa'] = $pane;
    $display->panels['header'][0] = 'new-f08edc40-af22-4dda-ad0e-c40f472909aa';
    $pane = new stdClass();
    $pane->pid = 'new-548ca78e-c502-4494-8269-197af16e248f';
    $pane->panel = 'header';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '548ca78e-c502-4494-8269-197af16e248f';
    $display->content['new-548ca78e-c502-4494-8269-197af16e248f'] = $pane;
    $display->panels['header'][1] = 'new-548ca78e-c502-4494-8269-197af16e248f';
    $pane = new stdClass();
    $pane->pid = 'new-f9e4ac51-b003-479b-a6c5-4198cdd81311';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Ellen White Quote ',
      'title' => '',
      'body' => '<div id="egwquote" >
<h3 align="center"><font face="Arial, Helvetica, sans-serif"><i>Ellen White 
        Quote </i></font></h3>
<p align="center"><font face="Arial, Helvetica, sans-serif">"To restore 
        in man the image of his Maker, to bring him back to the perfection in 
        which he was created, to promote the development of body, mind, and soul, 
        that the divine purpose in his creation might be realized&mdash;this was 
        to be the work of redemption. This is the object of education, the great 
        object of life."</font></p>
<h5 align="center"><font face="Arial, Helvetica, sans-serif"><em>Education,</em> 
        pp. 15, 16</font></h5>
</div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f9e4ac51-b003-479b-a6c5-4198cdd81311';
    $display->content['new-f9e4ac51-b003-479b-a6c5-4198cdd81311'] = $pane;
    $display->panels['right'][0] = 'new-f9e4ac51-b003-479b-a6c5-4198cdd81311';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e73efe87-06dd-4a68-9a32-9ec5abbc4881';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['god_s_messenger_meeting_kids_needs'] = $page;

  return $pages;

}
