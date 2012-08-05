(function ($) {
    collectionLayout = {
        reposition : function(eventObject){
            $(".collection_layout_slider_button_right").offset({
                top : eventObject.newtop == undefined ? 500 : eventObject.newtop,
                left : $("#content-inside").offset().left + $("#content-inside").width()
            })
            $(".collection_layout_slider_button_left").offset({
                top : eventObject.newtop == undefined ? 500 : eventObject.newtop,
                left : $("#content-inside").offset().left - $(".collection_layout_slider_button_left").width()
            })
        },
        scrollReposition : function(newtop) {
            $(".collection_layout_slider_button_left").offset({
                top : newtop == undefined ? 500 : newtop
            })
            $(".collection_layout_slider_button_right").offset({
                top : newtop == undefined ? 500 : newtop
            })
        }
    };
    $(collectionLayout.reposition);
    $(window).resize(collectionLayout.reposition);
    $(document).scroll(function(eventObject){
        if($(this).scrollTop() + 500 < $("#content-inside").offset().top + $("#content-inside").height())
            collectionLayout.scrollReposition($(this).scrollTop() + 500);
    });
})(jQuery);

