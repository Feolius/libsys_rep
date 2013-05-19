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
<?php drupal_add_css(drupal_get_path('theme', 'corporateclean') . '/tweet_button.css')?>
  <div class="page">
    <div class="panel-panel panel-main">

      <?php if (!empty($content['top'])): ?>
        <!-- Top. -->
          <?php print $content['top']; ?>
        <!-- EOF: #top -->
       <?php endif; ?>

      <?php if ($content['bottom']): ?>
        <!-- Bottom. -->
          <?php print $content['bottom']; ?>
        <!-- EOF: #bottom -->
      <?php endif; ?>

    </div>
  </div>
