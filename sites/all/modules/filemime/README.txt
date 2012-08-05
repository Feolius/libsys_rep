// $Id: README.txt,v 1.1.4.4 2010/08/25 21:17:31 mfb Exp $

Drupal determines the MIME type of each uploaded file by applying a MIME 
extension mapping to the file name.  The default mapping is hard-coded 
in the file_default_mimetype_mapping() function: 
http://api.drupal.org/api/function/file_default_mimetype_mapping/7

This module allows site administrators to alter the built-in mapping.  
For example, you may wish to serve FLAC files as audio/flac rather than 
application/x-flac.

Custom mappings can be extracted from the server's mime.types file 
(often available on a path such as /etc/mime.types) and/or a 
site-specific mapping string, both of which must use the standard syntax 
for mime.types files.  For example:

audio/mpeg					mpga mpega mp2 mp3 m4a
audio/mpegurl					m3u
audio/ogg					oga ogg spx

After installing and enabling this module, the MIME extension mapping 
can be customized by visiting Administer > Configuration > Media > File 
MIME (admin/config/media/filemime).

Disabling this module will restore Drupal's built-in mapping.
