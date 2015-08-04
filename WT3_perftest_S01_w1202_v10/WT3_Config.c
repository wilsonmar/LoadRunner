/*! 
\file WT3_Config.c
\brief Contains functions to establish run conditions and other configurations.

int WT3_Config_Run_Conditions(){
int WT3_Print_Run_Conditions(){
int WT3_Invoke_Run_Conditions(){

*/

WT3_Config()
{
	return 0;
}

/*

if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("Personalize",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T06_Select_My_Personalizations","pTransName");
//		rc=T06_Select_My_Personalizations();
*/


int WT3_Config_Run_Conditions(){ // after landing
	// TODO: Enable Run-time Attribute change of run conditions

	// Switch from "<OFF>" to "on":
	lr_save_string("<OFF>","MSO_Comments");
	lr_save_string("<OFF>","MSO_JSCalc");
	lr_save_string("<OFF>","MSO_JSFormSubmit1"); // Set LOGIN form's action tag to an error page. 
	lr_save_string("<OFF>","MSO_JSFormSubmit2");
	lr_save_string("on","MSO_JSVerify"); // Verify inputs for non-blank entries.
	lr_save_string("<OFF>","MSO_JSWPages");
	lr_save_string("<OFF>","MSO_Redirect");
	lr_save_string("<OFF>","MSO_Redirects");
	lr_save_string("on","MSO_SErrors"); // Returns HTTP 500 (Internal Server Error).
	lr_save_string("100","MSO_ServerErrorsProb");
	lr_save_string("<OFF>","MSO_SLoad");
	lr_save_string("50","MSO_ServerLoadProb");

	return 0;
}

int WT3_Print_Run_Conditions(){

	wi_startPrintingInfo();
	lr_output_message(">> MSO_Comments=%s",lr_eval_string("{MSO_Comments}"));
	lr_output_message(">> MSO_JSCalc=%s",lr_eval_string("{MSO_JSCalc}"));
	lr_output_message(">> MSO_JSCalc=%s",lr_eval_string("{MSO_JSCalc}"));
	lr_output_message(">> MSO_JSFormSubmit1=%s",lr_eval_string("{MSO_JSFormSubmit1}"));
	lr_output_message(">> MSO_JSFormSubmit2=%s",lr_eval_string("{MSO_JSFormSubmit2}"));
	lr_output_message(">> MSO_JSVerify=%s",lr_eval_string("{MSO_JSVerify}"));
	lr_output_message(">> MSO_JSWPages=%s",lr_eval_string("{MSO_JSWPages}"));
	lr_output_message(">> MSO_Redirect=%s",lr_eval_string("{MSO_Redirect}"));
	lr_output_message(">> MSO_Redirects=%s",lr_eval_string("{MSO_Redirects}"));
	lr_output_message(">> MSO_SErrors=%s (%s%%)",lr_eval_string("{MSO_SErrors}"),lr_eval_string("{MSO_ServerErrorsProb}"));
	lr_output_message(">> MSO_SLoad=%s (%s%%)",lr_eval_string("{MSO_SLoad}"),lr_eval_string("{MSO_ServerLoadProb}"));
	wi_resetPrinting();

	return 0;
}

int WT3_Invoke_Run_Conditions(){ // after landing
	// TODO: Separate 

	web_link("administration", 
		"Text=administration", 
		"Snapshot=t2.inf", 
		LAST);

	web_submit_form("admin.pl",
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=MSO_Comments", "Value={MSO_Comments}", ENDITEM, 
		"Name=MSO_JSCalc", "Value={MSO_JSCalc}", ENDITEM, 
		"Name=MSO_JSFormSubmit1", "Value={MSO_JSFormSubmit1}", ENDITEM, 
		"Name=MSO_JSFormSubmit2", "Value={MSO_JSFormSubmit2}", ENDITEM, 
		"Name=MSO_JSVerify", "Value={MSO_JSVerify}", ENDITEM, 
		"Name=MSO_JSWPages", "Value={MSO_JSWPages}", ENDITEM, 
		"Name=MSO_Redirect", "Value={MSO_Redirect}", ENDITEM, 
		"Name=MSO_Redirects", "Value={MSO_Redirects}", ENDITEM, 
		"Name=MSO_SErrors", "Value={MSO_SErrors}", ENDITEM, 
		"Name=MSO_ServerErrorsProb", "Value={MSO_ServerErrorsProb}", ENDITEM, 
		"Name=MSO_SLoad", "Value={MSO_SLoad}", ENDITEM, 
		"Name=MSO_ServerLoadProb", "Value={MSO_ServerLoadProb}", ENDITEM, 
		"Name=save", "Value=Update", ENDITEM, 
		LAST);

	web_url("Return to the Web Tours Homepage", 
		"URL={WebToursPath}/cgi-bin/welcome.pl", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={WebToursPath}/cgi-bin/admin.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	return 0;
} // WT3_Config_Run_Conditions
