(function ($) {
    Drupal.behaviors.collection_page_tabs = {
        attach: function () {
            var library_tabs = $("#collection_page_tabs"),
                last_time_active_tab = parseInt($.cookie('collection_page_last_time_active_tab')),
                disabled_tabs = Drupal.settings.collection_page.disabled_tabs;

            library_tabs.tabs();

            if (disabled_tabs != undefined) {
                library_tabs.tabs({disabled: disabled_tabs });
            }

            if (Drupal.settings.collection_page.default_tab != false
                && (
                (last_time_active_tab == NaN || last_time_active_tab == null)
                    || last_time_active_tab == Drupal.settings.collection_page.disabled_tab)
                ) {
                library_tabs.tabs('option', 'active', Drupal.settings.collection_page.default_tab);
            } else {
                library_tabs.tabs('option', 'active', parseInt($.cookie('collection_page_last_time_active_tab')));
            }
            library_tabs.tabs({
                activate: function (event, ui) {
                    $.cookie('collection_page_last_time_active_tab', $(this).tabs('option', 'active'));
                }
            });

        }
    }
})(jQuery);