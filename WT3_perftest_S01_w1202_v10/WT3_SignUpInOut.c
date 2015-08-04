/*! 
\file WT3_SignUpInOut.c
\brief Contains functions common to most apps.

WT3_SignUpInOut_Init()
WT3_Customer_attribute_set(){
WT3_UseCase_attribute_set(){

WT3_URL_Landing()
WT3_SignUpErr()
WT3_SignUp()
WT3_SignInErr()
WT3_SignIn()
WT3_SignOut()

*/


	
WT3_SignUpInOut(){ // .c file.
	int rc=LR_PASS;

	if( stricmp("LandingOnly",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUpInOut",LPCSTR_RunType ) == FOUND 
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
		wi_resetPrinting();

	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInErr",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignUpInOut",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("WT3_T04_SignUpNow","pTransName");
		rc=WT3_SignUpNow();
	}


	if( stricmp("SignInErr",LPCSTR_RunType ) == FOUND 
	){
			lr_save_string("XXX","parm_pwd"); // error!
			lr_save_string("WT3_T05_SignIn_Err","pTransName");
	 		rc=T04_SignIn_Err();
	}

		
	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUpInOut",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("WT3_T06_SignUp","pTransName");
		rc=WT3_SignUp();
		if( rc == LR_PASS ){// Added with no error:
			lr_save_string("WT3_T04_SignUp_Continue","pTransName");
			rc=WT3_SignUp_Continue();
		}else{
				// APP DEFECT: Clicking Continue really re-submits failed data again.
				// First need to get back to landing page because there is no login form.
				// Drop through to Signin. TODO: Keep a counter of how many were added already and skipped?
	
			//  stricmp("SignUp",LPCSTR_RunType not need Landing on err because it does Landing first anyway.
			if( stricmp("SignUpInOut",LPCSTR_RunType ) == FOUND 
		    ){
				// Because there is no "Cancel" button in the SignUp screen when "username is taken":
				lr_save_string("WT3_T03_URL_Landing","pTransName");
	 			rc=WT3_URL_Landing(); // just for establishing state to signin or invoke run conitions.
			}
		}
		// else Ignore. 
	}


	//  stricmp("SignUpInOut" not necessary because SignUp also logs in.
	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignInOnly",LPCSTR_RunType ) == FOUND 
    ||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("WT3_T07_SignIn","pTransName");
		rc=WT3_SignIn();
	}
	
	return rc;
}

WT3_SignOut_handle(){
	int rc=LR_PASS;
	
	// No SignOut if SignInOnly.
	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("SignUpInOut",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignUp",LPCSTR_RunType ) == FOUND 
	||  stricmp("SignInOut",LPCSTR_RunType ) == FOUND
	){
		lr_save_string("WT3_T08_SignOut","pTransName");
		rc=WT3_SignOut();
	}

	return rc;
}

WT3_SignUpInOut_Init(){ // Called from Action() on first iteration:
	int rc=LR_PASS;

	original_log_option = lr_get_debug_message(); // Save run-time setting as set in script or scenario.
	vi_set_Verbosity_attribute();
	//    iVerbosity=1; // mute messages to only error during long runs.
//		wi_setPrinting();
//		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
//		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_ON ); // LR_SWITCH_OFF (=0) means stop suppressing output.

	wi_set_unique_id(); // sets global_unique_id base string.	
	
// lr_save_string("no imposed impediments","pRunConditions"); // output in logs.

	rc=vi_set_RunType_attribute();
	rc=vi_set_UseCase_attribute();
	rc=wi_set_Think_Time();

	lr_save_string("{WebToursPath}","pProtocolHostPort");
	web_set_sockets_option("SSL_VERSION", "TLS1.1"); // Windows Internet Options has TLS1.1 and TLS1.2 selected.

//define USE_TIMEZONEOFFSET
#ifdef  USE_TIMEZONEOFFSET
// WT3 does not use client timezoneoffset:
	
	// See http://docs.oracle.com/cd/E13292_01/pt849pbr0/eng/psbooks/tgbl/chapter.htm?File=tgbl/htm/tgbl06.htm
	// Minutes offset from UTC :
	//  lr_save_string("0","timezoneOffset"); // UK (GMT/UTC)
	//	lr_save_string("-330","timezoneOffset"); // IST (India Standard Time)
	//	lr_save_string("360","timezoneOffset"); // US Montain Time during daylight savings
	//	lr_save_string("300","timezoneOffset"); // US Central Time during daylight savings
	//	lr_save_string("120","timezoneOffset"); // US Eastern Time during regular time 
		lr_save_string("180","timezoneOffset"); // US Eastern Time during daylight savings 
	// In the US, daylight savings during Spring and Summer is Sunday Mar. 8 to Nov. 1.
		// Regular time is in the Fall and Winter (October 1 to March 8).
	// Other countries have different daylight savings time dates.
	//	lr_save_string("330","timezoneOffset"); // India Time, which has no daylight savings.
	// WARNING: this number changes from 120 to 180 during daylight savings time.

		wi_startPrintingInfo();
		lr_output_message(">> Iteration=%d timezoneOffset=\"%s\"."
		                  ,iActionIterations
		                  ,lr_eval_string("{timezoneOffset}")
		                 );
		wi_resetPrinting();

#endif // USE_TIMEZONEOFFSET
	
	return 0;
} // WT3_SignUpInOut_Init
	
