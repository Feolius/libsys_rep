<?php
/**
 * @file
 * views_to_server.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_to_server_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'category_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Category view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Category view';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content using Category */
  $handler->display->display_options['relationships']['reverse_field_files_category_node']['id'] = 'reverse_field_files_category_node';
  $handler->display->display_options['relationships']['reverse_field_files_category_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_files_category_node']['field'] = 'reverse_field_files_category_node';
  $handler->display->display_options['relationships']['reverse_field_files_category_node']['required'] = 1;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'library_voc_cat' => 'library_voc_cat',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hide-category-view';
  $translatables['category_view'] = array(
    t('Master'),
    t('Category view'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_files_category'),
    t('All'),
    t('Page'),
  );
  $export['category_view'] = $view;

  $view = new view;
  $view->name = 'collection_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Collection View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collection View';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Date (field_files_date) */
  $handler->display->display_options['sorts']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['sorts']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['sorts']['field_files_date_value']['field'] = 'field_files_date_value';
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
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
    'files' => 'files',
  );

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'list');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_files_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['label'] = '';
  $handler->display->display_options['fields']['field_files_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_title']['type'] = 'colletion_layout_title_link';
  $handler->display->display_options['fields']['field_files_title']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Doc type */
  $handler->display->display_options['fields']['field_files_doc_type']['id'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['field'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['label'] = 'Document type';
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_doc_type']['field_api_classes'] = 0;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_files_category']['id'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['fields']['field_files_category']['field'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_category']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_category']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_category']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_files_category']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files_category']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_files_category']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_files_category']['field_api_classes'] = 0;
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_collection']['field_api_classes'] = 0;
  /* Field: Content: Groupe */
  $handler->display->display_options['fields']['field_files_groupe']['id'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['field'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_groupe']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
  $handler->display->display_options['path'] = 'hide-collection-view-list';

  /* Display: Filter Date */
  $handler = $view->new_display('block', 'Filter Date', 'filter_date');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = '';
  $handler->display->display_options['fields']['field_files_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_date']['type'] = 'collection_layout_date_link';
  $handler->display->display_options['fields']['field_files_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_files_date']['field_api_classes'] = 0;

  /* Display: Condensed list */
  $handler = $view->new_display('page', 'Condensed list', 'condensed_list');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_files_image' => 'field_files_image',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_files_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_title']['type'] = 'colletion_layout_title_link';
  $handler->display->display_options['fields']['field_files_title']['field_api_classes'] = 0;
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_collection']['field_api_classes'] = 0;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = 'Publication Date';
  $handler->display->display_options['fields']['field_files_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_date']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_files_date']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
  $handler->display->display_options['path'] = 'hide-collection-view-condensed-list';

  /* Display: Grid */
  $handler = $view->new_display('page', 'Grid', 'grid');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_files_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['label'] = '';
  $handler->display->display_options['fields']['field_files_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_title']['type'] = 'colletion_layout_title_link_small';
  $handler->display->display_options['fields']['field_files_title']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
  $handler->display->display_options['path'] = 'hide-collection-view-grid';

  /* Display: Map */
  $handler = $view->new_display('page', 'Map', 'map');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_files_location']['id'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['table'] = 'field_data_field_files_location';
  $handler->display->display_options['fields']['field_files_location']['field'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['label'] = '';
  $handler->display->display_options['fields']['field_files_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_location']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_files_location']['settings'] = array(
    'node_reference_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_files_location']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'hide-collection-view-map';
  $translatables['collection_view'] = array(
    t('Master'),
    t('Collection View'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('List'),
    t('Document type'),
    t('Category'),
    t('Collection'),
    t('Groupe'),
    t('Filter Date'),
    t('Condensed list'),
    t('Title'),
    t('Publication Date'),
    t('Grid'),
    t('Map'),
  );
  $export['collection_view'] = $view;

  $view = new view;
  $view->name = 'collection_view_taxonomy';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Collection view(taxonomy)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collection';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content using Collection */
  $handler->display->display_options['relationships']['reverse_field_files_collection_node']['id'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['relationships']['reverse_field_files_collection_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_files_collection_node']['field'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['relationships']['reverse_field_files_collection_node']['required'] = 1;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'library_voc_collection' => 'library_voc_collection',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hide-collection-view-taxonomy';
  $translatables['collection_view_taxonomy'] = array(
    t('Master'),
    t('Collection'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_files_collection'),
    t('All'),
    t('Page'),
  );
  $export['collection_view_taxonomy'] = $view;

  $view = new view;
  $view->name = 'document_type_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Document type views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Document type';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content using Doc type */
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['id'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['field'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['required'] = 1;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'library_voc_doc_type' => 'library_voc_doc_type',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hide_document-type-views';
  $translatables['document_type_views'] = array(
    t('Master'),
    t('Document type'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_files_doc_type'),
    t('All'),
    t('Page'),
  );
  $export['document_type_views'] = $view;

  $view = new view;
  $view->name = 'groupe_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Groupe view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Groupe view';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content using Groupe */
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['id'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['field'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['required'] = 1;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'library_voc_groupe' => 'library_voc_groupe',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hide-groupe-view';
  $translatables['groupe_view'] = array(
    t('Master'),
    t('Groupe view'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_files_groupe'),
    t('All'),
    t('Page'),
  );
  $export['groupe_view'] = $view;

  $view = new view;
  $view->name = 'node_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Node view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_files_image']['field_api_classes'] = 0;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_files_location']['id'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['table'] = 'field_data_field_files_location';
  $handler->display->display_options['fields']['field_files_location']['field'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['label'] = '';
  $handler->display->display_options['fields']['field_files_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_location']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_files_location']['settings'] = array(
    'node_reference_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_files_location']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Doc type */
  $handler->display->display_options['fields']['field_files_doc_type']['id'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['field'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['label'] = 'Document type';
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_doc_type]</span>';
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_doc_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_doc_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_doc_type']['field_api_classes'] = 0;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_files_category']['id'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['fields']['field_files_category']['field'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_files_category']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_category]</span>';
  $handler->display->display_options['fields']['field_files_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_category']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_category']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_category']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_files_category']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files_category']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_files_category']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_files_category']['field_api_classes'] = 0;
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_category]</span>';
  $handler->display->display_options['fields']['field_files_collection']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_collection']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_collection']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_collection']['field_api_classes'] = 0;
  /* Field: Content: Groupe */
  $handler->display->display_options['fields']['field_files_groupe']['id'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['field'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_groupe]</span>';
  $handler->display->display_options['fields']['field_files_groupe']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_groupe']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_groupe']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_groupe']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = 'Publication date';
  $handler->display->display_options['fields']['field_files_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_files_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_files_date']['field_api_classes'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
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
    'files' => 'files',
  );

  /* Display: Information */
  $handler = $view->new_display('page', 'Information', 'inf');
  $handler->display->display_options['path'] = 'hide-node-view-inf';

  /* Display: Image(Deep zoom) */
  $handler = $view->new_display('page', 'Image(Deep zoom)', 'image_deep_zoom');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['type'] = 'deepzoom_deepzoom';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'deepzoom_image_style' => 'large',
  );
  $handler->display->display_options['fields']['field_files_image']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'hide-node-view-image-deep-zoom';

  /* Display: Media */
  $handler = $view->new_display('page', 'Media', 'media');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_files_media']['id'] = 'field_files_media';
  $handler->display->display_options['fields']['field_files_media']['table'] = 'field_data_field_files_media';
  $handler->display->display_options['fields']['field_files_media']['field'] = 'field_files_media';
  $handler->display->display_options['fields']['field_files_media']['label'] = '';
  $handler->display->display_options['fields']['field_files_media']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_media']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_media']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_media']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_media']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_media']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_media']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_media']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_media']['settings'] = array(
    'widthxheight' => '640x360',
    'poster_image_style' => '',
  );
  $handler->display->display_options['fields']['field_files_media']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'hide-node-view-media';

  /* Display: Book */
  $handler = $view->new_display('page', 'Book', 'book');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_files_text']['id'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['table'] = 'field_data_field_files_text';
  $handler->display->display_options['fields']['field_files_text']['field'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['label'] = '';
  $handler->display->display_options['fields']['field_files_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_text']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_text']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_text']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_text']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_text']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'hide-node-view-book';
  $translatables['node_view'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h2>[title]</h2>'),
    t('Document type'),
    t('<span class="collection_layout_term_value">[field_files_doc_type]</span>'),
    t('Category'),
    t('<span class="collection_layout_term_value">[field_files_category]</span>'),
    t('Collection'),
    t('Groupe'),
    t('<span class="collection_layout_term_value">[field_files_groupe]</span>'),
    t('Publication date'),
    t('All'),
    t('Information'),
    t('Image(Deep zoom)'),
    t('Media'),
    t('Book'),
  );
  $export['node_view'] = $view;

  $view = new view;
  $view->name = 'timeline_json_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Timeline json view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = '';
  $handler->display->display_options['fields']['field_files_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_files_date']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['label'] = '';
  $handler->display->display_options['fields']['field_files_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_title']['type'] = 'colletion_layout_title_link';
  $handler->display->display_options['fields']['field_files_title']['field_api_classes'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_files_image']['field_api_classes'] = 0;
  /* Sort criterion: Content: Date (field_files_date) */
  $handler->display->display_options['sorts']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['sorts']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['sorts']['field_files_date_value']['field'] = 'field_files_date_value';
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value']['granularity'] = 'year';
  /* Contextual filter: Content: Doc type (field_files_doc_type) */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['not'] = 0;
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_category_tid']['not'] = 0;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_collection_tid']['not'] = 0;
  /* Contextual filter: Content: Groupe (field_files_groupe) */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_files_groupe_tid']['not'] = 0;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_date_value_1']['year_range'] = '1000:2050';
  $handler->display->display_options['arguments']['field_files_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_files_date_value_1']['use_fromto'] = 'no';
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
    'files' => 'files',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['timeline_json_view'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
  );
  $export['timeline_json_view'] = $view;

  return $export;
}
