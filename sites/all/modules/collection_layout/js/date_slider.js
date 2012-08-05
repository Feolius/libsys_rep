(function ($) {
    $(function() {
        $( "#slider-date-range" ).slider({
            range: true,
            min: 1000,
            max: 2050,
            values: [ Drupal.settings.collection_layout.date_min, Drupal.settings.collection_layout.date_max ],
            stop: function( event, ui ) {
                window.location = Drupal.settings.basePath + "collection?date[min]=" 
                + $( "#slider-date-range" ).slider( "values", 0 )
                + "&date[max]=" + $( "#slider-date-range" ).slider( "values", 1);
            }
        });
    });
    
})(jQuery);