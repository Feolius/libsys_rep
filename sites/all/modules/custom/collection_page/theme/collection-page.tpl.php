<div id="collection_page_tabs">
    <ul>
        <?php foreach ($elements as $element): ?>
        <li><a href=<?php print '#tab-' . $element['#id'] ?>><?php print $element['#title']?></a></li>
        <? endforeach; ?>
    </ul>
    <?php foreach ($elements as $element): ?>
    <div id=<?php print 'tab-' . $element['#id'] ?>>
        <?foreach ($element['#content'] as $content): ?>
        <?php print $content ?>
        <? endforeach; ?>
    </div>
    <? endforeach; ?>
</div>
