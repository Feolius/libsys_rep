Module Filters UI using two common variable for storing setting from admin UI,
that is facet_collection_filters and facet_colletion_filters_settings.

The first one is used directly by filters admin UI.
The second one is used for filters settings transferring to apache_solr implementation of facet filters.

The structure of variable facet_collection_filters:
bundle_name - > array of field_name(machine name) -> state (visible or hidden)
                                                  -> referenced_filters (array of referenced    ) -> array of field_name (machine name       )
                                                                        (field for current field)                        (of referenced field)

The structure of variable facet_collection_filters_settings:
(           -> voting_tag_name(for fivestar)           -> array of bundle_name(bundle_names is keys)                                                                           )
(           -> vocabulary_name(for term_reference)     -> array of bundle_name(bundle_names is keys)                                                                           )
(field_type -> field_name(for entityreference)         -> state (TRUE if filter is enabled and FALSE if not)                                                                   )
(                                                      -> settings(for referenced filters)                   -> array of field_name(for all filterable types except date types))
(           -> bundle_name(for date types)                                                                                                                                     )
(           -> field_name(for text types)              -> bundle_name                                                                                                          )
(           -> field_name(for list types)              -> bundle_name                                                                                                          )
All names and types is machine-readable and in lower case.

Also the module could add into the filter settings node title. In the structure it was represented the next way:

(title -> array of bundle_name