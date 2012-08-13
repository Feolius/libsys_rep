<div id="collection_layout_tabs">
    <ul>
        <li><a href="#tabs-1"><?php print $elements['#information']['#title']?></a></li>
        <li><a href="#tabs-2"><?php print $elements['#image']['#title']?></a></li>
        <li><a href="#tabs-3"><?php print $elements['#media']['#title']?></a></li>
        <li><a href="#tabs-4"><?php print $elements['#text']['#title']?></a></li>
    </ul>
    <div id="tabs-1">
        <?php print $elements['#information']['#content']['#view']?>
        <?php print $elements['#information']['#content']['#timeline_iframe']?>
    </div>
    <div id="tabs-2"><?php print $elements['#image']['#content']['#view']?></div>
    <div id="tabs-3"><?php print $elements['#media']['#content']['#view']?></div>
    <div id="tabs-4">
        <div id="collection_layout_book_tabs">
            <ul>
                <li><a href="#tabs-1"><?php print $elements['#text']['#content']['file_link']['#title']?></a></li>
                <li><a href="#tabs-2"><?php print $elements['#text']['#content']['google_docs']['#title']?></a></li>
                <li><a href="#tabs-3"><?php print $elements['#text']['#content']['flexpaper']['#title']?></a></li>
            </ul>
            <div id="tabs-1"><?php print $elements['#text']['#content']['file_link']['#view']?></div>
            <div id="tabs-2"><?php print $elements['#text']['#content']['google_docs']['#view']?></div>
            <div id="tabs-3"><?php print $elements['#text']['#content']['flexpaper']['#view']?></div>    

        </div>
    </div>
</div>
<?php print $elements['#slider_links']['#left']?>
<?php print $elements['#slider_links']['#right']?>
