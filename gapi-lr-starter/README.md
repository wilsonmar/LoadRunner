This script is intended for instructor-guided use during on-site live hands-on courses at StarWest, StarEast, and elsewhere.

The preference here is to place documentation in the script itself rather than in external documents.

This repo's name includes <strong>starter</strong> because it contains examples of how to code many of the constructs needed in advanced scripts in productive use:

 * VTS (Virtual Table Server) provided within LoadRunner.
 * A library of utility functions.
 * Example use of Google JWT (Java Web Tokens) 

CAUTION: Although the example script here is meant for stress testing, the script in this repo should not be run by more than one virtual users over more than a few seconds because it accesses a production site with usage limits.
That's the setting in the scenario file in the Scenario folder within this script.

Google's API was chosen as the system under test since Google has provides a well-documented implementation of their JWT (Java Web Toolkit) which more and more enterprises are adopting.

CAUTION: Before running this script, create your own Google API account and paste the keys into the keys text files.

To use this script within LoadRunner on a Windows machine:

 0. Install LoadRunner 11.52
 0. Install a git client 
 0. Make a folder 
 1. Clone this repo within that folder

## Files in this repo
* <strong>.gitignore</strong> is used by the collaborators of this repo for git clients to automatically block some files from being updated to github.com.

* <strong>output.txt</strong> is saved from the last run of this script using VuGen, with verbosity set to maximum.

* <strong>lr_js_date_lib.js</strong> is copied from <a target="_blank" href="https://github.com/wilsonmar/LoadRunner/tree/master/random_birthdate_js"> the random_birthday_js</a> sample script from the same author (Wilson Mar at wilsonmar+github@gmail.com).

* <strong>oauthhelper.dll</strong> is copyrighted by Phillip Mayhew.
