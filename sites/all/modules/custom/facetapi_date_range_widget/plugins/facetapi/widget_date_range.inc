<?php

/**
 * @file
 *
 */

/**
 * Date range widget for filtering.
 */
class FacetapiWidgetDateRange extends FacetapiWidget {

  /**
   * Renders the form.
   */
  public function execute() {
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_date_range_widget_' . $facet['name'] . '_form';

    $element = & $this->build[$this->facet['field alias']];
    if(!empty($element)){
      foreach($element as $val){
        if(isset($val['#path'])){
          $args = $this->getArgs($facet, $val['#path']);
          $element = array(
            'markup' => drupal_get_form($form_id, $args),
          );
          break;
        }
      }
    }
  }

  /**
   * Get arguments needed for building widget form
   */
  protected function getArgs($facet, $search_path) {
    //Get min and max date. Transform it in 'Y/m/d' format for presentation in our widget
    $min_date_unix = $this->facet['min callback']($facet);
    $date_min_obj = new DateObject($min_date_unix, NULL, 'U');
    $min_date = $date_min_obj->format('Y/m/d');
    $max_date_unix = $this->facet['max callback']($facet);
    $date_max_obj = new DateObject($max_date_unix, NULL, 'U');
    $max_date = $date_max_obj->format('Y/m/d');
    $args = array(
      'search path' => $search_path,
      'field alias' => $this->facet['field alias'],
      'min date' => $min_date,
      'max date' => $max_date,
      'facet name' => $facet['name'],
      'label' => $facet['label'],
    );
    return $args;
  }

  /**
   * This method allow to use this widget in facet_collection_block module
   */
  public function getForm($forms, $path) {
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_date_range_widget_' . $facet['name'] . '_form';
    $args = $this->getArgs($facet, $path);
    $callback = $forms[$form_id]['callback'];
    $fake_form_state['build_info']['form_id'] = $form_id;
    $form = $callback(array(), $fake_form_state, $args);
    return $form;
  }

}

