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
      $args = $this->getArgs($element, $facet);
      $element = array(
        'markup' => drupal_get_form($form_id, $args),
      );
    }
  }

  /**
   * Get arguments needed for building widget form
   */
  protected function getArgs($element, $facet){
    //Get search path.
    foreach ($element as $key => $val) {
      $search_path = $val['#path'];
      break;
    }
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
  public function getForm($forms){
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_library_term_widget_' . $facet['name'] . '_form';
    $form = array();
    $element = $this->build[$this->facet['field alias']];
    if (!empty($element)) {
      $args = $this->getArgs($element, $facet);
      $callback = $forms[$form_id]['callback'];
      $fake_form_state['build_info']['form_id'] = $form_id;
      $form = $callback(array(), $fake_form_state, $args);
    }
    return $form;
  }

}