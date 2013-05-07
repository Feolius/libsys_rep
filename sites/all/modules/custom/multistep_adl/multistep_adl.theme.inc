<?php

/**
 * Display a navigation block.
 * Use this theme function to override the output / display of this block.
 */
function theme_multistep_adl_navigation($variables = array()) {
  if (count($variables['links']['#children']) < 1) {
    return '';
  }
  $required_content = array();
  $optional_content = array();
  foreach ($variables['links']['#children'] as $key => $group) {
    extract($group);
    if (isset($url) || $next_unsubmitted_step) {
      $content = l($label, $url, array(
        'attributes' => array('id' => $id, 'class' => $class),
        'query' => array('step' => $step)
      ));
    }
    else {
      $content = '<span id="' . $id . '" class="' . implode(' ', $class) . '">' . $label . '</span>';
    }
    if ($required) {
      $required_content[$key] = $content;
    }
    else {
      $optional_content[$key] = $content;
    }
  }
  $required_header = '<span id="multistep-adl-required-steps-header">Required Steps</span><br>';
  $optional_header = '<span id="multistep-adl-optional-steps-header">Optional Steps</span><br>';
  $required_html = theme('item_list', array(
    'items' => $required_content,
    'type' => variable_get('multistep_adl_show_step_numbers') ? 'ol' : 'ul'
  ));
  $optional_html = theme('item_list', array(
    'items' => $optional_content,
    'type' => variable_get('multistep_adl_show_step_numbers') ? 'ol' : 'ul'
  ));

  $result = $required_header . $required_html;
  if (!empty($optional_content)) {
    $result .= '<br>' . $optional_header . $optional_html;
  }

  return $result;
}

/**
 * Block Theme function that displays the default output of a progress bar.
 * Use this theme function to override the output / display of this block.
 *
 * for small prograss values <50% the percentage is shown to the right of the bar
 */
function theme_multistep_adl_progress_bar($variables = array()) {
  list($left, $right) = array($variables['progress'] . '%', '');
  if ($variables['progress'] < 50) {
    list($left, $right) = array($right, $left);
  }
  $output = '<div class="multistep-adl-progress-bar-wrapper">';
  $output .= '<div class="multistep-adl-progress-bar multistep-adl-progress-bar-' . $variables['progress'] . '" style="width: ' . $variables['progress'] . '%">' . $left . '</div>';
  if ($right) {
    $output .= '<div class="multistep-adl-progress-bar-percentage-right">' . $right . '</div>';
  }
  $output .= '</div>';
  return $output;
}
