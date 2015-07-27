Recording_Travel_For_Validation()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	/* Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404*/

	web_add_cookie("MSFPC=ID=0a483d9b404672469c36676c7ba16f34&CS=1&LV=201504&V=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MC1=GUID=0a483d9b404672469c36676c7ba16f34&HASH=0a48&LV=201504&V=4&LU=1428540179491; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("A=I&I=AxUFAAAAAADiCAAAtqVUJ2dOsbwHJwijX2AXNw!!&V=4; DOMAIN=iecvlist.microsoft.com");

	lr_think_time(71);

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE10/1152921505002013023/iecompatviewlist.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("LogIn");

	web_reg_find("Text=Welcome", 
		LAST);

	web_reg_find("Text=Itinerary", 
		LAST);

	lr_think_time(39);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t56.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=115814.85054678fQfHcczpDHfDfHtDpDficf", ENDITEM, 
		"Name=username", "Value=jojo1", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=38", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("LogIn",LR_AUTO);

	lr_think_time(59);

	lr_start_transaction("WT3_T21_Travel_Home");

	web_image("Home Button", 
		"Alt=Home Button", 
		"Snapshot=t57.inf", 
		LAST);

	lr_end_transaction("WT3_T21_Travel_Home",LR_AUTO);

	lr_start_transaction("WT3_T22_Travel_Search_Flight");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(47);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Ordinal=1", 
		"Snapshot=t58.inf", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("WT3_T22_Travel_Search_Flight",LR_AUTO);

	lr_start_transaction("WT3_T23_Travel_Flight_Lookup");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(54);

	web_submit_form("reservations.pl", 
		"Snapshot=t59.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=04/23/2015", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=04/24/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=30", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T23_Travel_Flight_Lookup",LR_AUTO);

	lr_start_transaction("WT3_T24_Find_Flight");

	web_reg_find("Text=Payment Details", 
		LAST);

	lr_think_time(159);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t60.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=030;251;04/23/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=35", ENDITEM, 
		"Name=reserveFlights.y", "Value=3", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T24_Find_Flight",LR_AUTO);

	lr_think_time(147);

	lr_start_transaction("WT3_T25_Travel_Payment_Details");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t61.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=whatever", ENDITEM, 
		"Name=lastName", "Value=whatever", ENDITEM, 
		"Name=address1", "Value=whatever", ENDITEM, 
		"Name=address2", "Value=whatever", ENDITEM, 
		"Name=pass1", "Value=whatever whatever", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=12/20", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=47", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T25_Travel_Payment_Details",LR_AUTO);

	lr_start_transaction("WT3_T26_Travel_Invoice");

	lr_end_transaction("WT3_T26_Travel_Invoice",LR_AUTO);

	lr_start_transaction("WT3_T27_Travel_Click_Book_Another");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(83);

	web_submit_form("reservations.pl_4", 
		"Snapshot=t62.inf", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=27", ENDITEM, 
		"Name=Book Another.y", "Value=1", ENDITEM, 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("WT3_T27_Travel_Click_Book_Another",LR_AUTO);

	lr_start_transaction("WT3_T28_Travel_Search_Flight2");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(96);

	web_image("Search Flights Button_2", 
		"Alt=Search Flights Button", 
		"Ordinal=1", 
		"Snapshot=t63.inf", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("WT3_T28_Travel_Search_Flight2",LR_AUTO);

	lr_start_transaction("WT3_T29_Travel_Flight_Lookup2");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(63);

	web_submit_form("reservations.pl_5", 
		"Snapshot=t64.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=04/23/2015", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=04/24/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=29", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T29_Travel_Flight_Lookup2",LR_AUTO);

	lr_start_transaction("WT3_T30_Travel_Find_Flight2");

	web_reg_find("Text=Payment Details", 
		LAST);

	lr_think_time(99);

	web_submit_form("reservations.pl_6", 
		"Snapshot=t65.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=030;251;04/23/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=35", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T30_Travel_Find_Flight2",LR_AUTO);

	lr_start_transaction("WT3_T31_Travel_Payment_Details2");

	web_reg_find("Text=Invoice", 
		LAST);

	lr_think_time(83);

	web_submit_form("reservations.pl_7", 
		"Snapshot=t66.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=whatever", ENDITEM, 
		"Name=lastName", "Value=whatever", ENDITEM, 
		"Name=address1", "Value=whatever", ENDITEM, 
		"Name=address2", "Value=whatever", ENDITEM, 
		"Name=pass1", "Value=whatever whatever", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=12/20", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=23", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("WT3_T31_Travel_Payment_Details2",LR_AUTO);

	lr_think_time(92);

	lr_start_transaction("WT3_T32_Travel_Invoice2");

	lr_end_transaction("WT3_T32_Travel_Invoice2",LR_AUTO);

	lr_start_transaction("WT3_T33_Travel_Check_Itinerary");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Ordinal=1", 
		"Snapshot=t67.inf", 
		LAST);

	lr_end_transaction("WT3_T33_Travel_Check_Itinerary",LR_AUTO);

	lr_think_time(45);

	lr_start_transaction("logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Ordinal=1", 
		"Snapshot=t68.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}