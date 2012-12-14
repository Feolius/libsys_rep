(function ($) {
  Drupal.behaviors.facetCollection = {
    attach: function (context, settings) {
      $(".show-collection-teaser-button").click(function(){
        var parentContainer = $(this).parent();
        var results = parentContainer.find(".facet-collection-teaser-placeholder");
        if(results.length == 0){
          var teaserPlaceholder = $('<div class="facet-collection-teaser-placeholder"/>');
          parentContainer.append(teaserPlaceholder);
          var nid = parentContainer.find(".collection-nid-contatiner").val();
          var url = '/collection-teaser/node/' + nid;
          teaserPlaceholder.load(url, function(){
            var currHeight = $(this).css('height');
            $(this).css('height', 0);
            $(this).animate({
              height: currHeight
            },
            1000, function(){
              });
          });
          $(this).val('Hide preview');
        }else{
          if($(this).val() == 'Hide preview'){
            results.each(function(){
              $(this).slideUp(
              1000, function(){
              });
            });
            $(this).val('Show preview');
          }else{
            results.each(function(){
              $(this).slideDown(
               1000, function(){
              });
            });
            $(this).val('Hide preview');
          }

        }
      });
    }
  }
})(jQuery);



