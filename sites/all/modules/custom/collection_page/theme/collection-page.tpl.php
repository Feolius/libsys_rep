<div id="collection-page-views">
<div id="collection_page_tabs">
  <ul>
    <?php foreach ($content as $view): ?>
      <li><a id=<?php print 'tab-button-' . $view['#id']; ?> href= <?php print '#tab-' . $view['#id']; ?>><?php print $view['#title'];?></a></li>
    <?php endforeach; ?>
  </ul>
  <?php foreach ($content as $view): ?>
    <div id=<?php print 'tab-' . $view['#id']; ?>>
      <?php foreach ($view['#content'] as $view_content): ?>
        <?php print $view_content; ?>
      <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</div>
<div id="library-standard-view-types">
    <div id="library-standard-view-default-type" class="library-standard-view-type" link="<?php print $default_url?>" >Default</div>
    <div id="library-standard-view-thumbnail-type" class="library-standard-view-type" link="<?php print $thumbnail_url?>">Thumbnail</div>
</div>
</div>