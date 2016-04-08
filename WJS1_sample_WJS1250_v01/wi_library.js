/*
 * A set of utility functions for use in LoadRunner JavaScript scripts
 * Copyright (C) Wison Mar 2016.
 * See http://wilsonmar.github.io/javascript-for-loadrunner/ for details.
 */

// Global variable definitions:
var wi_msg_level_at_entry;
var wi_msg_level_current;
var wi_unix_start_timestamp;
var wi_random_seed;

function wi_library_init(){

    // Create a new JavaScript object of number of seconds since Jan. 1, 1970:
    var wi_unix_start_timestamp = Math.round(+new Date()/1000);
    var s4=function() {return Math.floor((1 + Math.random()) * 0x10000).toString(16).substring(1);};
    var randomGUID=function(){return s4() + s4() + '-' + s4() + '-' + s4() + '-' + s4() + '-' + s4() + s4() + s4();}
 
	if (!Date.now) {
        Date.now = function() { return new Date().getTime(); }
	}else{
		Date.now();
	}
	// new Date('Jan 1, 2039') / 1000 | 0 == -2117514496
	lr.outputMessage(">> Unix Date =" + wi_unix_start_timestamp );
	lr.outputMessage(">> Date.now()=" + Date.now() + " = " + displayTime() );
	// Math.floor(Date.now() / 1000) converts Date.now() to Unix time 10 digits.

	wi_random_seed = Math.random() * 100 ;
	lr.outputMessage(">> wi_random_seed = " + wi_random_seed );

	lr.outputMessage(">> randomGUID = " + randomGUID() );
	
	wi_msg_level_at_entry=lr.getDebugMessage(); // global var is set at top of this file.
   
       result = lr.whoami();
   if( result[0] == -1 ){
       lr.outputMessage(">> vuser id: -1, scenario id: 0, Group: \"undefined\" are expected in VuGen.");
   }else{
   	   lr.outputMessage(">> vuser id: " + result[0]+
              ", scenario id: "+ result[1] +
              ", Group: \"" + result[2] + "\"."
             );
   }
   return 0;
}


function wi_msg_force_print(){

  msg_level=lr.getDebugMessage(); // current settings.

  if( msg_level & lr.MSG_CLASS_DISABLE_LOG ){
  	  // Switch on so it shows up:
        lr.setDebugMessage( lr.MSG_CLASS_DISABLE_LOG, 0 ); // off = show.
  }

  if (msg_level & lr.MSG_CLASS_JIT_LOG_ON_ERROR ){ // Switch on so it shows up:
        lr.setDebugMessage( lr.MSG_CLASS_JIT_LOG_ON_ERROR, lr.SWITCH_OFF ); // off = show.
  }

   return 0;
}


function wi_msg_level_print( msg_level ){

  wi_msg_force_print();
   
  lr.outputMessage(">> Run-Time Settings > Log DebugMessage level:");

   if (msg_level & lr.MSG_CLASS_BRIEF_LOG){
       	lr.outputMessage(">>   [X] Enable Logging = " + lr.MSG_CLASS_BRIEF_LOG +".");
   }else{
       	lr.outputMessage(">>   [_] Enable logging = " + lr.MSG_CLASS_BRIEF_LOG +".");
   }

  lr.outputMessage(">>   Send messages:");

  if (msg_level & lr.MSG_CLASS_JIT_LOG_ON_ERROR ){ // (reverse logic)
       	lr.outputMessage(">>   [X] Log when error message occurs = " + lr.MSG_CLASS_JIT_LOG_ON_ERROR +".");
   }else{
       	lr.outputMessage(">>   [X] Always = " + lr.MSG_CLASS_JIT_LOG_ON_ERROR +".");
   }

       lr.outputMessage(">>   Detail level:");
   if (msg_level & lr.MSG_CLASS_EXTENDED_LOG ){
       	lr.outputMessage(">>   [X] Extended log = " + lr.MSG_CLASS_EXTENDED_LOG + ".");
   }else{
       	lr.outputMessage(">>   [X] Standard log = " + lr.MSG_CLASS_EXTENDED_LOG + ".");
   }

   if( msg_level & lr.MSG_CLASS_PARAMETERS ){
       lr.outputMessage(">>       [X] Parameter substitution = " + lr.MSG_CLASS_PARAMETERS + ".");
   }else{
       lr.outputMessage(">>       [_] Parameter substitution = " + lr.MSG_CLASS_PARAMETERS + ".");
   }

   if( msg_level & lr.MSG_CLASS_RESULT_DATA){
       lr.outputMessage(">>       [X] Data returned by server = " + lr.MSG_CLASS_RESULT_DATA + ".");
   }else{
       lr.outputMessage(">>       [_] Data returned by server = " + lr.MSG_CLASS_RESULT_DATA + ".");
   }

   if( msg_level & lr.MSG_CLASS_FULL_TRACE){
       lr.outputMessage(">>       [X] Advanced trace = " + lr.MSG_CLASS_FULL_TRACE + ".");
   }else{
       lr.outputMessage(">>       [_] Advanced trace = " + lr.MSG_CLASS_FULL_TRACE + ".");
   }

   wi_msg_restore_print();

   return 0;
}


function wi_msg_restore_print(){

   lr.setDebugMessage( wi_msg_level_at_entry ); // off = show.

   return 0;
}

function getTimeStamp(){ // 24 hour time:
    var now = new Date();
    return ( now.getFullYear() + "-" +
            (zeroFill( now.getMonth() + 1) ,2) + '-' +
            (zeroFill( now.getDate()) ,2) + ' ' +
             now.getHours() + ':' +
             ((now.getMinutes() < 10)
                 ? ("0" + now.getMinutes())
                 : (now.getMinutes())) + ':' +
             ((now.getSeconds() < 10)
                 ? ("0" + now.getSeconds())
                 : (now.getSeconds())
            )
           );
}

function displayTime() {
    var str = "";

    var now = new Date()
    var month   = now.getMonth()
    var days     = now.getDate()
    var hours   = now.getHours()
    var minutes = now.getMinutes()
    var seconds = now.getSeconds()

    if (month < 10) {
        month = "0" + minutes
    }
    if (days < 10) {
        days = "0" + minutes
    }
    str += now.getFullYear() + '-' + month + '-' + days + ' ';

    if (minutes < 10) {
        minutes = "0" + minutes
    }
    if (seconds < 10) {
        seconds = "0" + seconds
    }
    str += hours + ":" + minutes + ":" + seconds + " ";
    if(hours > 11){
        str += "PM"
    } else {
        str += "AM"
    }
    return str;
}

function zeroFill(number, size) {
// https://gist.github.com/andrewrk/4382935#file-test-js-L7
  number = number.toString();
  while (number.length < size) number = "0" + number;
  return number;
}

// END