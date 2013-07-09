<?php

/**
 * Field handler that returns the completion status of a multistep_adl node.
 */
class multistep_adl_views_handler_field_status extends views_handler_field {
  function query() {
    $this->ensure_my_table();
    $this->query->add_field('node', 'type');
    $this->query->add_field('multistep_adl', 'status');
    $this->query->add_groupby('nid');
  }

  function render($values) {
    if (!empty($values->multistep_adl_status)) {
      return t('Incomplete');
    }
    if (variable_get('multistep_adl_expose_' . $values->node_type, 'disabled') == 'enabled') {
      return t('Complete');
    }
    return '';
  }
}
