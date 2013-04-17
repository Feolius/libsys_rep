<?php

define('LIBRARY_DATA_FIELD_ROUNDING_FOR_YEARS', 1);
define('LIBRARY_DATA_FIELD_ROUNDING_FOR_MONTH', 2);
define('LIBRARY_DATA_FIELD_NO_ROUNDING', 3);

/**
 * Function for set date.
 */
function library_date_field_set_date($item, $processed) {
  if (empty($item)) {
    return;
  }
  else {
    $values = explode('/', $item);
    $rounding = sizeof($values);

    if ($processed == 'value') {
      $day = '01';
      $month = '01';
    } else {
      $day = '31';
      $month = '12';
    }

    if ($rounding == LIBRARY_DATA_FIELD_ROUNDING_FOR_YEARS) {
      array_unshift($values, $month, $day);
      $item = implode('/', $values);
    }
    elseif ($rounding == LIBRARY_DATA_FIELD_ROUNDING_FOR_MONTH) {
      if ($processed == 'value2') {
        $day = (string) cal_days_in_month(CAL_GREGORIAN, $values[0], $values[1]);
      }
      array_unshift($values, $day);
      $item = implode('/', $values);
    }
    elseif ($rounding == LIBRARY_DATA_FIELD_NO_ROUNDING) {
      $item = implode('/', $values);
    }

    // Creating date.
    $timestamp = strtotime($item);
    $output = array(
      'date' => $timestamp,
      'rounding' => $rounding,
    );
    return $output;
  }
}

/**
 * Function for set date.
 */
function library_date_field_get_date($item, $processed) {
  if (empty($item)) {
    return;
  }
  else {
    $rounding = ($processed == 'value') ? 'rounding' : 'rounding2' ;
    if ($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_MONTH) {
      $output = date("F Y", $item[$processed]);
    }
    elseif ($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_YEARS) {
      $output = date("Y", $item[$processed]);
    }
    else {
      $output = date("d F Y", $item[$processed]);
    }
    return $output;
  }
}

/**
 * Function for return approximate date.
 */
function library_date_field_return_date($item, $processed) {
  if (empty($item)) {
    return;
  }
  else {
    $rounding = ($processed == 'value') ? 'rounding' : 'rounding2' ;
    $month = ($processed == 'value') ? '01' : '12';
    if ($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_MONTH) {
      $output = date("m/Y", strtotime($item[$processed]));
    }
    elseif($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_YEARS) {
      $output = $item[$processed];
    }
    else {
      $output = date("d/m/Y", strtotime($item[$processed]));
    }
    return $output;
  }
}

/**
 * Helper function to create an array of the approximate date values in a
 * field that need to be processed.
 */
function library_date_field_process_values($field) {
  return $field['settings']['type'] == 'period' ? array('value', 'value2') : array('value');
}

/**
 * Helper function for process states.
 */
function _library_date_field_process_states($field_name, $langcode, $delta, $item_name) {
  return ':input[name="' . $field_name . '[' . $langcode . '][' . $delta . '][' . $item_name . ']"], ';
}