WT3_URL_Landing(){
	int rc=LR_FAIL; // Unless positive if returned by sub-functions.
	int i;
	for(i=1; i < iRequestRetries; i++){ // 5 times retry: 1,2,3,4,5
		wi_retry_add_time( i );

		// URL Landing page appears after invoking URL:
	
		web_reg_find("Text=Welcome to the Web Tours site","SaveCount=Found_count", LAST );
		wi_start_transaction();

		// regardless if( stricmp("on", lr_eval_string("{MSO_JSFormSubmit1}") ) == FOUND
	
		// Correlatie from response <input type="hidden" name="userSession" value="116443.360064804fQiQfffpDDDDDDDDDfQDHpDDc"/
		// Regular expression is only for Referer RequestURL containing /nav.pl:
		web_reg_save_param_regexp( 
			"ParamName=userSession_capture",
			"RegExp=name=\"userSession\"\\ value=\"(.*?)\"/>\\\n<table\\ border",
			"SEARCH_FILTERS",
			"Scope=Body",
			"IgnoreRedirections=No",
			"RequestUrl=*/nav.pl*",
			LAST);
	
		web_url("index.htm",
			"URL={WebToursPath}/WebTours/index.htm", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer={WebToursPath}/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);

		// Debug level (internal / not user-level data):
		wi_startPrintingDebug();
		lr_output_message(">> ParamName=userSession_capture=%s for MSO_JSFormSubmit1=%s."
	                  ,lr_eval_string("{userSession_capture}")
	                  ,lr_eval_string("{MSO_JSFormSubmit1}")
	                  );
		wi_resetPrinting();

		rc=wi_end_transaction();

		if( atoi( lr_eval_string("{Found_count}") ) >= 1 ){
			rc=LR_PASS;
			break; // out of loop.			
		}else{
			// cycle through loop again to retry.
			rc=LR_FAIL; // Fall-out of loop when retries are exhausted.
		}
	} 	

	return rc;
} //WT3_URL_Landing	
	


WT3_SignUp_Data(){ // one-time only.
	
	lr_save_string("POBOX 1"			,"SignUp_address1");
	lr_save_string("Anywhere, CA 92341"	,"SignUp_address2");

return 0;
} //WT3_URL_Landing	


/// This obtains the blank SigUp input form.
WT3_SignUpNow(){
	int rc;
	int i;
	for(i=1; i < iRequestRetries; i++){ // 5 times retry: 1,2,3,4,5
		wi_retry_add_time( i );
	
		web_reg_find("Text=First time registering", "Fail=NotFound", "SaveCount=Found_count", LAST );

		wi_start_transaction();
		web_link("sign up now",
			"Text=sign up now", 
			"Snapshot=t2.inf", 
			LAST);
		rc=wi_end_transaction();

		if( atoi( lr_eval_string("{Found_count}") ) >= 1 ){
			rc=LR_PASS;
			break; // out of loop.			
		}else{
			rc=LR_FAIL;
		}
	}

	return rc;
}

