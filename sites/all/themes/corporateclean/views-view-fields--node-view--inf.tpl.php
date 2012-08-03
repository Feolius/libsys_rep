<?php $count = 0; foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>
  <?php if($count == 0) print '<div class="collection_layout_node_leftbar">';?>
  <?php if($count == 2) print '</div> <div class="collection_layout_node_rightbar">';?>
  <?php print $field->wrapper_prefix; ?>
    <div class="collection_layout_term_label"><?php print $field->label_html; ?></div>
    <?php print $field->content; ?>
  <?php print $field->wrapper_suffix; ?>
    <?php if($count == count($fields) - 1) print '</div>'; $count++?>
<?php endforeach; ?>