(function ($) {
    Drupal.behaviors.collectionPagerBlock = {
        attach: function (context, settings) {
            $('#edit-result-number').keypress(function (event) {
                if (event.keyCode == 13) {
                    $('#edit-go-to-the-page-button').click();
                }
            });
        }
    }
})(jQuery);
