//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Tue Apr 05 13:15:10 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function Action()
{
 	lr.thinkTime(10.5); // You cannot use standard parameterization for any arguments in this function.

 	var trans_random_number = 72.3;
        wi_random_seed = Math.random() * 100 ;
 	if( wi_random_seed <= trans_random_number ){
		lr.outputMessage(">> Within range. wi_random_seed = " + wi_random_seed + " <= " + trans_random_number );
		// Do stuff.
 	}else{
		lr.outputMessage(">> Out of range. wi_random_seed = " + wi_random_seed + " NOT <= " + trans_random_number );
	}

	return 0;
}

