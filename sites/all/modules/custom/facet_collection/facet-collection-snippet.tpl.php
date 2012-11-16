<?php

/**
 * Template file for search result snippets un facet collection page
 */
?>

<?php if (isset($image_path)): ?>
<div class="facet-collection-snippet-thumb">
    <img src= <?php print $image_path ?>>
</div>
<?php endif; ?>
<?php if (isset($text)): ?>
<div class="facet-collection-snippet-text">
     <?php print t($text) ?>
</div>
<?php endif; ?>
