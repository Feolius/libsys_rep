<?php
/**
 * @file
 * Template for node files.
 */
?>
<div id="node-<?php print $node->nid; ?>"class="node-<?php print $node->type; ?>" <?php print $attributes; ?>>
  <?php if (!empty($content['field_files_rating'])) : ?>
    <?php print drupal_render($content['field_files_rating']); ?>
  <?php endif; ?>
  <div class="panel-separator"></div>
  <?php if (!empty($output)): ?>
    <?php foreach($output as $value): ?>
      <?php print drupal_render($value); ?>
    <?php endforeach; ?>
  <?php endif; ?>
</div>
