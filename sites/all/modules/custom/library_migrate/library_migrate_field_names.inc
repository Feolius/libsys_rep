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

//Location content type
//Location: Place of Event. ID 14. Link to events, people.
define('LOCATION_FIELD_14', 'field_location_related_entities');
//Location: On a Visit. ID 18. Link to people, events, date.
define('LOCATION_FIELD_18', 'field_location_visit_nodes');
define('LOCATION_FIELD_18_DATE', 'field_location_visit_date');
//Location: Home. ID 17. Link to events, date.
define('LOCATION_FIELD_17', 'field_location_home_event');
define('LOCATION_FIELD_17_DATE', 'field_location_home_date');
//Location: En Route to. ID 20. Link to events.
define('LOCATION_FIELD_20', 'field_location_route_to_event');
//Location: Starting the Route. ID 21. Link to events.
define('LOCATION_FIELD_21', 'field_location_route_start_event');
//Location: Original Place. ID 22. Link to events.
define('LOCATION_FIELD_22', 'field_location_placed_event');