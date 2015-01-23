<?php

class BasicEgwMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  public function prepareRow($row) {
    $point = geocoder('google', $row->location_csv);
    if (is_object($point)) {
      $row->country = $point->data['geocoder_address_components'][3]->long_name;
      $row->state = $point->data['geocoder_address_components'][2]->long_name;
      $row->city = $point->data['geocoder_address_components'][0]->long_name;
    }
  }
}


class EgwLettersMigration extends BasicEgwMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_letters_dest';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('id_csv', 'Filename');
    //  $columns[1] = array('from_csv', 'From');
    // $columns[2] = array('to_csv', 'To');
    $columns[3] = array('date_csv', 'Date');
    $columns[4] = array('year_csv', 'Year');
    $columns[5] = array('location_csv', 'Location');
    $columns[6] = array('notes_csv', 'Notes');
    $columns[7] = array('lb_ref', 'Lb ref number');
    $columns[8] = array('full_date', 'Date');
    $columns[9] = array('from_last_name', 'From(Last name)');
    $columns[10] = array('from_first_name', 'From(First name)');
    $columns[11] = array('to_last_name', 'To(Last name)');
    $columns[12] = array('to_first_name', 'To(First name)');


//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW letters import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/EGWLettersReceived(merged)2.csv', $columns, array());

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

//Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id_csv' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
    ), MigrateDestinationTable::getKeySchema($table_name));


//Field mapping
    $this->addUnmigratedDestinations(array('rid'));
    $this->addFieldMapping('filename', 'id_csv');
    $this->addFieldMapping('sender_last_name', 'from_last_name');
    $this->addFieldMapping('sender_first_name', 'from_first_name');
    $this->addFieldMapping('sender_second_name', 'from_first_name');
    $this->addFieldMapping('recipient_last_name', 'to_last_name');
    $this->addFieldMapping('recipient_first_name', 'to_first_name');
    $this->addFieldMapping('recipient_second_name', 'to_first_name');
    $this->addFieldMapping('date', 'full_date')->callbacks(array($this,'computeDate'));
    $this->addFieldMapping('country', 'country');
    $this->addFieldMapping('state', 'state');
    $this->addFieldMapping('city', 'city');
    $this->addFieldMapping('lb_ref_number', 'lb_ref');
    $this->addFieldMapping('notes', 'notes_csv');
  }

  protected function computeDate($date_csv) {
    $date = DateTime::createFromFormat('Y/m/d', $date_csv);
    return $date->format('m/d/Y');
  }

  /*
  public function getNames($string) {
    $count = substr_count($string,'.');
    if ($count == 2) {

    }
    else if ($count == 1) {

    }
    else {

    }
  }
  */
}
