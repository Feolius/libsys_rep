<?php

class WhiteIndexMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_whiteje_index';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('id_csv', 'Filename');
    $columns[1] = array('from_csv', 'From');
    $columns[2] = array('to_csv', 'To');
    $columns[3] = array('date_csv', 'Date');
    $columns[4] = array('location_csv', 'Location');
    $columns[5] = array('lb_ref', 'Lb ref number');
    $columns[6] = array('notes_csv', 'Notes');

//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('White JE index import');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/white_je_index.csv', $columns, array('header_rows' => 1));

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
    $this->addFieldMapping('date', 'date_csv');
    $this->addFieldMapping('location', 'location_csv');
    $this->addFieldMapping('lb_ref_number', 'lb_ref');
    $this->addFieldMapping('notes', 'notes_csv');
  }

}