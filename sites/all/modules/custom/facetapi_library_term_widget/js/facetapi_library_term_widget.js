(function ($) {
    Drupal.behaviors.facetapiLibraryTermWidget = {
        attach: function (context, settings) {
            //Create library combobox widget
            $.widget("ui.libraryCombobox", {
                _create: function () {
                    var self = this;
                    var select = this.element.hide();
                    //Marker element which allow to decline chosen filters  
                    var marker = '<a class="' + self.options.markerClass + '" href="">X</a>';
                    var markerClickHandler = function(event, object){
                        var parent = $(object).parent();
                        var value = parent.find('input').val();
                        var label = parent.find('label').text();
                        //Get items from input, remove needed and push it back
                        var items = JSON.parse($('#' + self.options.containerId).val());
                        items.splice( items.indexOf( value ), 1 );
                        items = JSON.stringify(items);
                        $('#' + self.options.containerId).val(items);
                        //Return option to select element
                        select.append('<option value="' + value +'">' + label + '</option>');
                        event.preventDefault();
                        parent.remove();
                    }
                    var input = $("<input />")
                        .insertAfter(select)                        
                        .autocomplete({
                            delay: 0,
                            minLength: 0,
                            source: function (request, response) {
                                var matcher = new RegExp($.ui.autocomplete.escapeRegex(request.term), "i");
                                response(select.children("option").map(function () {
                                    var text = $(this).text();
                                    if (this.value && ( !request.term || matcher.test(text) ))
                                        return {
                                            label: text.replace(
                                                new RegExp(
                                                    "(?![^&;]+;)(?!<[^<>]*)(" +
                                                        $.ui.autocomplete.escapeRegex(request.term) +
                                                        ")(?![^<>]*>)(?![^&;]+;)", "gi"),
                                                "<strong>$1</strong>"),
                                            value: text,
                                            option: this
                                        };
                                }));
                            },
                            select: function (event, ui) {
                                ui.item.option.selected = true;
                                self._trigger("selected", event, {
                                    item: ui.item.option
                                });
                                //Add items in input
                                var items = JSON.parse($('#' + self.options.containerId).val());
                                items[items.length] = ui.item.option.value;
                                items = JSON.stringify(items);
                                $('#' + self.options.containerId).val(items);
                                list.append('<li><input type="hidden" value="' + ui.item.option.value + '"><label class="facetapi-term-widget-item-label">' + ui.item.option.text + '</label>' + marker + '</li>');
                                $('.' + self.options.markerClass).unbind('click');
                                $('.' + self.options.markerClass).click(function(event){
                                    markerClickHandler(event, this);
                                });
                                //Remove option from select element
                                var children = select.children('option[value="' + ui.item.option.value + '"]');
                                children.remove();
                                // children.each
                            },
                            change: function (event, ui) {
                                if (!ui.item) {
                                    var matcher = new RegExp("^" + $.ui.autocomplete.escapeRegex($(this).val()) + "$", "i"),
                                        valid = false;
                                    select.children("option").each(function () {
                                        if (this.value.match(matcher)) {
                                            this.selected = valid = true;
                                            return false;
                                        }
                                    });
                                    if (!valid) {
                                        // remove invalid value, as it didn't match anything
                                        $(this).val("");
                                        select.val("");
                                        return false;
                                    }
                                }
                            }
                        })
                        .addClass("ui-widget ui-widget-content ui-corner-left");
                    input.data("autocomplete")._renderItem = function (ul, item) {
                        return $("<li></li>")
                            .data("item.autocomplete", item)
                            .append("<a>" + item.label + "</a>")
                            .appendTo(ul);
                    };
                    //List of selected items
                    var list = $('<ul class="facetapi-library-term-widget-list" type="none"></ul>').insertBefore(input);
                    //Put default items in list
                    var defaultItems = self.options.defaultItems;
                    for (var defaultItem in defaultItems){
                        list.append('<li><input type="hidden" value="' + defaultItem + '"><label class="facetapi-term-widget-item-label">' + defaultItems[defaultItem] + '</label>[' + marker + ']</li>');
                        $('.' + self.options.markerClass).unbind('click');
                        $('.' + self.options.markerClass).click(function(event){
                            markerClickHandler(event, this);
                        });
                    }

                    $('<button> </button>')
                        .attr("tabIndex", -1)
                        .attr("title", "Show All Items")
                        .insertAfter(input)
                        .button({
                            icons: {
                                primary: "ui-icon-triangle-1-s"
                            },
                            text: false
                        })
                        .removeClass("ui-corner-all")
                        .addClass("ui-corner-right ui-button-icon")                
                    .click(function (event) {
                            // close if already visible
                            if (input.autocomplete("widget").is(":visible")) {
                                input.autocomplete("close");
                                return;
                            }
                            // pass empty string as value to search for, displaying all results
                            input.autocomplete("search", "");
                            input.focus();
                        return false;
                        });

                }
            });
            //Get all forms with library term widget
            var forms = Drupal.settings.facetapi_library_term_widget.forms;
            $.each(forms, function (formId, formIdProperties) {
                var selectId = formIdProperties.selectId;
                var combobx = $('#' + selectId).libraryCombobox({
                    form: formId,
                    containerId: formIdProperties.itemContainerId,
                    defaultItems: formIdProperties.defaultItems,
                    markerClass: formIdProperties.markerClass
                });
            });
        }
    }
})(jQuery);