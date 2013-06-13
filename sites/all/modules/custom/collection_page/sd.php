<?php

function theme_facet_collection_search_results__alter($variables) {
  $content_tabs = array(
    '#standard-default' => array(
      '#id' => 'standard-default-view',
      '#title' => 'Standard View (Default)',
      '#class' => 'standart',
    ),
    '#standard-thumbnail' => array(
      '#id' => 'standard-thumbnail-view',
      '#title' => 'Standard View (Thumbnail)',
      '#class' => 'thumbnail',
    ),
    '#timeline' => array(
      '#id' => 'timeline-view',
      '#title' => t('Timeline View'),
      '#class' => 'timeline',
    ),
    '#location' => array(
      '#id' => 'location-view',
      '#title' => t('Location View'),
      '#class' => 'location',
    ),
  );
  $disabled_tabs = array();

  $results = $variables['results'];
  $content_tabs['#standard-default']['#content'] = array(theme('collection_standard_default_view', array('results' => $results)));
  $content_tabs['#standard-thumbnail']['#content'] = array(theme('collection_standard_thumbnail_view', array('results' => $results)));


  //Put apache_solr request results into SESSION for process those in timeline data callback
  $_SESSION['collection_page_apache_solr_results'] = $results;

  //Define for what bundle current apache_solr request was executed
  $bundle = '';
  if (isset($_GET['f'])) {
    foreach ($_GET['f'] as $filter) {
      $exploded_filter = explode(':', $filter);
      if ($exploded_filter[0] == 'bundle') {
        $bundle = $exploded_filter[1];
      }
    }
  }

  //Set page title
  drupal_set_title('Library');

  $timeline_library = libraries_get_path('timeline');
  $bundle_date_fields = _collection_page_get_date_fields_from_bundle($bundle);
  if (!empty($timeline_library) && !empty($bundle_date_fields)) {
    $content_tabs['#timeline']['#content'] = array(
      '#view' => theme('timeline_iframe'),
      '#pager' => theme('pager', array('tags' => NULL)),
    );
  }
  else {
    $disabled_tabs[] = '#timeline';
  }

  $node_ids = '';
  foreach ($results as $result) {
    if ($result['bundle'] == 'location') {
      //Collect NIDs of nodes for bundle Location
      $node_ids = implode(',', array($node_ids, $result['node']->entity_id));
    }
    else {
      $node = node_load($result['node']->entity_id);
      //Collect NIDs of referenced location nodes for bunlde Files
      $instances = field_info_instances('node', $node->type);
      foreach ($instances as $field_name => $instance) {
        $field_info = field_info_field($field_name);
        if ($field_info['type'] == 'entityreference' && in_array('location', $field_info['settings']['handler_settings']['target_bundles'])) {
          $items = field_get_items('node', $node, $field_info['field_name']);
          if (!empty($items)) {
            $node_ids = implode(',', array($node_ids, $items[0]['target_id']));
          }
        }
      }
    }

  }
  $node_ids = substr($node_ids, 1);
  $location_view_openlayer_map = NULL;
  if (!empty($node_ids)) {
    $location_view_openlayer_map = views_embed_view('location_view', 'map', $node_ids);
  }
  if (!empty($location_view_openlayer_map)) {
    $content_tabs['#location']['#content'] = array(
      '#view' => $location_view_openlayer_map,
      '#pager' => theme('pager', array('tags' => NULL)),
    );
  }
  else {
    $disabled_tabs[] = '#location';
  }

  $tabs = array_keys($content_tabs);
//Define default and disabled tabs on collection page
  switch ($bundle) {
    case 'people':
    case 'events':
      $default_tab = array_search('#timeline', $tabs);
      break;
    case 'location':
      $default_tab = array_search('#location', $tabs);
      break;
    default:
      $default_tab = array_search('#standard_default', $tabs);
      break;
  }

  foreach ($disabled_tabs as $disabled_tab) {
    $disabled_tabs_for_js[] = array_search($disabled_tab, $tabs);
  }

//Include on page supports files for building tabs and inserting into them needed views
//like timeline, default or location views
  drupal_add_library('system', 'ui.tabs');
  drupal_add_css(drupal_get_path('module', 'collection_page') . '/css/collection_page_style.css');
  drupal_add_js(drupal_get_path('module', 'collection_page') . '/js/collection_page_tabs.js');
  drupal_add_js(drupal_get_path('module', 'collection_page') . '/js/collection_page_thumbnails.js');
  drupal_add_js(libraries_get_path('jquery_cookie') . '/jquery.cookie.js');


//Set the number of tab which was selected by default and disabled.
  drupal_add_js(array('collection_page' => array('default_tab' => $default_tab)), 'setting');
  if (!empty($disabled_tabs_for_js)) {
    drupal_add_js(array('collection_page' => array('disabled_tabs' => $disabled_tabs_for_js)), 'setting');
  }

  return theme('collection_page', array(
    'content' => $content_tabs,
  ));
}
