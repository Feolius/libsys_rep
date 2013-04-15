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
    if (!empty($this->build[$this->facet['field alias']])) {
      //Get search path.
      foreach ($this->build[$this->facet['field alias']] as $key => $val) {
        $search_path = $val['#path'];
        break;
      }
      $element = & $this->build[$this->facet['field alias']];
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
      $element = array(
        'markup' => drupal_get_form($form_id, $args),
      );
    }
  }

}