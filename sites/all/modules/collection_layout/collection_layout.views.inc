<?php

function collection_layout_views_data_alter(&$data) {
    $data['taxonomy_term_data']['name']['field'] = array(
        'handler' => 'collection_layout_handler_field_taxonomy',
        'click sortable' => TRUE,
    );
}

function collection_layout_views_pre_render(&$view) {
    if ($view->name == 'node_view' && 
            ($view->current_display == 'inf' || $view->current_display == 'image_deep_zoom' 
            || $view->current_display == 'media' || $view->current_display == 'book')
            && isset($_SESSION['collection_layout']['nid'])) {
        //if (!isset($_SESSION['collection_layout']['view_result']))
            $_SESSION['collection_layout']['view_result'] = $view->result;
        $tmp = array();
        foreach ($_SESSION['collection_layout']['view_result'] as $row) 
            if ($row->nid == $_SESSION['collection_layout']['nid']) {
                $tmp[] = $row;
                break;
            }
        $view->result = $tmp;
    }
    if($view->name == 'timeline_json_view' && $view->current_display == 'block_1'){
        
        $_SESSION['collection_layout']['json']['date'] = array();
        $_SESSION['collection_layout']['json']['title'] = array();
        $_SESSION['collection_layout']['json']['text'] = array();
        $_SESSION['collection_layout']['json']['image_url'] = array();
        $_SESSION['collection_layout']['json']['nid'] = array();
        
        foreach ($view->result as $row) {
            $tmp = explode('-', $row->field_field_files_date[0]['raw']['value']);
            $_SESSION['collection_layout']['json']['date'][] = $tmp[0];
            $_SESSION['collection_layout']['json']['title'][] = $row->_field_data['nid']['entity']->title;
            $_SESSION['collection_layout']['json']['text'][] = l('read more', 'node-page', 
                    array('query' => array('nid' => $row->nid), 'attributes' => array('target' => '_parent')));
            $_SESSION['collection_layout']['json']['image_url'][] = image_style_url('thumbnail', $row->field_field_files_image[0]['raw']['uri']);
            $_SESSION['collection_layout']['json']['nid'][] = $row->nid;  
        }
    }
}

