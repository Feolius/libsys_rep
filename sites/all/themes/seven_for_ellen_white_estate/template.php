<?php

/**
 * Override or insert variables into the maintenance page template.
 */
function seven_for_ellen_white_estate_preprocess_maintenance_page(&$vars) {
  // While markup for normal pages is split into page.php and html.tpl.php,
  // the markup for the maintenance page is all in the single
  // maintenance-page.php template. So, to have what's done in
  // seven_preprocess_html() also happen on the maintenance page, it has to be
  // called here.
  seven_for_ellen_white_estate_preprocess_html($vars);
}

/**
 * Override or insert variables into the html template.
 */
function seven_for_ellen_white_estate_preprocess_html(&$vars) {
  // Add conditional CSS for IE8 and below.
  drupal_add_css(path_to_theme() . '/ie.css', array(
    'group' => CSS_THEME,
    'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE),
    'weight' => 999,
    'preprocess' => FALSE
  ));
  // Add conditional CSS for IE7 and below.
  drupal_add_css(path_to_theme() . '/ie7.css', array(
    'group' => CSS_THEME,
    'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE),
    'weight' => 999,
    'preprocess' => FALSE
  ));
  // Add conditional CSS for IE6.
  drupal_add_css(path_to_theme() . '/ie6.css', array(
    'group' => CSS_THEME,
    'browsers' => array('IE' => 'lte IE 6', '!IE' => FALSE),
    'weight' => 999,
    'preprocess' => FALSE
  ));
}

/**
 * Override or insert variables into the page template.
 */
function seven_for_ellen_white_estate_preprocess_page(&$vars) {
  $vars['primary_local_tasks'] = $vars['tabs'];
  unset($vars['primary_local_tasks']['#secondary']);
  $vars['secondary_local_tasks'] = array(
    '#theme' => 'menu_local_tasks',
    '#secondary' => $vars['tabs']['#secondary'],
  );
}

/**
 * Display the list of available node types for node creation.
 */
function seven_for_ellen_white_estate_node_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<ul class="admin-list">';
    foreach ($content as $item) {
      $output .= '<li class="clearfix">';
      $output .= '<span class="label">' . l($item['title'], $item['href'], $item['localized_options']) . '</span>';
      $output .= '<div class="description">' . filter_xss_admin($item['description']) . '</div>';
      $output .= '</li>';
    }
    $output .= '</ul>';
  }
  else {
    $output = '<p>' . t('You have not created any content types yet. Go to the <a href="@create-content">content type creation page</a> to add a new content type.', array('@create-content' => url('admin/structure/types/add'))) . '</p>';
  }
  return $output;
}

/**
 * Overrides theme_admin_block_content().
 *
 * Use unordered list markup in both compact and extended mode.
 */
function seven_for_ellen_white_estate_admin_block_content($variables) {
  $content = $variables['content'];
  $output = '';
  if (!empty($content)) {
    $output = system_admin_compact_mode() ? '<ul class="admin-list compact">' : '<ul class="admin-list">';
    foreach ($content as $item) {
      $output .= '<li class="leaf">';
      $output .= l($item['title'], $item['href'], $item['localized_options']);
      if (isset($item['description']) && !system_admin_compact_mode()) {
        $output .= '<div class="description">' . filter_xss_admin($item['description']) . '</div>';
      }
      $output .= '</li>';
    }
    $output .= '</ul>';
  }
  return $output;
}

/**
 * Override of theme_tablesort_indicator().
 *
 * Use our own image versions, so they show up as black and not gray on gray.
 */
function seven_for_ellen_white_estate_tablesort_indicator($variables) {
  $style = $variables['style'];
  $theme_path = drupal_get_path('theme', 'seven_for_ellen_white_estate');
  if ($style == 'asc') {
    return theme('image', array(
      'path' => $theme_path . '/images/arrow-asc.png',
      'alt' => t('sort ascending'),
      'width' => 13,
      'height' => 13,
      'title' => t('sort ascending')
    ));
  }
  else {
    return theme('image', array(
      'path' => $theme_path . '/images/arrow-desc.png',
      'alt' => t('sort descending'),
      'width' => 13,
      'height' => 13,
      'title' => t('sort descending')
    ));
  }
}

/**
 * Implements hook_css_alter().
 */
