(function ($) {
    Drupal.behaviors.nodetabs = {
        attach: function (context) {
//            $('.section ul.tabs').delegate('li:not(.current)', 'click', function() {
//                $(this).addClass('current').siblings().removeClass('current')
//                    .parents('div.section-wrapper').find('div.box').eq($(this).index()).fadeIn(150).siblings('div.box').hide();
//                if ($('.current').hasClass('tab-img')) {
//                    Drupal.attachBehaviors($('.openseadragon'));
//                }
//            });
            $("#image_tabs").tabs({
                select: function (event, ui) {
                    //TODO: clean openseadragon div only when tab with him selected
                    //TODO: clean openseadragon div only in tab with him
                    $(".openseadragon").html(' ');
                    Drupal.behaviors.openseadragon.attach();
                }
            });
            $("#docs_tabs").tabs();
        }
    }
})(jQuery);