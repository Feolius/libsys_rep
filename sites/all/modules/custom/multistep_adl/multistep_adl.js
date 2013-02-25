
if (Drupal.jsEnabled) {
  $(document).ready(function () {
    $("input[name=multistep_adl_expose]").ready(function() { multistep_adl_toggle_settings(); });
    $("input[name=multistep_adl_expose]").click(function() { multistep_adl_toggle_settings(); });
  });
}

function multistep_adl_toggle_settings() {
  if ($("#edit-multistep-adl-expose-enabled").attr("checked") == true) {
    $("#multistep-adl-settings").removeClass("collapsed");
  }
  else {
    $("#multistep-adl-settings").addClass("collapsed");
  }
}
