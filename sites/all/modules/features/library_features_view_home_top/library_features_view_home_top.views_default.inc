<?php
/**
 * @file
 * library_features_view_home_top.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function library_features_view_home_top_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'home_top';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home Top';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'node-view-home';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'main_view';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: field_home_top_image */
  $handler->display->display_options['fields']['field_field_home_top_image']['id'] = 'field_field_home_top_image';
  $handler->display->display_options['fields']['field_field_home_top_image']['table'] = 'field_data_field_field_home_top_image';
  $handler->display->display_options['fields']['field_field_home_top_image']['field'] = 'field_field_home_top_image';
  $handler->display->display_options['fields']['field_field_home_top_image']['label'] = '';
  $handler->display->display_options['fields']['field_field_home_top_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_field_home_top_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_field_home_top_image']['settings'] = array(
    'image_style' => 'home_top_image_size',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'entry_title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'arrow_link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = '&nbsp;';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'all' => 'all',
    'article' => 'article',
    'page' => 'page',
    'book' => 'book',
    'encyclopedia' => 'encyclopedia',
    'events' => 'events',
    'files' => 'files',
    'home_top_item' => 'home_top_item',
    'location' => 'location',
    'news_article' => 'news_article',
    'openseadragon_test' => 'openseadragon_test',
    'panel' => 'panel',
    'people' => 'people',
    'publications' => 'publications',
    'topics' => 'topics',
  );

  /* Display: Home left */
  $handler = $view->new_display('panel_pane', 'Home left', 'home_left');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'home_top_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_left';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Home region (field_home_region) */
  $handler->display->display_options['arguments']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['arguments']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['arguments']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['arguments']['field_home_region_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_home_region_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_tags_tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Tags (field_tags)',
    ),
  );

  /* Display: Home middle */
  $handler = $view->new_display('panel_pane', 'Home middle', 'home_middle');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'home_top_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_middle';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Home region (field_home_region) */
  $handler->display->display_options['arguments']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['arguments']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['arguments']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['arguments']['field_home_region_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_home_region_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_tags_tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Tags (field_tags)',
    ),
  );

  /* Display: Home right */
  $handler = $view->new_display('panel_pane', 'Home right', 'home_right');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'home_top_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_right';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Home region (field_home_region) */
  $handler->display->display_options['arguments']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['arguments']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['arguments']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['arguments']['field_home_region_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_home_region_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_home_region_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_tags_tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Tags (field_tags)',
    ),
  );
  $translatables['home_top'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('&nbsp;'),
    t('Home left'),
    t('All'),
    t('View panes'),
    t('Home middle'),
    t('Home right'),
  );
  $export['home_top'] = $view;

  return $export;
}
