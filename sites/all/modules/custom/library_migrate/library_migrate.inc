<?php

abstract class LibraryMigration extends DynamicMigration {

  public function __construct() {
    parent::__construct();
    require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'library_migrate') . '/library_migrate_field_names.inc';
    //For development on local machine
   /* $other_database = array(
        'database' => 'adventists',
        'username' => 'admin',
        'password' => '1234',
        'host' => 'localhost',
        'driver' => 'mysql',
    );*/
    //For import on production server
     $other_database = array(
      'database' => 'archive_library',
      'username' => 'archive_library',
      'password' => 'jkqeq23ffa3rh',
      'host' => 'sql-3',
      'driver' => 'mysql',
      );
    Database::addConnectionInfo('ImportDatabaseKey', 'default', $other_database);
    set_time_limit(0);
  }

  //Get source ids for entries which related with the reference entry ($reference_id, $reference_tb) through given linker
  public function getRelatedSids($reference_id, $reference_tb, $needed_tbs, $linkerinfo_id) {
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('egw_linker', 'l');
    $query->addField('l', 'tb_id');
    $query->join('egw_linker2info', 'l2i', 'l2i.linker_id = l.linker_entry_id');
    $query->join('egw_linker', 'l2', 'l2.linker_entry_id = l.linker_entry_id');
    $query->condition('l2.tb_id', $reference_id);
    $query->condition('l2.tb_name', $reference_tb);
    $condition = db_or();
    $data = array();
    foreach ($needed_tbs as $needed_tb) {
      $data[$needed_tb] = array();
      $condition = $condition->condition('l.tb_name', $needed_tb);
    }
    $query->condition($condition);
    $query->addField('l', 'tb_name');
    $query->condition('l2i.linkerinfo_id', $linkerinfo_id);
    $result = $query->execute();
    while ($record = $result->fetchAssoc()) {
      $data[$record['tb_name']][] = $record['tb_id'];
    }
    return $data;
  }

  //Helper function. Check if sids are already exist and if not, creates stubs. Return destids
  public function sidsHandler($data) {
    $results = array();
    foreach ($data as $source_name => $sids) {
      $source_migration = Migration::getInstance($source_name);
      foreach ($sids as $sid) {
        $destids = $source_migration->getMap()->lookupDestinationID(array($sid));
        if (!empty($destids['destid1'])) {
          $results[] = $destids['destid1'];
        } else {
          //We should create a stub here
          $node = new stdClass();
          $node->title = t('Stub for') . $sid;
          $node->body = t('Stub body');
          $node->type = $source_migration->destination->getBundle();
          $node->uid = 1;
          $node->status = 0;
          node_save($node);
          if (isset($node->nid)) {
            $destids = array($node->nid);
            $map_source_key = $source_migration->map->getSourceKey();
            $data_row = new stdClass;
            foreach ($map_source_key as $key => $definition) {
              $data_row->$key = $sid;
            }
            $source_migration->map->saveIDMapping($data_row, $destids, MigrateMap::STATUS_NEEDS_UPDATE, $source_migration->defaultRollbackAction);
            $results = array_merge($destids, $results);
          }
        }
      }
    }
    return $results;
  }

  //Method find all dates according to given reference entry id, reference table name and linker and put it in node inside given field
  public function set_datefield_value($field_name, $node, $reference_ID, $reference_tb, $linkerinfo_id) {
    $data = $this->getRelatedSids($reference_ID, $reference_tb, array('adv_date_time'), $linkerinfo_id);
    if (isset($data['adv_date_time'])) {
      foreach ($data['adv_date_time'] as $creation_date_id) {
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
          if (checkdate($start_month, $start_day, $start_year) && checkdate($end_month, $end_day, $end_year)) {
            $node->{$field_name}['und'][$i]['value'] = $start_year . '-' . $start_month . '-' . $start_day . ' 00:00:00';
            $node->{$field_name}['und'][$i]['timezone'] = date_default_timezone();
            $node->{$field_name}['und'][$i]['timezone_db'] = 'UTC';
            $node->{$field_name}['und'][$i]['date_type'] = 'datetime';
            if (checkdate($end_month, $end_day, $end_year)) {
              $node->{$field_name}['und'][$i]['value2'] = $end_year . '-' . $end_month . '-' . $end_day . ' 00:00:00';
            }
            $i++;
          } else {
            continue;
          }
        }
      }
    }
  }

  //Method allows to get destination ids from mapping tables
  public function getDidsFromMapTable($table_name, $sids) {
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

}

class FileCollectionMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Files Collections from file_collection table');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file_collection', 'fc')
            ->fields('fc', array('ID', 'name', 'name_short', 'description'));
    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array('type' => 'int',
                    'not null' => TRUE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
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
    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array('type' => 'int',
                    'not null' => TRUE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
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
    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array('type' => 'int',
                    'not null' => TRUE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
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
    $this->dependencies = array('FileCollection', 'FileFolder', 'FileCategory', 'People', 'Location');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file', 'f')
            ->fields('f', array('ID', 'topic', 'extendedtopic', 'description', 'keypoints', 'extended_summary', 'text', 'keywords', 'file_extension',
        'original_title', 'category_id', 'source', 'volume', 'number', 'chapter', 'page', 'handwritten', 'typewritten', 'letterhead', 'remarks'));
    $query->leftJoin('file_collection2file', 'c2f', 'c2f.file_id = f.ID');
    $query->addField('c2f', 'collection_id', 'cid');
    $query->leftJoin('file_file2folder', 'f2f', 'f2f.file_id = f.ID');
    $query->leftJoin('file_folder', 'ff', 'ff.ID = f2f.folder_id');
    $query->addField('ff', 'collection_id', 'cid2');
    $query->addField('f2f', 'folder_id', 'fid');
    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array(
                    'type' => 'int',
                    'not null' => TRUE,
                    'alias' => 'f',
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('files');
    $this->addFieldMapping('field_files_original_id', 'ID');
    $this->addFieldMapping('title', 'topic');
    $this->addFieldMapping('field_files_subtitle', 'extendedtopic');
    $this->addFieldMapping('field_files_description', 'description');
    $this->addFieldMapping('field_files_key_points', 'keypoints');
    $this->addFieldMapping('field_files_description:summary', 'extended_summary');
    $this->addFieldMapping('field_files_text', 'text');
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
    //Check if this file from collection with id 1,2 or 3
    if (!(is_null($row->cid))) {
      $cid = $row->cid;
    } elseif (!(is_null($row->cid2))) {
      $cid = $row->cid2;
    } else {
      return FALSE;
    }
    switch ($cid) {
      case 1:
      case 2:
      case 3:
        break;
      default:
        return FALSE;
    }
    //Add author field to the row
    $data = $this->getRelatedSids($row->ID, 'file', array('adv_people'), 1);
    $row->author = $data['adv_people'];
    //Add author field to the row
    $data = $this->getRelatedSids($row->ID, 'file', array('adv_people'), 3);
    $row->receiver = $data['adv_people'];
    //Add author location field to the row
    $data = $this->getRelatedSids($row->ID, 'file', array('adv_location'), 5);
    $row->author_location = $data['adv_location'];
    //Add receiver location field to the row
    $data = $this->getRelatedSids($row->ID, 'file', array('adv_location'), 6);
    $row->receiver_location = $data['adv_location'];
  }

  protected function createStub($migration, $source_id) {
    //Check if this stub from collection with id 1,2 or 3
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('file', 'f');
    $query->condition('f.ID', $source_id[0]);
    $query->leftJoin('file_collection2file', 'c2f', 'c2f.file_id = f.ID');
    $query->addField('c2f', 'collection_id', 'cid');
    $query->leftJoin('file_file2folder', 'f2f', 'f2f.file_id = f.ID');
    $query->leftJoin('file_folder', 'ff', 'ff.ID = f2f.folder_id');
    $query->addField('ff', 'collection_id', 'cid2');
    $result = $query->execute();
    if ($record = $result->fetchAssoc()) {
      if (!is_null($record['cid'])) {
        $cid = $record['cid'];
      } elseif (!is_null($record['cid2'])) {
        $cid = $record['cid2'];
      } else {
        return FALSE;
      }
      switch ($cid) {
        case 1:
        case 2:
        case 3:
          break;
        default:
          return FALSE;
      }
    }
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
    $data = $this->getRelatedSids($row->ID, 'file', array('adv_date_time'), 4);
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
    $node->language = 'en';
    $node->field_files_description['und'][0] = 'filtered_html';
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

    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array(
                    'type' => 'int',
                    'not null' => FALSE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
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
    $this->addFieldMapping(PEOPLE_FIELD_1, 'people_field_1');
    $this->addFieldMapping(PEOPLE_FIELD_3, 'people_field_3');
    $this->addFieldMapping(PEOPLE_FIELD_14, 'people_field_14');
    $this->addFieldMapping(PEOPLE_FIELD_18, 'people_field_18');
    $this->addFieldMapping(PEOPLE_FIELD_23, 'people_field_23');
    $this->addFieldMapping(PEOPLE_FIELD_17, 'people_field_17');
  }

  public function prepareRow($row) {
    if ($row->official_position != 1) {
      return FALSE;
    }
    $first_name = $row->first_name;
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
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('file', 'adv_events'), 1);
    $row->written_files = $data['file'];
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $row->people_field_1 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('file', 'adv_events'), 3);
    $row->received_files = $data['file'];
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $row->people_field_3 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('adv_location'), 17);
    $row->home = $data['adv_location'];
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('adv_location'), 18);
    $row->visit_place = $data['adv_location'];
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('adv_events', 'adv_location'), 14);
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $sids['Location'] = $data['adv_location'];
    $row->people_field_14 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('adv_events', 'adv_location'), 18);
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $sids['Location'] = $data['adv_location'];
    $row->people_field_18 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('adv_events'), 23);
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $row->people_field_23 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_people', array('adv_location'), 17);
    $sids = array();
    $sids['Location'] = $data['adv_location'];
    $row->people_field_17 = $this->sidsHandler($sids);
  }

  protected function createStub($migration, $source_id) {
    //We should create stubs only when we go from location migration
    if (get_class($migration) == "LocationMigration") {
      $query = Database::getConnection('default', 'ImportDatabaseKey')
              ->select('adv_people', 'p')
              ->fields('p', array('first_name', 'middle_name', 'last_name', 'email', 'official_position'));
      $result = $query->execute();
      if ($record = $result->fetchAssoc()) {
        if ($record['official_position'] != 1) {
          return FALSE;
        }
        if (!(isset($record['first_name']) || isset($record['last_name']) || isset($record['email']))) {
          return FALSE;
        }
      }
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
    } else {
      return FALSE;
    }
  }

  public function prepare($node, $row) {
    $node->language = 'en';
    $node->field_people_description['und'][0] = 'filtered_html';
    $this->set_datefield_value(PEOPLE_FIELD_17_DATE, $node, $row->ID, 'adv_people', 17);
    $this->set_datefield_value(PEOPLE_FIELD_18_DATE, $node, $row->ID, 'adv_people', 18);
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
    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array(
                    'type' => 'int',
                    'not null' => FALSE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
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
    $this->addFieldMapping(LOCATION_FIELD_14, 'location_field_14');
    $this->addFieldMapping(LOCATION_FIELD_18, 'location_field_18');
    $this->addFieldMapping(LOCATION_FIELD_20, 'location_field_20');
    $this->addFieldMapping(LOCATION_FIELD_21, 'location_field_21');
    $this->addFieldMapping(LOCATION_FIELD_22, 'location_field_22');
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
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('file'), 5);
    $row->written_files = $data['file'];
    //Add received files
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('file'), 6);
    $row->received_files = $data['file'];
    //Add living people
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('adv_people'), 17);
    $row->living_people = $data['adv_people'];
    //Add visiters
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('adv_people'), 18);
    $row->visiters = $data['adv_people'];
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('adv_people', 'adv_events'), 14);
    $sids = array();
    $sids['People'] = $data['adv_people'];
    $sids['Events'] = $data['adv_events'];
    $row->location_field_14 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('adv_people', 'adv_events'), 18);
    $sids = array();
    $sids['People'] = $data['adv_people'];
    $sids['Events'] = $data['adv_events'];
    $row->location_field_18 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('adv_events'), 20);
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $row->location_field_20 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('adv_events'), 21);
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $row->location_field_21 = $this->sidsHandler($sids);
    $data = $this->getRelatedSids($row->ID, 'adv_location', array('adv_events'), 22);
    $sids = array();
    $sids['Events'] = $data['adv_events'];
    $row->location_field_22 = $this->sidsHandler($sids);
  }

  public function prepare($node, $row) {
    $node->language = 'en';
    $node->field_location_description['und'][0]['format'] = 'filtered_html';
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
    //Add datefields
    $this->set_datefield_value(LOCATION_FIELD_18_DATE, $node, $row->ID, 'adv_location', 18);
    $this->set_datefield_value(LOCATION_FIELD_17_DATE, $node, $row->ID, 'adv_location', 17);
  }

}

class EventsMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Events content type from adv_events table');
    $this->dependencies = array('Location', 'People');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('adv_events', 'p')
            ->fields('p', array('events_id', 'title', 'description'));
    $this->map = new MigrateSQLMap($this->machineName, array(
                'events_id' => array(
                    'type' => 'int',
                    'not null' => FALSE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
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
    $this->addFieldMapping('field_events_related_publication', 'publication')
            ->sourceMigration('Publications');
    $this->addFieldMapping('field_events_encyclopedia', 'encyclopedia')
            ->sourceMigration('Encyclopedia');
  }

  public function prepareRow($row) {
    //Add author
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_people'), 1);
    $row->author = $data['adv_people'];
    //Add receiver
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_people'), 3);
    $row->receiver = $data['adv_people'];
    ;
    //Stefan said that this field should give us only datefield
    //Add event_field_13
    /* $data = $this->getRelatedSids($row->ID, 'adv_events', array('adv_people', 'adv_location'), 13);
      $nids = $this->getDidsFromMapTable('migrate_map_location', $data['adv_location']);
      $nids = array_merge($nids, $this->getDidsFromMapTable('migrate_map_people', $data['adv_people']));
      $row->event_field_13 = $nids; */
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_people', 'adv_location'), 14);
    $nids = $this->getDidsFromMapTable('migrate_map_location', $data['adv_location']);
    $nids = array_merge($nids, $this->getDidsFromMapTable('migrate_map_people', $data['adv_people']));
    $row->event_field_14 = $nids;
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_people', 'adv_location'), 18);
    $nids = $this->getDidsFromMapTable('migrate_map_location', $data['adv_location']);
    $nids = array_merge($nids, $this->getDidsFromMapTable('migrate_map_people', $data['adv_people']));
    $row->event_field_18 = $nids;
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_people'), 23);
    $nids = $this->getDidsFromMapTable('migrate_map_people', $data['adv_people']);
    $row->event_field_23 = $nids;
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_location'), 17);
    $nids = $this->getDidsFromMapTable('migrate_map_location', $data['adv_location']);
    $row->event_field_17 = $nids;
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_location'), 20);
    $nids = $this->getDidsFromMapTable('migrate_map_location', $data['adv_location']);
    $row->event_field_20 = $nids;
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_location'), 21);
    $nids = $this->getDidsFromMapTable('migrate_map_location', $data['adv_location']);
    $row->event_field_21 = $nids;
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_location'), 22);
    $nids = $this->getDidsFromMapTable('migrate_map_location', $data['adv_location']);
    $row->event_field_22 = $nids;
    //Add encyclopedia and publication
    $data = $this->getRelatedSids($row->events_id, 'adv_events', array('adv_entities'), 25);
    if (!empty($data['adv_entities'])) {
      $query = Database::getConnection('default', 'ImportDatabaseKey')
              ->select('adv_entities', 'l');
      $condition = db_or();
      foreach ($data['adv_entities'] as $entity_id) {
        $condition = $condition->condition('l.ID', $entity_id);
      }
      $query->condition($condition);
      $query->fields('l', array('ID', 'kind'));
      $result = $query->execute();
      $publications = array();
      $encyclopedias = array();
      while ($record = $result->fetchAssoc()) {
        if ($record['kind'] == 1 || $record['kind'] == 5) {
          $publications[] = $record['ID'];
        } elseif ($record['kind'] == 2 || $record['kind'] == 4) {
          $encyclopedias[] = $record['ID'];
        }
      }
      $row->publication = $publications;
      $row->encyclopedia = $encyclopedias;
    }
  }

  public function prepare($node, $row) {
    $node->language = 'en';
    $node->field_events_description['und'][0]['format'] = 'filtered_html';
    //Add dates
    $this->set_datefield_value(EVENT_FIELD_13_DATE, $node, $row->events_id, 'adv_events', 13);
    //@see comment in library_migrate_field_names
    //set_datefield_value(EVENT_FIELD_14_DATE, $node, $row->events_id, 'adv_events', 14);
    $this->set_datefield_value(EVENT_FIELD_18_DATE, $node, $row->events_id, 'adv_events', 18);
    $this->set_datefield_value(EVENT_FIELD_17_DATE, $node, $row->events_id, 'adv_events', 17);
  }

  public function complete($node, $row) {
    $this->buildHierarchy($node, $row->events_id);
  }

  //Save node and its parents recursively in drupal. Return mlid.
  public function buildHierarchy($node, $events_id) {
    //Try to get parent source id
    $parent_info = $this->getParentSid($events_id);
    if (!empty($parent_info['parent_id'])) {
      //If exists, check if drupal already has corresponding node
      $parent_did = $this->getDidsFromMapTable('migrate_map_events', array($parent_info['parent_id']));
      $parent_id = $parent_info['parent_id'];
      if (empty($parent_did)) {
        //If drupal doesn't have corresponding node, we should create a stub for it
        $source_migration = Migration::getInstance('Events');
        $parent_node = new stdClass();
        $query = Database::getConnection('default', 'ImportDatabaseKey')
                ->select('adv_events', 'l');
        $query->condition('l.ID', $parent_id);
        $query->addField('l', 'title');
        $result = $query->execute();
        $record = $result->fetchAssoc();
        $title = $record['title'];
        $parent_node->title = $title;
        $parent_node->body = t('Stub body');
        $parent_node->type = $source_migration->destination->getBundle();
        $parent_node->uid = 1;
        $parent_node->status = 0;
        node_save($parent_node);
        if (isset($parent_node->nid)) {
          $destids = array($parent_node->nid);
          $map_source_key = $source_migration->map->getSourceKey();
          $data_row = new stdClass;
          foreach ($map_source_key as $key => $definition) {
            $data_row->$key = $parent_id;
          }
          $source_migration->map->saveIDMapping($data_row, $destids, MigrateMap::STATUS_NEEDS_UPDATE, $source_migration->defaultRollbackAction);
        }
        $parent_nid = $parent_node->nid;
        //Build hierarchy for parent and get plid
        $parent_node = node_load($parent_nid);
        $plid = $this->buildHierarchy($parent_node, $parent_id);
      } else {
        $parent_nid = $parent_did[0];
        //If drupal has parent node we should check if we already have mlid for it
        //@TODO maybe it would be better to add condition for menu name to be certanly sure that we have needed plid
        $plid = _nodehierarchy_get_node_mlids($parent_nid);
        if (!empty($plid)) {
          $plid = $plid[0];
        } else {
          //Build hierarchy for parent and get plid
          $parent_node = node_load($parent_nid);
          $plid = $this->buildHierarchy($parent_node, $parent_id);
        }
      }
      //Creat link for given node
      $menu_link = _nodehierarchy_default_menu_link($node->nid, $plid);
      $menu_link['link_title'] = $node->title;
      $menu_link['weight'] = $parent_info['pos'];
      $mlid = menu_link_save($menu_link);
      _nodehierarchy_create_nodehierarchy_menu_link_reference($menu_link);
      return $mlid;
    } else {
      //If parent doesn't exist, it means that this is a first parent
      //We should check if corresponding link exists and, if not, create link for it
      $mlid = _nodehierarchy_get_node_mlids($node->nid);
      if (!empty($mlid)) {
        $mlid = $mlid[0];
      } else {
        $menu_link = _nodehierarchy_default_menu_link($node->nid);
        $menu_link['link_title'] = $node->title;
        $mlid = menu_link_save($menu_link);
        _nodehierarchy_create_nodehierarchy_menu_link_reference($menu_link);
      }
      return $mlid;
    }
  }

  //Return parent source id and position of current event
  public function getParentSid($event_id) {
    $info = array();
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('adv_events_parents', 'l');
    $query->condition('l.event_id', $event_id);
    $query->addField('l', 'parent_event_id');
    $query->addField('l', 'pos');
    $result = $query->execute();
    if (($record = $result->fetchAssoc())) {
      $info['pos'] = $record['pos'];
      $info['parent_id'] = $record['parent_event_id'];
    }
    return $info;
  }

}

class PublicationsMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Publications content type from adv_entities table');
    $this->dependencies = array('Events');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('adv_entities', 'e')
            ->fields('e', array('ID', 'title', 'description', 'kind'));
    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array(
                    'type' => 'int',
                    'not null' => FALSE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('publications');
    $this->addSimpleMappings(array('title'));
    $this->addFieldMapping('field_publications_description', 'description');
    $this->addFieldMapping('field_publications_related_event', 'event');
  }

  public function prepareRow($row) {
    if ($row->kind != 1 && $row->kind != 5) {
      return FALSE;
    }
    $data = $this->getRelatedSids($row->ID, 'adv_entities', array('adv_events'), 25);
    $row->event = $data['adv_events'];
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
    $node->language = 'en';
  }

}

class EncyclopediaMigration extends LibraryMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate Encyclopedia content type from adv_entities table');
    $this->dependencies = array('Events');
    $query = Database::getConnection('default', 'ImportDatabaseKey')
            ->select('adv_entities', 'e')
            ->fields('e', array('ID', 'title', 'description', 'kind'));
    $this->map = new MigrateSQLMap($this->machineName, array(
                'ID' => array(
                    'type' => 'int',
                    'not null' => FALSE,
                )
                    ), MigrateDestinationTerm::getKeySchema(), 'ImportDatabaseKey'
    );
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('encyclopedia');
    $this->addSimpleMappings(array('title'));
    $this->addFieldMapping('field_encyclopedia_description', 'description');
    $this->addFieldMapping('field_encyclopedia_related_event', 'event');
  }

  public function prepareRow($row) {
    if ($row->kind != 2 && $row->kind != 4) {
      return FALSE;
    }
    $data = $this->getRelatedSids($row->ID, 'adv_entities', array('adv_events'), 25);
    $row->event = $data['adv_events'];
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
    $node->language = 'en';
  }

}