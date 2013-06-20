<div class=<?php print 'snippet-type-' . $snippet_type; ?>>
  <?php foreach ($snippet_data as $element_class => $element): ?>
    <div class=<?php print $element_class; ?>>
      <?php if ($element['#label']): ?>
        <label><?php print $element['#label'] . ':'; ?> </label>
      <?php endif; ?>
      <?php print $element['#data']; ?>
    </div>
  <?php endforeach; ?>
</div>

