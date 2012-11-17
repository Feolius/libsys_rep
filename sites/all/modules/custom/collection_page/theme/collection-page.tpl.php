<div id="collection_page_tabs">
    <ul>
        <li><a href="#tabs-1"><?php print $elements['#timeline']['#title']?></a></li>
        <li><a href="#tabs-2"><?php print $elements['#location']['#title']?></a></li>
        <li><a href="#tabs-3"><?php print $elements['#standart']['#title']?></a></li>

    </ul>
    <div id="tabs-1"><?php print $elements['#timeline']['#content']['#timeline_iframe']?></div>
    <div id="tabs-2"><?php print $elements['#location']['#content']['#location_view']?></div>
    <div id="tabs-3"><?php print $elements['#standart']['#content']['#standart_view']?></div>
</div>

