<?php
/**
 * @file
 * Library admin copyright block content type template.
 */

?>
<?php if (!empty($items['menu'])): ?>
  <h3><?php print $items['title']; ?></h3>
  <div id="faq-menu">
    <?php print drupal_render($items['menu']); ?>
  </div>
<?php endif;?>
