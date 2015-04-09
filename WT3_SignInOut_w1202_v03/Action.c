// v03  2015.04.09 WM: Move app_specific Transactions to separate function in Action.c.
// v03  2015.04.09 Deleted TT and LR Start and LR End Transactions.
//Run types
//Added wi fuctions
// v02  2015.04.07
// v01 2015.03.23a LandingOnly

Action()
{
	int rc=LR_PASS;
	int i=0;
	
	     iActionIterations++; // increment from zero value defined in vuser_init.
	 if( iActionIterations == 1){
	     SignInOut_Init(); // establish variables.
	 }

	if( stricmp("LandingOnly",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignInOnly",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND 
	){ // Do every iteration:
		lr_save_string("T03_URL_Landing","pTransName");
		rc=T03_URL_Landing();
	}else
	if( stricmp("All",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignUpErr",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInErr",LPCSTR_RunType ) == FOUND
	){ // Do on first iteration only:
		if( iActionIterations == 1 ){
			lr_save_string("T03_URL_Landing","pTransName");
			rc=T03_URL_Landing();
		}
	}

// --- Do the rest every iteration:

	if( stricmp("SignUpErr",LPCSTR_RunType ) == FOUND 
	){ // Signing up a known user already defined:

			lr_save_string("jojo","parm_userid");
			lr_save_string("bean","parm_pwd");
			
			lr_save_string("T04_SignUp_Err","pTransName");
	 		rc=T04_SignUp_Err();
	 	}
	else
	if( stricmp("SignInErr",LPCSTR_RunType ) == FOUND 
	){
//	 	for(i=0; i<4; i++){ // 0,1,2,3 (4 times)

			lr_save_string("XXX","parm_pwd"); // error!
			lr_save_string("T04_SignUp_Err","pTransName");
	 		rc=T04_SignUp_Err();

			lr_save_string("T04_SignIn_Err","pTransName");
	 		rc=T04_SignIn_Err();
//	 	}
	}

	// Valid users from here on:
		lr_save_string(lr_eval_string("{UserIds_userid}"),"parm_userid");
		lr_save_string(lr_eval_string("{UserIds_pwd}"),"parm_pwd");
		wi_startPrintingInfo();
		lr_output_message(">> Iteration=%d User=\"%s\" timezoneOffset=\"%s\"."
		                  ,iActionIterations
		                  ,lr_eval_string("{parm_userid}")
		                  ,lr_eval_string("{timezoneOffset}")
		                 );
		wi_stopPrinting();


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T05_SignUp","pTransName");
		rc=T05_SignUp();
		if( rc == 0 ){
			lr_save_string("T06_SignUp_Continue","pTransName");
			rc=T06_SignUp_Continue();
		}
	}

		
	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInOnly",LPCSTR_RunType ) == FOUND 
    ||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T12_SignIn","pTransName");
		rc=T12_SignIn();
	}
	
Travel_functions();

	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND
	){
		lr_save_string("T13_SignOut","pTransName");
		rc=T13_SignOut();
	}
  
	return rc;
}
