<?php

require_once 'collection_layout_filters.inc';

class collection_layout_handler_field_taxonomy extends views_handler_field_taxonomy {

    function render_link($data, $values) {
        $tid = $this->get_value($values, 'tid');
        $filter_name = false;
        if (!empty($this->options['link_to_taxonomy']) && !empty($tid) && $data !== NULL && $data !== '') {
            $term = new stdClass();
            $term->tid = $tid;
            $term->vid = $this->get_value($values, 'vid');
            $term->vocabulary_machine_name = $values->{$this->aliases['vocabulary_machine_name']};
            $this->options['alter']['make_link'] = TRUE;
            $uri = entity_uri('taxonomy_term', $term);
            $filter_name = collection_layout_get_filter_machine_name($term->vocabulary_machine_name);
            if ($filter_name) {
                $path = "collection?{$filter_name}={$term->tid}";
                $this->options['alter']['path'] = $path;
            } else
                $this->options['alter']['path'] = $uri['path'];
        }

        if (!empty($this->options['convert_spaces'])) {
            $data = str_replace(' ', '-', $data);
        }
        $filter_list = collection_layout_get_enable_filters_list();
        if ($filter_list) {
            if (isset($filter_list[$filter_name]) && in_array($tid, $filter_list[$filter_name]))
                $data .= '[X]';
        }
        return $data;
    }

}