function seven_for_ellen_white_estate_css_alter(&$css) {
  // Use Seven's vertical tabs style instead of the default one.
  if (isset($css['misc/vertical-tabs.css'])) {
    $css['misc/vertical-tabs.css']['data'] = drupal_get_path('theme', 'seven_for_ellen_white_estate') . '/vertical-tabs.css';
    $css['misc/vertical-tabs.css']['type'] = 'file';
  }
  if (isset($css['misc/vertical-tabs-rtl.css'])) {
    $css['misc/vertical-tabs-rtl.css']['data'] = drupal_get_path('theme', 'seven_for_ellen_white_estate') . '/vertical-tabs-rtl.css';
    $css['misc/vertical-tabs-rtl.css']['type'] = 'file';
  }
  // Use Seven's jQuery UI theme style instead of the default one.
  if (isset($css['misc/ui/jquery.ui.theme.css'])) {
    $css['misc/ui/jquery.ui.theme.css']['data'] = drupal_get_path('theme', 'seven_for_ellen_white_estate') . '/jquery.ui.theme.css';
    $css['misc/ui/jquery.ui.theme.css']['type'] = 'file';
  }
}

/**
 * Overriden for the multistep node page
 */
function seven_for_ellen_white_estate_form_element($variables) {
  $element = & $variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
        ' ' => '-',
        '_' => '-',
        '[' => '-',
        ']' => ''
      ));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }

  //--------------------Overrided Code----------------------------
  if (arg(0) == 'node' && (arg(2) == 'edit' || arg(1) == 'add') && $element['#type'] != 'checkbox'
    && !in_array('form-item-field-files-text-und-0-format', $attributes['class'])
    && !in_array('form-item-field-files-description-und-0-format', $attributes['class'])
  ) {
    $attributes['class'][] = 'area';
  }
  //--------------------------------------------------------------

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Overriden for the multistep node page
 */
function seven_for_ellen_white_estate_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'][] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'][] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  //--------------------Overrided Code----------------------------
  if (arg(0) == 'node' && (arg(2) == 'edit' || arg(1) == 'add') && $element['#title_display'] != 'after' && $attributes['for'] != 'edit-field-files-text-und-0-format--2') {
    $attributes['class'][] = 'area_header';
  }
  //--------------------------------------------------------------

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array(
    '!title' => $title,
    '!required' => $required
  )) . "</label>\n";
}

/**
 * Overriden for the multistep node page
 */
