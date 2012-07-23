<?php
/**
 * @file
 * to_server.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function to_server_views_default_views() {
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
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
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_files_date']['field_api_classes'] = 0;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Date (field_files_date) */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['path'] = 'hide_collection-view';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
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
  $export['groupe_view'] = $view;

  return $export;
}
