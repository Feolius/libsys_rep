(function($) {
  Drupal.behaviors.flexpaper = {
    attach: function(context, settings) {

      //Get paths for all needed files
      var swfPaths = Drupal.settings.book_field.swfPaths;
      var pngPaths = Drupal.settings.book_field.pngPaths;
      var jsonPaths = Drupal.settings.book_field.jsonPaths;
      var jsonUris = Drupal.settings.book_field.jsonUris;
      var pdfPaths = Drupal.settings.book_field.pdfPaths;
      var desktopHTMLPath = Drupal.settings.book_field.desktopHTMLPath;
      var mobileHTMLPath = Drupal.settings.book_field.mobileHTMLPath;
      var jsDirectory = Drupal.settings.book_field.jsDirectory;
      var cssDirectory = Drupal.settings.book_field.cssDirectory;
      var localeDirectory = Drupal.settings.book_field.localeDirectory;
      var renderingOrder = Drupal.settings.book_field.renderingOrder;
      var showSearchTools = Drupal.settings.book_field.showSearchTools;
      //Get path of FlexPaperViewer.swf file
      var FlexPaperViewerPath = Drupal.settings.book_field.FlexPaperViewerPath;

      //We have to be able to show a few documents on page. Calculate numberof documents that have
      //to be shown on the page
      var length = swfPaths.length;
      var i = 0;

      //Find all elements with class viewerPlaceHolder
      var placeHolders = $('div.flexpaper_viewer');

      //Put ids for this elements
      placeHolders.each(function(index) {
        //@TODO Uncomment it when flexpaper will be ready for using few different ids
        //$(this).attr('id', 'documentViewer' + index);
        $(this).attr('id', 'documentViewer');
      });

      //Implements showing for each element
      for (var i = 0; i < length; i++) {
        //@TODO Uncomment it when flexpaper will be ready for using few different ids
        //var id = 'documentViewer' + i.toString();
        var id = 'documentViewer'
        desktopHTMLPath = desktopHTMLPath + "/" + id;
        mobileHTMLPath = mobileHTMLPath + "/" + id;
        var res = $.find('#' + id);
        if (res.length != 0) {
          var swfPath = swfPaths[i];
          var pngPath = pngPaths[i];
          var jsonPath = jsonPaths[i];
          var pdfPath = pdfPaths[i];
          $('#' + id).once(function() {
            $(this).FlexPaperViewer(
                    {config: {
                        SwfFile: swfPath,
                        JSONFile: jsonPath,
                        IMGFiles: pngPath,
                        PDFFile: pdfPath,
                        Scale: 0.8,
                        ZoomTransition: 'easeOut',
                        ZoomTime: 0.5,
                        ZoomInterval: 0.2,
                        FitPageOnLoad: false,
                        FitWidthOnLoad: true,
                        FullScreenAsMaxWindow: false,
                        ProgressiveLoading: false,
                        MinZoomSize: 0.2,
                        MaxZoomSize: 5,
                        SearchMatchAll: true,
                        InitViewMode: 'Portrait',
                        RenderingOrder: renderingOrder,
                        jsDirectory: jsDirectory,
                        cssDirectory: cssDirectory,
                        localeDirectory: localeDirectory,
                        key: '$47ee5411a2cb791b9eb',
                        ViewModeToolsVisible: true,
                        ZoomToolsVisible: true,
                        NavToolsVisible: true,
                        CursorToolsVisible: true,
                        SearchToolsVisible: showSearchTools,
                        localeChain: 'en_US'
                      }}
            );
          });
        }
        $('#' + id).once('flexpaper').bind('onDocumentLoaded', function(e, totalPages) {
          $('.flexpaper-viewer-container').before('<button class="flexpaper-fullscreen-view-btn">Full Screen View</button>');
          $('.flexpaper-fullscreen-view-btn').click(function() {
            $('.flexpaper_bttnFullScreen').click();
            $FlexPaper("documentViewer").fitWidth();
          });
        });
        var url = document.URL;
        var pathArray = url.split('/');
        var protocol = pathArray[0];
        var host = pathArray[2];
        var baseUrl = protocol + '//' + host;
        var jsonUri = jsonUris[i];
        // Get search buttons.
        if (showSearchTools && Drupal.settings.book_field.searchButtonsFlag == undefined) {
          // Set a flag to make this code executed only once.
          Drupal.settings.book_field.searchButtonsFlag = true;
          $.ajax({
            url: baseUrl + '/book_field/highlight',
            type: 'POST',
            dataType: 'json',
            data: {
              ajax: true,
              url: url,
              jsonPath: jsonUri
            },
            success: function(data, status) {
              if (data.length > 0) {
                var parent = $('#' + id).parent();
                //Get flexpaper viewer container element
                //var parent = parents[1];
                var container = $('<div class="highlight-buttons-container"></div>');
                $('.flexpaper-viewer-container').parent().prepend(container);
                //container.html('<h3>Search document</h3>');
                for (var key in data) {
                  term = data[key];
                  if (typeof term != 'function') {
                    $('<button> </button>')
                            .addClass('flexpaper-highlight-button')
                            .val(term)
                            .html(term)
                            .appendTo(container);
                  }
                }
                $('.flexpaper-highlight-button').click(function() {
                  var searchTerm = $(this).val();
                  //@TODO Remove this hardcode and add possibility to use different ids
                  $FlexPaper("documentViewer").searchText(searchTerm);
                });
              }
            }
          });
        }
      }
    }
  }

})(jQuery);
