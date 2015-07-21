Recording_Admin_Config()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t193.inf", 
		"Mode=HTML", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404*/

	lr_think_time(90);

	lr_start_transaction("WT3_T01_URL_Landing");

	lr_end_transaction("WT3_T01_URL_Landing",LR_AUTO);

	lr_start_transaction("WT3_T02_Click_Administration_Link");

	web_link("administration", 
		"Text=administration", 
		"Snapshot=t194.inf", 
		LAST);

	lr_end_transaction("WT3_T02_Click_Administration_Link",LR_AUTO);

	lr_think_time(69);

	lr_start_transaction("WT3_T03_CheckAllBoxes");

	web_submit_form("admin.pl", 
		"Snapshot=t195.inf", 
		ITEMDATA, 
		"Name=MSO_Comments", "Value=on", ENDITEM, 
		"Name=MSO_JSCalc", "Value=on", ENDITEM, 
		"Name=MSO_JSFormSubmit1", "Value=on", ENDITEM, 
		"Name=MSO_JSFormSubmit2", "Value=on", ENDITEM, 
		"Name=MSO_JSVerify", "Value=on", ENDITEM, 
		"Name=MSO_JSWPages", "Value=on", ENDITEM, 
		"Name=MSO_Redirect", "Value=on", ENDITEM, 
		"Name=MSO_Redirects", "Value=on", ENDITEM, 
		"Name=MSO_SErrors", "Value=on", ENDITEM, 
		"Name=MSO_ServerErrorsProb", "Value=50", ENDITEM, 
		"Name=MSO_SLoad", "Value=on", ENDITEM, 
		"Name=MSO_ServerLoadProb", "Value=50", ENDITEM, 
		"Name=save", "Value=Update", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T03_CheckAllBoxes",LR_AUTO);

	lr_think_time(61);

	lr_start_transaction("WT3_T04_");

	web_link("Return to the Web Tours Homepage", 
		"Text=Return to the Web Tours Homepage", 
		"Snapshot=t196.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	lr_end_transaction("WT3_T04_",LR_AUTO);

	return 0;
}