<?php

//This file defines boosts for all searchable fields in files, people, location, topics content types until we don't have admin settings for it

//Files content type
define('FILES_TITLE_BOOST', '4.0');
define('FIELD_FILES_DESCRIPTION_BOOST', '1.0');
define('FIELD_FILES_FILE_BOOST', '1.0');
define('FIELD_FILES_KEY_POINTS_BOOST', '1.0');
define('FIELD_FILES_LENGTH_BOOST', '1.0');
define('FIELD_FILES_NOTES_BOOST', '1.0');
define('FIELD_FILES_ORIGINAL_TITLE_BOOST', '1.0');
define('FIELD_FILES_SOURCE_PAGE_BOOST', '1.0');
define('FIELD_FILES_SOURCE_TITLE_BOOST', '1.0');
define('FIELD_FILES_SUBTITLE_BOOST', '1.0');
define('FIELD_FILES_TEXT_BOOST', '1.0');
define('FIELD_FILES_TRACK_NUMBER_BOOST', '1.0');

//People content type
define('PEOPLE_TITLE_BOOST', '4.0');
define('FIELD_PEOPLE_DEGREE_BOOST', '1.0');
define('FIELD_PEOPLE_DESCRIPTION_BOOST', '1.0');
define('FIELD_PEOPLE_E_MAIL_BOOST', '1.0');
define('FIELD_PEOPLE_FAVORITE_FOOD_BOOST', '1.0');
define('FIELD_PEOPLE_FIRST_NAME_BOOST', '1.0');
define('FIELD_PEOPLE_GENERIC_NAME_BOOST', '1.0');
define('FIELD_PEOPLE_LAST_NAME_BOOST', '1.0');
define('FIELD_PEOPLE_MAIDEN_NAME_BOOST', '1.0');
define('FIELD_PEOPLE_MIDDLE_NAME_BOOST', '1.0');
define('FIELD_PEOPLE_SOURCE_BOOST', '1.0');
define('FIELD_PEOPLE_TITLE_BOOST', '1.0');

//Location content type
define('LOCATION_TITLE_BOOST', '4.0');
define('FIELD_LOCATION_COUNTY_BOOST', '1.0');
define('FIELD_LOCATION_DESCRIPTION_BOOST', '1.0');
define('FIELD_LOCATION_LINK_BOOST', '1.0');
define('FIELD_LOCATION_SOURCE_BOOST', '1.0');

//Topics content type
define('TOPICS_TITLE_BOOST', '4.0');
define('FIELD_TOPICS_BODY_BOOST', '1.0');

//Events content type
define('EVENTS_TITLE_BOOST', '4.0');
define('FIELD_EVENTS_DESCRIPTION_BOOST', '1.0');

/**
 * It's hardcoded function. Return an array with keys are machine field names and values are boost values. This fields will be used in default search.
 * Need to be replaced by admin settings.
 */
function facet_collection_get_field_boosts($chosen_content_type){
  $boosts = array();
  $constants = get_defined_constants();
  $boosts['title'] = $constants[strtoupper($chosen_content_type . '_title_boost')];
  //Files
  //$boosts['files_title'] = FILES_TITLE_BOOST;
  $boosts['field_files_description'] = FIELD_FILES_DESCRIPTION_BOOST;
  $boosts['field_files_file'] = FIELD_FILES_FILE_BOOST;
  $boosts['field_files_notes'] = FIELD_FILES_NOTES_BOOST;
  $boosts['field_files_text'] = FIELD_FILES_TEXT_BOOST;
  //Locations
  //$boosts['people_title'] = PEOPLE_TITLE_BOOST;
  $boosts['field_people_description'] = FIELD_PEOPLE_DESCRIPTION_BOOST;
  $boosts['field_people_e_mail'] = FIELD_PEOPLE_E_MAIL_BOOST;
  $boosts['field_people_first_name'] = FIELD_PEOPLE_FIRST_NAME_BOOST;
  $boosts['field_people_last_name'] = FIELD_PEOPLE_LAST_NAME_BOOST;
  $boosts['field_people_middle_name'] = FIELD_PEOPLE_MIDDLE_NAME_BOOST;
  //People
  //$boosts['location_title'] = LOCATION_TITLE_BOOST;
  $boosts['field_location_description'] = FIELD_LOCATION_DESCRIPTION_BOOST;
  //Topics
 // $boosts['topics_title'] = TOPICS_TITLE_BOOST;
  $boosts['field_topics_body_boost'] = FIELD_TOPICS_BODY_BOOST;
  //Events
  $boosts['field_events_description'] = FIELD_EVENTS_DESCRIPTION_BOOST;
  return $boosts;
}