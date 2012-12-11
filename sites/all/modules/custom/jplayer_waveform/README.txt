CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Player kinds
 * Upgrading
 * Known issues
 * Support
 * Sponsorship


INTRODUCTION
------------

The jPlayer module provides a wrapper around the jPlayer JavaScript library.
This library provides an HTML5-based player, that uses a Flash fallback for
browsers that do not support it. This module provides a default presentation for
the player, as well as integration with file fields. This makes it possible to
easily convert the display of any file field into an audio or video player.

This player will work with the media types jPlayer supports: mp3, m4a, m4v, oga,
ogv, webma, webmv, wav. (Also jpeg, jpg and png for poster artwork.) Please be
sure to restrict the file upload extensions on your file fields to only allow
these extensions, or less depending on your requirements.


INSTALLATION
------------

 1. Drop the 'jplayer' folder into the modules directory '/sites/all/modules/'.

 2. Download jPlayer from http://www.jplayer.org/download/. The downloaded
    directory only contains 2 files, 'jquery.jplayer.min.js' and
    'Jplayer.swf'. Place these two files in 'sites/all/libraries/jplayer/'.

 3. In your Drupal site, enable the module under Administration -> Modules
    '?q=/admin/modules'.

 4. Global admin settings for jPlayer can be found Administration ->
    Configuration -> jPlayer '?q=admin/config/media/jplayer'.

 5. When you manage the display of file fields within your content types 
    '?q=admin/structure/types/manage/{type}/display', choose 'jPlayer - Player'
    as the format. You can then configure the settings available for that
    instance.



THEMING
------------

The jPlayer default output uses a lot of CSS to get the player looking
respectable. This default set of CSS is based on the demonstration skin provided
at http://www.happyworm.com/jquery/jplayer/latest/demos.htm.

Note that the default HTML output of jPlayer module is a standard template that
other "skins" may work with. It is highly suggest to not override the
jplayer.tpl.php file and instead build all your custom theming on top of the
default HTML through CSS.

To override the CSS file:

 * Copy (or create a new .css file) and place it in your theme with the same
   name as the original (jplayer.css).

 * In your theme .info file, add the line:

     stylesheets[all][] = jplayer.css

   to point to the new css file in your theme. If your file is a sub-directory,
   you will need adjust the stylesheet declaration to include that
   sub-directory.

     stylesheets[all][] = css/jplayer.css

   jplayer.css and jplayer.jpg have to be in the same folder, so if you want to
   override one of them copy also the other one. For more information, see
   https://drupal.org/node/263967.

To override the Javascript file:

 * Copy (or create a new .js file) and place it in your theme with the same
   name as the original (jplayer.js).

 * In your theme .info file, add the line:

     scripts[] = jplayer.js

   to point to new new javascript file in your theme. If your file is a
   sub-directory, you will adjust the JavaScript declaration to include that
   sub-directory.

   For more information, see http://drupal.org/node/171213.


UPGRADING
---------

Since the jPlayer module is purely a formatter most of the upgrade work required
will be in upgrading from old CCK File Fields into new core File Fields in
Drupal 7. Apart from that you will need to re-select your formatters after
upgrading to this new version.


SUPPORT
-------

Many issues you may have may be caused by jPlayer library itself, rather than
the Drupal module. Check with the jPlayer support pages for issues with Flash
warnings or the player behaving oddly:

http://www.jplayer.org/support/

If the problem is with the jPlayer Drupal module, please file a support request
at http://drupal.org/project/issues/jplayer.


SPONSORSHIP
-----------

The D7 branch of this module is currently sponsored by Holy Trinity Brompton
(http://www.htb.org.uk), and Cultivate4 (http://www.cultivatefour.com). Work has
been undertaken by Jordan de Laune.

The original D6 module was written by Nate Haug and was maintained by Blazej
Owczarczyk.



Information added by drupal.org packaging script on 2012-06-19
version = "7.x-2.0-beta1+10-dev"
core = "7.x"
project = "jplayer"
datestamp = "1340108610"
