<?php
/**
 * @file
 * library_features_content_type_news_article.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_news_article_node_info() {
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
