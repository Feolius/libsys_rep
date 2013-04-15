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
      <?php if (!empty($content['header_left']) || !empty($content['header_right'])): ?>
      <div id="header">
        <div id="header-inside">
          <?php if (!empty($content['header_left'])): ?>
            <div id="header-inside-left">
              <?php print $content['header_left']; ?>
            </div>
          <?php endif; ?>
          <?php if (!empty($content['header_search_block'])): ?>
            <div id="header-inside-right">
              <?php print $content['header_search_block']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
       <?php endif; ?>

      <?php if ($content['content']): ?>
        <!-- Content. -->
        <div id="content">
          <div id="content-inside" class="inside">
            <?php print $content['content']; ?>
          </div><!-- EOF: #content-inside -->
          <!-- EOF: #content -->
        </div>
      <?php endif; ?>

      <?php if ($content['right_sidebar']): ?>
        <?php print $content['right_sidebar']; ?>
      <?php endif; ?>
      <?php if (!empty($content['footer'])): ?>
        <div id="footer-bottom">
          <div id="footer-bottom-inside">
            <?php print $content['footer']; ?>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div>
