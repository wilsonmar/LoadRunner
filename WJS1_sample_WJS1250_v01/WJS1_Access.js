function WJS1_Access()
{
	return 0;
}

function WJS1_Access_landing( in_trans , in_url, in_chance){
    var rc=0;
 	
        wi_random_seed = Math.random() * 100 ;
 	if( wi_random_seed <= in_chance ){
        // Debug:
      	//lr.outputMessage(">> Trans " + in_trans + 
        //                 " wi_random_seed " + wi_random_seed + " <= " + in_chance +".");
		// Do stuff:
		rc=wi_web_url_http( in_trans , in_url );
		if( rc != 0 ){ return rc; }
 	}else{
        var n = wi_random_seed.toFixed(1);
        // Trace:
		lr.outputMessage(">> Trans " + in_trans +
                         " not selected for execution. wi_random_seed = " + n + " NOT <= " + in_chance +".");
	}

	return rc;
}

/*
function WJS1_Access_SignUp()
function WJS1_Access_SignIn()
function WJS1_Access_SignOut()
function WJS1_Access_Reset_Password()
*/
