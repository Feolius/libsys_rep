(function ($) {
    $(document).ready(function (){
        var minValue = Drupal.settings.facetapi_slider_widget.minValue;
        var maxValue = Drupal.settings.facetapi_slider_widget.maxValue;
        var leftLimit = Drupal.settings.facetapi_slider_widget.leftLimit;
        var rightLimit = Drupal.settings.facetapi_slider_widget.rightLimit;
        var forms = Drupal.settings.facetapi_slider_widget.forms;
        $.each( forms, function(formId, formIdProperties){
            var rangeLabelId = formIdProperties.rangeLabelId;
            var minValueId = formIdProperties.minValueId;
            var maxValueId = formIdProperties.maxValueId;
            $( "#" + minValueId).val(minValue);
            $( "#" + maxValueId).val(maxValue);
            $( "#" + rangeLabelId ).val( minValue + "%" + " - " + maxValue + "%" );
        } );
        $( ".facetapi-slider" ).slider({
            range: true,
            min: leftLimit,
            max: rightLimit,
            values: [minValue, maxValue],
            slide: function( event, ui ) {
                var obj = ui.handle;
                var parent = obj.parentElement;
                while(parent.tagName != "FORM"){
                    parent = parent.parentElement;
                }
                var changedFormId = parent.id;
                $.each( forms, function(formId, formIdProperties){
                    if (changedFormId == formId){
                        var rangeLabelId = formIdProperties.rangeLabelId;
                        var minValueId = formIdProperties.minValueId;
                        var maxValueId = formIdProperties.maxValueId;
                        $( "#" + rangeLabelId).val( ui.values[ 0 ] + "%" + " - " + ui.values[ 1 ] + "%" );
                        $( "#" + minValueId).val(ui.values[ 0 ]);
                        $( "#" + maxValueId).val(ui.values[ 1 ]);

                    }
                } );

            }
        });
    });
})(jQuery);