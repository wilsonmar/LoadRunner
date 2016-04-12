/*
 * A set of utility functions for use in LoadRunner JavaScript scripts
 * Copyright (C) Wison Mar 2016.
 * See http://wilsonmar.github.io/javascript-for-loadrunner/ for details.
 */

// Global variable definitions:
var wi_unix_start_timestamp;
var wi_msg_level_at_init;
var wi_HostName;
var wi_VuserIp;
var wi_random_seed;
var wi_http_download_bytes;
var wi_http_download_ms;


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

    wi_VuserIp = lr.getVuserIp(); // FIXME: VuserIp returning blank instead of an IP.
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

   wi_msg_print_reset();
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

   wi_msg_print_reset();

   return 0;
}


function wi_msg_force_print(){

        lr.setDebugMessage( lr.MSG_CLASS_JIT_LOG_ON_ERROR, lr.SWITCH_OFF ); // off = show.
        lr.setDebugMessage( 30 ); // off = show.
   //     lr.setDebugMessage( lr.MSG_CLASS_BRIEF_LOG, lr.SWITCH_ON );

   return 0;
}


function wi_msg_print_reset(){

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

        if( (wi_msg_level_at_init & lr.MSG_CLASS_PARAMETERS) == lr.MSG_CLASS_PARAMETERS ){
            lr.setDebugMessage( lr.MSG_CLASS_PARAMETERS, lr.SWITCH_ON ); // off = show.
    	}else{
            lr.setDebugMessage( lr.MSG_CLASS_PARAMETERS, lr.SWITCH_OFF ); // off = show.
        }
    
        if( (wi_msg_level_at_init & lr.MSG_CLASS_FULL_TRACE) == lr.MSG_CLASS_FULL_TRACE ){
            lr.setDebugMessage( lr.MSG_CLASS_FULL_TRACE, lr.SWITCH_ON ); // off = show.
    	}else{
            lr.setDebugMessage( lr.MSG_CLASS_FULL_TRACE, lr.SWITCH_OFF ); // off = show.
        }
    
        if( (wi_msg_level_at_init & lr.MSG_CLASS_RESULT_DATA) == lr.MSG_CLASS_RESULT_DATA ){
            lr.setDebugMessage( lr.MSG_CLASS_RESULT_DATA, lr.SWITCH_ON ); // off = show.
    	}else{
            lr.setDebugMessage( lr.MSG_CLASS_RESULT_DATA, lr.SWITCH_OFF ); // off = show.
        }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////

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

function wi_random_guid( number, size) {
    var s4=function() {return Math.floor((1 + Math.random()) * 0x10000).toString(16).substring(1);};
    var randomGUID=function(){return s4() + s4() + '-' + s4() + '-' + s4() + '-' + s4() + '-' + s4() + s4() + s4();}
    return randomGUID;
}

function wi_CapitalizeExtractFirstLetter(string){
    return string.charAt(0).toUpperCase();
}

///////////////////////////////////////////////////  Generic LoadRunner library functions:


function wi_web_url_retries( in_trans , in_prep, in_url, in_mode , in_title ){
   var rc=0;
   
   rc=wi_web_url_prep( in_prep );
       if( rc != 0 ){ return rc; }

   for(var i = 0; i < nRetries; i++ ){ 
       rc=wi_web_url( in_trans , in_prep, in_url , in_mode , in_title );
       if( rc != 0 ){ return rc; }
      // else loop back to top of for loop above.
   }
   
   return rc;
}


function wi_web_url_prep( in_prep ){
   var rc=0;
   
    if( "X" == in_prep ){
   	
    }else
    if( "Y" == in_prep ){
   	
 	}else
    if( "Y" == in_prep ){
	
    }else{
   	
    }
    	
    return rc;
}

function wi_web_url( in_trans , in_url , in_mode , in_title ){
   var rc=0;
   
   json_put_string="";
   json_post_file_path="";

   WJS1_Config_StartTrans( in_trans, in_title );
   
   if( in_mode == "PUT" ){
     rc=web.customRequest({
       stepName : in_trans, 
       url :      in_url, 
       method:"PUT",
       encType : "application/json",
       resource : 0, 
       recContentType : 'text/html', 
       mode : 'HTTP',
       body : '{json_put_string}'
      });
   	
   }else
   if( in_mode == "GET" ){
     rc=web.customRequest({
       stepName : in_trans, 
       url :      in_url, 
       method:"PUT",
       encType : "application/json",
       resource : 0, 
       recContentType : 'text/html', 
       mode : 'HTTP',
       body : ''
      });
   	
   }else
   if( in_mode == "POST" ){
     rc=web.customRequest({
       stepName : in_trans, 
       url :      in_url, 
       method:"PUT",
       encType : "application/json",
       resource : 0, 
       recContentType : 'text/html', 
       mode : 'HTTP',
       bodyFilePath: '{json_post_file_path}'
      });
   	  // This requires VuGen Tools > Options > Scripting > Script Management and add ".json|" to the Allowed Extensions list.
   	
   }else{
     rc=web.url({
       name : in_trans, 
       url :  in_url, 
       targetFrame : '', 
       resource : 0, 
       recContentType : 'text/html', 
       referer : '', 
       snapshot : 't1.inf', 
       mode : in_mode
      });
   }
   // rc = custom edits here raise (<title>)

   rc=WJS1_Config_EndTrans( in_trans , rc );

   return rc;
}

function wi_post( in_trans , in_url , in_mode , in_title ){
   var rc=0;
   
   WJS1_Config_StartTrans( in_trans, in_title );
   

   // rc = custom edits here raise (<title>)

   rc=WJS1_Config_EndTrans( in_trans , rc );

   return rc;
}

function wi_file_count( in_parm ){
  // Loop through a parm to return the number of rows found.
  // CAUTION: This only works if there are no duplicates of the first key in the file.
  // This is until I find a built-in function to do this.
  
	var rc=0; count=1; 
	//  RunDataIn_key; // using global variable 
	var in_parm_row_1;
	var go_on_flag=0;
	var in_parm_format = "{"+ in_parm +"}";
    var run_row_id;
    	
		//	WJS1_Config_print_debug();
		//	lr.outputMessage(">> in_parm="+ in_parm +" & in_parm_format = " + in_parm_format +".");
		//  wi_msg_print_reset();

	    RunDataIn_key = lr.evalString( in_parm_format );
		in_parm_row_1 = RunDataIn_key; 

	  	// TODO: Compare row Id in file against counter so duplicate values can occur. 
		// if( count != lr.evalString( "{run_row_id}") ){
		//	WJS1_Config_print_error();
		//	lr.outputMessage(">> count="+ count +", run_row_id="+ lr.evalString( "{run_row_id}" ) +".");
		//    wi_msg_print_reset();		   	
		//}

	while( go_on_flag == 0 ){
		// This loop assumes Update Value on Each Iteration, the default.
		// WARNING: if parm is set to Update Value on Each occurance, every access (even by a message function) advances the row pointer.
		rc=lr.advanceParam( in_parm ); // advance to next row in file. Expected rc=-1.

		RunDataIn_key = lr.evalString( in_parm_format );
		if( in_parm_row_1 == RunDataIn_key ){
			go_on_flag = 1; // break out of while loop.
		}else{
			count = count + 1;

			WJS1_Config_print_debug();
			lr.outputMessage(">> count="+ count +", rc="+ rc +", " + in_parm +"="+ RunDataIn_key +".");
		    wi_msg_print_reset();
		}
    }
  
  // TODO: Ignore file rows marked anything but "Y" or "Yes" or "yes" or "y" or blank.
  
  return count;
}


function wi_strip_braces( in_count_parm ){
    var newString = in_count_parm;
	
	if( newString.substr(1) == "{" ){
		newString = in_count_parm.substr(1);
	}else{
		newString = in_count_parm;
	}

	if( in_count_parm.substr(0, myString.length-1) == "}" ){
		newString = newString.substr(0, myString.length-1);
	}else{
		// newString same.
	}
 
    return newstring;
}


function wi_http_response_capture_check(){
	
	var wi_http_return_code;

 // var wi_http_request_bytes;
 // var wi_http_response_bytes;
 // var wi_http_last_err;
    
    // Return code  in HTTP response header:
    wi_http_return_code    = web.getIntProperty( web.HTTP_INFO_RETURN_CODE ); // value=1. The return code
    if(    wi_http_return_code >= 400 ){
    	rc=wi_http_return_code;
    }
    
    // Global vars:
    // Size in bytes of the last download, including the header, body, and communications overhead (for example, NTLM negotiation).
    wi_http_download_bytes = web.getIntProperty( web.HTTP_INFO_DOWNLOAD_SIZE ); // value= 2 
    // Time in milliseconds of the last download:
    wi_http_download_ms    = web.getIntProperty( web.HTTP_INFO_DOWNLOAD_TIME ); // value= 3 

    // Accumulated size of all headers and bodies since the first time web.getIntProperty was issued with HTTP_INFO_TOTAL_REQUEST_STAT.
    // wi_http_request_bytes = web.getIntProperty( web.HTTP_INFO_TOTAL_REQUEST_STAT ); // value= 4 
    // accumulated size, including header and body, of all responses since the first time web.getIntProperty was issued with HTTP_INFO_TOTAL_RESPONSE_STAT
    // wi_http_response_bytes = web.getIntProperty( web.HTTP_INFO_TOTAL_RESPONSE_STAT ); // value= 5 
    // last socket error. On timeout, web.getIntProperty(HTTP_INFO_LAST_SOCKET_ERROR) returns 10060. For other errors, see the socket documentation.
    // wi_http_last_err = web.getIntProperty( web.HTTP_INFO_LAST_SOCKET_ERROR ); // value= 6 
   
    return rc;
}

// END