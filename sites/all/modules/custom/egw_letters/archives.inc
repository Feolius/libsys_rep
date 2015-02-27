<?php

class QuestionEgwMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_question_answers';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('code_number_csv', 'Filename');
    $columns[1] = array('phrases_csv', 'From');

//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW answers and questions import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/egw_questions_answers.csv', $columns, array('header_rows' => 1));

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

//Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName, array(
      'code_number_csv' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    ), MigrateDestinationTable::getKeySchema($table_name));


//Field mapping
    $this->addUnmigratedDestinations(array('rid'));
    $this->addFieldMapping('code_number', 'code_number_csv');
    $this->addFieldMapping('phrases', 'phrases_csv');
  }

}
