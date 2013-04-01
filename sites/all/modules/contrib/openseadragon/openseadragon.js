(function ($) {
    Drupal.behaviors.openseadragon = {
        attach: function (context) {
            $('.openseadragon',context).each(function () {
                id = $(this,context).attr('id').split('-');
                OpenSeadragon({
                    id: "openseadragon-" + id[1],
                    tileSources: Drupal.settings.openseadragon_files + '/' + id[1] + '.dzi',
                    prefixUrl: Drupal.settings.openseadragon_library + '/images/',
                    debugMode: false
                });

            });
        }
    };
})(jQuery);
