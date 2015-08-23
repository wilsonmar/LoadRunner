Rec_MSOErr_Userdata()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t75.inf", 
		"Mode=HTML", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404*/

	lr_think_time(10);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t76.inf", 
		LAST);

	lr_think_time(41);

	web_submit_form("login.pl", 
		"Snapshot=t77.inf", 
		ITEMDATA, 
		"Name=username", "Value=jiji04", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=passwordConfirm", "Value=bean", ENDITEM, 
		"Name=firstName", "Value=fname", ENDITEM, 
		"Name=lastName", "Value=lname", ENDITEM, 
		"Name=address1", "Value=street", ENDITEM, 
		"Name=address2", "Value=city", ENDITEM, 
		"Name=register.x", "Value=46", ENDITEM, 
		"Name=register.y", "Value=4", ENDITEM, 
		LAST);

	return 0;
}