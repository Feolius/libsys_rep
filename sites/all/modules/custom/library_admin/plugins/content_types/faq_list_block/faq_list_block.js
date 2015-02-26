(function ($) {

  Drupal.behaviors.exampleModule = {
    attach: function(context, settings) {
      $('#edit-results a').click(function() {
        var toggle = $(this).html();
        if (toggle =='Show all') {
          $(this).html('Hide all');
        }
        else {
          $(this).html('Show all');
        }
        $('#showallfaq').toggle();
      //  return FALSE;
      });
      }
    };

})(jQuery);
