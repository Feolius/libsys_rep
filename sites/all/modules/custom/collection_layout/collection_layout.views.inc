<?php

function collection_layout_views_data_alter(&$data) {
    $data['taxonomy_term_data']['name']['field'] = array(
        'handler' => 'collection_layout_handler_field_taxonomy',
        'click sortable' => TRUE,
    );
}

function collection_layout_views_pre_render(&$view) {
    if ($view->name == 'timeline_json_view' && $view->current_display == 'timeline_json') {
        $_SESSION['collection_layout']['json']['date'] = array();
        $_SESSION['collection_layout']['json']['title'] = array();
        $_SESSION['collection_layout']['json']['text'] = array();
        $_SESSION['collection_layout']['json']['image_url'] = array();
        $_SESSION['collection_layout']['json']['nid'] = array();

        foreach ($view->result as $row) {
            $tmp = explode('-', $row->field_field_files_date[0]['raw']['value']);
            $_SESSION['collection_layout']['json']['date'][] = $tmp[0];
            $_SESSION['collection_layout']['json']['title'][] = $row->_field_data['nid']['entity']->title;
            $_SESSION['collection_layout']['json']['text'][] = l('read more', 'node-page', array('query' => array('nid' => $row->nid), 'attributes' => array('target' => '_parent')));
            if (isset($row->field_field_files_image[0]))
                $_SESSION['collection_layout']['json']['image_url'][] = image_style_url('thumbnail', $row->field_field_files_image[0]['raw']['uri']);
            $_SESSION['collection_layout']['json']['nid'][] = $row->nid;
        }
    }
}

function collection_layout_views_query_alter(&$view, &$query) {
    if ($view->name == 'node_view') {
        if ($view->current_display == 'node_prev')
            $query->where[0]['conditions'][0]['field'] = 'node.nid < :node_nid6';
        if ($view->current_display == 'node_next')
            $query->where[0]['conditions'][0]['field'] = 'node.nid > :node_nid7';
    }
}
