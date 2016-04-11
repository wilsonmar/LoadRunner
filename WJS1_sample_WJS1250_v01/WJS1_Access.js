function WJS1_Access(){
	
	return 0;
}

function WJS1_Access_loop(){
    var rc=0;
    var i=0;

    // Use run-time attribute "RunData" to select source of data to process.
	if( RunDataIn === "0"){
		// Noop.
    }else
 	if( RunDataIn === "1"){
    	// Example of a hard-coded call:
     	rc=WJS1_Access_landing( "T01_landing","http://127.0.0.1:1080/WebTours/index.htm",100,"Web Tours");

    }else
	if( RunDataIn === "FILE"){ // Loop thru file run_01.dat

    	WJS1_Config_print_info();
	    lr.outputMessage(">> RunDataIn_rows=" + RunDataIn_rows +" based on assumed unique "+ "{run_URL}" +".");
	    wi_msg_print_reset();

	    // FIXME: RunDataIn_key one off from associated transname.
	    
	    for (i = 1; i < RunDataIn_rows; i++){
	    	// NOTE: Using value in global RunDataIn_key retrieved in wi_file_count() within wi_library.js.
 
		    WJS1_Config_print_trace();
			lr.outputMessage(">> "+ lr.evalString("{pIteration}") 
	                 + ", row=" + i
	                 + ", use=" + lr.evalString("{run_use}")
	                 + ", trans=" + lr.evalString("{run_TransName}")
	                 + ", url=" + RunDataIn_key
	                 + ", chance="+ lr.evalString("{run_chance}") 
	                 + ", chance="+ lr.evalString("{run_title}") 
	                );
		    wi_msg_print_reset();

		    if( lr.evalString("{run_use}") == "Y" ){
				rc=WJS1_Access_landing( lr.evalString("{run_TransName}"), RunDataIn_key, lr.evalString("{run_chance}"), lr.evalString("{run_title}") );
				// if( rc != 0 ){ return rc; }				
			}
			
			// Next row:
			RunDataIn_key = lr.evalString("{run_URL}");
			lr.advanceParam( "run_URL" ); // advance to next row in file;
    	}
    }else
	if( RunDataIn === "VTS"){
		// TODO: Update results in VTS

    }else{
	    WJS1_Config_print_error();
		lr.errorMessage(">> Run-Time Settings Attribute RunDataIn="+ RunDataIn +" not recognized."); 
		lr.abort();
	    wi_msg_print_reset();
    }
   
   return rc;
}

function WJS1_Access_landing( in_trans , in_url, in_chance, in_title ){
    var rc=0;
 	
	    wi_random_seed = Math.random() * 100 ;
 	if( wi_random_seed <= in_chance ){
        WJS1_Config_print_debug();
      	lr.outputMessage(">> Trans " + in_trans + " wi_random_seed " + wi_random_seed + " <= " + in_chance +".");
  		wi_msg_print_reset();

      	// Do stuff using a generic library function:
		rc=wi_web_url_retries( in_trans , in_url , "HTTP", in_title );

    }else{
        var n = wi_random_seed.toFixed(1);
        
        WJS1_Config_print_debug();
		lr.outputMessage(">> Trans " + in_trans + " not selected for execution. wi_random_seed = " + n + " NOT <= " + in_chance +".");
  		wi_msg_print_reset();
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
