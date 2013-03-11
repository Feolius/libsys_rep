(function ($) {
    Drupal.behaviors.collection_page_tabs = {
        attach:function () {
            $("#collection_page_tabs").tabs();
            if (Drupal.settings.collection_page.default_tab != false) {
                $("#collection_page_tabs").tabs('select', Drupal.settings.collection_page.default_tab);
            }
            if (Drupal.settings.collection_page.disabled_tab != false && Drupal.settings.collection_page.disabled_tab > 0) {
                $("#collection_page_tabs").tabs({disabled:[Drupal.settings.collection_page.disabled_tab] });
            }
        }
    }
})
    (jQuery);