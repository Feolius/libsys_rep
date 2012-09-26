<?php

/**
 * @file
 * The facetapi_oneblock_widget widget plugin class.
 */

class FacetapiWidgetOneblock extends FacetapiWidget {
    public function execute() {        
        $form_id = 'facet_api_date_range_widget_filter_form';  
        $minimum = $this->facet['min callback']($this->facet->getFacet());
        $minimum = facetapi_isodate($minimum);
        $maximum = $this->facet['max callback']($this->facet->getFacet());
        $maximum = facetapi_isodate($maximum);
        $minimum = explode('-', $minimum);
        $maximum = explode('-', $maximum);
        $min_year = $minimum[0] + 1;
        $max_year = $maximum[0] + 1;        
        $info = array_shift($this->build[$this->facet['field alias']]);        
        $search_path = $info['#path']; 
        $args = array(
            'search path' => $search_path,
            'field alias' => $this->facet['field alias'],
            'min year' => $min_year,
            'max year' => $max_year,
        );        
        $element = &$this->build[$this->facet['field alias']];
        $element = array(            
            'markup' => drupal_get_form($form_id, $args),                    
        );      
        
    }
}
