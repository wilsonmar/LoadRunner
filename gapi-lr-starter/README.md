
This script is used during on-site live hands-on courses.

The preference is to place documentation in the script itself rather than in an external documen like this one.

This document is used to speculate on future enhancements, written as if the code has already been developed,
so it can be inserted in the script.


### <a name="birthdays"></a> Random Birthdays from Calling a JavaScript library

Within a LoadRunner script, code based on [this web page](http://h30499.www3.hp.com/t5/HP-LoadRunner-and-Performance/How-to-use-JavaScript-in-your-HP-LoadRunner-scripts/ba-p/6197321#.VMqXGl7F8eU)
can be used to reference JavaScript functions.

This is an example of how to do it.

A birthday may need to be generated even when it can be provided because
each person's real birthday can be used as the basis for authentication and thus identity theft
and thus needs to be protected as secrets.
So generating a birth date randomly can be useful and expedient during testing.

DateofBirth fields can be gen'd using JavaScript functions in a UI such as 
[this](http://sqa.fyicenter.com/Online_Test_Tools/Test_User_Birthday_Date_Generator.php)

```
    web_js_run(
        "Code=getAdultBirthDate(LR.getParam('BirthMonth'));",
        "ResultParam=BirthYYYYMMDD",
        SOURCES,
        "File=RandomBirthDate.js", ENDITEM,
        LAST);
```

In summary:

* DateOfBirthYear : random year from 1989 (19 yo), month / day 
* DateOfBirthMonth : random from 1 to 12 
* DateOfBirthDay : random valid day for month and perhaps leap year 

During date of birth generation there is often a need to specify whether the birthdate is that of 
an adult, a child, or of an entire population.
To avoid the need for callers to craft code to calculate age,
file RandomBirthDate.js contains different calling functions and parameters.

    When invoked, first a random floating point number between 0 and 1.0 is generated.

	The program then looks up the cumulative percentage between 0 and 100 
	in the hard-coded array 
	and picks the corresponding age associated with the percentage.

	The array is based on a the age range distribution derived for 
    the country as a whole by the 2010 US Census, provided by API sites such as http://developer.usatoday.com/apps/.
	Different statistics are relevant for male vs. female and across
	different geographies, and across time.

	So if you want to use a different set of statistics, just replace the array containing the same format.
	A future enhancement may be to externalize the arrary as a JSON file so that other age distributions can be specified by
	simplying putting another file in the script, or specifying the file path in another run-time attribute.

	The age from the array is used to calculate the year of birth through subtraction from the current year.

	The year of birth is used to determine whether the year isLeapYear.

	The month is a random number evenely generated between 1 and 12.

	The month and isLeapYear flag is input to a function to generate the number of days.
	A random number is generated for Day of Birth between 1 and the number of days.

	The beginnings of the JavaScript functions is below:

```
  /* automatically update days based on month */
  // randomly select year after 1996.
var iYear = random_year_from(1996);

window.updateMonth= function(iMonth, iDay) {
    var el = document.getElementById(iDay);
    el.options.length = 0;
   
    for(var d = new Date(iYear,iMonth-1,1); d.getMonth()==iMonth-1; d.setDate(d.getDate()+1)) {
        option = new Option(d.getDate(), d.getDate());
        el.options[d.getDate()-1] = option;
    }; 
}
```

	Note JavaScript objects are created within the script.

