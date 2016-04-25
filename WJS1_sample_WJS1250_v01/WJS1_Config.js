function WJS1_Config(){
	return 0;
}

// TODO: Enable flag to control when running in debug or trace verbosity.
 
function WJS1_Config_print_info(){
    wi_msg_force_print();
   return 0;
}
function WJS1_Config_print_error(){
    wi_msg_force_print();
   return 0;
}
function WJS1_Config_print_warning(){
    wi_msg_force_print();
   return 0;
}
function WJS1_Config_print_trace(){
    wi_msg_force_print();
   return 0;
}
function WJS1_Config_print_debug(){
    wi_msg_force_print();
   return 0;
}




function WJS1_Config_StartTrans( in_trans , in_title ){
    var rc=0;

 	lr.thinkTime( nThinkTimeSecs );

    // Capture title to be returned if it's not empty:
    if( in_title ){
        web.regFind({
           search : 'Body',
//           relFrameId: '',
//           fail : 'NotFound',
           saveCount : 'title_found_count',
           text : in_title
        });
    }
    
    // TODO: Capture user agent in HTTP header

    lr.startTransaction( in_trans );

    return rc;
}


function WJS1_Config_EndTrans( in_trans , in_rc ){
  var rc=0;

    // Check web response captured by regFind into LoadRunner parameters:
    if( lr.evalString("{title_found_count}") === 0 ){
        // Not found
		WJS1_Config_print_error();
    	lr.outputMessage(">> Title not found.");
    	wi_msg_print_reset();
    }

    rc=wi_http_response_capture_check();
    
    // TODO: Save response info into a log.

    if( in_rc !== 0 ){
       lr.endTransaction( in_trans, lr.FAIL );
    }else{
       lr.endTransaction( in_trans, lr.AUTO );
    }
    
    // TODO: Add web.cacheCleanup( ); if applicable.
    // TODO: Add web.cleanupCookies( ); if applicable.
    
    return rc;
}
