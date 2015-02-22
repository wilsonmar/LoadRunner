/* /file lr_js_date_lib.js
   /desc returns dates 
    Example of caller: 
    web_js_run(
        "Code=getWorkingAdultRandomBirthDate('YYYY-MM-DD');",
        "ResultParam=birth_date",
        SOURCES,
        "File=lr_js_date_lib.js", ENDITEM,
        LAST);
*/
function getWorkingAdultRandomBirthDate( in_format ){
    // Example at: http://jsfiddle.net/3nyjurtc/14/
    var f_year, f_month, f_mday;
    var working_age;
    var now = new Date(); // use as based date for age calcs.
//  var now = new Date("Feburary 29, 2012 01:15:00"); // last leap year.
    var isLeapYear;
    var iDays_in_month;
    
/*
    // PROTIP: For better readability, use JavaScript line continuation character:
    formatted_date.concat( now.getFullYear() \
        , ( now.getFullYear() +1 ) \
        ,   now.getDate() \
        );
    document.getElementById('today').innerHTML = now;
    // PROTIP: Instead of hard-coding dates, use the current system's date which can be overriden.
*/

    // Ignoring natural variation in likelihood of each age being picked:
    working_age = randomWorkingAdultAge(); 

    // PROTIP: Keep values in numeric datatype for calculations until formatting.
    f_year  = now.getFullYear() - working_age ;

        f_month = randomIntFromInterval(1,12);
    if( f_month == 2){
        //  isLeapYear = isLeapYear( f_year );
            isLeapYear = ((f_year % 4 === 0 && f_year % 100 !== 0) || f_year % 400 === 0); 
        if( isLeapYear ){
            f_mday = randomIntFromInterval(1,29);
        }else{
            f_mday = randomIntFromInterval(1,28);
        }
    }else{
        iDays_in_month = daysInMonth( f_month, f_year );
        f_mday = randomIntFromInterval(1,iDays_in_month);
    }
         
    // PROTIP: Separate calculations and formatting concerns in separate functions.
    return formatDate( f_year, f_month, f_mday, in_format );
}


function randomWorkingAdultAge(){
    // http://jsfiddle.net/wilsonmar/2qah2r8m/2/
    
    // This function retuns a randomly assigned valid age (used to calculate birth dates).
    var out_age=-1;
    // The age generated is designed to be within a range of 
    // what is considered working age (20 to 65). This range is not specified
    // by the caller because it is a "corporate" level "business rule" 
    // that can change over time, encapsulated in this function library.
    
    // This function works by first obtaining a random number between 0 and 100 
    // which is assumed to be evenly distributed across all values.
    var point_in_curve;

    // But we want to apply a probability distribution (such as a normal distribution).
    // So we use a two-dimentional look-up matrix of the cumulative chance and the age.
    // Each pair is like another column in the probability curve.
    // With [23,29] : [0,0]=23, [0,1]=29, [0,2]=undefined beyond columns defined
    // meaning there is 23% chance of between 25 and 29 years.
    var a = [ 
         [12,24]
        ,[23,29]
        ,[34,34]
        ,[44,39]
        ,[56,44]
        ,[67,49]
        ,[79,55]
        ,[91,59]
        ,[100,64] 
    ]; 
    // Age values on the right are the max age of each age band defined by 
    // the US Census at https://www.census.gov/population/age/data/cps.html
    // Smaller bands would provide a more realistic distribution.

    var i;
    
    point_in_curve = randomIntFromInterval( 0, 100 ); // func. within same js file.
    // document.getElementById('point_in_curve').innerHTML = point_in_curve; // DEBUGGING
 
    for (var i = 0; i < 9; i++){ // size of matrix = 9 items (i value 0 to 8).
        if( point_in_curve > a[i][0] ){ // left dimension (cum. popularity of each band)
            // loop though for next i (and higher cumulative chance).
        }else{
            out_age = a[i][1];
            break;
        }
    }
    return out_age;
}

function randomIntFromInterval( min ,max ){
    return Math.floor(Math.random()*(max-min+1)+min);
}

function daysInMonth( iMonth, iYear ){
	return 32 - new Date(iYear, iMonth, 32).getDate();
}

/*
function isLeapYear( year ){
    // For background: http://www.wikiwand.com/en/Leap_year#/Algorithm
    if (typeof year == "string") { 
        yr=parseInt(year);
    }   
    // from https://code.google.com/p/datejs/source/browse/trunk/src/core.js
    return ((year % 4 === 0 && year % 100 !== 0) || year % 400 === 0); 
}
*/

function formatDate( f_year, f_month, f_mday, in_format ){
    var formatted_date;

    if ( f_month <= 9 ){ // to zero fill:
         f_month=  "0" + f_month;
    }else{
         f_month = f_month.toString();
    }

    if( f_mday <= 9 ){ // to zero fill:
        f_mday = "0" + f_mday;
    }else{
        f_mday = f_mday.toString();
    }
    
          if( in_format == 'YYYY-MM-DD' || in_format == 'ISO 8601' ){
        formatted_date = f_year +"-"+ f_month +"-"+ f_mday;
 
    }else if( in_format == 'YYYYMMDD' ){
        formatted_date = f_year + f_month + f_mday;
    }else if( in_format == 'YYMMDD' ){
        f_year=f_year.substring(1, 2);
        formatted_date = f_year + f_month + f_mday;
    }else if( in_format == 'YY-MM-DD' ){
        f_year=f_year.substring(1, 2);
        formatted_date = f_year +"-"+ f_month +"-"+ f_mday;
    }else if( in_format == 'YYYY/MM/DD' ){
        formatted_date = f_year +"/"+ f_month +"/"+ f_mday;
    }else if( in_format == 'MM/DD/YYYY' ){
        formatted_date = f_month +"/"+ f_mday +"/"+ f_year;
    }else if( in_format == 'DD/MM/YYYY' ){
        formatted_date = f_mday +"/"+ f_month +"/"+ f_year;

    }else{
        // PROTIP: When using alert that can pop-up from any function, include the function name.
        formatted_date = "Format " + in_format +" not recognized in formatDate().";
        // PROTIP: For more complex date formats and calculations (different cultures, etc.), 
        // consider using http://www.datejs.com/.
    }

	return formatted_date;
}


