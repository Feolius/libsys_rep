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
//kpr($content);die;
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
  <?php if (!empty($content['sidebar_right'])): ?>
    <div id="sidebar">
      <?php print $content['sidebar_right']; ?>
    </div>
  <?php endif; ?>
</div>
