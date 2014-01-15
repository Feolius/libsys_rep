/**
 *
 * @file
 * Library background JS.
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.libraryShareGooglePlusOneButton = {
    attach: function(context, settings) {
      $('img.uploaded-image').once(function() {
        $(this).click(function(event) {
          $(this).remove();
          $(this).addClass('removed');
          var deleted_images = $('#edit-library-background-homepage-deleted-image').val();
          var id = $(this).attr('id');
          if (deleted_images) {
            $('#edit-library-background-homepage-deleted-image').val(deleted_images + ', ' + id);
          } else {
            $('#edit-library-background-homepage-deleted-image').val(id);
          }
        })
      })
    }
  }
})(jQuery, Drupal, this, this.document);
