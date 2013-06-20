<li class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($image): ?>
    <div class="collection-page-search-result-thumbnail-image">
      <?php print $image; ?>
    </div>
  <?php endif; ?>
  <?php print render($title_prefix); ?>
  <h3 class="collection-page-search-result-title"<?php print $title_attributes; ?>>
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </h3>
  <?php print render($title_suffix); ?>
    <?php if ($snippet): ?>
      <p class="collection-page-search-result-snippet"<?php print $content_attributes; ?>><?php print $snippet; ?></p>
    <?php endif; ?>
</li>
