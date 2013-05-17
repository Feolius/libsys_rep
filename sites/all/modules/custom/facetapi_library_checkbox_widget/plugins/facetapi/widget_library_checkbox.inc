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
    if (!empty($this->build[$this->facet['field alias']])) {
      //Get search path.
      foreach ($this->build[$this->facet['field alias']] as $key => $val) {
        $search_path = $val['#path'];
        break;
      }
      $element = & $this->build[$this->facet['field alias']];
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
      $element = array(
        'markup' => drupal_get_form($form_id, $args),
      );
    }
  }

  public function getForm($forms, $built_form_id){
    $facet = $this->facet->getFacet();
    $form_id = 'facetapi_library_checkbox_widget_' . $facet['name'] . '_form';
    $form = array();
    if (!empty($this->build[$this->facet['field alias']])) {
      //Get search path.
      foreach ($this->build[$this->facet['field alias']] as $key => $val) {
        $search_path = $val['#path'];
        break;
      }
      $element = & $this->build[$this->facet['field alias']];
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
      $callback = $forms[$form_id]['callback'];
      $fake_form_state['build_info']['form_id'] = $form_id;
      $form = $callback(array(), $fake_form_state, $args);
    }
    return $form;
  }


}