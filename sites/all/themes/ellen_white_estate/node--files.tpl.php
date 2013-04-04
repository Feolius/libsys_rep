<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted"><?php print $submitted ?></div>
  <?php endif; ?>

  <div class="content clearfix"<?php print $content_attributes; ?>>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
    ?>
        <?php if ($teaser):?>
            <?php print render($content);  ?>
        <?php else:?>
    <!-- Fivestar -->
    <div class="rating">
        <?php print render($content['field_files_rating']); ?>
    </div>
    <!-- end Fivestar -->

    <div class="section">

        <? if ($field_files_primary_media[0]['value'] == 'image'): ?>

    <div id="image_tabs">
        <?php if ($field_files_audio || $field_files_file['und']['0']['fid'] || $field_files_youtube_media): ?>
    <ul>
        <li><a href="#tab-image"><?php print t("Image");?></a></li>
        <?php if ($field_files_audio): ?>
        <li><a href="#tab-audio"><?php print t("Audio");?></a></li>
        <?endif;?>
        <?php if ($field_files_youtube_media): ?>
        <li><a href="#tab-video"><?php print t("Video");?></a></li>
        <?endif;?>
        <?php if ($field_files_file['und']['0']['fid']): ?>
        <li><a href="#tab-document"><?php print t("Document");?></a></li>
        <?endif;?>
    </ul>
        <?endif;?>

    <!-- Image tab -->
    <div id="tab-image">
        <?php print render($content['field_files_image']); ?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']);?>

        <?endif;?>

        <div class="additional-info">
            <?php if ($field_files_author): ?>
            <div class="info-label"><?php print t("People");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
            <?endif;?>
            <?php if ($field_files_author_location): ?>
            <div class="info-label"><?php print t("Location");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
            <?endif;?>
            <?php if ($field_fields_photographer): ?>
            <div class="info-label"><?php print t("Photographer");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_fields_photographer[0]['target_id'])?>"><?php print render($content['field_fields_photographer']); ?></a>
            <?endif;?>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Date taken");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
        </div>
    </div>
    <!-- end Image tab -->

    <!-- Audio tab -->
        <?php if ($field_files_audio): ?>
    <div id="tab-audio">
        <?php if ($field_files_album_poster): ?>
        <style>
            .field-name-field-files-audio .jp-interface {
                width: 520px;
                margin-left: 120px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-progress,
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-current-time,
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-duration{
                width: 320px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single a.jp-mute,
            .field-name-field-files-audio .jp-audio .jp-type-single a.jp-unmute{
                left: 435px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-volume-bar {
                left: 460px;
            }
        </style>
        <div class="album-cover">
            <?php print render($content['field_files_album_poster']); ?>
        </div>
        <?endif;?>
        <?php print render($content['field_files_audio']); ?>
        <div class="audio-download">
            <a href="<?print file_create_url($field_files_audio[0]['uri']);?>"><?php print t("Download");?></a>
        </div>
        <div class="audio-meta">
            <?php if ($field_files_artist): ?>
            <div class="info-label"><?php print t("Artist");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_artist[0]['target_id'])?>"><?php print render($content['field_files_artist']); ?></a>
            <?endif;?>
            <?php if ($field_files_year): ?>
            <div class="info-label"><?php print t("Year");?>:</div>
            <?php print render($content['field_files_year']); ?>
            <?endif;?>
            <?php if ($field_files_length): ?>
            <div class="info-label"><?php print t("Length");?>:</div>
            <?php print render($content['field_files_length']); ?>
            <?endif;?>
            <?php if ($field_files_topics): ?>
            <div class="info-label"><?php print t("Topics");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_topics[0]['target_id'])?>"><?php print render($content['field_files_topics']); ?></a>
            <?endif;?>
        </div>
    </div>
        <?endif;?>
    <!-- end Audio tab -->

    <!-- Video tab -->
        <?php if ($field_files_youtube_media): ?>
    <div id="tab-video">
        <?php print render($content['field_files_youtube_media']); ?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>

        <div class="additional-info">
            <?php if ($field_files_author): ?>
            <div class="info-label"><?php print t("People");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
            <?endif;?>
            <?php if ($field_files_author_location): ?>
            <div class="info-label"><?php print t("Location");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
            <?endif;?>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Date taken");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
        </div>
    </div>
        <?endif;?>
    <!-- end Video tab -->

    <!-- Document tab -->
        <?php if ($field_files_file['und']['0']['fid']): ?>
    <div id="tab-document">
        <?php if ($field_files_subtitle): ?>
        <h2><?php print render($content['field_files_subtitle']); ?></h2>
        <?endif;?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>
        <?php if ($field_files_key_points): ?>
        <?php print render($content['field_files_key_points']); ?>
        <?endif;?>
        <div id="docs_tabs">
            <?php if ($field_files_text): ?>
            <ul>
                <li><a href="#tab-text"><?php print t("Text");?></a></li>
                <li><a href="#tab-original"><?php print t("Original");?></a></li>
            </ul>
            <div id="tab-text">
                <?php print render($content['field_files_text']); ?>
            </div>
            <?endif;?>
            <div id="tab-original">
                <?php print render($content['field_files_file']); ?>
            </div>
        </div>
        <div class="document-section1">
            <?php if ($field_files_author): ?>
            <p class="author"><?php print t("Author");?></p>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
            <?php if ($field_files_author_location): ?>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
                <?endif;?>
            <?endif;?>
            <?php if ($field_files_receiver): ?>
            <p class="author"><?php print t("Receiver");?></p>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver[0]['target_id'])?>"><?php print render($content['field_files_receiver']); ?></a>
            <?php if ($field_files_receiver_location): ?>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver_location[0]['target_id'])?>"><?php print render($content['field_files_receiver_location']); ?></a>
                <?endif;?>
            <?endif;?>
            <div class="clear"></div>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Creation date");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
            <?php if ($field_files_topics): ?>
            <div class="info-label"><?php print t("Topics");?>:</div>
            <?php print render($content['field_files_topics']); ?>
            <?endif;?>
            <?php if ($field_files_collection): ?>
            <?php print render($content['field_files_collection']); ?>
            <?endif;?>
        </div>
        <div class="document-section2">
            <?php if ($field_files_folder): ?>
            <?php print render($content['field_files_folder']); ?>
            <?endif;?>
            <?php if ($field_files_original_title): ?>
            <?php print render($content['field_files_original_title']); ?>
            <?endif;?>
            <?php if ($field_files_publication): ?>
            <?php print render($content['field_files_publication']); ?>
            <?endif;?>
        </div>
        <h3><?php print t("Source");?>:</h3>
        <div class="document-section3">
            <?php if ($field_files_source_title): ?>
            <?php print render($content['field_files_source_title']); ?>
            <?endif;?>
            <?php if ($field_files_source_volume): ?>
            <?php print render($content['field_files_source_volume']); ?>
            <?endif;?>
            <?php if ($field_files_source_number): ?>
            <?php print render($content['field_files_source_number']); ?>
            <?endif;?>
            <?php if ($field_files_source_chapter): ?>
            <?php print render($content['field_files_source_chapter']); ?>
            <?endif;?>
            <?php if ($field_files_source_page): ?>
            <?php print render($content['field_files_source_page']); ?>
            <?endif;?>
        </div>
        <?php if ($field_files_notes): ?>
        <?php print render($content['field_files_notes']); ?>
        <?endif;?>
    </div>
        <?endif;?>
    <!-- end Document tab -->
    </div>

        <?elseif($field_files_primary_media[0]['value'] == 'video'):?>
    <div id="image_tabs">
        <?php if ($field_files_audio || $field_files_file['und']['0']['fid'] || $field_files_image): ?>
    <ul>
        <li><a href="#tab-video"><?php print t("Video");?></a></li>
        <?php if ($field_files_image): ?>
        <li><a href="#tab-image"><?php print t("Image");?></a></li>
        <?endif;?>
        <?php if ($field_files_audio): ?>
        <li><a href="#tab-audio"><?php print t("Audio");?></a></li>
        <?endif;?>
        <?php if ($field_files_file['und']['0']['fid']): ?>
        <li><a href="#tab-document"><?php print t("Document");?></a></li>
        <?endif;?>
    </ul>
        <?endif;?>

    <!-- Video tab -->
    <div id="tab-video">
        <?php print render($content['field_files_youtube_media']); ?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>

        <div class="additional-info">
            <?php if ($field_files_author): ?>
            <div class="info-label"><?php print t("People");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
            <?endif;?>
            <?php if ($field_files_author_location): ?>
            <div class="info-label"><?php print t("Location");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
            <?endif;?>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Date taken");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
        </div>
    </div>
    <!-- end Video tab -->

    <!-- Image tab -->
        <?php if ($field_files_image): ?>
    <div id="tab-image">
        <?php print render($content['field_files_image']); ?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>

        <div class="additional-info">
            <?php if ($field_files_author): ?>
            <div class="info-label"><?php print t("People");?>:</div>
            <?php print render($content['field_files_author']); ?>
            <?endif;?>
            <?php if ($field_files_author_location): ?>
            <div class="info-label"><?php print t("Location");?>:</div>
            <?php print render($content['field_files_author_location']); ?>
            <?endif;?>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Date taken");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
        </div>
    </div>
        <?endif;?>
    <!-- end Image tab -->

    <!-- Audio tab -->
        <?php if ($field_files_audio): ?>
    <div id="tab-audio">
        <?php if ($field_files_album_poster): ?>
        <style>
            .field-name-field-files-audio .jp-interface {
                width: 520px;
                margin-left: 120px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-progress,
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-current-time,
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-duration{
                width: 320px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single a.jp-mute,
            .field-name-field-files-audio .jp-audio .jp-type-single a.jp-unmute{
                left: 435px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-volume-bar {
                left: 460px;
            }
        </style>
        <div class="album-cover">
            <?php print render($content['field_files_album_poster']); ?>
        </div>
        <?endif;?>
        <?php print render($content['field_files_audio']); ?>
        <div class="audio-download">
            <a href="<?print file_create_url($field_files_audio[0]['uri']);?>"><?php print t("Download");?></a>
        </div>
        <div class="audio-meta">
            <?php if ($field_files_artist): ?>
            <div class="info-label"><?php print t("Artist");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_artist[0]['target_id'])?>"><?php print render($content['field_files_artist']); ?></a>
            <?endif;?>
            <?php if ($field_files_year): ?>
            <div class="info-label"><?php print t("Year");?>:</div>
            <?php print render($content['field_files_year']); ?>
            <?endif;?>
            <?php if ($field_files_length): ?>
            <div class="info-label"><?php print t("Length");?>:</div>
            <?php print render($content['field_files_length']); ?>
            <?endif;?>
            <?php if ($field_files_topics): ?>
            <div class="info-label"><?php print t("Topics");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_topics[0]['target_id'])?>"><?php print render($content['field_files_topics']); ?></a>
            <?endif;?>
        </div>
    </div>
        <?endif;?>
    <!-- end Audio tab -->

    <!-- Document tab -->
        <?php if ($field_files_file['und']['0']['fid']): ?>
    <div id="tab-document">
        <?php if ($field_files_subtitle): ?>
        <h2><?php print render($content['field_files_subtitle']); ?></h2>
        <?endif;?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>
        <?php if ($field_files_key_points): ?>
        <?php print render($content['field_files_key_points']); ?>
        <?endif;?>
        <div id="docs_tabs">
            <?php if ($field_files_text): ?>
            <ul>
                <li><a href="#tab-text"><?php print t("Text");?></a></li>
                <li><a href="#tab-original"><?php print t("Original");?></a></li>
            </ul>
            <div id="tab-text">
                <?php print render($content['field_files_text']); ?>
            </div>
            <?endif;?>
            <div id="tab-original">
                <?php print render($content['field_files_file']); ?>
            </div>
        </div>
        <div class="document-section1">
            <?php if ($field_files_author): ?>
            <p class="author"><?php print t("Author");?></p>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
            <?php if ($field_files_author_location): ?>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
                <?endif;?>
            <?endif;?>
            <?php if ($field_files_receiver): ?>
            <p class="author"><?php print t("Receiver");?></p>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver[0]['target_id'])?>"><?php print render($content['field_files_receiver']); ?></a>
            <?php if ($field_files_receiver_location): ?>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver_location[0]['target_id'])?>"><?php print render($content['field_files_receiver_location']); ?></a>
                <?endif;?>
            <?endif;?>
            <div class="clear"></div>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Creation date");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
            <?php if ($field_files_topics): ?>
            <div class="info-label"><?php print t("Topics");?>:</div>
            <?php print render($content['field_files_topics']); ?>
            <?endif;?>
            <?php if ($field_files_collection): ?>
            <?php print render($content['field_files_collection']); ?>
            <?endif;?>
        </div>
        <div class="document-section2">
            <?php if ($field_files_folder): ?>
            <?php print render($content['field_files_folder']); ?>
            <?endif;?>
            <?php if ($field_files_original_title): ?>
            <?php print render($content['field_files_original_title']); ?>
            <?endif;?>
            <?php if ($field_files_publication): ?>
            <?php print render($content['field_files_publication']); ?>
            <?endif;?>
        </div>
        <h3><?php print t("Source");?>:</h3>
        <div class="document-section3">
            <?php if ($field_files_source_title): ?>
            <?php print render($content['field_files_source_title']); ?>
            <?endif;?>
            <?php if ($field_files_source_volume): ?>
            <?php print render($content['field_files_source_volume']); ?>
            <?endif;?>
            <?php if ($field_files_source_number): ?>
            <?php print render($content['field_files_source_number']); ?>
            <?endif;?>
            <?php if ($field_files_source_chapter): ?>
            <?php print render($content['field_files_source_chapter']); ?>
            <?endif;?>
            <?php if ($field_files_source_page): ?>
            <?php print render($content['field_files_source_page']); ?>
            <?endif;?>
        </div>
        <?php if ($field_files_notes): ?>
        <?php print render($content['field_files_notes']); ?>
        <?endif;?>
    </div>
        <?endif;?>
    <!-- end Document tab -->
    </div>

        <?elseif($field_files_primary_media[0]['value'] == 'audio'):?>

        <?php if ($field_files_youtube_media || $field_files_file['und']['0']['fid'] || $field_files_image): ?>

        <div id="image_tabs">
        <ul>
            <li><a href="#tab-audio"><?php print t("Audio");?></a></li>
            <?php if ($field_files_image): ?>
            <li><a href="#tab-image"><?php print t("Image");?></a></li>
            <?endif;?>
            <?php if ($field_files_youtube_media): ?>
            <li><a href="#tab-video"><?php print t("Video");?></a></li>
            <?endif;?>
            <?php if ($field_files_file['und']['0']['fid']): ?>
            <li><a href="#tab-document"><?php print t("Document");?></a></li>
            <?endif;?>
        </ul>

        <!-- Audio tab -->
        <div id="tab-audio">
            <?php if ($field_files_album_poster): ?>
            <style>
                .field-name-field-files-audio .jp-interface {
                    width: 520px;
                    margin-left: 120px;
                }
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-progress,
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-current-time,
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-duration{
                    width: 320px;
                }
                .field-name-field-files-audio .jp-audio .jp-type-single a.jp-mute,
                .field-name-field-files-audio .jp-audio .jp-type-single a.jp-unmute{
                    left: 435px;
                }
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-volume-bar {
                    left: 460px;
                }
            </style>
            <div class="album-cover">
                <?php print render($content['field_files_album_poster']); ?>
            </div>
            <?endif;?>
            <?php print render($content['field_files_audio']); ?>
            <div class="audio-download">
                <a href="<?print file_create_url($field_files_audio[0]['uri']);?>"><?php print t("Download");?></a>
            </div>
            <div class="audio-meta">
                <?php if ($field_files_artist): ?>
                <div class="info-label"><?php print t("Artist");?>:</div>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_artist[0]['target_id'])?>"><?php print render($content['field_files_artist']); ?></a>
                <?endif;?>
                <?php if ($field_files_year): ?>
                <div class="info-label"><?php print t("Year");?>:</div>
                <?php print render($content['field_files_year']); ?>
                <?endif;?>
                <?php if ($field_files_length): ?>
                <div class="info-label"><?php print t("Length");?>:</div>
                <?php print render($content['field_files_length']); ?>
                <?endif;?>
                <?php if ($field_files_topics): ?>
                <div class="info-label"><?php print t("Topics");?>:</div>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_topics[0]['target_id'])?>"><?php print render($content['field_files_topics']); ?></a>
                <?endif;?>
            </div>
        </div>
        <!-- end Audio tab -->

        <!-- Image tab -->
            <?php if ($field_files_image): ?>
        <div id="tab-image">
            <?php print render($content['field_files_image']); ?>
            <?php if ($field_files_description): ?>
            <?php print render($content['field_files_description']); ?>
            <?endif;?>

            <div class="additional-info">
                <?php if ($field_files_author): ?>
                <div class="info-label"><?php print t("People");?>:</div>
                <?php print render($content['field_files_author']); ?>
                <?endif;?>
                <?php if ($field_files_author_location): ?>
                <div class="info-label"><?php print t("Location");?>:</div>
                <?php print render($content['field_files_author_location']); ?>
                <?endif;?>
                <?php if ($field_files_creation_date): ?>
                <div class="info-label"><?php print t("Date taken");?>:</div>
                <?php print render($content['field_files_creation_date']); ?>
                <?endif;?>
            </div>
        </div>
            <?endif;?>
        <!-- end Image tab -->

        <!-- Video tab -->
            <?php if ($field_files_youtube_media): ?>
        <div id="tab-video">
            <?php print render($content['field_files_youtube_media']); ?>
            <?php if ($field_files_description): ?>
            <?php print render($content['field_files_description']); ?>
            <?endif;?>

            <div class="additional-info">
                <?php if ($field_files_author): ?>
                <div class="info-label"><?php print t("People");?>:</div>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
                <?endif;?>
                <?php if ($field_files_author_location): ?>
                <div class="info-label"><?php print t("Location");?>:</div>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
                <?endif;?>
                <?php if ($field_files_creation_date): ?>
                <div class="info-label"><?php print t("Date taken");?>:</div>
                <?php print render($content['field_files_creation_date']); ?>
                <?endif;?>
            </div>
        </div>
            <?endif;?>
        <!-- end Video tab -->

        <!-- Document tab -->
            <?php if ($field_files_file['und']['0']['fid']): ?>
        <div id="tab-document">
            <?php if ($field_files_subtitle): ?>
            <h2><?php print render($content['field_files_subtitle']); ?></h2>
            <?endif;?>
            <?php if ($field_files_description): ?>
            <?php print render($content['field_files_description']); ?>
            <?endif;?>
            <?php if ($field_files_key_points): ?>
            <?php print render($content['field_files_key_points']); ?>
            <?endif;?>
            <div id="docs_tabs">
                <?php if ($field_files_text): ?>
                <ul>
                    <li><a href="#tab-text"><?php print t("Text");?></a></li>
                    <li><a href="#tab-original"><?php print t("Original");?></a></li>
                </ul>
                <div id="tab-text">
                    <?php print render($content['field_files_text']); ?>
                </div>
                <?endif;?>
                <div id="tab-original">
                    <?php print render($content['field_files_file']); ?>
                </div>
            </div>
            <div class="document-section1">
                <?php if ($field_files_author): ?>
                <p class="author"><?php print t("Author");?></p>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
                <?php if ($field_files_author_location): ?>
                    <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
                    <?endif;?>
                <?endif;?>
                <?php if ($field_files_receiver): ?>
                <p class="author"><?php print t("Receiver");?></p>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver[0]['target_id'])?>"><?php print render($content['field_files_receiver']); ?></a>
                <?php if ($field_files_receiver_location): ?>
                    <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver_location[0]['target_id'])?>"><?php print render($content['field_files_receiver_location']); ?></a>
                    <?endif;?>
                <?endif;?>
                <div class="clear"></div>
                <?php if ($field_files_creation_date): ?>
                <div class="info-label"><?php print t("Creation date");?>:</div>
                <?php print render($content['field_files_creation_date']); ?>
                <?endif;?>
                <?php if ($field_files_topics): ?>
                <div class="info-label"><?php print t("Topics");?>:</div>
                <?php print render($content['field_files_topics']); ?>
                <?endif;?>
                <?php if ($field_files_collection): ?>
                <?php print render($content['field_files_collection']); ?>
                <?endif;?>
            </div>
            <div class="document-section2">
                <?php if ($field_files_folder): ?>
                <?php print render($content['field_files_folder']); ?>
                <?endif;?>
                <?php if ($field_files_original_title): ?>
                <?php print render($content['field_files_original_title']); ?>
                <?endif;?>
                <?php if ($field_files_publication): ?>
                <?php print render($content['field_files_publication']); ?>
                <?endif;?>
            </div>
            <h3><?php print t("Source");?>:</h3>
            <div class="document-section3">
                <?php if ($field_files_source_title): ?>
                <?php print render($content['field_files_source_title']); ?>
                <?endif;?>
                <?php if ($field_files_source_volume): ?>
                <?php print render($content['field_files_source_volume']); ?>
                <?endif;?>
                <?php if ($field_files_source_number): ?>
                <?php print render($content['field_files_source_number']); ?>
                <?endif;?>
                <?php if ($field_files_source_chapter): ?>
                <?php print render($content['field_files_source_chapter']); ?>
                <?endif;?>
                <?php if ($field_files_source_page): ?>
                <?php print render($content['field_files_source_page']); ?>
                <?endif;?>
            </div>
            <?php if ($field_files_notes): ?>
            <?php print render($content['field_files_notes']); ?>
            <?endif;?>
        </div>
            <?endif;?>
        <!-- end Document tab -->
        </div>
            <?else:?>
        <div id="tab-audio">
            <?php if ($field_files_album_poster): ?>
            <style>
                .field-name-field-files-audio .jp-interface {
                    width: 520px;
                    margin-left: 120px;
                }
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-progress,
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-current-time,
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-duration{
                    width: 320px;
                }
                .field-name-field-files-audio .jp-audio .jp-type-single a.jp-mute,
                .field-name-field-files-audio .jp-audio .jp-type-single a.jp-unmute{
                    left: 435px;
                }
                .field-name-field-files-audio .jp-audio .jp-type-single .jp-volume-bar {
                    left: 460px;
                }
            </style>
            <div class="album-cover">
                <?php print render($content['field_files_album_poster']); ?>
            </div>
            <?endif;?>
            <?php print render($content['field_files_audio']); ?>
            <div class="audio-download">
                <a href="<?print file_create_url($field_files_audio[0]['uri']);?>"><?php print t("Download");?></a>
            </div>
            <div class="audio-meta">
                <?php if ($field_files_artist): ?>
                <div class="info-label"><?php print t("Artist");?>:</div>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_artist[0]['target_id'])?>"><?php print render($content['field_files_artist']); ?></a>
                <?endif;?>
                <?php if ($field_files_year): ?>
                <div class="info-label"><?php print t("Year");?>:</div>
                <?php print render($content['field_files_year']); ?>
                <?endif;?>
                <?php if ($field_files_length): ?>
                <div class="info-label"><?php print t("Length");?>:</div>
                <?php print render($content['field_files_length']); ?>
                <?endif;?>
                <?php if ($field_files_topics): ?>
                <div class="info-label"><?php print t("Topics");?>:</div>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_topics[0]['target_id'])?>"><?php print render($content['field_files_topics']); ?></a>
                <?endif;?>
            </div>
        </div>
            <?endif;?>
        <?elseif($field_files_primary_media[0]['value'] == 'document'):?>

    <div id="image_tabs">
        <?php if ($field_files_youtube_media || $field_files_audio || $field_files_image): ?>
    <ul>
        <li><a href="#tab-document"><?php print t("Document");?></a></li>
        <?php if ($field_files_image): ?>
        <li><a href="#tab-image"><?php print t("Image");?></a></li>
        <?endif;?>
        <?php if ($field_files_audio): ?>
        <li><a href="#tab-audio"><?php print t("Audio");?></a></li>
        <?endif;?>
        <?php if ($field_files_youtube_media): ?>
        <li><a href="#tab-video"><?php print t("Video");?></a></li>
        <?endif;?>
    </ul>
        <?endif;?>

    <!-- Document tab -->
    <div id="tab-document">
        <?php if ($field_files_subtitle): ?>
        <h2><?php print render($content['field_files_subtitle']); ?></h2>
        <?endif;?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>
        <?php if ($field_files_key_points): ?>
        <?php print render($content['field_files_key_points']); ?>
        <?endif;?>
        <div id="docs_tabs">
            <?php if ($field_files_text): ?>
            <ul>
                <li><a href="#tab-text"><?php print t("Text");?></a></li>
                <li><a href="#tab-original"><?php print t("Original");?></a></li>
            </ul>
            <div id="tab-text">
                <?php print render($content['field_files_text']); ?>
            </div>
            <?endif;?>
            <div id="tab-original">
                <?php print render($content['field_files_file']); ?>
            </div>
        </div>
        <div class="document-section1">
            <?php if ($field_files_author): ?>
            <p class="author"><?php print t("Author");?></p>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
            <?php if ($field_files_author_location): ?>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
                <?endif;?>
            <?endif;?>
            <?php if ($field_files_receiver): ?>
            <p class="author"><?php print t("Receiver");?></p>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver[0]['target_id'])?>"><?php print render($content['field_files_receiver']); ?></a>
            <?php if ($field_files_receiver_location): ?>
                <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_receiver_location[0]['target_id'])?>"><?php print render($content['field_files_receiver_location']); ?></a>
                <?endif;?>
            <?endif;?>
            <div class="clear"></div>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Creation date");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
            <?php if ($field_files_topics): ?>
            <div class="info-label"><?php print t("Topics");?>:</div>
            <?php print render($content['field_files_topics']); ?>
            <?endif;?>
            <?php if ($field_files_collection): ?>
            <?php print render($content['field_files_collection']); ?>
            <?endif;?>
        </div>
        <div class="document-section2">
            <?php if ($field_files_folder): ?>
            <?php print render($content['field_files_folder']); ?>
            <?endif;?>
            <?php if ($field_files_original_title): ?>
            <?php print render($content['field_files_original_title']); ?>
            <?endif;?>
            <?php if ($field_files_publication): ?>
            <?php print render($content['field_files_publication']); ?>
            <?endif;?>
        </div>
        <h3><?php print t("Source");?>:</h3>
        <div class="document-section3">
            <?php if ($field_files_source_title): ?>
            <?php print render($content['field_files_source_title']); ?>
            <?endif;?>
            <?php if ($field_files_source_volume): ?>
            <?php print render($content['field_files_source_volume']); ?>
            <?endif;?>
            <?php if ($field_files_source_number): ?>
            <?php print render($content['field_files_source_number']); ?>
            <?endif;?>
            <?php if ($field_files_source_chapter): ?>
            <?php print render($content['field_files_source_chapter']); ?>
            <?endif;?>
            <?php if ($field_files_source_page): ?>
            <?php print render($content['field_files_source_page']); ?>
            <?endif;?>
        </div>
        <?php if ($field_files_notes): ?>
        <?php print render($content['field_files_notes']); ?>
        <?endif;?>
    </div>
    <!-- end Document tab -->

    <!-- Image tab -->
        <?php if ($field_files_image): ?>
    <div id="tab-image">
        <?php print render($content['field_files_image']); ?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>

        <div class="additional-info">
            <?php if ($field_files_author): ?>
            <div class="info-label"><?php print t("People");?>:</div>
            <?php print render($content['field_files_author']); ?>
            <?endif;?>
            <?php if ($field_files_author_location): ?>
            <div class="info-label"><?php print t("Location");?>:</div>
            <?php print render($content['field_files_author_location']); ?>
            <?endif;?>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Date taken");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
        </div>
    </div>
        <?endif;?>
    <!-- end Image tab -->

    <!-- Audio tab -->
        <?php if ($field_files_audio): ?>
    <div id="tab-audio">
        <?php if ($field_files_album_poster): ?>
        <style>
            .field-name-field-files-audio .jp-interface {
                width: 520px;
                margin-left: 120px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-progress,
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-current-time,
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-duration{
                width: 320px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single a.jp-mute,
            .field-name-field-files-audio .jp-audio .jp-type-single a.jp-unmute{
                left: 435px;
            }
            .field-name-field-files-audio .jp-audio .jp-type-single .jp-volume-bar {
                left: 460px;
            }
        </style>
        <div class="album-cover">
            <?php print render($content['field_files_album_poster']); ?>
        </div>
        <?endif;?>
        <?php print render($content['field_files_audio']); ?>
        <div class="audio-download">
            <a href="<?print file_create_url($field_files_audio[0]['uri']);?>"><?php print t("Download");?></a>
        </div>
        <div class="audio-meta">
            <?php if ($field_files_artist): ?>
            <div class="info-label"><?php print t("Artist");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_artist[0]['target_id'])?>"><?php print render($content['field_files_artist']); ?></a>
            <?endif;?>
            <?php if ($field_files_year): ?>
            <div class="info-label"><?php print t("Year");?>:</div>
            <?php print render($content['field_files_year']); ?>
            <?endif;?>
            <?php if ($field_files_length): ?>
            <div class="info-label"><?php print t("Length");?>:</div>
            <?php print render($content['field_files_length']); ?>
            <?endif;?>
            <?php if ($field_files_topics): ?>
            <div class="info-label"><?php print t("Topics");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_topics[0]['target_id'])?>"><?php print render($content['field_files_topics']); ?></a>
            <?endif;?>
        </div>
    </div>
        <?endif;?>
    <!-- end Audio tab -->

    <!-- Video tab -->
        <?php if ($field_files_youtube_media): ?>
    <div id="tab-video">
        <?php print render($content['field_files_youtube_media']); ?>
        <?php if ($field_files_description): ?>
        <?php print render($content['field_files_description']); ?>
        <?endif;?>

        <div class="additional-info">
            <?php if ($field_files_author): ?>
            <div class="info-label"><?php print t("People");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author[0]['target_id'])?>"><?php print render($content['field_files_author']); ?></a>
            <?endif;?>
            <?php if ($field_files_author_location): ?>
            <div class="info-label"><?php print t("Location");?>:</div>
            <a href="<?print base_path().drupal_lookup_path('alias',"node/".$field_files_author_location[0]['target_id'])?>"><?php print render($content['field_files_author_location']); ?></a>
            <?endif;?>
            <?php if ($field_files_creation_date): ?>
            <div class="info-label"><?php print t("Date taken");?>:</div>
            <?php print render($content['field_files_creation_date']); ?>
            <?endif;?>
        </div>
    </div>
        <?endif;?>
    <!-- end Video tab -->
    </div>

        <? endif;?>
    <div class="file-copyright"><?print l(t("Copyright: Ellen G. White Estate."),"#");?></div>
    </div>
        <?php endif;?>
  </div>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <div class="links"><?php print render($content['links']); ?></div>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>

</div>