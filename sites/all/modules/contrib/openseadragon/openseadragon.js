(function($) {
  Drupal.behaviors.openseadragon = {
    attach: function(context) {
      $('.openseadragon').each(function() {
        id = $(this).attr('id').split('-');
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