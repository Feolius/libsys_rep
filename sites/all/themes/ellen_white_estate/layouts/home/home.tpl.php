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
  <div class="page">
    <div class="panel-panel panel-main">

      <?php if (!empty($content['top'])): ?>
        <!-- Top. -->
          <div id="home-top">
            <?php print $content['top']; ?>
          </div>
        <!-- EOF: #top -->
      <?php endif; ?>

      <?php if (!empty($content['left'])): ?>
        <!-- Left. -->
          <div id="home-left">
            <?php print $content['left']; ?>
          </div>
        <!-- EOF: #left -->
      <?php endif; ?>

      <?php if (!empty($content['middle'])): ?>
        <!-- Middle. -->
          <div id="home-middle">
            <?php print $content['middle']; ?>
          </div>
        <!-- EOF: #middle -->
      <?php endif; ?>

      <?php if (!empty($content['right'])): ?>
        <!-- Right. -->
          <div id="home-right">
            <?php print $content['right']; ?>
          </div>
        <!-- EOF: #right -->
      <?php endif; ?>
      </div>

      <?php if ($content['bottom']): ?>
        <!-- Bottom. -->
          <div id="home-right">
            <?php print $content['bottom']; ?>
          </div>
        <!-- EOF: #bottom -->
      <?php endif; ?>
  </div>
</div>
