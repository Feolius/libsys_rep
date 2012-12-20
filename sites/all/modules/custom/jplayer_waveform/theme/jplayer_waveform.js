/**
 * @file
 * Drupal behaviors for jPlayer.
 */

(function ($) {

    Drupal.jPlayer = Drupal.jPlayer || {};

    Drupal.behaviors.jPlayer = {
        attach:function (context, settings) {
            // Set time format settings
            $.jPlayer.timeFormat.showHour = Drupal.settings.jplayer_waveform.showHour;
            $.jPlayer.timeFormat.showMin = Drupal.settings.jplayer_waveform.showMin;
            $.jPlayer.timeFormat.showSec = Drupal.settings.jplayer_waveform.showSec;

            $.jPlayer.timeFormat.padHour = Drupal.settings.jplayer_waveform.padHour;
            $.jPlayer.timeFormat.padMin = Drupal.settings.jplayer_waveform.padMin;
            $.jPlayer.timeFormat.padSec = Drupal.settings.jplayer_waveform.padSec;

            $.jPlayer.timeFormat.sepHour = Drupal.settings.jplayer_waveform.sepHour;
            $.jPlayer.timeFormat.sepMin = Drupal.settings.jplayer_waveform.sepMin;
            $.jPlayer.timeFormat.sepSec = Drupal.settings.jplayer_waveform.sepSec;

            // INITIALISE

            $('.jp-jplayer:not(.jp-jplayer-processed)', context).each(function () {
                $(this).addClass('jp-jplayer-processed');
                var wrapper = this.parentNode;
                var player = this;
                var playerId = $(this).attr('id');
                var playerSettings = Drupal.settings.jplayer_waveform.jplayerInstances[playerId];
                var type = $(this).parent().attr('class');
                player.playerType = $(this).parent().attr('class');
                var waveform = $('div.jp-progress', $(player));
                var loaded = $('div.jp-seek-bar', $(player));

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
                    swfPath:Drupal.settings.jplayer_waveform.swfPath,
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

//                function drawWaveform(playerID) {
//                    if(widht == null){
//                        width =  $('#jp-progress').width();
//                    }
//                    if(height == null){
//                        height =  $('#jp-progress').height();
//                    }
//
//                    var canvas = document.getElementById('jp-waveform-canvas');
//                    var context = canvas.getContext('2d');
//                    var data = Drupal.settings.canvas_test.waveform_data;
//                    var frame_per_pixel = (data.length / width);
//                    var v = 0.0, d = 0;
//                    context.fillStyle = "rgba(0, 100, 0, 1)";
//                    context.fillRect(0, 0, width, height);
//                    for (d = 0; d < width; d++) {
//                        v = (Array.max(data.slice(d * frame_per_pixel, (d + 1) * frame_per_pixel)) / 255.0 * height);
//                        context.clearRect(d, height - v, 1, 2 * v - height);
//                    }
//                }
//
//                Array.max = function (array) {
//                    return Math.max.apply(Math, array);
//                };

            });

//            //Draw the waveform using canvas
//            drawWabeform();
//
//            $(window).resize(function () {
//                var width = $(window).width() * 0.8;
//                var height = $(window).height() * 0.2;
//                $('canvas').width(width);
//                $('canvas').height(height);
//                draw(width, height);
//            });


        }

    };

})(jQuery);

