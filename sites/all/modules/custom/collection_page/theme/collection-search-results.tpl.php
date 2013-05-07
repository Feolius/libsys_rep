<?php if ($search_results): ?>
  <ol class="collection-search-results-">
    <?php print $search_results; ?>
  </ol>
  <div id="collection-pager-container">
    <?php print $pager ?>
  </div>
<?php else : ?>
  <h2><?php print t('Your search yielded no results'); ?></h2>
  <?php print search_help('search#noresults', drupal_help_arg()); ?>
<?php endif; ?>

