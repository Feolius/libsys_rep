<?php
/**
 * @file
 * library_features_content_type_article.features.inc
 */

/**
 * Implements hook_node_info().
 */
function library_features_content_type_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}