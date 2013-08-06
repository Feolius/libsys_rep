<?php
//This file define constants for field names for nodes to be easily changed in future

//Events content type
//Person: Author. ID 1. Link to people
define('EVENT_FIELD_1', 'field_events_author');
//Person: Receiver. ID 3. Link to people
define('EVENT_FIELD_3', 'field_events_receiver');
//Date: Time of event. ID 13. Link to people, locations, sqlb_publications2link, date.
//define('EVENT_FIELD_13', 'field_events_time_nodes');
define('EVENT_FIELD_13_DATE', 'field_events_time');
//Location: Place of Event. ID 14. Link to people, locations, date.
define('EVENT_FIELD_14', 'field_events_place_nodes');
//I will remove it for now. It seems that this relation is unreasonable
//define('EVENT_FIELD_14_DATE', 'field_events_place_date');
//Location: On a Visit. ID 18. Link to people, locations, date.
define('EVENT_FIELD_18', 'field_events_visit_nodes');
define('EVENT_FIELD_18_DATE', 'field_events_visit_date');
//People: Main Character. ID 23. Link to people.
define('EVENT_FIELD_23', 'field_events_main_character');
//Location: Home. ID 17. Link to locations, date.
define('EVENT_FIELD_17', 'field_events_home');
define('EVENT_FIELD_17_DATE', 'field_events_home_date');
//Location: En Route to. ID 20. Link to locations.
define('EVENT_FIELD_20', 'field_events_route_to');
//Location: Starting the Route. ID 21. Link to locations.
define('EVENT_FIELD_21', 'field_events_route_start');
//Location: Original Place. ID 22. Link to locations.
define('EVENT_FIELD_22', 'field_events_original_place');

//People content type
//Person: Author. ID 1. Link to events
define('PEOPLE_FIELD_1', 'field_people_created_event');
//Person: Receiver. ID 3. Link to events
define('PEOPLE_FIELD_3', 'field_people_received_event');
//Location: Place of Event. ID 14. Link to events, locations.
define('PEOPLE_FIELD_14', 'field_people_place');
//Location: On a Visit. ID 18. Link to events, locations, date.
define('PEOPLE_FIELD_18', 'field_people_visit_nodes');
define('PEOPLE_FIELD_18_DATE', 'field_people_visit_date');
//People: Main Character. ID 23. Link to events.
define('PEOPLE_FIELD_23', 'field_people_related_event');
//Location: Home. ID 17. Link to  locations, date.
define('PEOPLE_FIELD_17', 'field_people_home_nodes');
define('PEOPLE_FIELD_17_DATE', 'field_people_home_date');

//Location content type
//Location: Place of Event. ID 14. Link to events, people.
define('LOCATION_FIELD_14', 'field_location_related_entities');
//Location: On a Visit. ID 18. Link to people, events, date.
define('LOCATION_FIELD_18', 'field_location_visit_nodes');
define('LOCATION_FIELD_18_DATE', 'field_location_visit_date');
//Location: Home. ID 17. Link to events, people, date.
define('LOCATION_FIELD_17', 'field_location_home_nodes');
define('LOCATION_FIELD_17_DATE', 'field_location_home_date');
//Location: En Route to. ID 20. Link to events.
define('LOCATION_FIELD_20', 'field_location_route_to_event');
//Location: Starting the Route. ID 21. Link to events.
define('LOCATION_FIELD_21', 'field_location_route_start_event');
//Location: Original Place. ID 22. Link to events.
define('LOCATION_FIELD_22', 'field_location_placed_event');

//Another info about fields.

//Content type Files.
//addFieldMapping('field_files_original_id', 'ID');
//addFieldMapping('title', 'topic');
//addFieldMapping('field_files_subtitle', 'extendedtopic');
//addFieldMapping('field_files_description', 'description');
//addFieldMapping('field_files_key_points', 'keypoints');
//addFieldMapping('field_files_description:summary', 'extended_summary');
//addFieldMapping('field_files_text', 'text');
//addFieldMapping('field_files_keywords', 'keywords')
//  ->separator(',')
//  ->arguments(array('create_term' => TRUE));
//addFieldMapping('field_files_original_title', 'original_title');
//addFieldMapping('field_files_category', 'category_id')
//  ->sourceMigration('FileCategory')
//  ->arguments(array('source_type' => 'tid'));
//addFieldMapping('field_files_source_title', 'source');
//addFieldMapping('field_files_source_volume', 'volume');
//addFieldMapping('field_files_source_number', 'number');
//addFieldMapping('field_files_source_page', 'page');
//addFieldMapping('field_files_source_chapter', 'chapter');
//addFieldMapping('field_files_handwritten', 'handwritten');
//addFieldMapping('field_files_typewritten', 'typewritten');
//addFieldMapping('field_files_letterhead', 'letterhead');
//addFieldMapping('field_files_notes', 'remarks');
//addFieldMapping('field_files_collection', 'cid')
//  ->sourceMigration('FileCollection')
//  ->arguments(array('source_type' => 'tid'));
//addFieldMapping('field_files_folder', 'fid')
//  ->sourceMigration('FileFolder')
//  ->arguments(array('source_type' => 'tid'));
//Person: Author. ID 1. Link to people. field_files_author.
//Person: Receiver. ID 3. Link to people. field_files_receiver.
//Location: Author. ID 5. Link to locations. field_files_author_location
//Location: Receiver. ID 6. Link to locations. field_files_receiver_location.
//Date: Creation. ID 4. Link to dates. field_files_creation_date.

//Content type People.
//addFieldMapping('title', 'real_title');
//addFieldMapping('field_people_first_name', 'first_name');
//addFieldMapping('field_people_last_name', 'last_name');
//addFieldMapping('field_people_middle_name', 'middle_name');
//addFieldMapping('field_people_maiden_name', 'maiden_name');
//addFieldMapping('field_people_generic_name', 'generic_name');
//addFieldMapping('field_people_e_mail', 'email');
//addFieldMapping('field_people_title', 'title');
//addFieldMapping('field_people_degree', 'degree');
//addFieldMapping('field_people_official_position', 'official_position');
//addFieldMapping('field_people_source', 'source');
//addFieldMapping('field_people_description', 'description');
//Person: Author. ID 1. Link to files. field_people_written_files.
//Person: Receiver. ID 3. Link to files. field_people_received_files.

//Content type Locations.
//addSimpleMappings(array('title'));
//addFieldMapping('field_location_description', 'description');
//addFieldMapping('field_location_link', 'link');
//addFieldMapping('field_location_source', 'source');
//Location: Author. ID 5. Link to files. field_location_written_files.
//Location: Receiver. ID 6. Link to files. field_location_received_files.

//Content type Events.
//addSimpleMappings(array('title'));
//addFieldMapping('field_events_description', 'description');
//Entity: Main Entity/Topic. ID 25. Link to topics. 'field_events_related_topic'

//Content type Topics.
//$this->addSimpleMappings(array('title'));
//$this->addFieldMapping('field_topics_body', 'description');
//$this->addFieldMapping('field_topics_kind', 'kind');
//Entity: Main Entity/Topic. ID 25. Link to events. field_topics_related_event.



