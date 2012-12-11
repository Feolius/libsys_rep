/**
 * @file
 * Drupal behaviors for jPlayer.
 */

(function ($) {

    Drupal.jPlayer = Drupal.jPlayer || {};

    Drupal.behaviors.jPlayer = {
        attach:function (context, settings) {
            // Set time format settings
            $.jPlayer.timeFormat.showHour = Drupal.settings.jPlayer.showHour;
            $.jPlayer.timeFormat.showMin = Drupal.settings.jPlayer.showMin;
            $.jPlayer.timeFormat.showSec = Drupal.settings.jPlayer.showSec;

            $.jPlayer.timeFormat.padHour = Drupal.settings.jPlayer.padHour;
            $.jPlayer.timeFormat.padMin = Drupal.settings.jPlayer.padMin;
            $.jPlayer.timeFormat.padSec = Drupal.settings.jPlayer.padSec;

            $.jPlayer.timeFormat.sepHour = Drupal.settings.jPlayer.sepHour;
            $.jPlayer.timeFormat.sepMin = Drupal.settings.jPlayer.sepMin;
            $.jPlayer.timeFormat.sepSec = Drupal.settings.jPlayer.sepSec;

            // INITIALISE

            $('.jp-jplayer:not(.jp-jplayer-processed)', context).each(function () {
                $(this).addClass('jp-jplayer-processed');
                var wrapper = this.parentNode;
                var player = this;
                var playerId = $(this).attr('id');
                var playerSettings = Drupal.settings.jplayerInstances[playerId];
                var type = $(this).parent().attr('class');
                player.playerType = $(this).parent().attr('class');
                var waveform = $('.jp-progress');
                var loaded = $('.jp-seek-bar');

                // Initialise single player
                $(player).jPlayer({
                    ready:function () {
                        $(this).jPlayer("setMedia", playerSettings.file);

                        // Make sure we pause other players on play
                        $(player).bind($.jPlayer.event.play, function () {
                            $(this).jPlayer("pauseOthers");
                        });

                        Drupal.attachBehaviors(wrapper);

                        // Repeat?
                        if (playerSettings.repeat != 'none') {
                            $(player).bind($.jPlayer.event.ended, function () {
                                $(this).jPlayer("play");
                            });
                        }

                        // Autoplay?
                        if (playerSettings.autoplay == true) {
                            $(this).jPlayer("play");
                        }
                    },
                    swfPath:Drupal.settings.jPlayer.swfPath,
                    cssSelectorAncestor:'#' + playerId + '_interface',
                    solution:playerSettings.solution,
                    supplied:playerSettings.supplied,
                    preload:playerSettings.preload,
                    volume:playerSettings.volume,
                    muted:playerSettings.muted
                });
                /**
                 * Disable drag-drop
                 */
                waveform.mousedown(function (e) {
                    e.stopPropagation();
                    e.preventDefault();
                    return false;
                });

                /**
                 * Progress
                 */
                waveform.mouseup(function (e) {

                    e.stopPropagation();
                    e.preventDefault();


                    var coords = waveform.offset();
                    var percent = (e.pageX - coords.left) * 100 / loaded.width();
                    if (percent < 0) percent = 0;
                    if (percent > 100) percent = 100;

                    $(player).jPlayer('playHead', percent); //TODO Buggy when not fully loaded, unsing playHeadTime doesn't solve the problem
                    $(player).jPlayer('play');

                    return false;

                });

            });
        }

    };

})(jQuery);

