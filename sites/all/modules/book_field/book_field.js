(function ($) {   
    $(function(){
        var path = Drupal.settings.book_field.path;    
        var fp = new FlexPaperViewer(	
            'FlexPaperViewer',
            'viewerPlaceHolder', {
                config : {
                    SwfFile : path,
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
                    SearchMatchAll : false,
                    InitViewMode : 'Portrait',
						 
                    ViewModeToolsVisible : true,
                    ZoomToolsVisible : true,
                    NavToolsVisible : true,
                    CursorToolsVisible : true,
                    SearchToolsVisible : true,
  						
                    localeChain: 'en_US'
                }
            });
						 
    function onDocumentLoadedError(errMessage){
        $('#viewerPlaceHolder').html("Error displaying document. Make sure the conversion tool is installed and that correct user permissions are applied to the SWF Path directory");
    }
    });
})(jQuery);