This script is intended for instructor-guided use during on-site live hands-on courses at StarWest, StarEast, and elsewhere.

The preference here is to place documentation in the script itself rather than in external documents.

This repo's name includes <strong>starter</strong> because it contains examples of how to code many of the constructs needed in advanced scripts in productive use:

 * VTS (Virtual Table Server) provided within LoadRunner.
 * A library of utility functions.
 * Example use of Google JWT (Java Web Tokens) 

CAUTION: Although the example script here is meant for stress testing, the script in this repo should not be run by more than one virtual users over more than a few seconds because it accesses a production site with usage limits.
That's the setting in the scenario file in the Scenario folder within this script.

Google's API was chosen as the system under test since Google has provides a well-documented implementation of their JWT (Java Web Toolkit) which more and more enterprises are adopting.

## To use this script 

 1. Install LoadRunner 11.52 on a Windows machine.
 2. Install a git client.
 3. Make a folder.
 4. Clone this repo within that folder (after creating an account on Github.com, if you haven't already).
 5. Create your own Google API account (if you haven't already).
 6. Paste keys from your Google account into the keys text file.
 7. Open this script within VuGen LoadRunner.
 8. Execute the script.

 9. Double-click the Scenario1.lrs file within the Scenario folder.
 10. Change the Script folder to point to the path to this repo on your hard disk.
 11. Change the Results folder path.

## Files in this repo
* <strong>.gitignore</strong> is used by the collaborators of this repo for git clients to automatically block some files from being updated to github.com.

* <strong>output.txt</strong> is saved from the last run of this script using VuGen, with verbosity set to maximum.

* <strong>lr_js_date_lib.js</strong> is copied from <a target="_blank" href="https://github.com/wilsonmar/LoadRunner/tree/master/random_birthdate_js"> the random_birthday_js</a> sample script from the same author (Wilson Mar at wilsonmar+github@gmail.com).

* <strong>oauthhelper.dll</strong> is copyrighted by Phillip Mayhew.
* <strong>vuser_init.c</strong> contains global variable definitions.
* <strong>action.c</strong> contains main loop functions.
* <strong>wi_library.c</strong> contains utility functions used by many scripts.

