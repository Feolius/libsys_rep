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

  //Get source ids for entries which related with the reference entry ($reference_id, $reference_tb) through given linker
  public function get_related_sids($reference_id, $reference_tb, $needed_tbs, $linkerinfo_id) {
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->join('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->join('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id');
    $query->condition('l2.tb_id', $reference_id, '=');
    $query->condition('l2.tb_name', $reference_tb);
    $condition = db_or();
    foreach ($needed_tbs as $needed_tb) {
      $condition = $condition->condition('l.tb_name', $needed_tb);
    }
    $query->condition($condition);
    $query->addField('l', 'tb_name');
    $query->condition('l2i.linkerinfo_id', $linkerinfo_id, '=');
    $result = $query->execute();
    $data = array();
    while ($record = $result->fetchAssoc()) {
      $data[$record['tb_name']][] = $record['tb_id'];
    }
    return $data;
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
    $this->addFieldMapping('field_files_author_location', 'author_location')
            ->sourceMigration('Location');
    $this->addFieldMapping('field_files_receiver_location', 'receiver_location')
            ->sourceMigration('Location');
  }

  public function prepareRow($row) {
    //Add author field to the row
    $data = $this->get_related_sids($row->ID, 'file', array('adv_people'), 1);
    $row->author = $data['adv_people'];
    //Add author field to the row
    $data = $this->get_related_sids($row->ID, 'file', array('adv_people'), 3);
    $row->receiver = $data['adv_people'];
    //Add author location field to the row
    $data = $this->get_related_sids($row->ID, 'file', array('adv_location'), 5);
    $row->author_location = $data['adv_location'];
    //Add receiver location field to the row
    $data = $this->get_related_sids($row->ID, 'file', array('adv_location'), 6);
    $row->receiver_location = $data['adv_location'];
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
      $data = $this->get_related_sids($row->ID, 'file', array('adv_date_time'), 4);
      if (isset($data['adv_date_time']['tb_id'])) {
        $creation_date_id = $data['adv_date_time']['tb_id'];
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
              $end_day = date_days_in_month($end_year, $end_month);
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
    //$this->dependencies = array('Location');
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
    /* if ($row->official_position == 0) {
      return FALSE;
      } */
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
    $data = $this->get_related_sids($row->ID, 'adv_people', array('file'), 1);
    $row->written_files = $data['file'];
    //Add received files
    $data = $this->get_related_sids($row->ID, 'adv_people', array('file'), 3);
    $row->received_files = $data['file'];
    //Add home
    $data = $this->get_related_sids($row->ID, 'adv_people', array('adv_location'), 17);
    $row->home = $data['adv_location'];
    //Add visit place
    $data = $this->get_related_sids($row->ID, 'adv_people', array('adv_location'), 18);
    $row->visit_place = $data['adv_location'];
  }

  protected function createStub($migration, $source_id) {
    //We should create stubs only when we go from location migration
    // if (get_class($migration) == "LocationMigration") {
    dpm($migration);
    dpm($source_id);
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
    /* } else {
      return FALSE;
      } */
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
    $this->addFieldMapping(LOCATION_FIELD_14, 'related_entities');
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
    $data = $this->get_related_sids($row->ID, 'adv_location', array('file'), 5);
    $row->written_files = $data['file'];
    //Add received files
    $data = $this->get_related_sids($row->ID, 'adv_location', array('file'), 6);
    $row->received_files = $data['file'];
    //Add living people
    $data = $this->get_related_sids($row->ID, 'adv_location', array('adv_people'), 17);
    $row->living_people = $data['adv_people'];
    //Add visiters
    $data = $this->get_related_sids($row->ID, 'adv_location', array('adv_people'), 18);
    $row->visiters = $data['adv_people'];
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

  //@TODO Maybe this is need to be remove if we start import from locations
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
    /* } else {
      return FALSE;
      } */
  }

}

class EventsMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Events content type from adv_events table');
    //$this->dependencies = array('Location', 'People');
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
    $this->addFieldMapping(EVENT_FIELD_1, 'author')
            ->sourceMigration('People');
    $this->addFieldMapping(EVENT_FIELD_3, 'receiver')
            ->sourceMigration('People');
    //$this->addFieldMapping(EVENT_FIELD_13, 'event_field_13');
    $this->addFieldMapping(EVENT_FIELD_14, 'event_field_14');
    $this->addFieldMapping(EVENT_FIELD_18, 'event_field_18');
    $this->addFieldMapping(EVENT_FIELD_23, 'event_field_23');
    $this->addFieldMapping(EVENT_FIELD_17, 'event_field_17');
    $this->addFieldMapping(EVENT_FIELD_20, 'event_field_20');
    $this->addFieldMapping(EVENT_FIELD_21, 'event_field_21');
    $this->addFieldMapping(EVENT_FIELD_22, 'event_field_22');
  }

  public function prepareRow($row) {
    //Add author
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_people'), 1);
    $row->author = $data['adv_people'];
    //Add receiver
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_people'), 3);
    $row->receiver = $data['adv_people'];
    ;
    //Stefan said that this field should give us only datefield
    //Add event_field_13
   /* $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_people', 'adv_location'), 13);
    $nids = $this->get_dids_from_map_table('migrate_map_location', $data['adv_location']);
    $nids = array_merge($nids, $this->get_dids_from_map_table('migrate_map_people', $data['adv_people']));
    $row->event_field_13 = $nids;*/
    //Add event_field_14
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_people', 'adv_location'), 14);
    $nids = $this->get_dids_from_map_table('migrate_map_location', $data['adv_location']);
    $nids = array_merge($nids, $this->get_dids_from_map_table('migrate_map_people', $data['adv_people']));
    $row->event_field_14 = $nids;
    //Add event_field_18
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_people', 'adv_location'), 18);
    $nids = $this->get_dids_from_map_table('migrate_map_location', $data['adv_location']);
    $nids = array_merge($nids, $this->get_dids_from_map_table('migrate_map_people', $data['adv_people']));
    $row->event_field_18 = $nids;
    //Add event_field_23
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_people'), 23);
    $nids = $this->get_dids_from_map_table('migrate_map_people', $data['adv_people']);
    $row->event_field_23 = $nids;
    //Add event_field_17
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_location'), 17);
    $nids = $this->get_dids_from_map_table('migrate_map_location', $data['adv_location']);
    $row->event_field_17 = $nids;
    //Add event_field_20
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_location'), 20);
    $nids = $this->get_dids_from_map_table('migrate_map_location', $data['adv_location']);
    $row->event_field_20 = $nids;
    //Add event_field_21
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_location'), 21);
    $nids = $this->get_dids_from_map_table('migrate_map_location', $data['adv_location']);
    $row->event_field_21 = $nids;
    //Add event_field_22
    $data = $this->get_related_sids($row->ID, 'adv_events', array('adv_location'), 22);
    $nids = $this->get_dids_from_map_table('migrate_map_location', $data['adv_location']);
    $row->event_field_22 = $nids;
  }

  public function prepare($node, $row) {
    $node->language = 'en';
    //Add dates
    set_datefield_value(EVENT_FIELD_13_DATE, $node, $row->ID, 'adv_events', 13);
    //@see comment in library_migrate_field_names
    //set_datefield_value(EVENT_FIELD_14_DATE, $node, $row->ID, 'adv_events', 14);
    set_datefield_value(EVENT_FIELD_18_DATE, $node, $row->ID, 'adv_events', 18);
    set_datefield_value(EVENT_FIELD_17_DATE, $node, $row->ID, 'adv_events', 17);
  }

  //Method allows to get destination ids from mapping tables
  public function get_dids_from_map_table($table_name, $sids) {
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select($table_name, 'l');
    $query->addField('l', 'destid1');
    $condition = db_or();
    if (!empty($sids)) {
      foreach ($sids as $sid) {
        $condition = $condition->condition('l.sourceid1', $sid);
      }
    } else {
      return array();
    }
    $query->condition($condition);
    $result = $query->execute();
    $dids = array();
    while ($record = $result->fetchAssoc()) {
      $dids[] = $record['destid1'];
    }
    return $dids;
  }

  //Method find all dates according to given reference entry id, reference table name and linker and put it in node inside given field
  public function set_datefield_value($field_name, $node, $reference_ID, $reference_tb, $linkerinfo_id) {
    $data = $this->get_related_sids($reference_ID, $reference_tb, array('adv_date_time'), $linkerinfo_id);
    if (isset($data['adv_date_time']['tb_id'])) {
      foreach ($data['adv_date_time']['tb_id'] as $creation_date_id) {
        $query = Database::getConnection('default', 'ImportDatabaseKey')
                ->select('adv_date_time', 'l');
        $query->condition('l.ID', $creation_date_id, '=');
        $query->fields('l', array('start_year', 'start_month', 'start_day', 'end_year', 'end_month', 'end_day'));
        $result = $query->execute();
        $i = 0;
        $record = $result->fetchAssoc();
        if (isset($record['start_year'])) {
          $start_year = $record['start_year'];
          if (isset($record['end_year'])) {
            $end_year = $record['end_year'];
          } else {
            $end_year = $start_year;
          }
          if (isset($record['start_month'])) {
            $start_month = $record['start_month'];
            if (isset($record['start_day'])) {
              $start_day = $record['start_day'];
            } else {
              $start_day = '01';
              $end_day = date_days_in_month($year, $month);
            }
          } else {
            $start_month = '01';
            $start_day = '01';
          }
          if (isset($record['end_month'])) {
            $end_month = $record['end_month'];
            if (isset($record['end_day'])) {
              $end_day = $record['end_day'];
            } else {
              $end_day = date_days_in_month($end_year, $end_month);
            }
          } else {
            $end_month = '12';
            $end_day = '31';
          }
          $node->{$field_name}['und'][$i]['value'] = $start_year . '-' . $start_month . '-' . $start_day . ' 00:00:00';
          $node->{$field_name}['und'][$i]['value2'] = $end_year . '-' . $end_month . '-' . $end_day . ' 00:00:00';
          $node->{$field_name}['und'][$i]['timezone'] = date_default_timezone();
          $node->{$field_name}['und'][$i]['timezone_db'] = 'UTC';
          $node->{$field_name}['und'][$i]['date_type'] = 'datetime';
          $i++;
        }
      }
    }
  }

}