//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Tue Apr 05 13:15:10 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function Action()
{
    var rc=0; i=0;
   
    // Info:
    lr.outputMessage(">> Action Iteration=" + lr.evalString("{pIteration}") +".");

    // Use run-time attribute "RunData" to select source of data to process.
	if( RunDataIn === "1"){
     	rc=WJS1_Access_landing( "T01_landing","http://127.0.0.1:1080/WebTours/index.htm",100);
		if( rc != 0 ){ return rc; }
    }else
	if( RunDataIn === "FILE"){ // Loop thru file run_01.dat
	    // Info:
	    lr.outputMessage(">> RunDataIn_rows=" + RunDataIn_rows +" for "+ "{run_URL}" +".");
    	for (i = 1; i < RunDataIn_rows; i++){ 
	    	// NOTE: Using value in global RunDataIn_key retrieved in wi_file_count() within wi_library.js.
 
			// Trace:
			lr.outputMessage(">> "+ lr.evalString("{pIteration}") 
	                 + ", row=" + i
	                 + ", trans=" + lr.evalString("{run_TransName}")
	                 + ", url=" + RunDataIn_key
	                 + ", chance="+ lr.evalString("{run_chance}") );
			rc=WJS1_Access_landing( lr.evalString("{run_TransName}"), RunDataIn_key, lr.evalString("{run_chance}") );
			// if( rc != 0 ){ return rc; }

			RunDataIn_key = lr.evalString("{run_URL}");
			//lr.advanceParam( "{run_URL}" ); // advance to next row in file;
    	}
    }else
	if( RunDataIn === "VTS"){
	    // TODO: Obtain data from VTS rather than run_01.dat.
		// TODO: Update results in VTS
    }else{
		lr.errorMessage(">> Run-Time Settings Attribute RunDataIn="+ RunDataIn +" not recognized."); 
		lr.abort();
    }
   
    
    // TODO: Report lr.userDataPoint("scr-items", scr-items); for items on the screen.

    return rc;
}

