<?php

/**
 * Widget for filtering by terms.
 */
class FacetapiWidgetLibraryTerm extends FacetapiWidget {

  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    $this->key = $facet['name'];
  }

  public function execute() {
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_library_term_widget_' . $facet['name'] . '_form';
    $element = &$this->build[$this->facet['field alias']];
    if (!empty($element)) {
      //Get search path.
      foreach ($element as $key => $val) {
        $search_path = $val['#path'];
        break;
      }
      $args = $this->getArgs($element, $facet, $search_path);
      $element = array(
        'markup' => drupal_get_form($form_id, $args),
      );
    }
  }

  /**
   * Get arguments needed for building widget form
   */
  protected function getArgs($element, $facet, $search_path){
    $options = array();
    foreach($element as $key => $item){
      $options[$key] = t($item['#markup']);
    }
    $args = array(
      'search path' => $search_path,
      'field alias' => $this->facet['field alias'],
      'facet name' => $facet['name'],
      'label' => $facet['label'],
      'options' => $options
    );
    return $args;
  }

  /**
   * This method allow to use this widget in facet_collection_block module
   */
  public function getForm($forms, $path){
    $facet = $this->facet->getFacet();
    $build = $this->getBuild();
    $adapter = $build['#adapter'];
    $adapter->processFacets();
    $processor = $adapter->getProcessor($facet['name']);
    $realm_name = $build['#realm_name'];
    $realm = facetapi_realm_load($realm_name);
    $this->facet->build($realm, $processor);
    $facet_build = $this->facet->getBuild();
    $form_id = 'facetapi_library_term_widget_' . $facet['name'] . '_form';
    $args = $this->getArgs($facet_build ? $facet_build : array(), $facet, $path);
    $callback = $forms[$form_id]['callback'];
    $fake_form_state['build_info']['form_id'] = $form_id;
    $form = $callback(array(), $fake_form_state, $args);
    return $form;
  }
}