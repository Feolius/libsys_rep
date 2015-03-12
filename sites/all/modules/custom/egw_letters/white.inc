<?php

class WhiteIndexMigration extends BasicEgwMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_whiteje_index';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[2] = array('filename', 'Filename');
    $columns[4] = array('sender_last_name', 'Sender last name');
    $columns[5] = array('sender_first_name', 'Sender first name');
    $columns[6] = array('sender_second_name', 'Sender second name');
    $columns[7] = array('sender2_last_name', 'Sender2 last name');
    $columns[8] = array('sender2_first_name', 'Sender2 first name');
    $columns[9] = array('sender2_second_name', 'Sender2 second name');
    $columns[10] = array('description', 'Description');
    $columns[11] = array('comment', 'Comment');
    $columns[12] = array('recipient_title', 'Recipient title');
    $columns[13] = array('recipient_last_name', 'Recipient last name');
    $columns[14] = array('recipient_first_name', 'Recipient first name');
    $columns[15] = array('recipient_second_name', 'Recipient second name');
    $columns[16] = array('recipient_suffix', 'Recipient suffix');
    $columns[17] = array('recipient2_last_name', 'Recipient last name');
    $columns[18] = array('recipient2_first_name', 'Recipient first name');
    $columns[19] = array('recipient2_second_name', 'Recipient second name');
    $columns[20] = array('date', 'Date');
    $columns[21] = array('country', 'Country');
    $columns[22] = array('state', 'State');
    $columns[23] = array('city', 'City');
    $columns[23] = array('lb_ref_number', 'Ref number');
    $columns[24] = array('notes_csv', 'Notes');


//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('White JE index import');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/latest_edit_whiteje_index.csv', $columns, array('header_rows' => 1));

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

//Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'filename' => array(
          'type' => 'int',
          'not null' => TRUE,
        )
      ),
      MigrateDestinationTable::getKeySchema($table_name)
    );

//Field mapping
    $this->addUnmigratedDestinations(array('rid'));
    $this->addFieldMapping('filename', 'filename');
    $this->addFieldMapping('sender_last_name', 'sender_last_name');
    $this->addFieldMapping('sender_first_name', 'sender_first_name');
    $this->addFieldMapping('sender_second_name', 'sender_second_name');
    $this->addFieldMapping('sender2_last_name', 'sender2_last_name');
    $this->addFieldMapping('sender2_first_name', 'sender2_first_name');
    $this->addFieldMapping('sender2_second_name', 'sender2_second_name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('comment', 'comment');
    $this->addFieldMapping('recipient_last_name', 'recipient_last_name');
    $this->addFieldMapping('recipient_first_name', 'recipient_first_name');
    $this->addFieldMapping('recipient_second_name', 'recipient_second_name');
    $this->addFieldMapping('recipient2_last_name', 'recipient2_last_name');
    $this->addFieldMapping('recipient2_first_name', 'recipient2_first_name');
    $this->addFieldMapping('recipient2_second_name', 'recipient2_second_name');
    $this->addFieldMapping('recipient_suffix', 'recipient_suffix');
    $this->addFieldMapping('date', 'date');
    $this->addFieldMapping('country', 'country');
    $this->addFieldMapping('state', 'state');
    $this->addFieldMapping('city', 'city');
    $this->addFieldMapping('lb_ref_number', 'lb_ref_number');
    $this->addFieldMapping('notes', 'notes_csv');
  }

}