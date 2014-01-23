<div id="collection_page_tabs">
  <ul>
    <?php foreach ($content as $view): ?>
      <li id=<?php print 'tab-button-' . $view['#id']; ?>><a
          href=<?php print '#tab-' . $view['#id']; ?> class=<?php print $view['#class']; ?>
          ><?php print $view['#title']; ?></a>
      </li>
    <?php endforeach; ?>
  </ul>
  <?php foreach ($content as $view): ?>
    <div id=<?php print 'tab-' . $view['#id']; ?>>
      <?php if (isset($view['#content'])): ?>
        <?php foreach ($view['#content'] as $view_content): ?>
          <?php if ($bundle): ?>
            <h3><?php print $bundle; ?></h3>
          <?php else: ?>
            <h3><?php print t("Library"); ?></h3>
          <?php endif; ?>
          <?php print $view_content; ?>
        <?php endforeach; ?>
      <?php endif;?>
    </div>
  <?php endforeach; ?>
</div>