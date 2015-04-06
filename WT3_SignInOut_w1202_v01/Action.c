// v01 2015.03.23a LandingOnly

Action()
{
	int rc=LR_PASS;
	int i=0;
	
	     iActionIterations++; // increment from zero value defined in vuser_init.
	 if( iActionIterations == 1){
	     SignInOut_Init(); // establish variables.
	 }

	// All or SignInOut or LandingOnly
	if( stricmp("LandingOnly",LPCSTR_RunType ) == FOUND 
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
	}else
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


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInOnly",LPCSTR_RunType ) == FOUND 
    ||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string(lr_eval_string("{UserIds_userid}"),"parm_userid");
		lr_save_string("password1","parm_pwd");
		wi_startPrintingInfo();
		lr_output_message(">> Iteration=%d User=\"%s\" timezoneOffset=\"%s\"."
		                  ,iActionIterations
		                  ,lr_eval_string("{parm_userid}")
		                  ,lr_eval_string("{timezoneOffset}")
		                 );
		wi_stopPrinting();

		lr_save_string("T12_SignIn","pTransName");
		rc=T12_SignIn();
	}
	

	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("ChangeProfile",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T04_Select_My_System_Profile","pTransName");
//		rc=T04_Select_My_System_Profile();
	}


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("Personalize",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T06_Select_My_Personalizations","pTransName");
//		rc=T06_Select_My_Personalizations();
	}


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("Home",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T07_Home","pTransName");
//		rc=T07_Home();
	}


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND
	){
		lr_save_string("T08_SignOut","pTransName");
		rc=T08_SignOut();
	}
  
	return rc;
}
