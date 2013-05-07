(function ($) {
  Drupal.behaviors.collectionTeaser = {
    attach: function (context, settings) {
      $(".show-collection-teaser-button").once('collectionTeaser').click(function(){
        var parentContainer = $(this).parent();
        var placeholder = parentContainer.find(".facet-collection-teaser-placeholder");
        //Try to find container for teaser. If exist it means that we've already upload teaser.
        if(placeholder.length == 0){
          var teaserPlaceholder = $('<div class="facet-collection-teaser-placeholder"/>');
          parentContainer.append(teaserPlaceholder);
          var nid = parentContainer.find(".collection-nid-container").val();
          var url = '/collection-teaser/node/' + nid;
          teaserPlaceholder.load(url, function(){
            $(this).hide();
            //To prevent jumping befor animation
            $(this).css('overflow', 'hidden');
            $(this).slideToggle(
            1000, function(){
              });
          });
          $(this).val('Hide preview');
        }else{
          if($(this).val() == 'Hide preview'){
            $(this).val('Show preview');
          }else{
            $(this).val('Hide preview');
          }
          placeholder.slideToggle(
              1000, function(){
              });
        }
      });
    }
  }
})(jQuery);



