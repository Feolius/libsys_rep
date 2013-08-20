/**
 *
 * @file
 * Library JS.
 */
(function ($, Drupal, window, document, undefined) {

  // Function for download files.
  function downloadFile(url) {
    var link = document.createElement('a');
    link.href = url;

    if (link.download !== undefined) {
      // Set HTML5 download attribute.
      var fileName = url.substring(url.lastIndexOf('/') + 1, url.length);
      link.download = fileName;
    }

    // Dispatching click event.
    if (document.createEvent) {
      var event = document.createEvent('MouseEvents');
      event.initEvent('click', true, true);
      link.dispatchEvent(event);
      return true;
    }
    var query = '?download';
    window.open(sUrl + query);
  }

  Drupal.behaviors.libraryDownloadFile = {
    attach: function(context, settings) {
      $('a.download').once(function() {
        $(this).each(function( index, value ) {
          $(value).click(function(event) {
            event.preventDefault();
            var url = $(value).attr('href');
            downloadFile(url);
          });
        });
      })
    }
  }

  Drupal.behaviors.libraryShareGooglePlusOneButton = {
    attach: function(context, settings) {
      $('.icon.gplus').once(function() {
        $(this).click(function(event) {
          var url = window.location.href;
          event.preventDefault();
            window.open(
              'https://plus.google.com/share?url=' + url,
              'popupwindow',
              'scrollbars=yes,width=800,height=400'
            ).focus();
            return false;
          })
      })
    }
  }

  Drupal.behaviors.libraryMoreInfoButton = {
    attach: function(context, settings) {
      $('a.information').once(function() {
        $(this).click(function(event) {
          event.preventDefault();
          var info_block = $('div.information');
          if (info_block.hasClass('hide-me')) {
            info_block.removeClass('hide-me');
          }
          else {
            info_block.addClass('hide-me');
          }
        })
      })
    }
  }

  Drupal.behaviors.libraryContentTabsFile = {
    attach: function(context, settings) {
      $('.node-files').once(function() {
        $('#ui-tabs').tabs({
            select: function (event, ui) {
            //TODO: clean openseadragon div only when tab with him selected
            //TODO: clean openseadragon div only in tab with him
            $(".openseadragon").html(' ');
            Drupal.behaviors.openseadragon.attach();
          }
        });
        $('#file-tabs').tabs();
      })
    }
  }

})(jQuery, Drupal, this, this.document);
