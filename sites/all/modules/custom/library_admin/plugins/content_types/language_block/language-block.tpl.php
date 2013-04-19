<?php
/**
 * @file
 * Library admin languages block content type template.
 */
?>
<?php if (!empty($results)): ?>
  <div class="languages">
    <?php foreach($results as $result): ?>
      <?php print $result; ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
