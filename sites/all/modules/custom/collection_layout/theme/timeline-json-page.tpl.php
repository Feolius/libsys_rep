<html>
    <body>
        <div id="timeline-embed"></div>
        <script type="text/javascript">
            var timeline_config = {
                width: '100%',
                height: '100%',
                source: '/timeline-json',
                start_at_slide: <?php print $start_slide ?>
            }
        </script>
        <script type="text/javascript" src="<?php print $timeline_lib_url ?>"></script>
    </body>
</html>