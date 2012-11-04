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
