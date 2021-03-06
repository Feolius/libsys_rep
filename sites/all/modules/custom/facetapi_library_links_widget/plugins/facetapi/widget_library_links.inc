<?php

/**
 * Library links widget for filtering.
 */
class FacetapiWidgetLibraryLinks extends FacetapiWidgetLinks {

  public function execute() {
    $response = $this->makeStatisticQuery();

    $environment = apachesolr_default_environment();
    $indexed_bundles = apachesolr_get_index_bundles($environment, 'node');
    $entity_info = entity_get_info('node');
    $element = &$this->build[$this->facet['field alias']];
    //We should keep order of items
    $ordered_element = array();
    foreach ($indexed_bundles as $bundle) {
      if (!isset($element[$bundle])) {
        if (isset($response->facet_counts->facet_fields->bundle->{$bundle})) {
          $ordered_element[$bundle] = array(
              '#markup' => $entity_info['bundles'][$bundle]['label'],
              '#path' => arg(0) . '/' . arg(1),
              '#html' => FALSE,
              '#indexed_value' => $bundle,
              '#count' => $response->facet_counts->facet_fields->bundle->{$bundle},
              '#active' => 0,
              '#item_parents' => array(),
              '#item_children' => array(),
              '#query' => array('f' => array('bundle:' . $bundle)),
          );
        }
      }else{
        $ordered_element[$bundle] = $element[$bundle];
      }
    }
    // Sets each item's theme hook, builds item list.
    $this->setThemeHooks($ordered_element);

    $element = array(
        '#theme' => 'item_list',
        '#items' => $this->buildListItems($ordered_element),
        '#attributes' => $this->build['#attributes'],
    );
  }

  public function makeStatisticQuery() {
    $environment = apachesolr_default_environment();
    $solr = apachesolr_get_solr($environment);
    $params = array();
    $q = arg(1);
    if (is_null($q)) {
      $params['q'] = '*:*';
    } else {
      $params['q'] = $q;
    }
    $params['defType'] = 'lucene';
    $params['spellcheck'] = 'false';
    $params['fq'] = array('entity_type:node');
    $params['facet.field'] = array('bundle');
    $params['facet'] = 'true';
    $params['start'] = 0;
    $params['rows'] = 1;
    $query = apachesolr_drupal_query('apachesolr', $params, '', '', $solr);
    $keys = $query->getParam('q');
    $response = $query->search($keys);
    return $response;
  }

  public function setThemeHooks(array &$build) {
    foreach ($build as $value => &$item) {
      $item['#theme'] = ($item['#active']) ? 'facetapi_library_link_active' : 'facetapi_link_inactive';
    }
    return $this;
  }

}
