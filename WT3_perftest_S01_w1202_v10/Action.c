/*! 
\file Action.c
\brief Contains Action() function compiler looks for to invoke every iteration during run. 
*/

Action()
{
	int rc=LR_PASS;
	int i=0;
	
	     iActionIterations++; // increment from zero value defined in vuser_init.
	 if( iActionIterations == 1){
	     WT3_SignUpInOut_Init(); // establish variables.
  
		 lr_save_string("WT3_T03_URL_Landing_1","pTransName");
 		 WT3_Config_Run_Conditions();
	     rc=WT3_URL_Landing(); // just for establishing state to invoke run conditions.
 		 WT3_Config_Run_Conditions();
 		 WT3_Invoke_Run_Conditions();
	 }


	     if( stricmp("LandingOnly",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignInOnly",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND 
	){ // Do every iteration:
		lr_save_string("WT3_T03_URL_Landing","pTransName");
		rc=WT3_URL_Landing();
	}else
	if( stricmp("All",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignUpErr",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInErr",LPCSTR_RunType ) == FOUND
	){ // Do on first iteration only:
		if( iActionIterations == 1 ){
			lr_save_string("WT3_T03_URL_Landing","pTransName");
			rc=WT3_URL_Landing();
		}
	}
	     
// --- Do the rest every iteration:

	if( stricmp("SignUpErr",LPCSTR_RunType ) == FOUND 
	){ // Signing up a known user already defined:

		// Try to sign up a known existing (built-in) userid and password:
			lr_save_string("jojo","parm_userid");
			lr_save_string("bean","parm_pwd"); 
			
			lr_save_string("WT3_T04_SignUp_Err","pTransName");
	 		rc=T04_SignUp_Err();
	}

		lr_save_string(lr_eval_string("{UserIds_userid}"),"parm_userid");
		lr_save_string(lr_eval_string("{UserIds_pwd}"),"parm_pwd");
		wi_startPrintingInfo();
		lr_output_message(">> Iteration=%d User=\"%s\"."
		                  ,iActionIterations
		                  ,lr_eval_string("{parm_userid}")		                 );
		wi_stopPrinting();


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("WT3_T05_SignUp","pTransName");
		rc=WT3_SignUp();
		if( rc == 0 ){
			lr_save_string("WT3_T04_SignUp_Continue","pTransName");
			rc=WT3_SignUp_Continue();
		}
	}


	if( stricmp("SignInErr",LPCSTR_RunType ) == FOUND 
	){
//	 	for(i=0; i<4; i++){ // 0,1,2,3 (4 times)

			lr_save_string("XXX","parm_pwd"); // error!
			lr_save_string("WT3_T05_SignIn_Err","pTransName");
	 		rc=T04_SignIn_Err();
//	 	}
	}


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInOnly",LPCSTR_RunType ) == FOUND 
    ||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("WT3_T07_SignIn","pTransName");
		rc=WT3_SignIn();
	}
	
		rc=WT3_Travel(); // to handle UseCase attribute.


		if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND
	){
		lr_save_string("WT3_T08_SignOut","pTransName");
		rc=WT3_SignOut();
	}
  
	return rc;
}
