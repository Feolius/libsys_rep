<?php
/**
 * @file
 * features_library_ct_news_article.features.inc
 */

/**
 * Implements hook_node_info().
 */
function features_library_ct_news_article_node_info() {
  $items = array(
    'news_article' => array(
      'name' => t('News Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
