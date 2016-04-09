//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Tue Apr 05 13:15:10 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function Action()
{
    var rc=0;
   
    // TODO: Loop thru file run_01.dat
	// rc=WJS1_Access_landing( run_TransName, run_URL, run_chance);
    
	rc=WJS1_Access_landing( "T01_landing","http://127.0.0.1:1080/WebTours/index.htm",100);
	if( rc != 0 ){ return rc; }

	return rc;
}

