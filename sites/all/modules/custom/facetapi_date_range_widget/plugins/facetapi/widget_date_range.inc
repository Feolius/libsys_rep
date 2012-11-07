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
        $args = array(
            'search path' => $search_path,
            'field alias' => $this->facet['field alias'],
            'min date' => $min_date,
            'max date' => $max_date,
            'facet name' => $facet['name']
        );
        $element = &$this->build[$this->facet['field alias']];
        $element = array(
            'markup' => drupal_get_form($form_id, $args),
        );
    }

}
