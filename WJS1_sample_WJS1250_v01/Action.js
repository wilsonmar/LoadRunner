//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Tue Apr 05 13:15:10 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function Action()
{
    var rc=0;
   
    lr.outputMessage(">> Iteration=" + lr.evalString("{pIteration}") +".");
    
    // TODO: Use run-time attribute "RunData" to select source of data to process. 

    /*
	rc=WJS1_Access_landing( "T01_landing","http://127.0.0.1:1080/WebTours/index.htm",100);
	if( rc != 0 ){ return rc; }
    */
   
	// Loop thru file run_01.dat
	lr.outputMessage(">> trans=" + lr.evalString("{run_TransName}")
	                 + ", url=" + lr.evalString("{run_URL}")
	                 + ", mode="+ lr.evalString("{run_chance}") );
	rc=WJS1_Access_landing( lr.evalString("{run_TransName}"), lr.evalString("{run_URL}"), lr.evalString("{run_chance}") );
	lr.advanceParam( "{run_URL}" ); // advance to next;
    
    // TODO: Obtain data from VTS rather than run_01.dat.

    // TODO: Update results in VTS
    
    // TODO: Report lr.userDataPoint("scr-items", scr-items); for items on the screen.


    return rc;
}

