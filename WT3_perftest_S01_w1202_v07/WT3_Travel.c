WT3_Travel()
{
	int rc=LR_PASS;
	// call from within	Action.c.

	if( stricmp("All",LPCSTR_UseCase ) == FOUND
	||  stricmp("ChangeProfile",LPCSTR_UseCase ) == FOUND 
    ){
		lr_save_string("WT3_T04_Find_Flight","pTransName");
//		web_reg_find("Text=Flight departing from", "Fail=NotFound", LAST);
		rc=WT3_T21_Travel_Find_Flight();
	}


	if( stricmp("All",LPCSTR_UseCase ) == FOUND
	||  stricmp("Personalize",LPCSTR_UseCase ) == FOUND 
    ){
		lr_save_string("T06_Select_My_Personalizations","pTransName");
//		rc=WT3_T22_Select_My_Personalizations();
	}

	return 0;
}

	
WT3_T21_Travel_Home(){
	int rc=LR_PASS;
	
	wi_start_transaction();
	web_image("Home Button", 
		"Alt=Home Button", 
		"Snapshot=t32.inf", 
		LAST);
	rc=wi_end_transaction();
	return 0;
} //WT3_T21_Travel_Home
	
	
WT3_T22_Travel_Search_Flight(){
	int rc=LR_PASS;
	
	web_reg_find("Text=Find Flight", 
		LAST);
	wi_start_transaction();
	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t33.inf", 
		LAST);
	rc=wi_end_transaction();

	return 0;
} //WT3_T22_Travel_Search_Flight
	
WT3_T23_Travel_Flight_Lookup(){
	int rc=LR_PASS;

	web_reg_find("Text=Flight departing from", 
		LAST);
	wi_start_transaction();
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
	 rc=wi_end_transaction();
	return 0;
} //WT3_T23_Travel_Flight_Lookup
	
	
WT3_T24_Travel_Payment_Details(){
	int rc=LR_PASS;
	web_reg_find("Text=Payment Details", 
		LAST);
	wi_start_transaction();
	web_submit_form("reservations.pl_2", 
		"Snapshot=t35.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=030;251;04/14/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=46", ENDITEM, 
		"Name=reserveFlights.y", "Value=11", ENDITEM, 
		LAST);
	rc=wi_end_transaction();

	wi_start_transaction();
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
	rc=wi_end_transaction();
	return 0;
	} //WT3_T24_Travel_Payment_Details
	
	
WT3_T25_Travel_Invoice(){
	int rc=LR_PASS;
	lr_start_transaction("WT3_T25_Travel_Invoice");

	lr_end_transaction("WT3_T25_Travel_Invoice",LR_AUTO);
	return 0;
	} //WT3_T25_Travel_Invoice
	
WT3_T26_Travel_Click_Book_Another(){
	int rc=LR_PASS;

	web_reg_find("Text=Find Flight", 
		LAST);
	wi_start_transaction();
	web_submit_form("reservations.pl_4", 
		"Snapshot=t37.inf", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=43", ENDITEM, 
		"Name=Book Another.y", "Value=6", ENDITEM, 
		LAST);
	rc=wi_end_transaction();

	return 0;
	} //WT3_T26_Travel_Click_Book_Another
	
WT3_T27_Travel_Search_Flight2(){
	int rc=LR_PASS;

	web_reg_find("Text=Find Flight", 
		LAST);
	wi_start_transaction();
	web_image("Search Flights Button_2", 
		"Alt=Search Flights Button", 
		"Snapshot=t38.inf", 
		LAST);
	rc=wi_end_transaction();

	web_reg_find("Text=Flight departing from", LAST);
	wi_start_transaction();
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
	 rc=wi_end_transaction();
	return 0;
	} //WT3_T27_Travel_Search_Flight2
	
WT3_T28_Travel_Flight_Lookup2(){
	int rc=LR_PASS;
	web_reg_find("Text=Payment Details", 
		LAST);
	wi_start_transaction();
	web_submit_form("reservations.pl_6", 
		"Snapshot=t40.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=050;275;04/14/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=64", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);
	rc=wi_end_transaction();

//	lr_end_transaction("T28_ Flight_Lookup2",LR_AUTO);
	return 0;
} //WT3_T28_Travel_Flight_Lookup2
	
	
WT3_T29_Travel_Payment_Details2(){
	int rc=LR_PASS;

	web_reg_find("Text=Thank you for booking", 
		LAST);
	wi_start_transaction();
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
	rc=wi_end_transaction();
	return 0;
	} //WT3_T29_Travel_Payment_Details2
	
WT3_T30_Travel_Invoice2(){
	int rc=LR_PASS;
	lr_start_transaction("T30_Invoice2");

	lr_end_transaction("T30_Invoice2",LR_AUTO);
	return 0;
} //WT3_T30_Travel_Invoice2
	
	
WT3_T31_Travel_Check_Itinerary(){
	int rc=LR_PASS;
	web_reg_find("Text=Itinerary", 
		LAST);
	wi_start_transaction();
	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t42.inf", 
		LAST);
	rc=wi_end_transaction();

//	lr_end_transaction("T31_Check_Itinerary",LR_AUTO);
	return 0;
}//WT3_T31_Travel_Check_Itinerary	
	
