<?php

class DeepzoomNodesMigration extends Migration {
  public function __construct() {
    parent::__construct();
    // The example uses a SQL database as source.
    $csv_file_path = drupal_get_path('module', 'migrate_deepzoom_files') . DIRECTORY_SEPARATOR . 'images_info.csv';
    $columns = array(
      array('filename', 'Image File Name '),
      array('deepzoom_hash', 'DeepZoom Hash value for image'),
      array('title', 'Title'),
      array('galleries', 'Gallery'),
    );
    $options = array('header_rows' => 1);
    $this->source = new MigrateSourceCSV($csv_file_path, $columns, $options);
    //Migrate into "files" nodes.
    $this->destination = new MigrateDestinationNode('files');

    // We instantiate the MigrateMap
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'deepzoom_hash' => array(
          'type' => 'varchar',
          'not null' => TRUE,
          'length' => 32,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Finally we add simple field mappings
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_files_description', 'description');
    $this->addFieldMapping('field_files_image', 'filename');
    $this->addFieldMapping('field_files_image:file_class')
      ->defaultValue('MigrateFileUri');
    $this->addFieldMapping('field_files_image:file_replace')
      ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);
    $this->addFieldMapping('field_files_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_files_galleries', 'galleries');
    $this->addFieldMapping('field_files_galleries:create_term')
      ->defaultValue(TRUE);
    $this->addUnmigratedSources(array('deepzoom_hash'));
  }

  public function prepareRow($row) {
    $title = $row->title;
    if (strlen($title) > 80) {
      $title = substr($title, 0, 80);
      $title .= '...';
      $row->description = $row->title;
    }
    $row->title = $title;
  }
}