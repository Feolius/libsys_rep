<div id="conten_layout_filter_block">
    <h2><?php print $elements['browsing']['#title'] ?></h2>
    <div class="collection_layout_sub_content">
        <?php foreach ($elements['browsing']['#content'] as $link): ?>
            <div><span><?php print $link ?></span></div>
        <?php endforeach; ?>
    </div>
    <h2><?php print $elements['publication_date_range']['#title'] ?></h2>
    <div id="collection_layout_date_range_slider"><?php print $elements['publication_date_range']['#content'] ?></div>
    <h2><?php print $elements['refine']['#title'] ?></h2>
    <div class="collection_layout_sub_content">
        <?php foreach ($elements['refine']['#content'] as $link): ?>
            <div><span><?php print $link ?></span></div>
        <?php endforeach; ?>
    </div>
    <?php foreach ($elements['filters'] as $filter): ?>
        <h2><?php print $filter['#title'] ?></h2>
        <div class="collection_layout_sub_content"><?php print $filter['#content'] ?></div>
    <?php endforeach; ?>
</div>