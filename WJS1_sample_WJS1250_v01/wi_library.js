/*
 * A set of utility functions for use in LoadRunner JavaScript scripts
 * Copyright (C) Wison Mar 2016.
 * See http://wilsonmar.github.io/javascript-for-loadrunner/ for details.
 */

// Global variable definitions:
var wi_msg_level_at_init;
var wi_unix_start_timestamp;
var wi_random_seed;
var wi_HostName;
var wi_VuserIp;

function wi_library_init(){

    // Create a new JavaScript object of number of seconds since Jan. 1, 1970:
    // var wi_unix_start_timestamp = Math.round(+new Date()/1000);
    var wi_unix_start_timestamp = Math.floor(Date.now() /1000); // converts Date.now() to Unix time 10 digits.
  
	if (!Date.now) {
        Date.now = function() { return new Date().getTime(); }
	}else{
		Date.now();
	}

    wi_msg_level_at_init=lr.getDebugMessage(); // current settings.
    wi_msg_level_print();

    wi_msg_force_print();

    lr.outputMessage(">> wi_msg_level_at_init = " + wi_msg_level_at_init +".");
   
	// new Date('Jan 1, 2039') / 1000 | 0 == -2117514496
	lr.outputMessage(">> Unix Date =" + wi_unix_start_timestamp );
	lr.outputMessage(">> Date.now()=" + Date.now() + " = " + wi_displayTime() );

	wi_random_seed = Math.random() * 100 ;
	lr.outputMessage(">> wi_random_seed = " + wi_random_seed );

	wi_HostName = lr.getHostName();
    lr.outputMessage(">> HostName=" + wi_HostName + ".");

    wi_VuserIp = lr.getVuserIp();
    lr.outputMessage(">> VuserIp=" + wi_VuserIp + ".");

       result = lr.whoami();
   if( result[0] == -1 ){
       lr.outputMessage(">> vuserId: -1, ScenarioId: 0, Group: \"undefined\" are expected in VuGen.");
   }else{
   	   lr.outputMessage(">> vuserId: " + result[0]+
              ", ScenarioId: "+ result[1] +
              ", Group: \"" + result[2] + "\"."
             );
   }

   wi_msg_restore_print();
   return 0;
}


function wi_msg_level_print(){

  var msg_level=lr.getDebugMessage(); // current settings.

  wi_msg_force_print();
   
  lr.outputMessage(">> Run-Time Settings > Log DebugMessage level: " + msg_level +".");

   // Not displaying lr.MSG_CLASS_DISABLE_LOG & MSG_CLASS_BRIEF_LOG always zero.
   
   // Using & bit-wise operator:
   if( msg_level == 0 ){
       	lr.outputMessage(">>   [_] Enable logging = " + lr.MSG_CLASS_BRIEF_LOG +".");
   }else{
       	lr.outputMessage(">>   [X] Enable Logging = " + lr.MSG_CLASS_BRIEF_LOG +".");

       lr.outputMessage(">>   Send messages: " );

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

   } // Enabled logging

   wi_msg_restore_print();

   return 0;
}


function wi_msg_force_print(){

        lr.setDebugMessage( lr.MSG_CLASS_JIT_LOG_ON_ERROR, lr.SWITCH_OFF ); // off = show.
        lr.setDebugMessage( 30 ); // off = show.
   //     lr.setDebugMessage( lr.MSG_CLASS_BRIEF_LOG, lr.SWITCH_ON );

   return 0;
}


