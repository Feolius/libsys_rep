<div id='toolbar1' class='flexpaper_toolbar flexpaper_toolbarios'>
  <img src='<?php print $image_path . 'touch/print.png'; ?>' class='flexpaper_bttnPortrait flexpaper_tbbutton_large flexpaper_print' style='margin-left:5px;' onclick='$FlexPaper("<?php print $viewer_id; ?>").printPaper();'/>
  <img src='<?php print $image_path . 'touch/document.png'; ?>' class='flexpaper_tbbutton_large flexpaper_tbbutton_viewmode  flexpaper_singlepage' style='margin-left:15px;' onclick='$FlexPaper("<?php print $viewer_id; ?>").switchMode("Portrait")'>
  <img src='<?php print $image_path . 'touch/twodocuments.png'; ?>' style='margin-left:-1px;' class='flexpaper_bttnTwoPage flexpaper_tbbutton_large flexpaper_tbbutton_viewmode flexpaper_twopage' onclick='$FlexPaper("<?php print $viewer_id; ?>").switchMode("TwoPage")' >
  <img src='<?php print $image_path . 'touch/thumbs.png'; ?>' style='margin-left:-1px;' class='flexpaper_bttnTileMode flexpaper_tbbutton_large flexpaper_tbbutton_viewmode flexpaper_thumbview' onclick='$FlexPaper("<?php print $viewer_id; ?>").switchMode("Tile")' >
  <img src='<?php print $image_path . 'touch/zoomin.png'; ?>' class='flexpaper_bttnZoomIn flexpaper_tbbutton_large' style='margin-left:15px;' onclick='$FlexPaper("<?php print $viewer_id; ?>").Zoom(2)'/>
  <img src='<?php print $image_path . 'touch/zoomout.png'; ?>' class='flexpaper_bttnZoomOut flexpaper_tbbutton_large' style='margin-left:-1px;' onclick='$FlexPaper("<?php print $viewer_id; ?>").Zoom(1)' />
  <img src='<?php print $image_path . 'touch/fullscreen.png'; ?>' class='flexpaper_bttnFullScreen flexpaper_tbbutton_large' style='margin-left:-1px;' onclick='showFullScreen("<?php print $viewer_id; ?>");'/>
  <img src='<?php print $image_path . 'touch/prev.png'; ?>' class='flexpaper_bttnPrevPage flexpaper_tbbutton_large flexpaper_previous' style='margin-left:15px;' onclick='$FlexPaper("<?php print $viewer_id; ?>").prevPage()'/>
  <input type='text' class='flexpaper_txtPageNumber flexpaper_tbtextinput_large flexpaper_currPageNum' value='1' style='width:80px;text-align:right;' />
  <div class='flexpaper_lblTotalPages flexpaper_tblabel_large flexpaper_numberOfPages'> / </div>
  <img src='<?php print $image_path . 'touch/next.png'; ?>'  class='flexpaper_bttnNextPage flexpaper_tbbutton_large flexpaper_next' onclick='$FlexPaper("<?php print $viewer_id; ?>").nextPage()'/>
  <input type='text' class='flexpaper_txtSearchText flexpaper_tbtextinput_large' style='margin-left:15px;width:130px;' />
  <img src='<?php print $image_path . 'touch/search.png'; ?>' class='flexpaper_bttnTextSearch flexpaper_find flexpaper_tbbutton_large' style='' onclick='searchText()' />
</div>