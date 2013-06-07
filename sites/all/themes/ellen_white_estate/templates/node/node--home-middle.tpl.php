<?php
/**
 * @file
 * Template for node home view mode.
 */
?>
<div id="node-<?php print $node->nid; ?>"class="node-<?php print $node->type; ?>" <?php print $attributes; ?>>
  <?php print render($content); ?>
</div>
