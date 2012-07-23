<?php

function collection_layout_views_data_alter(&$data) {
    $data['taxonomy_term_data']['name']['field'] = array(
        'handler' => 'collection_layout_handler_field_taxonomy',
        'click sortable' => TRUE,
    );
}

function collection_layout_views_pre_render(&$view) {
    
    if ($view->name == 'node_view' && $view->current_display == 'page' && isset($_SESSION['collection_layout']['nid'])) {
        if (!isset($_SESSION['collection_layout']['view_result']))
            $_SESSION['collection_layout']['view_result'] = $view->result;
        $tmp = array();
        foreach ($_SESSION['collection_layout']['view_result'] as $row) {
            if ($row->nid == $_SESSION['collection_layout']['nid']) {
                $tmp[] = $row;
                break;
            }
        }
        $view->result = $tmp;
    }
    if($view->name == 'timeline_json_view' && $view->current_display == 'block_1'){
        $_SESSION['collection_layout']['json']['date'] = array();
        $_SESSION['collection_layout']['json']['title'] = array();
        $_SESSION['collection_layout']['json']['image_url'] = array();
        foreach ($view->result as $row) {
            $_SESSION['collection_layout']['json']['date'][] = $row->field_field_files_date[0]["rendered"]["#markup"];
            $_SESSION['collection_layout']['json']['title'] = '<h2>' . l($row->_field_data['nid']['entity']->title, 'node-page', array('query' => array('nid' => $row->nid))) . '</h2>';
        }
    }
}