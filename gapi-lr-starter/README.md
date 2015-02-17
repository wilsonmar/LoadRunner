
This script is referenced during on-site live hands-on courses.
The script is called starter because it contains use of many of the constructs needed in real scripts in productive use.

The preference is to place documentation in the script itself rather than in an external documen like this one.

This document is used to speculate on future enhancements, written as if the code has already been developed,
so it can be inserted in the script.


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

Within a LoadRunner script, code based on [this web page](http://h30499.www3.hp.com/t5/HP-LoadRunner-and-Performance/How-to-use-JavaScript-in-your-HP-LoadRunner-scripts/ba-p/6197321#.VMqXGl7F8eU)
can be used to reference established JavaScript functions.

The advantage of LoadRunner scripts reusing functions in a JavaScript utility library is to avoid losing time:
Time to write script code. Time to debug script code. Time to explain the code to others.
And more importantly, work to overcome miscommunication between the tester and developers if they don't share a library.

Below is sample LoadRunner code to obtain a text string into a LoadRunner parameter such as 
lr_eval_string("{BirthYYYYMMDD}").
The input specification YYYYMMDD is needed because there are different formats for dates.

* var d = new Date("July 21, 1983 01:15:00"); // defines the date object using JavaScript code.
* YYYYMMDD specifies a 4 digit year, 2 digit month, and 2 digit day of month.

```
    web_js_run(
        "Code=getWorkingAdultBirthDate('YYYYMMDD');",
        "ResultParam=BirthYYYYMMDD",
        SOURCES,
        "File=RandomBirthDate.js", ENDITEM,
        LAST);
```

The example above calls a file named **RandomBirthDate.js** stored in the script folder.

CHALLENGE: Add the javascript file among Extra Files in your LoadRunner script.

1. Paste the calling code at an approprite spot in your LoadRunner script.
2. Right-click on Extra Files.
3. Paste the JavaScript code into the file. Save the file.

BEST PRACTICE IDEA: Take a test-driven approach to developing code. Code from the "outside in".
Initially, inside a function, define the variable and a valid return value expected by the caller.

Initially, create the library file that returns the correct format.
That would be the birthdate for an 18 year old having a birthday today.

```
/* /file RandomBirthDate.js
   /desc returns dates 
    Example of caller: getWorkingAdultBirthDate('YYYYMMDD')
*/

function getWorkingAdultBirthDate(){
    var formatted_date;
    var years_worked = new Date();
    var now = new Date();

    // Random number between 18 and 64 years old today:
    
    // if YYYYMMDD:
    // 2015 - 18 = 1997
    formatted_date = (now.getFullYear() - 18) + "0503";

    return formatted_date;
}
```

BEST PRACTICE IDEA: Define functions to obtain the current date so that the propram still works in the future
without need to change hard-coded text.

During date of birth generation there is often a need to specify whether the birthdate is that of 
an adult, a child, a retiree, or of an entire population.
To avoid the need for callers to craft code to calculate age,
the library file contains different calling functions and parameters.

CAUTION: Quotes must be single quotes because they are within double quotes.

Instead of a string, the input parameter can come from a LoadRunner parameter already defined:

```
        "Code=getWorkingAdultBirthDate(LR.getParam('YYYYMMDD'));",
```

First debug the script in a HTML file
Better yet, avoid having to craft script library calls, use a (free) JavaScript environment such as:

http://jsfiddle.net/wilsonmar/3nyjurtc/

The HTML is:

'''
<form>
<input type="button" value="Click me!" onclick="javascript:web_js_run('YYYYMMDD')" />
</form>
<p>Pressing "Click me"</p>
working_age: <span id="working_age"></span>
Result: <span id="result"></span>
'''

The JavaScript emulates LoadRunner calls:

```
    var working_age;

function web_js_run(){
    var Birth_YYYYMMDD;
    Birth_YYYYMMDD = getWorkingAdultBirthDate('YYYYMMDD');
    // alert(Birth_YYYYMMDD);
    document.getElementById('result').innerHTML = Birth_YYYYMMDD;
    document.getElementById('working_age').innerHTML = working_age;
}
```


Click on the **Click me!** button in the Result pane for a pop-up with the answer.
The web_js_run() function is the equivalent of what Loadrunner does.

Invoke the LoadRunner program to make sure it returns what the LoadRunner script can use.

Next, define the various inputs into what is returned:

```
    var formatted_date, random_year, random_month, random_day;
    // 1. Get 4 digit random year from 1997 (18 yo)
    // 2. Get 2 digit month random from 1 to 12 
    // 3. Get 2 digit day within month random valid day for month and perhaps leap year 

    // based on statistics array.
```


We could call a function that randomly obtains a date within a range of two boundign dates:

* the birthdate of someone turning 65 (retiring) today
* the birthdate of of someone turning 18 (becoming an an adult) today

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

The year of birth is used to determine whether the year isLeapYear.
The edge test case is someone born Feb. 29 during a leap year.
For this purpose, we're saying such a person would have their birthday on the 28th during regular years.

The month is a random number evenely generated between 1 and 12.

The month and isLeapYear flag is input to a function to generate the number of days.
A random number is generated for Day of Birth between 1 and the number of days.

	Note JavaScript objects are created within the script.

The beginnings of that file is below:

```
function getAdultBirthDate(){
    var from_year, from_month, from_day
    // 	
    return randomDate(new Date(from_year, from_month, from_day), new Date()); // random date generator.
}


```



Sample C code LoadRunner may be able to use:

* http://www.codingunit.com/c-reference-stdlib-h-function-rand-generate-a-random-number
 
