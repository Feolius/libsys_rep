<?php drupal_add_css(drupal_get_path('theme', 'corporateclean') . '/tweet_button.css')?>
<!-- Header. -->
<div id="header">

    <div id="header-inside">
    
        <div id="header-inside-left">
            
            <?php if ($logo): ?>
            <a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
            <?php endif; ?>
     
            <?php if ($site_name || $site_slogan): ?>
            <div class="clearfix">
            <?php if ($site_name): ?>
            <span id="site-name"><a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a></span>
            <?php endif; ?>
            <?php if ($site_slogan): ?>
            <span id="slogan"><?php print $site_slogan; ?></span>
            <?php endif; ?>
            </div><!-- /site-name-wrapper -->
            <?php endif; ?>
            
        </div>
            
        <div id="header-inside-right">
		<?php print render($page['search_area']); ?>    
        </div>
    
    </div><!-- EOF: #header-inside -->

</div><!-- EOF: #header -->

<!-- Header Menu. -->
<div id="header-menu">

<div id="header-menu-inside">
    <?php 
	if (module_exists('i18n_menu')) {
	$main_menu_tree = i18n_menu_translated_tree(variable_get('menu_main_links_source', 'main-menu'));
	} else {
	$main_menu_tree = menu_tree(variable_get('menu_main_links_source', 'main-menu')); 
	}
	print drupal_render($main_menu_tree);
	?>
</div><!-- EOF: #header-menu-inside -->

</div><!-- EOF: #header-menu -->

<!-- Banner. -->
<div id="banner">

	<?php print render($page['banner']); ?>
	
    <?php if (theme_get_setting('slideshow_display','corporateclean')): ?>
    
    <?php if ($is_front): ?>
    
    <!--slideshow-->
    <div id="slideshow">
    
        <!--slider-item-->
        <div class="slider-item">
            <div class="content">
                
                <!--slider-item content-->
                <div style="float:left; padding:0 30px 0 0;">
                <img height="250px" class="masked" src="<?php print base_path() . drupal_get_path('theme', 'corporateclean') ;?>/mockup/slide-1.jpg"/>
                </div>
                <h2>Ellen G. White Estate</h2>
                <p>The Ellen G. White Estate, Incorporated, or simply the (Ellen) White Estate, is the official organization created by Ellen G. White to act as the custodian of her writings, which are of importance to the Seventh-day Adventist Church. Based at the General Conference in Silver Spring, Maryland, with which it works closely, the White Estate has branch offices and research centers at Adventist universities and colleges around the world.</p>
		<p>The mission of the White Estate is to circulate Ellen White's writings, translate them, and provide resources for helping to better understand her life and ministry. At the Toronto General Conference Session in 2000, the world church expanded the mission of the organization to include a responsibility for promoting Adventist history for the entire denomination.</p>
                <div style="display:block; padding:30px 0 10px 0; float: left"><a class="more" href="#">Tell me more</a></div>
                <a href="https://twitter.com/ellenwhite" class="twitter-follow-button" data-show-count="false" data-size="large" >Follow @ellenwhite</a>
                <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
                <!--EOF:slider-item content-->
                
            </div>
        </div>
        <!--EOF:slider-item-->
        
        <!--slider-item-->
        <div class="slider-item">
            <div class="content">
            
                <!--slider-item content-->
                <div style="float:right; padding:0 0 0 30px;">
                <img height="250px" class="masked" src="<?php print base_path() . drupal_get_path('theme', 'corporateclean') ;?>/mockup/slide-2.jpg"/>
                </div>
                <h2>Center for Adventist Research</h2>
                <p>The Center for Adventist Research is a leading documentary collection for the study of the Seventh-day Adventist Church, its predecessors and related groups, from the Millerite movement of the mid nineteenth century to the present. The Center holds publications in all formats on all aspects of the Seventh-day Adventist Church--its mission, theology, and activities--including those from official and unofficial sources. The center serves as a Branch Office of the Ellen G. White Estate, the rare material repository for the James White Library and as the Andrews University Archives and Records Center.</p
		<p>Any conclusions, published or unpublished, drawn by researchers using Center for Adventist Research resources are the responsibility of the researcher and do not necessarily reflect those of the Center for Adventist Research, Andrews University, Ellen G.  White Estate, or the Seventh-day Adventist church.</p>
                <div style="display:block; padding:30px 0 10px 0;"><a class="more" href="#">Tell me more</a></div>
                
                <!--EOF:slider-item content-->
            
            </div>
        </div>
        <!--EOF:slider-item-->
        
        <!--slider-item-->
        <div class="slider-item">
            <div class="content">
            
                <!--slider-item content-->
                <div style="float:right; padding:0 0 0 30px;">
                <img height="250px" class="masked" src="<?php print base_path() . drupal_get_path('theme', 'corporateclean') ;?>/mockup/slide-3.jpg"/>
                </div>
                <h2>Office of Archives, Statistics, and Research</h2>
                <p>The Office of Archives, Statistics, and Research has been established for the purpose of managing the Records Center and Archives of the denomination's world headquarters, conduct research projects for General Conference administration, produce the denomination's annual directory, the Yearbook, and its annual statistical report. The Office is located in the lower level of the headquarters complex, and includes a fireproof, climate-controlled vault, two workrooms, and office space for its staff. While its responsibilities are limited to the headquarters complex, its staff members are available as consultants to the church's organizations and institutions, as time permits.</p>
                <div style="display:block; padding:30px 0 10px 0;  float: left"><a class="more" href="#">Tell me more</a></div>
		<a href="https://twitter.com/gcarchives" class="twitter-follow-button" data-show-count="false" data-size="large">Follow @gcarchives</a>
                <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
                <!--EOF:slider-item content-->
            
            </div>
        </div>
        <!--EOF:slider-item-->
        
    
    </div>
    <!--EOF:slideshow-->
    
    <!--slider-controls-wrapper-->
    <div id="slider-controls-wrapper">
        <div id="slider-controls">
            <ul id="slider-navigation">
                <li><a href="#"></a></li>
                <li><a href="#"></a></li>
                <li><a href="#"></a></li>
            </ul>
        </div>
    </div>
    <!--EOF:slider-controls-wrapper-->
    
    <?php endif; ?>
    
	<?php endif; ?>  