WT3_SignUp_Error(){
	int rc=LR_PASS;

	// Sign up using already registered user name and password
	// username as jojo and password as bean.


//	web_reg_find("Text=Your username is taken", "Fail=NotFound", LAST); // Intended error message.
	web_reg_find("Text=Your username is taken","SaveCount=DBErr_count", LAST );

	wi_start_transaction();
	web_submit_form("SignIn.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username"			,"Value={parm_userid}", ENDITEM, 
		"Name=password"			,"Value={parm_pwd}", ENDITEM, 
		"Name=passwordConfirm"	,"Value={parm_pwd}", ENDITEM, 
		"Name=firstName"		,"Value=", ENDITEM, 
		"Name=lastName"			,"Value=", ENDITEM, 
		"Name=address1"			,"Value=", ENDITEM, 
		"Name=address2"			,"Value=", ENDITEM, 
		"Name=register.x"		,"Value=40", ENDITEM, 
		"Name=register.y"		,"Value=7", ENDITEM, 
		LAST);

	rc=wi_end_transaction();

	return 0;		
} // WT3_SignUp_Error

	
WT3_SignUp(){
	int rc=LR_PASS;
	int i;
	for(i=1; i < iRequestRetries; i++){ // 5 times retry: 1,2,3,4,5
		wi_retry_add_time( i );
	
		// TODO: Add logic to get another data value if a value is already taken.

		// signing up with new username and password to populate in database.

		web_reg_find("Text=Thank you, <b>","SaveCount=Found_count", LAST); // positive test
		web_reg_find("Text=Your username is taken","SaveCount=Err_count", LAST ); // negative test

		wi_start_transaction();

		//	"Name=firstName"			,"Value={parm_userid}", ENDITEM,
		// DEBUGGING: Blank to trigger MSO_JSVerify error.
	
		web_submit_data("T05_SignUp", 
			"Action={WebToursPath}/cgi-bin/login.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={WebToursPath}/cgi-bin/login.pl?username=&password=&getInfo=true", 
			"Snapshot=t19.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=username"				,"Value={parm_userid}", ENDITEM, 
			"Name=password"				,"Value={parm_pwd}", ENDITEM, 
			"Name=passwordConfirm"		,"Value={parm_pwd}", ENDITEM, 
			"Name=firstName"			,"Value={parm_userid}", ENDITEM,
			"Name=lastName"				,"Value={global_unique_id}", ENDITEM, 
			"Name=address1"				,"Value={SignUp_address1}", ENDITEM,
			"Name=address2"				,"Value={SignUp_address2}", ENDITEM,
			"Name=register.x"			,"Value=50", ENDITEM, 
			"Name=register.y"			,"Value=5", ENDITEM, 
			LAST);
		rc=wi_end_transaction();
		wi_noop();
		
		if( atoi( lr_eval_string("{Found_count}") ) >= 1 ){
			rc = LR_PASS;
			break; // exit loop successfully.			
		}else{ // "Thank you not found.
			rc = LR_FAIL; 
			if( atoi( lr_eval_string("{Err_count}") ) > 0 ){
				// Signup already exists.
				break; // because already found, so no need to retry SignUp.
			} 
			// cycle through loop again to retry.
		}
	}
	return rc;
} //T05_SignUp
	
WT3_SignUp_Continue(){
	int rc=LR_PASS;

	web_reg_find("Text=Welcome, <b>{parm_userid}", LAST);
	
	wi_start_transaction();
	web_url("button_next.gif", 
		"URL={WebToursPath}/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={WebToursPath}/cgi-bin/login.pl", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	rc=wi_end_transaction();
	
	return rc;
} //WT3_SignUp_Continue

	
WT3_SignIn_Error(){
	int rc=LR_PASS;

	// singning in with valid username and password which is just created
	// username as jojo01 and password as bean.

	web_reg_find("Text=Web Tours Error - Incorrect Password", "Fail=NotFOund", LAST); // Error is intended.
	// Instead of {parm_userid} and {parm_pwd}
	wi_start_transaction();
	web_submit_form("SignIn.pl_4", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=username", "Value=Something", ENDITEM, 
		"Name=password", "Value=Unknown", ENDITEM, 
		"Name=login.x", "Value=29", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		LAST);
	rc=wi_end_transaction();
	
	return 0;		
} //WT3_SignIn_Error


WT3_SignIn(){
	int rc=LR_PASS;
	int i;
	for(i=1; i < iRequestRetries; i++){ // 5 times retry: 1,2,3,4,5
		wi_retry_add_time( i );
	
		// signing in with valid username and password which is just created
		// Such as username as jojo01 and password as bean.

		// TODO: If {parm_userid} is blank, return as error.
		// Response HTML: <blockquote>Welcome, <b>jaja01</b>, to the Web Tour
		web_reg_find("Text=Welcome, <b>{parm_userid}</b>,", "Fail=NOTFOUND", "SaveCount=Found_count", LAST); // positive test

		wi_start_transaction();
		web_submit_form("SignIn.pl_4", 
			"Snapshot=t6.inf", 
			ITEMDATA, 
			"Name=username", "Value={parm_userid}", ENDITEM, 
			"Name=password", "Value={parm_pwd}", ENDITEM, 
			"Name=login.x", "Value=29", ENDITEM, 
			"Name=login.y", "Value=10", ENDITEM, 
			LAST);
		rc=wi_end_transaction();
	
		if(rc == LR_PASS){
			isSignedIn = TRUE;
		}else{
			isSignedIn = FALSE;
		}
	
		if( atoi( lr_eval_string("{Found_count}") ) >= 1 ){
			rc = LR_PASS;
			break; // exit loop successfully.			
		}else{ // "Thank you not found.
			rc = LR_FAIL; 
		}
	}

	return rc;		
} //WT3_SignIn


WT3_SignOut(){
	int rc=LR_PASS;
	
	// Siging off from the application:

	if(isSignedIn == TRUE){
	
		web_reg_find("Text=Welcome to the Web Tours site", "Fail=NOTFOUND", LAST);
		wi_start_transaction();
		web_image("SignOff Button", 
			"Alt=SignOff Button", 
			"Snapshot=t7.inf", 
			LAST);
		rc=wi_end_transaction();

	} // if(isSignedIn == TRUE)
	
	return rc;
}//WT3_SignOut
