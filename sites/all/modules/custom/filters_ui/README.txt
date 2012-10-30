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
(           -> bundle_name(for date types)

All names and types is machine-readable and in lower case.

/*********************************************************/

Module Filters_UI allows to add new type of field for filtering.
To do this, you need to create new submodule with such name  - filters_ui_*machine name of new type that you need to add*
That module need to implement add filter to storage sturcture, delete from there and
get information by what current field filtered functions.
They should named like this:
add - filters_ui_*machine name of new type that you need to add*_add_field
      and take as arguments :
      $field - field information received by calling field_info_field function;
      $bundle - bundle,to which field is attached;
      &$facet_filters_settings - reference at current version of storage structure;
      $filter - information about field, that was taken from facet_collection_filters structure;

delete - filters_ui_*machine name of new type that you need to add*_delete_field
         and take as arguments :
         $field - field information received by calling field_info_field function;
         $bundle - bundle,to which field is attached;
         &$facet_filters_settings - reference at current version of storage structure;
         $filter - information about field, that was taken from facet_collection_filters structure;

filter by information - filters_ui_*machine name of new type that you need to add*_filter_by
                        and take as arguments :
                        $field - field information received by calling field_info_field function;

If field need some custom settings, like entity reference need form for choosing by which referenced filter should be enabled
and which disabled, you need to implement referenced fields summary and settings form functions.
They should named like this:
summary - filters_ui_*machine name of new type that you need to add*_summary
          and take as arguments :
          $field - field information received by calling field_info_field function;
          $ref_filters - list of already enabled filters;

form    - filters_ui_*machine name of new type that you need to add*_settings_form
          and take as arguments :
          $field - field information received by calling field_info_field function;
          $ref_filters - list of already enabled filters;
          $form - page form, in that form you need to add your settings form;
          &$form_state - structure, which store current state of enabled filters;
