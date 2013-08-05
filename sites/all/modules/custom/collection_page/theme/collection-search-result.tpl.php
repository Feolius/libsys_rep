<li
  class="<?php print $classes . ' collection-page-clearfix'; ?>"<?php print $attributes; ?>>
  <?php if ($image): ?>
    <div class="collection-page-search-result-thumbnail-image">
      <?php print $image; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($snippet)): ?>
    <div
      class="collection-page-search-result-snippet"<?php print $content_attributes; ?>>
      <h3 class="collection-page-search-result-title"<?php print $title_attributes; ?>>
        <?php print l(t($title), $url) ?>
      </h3>
      <?php print $snippet; ?>
    </div>
  <?php endif; ?>
</li>
<li style="clear:both"></li>
