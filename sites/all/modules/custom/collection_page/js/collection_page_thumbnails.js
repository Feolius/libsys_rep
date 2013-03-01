(function ($) {
  Drupal.behaviors.collectionThumbnailsView = {
    attach: function (context, settings) {
      var height = Drupal.settings.collection_page.height;
      //Height for visually compressed images
      var lowHeight = height*2/3;
       $(".collection-thumbnail").css("height", lowHeight);
       $(".collection-upper-thumbnail").css("height", lowHeight);
      $("#collection-upper-thumbnail").hover(function(){

        },function(){
          $("#collection-thumbnail-upper-container").css("display", "none");
          $("#collection-upper-thumbnail").css("height", lowHeight);
          $("#collection-thumbnail-metainfo").html("");
        });
      $(".collection-thumbnail").hover(function(){
        var metainfo = $(this).parent().find(".collection-thumbnail-metainfo").html();
        var nodeLink = $(this).parent().find(".collection-thumbnail-node-link").val();
        var initialLeft = $(this).position().left;
        var initialWidth = $(this).width();
        var padding = parseInt($("#collection-thumbnail-upper-container").css("padding-left"));
        $("#collection-thumbnail-upper-container").css("top", $(this).position().top - padding);
        $("#collection-upper-thumbnail").attr("src", $(this).attr("src"));
        $("#collection-upper-thumbnail-link").attr("href", nodeLink);
        if ($("#collection-thumbnail-upper-container").css("display") == "none"){
          $("#collection-thumbnail-upper-container").css("display", "block");
          $("#collection-upper-thumbnail").animate({
            height: height
          },{
            duration: 300,
            complete: function(){
              $("#collection-thumbnail-metainfo").html(metainfo);
              $("#collection-thumbnail-metainfo").width(1.5*initialWidth);
            },
            step: function(now, fx){
              var left = initialLeft - initialWidth*0.5*(now/lowHeight - 1) - padding;
              var right = left + now + 2*padding;
              var containerWidth = $("#collection-standart-thumbnail-view-container").width();
              if (right >= containerWidth){
                left = containerWidth - now;
              }
              if (left < 0){
                left = 0;
              }
              $("#collection-thumbnail-upper-container").css("left", left);
              $("#collection-thumbnail-upper-container").width((now/lowHeight)*initialWidth);
            }
          });
      }else{
        $("#collection-upper-thumbnail").attr("src", $(this).attr("src"));
      }

      },function(){

      });
  }
}
})(jQuery);

