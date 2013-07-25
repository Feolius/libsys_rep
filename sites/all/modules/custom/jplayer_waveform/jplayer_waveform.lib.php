<?php

/**
 * Waveform generating class
 * @author Andrew Freiday http://andrewfreiday.com/2010/04/29/generating-mp3-waveforms-with-php/
 */
/**
Apache License
Version 2.0, January 2004
http://www.apache.org/licenses/

TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION

1. Definitions.

"License" shall mean the terms and conditions for use, reproduction,
and distribution as defined by Sections 1 through 9 of this document.

"Licensor" shall mean the copyright owner or entity authorized by
the copyright owner that is granting the License.

"Legal Entity" shall mean the union of the acting entity and all
other entities that control, are controlled by, or are under common
control with that entity. For the purposes of this definition,
"control" means (i) the power, direct or indirect, to cause the
direction or management of such entity, whether by contract or
otherwise, or (ii) ownership of fifty percent (50%) or more of the
outstanding shares, or (iii) beneficial ownership of such entity.

"You" (or "Your") shall mean an individual or Legal Entity
exercising permissions granted by this License.

"Source" form shall mean the preferred form for making modifications,
including but not limited to software source code, documentation
source, and configuration files.

"Object" form shall mean any form resulting from mechanical
transformation or translation of a Source form, including but
not limited to compiled object code, generated documentation,
and conversions to other media types.

"Work" shall mean the work of authorship, whether in Source or
Object form, made available under the License, as indicated by a
copyright notice that is included in or attached to the work
(an example is provided in the Appendix below).

"Derivative Works" shall mean any work, whether in Source or Object
form, that is based on (or derived from) the Work and for which the
editorial revisions, annotations, elaborations, or other modifications
represent, as a whole, an original work of authorship. For the purposes
of this License, Derivative Works shall not include works that remain
separable from, or merely link (or bind by name) to the interfaces of,
the Work and Derivative Works thereof.

"Contribution" shall mean any work of authorship, including
the original version of the Work and any modifications or additions
to that Work or Derivative Works thereof, that is intentionally
submitted to Licensor for inclusion in the Work by the copyright owner
or by an individual or Legal Entity authorized to submit on behalf of
the copyright owner. For the purposes of this definition, "submitted"
means any form of electronic, verbal, or written communication sent
to the Licensor or its representatives, including but not limited to
communication on electronic mailing lists, source code control systems,
and issue tracking systems that are managed by, or on behalf of, the
Licensor for the purpose of discussing and improving the Work, but
excluding communication that is conspicuously marked or otherwise
designated in writing by the copyright owner as "Not a Contribution."

"Contributor" shall mean Licensor and any individual or Legal Entity
on behalf of whom a Contribution has been received by Licensor and
subsequently incorporated within the Work.

2. Grant of Copyright License. Subject to the terms and conditions of
this License, each Contributor hereby grants to You a perpetual,
worldwide, non-exclusive, no-charge, royalty-free, irrevocable
copyright license to reproduce, prepare Derivative Works of,
publicly display, publicly perform, sublicense, and distribute the
Work and such Derivative Works in Source or Object form.

3. Grant of Patent License. Subject to the terms and conditions of
this License, each Contributor hereby grants to You a perpetual,
worldwide, non-exclusive, no-charge, royalty-free, irrevocable
(except as stated in this section) patent license to make, have made,
use, offer to sell, sell, import, and otherwise transfer the Work,
where such license applies only to those patent claims licensable
by such Contributor that are necessarily infringed by their
Contribution(s) alone or by combination of their Contribution(s)
with the Work to which such Contribution(s) was submitted. If You
institute patent litigation against any entity (including a
cross-claim or counterclaim in a lawsuit) alleging that the Work
or a Contribution incorporated within the Work constitutes direct
or contributory patent infringement, then any patent licenses
granted to You under this License for that Work shall terminate
as of the date such litigation is filed.

4. Redistribution. You may reproduce and distribute copies of the
Work or Derivative Works thereof in any medium, with or without
modifications, and in Source or Object form, provided that You
meet the following conditions:

(a) You must give any other recipients of the Work or
Derivative Works a copy of this License; and

(b) You must cause any modified files to carry prominent notices
stating that You changed the files; and

(c) You must retain, in the Source form of any Derivative Works
that You distribute, all copyright, patent, trademark, and
attribution notices from the Source form of the Work,
excluding those notices that do not pertain to any part of
the Derivative Works; and

(d) If the Work includes a "NOTICE" text file as part of its
distribution, then any Derivative Works that You distribute must
include a readable copy of the attribution notices contained
within such NOTICE file, excluding those notices that do not
pertain to any part of the Derivative Works, in at least one
of the following places: within a NOTICE text file distributed
as part of the Derivative Works; within the Source form or
documentation, if provided along with the Derivative Works; or,
within a display generated by the Derivative Works, if and
wherever such third-party notices normally appear. The contents
of the NOTICE file are for informational purposes only and
do not modify the License. You may add Your own attribution
notices within Derivative Works that You distribute, alongside
or as an addendum to the NOTICE text from the Work, provided
that such additional attribution notices cannot be construed
as modifying the License.

You may add Your own copyright statement to Your modifications and
may provide additional or different license terms and conditions
for use, reproduction, or distribution of Your modifications, or
for any such Derivative Works as a whole, provided Your use,
reproduction, and distribution of the Work otherwise complies with
the conditions stated in this License.

5. Submission of Contributions. Unless You explicitly state otherwise,
any Contribution intentionally submitted for inclusion in the Work
by You to the Licensor shall be under the terms and conditions of
this License, without any additional terms or conditions.
Notwithstanding the above, nothing herein shall supersede or modify
the terms of any separate license agreement you may have executed
with Licensor regarding such Contributions.

6. Trademarks. This License does not grant permission to use the trade
names, trademarks, service marks, or product names of the Licensor,
except as required for reasonable and customary use in describing the
origin of the Work and reproducing the content of the NOTICE file.

7. Disclaimer of Warranty. Unless required by applicable law or
agreed to in writing, Licensor provides the Work (and each
Contributor provides its Contributions) on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied, including, without limitation, any warranties or conditions
of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
PARTICULAR PURPOSE. You are solely responsible for determining the
appropriateness of using or redistributing the Work and assume any
risks associated with Your exercise of permissions under this License.

8. Limitation of Liability. In no event and under no legal theory,
whether in tort (including negligence), contract, or otherwise,
unless required by applicable law (such as deliberate and grossly
negligent acts) or agreed to in writing, shall any Contributor be
liable to You for damages, including any direct, indirect, special,
incidental, or consequential damages of any character arising as a
result of this License or out of the use or inability to use the
Work (including but not limited to damages for loss of goodwill,
work stoppage, computer failure or malfunction, or any and all
other commercial damages or losses), even if such Contributor
has been advised of the possibility of such damages.

9. Accepting Warranty or Additional Liability. While redistributing
the Work or Derivative Works thereof, You may choose to offer,
and charge a fee for, acceptance of support, warranty, indemnity,
or other liability obligations and/or rights consistent with this
License. However, in accepting such obligations, You may act only
on Your own behalf and on Your sole responsibility, not on behalf
of any other Contributor, and only if You agree to indemnify,
defend, and hold each Contributor harmless for any liability
incurred by, or claims asserted against, such Contributor by reason
of your accepting any such warranty or additional liability.

END OF TERMS AND CONDITIONS

Copyright 2010 Andrew Freiday

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */
class Waveform {
  /**
   * Generate waveform data for given filename
   * @param string $file File to process (absolute path)
   * @return resource
   */
  public static function generateWaveformData($file) {

    ini_set("max_execution_time", "30000");

    // temporary file name
    $temp_directory_path = file_directory_temp();
    $temp_file_name = $temp_directory_path . DIRECTORY_SEPARATOR . substr(md5(time()), 0, 10);
    // copy from temp upload directory to current
    copy($file, "{$temp_file_name}_o.mp3");

    /**
     * convert mp3 to wav using lame decoder
     * First, resample the original mp3 using as mono (-m m), 16 bit (-b 16), and 8 KHz (--resample 8)
     * Secondly, convert that resampled mp3 into a wav
     * We don't necessarily need high quality audio to produce a waveform, doing this process reduces the WAV
     * to it's simplest form and makes processing significantly faster
     */
    $lame_application_path = variable_get('jplayer_waveform_lame_application_path', 'lame');

    exec("{$lame_application_path} {$temp_file_name}_o.mp3 -f -m m -b 16 --resample 8 {$temp_file_name}.mp3 && {$lame_application_path} --decode {$temp_file_name}.mp3 {$temp_file_name}.wav", $output, $return);

    // delete temporary files
    if (file_exists("{$temp_file_name}_o.mp3")) {
      unlink("{$temp_file_name}_o.mp3");
    }
    else {
      return FALSE;
    }

    if (file_exists("{$temp_file_name}.mp3")) {
      unlink("{$temp_file_name}.mp3");
    }
    else {
      return FALSE;
    }


    $filename = "{$temp_file_name}.wav";

    /**
     * Below as posted by "zvoneM" on
     * http://forums.devshed.com/php-development-5/reading-16-bit-wav-file-318740.html
     * as nadjiVrijednosti() defined above
     */
    if (file_exists($filename)) {
      $handle = fopen($filename, "r");
    }
    else {
      return FALSE;
    }

    if ($handle == FALSE) {
      return FALSE;
    }
    //dohvacanje zaglavlja wav datoteke
    $header = array();
    $header[] = fread($handle, 4);
    $header[] = bin2hex(fread($handle, 4));
    $header[] = fread($handle, 4);
    $header[] = fread($handle, 4);
    $header[] = bin2hex(fread($handle, 4));
    $header[] = bin2hex(fread($handle, 2));
    $header[] = bin2hex(fread($handle, 2));
    $header[] = bin2hex(fread($handle, 4));
    $header[] = bin2hex(fread($handle, 4));
    $header[] = bin2hex(fread($handle, 2));
    $header[] = bin2hex(fread($handle, 2));
    $header[] = fread($handle, 4);
    $header[] = bin2hex(fread($handle, 4));

    //bitrate wav
    $bits = hexdec(substr($header[10], 0, 2));
    $byte = $bits / 8;

    //get channels number
    $channels = hexdec(substr($header[6], 0, 2));

    if ($channels == 2) {
      $skip = 40;
    }
    else {
      $skip = 80;
    }

    $data = array();
    while (!feof($handle)) {
      $bytes = array();
      //get number of bytes depending on bitrate
      for ($i = 0; $i < $byte; $i++) {
        $bytes[$i] = fgetc($handle);
      }
      switch ($byte) {
        //get value for 8-bit wav
        case 1:
          $data[] = self::getAmplitude($bytes[0], $bytes[1]);
          break;
        //get value for 16-bit wav
        case 2:
          if (ord($bytes[1]) & 128) {
            $temp = 0;
          }
          else {
            $temp = 128;
          }
          $temp = chr((ord($bytes[1]) & 127) + $temp);
          $data[] = floor(self::getAmplitude($bytes[0], $temp) / 256);
          break;
      }
      //skip bytes for memory optimization
      fread($handle, $skip);
    }

    // close and cleanup
    fclose($handle);
    unlink("{$temp_file_name}.wav");

    return $data;
  }

