Rec_Roundtrip_Ticket()
{

	lr_start_transaction("Travel_Search_Flight");

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t121.inf", 
		"Mode=HTML", 
		LAST);

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	/* Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403*/

	lr_end_transaction("Travel_Search_Flight",LR_AUTO);

	lr_start_transaction("Travel_Flight_Lookup");

	web_submit_form("reservations.pl", 
		"Snapshot=t122.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=08/14/2015", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=08/15/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=25", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("Travel_Flight_Lookup",LR_AUTO);

	lr_start_transaction("Travel_Find_Flight");

	web_submit_form("reservations.pl_2", 
		"Snapshot=t123.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=030;251;08/14/2015", ENDITEM, 
		"Name=returnFlight", "Value=300;251;08/15/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=41", ENDITEM, 
		"Name=reserveFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("Travel_Find_Flight",LR_AUTO);

	lr_start_transaction("Travel_Payment_Details");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t124.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=31", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("Travel_Payment_Details",LR_AUTO);

	lr_start_transaction("Travel_Check_Itinerary");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t125.inf", 
		LAST);

	lr_end_transaction("Travel_Check_Itinerary",LR_AUTO);

	lr_start_transaction("Travel_Cancel_Itinerary");

	web_submit_form("itinerary.pl", 
		"Snapshot=t126.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=31", ENDITEM, 
		"Name=removeFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("Travel_Cancel_Itinerary",LR_AUTO);

	return 0;
}