Recording_Travel()
{

	web_url("index.htm", 
		"URL={WebToursPath}/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	/* Request with GET method to URL "{WebToursPath}/favicon.ico" failed during recording. Server response : 404*/

	lr_think_time(60);

	lr_start_transaction("Invoke_URL");

	lr_end_transaction("Invoke_URL",LR_AUTO);

	lr_start_transaction("LogIn");

	web_submit_form("login.pl", 
		"Snapshot=t31.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo1", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=57", ENDITEM, 
		"Name=login.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("LogIn",LR_AUTO);

	lr_think_time(35);

	lr_start_transaction("T21_Home");

	web_image("Home Button", 
		"Alt=Home Button", 
		"Snapshot=t32.inf", 
		LAST);

	lr_end_transaction("T21_Home",LR_AUTO);

	lr_start_transaction("T22_Search_Flight");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(54);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t33.inf", 
		LAST);

	/* Request with GET method to URL "{WebToursPath}/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "{WebToursPath}/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("T22_Search_Flight",LR_AUTO);

	lr_start_transaction("T23_ Flight_Lookup");

	web_reg_find("Text=Flight departing from", 
		LAST);

	lr_think_time(93);

	web_submit_form("reservations.pl", 
		"Snapshot=t34.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=04/14/2015", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=04/15/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=40", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("T23_ Flight_Lookup",LR_AUTO);

	//lr_start_transaction("T24_ Payment_Details");

	web_reg_find("Text=Payment Details", 
		LAST);

	lr_think_time(68);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t35.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=030;251;04/14/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=46", ENDITEM, 
		"Name=reserveFlights.y", "Value=11", ENDITEM, 
		LAST);

	web_reg_find("Text=Invoice", 
		LAST);

	lr_think_time(56);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t36.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=whatever", ENDITEM, 
		"Name=lastName", "Value=whatever", ENDITEM, 
		"Name=address1", "Value=whatever", ENDITEM, 
		"Name=address2", "Value=whatever", ENDITEM, 
		"Name=pass1", "Value=whatever whatever", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=41", ENDITEM, 
		"Name=buyFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("T24_ Payment_Details",LR_AUTO);

	lr_start_transaction("T25_Invoice");

	lr_end_transaction("T25_Invoice",LR_AUTO);

	lr_start_transaction("T26_ Click_Book Another ");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(75);

	web_submit_form("reservations.pl_4", 
		"Snapshot=t37.inf", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=43", ENDITEM, 
		"Name=Book Another.y", "Value=6", ENDITEM, 
		LAST);

	/* Request with GET method to URL "{WebToursPath}/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "{WebToursPath}/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("T26_ Click_Book Another ",LR_AUTO);

	lr_start_transaction("T27_Search_Flight2");

	web_reg_find("Text=Find Flight", 
		LAST);

	lr_think_time(65);

	web_image("Search Flights Button_2", 
		"Alt=Search Flights Button", 
		"Snapshot=t38.inf", 
		LAST);

	/* Request with GET method to URL "{WebToursPath}/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "{WebToursPath}/WebTours/classes/" failed during recording. Server response : 403*/

	web_reg_find("Text=Flight departing from", LAST);
	lr_think_time(25);
	web_submit_form("reservations.pl_5", 
		"Snapshot=t39.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=04/14/2015", ENDITEM, 
		"Name=arrive", "Value=Portland", ENDITEM, 
		"Name=returnDate", "Value=04/15/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=18", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("T27_Search_Flight2",LR_AUTO);

	lr_start_transaction("T28_ Flight_Lookup2");

	web_reg_find("Text=Payment Details", 
		LAST);

	lr_think_time(49);

	web_submit_form("reservations.pl_6", 
		"Snapshot=t40.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=050;275;04/14/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=64", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("T28_ Flight_Lookup2",LR_AUTO);

	lr_start_transaction("T29_ Payment_Details2");

	web_reg_find("Text=Thank you for booking", 
		LAST);

	lr_think_time(53);

	web_submit_form("reservations.pl_7", 
		"Snapshot=t41.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=whatever", ENDITEM, 
		"Name=lastName", "Value=whatever", ENDITEM, 
		"Name=address1", "Value=whatever", ENDITEM, 
		"Name=address2", "Value=whatever", ENDITEM, 
		"Name=pass1", "Value=whatever whatever", ENDITEM, 
		"Name=creditCard", "Value=12345678", ENDITEM, 
		"Name=expDate", "Value=15/16", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=34", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("T29_ Payment_Details2",LR_AUTO);

	lr_start_transaction("T30_Invoice2");

	lr_end_transaction("T30_Invoice2",LR_AUTO);

	lr_start_transaction("T31_Check_Itinerary");

	web_reg_find("Text=Itinerary", 
		LAST);

	lr_think_time(79);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t42.inf", 
		LAST);

	lr_end_transaction("T31_Check_Itinerary",LR_AUTO);

	lr_think_time(34);

	lr_start_transaction("LogOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t43.inf", 
		LAST);

	return 0;
}