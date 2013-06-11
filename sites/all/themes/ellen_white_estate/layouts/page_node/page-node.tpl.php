<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a very simple "one column" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['middle']: The only panel in the layout.
 */
?>
<div class="panel-panel panel-node">
  <?php if (!empty($content['breadcrumb']) || !empty($content['content'])) : ?>
    <div id="main">
      <?php if (!empty($content['breadcrumb'])): ?>
        <?php print $content['breadcrumb']; ?>
      <?php endif; ?>
      <?php if (!empty($content['content'])): ?>
        <div class="main_inside">
          <?php print $content['content']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['right_sidebar'])): ?>
    <div id="sidebar">
      <?php print $content['right_sidebar']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['bottom'])): ?>
    <div class="bottom">
      <?php print $content['bottom']; ?>
    </div>
  <?php endif; ?>
</div>
