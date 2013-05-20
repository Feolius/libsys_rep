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
    $element = &$this->build[$this->facet['field alias']];
    if (!empty($element)) {
      $args = $this->getArgs($element, $facet);
      $element = array(
        'markup' => drupal_get_form($form_id, $args),
      );
    }
  }

  /**
   * Get arguments needed for building widget form
   */
  protected function getArgs($element, $facet){
    //Get search path.
    foreach ($element as $key => $val) {
      $search_path = $val['#path'];
      break;
    }
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
          if (isset($element[$allowed_value])) {
            $variants[$allowed_value] = $label;
          }
        }
        break;
      default:
        $variants = array_keys($element);
        $variants = drupal_map_assoc($variants);
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
  public function getForm($forms){
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_library_checkbox_widget_' . $facet['name'] . '_form';
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