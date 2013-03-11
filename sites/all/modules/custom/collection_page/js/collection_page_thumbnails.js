(function($) {
  Drupal.behaviors.collectionPageThumbnails = {
    attach: function(context, settings) {
      var height = Drupal.settings.collection_page.height;
      var lowHeight = height * 2 / 3;
     
      $(".collection-thumbnail").once('collectionPageThumbnails').each(function() {
        var height = $(this).height();
        var width = $(this).width();
        $(this).height(height * 2 / 3);
        $(this).width(width * 2 / 3);
        var parent = $(this).parent();
        parent.width(width * 2 / 3);
        parent.height(height * 2 / 3);
      });


      $("#collection-upper-thumbnail", context).once('collectionPageThumbnails').hover(function() {
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
        var width = initialWidth * 1.5;
        height = initialHeight * 1.5;
        var padding = parseInt($("#collection-thumbnail-upper-container").css("padding-left"));
        $("#collection-thumbnail-upper-container").css("width", initialWidth);
        $("#collection-thumbnail-upper-container").css("top", $(this).position().top - parentPaddingTop);
        $("#collection-thumbnail-upper-container").css("left", initialLeft);
        //$('#collection-upper-thumbnail').html("<div style='background-color:black; width: 100%; height: 100%;'></div>");
        $("#collection-upper-thumbnail").attr("src", $(this).attr("src"));
        //$("#collection-upper-thumbnail").width(initialWidth);
       // $("#collection-upper-thumbnail").height(initialHeight);
        $("#collection-upper-thumbnail-link").attr("href", nodeLink);
        $("#collection-thumbnail-upper-container").css("display", "none");
        var n = 0;
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
              var cur = $("#collection-thumbnail-upper-container").width() + 10;            
              var left = initialLeft - (cur - initialWidth) * 0.5;
              var height = initialHeight*now/initialWidth;
              $(this).height(height);            
              if (left < 0) {
                left = 0;
              }
              var right = left + now;
              var containerWidth = $("#collection-standart-thumbnail-view-container").width();
              if (right >= containerWidth) {
                left = containerWidth - now;
              }
              $(this).css("left", left);             
            }
          });
        } else {
          $("#collection-upper-thumbnail").attr("src", $(this).attr("src"));
        }

      }, function() {

      });
    }
  }
})(jQuery);

