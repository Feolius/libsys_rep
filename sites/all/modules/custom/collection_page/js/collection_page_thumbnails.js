(function($) {
  Drupal.behaviors.collectionPageThumbnails = {
    attach: function(context, settings) {
      //Coefficient of scaling
      var coefficient = Drupal.settings.collection_page.coefficient;      
     
      $(".collection-thumbnail").once('collectionPageThumbnails').each(function() {        
        $(this).height($(this).height() / coefficient);
        $(this).width($(this).width()/ coefficient);        
      });

      $("#collection-upper-thumbnail", context).hover(function() {
      }, function() {
        $("#collection-thumbnail-upper-container").css("display", "none");
        
        $("#collection-thumbnail-metainfo").html("");
      });
      $(".collection-thumbnail", context).hover(function() {
        $("#collection-thumbnail-upper-container").css("display", "block");
        var metainfo = $(this).parent().find(".collection-thumbnail-metainfo").html();
        var nodeLink = $(this).parent().find(".collection-thumbnail-node-link").val();
        var parentPaddingLeft = parseInt($(this).parent().css("padding-left"));
        var parentPaddingTop = parseInt($(this).parent().css("padding-top"));
        var initialLeft = $(this).position().left - parentPaddingLeft;
        var initialWidth = $(this).width();
        var initialHeight = $(this).height();
        var width = initialWidth * coefficient;       
        $("#collection-thumbnail-upper-container").css("width", initialWidth);
        $("#collection-thumbnail-upper-container").css("top", $(this).position().top - parentPaddingTop);
        $("#collection-thumbnail-upper-container").css("left", initialLeft);       
        $("#collection-upper-thumbnail").attr("src", $(this).attr("src"));        
        $("#collection-upper-thumbnail-link").attr("href", nodeLink);
        $("#collection-thumbnail-upper-container").css("display", "none");        
        if ($("#collection-thumbnail-upper-container").css("display") === "none") {
          $("#collection-thumbnail-upper-container").css("display", "block");
          $("#collection-thumbnail-upper-container").animate({
            width: width
          }, {
            duration: 300,
            queue: false,            
            complete: function() {
              $(this).css('height', '');
              $("#collection-thumbnail-metainfo").html(metainfo);
              $("#collection-thumbnail-metainfo").width(1.5 * initialWidth);
            },
            step: function(now, fx) {             
              var left = initialLeft - (now - initialWidth) * 0.5;
              var height = initialHeight*now/initialWidth;
              $(this).height(height);            
              if (left < 0) {
                left = 0;
              }
              var right = left + now;
              var containerWidth = $("#collection-standard-thumbnail-view-container").width();
              if (right >= containerWidth) {
                left = containerWidth - now;
              }
              $(this).css("left", left);             
            }
          });
        } else {
          $("#collection-upper-thumbnail").attr("src", $(this).attr("src"));
        }
      }, function() {});
    }
  };
})(jQuery);

