var wi_msg_level_at_entry;
var wi_msg_level_current;
  
function wi_library_init(){

   wi_msg_level_at_entry=lr.getDebugMessage(); // global var is set at top of this file.
   
   result = lr.whoami();

   lr.outputMessage(">> vuser id: " + result[0]+
              ", scenario id: "+ result[1] +
              ", Group: " + result[2] +
             ".");
   if( result[0] == -1 ){
       lr.outputMessage(">> vuser id: -1, scenario id: 0, Group: undefined are expected in VuGen.");
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
   
  lr.outputMessage(">> Run-Time Settings > Log DebugMessage level=" + msg_level + ".");

   if (msg_level & lr.MSG_CLASS_BRIEF_LOG){
       	lr.outputMessage(">>   [X] Enable Logging =" + lr.MSG_CLASS_BRIEF_LOG +".");
   }else{
       	lr.outputMessage(">>   [_] Enable logging =" + lr.MSG_CLASS_BRIEF_LOG +".");
   }

  lr.outputMessage(">>   Send messages:");

  if (msg_level & lr.MSG_CLASS_JIT_LOG_ON_ERROR ){ // (reverse logic)
       	lr.outputMessage(">>       [X] Log when error message occurs =" + lr.MSG_CLASS_JIT_LOG_ON_ERROR +".");
   }else{
       	lr.outputMessage(">>       [X] Always =" + lr.MSG_CLASS_JIT_LOG_ON_ERROR +".");
   }

       lr.outputMessage(">>   Detail level:");
   if (msg_level & lr.MSG_CLASS_EXTENDED_LOG ){
       	lr.outputMessage(">>   [X] Extended log =" + lr.MSG_CLASS_EXTENDED_LOG + ".");
   }else{
       	lr.outputMessage(">>   [X] Standard log =" + lr.MSG_CLASS_EXTENDED_LOG + ".");
   }

   if( msg_level & lr.MSG_CLASS_PARAMETERS ){
       lr.outputMessage(">>       [X] Parameter substitution =" + lr.MSG_CLASS_PARAMETERS + ".");
   }else{
       lr.outputMessage(">>       [_] Parameter substitution =" + lr.MSG_CLASS_PARAMETERS + ".");
   }

   if( msg_level & lr.MSG_CLASS_RESULT_DATA){
       lr.outputMessage(">>       [X] Data returned by server =" + lr.MSG_CLASS_RESULT_DATA );
   }else{
       lr.outputMessage(">>       [_] Data returned by server =" + lr.MSG_CLASS_RESULT_DATA );
   }

   if( msg_level & lr.MSG_CLASS_FULL_TRACE){
       lr.outputMessage(">>       [X] Advanced trace =" + lr.MSG_CLASS_FULL_TRACE );
   }else{
       lr.outputMessage(">>       [_] Advanced trace =" + lr.MSG_CLASS_FULL_TRACE );
   }

   wi_msg_restore_print();

   return 0;
}

function wi_msg_restore_print(){

   lr.setDebugMessage( wi_msg_level_at_entry ); // off = show.

   return 0;
}

function wi_status(){
	
   result = lr.whoami();
   lr.outputMessage(">> vuser id: " + result[0]+
              ", scenario id: "+ result[1] +
              ", Group: " + result[2] +
             ".");
   lr.outputMessage(">> vuser id: -1, scenario id: 0, Group: undefined are expected in VuGen.");

   return 0;
}