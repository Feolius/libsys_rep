<?php

/**
 * Display a navigation block.
 * Use this theme function to override the output / display of this block.
 */
function theme_multistep_adl_navigation($variables) {
  if (count($variables['links']['#children']) < 1) {
    return '';
  }
  $required_content = array();
  $optional_content = array();
  $attributes = array();
  foreach ($variables['links']['#children'] as $key => $group) {
    extract($group);
    if (isset($url)) {
      $query = array('step' => $step);
      $destination = drupal_get_destination();
      $query += $destination;
      $content = l($label, $url, array(
        'attributes' => array('id' => $id, 'class' => $class),
        'query' => $query,
        'html' => TRUE,
      ));
    }
    else {
      $content = '<span id="' . $id . '" class="' . implode(' ', $class) . '">' . $label . '</span>';
    }

    if ($active) {
      $attributes['class'] = 'active';
    }
    else {
      $attributes = array();
    }
    if ($required) {
      if (empty($required_content)) {
        $required_content[] = '<li ' . drupal_attributes($attributes) . '><span class="number">1.</span>' . $content . '</li>';
      }
      else {
        $required_content[] = '<li ' . drupal_attributes($attributes) . '><span class="number">2.</span>' . $content . '</li>';
      }
    }
    else {
      $optional_content[] = '<li ' . drupal_attributes($attributes) . '>' . $content . '</li>';
    }
  }

  if (count($required_content) == 1) {
    $required_content[] = '<li ><span><span class="number">2.</span>Please complete Step1</span></li>';
  }


  $required_html = '<ul class="steps">' . implode('', $required_content) . '</ul>';
  $optional_html = '<ul class="file_types">' . implode('', $optional_content) . '</ul>';

  $required_header = '<span class="area_header">Required Steps</span><br>';
  $optional_header = '<span class="area_header">Optional Steps</span><br>';

  $result = '<div class="area_left">' . $required_header . $required_html . '</div>';
  $result .= '<div class="area_right">' . $optional_header . $optional_html . '</div>';

  return '<div class="area clearfix">' . $result . '</div>';
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
