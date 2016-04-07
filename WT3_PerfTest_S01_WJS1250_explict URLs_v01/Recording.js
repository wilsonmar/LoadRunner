//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Wed Apr 06 22:20:30 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function Recording()
{
	web.regFind(
		{
			text : 'Web Tours'
		}
	);

	web.url(
		{
			name : 'index.htm', 
			url : 'http://127.0.0.1:1080/WebTours/index.htm', 
			targetFrame : '', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : '', 
			snapshot : 't1.inf', 
			mode : 'HTML'
		}
	);

	//  Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404
	lr.startTransaction('WT3_T03_URL_Landing');

	lr.endTransaction('WT3_T03_URL_Landing', lr.AUTO);

	lr.startTransaction('WT3_T07_SignIn');

//lr.saveString(lr.decrypt('5705d1fe397a0a27'), 'PasswordParameter');

	web.regFind(
		{
			text : 'Welcome, <b>{UserIds_userid}</b>,'
		}
	);

	web.regFind(
		{
			text : 'Itinerary'
		}
	);

	web.regFind(
		{
			text : 'Web Tours'
		}
	);

	lr.thinkTime(116);
	web.submitData(
		{
			name : 'login.pl', 
			action : 'http://127.0.0.1:1080/cgi-bin/login.pl', 
			method : 'POST', 
			targetFrame : 'body', 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/nav.pl?in=home', 
			snapshot : 't2.inf', 
			mode : 'HTML', 
			itemData : 
				[
					{ name : 'userSession', value : '{userSession}' }, 
					{ name : 'username', value : 'jojo' }, 
					{ name : 'password', value : 'bean' }, 
					{ name : 'JSFormSubmit', value : 'off' }, 
					{ name : 'login.x', value : '43' }, 
					{ name : 'login.y', value : '8' }
				]
		}
	);

	lr.endTransaction('WT3_T07_SignIn', lr.AUTO);

	lr.startTransaction('WT3_T22_Travel_Search_Flight');

	web.regFind(
		{
			text : 'Find Flight'
		}
	);

	lr.thinkTime(45);
	web.url(
		{
			name : 'Search Flights Button', 
			url : 'http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search', 
			targetFrame : 'body', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home', 
			snapshot : 't3.inf', 
			mode : 'HTML'
		}
	);

	//  Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403
	//  Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403
	lr.endTransaction('WT3_T22_Travel_Search_Flight', lr.AUTO);

	lr.startTransaction('WT3_T23_Travel_Flight_Lookup');

	web.regFind(
		{
			text : 'Find Flight'
		}
	);

	lr.thinkTime(48);
	web.submitData(
		{
			name : 'reservations.pl', 
			action : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome', 
			snapshot : 't4.inf', 
			mode : 'HTML', 
			itemData :  [
				{name : 'advanceDiscount', value : '0'},
				{name : 'depart', value : '{WT3_Flights_DepartCity}'},
				{name : 'departDate', value : '04/07/2016'},
				{name : 'arrive', value : '{WT3_Flights_ArriveCity}'},
				{name : 'returnDate', value : '04/08/2016'},
				{name : 'numPassengers', value : '1'},
				{name : 'seatPref', value : 'None'},
				{name : 'seatType', value : 'Coach'},
				{name : '.cgifields', value : 'roundtrip'},
				{name : '.cgifields', value : 'seatType'},
				{name : '.cgifields', value : 'seatPref'},
				{name : 'findFlights.x', value : '34'},
				{name : 'findFlights.y', value : '7'}
			]
		}
	);

	lr.endTransaction('WT3_T23_Travel_Flight_Lookup', lr.AUTO);

	lr.startTransaction('WT3_T24_Find_Flight');

	web.regFind(
		{
			text : 'Payment Details'
		}
	);

	lr.thinkTime(39);
	web.submitData(
		{
			name : 'reservations.pl_2', 
			action : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			snapshot : 't5.inf', 
			mode : 'HTML', 
			itemData : 
				[
					{ name : 'outboundFlight', value : '{outboundFlight}' }, 
					{ name : 'numPassengers', value : '1' }, 
					{ name : 'advanceDiscount', value : '0' }, 
					{ name : 'seatType', value : 'Coach' }, 
					{ name : 'seatPref', value : 'None' }, 
					{ name : 'reserveFlights.x', value : '70' }, 
					{ name : 'reserveFlights.y', value : '11' }
				]
		}
	);

	lr.endTransaction('WT3_T24_Find_Flight', lr.AUTO);

	lr.startTransaction('WT3_T25_Travel_Payment_Details');

	web.regFind(
		{
			text : 'Invoice'
		}
	);

	lr.thinkTime(41);
	web.submitData(
		{
			name : 'reservations.pl_3', 
			action : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			snapshot : 't6.inf', 
			mode : 'HTML', 
			itemData : 
				[
					{ name : 'firstName', value : '{UserIds_userid}' }, 
					{ name : 'lastName', value : '{UserIds_pwd}' }, 
					{ name : 'address1', value : '' }, 
					{ name : 'address2', value : '' }, 
					{ name : 'pass1', value : '{UserIds_userid} {UserIds_pwd}' }, 
					{ name : 'creditCard', value : '' }, 
					{ name : 'expDate', value : '' }, 
					{ name : 'oldCCOption', value : '' }, 
					{ name : 'numPassengers', value : '1' }, 
					{ name : 'seatType', value : 'Coach' }, 
					{ name : 'seatPref', value : 'None' }, 
					{ name : 'outboundFlight', value : '{outboundFlight}' }, 
					{ name : 'advanceDiscount', value : '0' }, 
					{ name : 'returnFlight', value : '' }, 
					{ name : 'JSFormSubmit', value : 'off' }, 
					{ name : '.cgifields', value : 'saveCC' }, 
					{ name : 'buyFlights.x', value : '44' }, 
					{ name : 'buyFlights.y', value : '8' }
				]
		}
	);

	lr.endTransaction('WT3_T25_Travel_Payment_Details', lr.AUTO);

	lr.thinkTime(36);
	lr.startTransaction('WT3_T33_Travel_Check_Itinerary');

	web.url(
		{
			name : 'Itinerary Button', 
			url : 'http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary', 
			targetFrame : 'body', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights', 
			snapshot : 't7.inf', 
			mode : 'HTML'
		}
	);

	lr.endTransaction('WT3_T33_Travel_Check_Itinerary', lr.AUTO);

	lr.thinkTime(34);
	lr.startTransaction('WT3_T08_SignOut');

	web.url(
		{
			name : 'SignOff Button', 
			url : 'http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1', 
			targetFrame : 'body', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary', 
			snapshot : 't8.inf', 
			mode : 'HTML'
		}
	);

	lr.endTransaction('WT3_T08_SignOut', lr.AUTO);

	return 0;
}

