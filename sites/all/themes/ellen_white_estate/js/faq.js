/**
 * @file
 * FAQ JS.
 */
(function ( $, Drupal, window, document, undefined ) {
    Drupal.behaviors.libraryFaqSearch = {
        attach: function( context, settings ) {
            var settings = Drupal.settings.Library;
            var faq = Drupal.settings.Library.faq;
            $('input.search-faq').once(function() {
                $(this).click(function( event ) {
                    event.preventDefault();
                    var results = $('#faq-results');
                    results.html('');
                    var text = ($('input.search-faq-text').attr('value'));
                    if (text != '') {
                        var words = text.replace(',', ' ').split(" ");
                        for (var i = 0; i < words.length; i++) {
                            var $last_char = words[i].substring(words[i].length - 1);
                            if ($last_char == ',' || $last_char == ' ') {
                                words[i] = words[i].substr(0, words[i].length - 1);
                            }
                            removeItem(words, ['', ',', '.', '!', '?', '*', ':', ';']);
                        }
                        var matches = findText( words, faq );
                        if (matches.length) {
                            var links = buildLinks( matches );
                            for (var i = 0; i < links.length; i++) {
                                $(results).append('<li>' + links[i] + '</li>');
                            }
                        } else {
                            $(results).append(Drupal.t('No results found'));
                        }
                    }
                })
            })
        }
    }

    // Function for search keywords.
    function findText( words, array ) {
        var matches = [];
        $.each( array, function( index, element ) {
            for (var i = 0; i < words.length; i++) {
                var word = words[i].toLocaleLowerCase();
                var keywords = element.keywords.toLocaleLowerCase();
                var title = element.title.toLocaleLowerCase();
                if ( keywords.indexOf( word ) !== -1 || title.indexOf( word ) !== -1 ) {
                    if ($.inArray(element, matches) == -1) {
                        matches.push( element );
                    }
                }
            }
        });
        return matches;
    }

    // Function for build links by search results.
    function buildLinks( matches ) {
        var links = [];
        for (var i = 0; i < matches.length; i++) {
            var path = matches[i].alias != '' ? matches[i].alias : 'node/' + matches[i].nid;
            var link = '<a href="'+ path +'">'+ matches[i].title +'</a>';
            links.push(link);
        }
        return links;
    }

    // Function for remove item from array.
    function removeItem( array, items ) {
        for (var i in array) {
            $.each(items, function( index, element ) {
                if (array[i] == element) {
                    array.splice(i, 1);
                }
            });
        }
    }

    Drupal.behaviors.libraryMenuSectionItem = {
        attach: function(context, settings) {
            $('ul.menu li a.section').once(function() {
                $(this).click(function(e) {
                    e.preventDefault();
                })
            })
        }
    }

})(jQuery, Drupal, this, this.document);

