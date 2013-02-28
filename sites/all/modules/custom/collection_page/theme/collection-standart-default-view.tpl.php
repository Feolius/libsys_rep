<div id="collection-standart-default-view">
  <div id="colection-search-results-accordion">
    <?php foreach($results_content as $bundle => $bundle_results): ?>
    <h3><?php print $bundle ?></h3>
    <div>
      <p><?php print $bundle_results ?></p>
    </div>
    <?php endforeach ?>
  </div>
</div>