/*! 
\file Action.c
\brief Contains Action() function compiler looks for to invoke every iteration during run. 
*/

Action()
{
	int rc=LR_PASS;
	int i=0;
	
	     iActionIterations++; // increment from zero value defined in vuser_init.
	 if( iActionIterations == 1){ // instead of being in vuser_init.
		WT3_SignUpInOut_Init(); // establish variables.
  
		lr_save_string("http://127.0.0.1:1080","WebToursPath"); // TODO: Convert into LoginURL RunTime Attribute.
		lr_output_message(">> {WebToursPath}=%s", lr_eval_string("{WebToursPath}"));
		wi_save_request_header(); // to wi_show_user_agent() later.
		
		lr_save_string("WT3_T03_URL_Landing_1","pTransName");
 		rc=WT3_URL_Landing(); // just for establishing state to invoke run conditions.
 		wi_show_user_agent();
 		WT3_Config_Run_Conditions();
 		WT3_Invoke_Run_Conditions();

 		WT3_SignUp_Data();
	 }

	rc=WT3_SignUpInOut(); // to handle specified RunType attribute.

	if( rc == LR_PASS ){
		rc=WT3_Travel(); // to handle specified UseCase attribute.
	}

	rc=WT3_SignOut_handle();
	
	return rc;
}
