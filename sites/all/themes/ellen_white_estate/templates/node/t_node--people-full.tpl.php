<?php
/**
 * @file
 * Template for node people.
 */
?>
<div id="node-<?php print $node->nid; ?>"class="node-<?php print $node->type; ?>" <?php print $attributes; ?>>
  <?php if (!empty($full_name_people)): ?>
    <h2 class="title">
      <?php print $full_name_people; ?>
    </h2>
  <?php endif; ?>
  <?php if (!empty($content['field_rating'])): ?>
    <div class="fivestar-rating">
      <?php print drupal_render($content['field_rating']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['field_people_image'])): ?>
    <h2 class="image">
      <?php print drupal_render($content['field_people_image']); ?>
    </h2>
  <?php endif; ?>
  <?php if (!empty($content['field_people_description'])): ?>
    <div class="description">
      <?php print drupal_render($content['field_people_description']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['field_people_birthday'])): ?>
    <?php print drupal_render($content['field_people_birthday']); ?>
  <?php endif; ?>
  <?php if (!empty($content['field_people_marriage_date'])): ?>
    <?php print drupal_render($content['field_people_marriage_date']); ?>
  <?php endif; ?>
  <?php if (!empty($content['field_people_children'])): ?>
    <?php print drupal_render($content['field_people_children']); ?>
  <?php endif; ?>
  <?php if (!empty($content['field_people_parents'])): ?>
    <?php print drupal_render($content['field_people_parents']); ?>
  <?php endif; ?>
</div>
