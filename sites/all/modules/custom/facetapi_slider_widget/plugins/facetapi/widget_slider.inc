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
    $this->key = $facet['name'];
    $form_id = 'facetapi_slider_widget_' . $facet['name'] . '_form';

    //Get min and max values for given facet
    $left_limit = $this->facet['min callback']($facet);
    $right_limit = $this->facet['max callback']($facet);
    $info = array_shift($this->build[$this->facet['field alias']]);
    $search_path = $info['#path'];

    //Remove default query *:*.
    //@todo Remove this code block if we remove possibility for this query to be shown in browser
    $search_path_parts = explode('/', $search_path);
    $search_query_string = $search_path_parts[1];
    if (!empty($search_query_string)) {
      $current_search_queries = explode(' AND ', $search_query_string);
      foreach ($current_search_queries as $key => $query) {
        if ($query == '*:*') {
          unset($current_search_queries[$key]);
        }
      }
    }
    $search_query_string = implode(' AND ', $current_search_queries);
    if (!empty($search_query_string)) {
      $search_path = $search_path_parts[0] . '/' . $search_query_string;
    } else {
      $search_path = $search_path_parts[0];
    }

    $args = array(
        'search path' => $search_path,
        'field alias' => $this->facet['field alias'],
        'left limit' => $left_limit,
        'right limit' => $right_limit,
        'label' => $facet['label'],
        'facet name' => $facet['name'],
    );
    $element = &$this->build[$this->facet['field alias']];
    $element = array(
        'markup' => drupal_get_form($form_id, $args),
    );
  }

}
