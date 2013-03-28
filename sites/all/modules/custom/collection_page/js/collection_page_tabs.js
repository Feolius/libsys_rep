(function ($) {
    Drupal.behaviors.collection_page_tabs = {
        attach:function () {
            var standard_view_tab_button = $("#tab-button-standard-view"),
                stantard_view_types = $("#library-standard-view-types"),
                library_tabs = $("#collection_page_tabs");

            library_tabs.tabs();
            if (Drupal.settings.collection_page.default_tab != false) {
                library_tabs.tabs('select', Drupal.settings.collection_page.default_tab);
            }
            if (Drupal.settings.collection_page.disabled_tab != false && Drupal.settings.collection_page.disabled_tab > 0) {
                library_tabs.tabs({disabled:[Drupal.settings.collection_page.disabled_tab] });
            }
            standard_view_tab_button.append(stantard_view_types);
            stantard_view_types.hide();

            standard_view_tab_button.mouseover(function(){
                stantard_view_types.show();
            });
            standard_view_tab_button.mouseout(function(){
                stantard_view_types.hide();
            });

            $("#library-standard-view-default-type").click(function(){
                window.location = $("#library-standard-view-default-type").attr('link');
            });
            $("#library-standard-view-thumbnail-type").click(function(){
                window.location = $("#library-standard-view-thumbnail-type").attr('link');
            });

        }
    }
})
    (jQuery);