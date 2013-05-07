<?php
/**
 * @file
 * Provide the HTML output for a jPlayer interface.
 */
?>

<div class="jp-<?php print $type; ?>">
    <div class="jp-type-single">
        <div id="<?php print $player_id; ?>" class="jp-jplayer"></div>
        <div id="<?php print $player_id; ?>_interface" class="jp-interface">
            <ul class="jp-controls">
                <li><a href="#" class="jp-play" tabindex="1">play</a></li>
                <li><a href="#" class="jp-pause" tabindex="1">pause</a></li>
                <li><a href="#" class="jp-stop" tabindex="1">stop</a></li>
                <li><a href="#" class="jp-mute" tabindex="1">mute</a></li>
                <li><a href="#" class="jp-unmute" tabindex="1">unmute</a></li>
            </ul>

            <div class="jp-progress">
                <canvas class="jp-waveform-canvas">
                    <img class="jp-waveform-image" src="<?php print $waveform_image;?>">
                </canvas>
                <div class="jp-seek-bar">
                    <div class="jp-play-bar"></div>
                </div>
            </div>

            <div class="jp-volume-bar">
                <div class="jp-volume-bar-value"></div>
            </div>

            <div class="jp-current-time"></div>
            <div class="jp-duration"></div>
            <div class="jp-media-info"><?php print $media_info;?> </div>
        </div>
    </div>
</div>
<?php print drupal_render($dynamic); ?>

