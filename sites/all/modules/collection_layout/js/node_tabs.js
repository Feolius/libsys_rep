(function ($) {
    $(function() {
        $("#collection_layout_tabs").tabs({
            select: function(event, ui){
                if(ui.index == 3)
                    $("#collection_layout_book_tabs").tabs("select" , 1);
            }
        }
    );
        $("#collection_layout_book_tabs").tabs();
    });
})(jQuery);
