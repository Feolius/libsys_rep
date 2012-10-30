<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="collection_layout_grid_content">
    <?php foreach ($rows as $row_number => $columns): ?>
        <?php foreach ($columns as $column_number => $item): ?>
    <?php if($item != '') : ?>
    <div class="collection_layout_grid_cell_shell">
        <div class="collection_layout_grid_cell"><?php print $item; ?></div>
        </div>
    <?php endif; ?>
        <?php endforeach; ?>
    <?php endforeach; ?>
</div>