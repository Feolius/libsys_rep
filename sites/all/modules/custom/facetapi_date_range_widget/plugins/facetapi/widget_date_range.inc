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

    //Get min and max date. Transform it in 'Y/m/d' format for presentation in our widget
    $min_date_unix = $this->facet['min callback']($facet);
    $date_min_obj = new DateObject($min_date_unix, NULL, 'U');
    $min_date = $date_min_obj->format('Y/m/d');
    $max_date_unix = $this->facet['max callback']($facet);
    $date_max_obj = new DateObject($max_date_unix, NULL, 'U');
    $max_date = $date_max_obj->format('Y/m/d');
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
    if(!empty($search_query_string)){
      $search_path = $search_path_parts[0] . '/' . $search_query_string;
    }else{
      $search_path = $search_path_parts[0];
    }
    $args = array(
        'search path' => $search_path,
        'field alias' => $this->facet['field alias'],
        'min date' => $min_date,
        'max date' => $max_date,
        'facet name' => $facet['name'],
        'label' => $facet['label'],
    );
    $element = &$this->build[$this->facet['field alias']];
    $element = array(
        'markup' => drupal_get_form($form_id, $args),
    );
  }

}
