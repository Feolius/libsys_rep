<?php

/**
 * @file
 * Hooks provided by the Facet Collection module.
 */

/**
 * Define field types that will handle by the module for facet collection. 
 *
 * @return array
 *   An array containing field types.
 */
function hook_facet_collection_field_type_info() {
    return array('date', 'datetime', 'datestamp');
}

/**
 * Define facets and their groups that will handle by the module for facet collection for given field.
 * Facets from different groups can be handled different ways
 *
 * @param array $field_info
 *   Field array. Field type value is always from array returned by hook_facet_collection_field_type_info()
 *
 * @return array
 *   An associative array array keyed by group name and containing Facet API facets defenitions for given field.
 */

function hook_facet_collection_field_facet_groups($field_info) {
    $facets = array();
    $field_name = $field_info['field_name'];
    $facet_name = 'collection_date_facet';
    $label = 'Date';
    $index_field_name = 'dm_facet_collection_date';
    $query_types = array('date');
    $default_widget = 'facetapi_date_range_widget';
    $min_callback = 'facet_collection_get_min_date';
    $max_callback = 'facet_collection_get_max_date';

    $facets[$facet_name] = array(
        'name' => $facet_name,
        'label' => t($label),
        'description' => t('Automatically created facet for facet collection module'),
        'field' => $index_field_name,
        'field alias' => $facet_name,
        'field api name' => $field_name,
        'field api bundles' => array(),
        'query types' => $query_types,
        'default widget' => $default_widget,
        'allowed operators' => array(FACETAPI_OPERATOR_AND => FALSE, FACETAPI_OPERATOR_OR => TRUE),
        'facet mincount allowed' => TRUE,
        'facet missing allowed' => TRUE,
        'map callback' => FALSE,
        'map options' => FALSE,
        'min callback' => $min_callback,
        'max callback' => $max_callback
    );
    $facet_groups['default'] = $facets;
    return $facet_groups;
}

/**
 * Add needed values to solr document for given field
 *
 * @param ApacheSolrDocument $filedocument
 *   ApacheSolrDocument for given node
 *
 * @param stdClass $node
 *   Node object
 *
 * @param array $field_info
 *   Field array
 *
 * @return ApacheSolrDocument
 *   ApacheSolrDocument containing all needed values for given fields
 */

function hook_facet_collection_index_field($filedocument, $node, $field_info) {
    $fields = facet_collection_date_indexing_callback($node, 'dm_facet_collection_date', $field_info);
      foreach ($fields as $field) {
      $filedocument->setMultiValue($field['key'], $field['value']);
    }
    return $filedocument;
}

/**
 * Return list of node bundles for which given facet can be applied
 *
 * @param array $filter_settings
 *   Settings from filters_ui.module
 *
 * @param srting $facet_group
 *   Facet group name for given facet
 *
 * @param string $facet_name
 *   Facet name
 *
 * @param string $searcher
 *   Searcher name
 *
 * @return array
 *   Array containing node bundles for given facet
 */

function hook_facet_collection_facet_content_types($filter_settings, $facet_group, $facet_name, $searcher) {
    $facet_content_types_array = array();
    return $facet_content_types_array;
}