  /**
   * Create image by pregenerated audio data.
   * @param $data
   * @return resource
   */
  public static function createImage($data, $width = 400, $height = 50, $background_color = '#EEEEEE') {
    // create original image width based on arguments
    $img = imagecreatetruecolor($width, $height);
    imagealphablending($img, FALSE);
    imagesavealpha($img, TRUE);

    // generate background color
    list($r, $g, $b) = self::html2rgb($background_color);
    $color = imagecolorallocate($img, $r, $g, $b);
    $transparent = imagecolorallocatealpha($img, 0, 0, 0, 127);
    imagefill($img, 1, 1, $color);

    //Calculate the count of frames which would displayed as one because of the image width value
    $frames_in_pixel = sizeof($data) / $width;
    //And also calculate the rounded value to improve performance of the loop
    $rounded_frames_in_pixel = round($frames_in_pixel);
    // loop through frames/bytes of wav data as generated above
    for ($x = 0; $x < $width; $x += 1) {
      // relative value based on height of image being generated
      // data values can range between 0 and 255
      $v = round((max(array_slice($data, round($x * $frames_in_pixel), $rounded_frames_in_pixel)) / 255.0 * $height));
      // draw the line on the image using the $v value and centering it vertically on the canvas
      imagefilledrectangle($img, $x, 0 + ($height - $v), $x, $height - ($height - $v), $transparent);
    }

    return $img;
  }

  /**
   * Get amplitude between two bytes?
   * @param  $byte1
   * @param  $byte2
   * @return
   */
  private static function getAmplitude($byte1, $byte2) {
    $byte1 = hexdec(bin2hex($byte1));
    $byte2 = hexdec(bin2hex($byte2));
    return ($byte1 + ($byte2 * 256));
  }

  /**
   * Great function slightly modified as posted by Minux at
   * http://forums.clantemplates.com/showthread.php?t=133805
   * @param  string $input #abcdef
   * @return array
   */
  private static function html2rgb($input) {
    $input = ($input[0] == "#") ? substr($input, 1, 6) : substr($input, 0, 6);
    return array(
      hexdec(substr($input, 0, 2)),
      hexdec(substr($input, 2, 2)),
      hexdec(substr($input, 4, 2))
    );
  }

}
