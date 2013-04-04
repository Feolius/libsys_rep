<?php

/**
 * Checkbox widget for filtering.
 */
class FacetapiWidgetLibraryCheckbox extends FacetapiWidget {

  /**
   * Overrides FacetapiWidget::__construct().
   *
   * For links, it is better to use the machine name of the facet as opposed to
   * the alias for the key. Alias are usually, but not necessarily, unique. It
   * doesn't make sense to group links in the same element as they are usually
   * rendered in blocks with are separate from one another.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    $this->key = $facet['name'];
  }

  /**
   * Renders the form.
   */
  public function execute() {
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_library_checkbox_widget_' . $facet['name'] . '_form';
    if(!empty($this->build[$this->facet['field alias']])){
      foreach($this->build[$this->facet['field alias']] as $key => $val){
        $search_path = $val['#path'];
        break;
      }
    $element = &$this->build[$this->facet['field alias']];
    $variants = array_keys($element);
    $args = array(
      'search path' => $search_path,
      'field alias' => $this->facet['field alias'],
      'facet name' => $facet['name'],
      'label' => $facet['label'],
      'variants' => $variants
    );
    $element = array(
      'markup' => drupal_get_form($form_id, $args),
    );
    }
  }


}