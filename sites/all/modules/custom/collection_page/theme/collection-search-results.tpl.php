<?php if ($search_results): ?>
  <ol class="collection-search-results-">
    <?php print $search_results; ?>
  </ol>
  <?php if ($more_link): ?>
<?php print $more_link ?>
<?php else: ?>
<?php print $pager ?>
  <?php endif; ?>
<?php else : ?>
  <h2><?php print t('Your search yielded no results'); ?></h2>
  <?php print search_help('search#noresults', drupal_help_arg()); ?>
<?php endif; ?>

