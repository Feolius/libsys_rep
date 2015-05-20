<?php

class EgwCorrespondenceMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $table_name = 'migrate_egw_incoming_correspondence';
//The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns[0] = array('id', 'Id');

    $columns[2] = array('author_title', 'AuthorTitle');
    $columns[3] = array('author_last_name', 'AuthorLastName');
    $columns[4] = array('author_first_name', 'AuthorFirstName');
    $columns[5] = array('author_middle_name', 'AuthorMiddleName');
    $columns[6] = array('author_middle_name2', 'AuthorMiddleName2');
    $columns[7] = array('author_nick_name', 'AuthorNickName');
    $columns[8] = array('author_suffix', 'AuthorSuffix');
    $columns[9] = array('author_maiden_name', 'AuthorMaidenName');
    $columns[10] = array('author_alternate_last_name', 'AuthorAlternateLastName');
    $columns[11] = array('author_degree', 'AuthorDegree');

    $columns[13] = array('author2_title', 'Author2Title');
    $columns[14] = array('author2_last_name', 'Author2LastName');
    $columns[15] = array('author2_first_name', 'Author2 FirstName');
    $columns[16] = array('author2_middle_name', 'Author2MiddleName');
    $columns[17] = array('author2_middle_name2', 'Author2MiddleName2');
    $columns[18] = array('author2_nick_name', 'Author2NickName');
    $columns[19] = array('author2_suffix', 'Author2Suffix');
    $columns[20] = array('author2_maiden_name', 'Author2MaidenName');
    $columns[21] = array('author2_alternate_last_name', 'Author2AlternateLastName');
    $columns[22] = array('author2_degree', 'Author2Degree');

    $columns[24] = array('author3_title', 'Author3Title');
    $columns[25] = array('author3_last_name', 'Author3LastName');
    $columns[26] = array('author3_first_name', 'Author3FirstName');
    $columns[27] = array('author3_middle_name', 'Author3MiddleName');
    $columns[28] = array('author3_middle_name2', 'Author3MiddleName2');
    $columns[29] = array('author3_nick_name', 'Author3NickName');
    $columns[30] = array('author3_suffix', 'Author3Suffix');
    $columns[31] = array('author3_maiden_name', 'Author3MaidenName');
    $columns[32] = array('author3_alternate_last_name', 'Author3AlternateLastName');
    $columns[33] = array('author3_degree', 'Author3Degree');

    $columns[35] = array('receiver_title', 'ReceiverTitle');
    $columns[36] = array('receiver_last_name', 'ReceiverLastName');
    $columns[37] = array('receiver_first_name', 'ReceiverFirstName');
    $columns[38] = array('receiver_middle_name', 'ReceiverMiddleName');
    $columns[39] = array('receiver_middle_name2', 'ReceiverMiddleName2');
    $columns[40] = array('receiver_nick_name', 'ReceiverNickName');
    $columns[41] = array('receiver_suffix', 'ReceiverSuffix');
    $columns[42] = array('receiver_maiden_name', 'ReceiverMaidenName');
    $columns[43] = array('receiver_alternate_last_name', 'ReceiverAlternateLastName');
    $columns[44] = array('receiver_degree', 'ReceiverDegree');

    $columns[46] = array('receiver2_title', 'Receiver2Title');
    $columns[47] = array('receiver2_last_name', 'Receiver2LastName');
    $columns[48] = array('receiver2_first_name', 'Receiver2FirstName');
    $columns[49] = array('receiver2_middle_name', 'Receiver2MiddleName');
    $columns[50] = array('receiver2_middle_name2', 'Receiver2MiddleName2');
    $columns[51] = array('receiver2_nick_name', 'Receiver2NickName');
    $columns[52] = array('receiver2_suffix', 'Receiver2Suffix');
    $columns[53] = array('receiver2_maiden_name', 'Receiver2MaidenName');
    $columns[54] = array('receiver2_alternate_last_name', 'Receiver2AlternateLastName');
    $columns[55] = array('receiver2_degree', 'Receiver2Degree');

    $columns[56] = array('receiver3_title', 'Receiver3Title');
    $columns[57] = array('receiver3_last_name', 'Receiver3LastName');
    $columns[58] = array('receiver3_first_name', 'Receiver3FirstName');
    $columns[59] = array('receiver3_middle_name', 'Receiver3MiddleName');
    $columns[60] = array('receiver3_middle_name2', 'Receiver3MiddleName2');
    $columns[61] = array('receiver3_nick_name', 'Receiver3NickName');
    $columns[62] = array('receiver3_suffix', 'Receiver3Suffix');
    $columns[63] = array('receiver3_maiden_name', 'Receiver3MaidenName');
    $columns[64] = array('receiver3_alternate_last_name', 'Receiver3AlternateLastName');
    $columns[65] = array('receiver3_degree', 'Receiver3Degree');

    $columns[66] = array('date', 'Date');
    $columns[67] = array('lb_ref_number', 'LB Ref#');
    $columns[68] = array('notes', 'Notes');
    $columns[69] = array('author_position', 'AuthorPosition');
    $columns[70] = array('author_institution', 'AuthorInstitution');
    $columns[71] = array('author_town', 'AuthorTown');
    $columns[72] = array('author_state', 'AuthorState');
    $columns[73] = array('author_country', 'AuthorCountry');
    $columns[74] = array('author_zip_code', 'AuthorZipcode');
    $columns[75] = array('receiver_position', 'ReceiverPosition');
    $columns[76] = array('receiver_institution', 'ReceiverInstitution');
    $columns[77] = array('receiver_town', 'ReceiverTown');
    $columns[78] = array('receiver_state', 'ReceiverState');
    $columns[79] = array('receiver_country', 'ReceiverCountry');
    $columns[80] = array('receiver_zipcode', 'ReceiverZipcode');
    $columns[81] = array('year', 'Year');
    $columns[82] = array('month', 'Month');
    $columns[83] = array('day', 'Day');
    $columns[84] = array('text', 'Text');
    $columns[85] = array('author_address', 'AuthorAddress');
    $columns[86] = array('receiver_address', 'ReceiverAddress');
    $columns[87] = array('letterhead', 'Letterhead');
    $columns[88] = array('handwritten', 'Handwritten');
    $columns[89] = array('typewritten', 'Typewritten');
    $columns[90] = array('author_county', 'AuthorCounty');
    $columns[91] = array('receiver_county', 'ReceiverCounty');


