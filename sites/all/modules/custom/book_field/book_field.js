(function ($) {   
    $(document).ready(function (){
        
        //Get paths of swf files
        var paths = Drupal.settings.book_field.paths;       
        
        //Get path of FlexPaperViewer.swf file        
        var FlexPaperViewerPath = Drupal.settings.book_field.FlexPaperViewerPath;
        
        //We have to be able to show a few documents on page. Calculate numberof documents that have
        //to be shown on the page
        var length = paths.length;
        var i = 0;
        
        //Find all elements with class viewerPlaceHolder
        var placeHolders = $('p.viewerPlaceHolder');
        
        //Put ids for this elements
        placeHolders.each(function(index){
            $(this).attr('id', 'viewerPlaceHolder_' + index); 
        });
        
        //Implements showing for each element
        for (var i = 0; i < length; i++){
            var id = 'viewerPlaceHolder_' + i.toString();
            var res = $.find('#' + id);
            if(res.length != 0){
                var path = paths[i];
                var fp = new FlexPaperViewer(	
                    FlexPaperViewerPath,
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
//Implements higlighting search term after documents being load
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
