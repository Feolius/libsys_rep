<?php
/**
 * @file
 * Library admin copyright block content type template.
 */

?>
<?php if (!empty($items['menu'])): ?>
  <h3><?php print $items['title']; ?></h3>
  <?php print drupal_render($items['menu']); ?>
<?php endif;?>
