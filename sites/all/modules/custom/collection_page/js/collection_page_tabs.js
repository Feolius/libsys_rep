(function ($) {
    Drupal.behaviors.collection_page_tabs = {
        attach: function () {
            var standard_view_tab_button = $("#tab-button-standard-view"),
                standard_view_types = $("#library-standard-view-types-menu"),
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

            $('.standard-view-type-title').click(function () {
                if ($(this).parent().get(0).id == 'library-standard-view-button') {
                    standard_view_types.hide();
                } else {
                    var left = standard_view_tab_button.position().left;
                    var top = standard_view_tab_button.position().top;
                    var width = standard_view_tab_button.width();
                    var height = standard_view_tab_button.height()
                    standard_view_types.css("width", width);
                    standard_view_types.css("top", top);
                    standard_view_types.css("left", left);
                    standard_view_types.css("height", height * 3);
                    $(".library-standard-view-type").css("height", height);
                    $(".library-standard-view-type").css("width", width);
                    standard_view_types.show();
                }

            });

            standard_view_types.mouseleave(function () {
                standard_view_types.hide();
            });

            $("#library-standard-view-default-type").click(function () {
                standard_view_types.hide();
                library_tabs.tabs('select', 0);
                if ($('#standard-view-tab-button-type-title').text().toLowerCase() == 'thumbnail') {
                    $('#standard-view-tab-button-type-title').text('Default')
                    window.location = $(this).attr('link');
                }
            });
            $("#library-standard-view-thumbnail-type").click(function () {
                standard_view_types.hide();
                library_tabs.tabs('select', 0);
                if ($('#standard-view-tab-button-type-title').text().toLowerCase() == 'default') {
                    $('#standard-view-tab-button-type-title').text('Thumbnail')
                    window.location = $(this).attr('link');
                }
            });
            $("#library-standard-view-button").click(function () {
                standard_view_types.hide();
                library_tabs.tabs('select', 0);
            });


        }
    }
})
    (jQuery);