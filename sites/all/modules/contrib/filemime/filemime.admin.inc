<?php
// $Id: filemime.admin.inc,v 1.1.4.4 2010/08/25 20:46:54 mfb Exp $

/**
 * Form builder function for admin settings.
 */
function filemime_settings() {
  $form['filemime_file'] = array(
    '#type' => 'textfield',
    '#title' => t('Local mime.types file path'),
    '#default_value' => variable_get('filemime_file', ''),
    '#description' => t('If a mime.types file is readable, it will be parsed to extract MIME extension mappings. Example: <em>/etc/mime.types</em>') . '<br />' . (is_readable(variable_get('filemime_file', '')) ? t('The configured mime.types file is readable.') : t('The configured mime.types file is not readable.')),
  );
  $form['filemime_types'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom MIME extension mappings'),
    '#default_value' => variable_get('filemime_types', ''),
    '#description' => t('Types provided here will override the mime.types file. Specify the mappings using the mime.types file format. Example:<br /><em>audio/mpeg mpga mpega mp2 mp3 m4a<br />audio/mpegurl m3u<br />audio/ogg oga ogg spx</em>'),
  );
  return system_settings_form($form);
}