//The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('A CSV EGW incoming correspondence import ');

//The Source of the import
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'egw_letters') . '/import/20150415_FinalOutput_XtraColumnsRemoved.csv', $columns, array('header_rows' => 1));

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
    $this->addFieldMapping('author_title', 'author_title');
    $this->addFieldMapping('author_last_name', 'author_last_name');
    $this->addFieldMapping('author_first_name', 'author_first_name');
    $this->addFieldMapping('author_middle_name', 'author_middle_name');
    $this->addFieldMapping('author_middle_name2', 'author_middle_name2');
    $this->addFieldMapping('author_nick_name', 'author_nick_name');
    $this->addFieldMapping('author_suffix', 'author_suffix');
    $this->addFieldMapping('author_maiden_name', 'author_maiden_name');
    $this->addFieldMapping('author_alternate_last_name', 'author_alternate_last_name');
    $this->addFieldMapping('author_degree', 'author_degree');

    $this->addFieldMapping('author2_title', 'author2_title');
    $this->addFieldMapping('author2_last_name', 'author2_last_name');
    $this->addFieldMapping('author2_first_name', 'author2_first_name');
    $this->addFieldMapping('author2_middle_name', 'author2_middle_name');
    $this->addFieldMapping('author2_middle_name2', 'author2_middle_name2');
    $this->addFieldMapping('author2_nick_name', 'author2_nick_name');
    $this->addFieldMapping('author2_suffix', 'author2_suffix');
    $this->addFieldMapping('author2_maiden_name', 'author2_maiden_name');
    $this->addFieldMapping('author2_alternate_last_name', 'author2_alternate_last_name');
    $this->addFieldMapping('author2_degree', 'author2_degree');

    $this->addFieldMapping('author3_title', 'author3_title');
    $this->addFieldMapping('author3_last_name', 'author3_last_name');
    $this->addFieldMapping('author3_first_name', 'author3_first_name');
    $this->addFieldMapping('author3_middle_name', 'author3_middle_name');
    $this->addFieldMapping('author3_middle_name2', 'author3_middle_name2');
    $this->addFieldMapping('author3_nick_name', 'author3_nick_name');
    $this->addFieldMapping('author3_suffix', 'author3_suffix');
    $this->addFieldMapping('author3_maiden_name', 'author3_maiden_name');
    $this->addFieldMapping('author3_alternate_last_name', 'author3_alternate_last_name');
    $this->addFieldMapping('author3_degree', 'author3_degree');

    $this->addFieldMapping('receiver_title', 'receiver_title');
    $this->addFieldMapping('author3_last_name', 'author3_last_name');
    $this->addFieldMapping('author3_first_name', 'author3_first_name');
    $this->addFieldMapping('author3_middle_name', 'author3_middle_name');
    $this->addFieldMapping('author3_middle_name2', 'author3_middle_name2');
    $this->addFieldMapping('author3_nick_name', 'author3_nick_name');
    $this->addFieldMapping('author3_suffix', 'author3_suffix');
    $this->addFieldMapping('author3_maiden_name', 'author3_maiden_name');
    $this->addFieldMapping('author3_alternate_last_name', 'author3_alternate_last_name');
    $this->addFieldMapping('author3_degree', 'author3_degree');

    $this->addFieldMapping('text', 'text');
  }
}