<?php
/**
 * @file
 * Library admin node list content type template.
 */
?>
<?php if (!empty($nodes)): ?>
  <?php print drupal_render($nodes); ?>
<?php endif;?>
