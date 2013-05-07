(function ($) {
  Drupal.behaviors.facetapiDateRange = {
    attach: function (context, settings) {
      var iconPath = Drupal.settings.facetapi_date_range_widget.iconPath;

      //Get all forms with date widget
      var forms = Drupal.settings.facetapi_date_range_widget.forms;
      $.each( forms, function(formId, formIdProperties){

        //Get id of all elements
        var minValueId = formIdProperties.minValueId;
        var maxValueId = formIdProperties.maxValueId;
        var minDatepickerID = formIdProperties.minDatepickerID;
        var maxDatepickerID = formIdProperties.maxDatepickerID;
        var sliderID = formIdProperties.sliderID;

        //Get current values and both limits
        var minValue = formIdProperties.minValue;
        var maxValue = formIdProperties.maxValue;
        var leftLimit = formIdProperties.leftLimit;
        var rightLimit = formIdProperties.rightLimit;
        minValue = checkMinDate(minValue, leftLimit);
        maxValue = checkMaxDate(maxValue, leftLimit);

        //Create Date ojects to operate with elements
        var leftLimitDateObj = new Date(leftLimit);
        var rightLimitDateObj = new Date(rightLimit);
        var minDateObj = new Date(minValue);
        var maxDateObj = new Date(maxValue);

        //Convert ISO dates to milliseconds UNIX
        var minValueInMilliseconds = minDateObj.getTime();
        var maxValueInMilliseconds = new Date(maxValue).getTime();
        var leftLimitInMilliseconds = new Date(leftLimit).getTime();
        var rightValueInMilliseconds = new Date(rightLimit).getTime();

        //Create datapickers
        $( "#" + minDatepickerID ).datepicker(
        {
          showOn: "button",
          changeMonth: true,
          changeYear: true,
          buttonImage: iconPath,
          buttonImageOnly: true,
          minDate: leftLimitDateObj,
          maxDate: rightLimitDateObj,
          onSelect : function (dateText, inst){

            //We should change slider value and values in form that will be pass to form submiter
            var dateObj = new Date(dateText);
            var selectedDateInMilliseconds = dateObj.getTime();
            $( "#" + minValueId).val(dateText);
            $( "#" + sliderID ).slider('values', 0, selectedDateInMilliseconds);
          }
        });
        $( "#" + minDatepickerID ).datepicker('setDate', minDateObj);
        $( "#" + minDatepickerID ).datepicker( "option", "dateFormat", "yy/mm/dd" );        
        $( "#" + minValueId ).focusout(function(eventObject){
          var value = eventObject.currentTarget.value;
          value = checkMinDate(value, leftLimit);
          var dateObj = new Date(value);
          var selectedDateInMilliseconds = dateObj.getTime();
          $ ( "#" + minDatepickerID ).datepicker( "setDate", value);
          $( "#" + sliderID ).slider("values", 0, selectedDateInMilliseconds);
        });
        $( "#" + maxDatepickerID ).datepicker(
        {
          showOn: "button",
          changeMonth: true,
          changeYear: true,
          buttonImage: iconPath,
          buttonImageOnly: true,
          minDate: leftLimitDateObj,
          maxDate: rightLimitDateObj,
          onSelect: function( dateText, inst ) {
            var dateObj = new Date(dateText);
            var selectedDateInMilliseconds = dateObj.getTime();
            $( "#" + sliderID ).slider("values", 1, selectedDateInMilliseconds);
            $( "#" + maxValueId).val(dateText);
          }
        });
        $( "#" + maxDatepickerID ).datepicker('setDate', maxDateObj);
        $( "#" + maxDatepickerID ).datepicker( "option", "dateFormat", "yy/mm/dd" );
        $( "#" + maxValueId ).focusout(function(eventObject){
          var value = eventObject.currentTarget.value;
          value = checkMaxDate(value, rightLimit);
          var dateObj = new Date(value);
          var selectedDateInMilliseconds = dateObj.getTime();
          $( "#" + maxDatepickerID).val(value);
          $( "#" + sliderID ).slider("values", 1, selectedDateInMilliseconds);
        });
        $( "#" + sliderID ).slider({
          range: true,
          min: leftLimitInMilliseconds,
          max: rightValueInMilliseconds,
          values: [minValueInMilliseconds, maxValueInMilliseconds],
          slide: function( event, ui ) {

            //Change values in datepickers and values in form that will be passed to form submiter
            var minValueId = formIdProperties.minValueId;
            var maxValueId = formIdProperties.maxValueId;
            minValue = new Date(ui.values[0]);
            $( "#" + minDatepickerID ).datepicker('setDate', minValue);
            var minValueYear = minValue.getFullYear().toString();
            var minValueMonth = (minValue.getMonth() + 1).toString();
            var minValueDay = minValue.getDate().toString();
            if (minValueMonth.length == 1){
              minValueMonth = '0' + minValueMonth;
            }
            if (minValueDay.length == 1){
              minValueDay = '0' + minValueDay;
            }
            minValue = minValueYear + '/' + minValueMonth + '/' + minValueDay;
            maxValue = new Date(ui.values[1]);
            $( "#" + maxDatepickerID ).datepicker('setDate', maxValue);
            var maxValueYear = maxValue.getFullYear().toString();
            var maxValueMonth = (maxValue.getMonth() + 1).toString();
            var maxValueDay = maxValue.getDate().toString();
            if (maxValueMonth.length == 1){
              maxValueMonth = '0' + maxValueMonth;
            }
            if (maxValueDay.length == 1){
              maxValueDay = '0' + maxValueDay;
            }
            maxValue = maxValueYear + '/' + maxValueMonth + '/' + maxValueDay;
            $( "#" + minValueId).val(minValue);
            $( "#" + maxValueId).val(maxValue);
          }
        });

      } );

    }
  }
  function checkMinDate (dateString, defaultValue){
    var dateParts = dateString.split('/');
    var numberOfDateParts = dateParts.length;
    switch (numberOfDateParts) {
      case 3:
        break;
      case 2:
        if (dateParts[1].length == 1){
          dateParts[1] = "0" + dateParts[1];
        }
        dateString = dateParts[0] + '/' + dateParts[1] + '/01';
        break;
      case 1:
        dateString = dateString + '/01/01';
        break;
      default:
        dateString = defaultValue;
        break;
    }
    return dateString;
  }
  function checkMaxDate (dateString, defaultValue){
    var dateParts = dateString.split('/');
    var numberOfDateParts = dateParts.length;
    switch (numberOfDateParts) {
      case 3:
        break;
      case 2:
        var year = parseInt(dateParts[0]);
        var month = parseInt(dateParts[1]);
        var daysNumber = new Date(year, month, 0).getDate().toString();
        if (daysNumber.length == 1){
          daysNumber = '0' + daysNumber;
        }
        if (dateParts[1].length == 1){
          dateParts[1] = "0" + dateParts[1];
        }
        dateString = dateParts[0] + '/' + dateParts[1] + '/' + daysNumber;
        break;
      case 1:
        dateString = dateString + '/12/31';
        break;
      default:
        dateString = defaultValue;
        break;
    }
    return dateString;
  }
})(jQuery);