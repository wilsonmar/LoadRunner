Action()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	/* Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404*/

	lr_start_transaction("WT_T01_LandingPage");

	lr_end_transaction("WT_T01_LandingPage",LR_AUTO);

	lr_start_transaction("WT_T02_LogIn");

	lr_save_string(lr_decrypt("56b54b687b823bf2"), "PasswordParameter");

	lr_think_time(54);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=117838.93236128zAzVDtApAiDDDDDDDzDzipAtAf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value={PasswordParameter}", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=login.x", "Value=42", ENDITEM, 
		"Name=login.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("WT_T02_LogIn",LR_AUTO);

	lr_think_time(36);

	lr_start_transaction("WT_T03_Search_Flights");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("WT_T03_Search_Flights",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("WT_T04_Find_Flights");

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=02/06/2016", ENDITEM, 
		"Name=arrive", "Value=Portland", ENDITEM, 
		"Name=returnDate", "Value=02/07/2016", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=56", ENDITEM, 
		"Name=findFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("WT_T04_Find_Flights",LR_AUTO);

	lr_think_time(23);

	lr_start_transaction("WT_T05_Select_Flight");

	web_submit_form("reservations.pl_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=050;275;02/06/2016", ENDITEM, 
		"Name=reserveFlights.x", "Value=31", ENDITEM, 
		"Name=reserveFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("WT_T05_Select_Flight",LR_AUTO);

	lr_think_time(29);

	lr_start_transaction("WT_T06_Payment_Details");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=64", ENDITEM, 
		"Name=buyFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("WT_T06_Payment_Details",LR_AUTO);

	lr_think_time(27);

	lr_start_transaction("WT_T07_Check_Itinerary");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Ordinal=1", 
		"Snapshot=t7.inf", 
		LAST);

	lr_end_transaction("WT_T07_Check_Itinerary",LR_AUTO);

	lr_think_time(43);

	lr_start_transaction("WT_T08_LogOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Ordinal=1", 
		"Snapshot=t8.inf", 
		LAST);

	lr_end_transaction("WT_T08_LogOff",LR_AUTO);

	return 0;
}