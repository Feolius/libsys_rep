<?php

/**
 * @file
 * Provides API documentation for adding  new field type support at filters_ui module
 *
 * Module Filters_UI allows to add new type of field for filtering.
 * To do this, you need to create new submodule with
 * such name  - filters_ui_*machine name of new type that you need to add*.
 * That module need to implement add filter to storage sturcture, delete from there,
 * get information about handled types and get information by what current field filtered functions.
 *
 * If field need some custom settings, like entity reference need form for choosing by which referenced filter should be enabled
 * and which disabled, you need to implement referenced fields summary and settings form functions.
 *
 * Also some field need to have custom handler when field was updated.
 * Implement for this the system hook - hook_field_update_field in
 * what submodule(filters_ui_*machine name of new type that you need to add*) in what needed.
 *
 */

/**
 * Define field types that will handle by current filter_ui submodule
 *
 * @return array
 *   An array containing field types.
 */
function hook_filters_ui_field_type_info()
{
}


/**
 * Add information about field to storage structure.
 *
 * @param $field
 *  Field information received by calling field_info_field function.
 * @param $bundle
 *  Bundle,to which field is attached.
 * @param $facet_filters_settings
 *  Reference at current version of storage structure.
 * @param $filter
 *  Information about field, that was taken from facet_collection_filters structure.
 */
function hook_filters_ui_add_field($field, $bundle, &$facet_filters_settings, $filter)
{

}


/**
 * Delete information about filter from storage structure.
 *
 * @param $field
 *  Field information received by calling field_info_field function.
 * @param $bundle
 *  Bundle,to which field is attached.
 * @param $facet_filters_settings
 *  Reference at current version of storage structure.
 * @param $filter
 *  Information about field, that was taken from facet_collection_filters structure.
 */
function hook_filters_ui_delete_field($field, $bundle, &$facet_filters_settings, $filter)
{

}


/**
 * Return information by what current field would be filtered.
 *
 * @param $field
 *  Field information received by calling field_info_field function.
 * @return string
 *  String label, described by what current field would be filtered.
 */
function hook_filters_ui_filter_by($field)
{

}

/**
 * Return summary of which of referenced fields are enabled for filtering.
 *
 * @param $field
 *  Field information received by calling field_info_field function.
 * @param $ref_filters
 *  List of already enabled filters.
 * @return string
 *  String, which consist of summary for each enables referenced filter.
 */
function hook_filters_ui_summary($field, $ref_filters)
{

}


/**
 * Bulding settings form for choosing by which referenced field need to filter or not
 *
 * @param $field
 *  Field information received by calling field_info_field function.
 * @param $ref_filters
 *  List of already enabled filters.
 * @param $form
 *  Page form, in that form you need to add your settings form.
 * @param $form_state
 *  Structure, which store current state of enabled filters.
 * @return mixed
 *  Return settings form, if referenced content types have filterable field,
 *  and empty array if not.
 */
function hook_filters_ui_settings_form($field, $ref_filters, $form, &$form_state)
{

}
