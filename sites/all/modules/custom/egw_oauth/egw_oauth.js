(function($) {
  Drupal.behaviors.flexpaper_test = {
    attach: function(context, settings) {
      $('#documentFlex').FlexPaperViewer({
        config : {
          PDFFile : '/sites/all/modules/custom/egw_oauth/files/38.pdf',
          SwfFile: '/sites/all/modules/custom/egw_oauth/files/381.swf',
          JSONFile: '/sites/all/modules/custom/egw_oauth/files/38.js',
          IMGFiles: '/sites/all/modules/custom/egw_oauth/files/38_1.png',
          jsDirectory: '/sites/all/libraries/flexpaper/js/',
          cssDirectory: '/sites/all/libraries/flexpaper/css/',
          localeDirectory: '/sites/all/libraries/flexpaper/locale/',
          key : "$47ee5411a2cb791b9eb",
          Scale : 0.6,
          ZoomTransition : 'easeOut',
          ZoomTime : 0.5,
          ZoomInterval : 0.2,
          FitPageOnLoad : true,
          FitWidthOnLoad : false,
          FullScreenAsMaxWindow : false,
          SearchMatchAll : false,
          InitViewMode : 'Portrait',
          RenderingOrder : 'html5',
          StartAtPage : '',
          ViewModeToolsVisible : true,
          ZoomToolsVisible : true,
          NavToolsVisible : true,
          CursorToolsVisible : true,
          SearchToolsVisible : true,
          localeChain: 'en_US'
        }
      });
      $(document).on('click','.flexpaper_bttnFullScreen',function(document){

      });
    }
  }
})(jQuery);
