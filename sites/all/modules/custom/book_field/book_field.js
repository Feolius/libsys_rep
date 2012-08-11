(function ($) {   
    $(document).ready(function (){
        var paths = Drupal.settings.book_field.paths;    
        var length = paths.length;
        var i = 0;
        var placeHolders = $('p.viewerPlaceHolder');
        placeHolders.each(function(index){
            $(this).attr('id', 'viewerPlaceHolder_' + index); 
        });
        for (var i = 0; i < length; i++){
            var id = 'viewerPlaceHolder_' + i.toString();
            var res = $.find('#' + id);
            if(res.length != 0){
                var path = paths[i];
                var fp = new FlexPaperViewer(	
                    '/sites/all/modules/book_field/FlexPaperViewer',
                    id, {
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
                            SearchMatchAll : true,
                            InitViewMode : 'Portrait',
						 
                            ViewModeToolsVisible : true,
                            ZoomToolsVisible : true,
                            NavToolsVisible : true,
                            CursorToolsVisible : true,
                            SearchToolsVisible : true,
  						
                            localeChain: 'en_US'
                        }
                    });	      
            }
             
        }           
    });
    
})(jQuery);
function onDocumentLoaded(totalPages){ 
    var searchTherm = Drupal.settings.book_field.search;
    if (searchTherm != undefined){        
        var instance = window.FlexPaperViewer_Instance ;
        var api = instance.getApi();    
        api.searchText(searchTherm);
    }
     
}
function onDocumentLoadedError(errMessage){
    $('#viewerPlaceHolder').html("Error displaying document. Make sure the conversion tool is installed and that correct user permissions are applied to the SWF Path directory");
}