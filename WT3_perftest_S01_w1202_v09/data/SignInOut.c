SignInOut()
{

	web_reg_find("Text=Welcome to the Web Tours site", 
		LAST);

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	/* URL Landing page appears after invoking URL. */

	lr_think_time(295);

	lr_start_transaction("T03_URL_Landing");

	lr_end_transaction("T03_URL_Landing",LR_AUTO);

	/* Sign up using already registered user name and password
	   username as jojo and password as bean. */

	lr_start_transaction("T04_SignUp_Error");

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t2.inf", 
		LAST);

	web_reg_find("Text=Your username is taken", 
		LAST);

	lr_think_time(30);

	web_submit_form("login.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=passwordConfirm", "Value=bean", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=40", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("T04_SignUp_Error",LR_AUTO);

	/* signing up with new username and password to populate in database.  */

	lr_start_transaction("T05_SignUp");

	web_reg_find("Text=Thank you, <b>jojo01", 
		LAST);

	lr_think_time(151);

	web_submit_form("login.pl_2", 
		"Ordinal=1", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo01", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=passwordConfirm", "Value=bean", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=50", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("T05_SignUp",LR_AUTO);

	/* performing signin error by inputting 
	   username "xxx" and leaving password empty. */

	lr_start_transaction("T08_SingIn Error");

	web_reg_find("Text=Web Tours Error - Incorrect Password", 
		LAST);

	lr_think_time(132);

	web_submit_data("login.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=115695.667719725fQfVAQfpQAiDDDDDDfHAzpfHftf", ENDITEM, 
		"Name=username", "Value=xxx", ENDITEM, 
		"Name=password", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=35", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("T08_SingIn Error",LR_AUTO);

	/* singning in with valid username and password which is just created
	   username as jojo01 and password as bean. */

	lr_start_transaction("T12_SignIn");

	web_reg_find("Text=Welcome, <b>jojo01", 
		LAST);

	lr_think_time(140);

	web_submit_form("login.pl_4", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo01", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=29", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("T12_SignIn",LR_AUTO);

	/* siging off from the application. */

	lr_think_time(89);

	lr_start_transaction("T13_SignOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t7.inf", 
		LAST);

	web_find("Text Check", "What=Welcome to the Web Tours site", LAST);

	lr_end_transaction("T13_SignOff",LR_AUTO);

	return 0;
}