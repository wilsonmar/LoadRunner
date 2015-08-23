Rec_SignUp()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404*/

	lr_think_time(17);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t70.inf", 
		LAST);

	return 0;
}