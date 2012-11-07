(function ($) {
    $(document).ready(function () {
        var arrow_left = $('<div/>'),
        arrow_left_url = Drupal.settings.collection_arrows.previous_node_html,
        arrow_right = $('<div/>'),
        arrow_right_url = Drupal.settings.collection_arrows.next_node_html;

        arrow_left.addClass("collection_layout_slider_button_left");
        arrow_left.append(arrow_left_url);

        arrow_right.addClass("collection_layout_slider_button_right");
        arrow_right.append(arrow_right_url);

        $('body').append(arrow_left);
        $('body').append(arrow_right);

    });
    collectionLayout = {
        reposition:function (eventObject) {
            $(".collection_layout_slider_button_right").offset({
                top:eventObject.newtop == undefined ? 500 : eventObject.newtop,
                left:$("#content-inside").offset().left + $("#content-inside").width()
            })
            $(".collection_layout_slider_button_left").offset({
                top:eventObject.newtop == undefined ? 500 : eventObject.newtop,
                left:$("#content-inside").offset().left - $(".collection_layout_slider_button_left").width()
            })
        },
        scrollReposition:function (newtop) {
            $(".collection_layout_slider_button_left").offset({
                top:newtop == undefined ? 500 : newtop
            })
            $(".collection_layout_slider_button_right").offset({
                top:newtop == undefined ? 500 : newtop
            })
        }
    };
    $(".collection_layout_slider_button_left a").ready(function () {
        $(".collection_layout_slider_button_left a").text('');
    });
    $(".collection_layout_slider_button_right a").ready(function () {
        $(".collection_layout_slider_button_right a").text('');
    });
    $(collectionLayout.reposition);
    $(window).resize(collectionLayout.reposition);
    $(document).scroll(function (eventObject) {
        if ($(this).scrollTop() + 500 < $("#content-inside").offset().top + $("#content-inside").height())
            collectionLayout.scrollReposition($(this).scrollTop() + 500);
    });

})(jQuery);

