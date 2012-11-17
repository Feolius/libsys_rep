(function ($) {
    Drupal.behaviors.collection_page_tabs = {
        attach:function () {
            $("#collection_page_tabs").tabs();
           // $("#collection_page_tabs").tabs("select", 1);
        }
    }

})(jQuery);