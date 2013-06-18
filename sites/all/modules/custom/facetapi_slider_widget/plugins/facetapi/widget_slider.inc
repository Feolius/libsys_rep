<?php

/**
 * @file
 *
 */

/**
 * Date range widget for filtering.
 */
class FacetapiWidgetSlider extends FacetapiWidget {

  /**
   * Renders the form.
   */
  public function execute() {
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_slider_widget_' . $facet['name'] . '_form';

    $element = &$this->build[$this->facet['field alias']];
    $args = $this->getArgs($element, $facet);

    $element = array(
        'markup' => drupal_get_form($form_id, $args),
    );
  }

  /**
   * Get arguments needed for building widget form
   */
  protected function getArgs($element, $facet){
    //Get search path.
    foreach ($element as $val) {
      $search_path = $val['#path'];
      break;
    }
    //Get min and max values for given facet
    $left_limit = $this->facet['min callback']($facet);
    $right_limit = $this->facet['max callback']($facet);
    $args = array(
      'search path' => $search_path,
      'field alias' => $this->facet['field alias'],
      'left limit' => $left_limit,
      'right limit' => $right_limit,
      'label' => $facet['label'],
      'facet name' => $facet['name'],
    );
    return $args;
  }

  /**
   * This method allow to use this widget in facet_collection_block module
   */
  public function getForm($forms){
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_slider_widget_' . $facet['name'] . '_form';
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
