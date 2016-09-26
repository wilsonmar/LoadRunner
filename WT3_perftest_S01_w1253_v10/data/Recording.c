Recording()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	lr_think_time(6);

	web_submit_form("login.pl", 
		"Snapshot=t79.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t80.inf", 
		LAST);

	lr_think_time(20);

	web_submit_form("reservations.pl", 
		"Snapshot=t81.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=08/02/2015", ENDITEM, 
		"Name=arrive", "Value=Frankfurt", ENDITEM, 
		"Name=returnDate", "Value=08/03/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	lr_think_time(6);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t82.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=010;386;08/02/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=43", ENDITEM, 
		"Name=reserveFlights.y", "Value=12", ENDITEM, 
		LAST);

	web_image("Search Flights Button_2", 
		"Alt=Search Flights Button", 
		"Snapshot=t83.inf", 
		LAST);

	lr_think_time(8);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t84.inf", 
		ITEMDATA, 
		"Name=depart", "Value=London", ENDITEM, 
		"Name=departDate", "Value=08/02/2015", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=08/03/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_4", 
		"Snapshot=t85.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=230;773;08/02/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=58", ENDITEM, 
		"Name=reserveFlights.y", "Value=8", ENDITEM, 
		LAST);

	web_image("Search Flights Button_3", 
		"Alt=Search Flights Button", 
		"Snapshot=t86.inf", 
		LAST);

	lr_think_time(8);

	web_submit_form("reservations.pl_5", 
		"Snapshot=t87.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Paris", ENDITEM, 
		"Name=departDate", "Value=08/02/2015", ENDITEM, 
		"Name=arrive", "Value=Portland", ENDITEM, 
		"Name=returnDate", "Value=08/03/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_6", 
		"Snapshot=t88.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=450;621;08/02/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=45", ENDITEM, 
		"Name=reserveFlights.y", "Value=5", ENDITEM, 
		LAST);

	web_image("Search Flights Button_4", 
		"Alt=Search Flights Button", 
		"Snapshot=t89.inf", 
		LAST);

	lr_think_time(10);

	web_submit_form("reservations.pl_7", 
		"Snapshot=t90.inf", 
		ITEMDATA, 
		"Name=depart", "Value=San Francisco", ENDITEM, 
		"Name=departDate", "Value=08/02/2015", ENDITEM, 
		"Name=arrive", "Value=Seattle", ENDITEM, 
		"Name=returnDate", "Value=08/03/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_8", 
		"Snapshot=t91.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=670;86;08/02/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=35", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);

	web_image("Search Flights Button_5", 
		"Alt=Search Flights Button", 
		"Snapshot=t92.inf", 
		LAST);

	lr_think_time(8);

	web_submit_form("reservations.pl_9", 
		"Snapshot=t93.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Sydney", ENDITEM, 
		"Name=departDate", "Value=08/02/2015", ENDITEM, 
		"Name=arrive", "Value=Zurich", ENDITEM, 
		"Name=returnDate", "Value=08/03/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_10", 
		"Snapshot=t94.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=890;1073;08/02/2015", ENDITEM, 
		"Name=reserveFlights.x", "Value=50", ENDITEM, 
		"Name=reserveFlights.y", "Value=5", ENDITEM, 
		LAST);

	return 0;
}