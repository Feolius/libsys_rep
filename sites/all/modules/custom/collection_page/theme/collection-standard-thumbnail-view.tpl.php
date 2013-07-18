<div id="collection-standard-thumbnail-view-container">
  <div id="collection-thumbnail-upper-container">
    <a id="collection-upper-thumbnail-link" href="">
      <img id="collection-upper-thumbnail" src="">
    </a>
    <div id="collection-thumbnail-metainfo"></div>
  </div>
  <?php foreach ($collection_thumbnails as $collection_thumbnail): ?>
    <div class="collection-thumbnail-container">
      <img class="collection-thumbnail" src=" <?php print $collection_thumbnail['thumbnail_url'] ?>" style="height:<?php print $collection_thumbnail['height']?>px;">
      <div class="collection-thumbnail-metainfo"><?php print $collection_thumbnail['meta_info'] ?></div>
      <input class="collection-thumbnail-node-link" type="hidden" value="<?php print $collection_thumbnail['node_link'] ?>">
    </div>
  <?php endforeach ?>
</div>
<?php print $pager; ?>