function seven_for_ellen_white_estate_table($variables) {
  $header = $variables['header'];
  $rows = $variables['rows'];
  $attributes = $variables['attributes'];
  $caption = $variables['caption'];
  $colgroups = $variables['colgroups'];
  $sticky = $variables['sticky'];
  $empty = $variables['empty'];

  // Add sticky headers, if applicable.
  if (count($header) && $sticky) {
    drupal_add_js('misc/tableheader.js');
    // Add 'sticky-enabled' class to the table to identify it for JS.
    // This is needed to target tables constructed by this function.
    $attributes['class'][] = 'sticky-enabled';
  }

  //--------------------Overrided Code----------------------------
  if (arg(0) == 'node' && (arg(2) == 'edit' || arg(1) == 'add')) {
    $attributes['class'][] = 'area';
  }
  //--------------------------------------------------------------

  $output = '<table' . drupal_attributes($attributes) . ">\n";

  if (isset($caption)) {
    $output .= '<caption>' . $caption . "</caption>\n";
  }

  // Format the table columns:
  if (count($colgroups)) {
    foreach ($colgroups as $number => $colgroup) {
      $attributes = array();

      // Check if we're dealing with a simple or complex column
      if (isset($colgroup['data'])) {
        foreach ($colgroup as $key => $value) {
          if ($key == 'data') {
            $cols = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $cols = $colgroup;
      }

      // Build colgroup
      if (is_array($cols) && count($cols)) {
        $output .= ' <colgroup' . drupal_attributes($attributes) . '>';
        $i = 0;
        foreach ($cols as $col) {
          $output .= ' <col' . drupal_attributes($col) . ' />';
        }
        $output .= " </colgroup>\n";
      }
      else {
        $output .= ' <colgroup' . drupal_attributes($attributes) . " />\n";
      }
    }
  }

  // Add the 'empty' row message if available.
  if (!count($rows) && $empty) {
    $header_count = 0;
    foreach ($header as $header_cell) {
      if (is_array($header_cell)) {
        $header_count += isset($header_cell['colspan']) ? $header_cell['colspan'] : 1;
      }
      else {
        $header_count++;
      }
    }
    $rows[] = array(array('data' => $empty, 'colspan' => $header_count, 'class' => array('empty', 'message')));
  }

  // Format the table header:
  if (count($header)) {
    $ts = tablesort_init($header);
    // HTML requires that the thead tag has tr tags in it followed by tbody
    // tags. Using ternary operator to check and see if we have any rows.
    $output .= (count($rows) ? ' <thead><tr>' : ' <tr>');
    foreach ($header as $cell) {
      $cell = tablesort_header($cell, $header, $ts);
      $output .= seven_for_ellen_white_estate_table_cell($cell, TRUE);
    }
    // Using ternary operator to close the tags based on whether or not there are rows
    $output .= (count($rows) ? " </tr></thead>\n" : "</tr>\n");
  }
  else {
    $ts = array();
  }

  // Format the table rows:
  if (count($rows)) {
    $output .= "<tbody>\n";
    $flip = array('even' => 'odd', 'odd' => 'even');
    $class = 'even';
    foreach ($rows as $number => $row) {
      $attributes = array();

      // Check if we're dealing with a simple or complex row
      if (isset($row['data'])) {
        foreach ($row as $key => $value) {
          if ($key == 'data') {
            $cells = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $cells = $row;
      }
      if (count($cells)) {
        // Add odd/even class
        if (empty($row['no_striping'])) {
          $class = $flip[$class];
          $attributes['class'][] = $class;
        }

        // Build row
        $output .= ' <tr' . drupal_attributes($attributes) . '>';
        $i = 0;
        foreach ($cells as $cell) {
          $cell = tablesort_cell($cell, $header, $ts, $i++);
          $output .= seven_for_ellen_white_estate_table_cell($cell);
        }
        $output .= " </tr>\n";
      }
    }
    $output .= "</tbody>\n";
  }

  $output .= "</table>\n";
  return $output;

}

/**
 * Overriden for the multistep node page
 *
 * @param $cell
 * @param bool $header
 * @return string
 */
function seven_for_ellen_white_estate_table_cell($cell, $header = FALSE) {
  $attributes = '';

  if (is_array($cell)) {
    $data = isset($cell['data']) ? $cell['data'] : '';
    // Cell's data property can be a string or a renderable array.
    if (is_array($data)) {
      $data = drupal_render($data);
    }
    $header |= isset($cell['header']);
    unset($cell['data']);
    unset($cell['header']);
    $attributes = drupal_attributes($cell);
  }
  else {
    $data = $cell;
  }

  if ($header) {
    $output = "<th$attributes>$data</th>";
  }
  else {
    $output = "<td$attributes>$data</td>";
  }

  return $output;
}


//function seven_for_ellen_white_estate_fieldset($variables) {
//  $element = $variables['element'];
//  element_set_attributes($element, array('id'));
//  seven_for_ellen_white_estate_form_set_class($element, array('form-wrapper'));
//  $attributes = $element['#attributes'];
//
//  //--------------------Overrided Code----------------------------
//
//  if (arg(0) == 'node' && (arg(2) == 'edit' || arg(1) == 'add')
//    && !in_array('field-group-fieldset', $attributes['class'])
//    ) {
//    $attributes['class'][] = 'area';
//  }
//  //--------------------------------------------------------------
//
//
//  $output = '<fieldset' . drupal_attributes($attributes) . '>';
//  if (!empty($element['#title'])) {
//    // Always wrap fieldset legends in a SPAN for CSS positioning.
//    $output .= '<legend><span class="fieldset-legend">' . $element['#title'] . '</span></legend>';
//  }
//  $output .= '<div class="fieldset-wrapper">';
//  if (!empty($element['#description'])) {
//    $output .= '<div class="fieldset-description">' . $element['#description'] . '</div>';
//  }
//  $output .= $element['#children'];
//  if (isset($element['#value'])) {
//    $output .= $element['#value'];
//  }
//  $output .= '</div>';
//  $output .= "</fieldset>\n";
//  return $output;
//}
//
//function seven_for_ellen_white_estate_form_set_class(&$element, $class = array()) {
//  if (!empty($class)) {
//    if (!isset($element['#attributes']['class'])) {
//      $element['#attributes']['class'] = array();
//    }
//    $element['#attributes']['class'] = array_merge($element['#attributes']['class'], $class);
//  }
//  // This function is invoked from form element theme functions, but the
//  // rendered form element may not necessarily have been processed by
//  // form_builder().
//  if (!empty($element['#required'])) {
//    $element['#attributes']['class'][] = 'required';
//  }
//  if (isset($element['#parents']) && form_get_error($element) !== NULL && !empty($element['#validated'])) {
//    $element['#attributes']['class'][] = 'error';
//  }
//}




