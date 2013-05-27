<?php
/**
 * @file
 * Library admin user menu block content type template.
 */
?>
<?php if (!empty($menu)): ?>
  <div class="pane-user-menu">
    <ul class="menu">
      <?php foreach ($menu as $item): ?>
        <li><?php print $item; ?></li>
      <?php endforeach; ?>
    </ul>
  </div>
<?php endif;?>
