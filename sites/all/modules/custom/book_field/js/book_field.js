(function ($) {
    Drupal.behaviors.flexpaper = {
        attach: function (context, settings){

            //Get paths for all needed files
            var swfPaths = Drupal.settings.book_field.swfPaths;
            var pngPaths = Drupal.settings.book_field.pngPaths;
            var jsonPaths = Drupal.settings.book_field.jsonPaths;
            var pdfPaths = Drupal.settings.book_field.pdfPaths;
            var desktopHTMLPath = Drupal.settings.book_field.desktopHTMLPath;
            var mobileHTMLPath = Drupal.settings.book_field.mobileHTMLPath;
            var jsDirectory = Drupal.settings.book_field.jsDirectory;
            var cssDirectory = Drupal.settings.book_field.cssDirectory;
            var localeDirectory = Drupal.settings.book_field.localeDirectory;
            var renderingOrder = Drupal.settings.book_field.renderingOrder;
            //Get path of FlexPaperViewer.swf file
            var FlexPaperViewerPath = Drupal.settings.book_field.FlexPaperViewerPath;

            //We have to be able to show a few documents on page. Calculate numberof documents that have
            //to be shown on the page
            var length = swfPaths.length;
            var i = 0;

            //Find all elements with class viewerPlaceHolder
            var placeHolders = $('div.flexpaper_viewer');

            //Put ids for this elements
            placeHolders.each(function(index){
                //@TODO Uncomment it when flexpaper will be ready for using few different ids
                //$(this).attr('id', 'documentViewer' + index);
                $(this).attr('id', 'documentViewer');
            });

            //Implements showing for each element
            for (var i = 0; i < length; i++){
                //@TODO Uncomment it when flexpaper will be ready for using few different ids
                //var id = 'documentViewer' + i.toString();
                var id = 'documentViewer'
                desktopHTMLPath = desktopHTMLPath + "/" + id;
                mobileHTMLPath = mobileHTMLPath + "/" + id;
                var res = $.find('#' + id);
                if(res.length != 0){
                    var swfPath = swfPaths[i];
                    var pngPath = pngPaths[i];
                    var jsonPath = jsonPaths[i];
                    var pdfPath = pdfPaths[i];
                    jQuery.get((!window.isTouchScreen)?desktopHTMLPath:mobileHTMLPath,
                        function(toolbarData) {
                            $('#' + id ).FlexPaperViewer(
                                { config : {
                                    SwfFile : swfPath,
                                    JSONFile : jsonPath,
                                    IMGFiles : pngPath,
                                    PDFFile : pdfPath,
                                    Scale : 0.6,
                                    ZoomTransition : 'easeOut',
                                    ZoomTime : 0.5,
                                    ZoomInterval : 0.2,
                                    FitPageOnLoad : true,
                                    FitWidthOnLoad : false,
                                    FullScreenAsMaxWindow : false,
                                    ProgressiveLoading : false,
                                    MinZoomSize : 0.2,
                                    MaxZoomSize : 5,
                                    SearchMatchAll : true,
                                    InitViewMode : 'Portrait',
                                    RenderingOrder : renderingOrder,
                                    jsDirectory : jsDirectory,
                                    cssDirectory : cssDirectory,
                                    localeDirectory: localeDirectory,
                                    Toolbar         : toolbarData,

                                    key : '$47ee5411a2cb791b9eb',

                                    ViewModeToolsVisible : true,
                                    ZoomToolsVisible : true,
                                    NavToolsVisible : true,
                                    CursorToolsVisible : true,
                                    SearchToolsVisible : true,

                                    localeChain: 'en_US'
                                }}
                            );


                        });
                }
                var url = document.URL;
                var pathArray = url.split( '/' );
                var protocol = pathArray[0];
                var host = pathArray[2];
                var baseUrl = protocol + '//' + host;
                $.ajax({
                    url: baseUrl + '/book_field/highlight',
                    type: 'POST',
                    dataType: 'json',
                    data: {
                        ajax: true,
                        url: url,
                        jsonPath: jsonPath
                    },
                    success: function(data, status){
                        if(!$.isEmptyObject(data)){
                            var parent = $('#' + id).parent();
                            //Get flexpaper viewer container element
                            //var parent = parents[1];
                            var container = $('<div class="highlight-buttons-container"></div>').insertBefore(parent);
                            container.html('<h3>Search document</h3>');
                            for(var key in data){
                                term = data[key];
                                $('<button> </button>')
                                    .addClass('flexpaper-highlight-button')
                                    .val(term)
                                    .html(term)
                                    .appendTo(container);
                            }
                            $('.flexpaper-highlight-button').click(function(){
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

})(jQuery);
//Implements higlighting search term after documents being load
function onDocumentLoaded(totalPages){
    var searchTerm = Drupal.settings.book_field.search;
    if (searchTerm != undefined){
        var instance = window.FlexPaperViewer_Instance;
        var api = instance.getApi();
        api.searchText(searchTerm);
    }
}
function onDocumentLoadedError(errMessage){
    $('#viewerPlaceHolder').html("Error displaying document. Make sure the conversion tool is installed and that correct user permissions are applied to the SWF Path directory");
}
