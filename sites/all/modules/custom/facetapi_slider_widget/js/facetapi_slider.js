(function ($) {
    Drupal.behaviors.facetapiSlider = {
        attach: function (context, settings) {
            //@TODO Need to rewrite it
            var minValue = Drupal.settings.facetapi_slider_widget.minValue;
            var maxValue = Drupal.settings.facetapi_slider_widget.maxValue;
            var leftLimit = Drupal.settings.facetapi_slider_widget.leftLimit;
            var rightLimit = Drupal.settings.facetapi_slider_widget.rightLimit;
            var forms = Drupal.settings.facetapi_slider_widget.forms;
            $.each(forms, function (formId, formIdProperties) {
                var rangeLabelId = formIdProperties.rangeLabelId;
                var minValueId = formIdProperties.minValueId;
                var maxValueId = formIdProperties.maxValueId;
                $("#" + minValueId).val(minValue);
                $("#" + maxValueId).val(maxValue);
                $("#" + rangeLabelId).val(minValue + "%" + " - " + maxValue + "%");
            });
            $(".facetapi-slider").slider({
                range: true,
                min: leftLimit,
                max: rightLimit,
                values: [minValue, maxValue],
                slide: function (event, ui) {
                    var obj = ui.handle;
                    var parent = obj.parentElement;
                    while (!$(parent).hasClass("facetapi-slider-container")) {
                        parent = parent.parentElement;
                    }
                    $(parent).find('.facetapi-slider-min-value').val(ui.values[ 0 ]);
                    $(parent).find('.facetapi-slider-max-value').val(ui.values[ 1 ]);
                    $(parent).find('.facetapi_range_info').val(ui.values[ 0 ] + "%" + " - " + ui.values[ 1 ] + "%");
                }
            });
        }
    }
})(jQuery);