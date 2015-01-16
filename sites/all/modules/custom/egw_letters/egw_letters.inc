<?

class EgwLettersMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $table_name = 'migrate_egw_letters_dest';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('id_csv', 'Id');
    $columns[1] = array('title_csv', 'Title');
    $columns[2] = array('body_csv', 'Body');
    $columns[3] = array('another_field_csv', 'Just another field');

//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW letters import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('egw_letters', 'module_name') . '/import/EGWLettersReceived(merged).csv', $columns);

//The destination table
    $this->destination = new MigrateDestinationTable($table_name);

//Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName,
      array('fooid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
      ),
      MigrateDestinationTable::getKeySchema($table_name)
    );


//Field ampping
    $this->addFieldMapping('title', 'title_csv');
    $this->addFieldMapping('body', 'body_csv');
    $this->addFieldMapping('another_field', 'another_field_csv');
  }
}