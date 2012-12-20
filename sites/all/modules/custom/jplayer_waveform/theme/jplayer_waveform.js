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


            // Initialise the player
            $('.jp-jplayer:not(.jp-jplayer-processed)', context).each(function () {
                $(this).addClass('jp-jplayer-processed');
                var wrapper = this.parentNode;
                var player = this;
                var playerId = $(this).attr('id');
                var playerSettings = Drupal.settings.jplayer_waveform.jplayerInstances[playerId];
                var type = $(this).parent().attr('class');
                player.playerType = $(this).parent().attr('class');

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
            });
            //Initialize interface
            $('.jp-interface', context).each(function () {
                var progress_bar = $(this).find('.jp-progress');
                var seek_bar = $(this).find('.jp-seek-bar');
                var interfaceID = $(this).attr('id');
                //Delete the '_interface' from interfaceID to get the player id
                var playerID = interfaceID.split('_')[0];

                /**
                 * Disable drag-drop
                 */
                progress_bar.mousedown(function (e) {
                    e.stopPropagation();
                    e.preventDefault();
                    return false;
                });

                /**
                 * Progress
                 */
                progress_bar.mouseup(function (e) {

                    e.stopPropagation();
                    e.preventDefault();

                    var coords = progress_bar.offset();
                    var percent = (e.pageX - coords.left) * 100 / seek_bar.width();
                    var player = $('[id=' + playerID + ']');
                    if (percent < 0) percent = 0;
                    if (percent > 100) percent = 100;

                    $(player).jPlayer('playHead', percent); //TODO Buggy when not fully loaded, unsing playHeadTime doesn't solve the problem
                    $(player).jPlayer('play');

                    return false;

                });
                //Draw the waveform using canvas
                drawCanvasWaveform(playerID);
            });
        }
    };

    $(window).resize(function () {
        $('.jp-jplayer').each(function () {
            var playerID = $(this).attr('id');
            drawCanvasWaveform(playerID);
        });
    });

    function drawCanvasWaveform(playerID) {
        //Get the progress bar in the interface part of jplayer_waveform DOM object
        var interface = $('[id=' + playerID + '_interface]');
        var progress_bar = $(interface).find('.jp-progress');
        var width = $(progress_bar).width();
        var height = $(progress_bar).height();

        //Get the canvas DOM object from interface of jplayer_waveform
        var canvas = $(interface).find('.jp-waveform-canvas').get(0);
        var context = canvas.getContext('2d');

        //Get data from player settings for drawing canvas waveform
        var playerSettings = Drupal.settings.jplayer_waveform.jplayerInstances[playerID];
        var waveformData = playerSettings.waveformData;
        var framePerPixel = (waveformData.length / width);
        var frameSize = 0.0, x = 0;

        //Set the backgroud color
        context.fillStyle = playerSettings.backgroundColor;
        context.fillRect(0, 0, width, height);

        //Draw the waveform using canvas
        for (x = 0; x < width; x++) {
            frameSize = (Array.max(waveformData.slice(x * framePerPixel, (x + 1) * framePerPixel)) / 255.0 * height);
            context.clearRect(x, height - frameSize, 1, 2 * frameSize - height);
        }
    }

    Array.max = function (array) {
        return Math.max.apply(Math, array);
    };

})(jQuery);

