function WJS1_Access(){
	return 0;
}

// Called by Action.js:
function WJS1_Access_landing_loops(){
    var rc=0;
    var i=0;

    // Use run-time attribute "RunData" to select source of data to process.
	if( RunDataIn === "0"){
		// Noop.
    }else
 	if( RunDataIn === "1"){
    	// Example of a hard-coded call:
     	rc=WJS1_Access_landing_random( "T01_landing",100,"HTML","http://127.0.0.1:1080/WebTours/index.htm","XXXX");

    }else
	if( RunDataIn === "FILE"){ // Loop thru file run_01.dat

		rc=WJS1_Access_landing_loop_file();
		
    }else
	if( RunDataIn === "VTS"){
		// TODO: Update results in VTS
		// rc=WJS1_Access_landing_loop_VTS();

    }else{
	    WJS1_Config_print_error();
		lr.errorMessage(">> Run-Time Settings Attribute RunDataIn="+ RunDataIn +" not recognized."); 
		lr.abort();
	    wi_msg_print_reset();
    }
   
   return rc;
}

function WJS1_Access_landing_loop_file(){
    var rc=0; 
    var run_use_cap;

        WJS1_Config_print_info();
	    lr.outputMessage(">> RunDataIn_rows=" + RunDataIn_rows +" based on assumed unique "+ "{run_URL}" +".");
	    wi_msg_print_reset();

	    // FIXME: RunDataIn_key one off from associated transname.
	    
	    for (i = 1; i < RunDataIn_rows; i++){
	    	// NOTE: Using value in global RunDataIn_key retrieved in wi_file_count() within wi_library.js.
	    	run_use_cap = wi_CapitalizeExtractFirstLetter( lr.evalString("{run_use}") );
		    WJS1_Config_print_trace();
			lr.outputMessage(">> "+ lr.evalString("{pIteration}") 
	                 + ", row=" + i
	                 + ", #="+ lr.evalString("{run_row_id}") 
	                 + ", use=" + run_use_cap
	                 + ", trans=" + lr.evalString("{run_TransName}")
	                 + ", chance="+ lr.evalString("{run_chance}") 
	                 + ", chance="+ lr.evalString("{run_prep}") 
	                 + ", chance="+ lr.evalString("{run_mode}") 
	                 + ", url=" + RunDataIn_key
	                 + ", chance="+ lr.evalString("{run_title}") 
	                );
		    wi_msg_print_reset();

		    if( run_use_cap == "Y" ){
				rc=WJS1_Access_landing_random( lr.evalString("{run_TransName}"), lr.evalString("{run_chance}"),  lr.evalString("{run_prep}") 
		    	                             , lr.evalString("{run_mode}") 
		    	                             , RunDataIn_key, lr.evalString("{run_title}") );
				// if( rc != 0 ){ return rc; }				
			}
			
			// Next row:
			RunDataIn_key = lr.evalString("{run_URL}"); // This increments if run_URL has Update Value on: Each occurance. 
			lr.advanceParam( "run_URL" ); // advance key not needed if run_URL has Update Value on: Each occurance. 
			// Now loop back to top of for loop above.
    	}
	    
   return rc;
}

function WJS1_Access_landing_random( in_trans , in_chance , in_prep , in_mode , in_url , in_title ){
    var rc=0;

	    wi_random_seed = Math.random() * 100 ;
 	if( wi_random_seed <= in_chance ){
        WJS1_Config_print_debug();
      	lr.outputMessage(">> Trans " + in_trans + " wi_random_seed " + wi_random_seed + " <= " + in_chance +".");
  		wi_msg_print_reset();

      	// Do stuff using a generic library function:
		rc=WJS1_Access_landing_retries( in_trans  , in_prep , in_mode , in_url , in_title );

    }else{
        var n = wi_random_seed.toFixed(1);
        
        WJS1_Config_print_debug();
		lr.outputMessage(">> Trans " + in_trans + " not selected for execution. wi_random_seed = " + n + " NOT <= " + in_chance +".");
  		wi_msg_print_reset();
	}
	    
   return rc;
}


function WJS1_Access_landing_retries( in_trans , in_prep , in_mode , in_url , in_title ){
   var rc=0;
   var i =0;
   
      rc=WJS1_Access_landing_prep( in_prep ); // prepare global strings.
       if( rc != 0 ){ return rc; }

   for( i = 0; i < nRetries; i++ ){ 
       	
        WJS1_Config_StartTrans( in_trans, in_title );
   
		rc=wi_web_url( in_trans , in_url , in_mode );
		
	    rc=WJS1_Config_EndTrans( in_trans , rc );
        if( rc != 0 ){ return rc; }
        // else loop back to top of for loop above.
   }
   
   return rc;
}


function WJS1_Access_landing_prep( in_prep ){
   var rc=0;
   
    if( "X" == in_prep ){
	    json_put_string="";
   		json_post_file_path="";
   	
    }else
    if( "Y" == in_prep ){
 
   	
 	}else
    if( "Z" == in_prep ){
	
   	
    }else{
	   	WJS1_Config_print_error();
		lr.errorMessage(">> in_prep="+ in_prep +" not recognized."); 
	    wi_msg_print_reset();
	    rc=213; // number specific to this.
    }
    	
    return rc;
}


/*
function WJS1_Access_SignUp_error(){
function WJS1_Access_SignUp(){

function WJS1_Access_SignIn_error(){
function WJS1_Access_SignIn(){

function WJS1_Access_SignOut(){
function WJS1_Access_Reset_Password(){
*/
