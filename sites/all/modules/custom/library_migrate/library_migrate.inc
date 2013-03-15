<?php

abstract class LibraryMigration extends DynamicMigration {

  public function __construct() {
    parent::__construct();
    require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'library_migrate') . '/library_migrate_field_names.inc';
    //For development on local machine
    $other_database = array(
        'database' => 'adventists',
        'username' => 'admin',
        'password' => '1234',
        'host' => 'localhost',
        'driver' => 'mysql',
    );
    //For import on production server
    /* $other_database = array(
      'database' => 'archive_library',
      'username' => 'archive_library',
      'password' => 'jkqeq23ffa3rh',
      'host' => 'sql-3',
      'driver' => 'mysql',
      ); */

    Database::addConnectionInfo('ImportDatabaseKey', 'default', $other_database);
  }

}

class FileCollectionMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Files Collections from file_collection table');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file_collection', 'fc')
            ->fields('fc', array('ID', 'name', 'name_short', 'description'));
    $this->map = new MigrateSQLMap($this->machineName,
                    array(
                        'ID' => array('type' => 'int',
                            'not null' => TRUE,
                        )
                    ),
                    MigrateDestinationTerm::getKeySchema(),
                    'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTerm('file_collection');
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('field_file_collection_short_name', 'name_short');
    $this->addFieldMapping('description', 'description');
  }

}

class FileFolderMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Files Folders from file_folder table');
    $this->dependencies = array('FileCollection');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file_folder', 'ff')
            ->fields('ff', array('ID', 'collection_id', 'topic', 'file_no', 'other_source', 'comments'));
    $this->map = new MigrateSQLMap($this->machineName,
                    array(
                        'ID' => array('type' => 'int',
                            'not null' => TRUE,
                        )
                    ),
                    MigrateDestinationTerm::getKeySchema(),
                    'ImportDatabaseKey'
    );

    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTerm('file_folder');
    $this->addFieldMapping('name', 'topic');
    $this->addFieldMapping('field_files_folder_file_no', 'file_no');
    $this->addFieldMapping('field_files_folder_other_source', 'other_source');
    $this->addFieldMapping('field_files_folder_comments', 'comments');
    $this->addFieldMapping('field_files_folder_collection', 'collection_id')
            ->sourceMigration('FileCollection')
            ->arguments(array('source_type' => 'tid'));
  }

}

class FileCategoryMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Files Categories from file_categories table');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file_categories', 'fcc')
            ->fields('fcc', array('ID', 'name'));
    $this->map = new MigrateSQLMap($this->machineName,
                    array(
                        'ID' => array('type' => 'int',
                            'not null' => TRUE,
                        )
                    ),
                    MigrateDestinationTerm::getKeySchema(),
                    'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTerm('file_category');
    $this->addFieldMapping('name', 'name');
  }

}

class FilesMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Files content type from file table');
    //$this->dependencies = array('FileCollection', 'FileFolder', 'FileCategory', 'People', 'Location');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file', 'f')
            ->fields('f', array('ID', 'topic', 'extendedtopic', 'description', 'keypoints', 'extended_summary', 'text', 'keywords', 'file_extension',
        'original_title', 'category_id', 'source', 'volume', 'number', 'chapter', 'page', 'handwritten', 'typewritten', 'letterhead', 'remarks'));
    $query->leftJoin('file_collection2file', 'c2f', 'c2f.file_id = f.ID');
    $query->addField('c2f', 'collection_id', 'cid');
    $query->leftJoin('file_file2folder', 'f2f', 'f2f.file_id = f.ID');
    $query->addField('f2f', 'folder_id', 'fid');
    $this->map = new MigrateSQLMap($this->machineName,
                    array(
                        'ID' => array(
                            'type' => 'int',
                            'not null' => TRUE,
                            'alias' => 'f',
                        )
                    ),
                    MigrateDestinationTerm::getKeySchema(),
                    'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('files');
    $this->addFieldMapping('field_files_original_id', 'ID');
    $this->addFieldMapping('title', 'topic');
    $this->addFieldMapping('field_files_subtitle', 'extendedtopic');
    $this->addFieldMapping('field_files_description', 'description');
    $this->addFieldMapping('field_files_key_points', 'keypoints');
    $this->addFieldMapping('field_files_description:summary', 'extended_summary');
    $this->addFieldMapping('field_files_text2', 'text');
    $this->addFieldMapping('field_files_keywords', 'keywords')
            ->separator(',')
            ->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('field_files_original_title', 'original_title');
    $this->addFieldMapping('field_files_category', 'category_id')
            ->sourceMigration('FileCategory')
            ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_files_source_title', 'source');
    $this->addFieldMapping('field_files_source_volume', 'volume');
    $this->addFieldMapping('field_files_source_number', 'number');
    $this->addFieldMapping('field_files_source_page', 'page');
    $this->addFieldMapping('field_files_source_chapter', 'chapter');
    $this->addFieldMapping('field_files_handwritten', 'handwritten');
    $this->addFieldMapping('field_files_typewritten', 'typewritten');
    $this->addFieldMapping('field_files_letterhead', 'letterhead');
    $this->addFieldMapping('field_files_notes', 'remarks');
    $this->addFieldMapping('field_files_collection', 'cid')
            ->sourceMigration('FileCollection')
            ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_files_folder', 'fid')
            ->sourceMigration('FileFolder')
            ->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_files_author', 'author')
            ->sourceMigration('People');
    $this->addFieldMapping('field_files_receiver', 'receiver')
            ->sourceMigration('People');
    $this->addFieldMapping('field_files_creation_date', 'creation_date');
  }

  public function prepareRow($row) {
    //Add author field to the row
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'file', '=');
    $query->condition('l.tb_name', 'adv_people', '=');
    $query->condition('l2i.linkerinfo_id', '1', '=');
    $result = $query->execute();
    $authors = array();
    while ($record = $result->fetchAssoc()) {
      $authors[] = $record['tb_id'];
    }
    $row->author = $authors;

    //Add author field to the row
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'file', '=');
    $query->condition('l.tb_name', 'adv_people', '=');
    $query->condition('l2i.linkerinfo_id', '3', '=');
    $result = $query->execute();
    $receivers = array();
    while ($record = $result->fetchAssoc()) {
      $receivers[] = $record['tb_id'];
    }
    $row->receiver = $receivers;


    //Check if this file from collection with id 1,2 or 3
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file_collection2file', 'c2f');
    $query->addField('c2f', 'collection_id');
    $query->rightJoin('file', 'f', 'c2f.file_id = f.ID');
    $query->condition('f.ID', $row->ID . '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    switch ($record['collection_id']) {
      case 1:
      case 2:
      case 3:
        return TRUE;
      default:
        return FALSE;
    }
  }

  protected function createStub($migration, $source_id) {
    $node = new stdClass();
    $node->title = t('Stub for') . $source_id[0];
    $node->body = t('Stub body');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    } else {
      return FALSE;
    }
  }

  public function prepare($node, $row) {
    if ($row->file_extension == 'pdf') {
      $ID = $row->ID;
      //Deal with pdfs and swfs
      $directory = file_default_scheme() . '://books/' . $ID;
      if (file_prepare_directory($directory)) {
        $pdf_uri = $directory . '/' . $ID . '.pdf';
        $pdf_file = new stdClass();
        $pdf_file->uri = $pdf_uri;
        $pdf_file->uid = 1;
        $pdf_file->status = 1;
        $pdf_file->filename = $ID . '.pdf';
        $pdf_file->filemime = 'application/pdf';
        $pdf_file->filesize = filesize(drupal_realpath($pdf_uri));
        $pdf_file = file_save($pdf_file);
        $image_uri = $directory . '/' . $ID . '.jpg';
        $image_file = new stdClass();
        $image_file->uri = $image_uri;
        $image_file->uid = 1;
        $image_file->status = 1;
        $image_file->filename = $ID . '.jpg';
        $image_file->filemime = 'image/jpeg';
        $image_file->filesize = filesize($image_uri);
        $image_file = file_save($image_file);
        $node->field_files_file['und'][0]['fid'] = $pdf_file->fid;
        $node->field_files_file['und'][0]['fid_thumb'] = $image_file->fid;
        $node->field_files_file['und'][0]['conversion_done'] = 1;
        $node->field_files_file['und'][0]['folder_name'] = $ID;
      }
      //Set creation date
      $query = Database::getConnection('default', 'ImportDatabaseKey')
              ->select('egw_linker', 'l');
      $query->addField('l', 'tb_id');
      $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
      $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
      $query->condition('l2.tb_id', $row->ID, '=');
      $query->condition('l2.tb_name', 'file', '=');
      $query->condition('l2i.linkerinfo_id', '4', '=');
      $result = $query->execute();
      $record = $result->fetchAssoc();
      if (isset($record['tb_id'])) {
        $creation_date_id = $record['tb_id'];
        dpm($creation_date_id);
        $query = Database::getConnection('default', 'ImportDatabaseKey')
                ->select('adv_date_time', 'l');
        $query->condition('l.ID', $creation_date_id, '=');
        $query->fields('l', array('start_year', 'start_month', 'start_day'));
        $result = $query->execute();
        $record = $result->fetchAssoc();
        if (isset($record['start_year'])) {
          $start_year = $record['start_year'];
          $end_year = $start_year;
          if (isset($record['start_month'])) {
            $start_month = $record['start_month'];
            $end_month = $start_month;
            if (isset($record['start_day'])) {
              $start_day = $record['start_day'];
              $end_day = $start_day;
            } else {
              $start_day = '01';
              $end_day = date_days_in_month($year, $month);
            }
          } else {
            $start_month = '01';
            $end_month = '12';
            $start_day = '01';
            $end_day = '31';
          }
          $node->field_files_creation_date['und'][0]['value'] = $start_year . '-' . $start_month . '-' . $start_day . ' 00:00:00';
          $node->field_files_creation_date['und'][0]['value2'] = $end_year . '-' . $end_month . '-' . $end_day . ' 00:00:00';
          $node->field_files_creation_date['und'][0]['timezone'] = date_default_timezone();
          $node->field_files_creation_date['und'][0]['timezone_db'] = 'UTC';
          $node->field_files_creation_date['und'][0]['date_type'] = 'datetime';
        }
      }
    }
    $node->language = 'en';
  }

}

class PeopleMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate People content type from adv_people table');
    $this->dependencies = array('Location');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('adv_people', 'p')
            ->fields('p', array('ID', 'first_name', 'middle_name', 'last_name', 'maiden_name', 'generic_name',
        'email', 'description', 'title', 'degree', 'official_position', 'source'));

    $this->map = new MigrateSQLMap($this->machineName,
                    array(
                        'ID' => array(
                            'type' => 'int',
                            'not null' => FALSE,
                        )
                    ),
                    MigrateDestinationTerm::getKeySchema(),
                    'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('people');
    $this->addFieldMapping('title', 'real_title');
    $this->addFieldMapping('field_people_first_name', 'first_name');
    $this->addFieldMapping('field_people_last_name', 'last_name');
    $this->addFieldMapping('field_people_middle_name', 'middle_name');
    $this->addFieldMapping('field_people_maiden_name', 'maiden_name');
    $this->addFieldMapping('field_people_generic_name', 'generic_name');
    $this->addFieldMapping('field_people_e_mail', 'email');
    $this->addFieldMapping('field_people_title', 'title');
    $this->addFieldMapping('field_people_degree', 'degree');
    $this->addFieldMapping('field_people_official_position', 'official_position');
    $this->addFieldMapping('field_people_source', 'source');
    $this->addFieldMapping('field_people_description', 'description');
    $this->addFieldMapping('field_people_written_files', 'written_files')
            ->sourceMigration('Files');
    $this->addFieldMapping('field_people_received_files', 'received_files')
            ->sourceMigration('Files');
    $this->addFieldMapping('field_people_home', 'home')
            ->sourceMigration('Location');
    $this->addFieldMapping('field_people_visit_place', 'visit_place')
            ->sourceMigration('Location');
  }

  public function prepareRow($row) {
    if ($row->official_position == 0) {
      return FALSE;
    }
    $first_name = $row->first_name;
    $middle_name = $row->middle_name;
    $last_name = $row->last_name;
    $email = $row->email;
    if ($first_name || $last_name) {
      $real_title = $first_name . ' ' . $last_name;
    } elseif ($email) {
      $real_title = $email;
    } else {
      return FALSE;
    }
    if (strlen($real_title) >= 255) {
      $real_title = substr($real_title, 0, 255);
    }
    $row->real_title = $real_title;

    //Add written files
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_people', '=');
    $query->condition('l.tb_name', 'file', '=');
    $query->condition('l2i.linkerinfo_id', 1, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $written_files = array();
    while ($record = $result->fetchAssoc()) {
      $written_files[] = $record['tb_id'];
    }
    $row->written_files = $written_files;

    //Add received files
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_people', '=');
    $query->condition('l.tb_name', 'file', '=');
    $query->condition('l2i.linkerinfo_id', 3, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $received_files = array();
    while ($record = $result->fetchAssoc()) {
      $received_files[] = $record['tb_id'];
    }
    $row->received_files = $received_files;

    //Add home
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_people', '=');
    $query->condition('l.tb_name', 'adv_location', '=');
    $query->condition('l2i.linkerinfo_id', 17, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $home = array();
    while ($record = $result->fetchAssoc()) {
      $home[] = $record['tb_id'];
    }
    $row->home = $home;

    //Add visit place
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_people', '=');
    $query->condition('l.tb_name', 'adv_location', '=');
    $query->condition('l2i.linkerinfo_id', 18, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $visit_place = array();
    while ($record = $result->fetchAssoc()) {
      $visit_place[] = $record['tb_id'];
    }
    $row->visit_place = $visit_place;
  }

  protected function createStub($migration, $source_id) {
    //We should create stubs only when we go from location migration
   // if (get_class($migration) == "LocationMigration") {
      $node = new stdClass();
      $node->title = t('Stub for') . $source_id[0];
      $node->body = t('Stub body');
      $node->type = $this->destination->getBundle();
      $node->uid = 1;
      $node->status = 0;
      node_save($node);
      if (isset($node->nid)) {
        return array($node->nid);
      } else {
        return FALSE;
      }
    /*} else {
      return FALSE;
    }*/
  }

  public function prepare($node, $row) {
    $node->language = 'en';
  }

}

class LocationMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Location content type from adv_location table');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('adv_location_iso', 'p')
            ->fields('p', array('ID', 'locname', 'address', 'town', 'state', 'country',
        'zipcode', 'description', 'link', 'source'));
    $this->map = new MigrateSQLMap($this->machineName,
                    array(
                        'ID' => array(
                            'type' => 'int',
                            'not null' => FALSE,
                        )
                    ),
                    MigrateDestinationTerm::getKeySchema(),
                    'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('location');
    $this->addSimpleMappings(array('title', 'description'));
    $this->addFieldMapping('field_location_link', 'link');
    $this->addFieldMapping('field_location_source', 'source');
    $this->addFieldMapping('field_location_written_files', 'written_files')
            ->sourceMigration('Files');
    $this->addFieldMapping('field_location_received_files', 'received_files')
            ->sourceMigration('Files');
    $this->addFieldMapping('field_location_living_people', 'living_people')
            ->sourceMigration('People');
    $this->addFieldMapping('field_location_visiter', 'visiters')
            ->sourceMigration('People');
  }

  public function prepareRow($row) {
    $town = $row->town;
    $state = $row->state;
    $country = $row->country;
    $locname = $row->locname;
    $title = array();
    if ($town) {
      $title[] = $town;
    }
    if ($state) {
      $title[] = $state;
    }
    if ($country) {
      $title[] = $country;
    }
    $title = implode(', ', $title);
    if ($locname != 'Unknown' && !empty($locname)) {
      if (!empty($title)) {
        $title = $locname . ' (' . $title . ')';
      } else {
        $title = $locname;
      }
    } elseif (empty($title)) {
      return FALSE;
    }
    if (strlen($title) >= 255) {
      $title = substr($title, 0, 255);
    }
    $row->title = $title;

    //Add written files
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_location', '=');
    $query->condition('l.tb_name', 'file', '=');
    $query->condition('l2i.linkerinfo_id', 5, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $written_files = array();
    while ($record = $result->fetchAssoc()) {
      $written_files[] = $record['tb_id'];
    }
    $row->written_files = $written_files;

    //Add received files
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_people', '=');
    $query->condition('l.tb_name', 'file', '=');
    $query->condition('l2i.linkerinfo_id', 6, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $received_files = array();
    while ($record = $result->fetchAssoc()) {
      $received_files[] = $record['tb_id'];
    }
    $row->received_files = $received_files;

    //Add living people
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_location', '=');
    $query->condition('l.tb_name', 'adv_people', '=');
    $query->condition('l2i.linkerinfo_id', 17, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $living_people = array();
    while ($record = $result->fetchAssoc()) {
      $living_people[] = $record['tb_id'];
    }
    $row->living_people = $living_people;

    //Add visiters
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->leftJoin('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->leftJoin('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id AND l2.tb_name != l.tb_name');
    $query->condition('l2.tb_id', $row->ID, '=');
    $query->condition('l2.tb_name', 'adv_location', '=');
    $query->condition('l.tb_name', 'adv_people', '=');
    $query->condition('l2i.linkerinfo_id', 18, '=');
    $result = $query->execute();
    $record = $result->fetchAssoc();
    $visiters = array();
    while ($record = $result->fetchAssoc()) {
      $visiters[] = $record['tb_id'];
    }
    $row->visiters = $visiters;
  }

  public function prepare($node, $row) {
    $node->language = 'en';
    require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'library_migrate') . '/library_migrate_state_info.inc';
    $country = $row->country;
    $state = library_migrate_state_ISO($country, $row->state);
    $addressfield_content = array(
        'country' => $country,
        'administrative_area' => $state,
        'locality' => $row->town,
        'postal_code' => $row->zipcode,
        'thoroughfare' => $row->address,
        'organisation_name' => $row->locname
    );
    $node->field_location_address['und']['0'] = $addressfield_content;
    $field_instance = field_info_instance('node', 'field_location_geofield', 'location');
    if (($field_value = geocoder_widget_get_field_value('node', $field_instance, $node)) !== FALSE) {
      $node->{$field_instance['field_name']} = $field_value;
    }
  }
}

class EventsMigration extends LibraryMigration{

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Events content type from adv_events table');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('adv_events', 'p')
            ->fields('p', array('ID', 'title', 'description'));
    $this->map = new MigrateSQLMap($this->machineName,
                    array(
                        'ID' => array(
                            'type' => 'int',
                            'not null' => FALSE,
                        )
                    ),
                    MigrateDestinationTerm::getKeySchema(),
                    'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('events');
    $this->addSimpleMappings(array('title'));
    $this->addFieldMapping('field_events_description', 'description');
    $this->addFieldMapping('EVENT_FIELD_1', 'author')
            ->sourceMigration('People');
    $this->addFieldMapping('EVENT_FIELD_3', 'receiver')
            ->sourceMigration('People');
  }

}