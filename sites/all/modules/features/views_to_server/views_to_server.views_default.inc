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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['relationships']['reverse_field_files_category_node']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_category_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['sorts']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['sorts']['field_files_date_value']['field'] = 'field_files_date_value';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['label'] = '';
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_doc_type']['id'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['field'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['label'] = 'Document type';
  $handler->display->display_options['fields']['field_files_doc_type']['element_label_colon'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_files_category']['id'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['fields']['field_files_category']['field'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_category']['delta_offset'] = '0';
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_collection']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_groupe']['id'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['field'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'hide-collection-view-list';

  /* Display: Filter Date */
  $handler = $view->new_display('block', 'Filter Date', 'filter_date');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = '';
  $handler->display->display_options['fields']['field_files_date']['element_label_colon'] = FALSE;

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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = FALSE;
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_collection']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = 'Publication Date';
  $handler->display->display_options['fields']['field_files_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'hide-collection-view-condensed-list';

  /* Display: Grid */
  $handler = $view->new_display('page', 'Grid', 'grid');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['label'] = '';
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'hide-collection-view-grid';

  /* Display: Map */
  $handler = $view->new_display('page', 'Map', 'map');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_location']['id'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['table'] = 'field_data_field_files_location';
  $handler->display->display_options['fields']['field_files_location']['field'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['label'] = '';
  $handler->display->display_options['fields']['field_files_location']['element_label_colon'] = FALSE;
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
    t('Broken handler field_data_field_files_groupe.field_files_groupe'),
    t('Filter Date'),
    t('Condensed list'),
    t('Broken handler field_data_field_files_title.field_files_title'),
    t('Publication Date'),
    t('Grid'),
    t('Map'),
  );
  $export['collection_view'] = $view;

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['relationships']['reverse_field_files_collection_node']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_collection_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['id'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['field'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['relationships']['reverse_field_files_doc_type_node']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_doc_type_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
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
    t('reverse_field_files_doc_type_node'),
    t('All'),
    t('Page'),
  );
  $export['document_type_views'] = $view;

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['id'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['field'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['relationships']['reverse_field_files_groupe_node']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['relationship'] = 'reverse_field_files_groupe_node';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
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
    t('reverse_field_files_groupe_node'),
    t('All'),
    t('Page'),
  );
  $export['groupe_view'] = $view;

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_location']['id'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['table'] = 'field_data_field_files_location';
  $handler->display->display_options['fields']['field_files_location']['field'] = 'field_files_location';
  $handler->display->display_options['fields']['field_files_location']['label'] = '';
  $handler->display->display_options['fields']['field_files_location']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_doc_type']['id'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['field'] = 'field_files_doc_type';
  $handler->display->display_options['fields']['field_files_doc_type']['label'] = 'Document type';
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_files_doc_type']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_doc_type]</span>';
  $handler->display->display_options['fields']['field_files_doc_type']['element_label_colon'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_files_category']['id'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['fields']['field_files_category']['field'] = 'field_files_category';
  $handler->display->display_options['fields']['field_files_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_files_category']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_category]</span>';
  $handler->display->display_options['fields']['field_files_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_files_category']['delta_offset'] = '0';
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_files_collection']['id'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['field'] = 'field_files_collection';
  $handler->display->display_options['fields']['field_files_collection']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_files_collection']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_category]</span>';
  $handler->display->display_options['fields']['field_files_collection']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_collection']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_groupe']['id'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['field'] = 'field_files_groupe';
  $handler->display->display_options['fields']['field_files_groupe']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_files_groupe']['alter']['text'] = '<span class="collection_layout_term_value">[field_files_groupe]</span>';
  $handler->display->display_options['fields']['field_files_groupe']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = 'Publication date';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['path'] = 'hide-node-view-inf';

  /* Display: Image(Deep zoom) */
  $handler = $view->new_display('page', 'Image(Deep zoom)', 'image_deep_zoom');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['type'] = 'deepzoom_deepzoom';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'deepzoom_image_style' => 'large',
  );
  $handler->display->display_options['path'] = 'hide-node-view-image-deep-zoom';

  /* Display: Media */
  $handler = $view->new_display('page', 'Media', 'media');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_media']['id'] = 'field_files_media';
  $handler->display->display_options['fields']['field_files_media']['table'] = 'field_data_field_files_media';
  $handler->display->display_options['fields']['field_files_media']['field'] = 'field_files_media';
  $handler->display->display_options['fields']['field_files_media']['label'] = '';
  $handler->display->display_options['fields']['field_files_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'hide-node-view-media';

  /* Display: Book(flexpaper) */
  $handler = $view->new_display('page', 'Book(flexpaper)', 'book_flexpaper');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_files_text']['id'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['table'] = 'field_data_field_files_text';
  $handler->display->display_options['fields']['field_files_text']['field'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['label'] = '';
  $handler->display->display_options['fields']['field_files_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_text']['click_sort_column'] = 'fid';
  $handler->display->display_options['path'] = 'hide-node-view-book-flexpaper';

  /* Display: Book(google docs) */
  $handler = $view->new_display('page', 'Book(google docs)', 'book_google_docs');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_files_text']['id'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['table'] = 'field_data_field_files_text';
  $handler->display->display_options['fields']['field_files_text']['field'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['label'] = '';
  $handler->display->display_options['fields']['field_files_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_text']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_text']['type'] = 'book_field_google_doc_formatter';
  $handler->display->display_options['path'] = 'hide-node-view-book-google-docs';

  /* Display: Book(file link) */
  $handler = $view->new_display('page', 'Book(file link)', 'book_file_link');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_files_text']['id'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['table'] = 'field_data_field_files_text';
  $handler->display->display_options['fields']['field_files_text']['field'] = 'field_files_text';
  $handler->display->display_options['fields']['field_files_text']['label'] = '';
  $handler->display->display_options['fields']['field_files_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_text']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_text']['type'] = 'file_link_formatter';
  $handler->display->display_options['path'] = 'hide-node-view-book-file-link';

  /* Display: Node Prev */
  $handler = $view->new_display('block', 'Node Prev', 'node_prev');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node-page?nid=[nid]';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'm-icon-big-swapleft';
  $handler->display->display_options['fields']['nid']['alter']['prefix'] = '<div class="collection_layout_slider_button_left">';
  $handler->display->display_options['fields']['nid']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';

  /* Display: Node Next */
  $handler = $view->new_display('block', 'Node Next', 'node_next');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node-page?nid=[nid]';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'm-icon-big-swapright';
  $handler->display->display_options['fields']['nid']['alter']['prefix'] = '<div class="collection_layout_slider_button_right">';
  $handler->display->display_options['fields']['nid']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
    t('Broken handler field_data_field_files_groupe.field_files_groupe'),
    t('<span class="collection_layout_term_value">[field_files_groupe]</span>'),
    t('Publication date'),
    t('All'),
    t('Information'),
    t('Image(Deep zoom)'),
    t('Media'),
    t('Book(flexpaper)'),
    t('Book(google docs)'),
    t('Book(file link)'),
    t('Node Prev'),
    t('<div class="collection_layout_slider_button_left">'),
    t('</div>'),
    t('Node Next'),
    t('<div class="collection_layout_slider_button_right">'),
  );
  $export['node_view'] = $view;

  $view = new view();
  $view->name = 'similar_files';
  $view->description = 'View with custom displays for the blocks with similar files at the sidebar';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Similar Files';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Similar Files';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Primary Media (field_files_primary_media) */
  $handler->display->display_options['arguments']['field_files_primary_media_value']['id'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['table'] = 'field_data_field_files_primary_media';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['field'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['limit'] = '0';
  /* Contextual filter: Content: Artist (field_files_artist) */
  $handler->display->display_options['arguments']['field_files_artist_target_id']['id'] = 'field_files_artist_target_id';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['table'] = 'field_data_field_files_artist';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['field'] = 'field_files_artist_target_id';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['summary']['format'] = 'default_summary';
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

  /* Display:  Same People */
  $handler = $view->new_display('page', ' Same People', 'same_people');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Primary Media (field_files_primary_media) */
  $handler->display->display_options['arguments']['field_files_primary_media_value']['id'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['table'] = 'field_data_field_files_primary_media';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['field'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['limit'] = '0';
  /* Contextual filter: Content: People Tags (field_files_people_tags) */
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['id'] = 'field_files_people_tags_target_id';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['table'] = 'field_data_field_files_people_tags';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['field'] = 'field_files_people_tags_target_id';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_people_tags_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'hide-same-people';

  /* Display: Same Event */
  $handler = $view->new_display('page', 'Same Event', 'same_event');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Primary Media (field_files_primary_media) */
  $handler->display->display_options['arguments']['field_files_primary_media_value']['id'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['table'] = 'field_data_field_files_primary_media';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['field'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['limit'] = '0';
  /* Contextual filter: Content: Event Tags (field_files_event_tags) */
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['id'] = 'field_files_event_tags_target_id';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['table'] = 'field_data_field_files_event_tags';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['field'] = 'field_files_event_tags_target_id';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_event_tags_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'hide-same-event';

  /* Display: Same Location */
  $handler = $view->new_display('page', 'Same Location', 'same_location');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Primary Media (field_files_primary_media) */
  $handler->display->display_options['arguments']['field_files_primary_media_value']['id'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['table'] = 'field_data_field_files_primary_media';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['field'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['limit'] = '0';
  /* Contextual filter: Content: Location Tags (field_files_location_tags) */
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['id'] = 'field_files_location_tags_target_id';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['table'] = 'field_data_field_files_location_tags';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['field'] = 'field_files_location_tags_target_id';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_location_tags_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'hide-same-location';

  /* Display: Same Topic */
  $handler = $view->new_display('page', 'Same Topic', 'same_topic');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Primary Media (field_files_primary_media) */
  $handler->display->display_options['arguments']['field_files_primary_media_value']['id'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['table'] = 'field_data_field_files_primary_media';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['field'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['limit'] = '0';
  /* Contextual filter: Content: Topic Tags (field_files_topic_tags) */
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['id'] = 'field_files_topic_tags_target_id';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['table'] = 'field_data_field_files_topic_tags';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['field'] = 'field_files_topic_tags_target_id';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_topic_tags_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'hide-same-topic';

  /* Display: Same Artist */
  $handler = $view->new_display('page', 'Same Artist', 'same_artist');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Primary Media (field_files_primary_media) */
  $handler->display->display_options['arguments']['field_files_primary_media_value']['id'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['table'] = 'field_data_field_files_primary_media';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['field'] = 'field_files_primary_media_value';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_primary_media_value']['limit'] = '0';
  /* Contextual filter: Content: Artist (field_files_artist) */
  $handler->display->display_options['arguments']['field_files_artist_target_id']['id'] = 'field_files_artist_target_id';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['table'] = 'field_data_field_files_artist';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['field'] = 'field_files_artist_target_id';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_artist_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'hide-same-artist';
  $translatables['similar_files'] = array(
    t('Master'),
    t('Similar Files'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t(' Same People'),
    t('Same Event'),
    t('Same Location'),
    t('Same Topic'),
    t('Same Artist'),
  );
  $export['similar_files'] = $view;

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_date']['id'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['fields']['field_files_date']['field'] = 'field_files_date';
  $handler->display->display_options['fields']['field_files_date']['label'] = '';
  $handler->display->display_options['fields']['field_files_date']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_files_title']['id'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['table'] = 'field_data_field_files_title';
  $handler->display->display_options['fields']['field_files_title']['field'] = 'field_files_title';
  $handler->display->display_options['fields']['field_files_title']['label'] = '';
  $handler->display->display_options['fields']['field_files_title']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_files_image']['id'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['table'] = 'field_data_field_files_image';
  $handler->display->display_options['fields']['field_files_image']['field'] = 'field_files_image';
  $handler->display->display_options['fields']['field_files_image']['label'] = '';
  $handler->display->display_options['fields']['field_files_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_files_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['sorts']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['sorts']['field_files_date_value']['field'] = 'field_files_date_value';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value']['id'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['id'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['table'] = 'field_data_field_files_doc_type';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['field'] = 'field_files_doc_type_tid';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_doc_type_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_files_category) */
  $handler->display->display_options['arguments']['field_files_category_tid']['id'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['table'] = 'field_data_field_files_category';
  $handler->display->display_options['arguments']['field_files_category_tid']['field'] = 'field_files_category_tid';
  $handler->display->display_options['arguments']['field_files_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Collection (field_files_collection) */
  $handler->display->display_options['arguments']['field_files_collection_tid']['id'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['table'] = 'field_data_field_files_collection';
  $handler->display->display_options['arguments']['field_files_collection_tid']['field'] = 'field_files_collection_tid';
  $handler->display->display_options['arguments']['field_files_collection_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_collection_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_files_collection_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_groupe_tid']['id'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['table'] = 'field_data_field_files_groupe';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['field'] = 'field_files_groupe_tid';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_groupe_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_files_date_value_1']['id'] = 'field_files_date_value_1';
  $handler->display->display_options['arguments']['field_files_date_value_1']['table'] = 'field_data_field_files_date';
  $handler->display->display_options['arguments']['field_files_date_value_1']['field'] = 'field_files_date_value';
  $handler->display->display_options['arguments']['field_files_date_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_files_date_value_1']['summary_options']['items_per_page'] = '25';
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

  /* Display: Timeline json */
  $handler = $view->new_display('block', 'Timeline json', 'timeline_json');
  $translatables['timeline_json_view'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Timeline json'),
  );
  $export['timeline_json_view'] = $view;

  return $export;
}
