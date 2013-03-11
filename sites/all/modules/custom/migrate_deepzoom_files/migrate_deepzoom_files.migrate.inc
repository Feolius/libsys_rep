<?php

function migrate_deepzoom_files_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'DeepzoomNodes' => array('class_name' => 'DeepzoomNodesMigration'),
    ),
  );
  return $api;
}


