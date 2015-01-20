<?

class EgwLettersMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_letters_dest';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('id_csv', 'Id');
    $columns[1] = array('from_csv', 'From');
  //  $columns[2] = array('to_csv', 'To');
  //  $columns[3] = array('date_csv', 'Date');
  //  $columns[5] = array('location_csv', 'Location');
  //  $columns[6] = array('date_csv', 'Date');

//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW letters import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/GL2008.TXT', $columns);

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
    $this->addFieldMapping('from', 'from_csv');
  //  $this->addFieldMapping('to', 'from_csv');
  }
}