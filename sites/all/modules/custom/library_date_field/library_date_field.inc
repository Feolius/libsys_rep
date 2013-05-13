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
    $values = explode('/', trim($item, ' '));
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
      $values[2] = $values[1];
      $values[1] = $day;
      $item = implode('/', $values);
    }
    elseif ($rounding == LIBRARY_DATA_FIELD_NO_ROUNDING) {
      $day = $values[0];
      $values[0] = $values[1];
      $values[1] = $day;
      $item = implode('/', $values);
    }

    // Creating date.
    $timestamp = strtotime($item);
    $date = date("Y-m-d H:i:s", $timestamp);
    $output = array(
      'date' => $date,
      'rounding' => $rounding,
    );
    return $output;
  }
}

/**
 * Function for get date.
 */
function library_date_field_get_date($item, $processed) {
  if (empty($item)) {
    return;
  }
  else {
    $rounding = ($processed == 'value') ? 'rounding' : 'rounding2' ;
    $datetime = DateTime::createFromFormat('Y-m-d H:i:s', $item[$processed]);
    if ($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_MONTH) {
      $output = $datetime->format('F Y');
    }
    elseif ($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_YEARS) {
      $output = $datetime->format('Y');
    }
    elseif($item[$rounding] == LIBRARY_DATA_FIELD_NO_ROUNDING) {
      $output = $datetime->format('d F Y');
    }
    return $output;
  }
}

/**
 * Function for load date.
 */
function library_date_field_load_date($item, $processed) {
  if (empty($item)) {
    return;
    }
  else {
    $date = DateTime::createFromFormat('Y-m-d H:i:s', $item[$processed]);
    return $date->format('Y-m-d H:i:s');
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
    $rounding = ($processed == 'value') ? 'rounding' : 'rounding2';
    $datetime = DateTime::createFromFormat('Y-m-d H:i:s', $item[$processed]);
    if ($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_MONTH) {
      $output = $datetime->format('m/Y');
    }
    elseif($item[$rounding] == LIBRARY_DATA_FIELD_ROUNDING_FOR_YEARS) {
      $output = $datetime->format('Y');
    }
    else {
      $output = $datetime->format('d/m/Y');
    }
    return $output;
  }
}

/**
 * Helper function to create an array of the approximate date values in a
 * field that need to be processed.
 */
function library_date_field_process_values($field) {
  return array('value', 'value2');
}

/**
 * Helper function for process states.
 */
function _library_date_field_process_states($field_name, $langcode, $delta, $item_name) {
  return ':input[name="' . $field_name . '[' . $langcode . '][' . $delta . '][' . $item_name . ']"], ';
}

/**
 * Helper function for validate.
 */
function _library_date_return_timestamp($item, $processed) {
  if (!empty($item) && !empty($processed)) {
    $output = '';
    $items = explode('/', $item[$processed]);
    switch (sizeof($items)) {
      case LIBRARY_DATA_FIELD_NO_ROUNDING:
        $output = strtotime("$items[1]/$items[0]/$items[2]");
        break;
      case LIBRARY_DATA_FIELD_ROUNDING_FOR_MONTH:
        $day = ($processed == 'value') ? '01' : (string) cal_days_in_month(CAL_GREGORIAN, $items[0], $items[1]);
        $output = strtotime("$items[0]/$day/$items[1]");
        break;
      case LIBRARY_DATA_FIELD_ROUNDING_FOR_YEARS:
        $day = ($processed == 'value') ? '01' : '31';
        $mounth = ($processed == 'value') ? '01' : '12';
        $output = strtotime("$mounth/$day/$item[$processed]");
        break;
    }
    return $output;
  }
}
