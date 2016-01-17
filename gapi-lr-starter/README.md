This script is intented for guided used during on-site live hands-on courses at StarWest, StarEast, and elsewhere.
The preference is to place documentation in the script itself rather than in external documents.

This repo's name includes <strong>starter</strong> because it contains use of many of the constructs needed in real scripts in productive use:

 * VTS (Virtual Table Server) provided within LoadRunner.
 * A library of utility functions.
 * Use of Google JWT (Java Web Tokens) 

CAUTION: Although the example script here is meant for stress testing, the script in this repo should not be run by more than one virtual users over more than a few seconds because it accesses a production site with usage limits.
That's the setting in the scenario file in the Scenario folder within this script.

Google's API was chosen as the system under test since Google has provides a well-documented implementation of their JWT (Java Web Toolkit) that more and more enterprises are adopting.

CAUTION: Before running this script, create your own Google API account and paste the keys into the keys text files.

The Data folder
