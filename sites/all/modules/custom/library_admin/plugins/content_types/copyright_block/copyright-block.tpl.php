<?php
/**
 * @file
 * Library admin copyright block content type template.
 */
?>
<?php
	if (!empty($copyright_path)) {
		print '<a href="' . $copyright_path . '">';
	}
	if (!empty($copyright_text)) {
		print $copyright_text;
	}
	if (!empty($copyright_path)) {
		print '</a>';
	}
?>