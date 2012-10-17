Module Filters UI using two common variable for storing setting from admin UI,
that is facet_collection_filters and facet_colletion_filters_settings.

The first one is used directly by filters admin UI.
The second one is used for filters settings transferring to apache_solr implementation of facet filters.

The structure of variable facet_collection_filters:
field_name(machine name) -> state (visible or hidden)
                         -> referenced_filters (array of referenced    ) -> array of field_name (machine name       )
                                               (field for current field)                        (of referenced field)





The structure of variable facet_collection_filters_settings:
(           -> vocabulary_name(for term_reference)     -> bundle_name                                    )
(field_type -> field_name(for entityreference)         -> content_types                   -> bundle_name )
(                                                      -> settings(for referenced filters)               )
(           -> bundle_name(for date types)

The structure of associated array for referenced filters is the same
as for usual filters, except settings key foe fiel_name for entityreference field type.
(              voc_name(for term_reference)     -> bundle_name )
(field_type -> field_name(for entityreference)  -> bundle_name )
(              bundle_name(for date types)                     )

All names and types is machine-readable and in lower case.