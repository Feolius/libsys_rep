<div id="collection-standart-thumbnail-view-container">
  <div id="collection-thumbnail-upper-container">
    <img id="collection_upper_thumbnail" src="">
    <div id="collection-thumbnail-metainfo"></div>
  </div>
  <?php foreach($collection_thumbnails as $collection_thumbnail): ?>
  <div class="collection-thumbnail-container">
    <img class="collection-thumbnail" src=" <?php print $collection_thumbnail['thumbnail_url'] ?>" >
    <div class="collection-thumbnail-metainfo"><?php print $collection_thumbnail['meta_info'] ?></div>
  </div>
  <?php endforeach ?>
</div>

