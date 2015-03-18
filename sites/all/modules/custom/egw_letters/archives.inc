<?php

class QuestionEgwMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_question_answers';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('code_number_csv', 'Filename');
    $columns[1] = array('phrases_csv', 'From');
    $columns[2] = array('id', 'id');
//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW answers and questions import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/egw_questions_answers.csv', $columns, array('header_rows' => 1));

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

//Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ), MigrateDestinationTable::getKeySchema($table_name));

//Field mapping
    $this->addUnmigratedDestinations(array('rid'));
    $this->addFieldMapping('code_number', 'code_number_csv');
    $this->addFieldMapping('phrases', 'phrases_csv');
  }
}


class BibliographyEgwMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_bibliography';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('title', 'Title');
    $columns[1] = array('year', 'Year');
    $columns[2] = array('pages', 'Pages');
    $columns[3] = array('notes', 'Notes');
    $columns[4] = array('id', 'id');
    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW bibliography import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/bibliography_egw_writings.csv', $columns, array('header_rows' => 1));

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

//Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ), MigrateDestinationTable::getKeySchema($table_name));

//Field mapping
    $this->addUnmigratedDestinations(array('rid'));
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('year', 'year');
    $this->addFieldMapping('pages', 'pages');
    $this->addFieldMapping('notes', 'notes');
  }
}


class PrivateOfficeEgwMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_private_office';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('author', 'Author');
    $columns[1] = array('title', 'Title');
    $columns[2] = array('publisher', 'publisher');
    $columns[3] = array('date', 'Date');
    $columns[4] = array('pages', 'Pages');
    $columns[5] = array('library', 'Library');
    $columns[6] = array('location', 'Location');
    $columns[7] = array('ebooks', 'Ebooks');
    $columns[8] = array('notes', 'Notes');
    $columns[9] = array('id', 'id');

//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW Private and Office Libraries import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/private_offices.csv', $columns, array('header_rows' => 1));

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

    //Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ), MigrateDestinationTable::getKeySchema($table_name));

//Field mapping
    $this->addUnmigratedDestinations(array('rid'));
    $this->addFieldMapping('author', 'author');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('date', 'date');
    $this->addFieldMapping('publisher', 'publisher');
    $this->addFieldMapping('pages', 'pages');
    $this->addFieldMapping('library', 'library');
    $this->addFieldMapping('location', 'location');
    $this->addFieldMapping('ebooks', 'ebooks');
    $this->addFieldMapping('notes', 'notes');
  }

}