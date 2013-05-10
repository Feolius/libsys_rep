<div id='toolbar1' class='flexpaper_toolbar flexpaper_toolbarstd'>
  <img src='<?php print $image_path . 'print-icon.gif'; ?>' class='flexpaper_tbbutton flexpaper_bttnPrint' title='Print' alt='Print' onclick='$FlexPaper("<?php print $viewer_id; ?>").printPaper();' />
  <img src='<?php print $image_path . 'bar.gif'; ?>' class='flexpaper_tbseparator' alt='' />
  <img src='<?php print $image_path . 'singlepage.gif'; ?>' border='0' class='flexpaper_bttnSinglePage flexpaper_tbbutton_pressed flexpaper_tbbutton flexpaper_tbbutton_viewmode flexpaper_viewmode' onclick='$FlexPaper("<?php print $viewer_id; ?>").switchMode("Portrait")' title='Single Page' alt='Single Page' />
  <img src='<?php print $image_path . 'twopage.gif'; ?>' border='0' class='flexpaper_bttnTwoPage flexpaper_tbbutton flexpaper_tbbutton_viewmode flexpaper_viewmode' title='Two Pages' alt='Two Pages' onclick='$FlexPaper("<?php print $viewer_id; ?>").switchMode("TwoPage")'  />
  <img src='<?php print $image_path . 'thumbs.gif'; ?>' border='0' class='flexpaper_bttnThumbView flexpaper_tbbutton flexpaper_tbbutton_viewmode flexpaper_viewmode' title='Thumb View' alt='Thumb View' onclick='$FlexPaper("<?php print $viewer_id; ?>").switchMode("Tile")'  />
  <img src='<?php print $image_path . 'fit.gif'; ?>' class='flexpaper_bttnFitWidth flexpaper_tbbutton flexpaper_tbbutton_fitmode flexpaper_fitmode' title='Fit Width' alt='Fit Width' onclick='$FlexPaper("<?php print $viewer_id; ?>").fitWidth()'  />
  <img src='<?php print $image_path . 'pagefit.gif'; ?>' class='flexpaper_bttnFitHeight flexpaper_tbbutton flexpaper_tbbutton_fitmode flexpaper_fitmode' title='Fit Page' alt='Fit Page' onclick='$FlexPaper("<?php print $viewer_id; ?>").fitHeight()'  />
  <img src='<?php print $image_path . 'flip.gif'; ?>' class='flexpaper_tbbutton' title='Rotate' alt='Rotate' onclick='$FlexPaper("<?php print $viewer_id; ?>").rotate()'  />
  <img src='<?php print $image_path . 'bar.gif'; ?>' class='flexpaper_tbseparator' alt='' />
  <div class='flexpaper_slider flexpaper_zoomSlider'><div class='flexpaper_handle'></div></div>
  <input type='text' class='flexpaper_tbtextinput flexpaper_txtZoomFactor' style='width:36px;' />
  <img src='<?php print $image_path . 'fullscreen.gif'; ?>' class='flexpaper_bttnFullScreen flexpaper_tbbutton' title='Fullscreen' alt='Fullscreen' onclick='jQuery("#<?php print $viewer_id; ?>").showFullScreen();'  />
  <img src='<?php print $image_path . 'bar.gif'; ?>' class='flexpaper_tbseparator' alt='' />
  <img src='<?php print $image_path . 'icon-arrow-left.gif'; ?>' class='flexpaper_bttnPrevPage flexpaper_tbbutton' onclick='$FlexPaper("<?php print $viewer_id; ?>").prevPage()' title='Previous Page' alt='Previous Page'/>
  <input type='text' class='flexpaper_txtPageNumber flexpaper_tbtextinput' style='width:36px;' />
  <div class='flexpaper_lblTotalPages flexpaper_tblabel'> / </div>
  <img src='<?php print $image_path . 'icon-arrow-right.gif'; ?>' class='flexpaper_bttnPrevNext flexpaper_tbbutton' onclick='$FlexPaper("<?php print $viewer_id; ?>").nextPage()' title='Next Page' alt='Next Page'/>
  <img src='<?php print $image_path . 'bar.gif'; ?>' class='flexpaper_tbseparator' alt='' />
  <img src='<?php print $image_path . 'textselect.gif'; ?>' class='flexpaper_bttnTextSelect flexpaper_tbbutton' title='Select Text' alt='Select Text' onclick="$FlexPaper('<?php print $viewer_id; ?>').setCurrentCursor('TextSelectorCursor')"/>
  <img src='<?php print $image_path . 'hand2.gif'; ?>' class='flexpaper_bttnHand flexpaper_tbbutton flexpaper_tbbutton_pressed' title='Drag Cursor' alt='Drag Cursor'  onclick="$FlexPaper('<?php print $viewer_id; ?>').setCurrentCursor('ArrowCursor')"/>
  <img src='<?php print $image_path . 'bar.gif'; ?>' class='flexpaper_tbseparator' alt='' />
  <input type='text' class='flexpaper_txtSearch flexpaper_tbtextinput' style='width:56px;margin-left:4px;' />
  <img src='<?php print $image_path . 'find.gif'; ?>' class='flexpaper_bttnTextSearch flexpaper_tbbutton' onclick='$FlexPaper("<?php print $viewer_id; ?>").searchText(jQuery(this).parent().find(".flexpaper_txtSearch").val());' title='Search' alt='Search'/>
  <img src='<?php print $image_path . 'bar.gif'; ?>' class='flexpaper_tbseparator' alt='' />
  <img src='<?php print $image_path . 'loader.gif'; ?>' class='flexpaper_progress flexpaper_tbloader' alt='' />
</div>