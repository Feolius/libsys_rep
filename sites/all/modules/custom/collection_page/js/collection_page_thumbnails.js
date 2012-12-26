(function ($) {
  Drupal.behaviors.collectionThumbnailsView = {
    attach: function (context, settings) {
      $("#collection_upper_thumbnail").hover(function(){

        },function(){
          $("#collection-thumbnail-upper-container").css("display", "none");
          $("#collection_upper_thumbnail").css("height", 200);
          $("#collection-thumbnail-metainfo").html("");
        });
      $(".collection-thumbnail").hover(function(){
        var metainfo = $(this).parent().find(".collection-thumbnail-metainfo").html();
        var initialLeft = $(this).position().left;
        var initialWidth = $(this).width();
        var padding = parseInt($("#collection-thumbnail-upper-container").css("padding-left"));
        $("#collection-thumbnail-upper-container").css("top", $(this).position().top - padding);
        $("#collection_upper_thumbnail").attr("src", $(this).attr("src"));
        $("#collection-thumbnail-upper-container").width(initialWidth + 2*padding);
        if ($("#collection-thumbnail-upper-container").css("display") == "none"){
          $("#collection-thumbnail-upper-container").css("display", "block");
          $("#collection_upper_thumbnail").animate({
            height: 300
          },{
            duration: 300,
            complete: function(){
              $("#collection-thumbnail-metainfo").html(metainfo);
              $("#collection-thumbnail-metainfo").width(1.5*initialWidth);
              //$("#collection-thumbnail-upper-container").width(1.5*initialWidth + 2*padding);
            },
            step: function(now, fx){
              var left = initialLeft - initialWidth*0.5*(now/200 - 1) - padding;
              var right = left + now + 2*padding;
              var containerWidth = $("#collection-standart-thumbnail-view-container").width();
              if (right >= containerWidth){
                left = containerWidth - now;
              }
              if (left < 0){
                left = 0;
              }
              $("#collection-thumbnail-upper-container").css("left", left);
              $("#collection-thumbnail-upper-container").width((now/200)*initialWidth + 2*padding);
            }
          });
      }else{
        $("#collection_upper_thumbnail").attr("src", $(this).attr("src"));
      }

      },function(){

      });
  }
}
})(jQuery);

