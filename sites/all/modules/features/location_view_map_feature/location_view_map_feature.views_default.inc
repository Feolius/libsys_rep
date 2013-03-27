<?php
/**
 * @file
 * location_view_map_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function location_view_map_feature_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'location_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Location view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Location view';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_location_geofield']['id'] = 'field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['table'] = 'field_data_field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['field'] = 'field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['label'] = '';
  $handler->display->display_options['fields']['field_location_geofield']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_geofield']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_location_geofield']['field_api_classes'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
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
    'location' => 'location',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'map');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'location_view_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_location_geofield']['id'] = 'field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['table'] = 'field_data_field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['field'] = 'field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['label'] = '';
  $handler->display->display_options['fields']['field_location_geofield']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_geofield']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_location_geofield']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'hide-location-view';

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_data_overlay');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_location_geofield',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
    'view_mode' => 'full',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_location_geofield']['id'] = 'field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['table'] = 'field_data_field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['field'] = 'field_location_geofield';
  $handler->display->display_options['fields']['field_location_geofield']['label'] = '';
  $handler->display->display_options['fields']['field_location_geofield']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_geofield']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location_geofield']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_location_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_location_geofield']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $translatables['location_view'] = array(
    t('Master'),
    t('Location view'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Page'),
    t('OpenLayers Data Overlay'),
  );
  $export['location_view'] = $view;

  return $export;
}
