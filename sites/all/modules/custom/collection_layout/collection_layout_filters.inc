<?php

function collection_layout_get_avaliable_filters_list() {
    return array('document_type', 'collection', 'category', 'group', 'date', 'creator', 'view_type');
}

function collection_layout_is_filter($arg) {
    return in_array($arg, collection_layout_get_avaliable_filters_list());
}

function collection_layout_set_filter_value($fid, $val) {
    $_SESSION['collection_layout'][$fid][] = $val;
    $_SESSION['collection_layout']['flag'] = 1;
}

function collection_layout_add_filter_value($fid, $val) {
    if ($fid == 'date') {
        if (isset($val['year'])) {
            if (isset($_SESSION['collection_layout'][$fid]['year'])) {
                if ($_SESSION['collection_layout'][$fid]['year'] == $val['year'])
                    unset($_SESSION['collection_layout'][$fid]['year']);
                else
                    $_SESSION['collection_layout'][$fid]['year'] = $val['year'];
            }else
                $_SESSION['collection_layout'][$fid]['year'] = $val['year'];
            $_SESSION['collection_layout']['flag'] = 1;
        }
        if (isset($val['min']) && isset($val['max'])) {
            $_SESSION['collection_layout'][$fid]['min'] = $val['min'];
            $_SESSION['collection_layout'][$fid]['max'] = $val['max'];
            $_SESSION['collection_layout']['flag'] = 1;
        }
        return;
    }
    if ($fid == 'view_type') {
        $_SESSION['collection_layout']['view_type'] = $val;
        return;
    }
    if (isset($_SESSION['collection_layout'][$fid]))
        if (!in_array($val, $_SESSION['collection_layout'][$fid])) {
            collection_layout_set_filter_value($fid, $val);
        } else
            collection_layout_remove_filter_value($fid, $val);
    else
        collection_layout_set_filter_value($fid, $val);
}

function collection_layout_remove_filter_value($fid, $val) {
    if (in_array($val, $_SESSION['collection_layout'][$fid]))
        foreach ($_SESSION['collection_layout'][$fid] as $key => $value) {
            if ($val == $value) {
                unset($_SESSION['collection_layout'][$fid][$key]);
                $_SESSION['collection_layout']['flag'] = 1;
            }
        }
}

function collection_layout_get_filter_value($fid) {
    if (collection_layout_is_filter($fid))
        if (isset($_SESSION['collection_layout'][$fid]))
            return $_SESSION['collection_layout'][$fid];
        else
            return false;
}

function collection_layout_get_enable_filters_list() {
    $list = array();
    if (isset($_SESSION['collection_layout']))
        foreach ($_SESSION['collection_layout'] as $key => $value) {
            if (collection_layout_is_filter($key))
                $list[$key] = $value;
        }
    return empty($list) ? false : $list;
}

function collection_layout_get_filter_human_name($fid) {
    switch ($fid) {
        case 'document_type' :
            return 'Document type';
        case 'collection' :
            return 'Collection';
        case 'category' :
            return 'Category';
        case 'group' :
            return 'Groupe';
        case 'data' :
            return '';
        default :
            return false;
    }
}

function collection_layout_get_term_name($tid) {
    return $term_name = db_select('taxonomy_term_data', 't')
                    ->fields('t', array('name'))
                    ->condition('tid', $tid)
                    ->execute()
                    ->fetchObject()
            ->name;
}

function collection_layout_get_filter_machine_name($voc) {
    switch ($voc) {
        case 'library_voc_cat' :
            return 'category';
        case 'library_voc_collection' :
            return 'collection';
        case 'library_voc_doc_type' :
            return 'document_type';
        case 'library_voc_groupe' :
            return 'group';
        default :
            return false;
    }
}