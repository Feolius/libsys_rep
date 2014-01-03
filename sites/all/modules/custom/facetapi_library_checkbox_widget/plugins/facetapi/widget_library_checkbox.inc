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
    $element = & $this->build[$this->facet['field alias']];
    if (!empty($element)) {
      foreach ($element as $val) {
        if (isset($val['#path'])) {
          $args = $this->getArgs($element, $facet, $val['#path']);
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
  protected function getArgs($element, $facet, $search_path) {
    $field_name = $facet['field api name'];
    $field_info = field_info_field($field_name);
    $variants = array();
    switch ($field_info['type']) {
      case 'list_integer':
      case 'list_float':
      case 'list_text':
      case 'list_boolean':
        //Save order of checkboxes from field settings
        foreach ($field_info['settings']['allowed_values'] as $allowed_value => $label) {
          $variants[$allowed_value] = $label;
        }
        break;
      case 'taxonomy_term_reference':
        foreach($element as $tid => $existed_term_info){
          $variants[$tid] = $existed_term_info['#markup'];
        }
    }
    $args = array(
      'search path' => $search_path,
      'field alias' => $this->facet['field alias'],
      'facet name' => $facet['name'],
      'label' => $facet['label'],
      'variants' => $variants
    );
    return $args;

  }

  /**
   * This method allow to use this widget in facet_collection_block module
   */
  public function getForm($forms, $path) {
    $facet = $this->facet->getFacet();
    $build = $this->getBuild();
    $adapter = $build['#adapter'];
    $adapter->processFacets();
    $processor = $adapter->getProcessor($facet['name']);
    $realm_name = $build['#realm_name'];
    $realm = facetapi_realm_load($realm_name);
    $this->facet->build($realm, $processor);
    $facet_build = $this->facet->getBuild();
    $form_id = 'facetapi_library_checkbox_widget_' . $facet['name'] . '_form';
    $args = $this->getArgs($facet_build ? $facet_build : array(), $facet, $path);
    $callback = $forms[$form_id]['callback'];
    $fake_form_state['build_info']['form_id'] = $form_id;
    $form = $callback(array(), $fake_form_state, $args);
    return $form;
  }


}