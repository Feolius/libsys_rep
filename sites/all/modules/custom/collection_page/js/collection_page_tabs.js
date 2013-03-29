(function ($) {
    Drupal.behaviors.collection_page_tabs = {
        attach: function () {
            var standard_view_tab_button = $("#tab-button-standard-view"),
                stantard_view_types = $("#library-standard-view-types"),
                library_tabs = $("#collection_page_tabs");


            if (Drupal.settings.collection_page.default_tab != false && $.cookie('collection_page_last_time_active_tab').empty()) {
                library_tabs.tabs('select', Drupal.settings.collection_page.default_tab);
            } else {
                library_tabs.tabs('select', parseInt($.cookie('collection_page_last_time_active_tab')));
            }

            library_tabs.tabs({
                select: function (event, ui) {
                    $.cookie('collection_page_last_time_active_tab', ui.index);
                }
            });

            if (Drupal.settings.collection_page.disabled_tab != false && Drupal.settings.collection_page.disabled_tab > 0) {
                library_tabs.tabs({disabled: [Drupal.settings.collection_page.disabled_tab] });
            }

            standard_view_tab_button.mouseenter(function () {
                var left = $(this).position().left;
                var top = $(this).position().top;
                var width = $(this).width();
                var height = $(this).height()
                stantard_view_types.css("width", width);
                stantard_view_types.css("top", top);
                stantard_view_types.css("left", left);
                stantard_view_types.css("height", height);
                stantard_view_types.show();
            });

            stantard_view_types.mouseleave(function () {
                stantard_view_types.hide();
            });

            $("#library-standard-view-default-type").click(function () {
                stantard_view_types.hide();
                window.location = $("#library-standard-view-default-type").attr('link');
            });
            $("#library-standard-view-thumbnail-type").click(function () {
                stantard_view_types.hide();
                window.location = $("#library-standard-view-thumbnail-type").attr('link');
            });


        }
    }
})
    (jQuery);