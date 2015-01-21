<?php
/**
 * @file
 * Declares migrations.
 */


/**
 * Implements hook_migrate_api().
 */
function egw_letters_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'egw_csv_files' => array(
        'title' => t('EGW CSV files'),
      ),
      'white_je_index' => array(
        'title' => t('White JE index CSV files'),
      ),
    ),
    'migrations' => array(
      'egw_letters' => array(
        'class_name' => 'EgwLettersMigration',
        'group_name' => 'egw_csv_files',
      ),
      'white_je' => array(
        'class_name' => 'WhiteIndexMigration',
        'group_name' => 'white_je_index',
      ),
    ),
  );
  return $api;
}