</div><!-- EOF: #banner -->


<!-- Content. -->
<div id="content">

    <div id="content-inside" class="inside">
    
        <div id="main">
            
            <?php if (theme_get_setting('breadcrumb_display','corporateclean')): print $breadcrumb; endif; ?>
            
            <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
       
            <?php if ($messages): ?>
            <div id="console" class="clearfix">
            <?php print $messages; ?>
            </div>
            <?php endif; ?>
     
            <?php if ($page['help']): ?>
            <div id="help">
            <?php print render($page['help']); ?>
            </div>
            <?php endif; ?>
            
            <?php if ($action_links): ?>
            <ul class="action-links">
            <?php print render($action_links); ?>
            </ul>
            <?php endif; ?>
            
			<?php print render($title_prefix); ?>
            <?php if ($title): ?>
            <h1><?php print $title ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
            
            <?php if ($tabs): ?><?php print render($tabs); ?><?php endif; ?>
            
            <?php print render($page['content']); ?>
            
            <?php print $feed_icons; ?>
            
        </div><!-- EOF: #main -->
        
        <div id="sidebar">
             
            <?php print render($page['sidebar_first']); ?>

        </div><!-- EOF: #sidebar -->

    </div><!-- EOF: #content-inside -->

</div><!-- EOF: #content -->

<!-- Footer -->    
<div id="footer">

    <div id="footer-inside">
    
        <div class="footer-area first">
        <?php print render($page['footer_first']); ?>
        </div><!-- EOF: .footer-area -->
        
        <div class="footer-area second">
        <?php print render($page['footer_second']); ?>
        </div><!-- EOF: .footer-area -->
        
        <div class="footer-area third">
        <?php print render($page['footer_third']); ?>
        </div><!-- EOF: .footer-area -->
       
    </div><!-- EOF: #footer-inside -->

</div><!-- EOF: #footer -->

<!-- Footer -->    
<div id="footer-bottom">

    <div id="footer-bottom-inside">
    
    	<div id="footer-bottom-left">
        
            <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('class' => array('secondary-menu', 'links', 'clearfix')))); ?>
            
            <?php print render($page['footer']); ?>
            
        </div>
        
        <div id="footer-bottom-right">
        
        	<?php print render($page['footer_bottom_right']); ?>
        
        </div><!-- EOF: #footer-bottom-right -->
       
    </div><!-- EOF: #footer-bottom-inside -->

</div><!-- EOF: #footer -->
