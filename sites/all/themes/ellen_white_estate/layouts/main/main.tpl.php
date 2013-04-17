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

      <?php if (!empty($content['header_left']) || !empty($content['header_search_block'])): ?>
        <!-- Header. -->
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
        <!-- EOF: #header -->
       <?php endif; ?>

      <?php if (!empty($content['header_menu'])): ?>
        <!-- Header menu. -->
        <div id="header-menu">
          <div id="header-menu-inside">
            <?php print $content['header_menu']; ?>
          </div>
        </div>
        <!-- EOF: #header-menu -->
      <?php endif; ?>

      <?php if ($content['content']): ?>
        <!-- Content. -->
        <div id="content">
          <div id="content-inside" class="inside">
            <div id="main">
              <?php print $content['content']; ?>
            </div>
            <!-- EOF: #content -->
          </div>
        </div>
      <?php endif; ?>

      <?php if (!empty($content['footer'])
        || !empty($content['footer_left'])
        || !empty($content['footer_right'])): ?>
        <!-- Footer. -->
        <div id="footer-bottom">
        <?php if (!empty($content['footer'])): ?>
          <div id="footer-bottom-inside">
            <?php print $content['footer']; ?>
            <?php if (!empty($content['footer_left'])): ?>
              <div id="footer-bottom-left">
                <?php print $content['footer_left']; ?>
              </div>
            <?php endif; ?>
            <?php if (!empty($content['footer_right'])): ?>
              <div id="footer-bottom-right">
                <?php print $content['footer_right']; ?>
              </div>
            <?php endif; ?>
          </div>
          <?php endif; ?>
        </div>
        <!-- EOF: #footer-bottom -->
      <?php endif; ?>
    </div>
  </div>
