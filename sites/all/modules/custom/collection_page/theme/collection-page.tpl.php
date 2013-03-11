<div id="collection_page_tabs">
    <ul>
        <?php foreach ($elements as $element): ?>
        <li><a href= <?php print '#tab-' . $element['#id']; ?>><?php print $element['#title'];?></a></li>
        <?php endforeach; ?>
    </ul>
    <?php foreach ($elements as $element): ?>
    <div id= <?php print 'tab-' . $element['#id']; ?> >
        <?php foreach ($element['#content'] as $content): ?>
        <?php print $content; ?>
        <?php endforeach; ?>
    </div>
    <?php endforeach; ?>
</div>