function wi_msg_restore_print(){

    lr.setDebugMessage( wi_msg_level_at_init );

    if( wi_msg_level_at_init == 0 ){
        lr.setDebugMessage( lr.MSG_CLASS_BRIEF_LOG, lr.SWITCH_OFF );
    }else{
        lr.setDebugMessage( lr.MSG_CLASS_BRIEF_LOG, lr.SWITCH_ON );
    }

        if( (wi_msg_level_at_init & lr.MSG_CLASS_JIT_LOG_ON_ERROR) == lr.MSG_CLASS_JIT_LOG_ON_ERROR ){
            lr.setDebugMessage( lr.MSG_CLASS_JIT_LOG_ON_ERROR, lr.SWITCH_ON ); // off = show.
    	}else{
            lr.setDebugMessage( lr.MSG_CLASS_JIT_LOG_ON_ERROR, lr.SWITCH_OFF ); // off = show.
        }
    
        if( (wi_msg_level_at_init & lr.MSG_CLASS_EXTENDED_LOG) == lr.MSG_CLASS_EXTENDED_LOG ){
            lr.setDebugMessage( lr.MSG_CLASS_EXTENDED_LOG, lr.SWITCH_ON ); // off = show.
    	}else{
            lr.setDebugMessage( lr.MSG_CLASS_EXTENDED_LOG, lr.SWITCH_OFF ); // off = show.
        }

        if( (wi_msg_level_at_init & lr.MSG_CLASS_FULL_TRACE) == lr.MSG_CLASS_FULL_TRACE ){
            lr.setDebugMessage( lr.MSG_CLASS_FULL_TRACE, lr.SWITCH_ON ); // off = show.
    	}else{
            lr.setDebugMessage( lr.MSG_CLASS_FULL_TRACE, lr.SWITCH_OFF ); // off = show.
        }
    
    return 0;
}

function wi_TimeStamp(){ // 24 hour time:
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

function wi_displayTime() {

              var now = new Date()
    var month   = now.getMonth();
    var days    = now.getDate();
    var hours   = now.getHours();
    var minutes = now.getMinutes();
    var seconds = now.getSeconds();
    var str = "";

        month = 1 + month; // fix JavaScript bug begin count from zero.
    if (month < 10) {
        month = "0" + month;
    }
    if (days < 10) {
        days = "0" + days;
    }
    str += now.getFullYear() + '-' + month + '-' + days + ' ';

    if (minutes < 10) {
        minutes = "0" + minutes;
    }
    if (seconds < 10) {
        seconds = "0" + seconds;
    }
    str += hours + ":" + minutes + ":" + seconds + " ";
    if(hours > 11){
        str += "PM";
    } else {
        str += "AM";
    }
    return str;
}

function wi_zeroFill(number, size) {
// https://gist.github.com/andrewrk/4382935#file-test-js-L7
  number = number.toString();
  while (number.length < size) number = "0" + number;
  return number;
}

function wi_random_guid( number, size) {
    var s4=function() {return Math.floor((1 + Math.random()) * 0x10000).toString(16).substring(1);};
    var randomGUID=function(){return s4() + s4() + '-' + s4() + '-' + s4() + '-' + s4() + '-' + s4() + s4() + s4();}
    return randomGUID;
}

function wi_web_url_html( in_trans , in_url ){
   var rc=0;
   var in_mode="HTML";
   
   rc=wi_web_url( in_trans , in_url , in_mode );
   return rc;
}

function wi_web_url_http( in_trans , in_url ){
   var rc=0;
   var in_mode="HTTP";
   
   rc=wi_web_url( in_trans , in_url, in_mode );
   return rc;
}

function wi_web_url( in_trans , in_url, in_mode ){
   var rc=0;
   
   // Trace:
   lr.outputMessage(">> trans=" + in_trans + ", url=" + in_url );

   wi_StartTrans( in_trans );
   
   web.url({
    name : in_trans, 
    url :  in_url, 
    targetFrame : '', 
    resource : 0, 
    recContentType : 'text/html', 
    referer : '', 
    snapshot : 't1.inf', 
    mode : in_mode
   });

   // rc = custom edits here raise (<title>)

   rc=wi_EndTrans( in_trans , rc );

   return rc;
}

function wi_StartTrans( in_trans ){
    var rc=0;
    
    // lr.outputMessage(">> in_trans=" + in_trans );
    
 	lr.thinkTime(1.5); // Cannot use std. parameterization for  arguments?

    // Capture generic itmes:
    // wi_capture_user_agent();

    lr.startTransaction( in_trans );

    return rc;
}


function wi_EndTrans( in_trans , in_rc ){
  var rc=0;

    // Check HTML return code:
    // ???

   if( in_rc != 0 ){
      lr.endTransaction( in_trans, lr.FAIL );
   }else{
      lr.endTransaction( in_trans, lr.AUTO );
   }

  return rc;
}


function wi_capture_user_agent(){

  web.regSaveParamEx(
    {
      paramName : 'userAgent', 
      lb : 'User-Agent: ', 
      rb : '\\r\\n', 
      scope : 'Head', 
      requestUrl : ''
    }
  );
}
// END