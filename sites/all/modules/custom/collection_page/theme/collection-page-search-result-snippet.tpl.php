<div class=<?php print 'snippet-type-' . $snippet_type; ?>>
  <?php foreach ($snippet_data as $element_class => $element): ?>
    <?php if (!empty($element['#data'])):  ?>
      <div class=<?php print $element_class; ?>>
        <?php if ($element['#label']): ?>
          <label class="snippet-field-label"""><?php print $element['#label'] . ':'; ?> </label>
      <?php endif; ?>
        <div class="snippet-field-data">
          <?php print $element['#data']; ?>
        </div>
      </div>
    <?php endif; ?>
  <?php endforeach; ?>
</div>

