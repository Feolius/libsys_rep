<?php

class EgwLettersMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_letters_dest';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('id_csv', 'Filename');
    $columns[1] = array('from_csv', 'From');
    $columns[2] = array('to_csv', 'To');
    $columns[3] = array('date_csv', 'Date');
    $columns[4] = array('year_csv', 'Year');
    $columns[5] = array('location_csv', 'Location');
    $columns[6] = array('notes_csv', 'Notes');
    $columns[8] = array('full_date', 'Date');

//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW letters import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/EGWLettersReceived(merged)2.csv', $columns, array());

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

//Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id_csv' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
      )
      ),
      MigrateDestinationTable::getKeySchema($table_name)
    );


//Field mapping
    $this->addUnmigratedDestinations(array('rid'));
    $this->addFieldMapping('filename', 'id_csv');
    $this->addFieldMapping('sender', 'from_csv');
    $this->addFieldMapping('recipient', 'to_csv');
    $this->addFieldMapping('date', 'full_date')->callbacks(array($this,'computeDate'));
    $this->addFieldMapping('location', 'location_csv');
    $this->addFieldMapping('notes', 'notes_csv');
  }

  protected function computeDate($date_csv) {
    $date = DateTime::createFromFormat('Y/m/d', $date_csv);
    return $date->format('d/m/Y');
  }

}
