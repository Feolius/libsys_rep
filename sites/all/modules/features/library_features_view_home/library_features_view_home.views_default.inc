<?php
/**
 * @file
 * library_features_view_home.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function library_features_view_home_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'main_view';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'qwertye' => 0,
    'www' => 0,
  );
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
  /* Contextual filter: Nodequeue: Queue title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'nodequeue_queue';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['arguments']['title']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
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
  /* Filter criterion: Content: Home region (field_home_region) */
  $handler->display->display_options['filters']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['filters']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['value'] = array(
    0 => '5793',
  );
  $handler->display->display_options['filters']['field_home_region_tid']['vocabulary'] = 'home_region';

  /* Display: Home top */
  $handler = $view->new_display('panel_pane', 'Home top', 'home_top');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'main_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_top';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodequeue: Queue title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'nodequeue_queue';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['arguments']['title']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Home region (field_home_region) */
  $handler->display->display_options['filters']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['filters']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['value'] = array(
    0 => '10',
  );
  $handler->display->display_options['filters']['field_home_region_tid']['vocabulary'] = 'home_region';
  $handler->display->display_options['argument_input'] = array(
    'title' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Nodequeue: Queue title',
    ),
  );

  /* Display: Home left */
  $handler = $view->new_display('panel_pane', 'Home left', 'home_left');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'main_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_left';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Home region (field_home_region) */
  $handler->display->display_options['filters']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['filters']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['value'] = array(
    0 => '6',
  );
  $handler->display->display_options['filters']['field_home_region_tid']['vocabulary'] = 'home_region';
  $handler->display->display_options['argument_input'] = array(
    'title' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Nodequeue: Queue title',
    ),
  );

  /* Display: Home middle */
  $handler = $view->new_display('panel_pane', 'Home middle', 'home_middle');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'main_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_middle';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Home region (field_home_region) */
  $handler->display->display_options['filters']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['filters']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['value'] = array(
    0 => '8',
  );
  $handler->display->display_options['filters']['field_home_region_tid']['vocabulary'] = 'home_region';
  $handler->display->display_options['argument_input'] = array(
    'title' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Nodequeue: Queue title',
    ),
  );

  /* Display: Home right */
  $handler = $view->new_display('panel_pane', 'Home right', 'home_right');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'main_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_right';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Home region (field_home_region) */
  $handler->display->display_options['filters']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['filters']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['value'] = array(
    0 => '9',
  );
  $handler->display->display_options['filters']['field_home_region_tid']['vocabulary'] = 'home_region';
  $handler->display->display_options['argument_input'] = array(
    'title' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Nodequeue: Queue title',
    ),
  );

  /* Display: Home bottom */
  $handler = $view->new_display('panel_pane', 'Home bottom', 'home_bottom');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'main_view';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'home_bottom';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Home region (field_home_region) */
  $handler->display->display_options['filters']['field_home_region_tid']['id'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['table'] = 'field_data_field_home_region';
  $handler->display->display_options['filters']['field_home_region_tid']['field'] = 'field_home_region_tid';
  $handler->display->display_options['filters']['field_home_region_tid']['value'] = array(
    0 => '11',
  );
  $handler->display->display_options['filters']['field_home_region_tid']['vocabulary'] = 'home_region';
  $handler->display->display_options['argument_input'] = array(
    'title' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Nodequeue: Queue title',
    ),
  );
  $translatables['homepage'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('All'),
    t('Home top'),
    t('View panes'),
    t('Home left'),
    t('Home middle'),
    t('Home right'),
    t('Home bottom'),
  );
  $export['homepage'] = $view;

  return $export;
}
