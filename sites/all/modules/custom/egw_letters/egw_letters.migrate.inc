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
      'correspondence' => array(
        'title' => t('Correspondence files'),
      ),
      'egw_archives' => array(
        'title' => t('Ellen G. White Archives'),
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
      'egw_correspondence' => array(
        'class_name' => 'EgwCorrespondenceMigration',
        'group_name' => 'correspondence',
      ),
      'questions_answers' => array(
        'class_name' => 'QuestionEgwMigration',
        'group_name' => 'egw_archives',
      ),
      'private_office' => array(
        'class_name' => 'PrivateOfficeEgwMigration',
        'group_name' => 'egw_archives',
      ),
      'bibliography' => array(
        'class_name' => 'BibliographyEgwMigration',
        'group_name' => 'egw_archives',
      ),
    ),
  );
  return $api;
}