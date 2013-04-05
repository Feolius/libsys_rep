(function ($) {
    Drupal.behaviors.collectionPageAccordion = {
        attach: function (context, settings) {
            var active = Drupal.settings.collection_page.active;
            $('#colection-search-results-accordion').accordion({
                collapsible: true,
                active: active
            });
        }
    }
})(jQuery);


