Recording_Config()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t185.inf", 
		"Mode=HTML", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404*/

	lr_start_transaction("WT3_T03_URL_Landing");

	lr_end_transaction("WT3_T03_URL_Landing",LR_AUTO);

	lr_start_transaction("WT3_T08_SignIn");

	web_reg_find("Text=Welcome, <b>jojo", 
		LAST);

	lr_think_time(54);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t186.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=116429.837829081fQiiifQpHiDDDDDDDfQDDpVfiH", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=login.x", "Value=22", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T08_SignIn",LR_AUTO);

	lr_start_transaction("WT3_T22_Travel_Search_Flight");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(36);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t187.inf", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("WT3_T22_Travel_Search_Flight",LR_AUTO);

	lr_start_transaction("WT3_T23_Travel_Flight_Lookup");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(115);

	web_submit_form("reservations.pl", 
		"Snapshot=t188.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=07/20/2015", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=07/21/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=37", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		EXTRARES, 
		"Url=../WebTours/images/resubmit.gif", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T23_Travel_Flight_Lookup",LR_AUTO);

	lr_start_transaction("WT3_T24_Find_Flight");

	/* Request with POST method to URL "http://127.0.0.1:1080/cgi-bin/reservations.pl" failed during recording. Server response : 503*/

	/* Request with POST method to URL "http://127.0.0.1:1080/cgi-bin/reservations.pl" failed during recording. Server response : 503*/

	web_reg_find("Text=Payment Details", 
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t189.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=outboundFlight", "Value=030;251;07/20/2015", ENDITEM, 
		"Name=reutrnFlight", "Value=", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=33", ENDITEM, 
		"Name=reserveFlights.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T24_Find_Flight",LR_AUTO);

	lr_start_transaction("WT3_T25_Travel_Payment_Details");

	web_reg_find("Text=Invoice", 
		LAST);

	lr_think_time(57);

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t190.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=123 Wood Duck Drive", ENDITEM, 
		"Name=address2", "Value=Dallas/TX/76039", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=12/15", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value=030;251;07/20/2015", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=35", ENDITEM, 
		"Name=buyFlights.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T25_Travel_Payment_Details",LR_AUTO);

	lr_think_time(31);

	lr_start_transaction("WT3_T33_Travel_Check_Itinerary");

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t191.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("WT3_T33_Travel_Check_Itinerary",LR_AUTO);

	lr_think_time(22);

	lr_start_transaction("WT3_T09_SignOut");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t192.inf", 
		LAST);

	lr_end_transaction("WT3_T09_SignOut",LR_AUTO);

	return 0;
}