
## Coding Challenges:

### <a name="birthdays"></a> Random Birthdays from Calling a JavaScript library

A birthday may need to be generated even when it can be provided because
each person's real birthday can be used as the basis for authentication and thus identity theft
and thus needs to be protected as secrets.
So generating a birth date randomly can be useful and expedient during testing.

DateofBirth fields can be gen'd using JavaScript functions in a UI such as 

* http://sqa.fyicenter.com/Online_Test_Tools/Test_User_Birthday_Date_Generator.php)
* https://www.random.org/calendar-dates/

JavaScript coding for generating birth dates are in web pages such as :

* http://stackoverflow.com/questions/9035627/elegant-method-to-generate-array-of-random-dates-within-two-dates

# LoadRunner Usage of JavaScript Library

Within a LoadRunner script, code based on [this web page](http://h30499.www3.hp.com/t5/HP-LoadRunner-and-Performance/How-to-use-JavaScript-in-your-HP-LoadRunner-scripts/ba-p/6197321#.VMqXGl7F8eU)
can be used to reference established JavaScript functions.

The advantage of LoadRunner scripts reusing functions in a JavaScript utility library is to avoid losing time:
Time to write script code. Time to debug script code. Time to explain the code to others.
And more importantly, work to overcome miscommunication between the tester and developers if they don't share a library.

Notes on dates written in C for LoadRunner is at
http://www.solutionmaniacs.com/blog/2012/8/24/loadrunner-date-handling-2-of-3-c-datetime-functions.html

Below is sample LoadRunner C code to call a JavaScript library to 
return a text string into a LoadRunner parameter such as 
lr_eval_string("{BirthYYYYMMDD}").

1. Paste this code into an appropriate line in the script, such as after identifying a row in VTS.

```
    web_js_run(
        "Code=getWorkingAdultRandomBirthDate('YYYY-MM-DD');",
        "ResultParam=BirthYYYYMMDD",
        SOURCES,
        "File=lr_js_date_lib.js", ENDITEM,
        LAST);
```

2. While you are there, right-click on the LoadRunner code line **after** this and set a **Breakpoint** so 
execution can pause there during debugging.

### Date formats

The format specification 'YYYY-MM-DD' is needed because there are different formats for dates:

* "YYYY-MM-DD" is for a date such as 2015-12-30. This is ISO 8601 popular everywhere outside the US.
* YYYYMMDD specifies a 4 digit year, 2 digit month, and 2 digit day of month.
* var d = new Date("July 21, 1983 01:15:00"); // defines the input to populate the data object using JavaScript code.

This example calls a file named **lr_js_date_lib.js** stored in the script folder.

BTW, instead of a hard-coded string, the input parameter can come from a LoadRunner parameter already defined:

```
        "Code=getWorkingAdultRandomBirthDate(LR.getParam('YYYY-MM-DD'));",
```


CHALLENGE: Add the javascript file among Extra Files in your LoadRunner script.

3. Paste the calling code at an approprite spot in your LoadRunner script.
4. Right-click on Extra Files within the VuGen Solution Explorer.
5. Specify the JavaScript file name.


PROTIP: Specify Doxygen tags for automatic generation of cross-reference documentation, whith
sample code to call the function.

CHALLENGE: Immediately after creating a file, at the top of the file add Doxygen tags.

6. Copy the sample JavaScript multi-line comment and paste it at the top of new file lr_js_date_lib.js.

```
/* /file lr_js_date_lib.js
   /desc returns dates 
    Example of caller: 
    web_js_run(
        "Code=getWorkingAdultRandomBirthDate('YYYY-MM-DD');",
        "ResultParam=Birth_date",
        SOURCES,
        "File=lr_js_date_lib.js", ENDITEM,
        LAST);
*/
```

PROTIP: Take a test-driven approach to developing code to finish quicker. Code from the "outside in".

CHALLENGE: Initially, return a static value in the format expected to ensure that the script connects.

7. Copy the sample initial JavaScript below and paste it at the bottom of new file lr_js_date_lib.js.

```
function getWorkingAdultRandomBirthDate( in_format ){
    // 2015 - 25 = 1990
    return "1990-05-03";
}
```

This intermediate example defines a static but valid return value expected by the caller.

The comments notes this is the birthdate of a 25-year old.

8. Run (and debug) the LoadRunner script to the block.

PROTIP: JavaScript within LoadRunner is difficult to debug, so first debug JavaScript outside LoadRunner
using an interactive environment such as Codepen.io or JSFiddle.net at

http://jsfiddle.net/wilsonmar/3nyjurtc/14/

The remainder of this document defines how you can create your own.

CHALLENGE: Define JavaScript and HTML that takes the place of how LoadRunner calls the underlying JavaScript functions.

1. Create your own account.
2. Create a new file.
3. Paste this at the top of the JavaScript pane:

```
'use strict';

function web_js_run(){
var birth_date;
    birth_date = getWorkingAdultRandomBirthDate('YYYY-MM-DD');
    // alert("birth_date=" + birth_date);
    document.getElementById('result').innerHTML = birth_date;
}
```

The `use strict` directive tells JavaScript to ensure that variables are specifically defined 
by a statement such as `var Birth_date`.

PROTIP: Where convenient, align variable names vertically to make it obvious where several lines of code are visually related.

CAUTION: Single quotes are used within JavaScript functios because there may be double quotes surrounding them.

4. Paste this into the HTML pane:

```
<form>
<input type="button" value="Click me!" onclick="javascript:web_js_run()" />
</form>
<p>Pressing "Click me"</p>
Today: <span id="today"></span><br />
<!-- 
PROTIP: When there are several substitutions on a line, to preserve spacing, and make updates less visually jarring, put placeholder characters where real values will go.
-->
Age: <span id="working_age">??</span>
Result: <span id="result">YYYY-MM-DD</span>
```

This defines how values returned from the JavaScript function is displayed.


PROTIP: Define functions to obtain the current date so that the program still works in the future
without need to change hard-coded text.

During date of birth generation there is often a need to specify whether the birthdate is that of 
an adult, a child, a retiree, or of an entire population.
To avoid the need for callers to craft code to calculate age,
the library file contains different calling functions and parameters.


Invoke the LoadRunner program to make sure it returns what the LoadRunner script can use.

Next, define the various inputs into what is returned:

### Month

The month is a random number evenly generated between 1 and 12.
We use a function that randomly returns a number within a range of two numbers:
This is similar to sample C code LoadRunner at:

* http://www.codingunit.com/c-reference-stdlib-h-function-rand-generate-a-random-number

### Age

That lower level function should use consider the relative chance of ages
based on actual population statistics.
So when function ___ is first envoked,
a random floating point number between 0 and 1.0 is generated to pick where on a table of ages the lucky person lands.
The function then looks up the cumulative percentage between 0 and 100 
in the hard-coded array 
and picks the corresponding age associated with the percentage.

The array is based on a the age range distribution derived for 
the country as a whole by the US Census, provided by API sites such as 

https://www.census.gov/population/age/data/2012comp.html.

Different statistics are relevant for male vs. female and across
different geographies, and across time.

If you want to use a different set of statistics, just replace the array containing the same format.
A future enhancement may be to externalize the arrary as a JSON file so that other age distributions can be specified by
simplying putting another file in the script, or specifying the file path in another run-time attribute.

The age from the array is used to calculate the year of birth through subtraction from the current year.
For purposes of this exercise, we use the mid-point in each range of ages.

       if (jQuery.inArray(name, names)!='-1') {
 
### Year

The year is used to determine whether the year isLeapYear.
The edge test case is someone born Feb. 29 during a leap year.
For this purpose, we're saying such a person would have their birthday on the 28th during regular years.

The month and isLeapYear flag is input to a function to generate the number of days.
A random number is generated for Day of Birth between 1 and the number of days.

### Enable JavaScript Parsing in LoadRunner

When the script is run, if you didn't “Enable running JavaScript code” in Replay (F4) Run-Time Settings > Preferences > JavaScript, this message appears:

```
Action.c(81): Error -35052: Step 'web_js_run' requires that JavaScript engine be enabled in the Run-Time Settings  	[MsgId: MERR-35052]
```

### Watching JavaScript Engine Sizes in LoadRunner

TODO: 
