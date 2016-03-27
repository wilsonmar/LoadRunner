//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Sat Feb 20 13:29:54 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
/*
WT3_T03_URL_Landing
WT3_T04_SignUpNow
WT3_T05_SignUp
WT3_T07_SignIn
WT3_T22_Travel_Search_Flight
WT3_T23_Travel_Flight_Lookup
WT3_T24_Find_Flight
WT3_T25_Travel_Payment_Details
WT3_T33_Travel_Check_Itinerary
WT3_T08_SignOut
*/

function Action()
{
	lr.startTransaction('WT3_T03_URL_Landing');
	
/*Correlation comment - Do not change!  Original value='117838.93236128zAzVDtApAiDDDDDDDzDzipAtAf' Name ='userSession' Type ='ResponseBased'*/
	web.regSaveParamEx(
		{
			paramName : 'userSession', 
			lb : 'name=\"userSession\" value=\"', 
			rb : '\"/>\n<table border', 
			scope : 'Body', 
			ignoreRedirections : 'No', 
			requestUrl : '*/nav.pl*'
		}
	);

	web.regFind(
		{
			text : 'Web Tours', 
			search : 'Body'
		}
	);

	web.url(
		{
			name : 'index.htm', 
			url : '{pProtocolHostPort}/WebTours/index.htm', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : '', 
			snapshot : 't1.inf', 
			mode : 'HTML'
		}
	);
	
	lr.endTransaction('WT3_T03_URL_Landing', lr.AUTO);

//	web.setSocketsOption('SSL_VERSION', 'TLS1.1');

	//  Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404
	
		
	lr.thinkTime(54);
// ----->>>>

	lr.startTransaction('WT3_T04_SignUpNow');

	web.url(
		{
			name : 'login.pl', 
			url : 'http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true',			
			resource : 0, 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/WebTours/home.html', 
			snapshot : 't10.inf', 
			mode : 'HTML'
		}
	);

	lr.endTransaction('WT3_T04_SignUpNow', lr.AUTO);

	lr.startTransaction('WT3_T05_SignUp');

	lr.thinkTime(83);
	web.submitForm(
		{
			name : 'login.pl_2', 
			snapshot : 't11.inf', 
			itemData :  [
				{name : 'username', value : '{UserIds_userid}'},
				{name : 'password', value : '{UserIds_pwd}'},
				{name : 'passwordConfirm', value : '{UserIds_pwd}'},
				{name : 'firstName', value : ''},
				{name : 'lastName', value : ''},
				{name : 'address1', value : ''},
				{name : 'address2', value : ''},
				{name : 'register.x', value : '53'},
				{name : 'register.y', value : '3'}
			]
		}
	);

	lr.endTransaction('WT3_T05_SignUp', lr.AUTO);

//<<<-----
	
	lr.startTransaction('WT3_T07_SignIn');

	web.regFind(
		{
			text : 'Welcome', 
			search : 'Body'
		}
	);
	web.submitData(
		{
			name : 'login.pl', 
			action : '{pProtocolHostPort}/cgi-bin/login.pl', 
			method : 'POST', 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/nav.pl?in=home', 
			snapshot : 't2.inf', 
			mode : 'HTML', 
			itemData : 
				[
					{ name : 'userSession', value : '{userSession}' }, 
					{ name : 'username', value : '{UserIds_userid}' }, 
					{ name : 'password', value : '{UserIds_pwd}' }, 
					{ name : 'JSFormSubmit', value : 'on' }, 
					{ name : 'login.x', value : '42' }, 
					{ name : 'login.y', value : '8' }
				]
		}
	);

	lr.endTransaction('WT3_T07_SignIn', lr.AUTO);

	lr.thinkTime(36);
	lr.startTransaction('WT3_T22_Travel_Search_Flight');

	web.regFind(
		{
			text : 'Find Flight', 
			search : 'Body'
		}
	);

/*Correlation comment - Do not change!  Original value='02/06/2016' Name ='departDate' Type ='RecordReplay'*/
	web.regSaveParamEx(
		{
			paramName : 'departDate', 
			lb : 'name=\"departDate\" value=\"', 
			rb : '\"', 
			scope : 'Body', 
			requestUrl : '*/reservations.pl*'
		}
	);

/*Correlation comment - Do not change!  Original value='02/07/2016' Name ='returnDate' Type ='RecordReplay'*/
	web.regSaveParamEx(
		{
			paramName : 'returnDate', 
			lb : 'name=\"returnDate\" value=\"', 
			rb : '\"', 
			scope : 'Body', 
			requestUrl : '*/reservations.pl*'
		}
	);

	web.image(
		{
			name : 'Search Flights Button', 
			alt : 'Search Flights Button', 
			snapshot : 't3.inf'
		}
	);

	//  Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403
	//  Request with GET method to URL "http://127.0.0.1:1080/WebTours/classes/" failed during recording. Server response : 403
	lr.endTransaction('WT3_T22_Travel_Search_Flight', lr.AUTO);

	lr.thinkTime(33);
	lr.startTransaction('WT3_T23_Travel_Flight_Lookup');

	web.regFind(
		{
			text : 'Flight departing from', 
			search : 'Body'
		}
	);

/*Correlation comment - Do not change!  Original value='050;275;02/06/2016' Name ='outboundFlight' Type ='ResponseBased'*/
	web.regSaveParamEx(
		{
			paramName : 'outboundFlight', 
			lb : 'name=\"outboundFlight\" value=\"', 
			rb : '\" checked', 
			scope : 'Body', 
			ignoreRedirections : 'No'
		}
	);

	web.submitForm(
		{
			name : 'reservations.pl', 
			snapshot : 't4.inf', 
			itemData : 
				[
					{ name : 'depart', value : '{WT3_Flights_DepartCity}' }, 
					{ name : 'departDate', value : '{departDate}' }, 
					{ name : 'arrive', value : '{WT3_Flights_ArriveCity}' }, 
					{ name : 'returnDate', value : '{returnDate}' }, 
					{ name : 'numPassengers', value : '1' }, 
					{ name : 'roundtrip', value : '<OFF>' }, 
					{ name : 'seatPref', value : 'None' }, 
					{ name : 'seatType', value : 'Coach' }, 
					{ name : 'findFlights.x', value : '56' }, 
					{ name : 'findFlights.y', value : '8' }
				]
		}
	);

	lr.endTransaction('WT3_T23_Travel_Flight_Lookup', lr.AUTO);

	lr.thinkTime(23);
	lr.startTransaction('WT3_T24_Find_Flight');

	web.regFind(
		{
			text : 'Payment Details', 
			search : 'Body'
		}
	);

	web.submitForm(
		{
			name : 'reservations.pl_2', 
			snapshot : 't5.inf', 
			itemData : 
				[
					{ name : 'outboundFlight', value : '{outboundFlight}' }, 
					{ name : 'reserveFlights.x', value : '31' }, 
					{ name : 'reserveFlights.y', value : '9' }
				]
		}
	);

	lr.endTransaction('WT3_T24_Find_Flight', lr.AUTO);

	lr.thinkTime(29);
	lr.startTransaction('WT3_T25_Travel_Payment_Details');

	web.regFind(
		{
			text : 'Invoice', 
			search : 'Body'
		}
	);

	web.submitForm(
		{
			name : 'reservations.pl_3', 
			snapshot : 't6.inf', 
			itemData :  [
				{name : 'firstName', value : 'jojo'},
				{name : 'lastName', value : 'Bean'},
				{name : 'address1', value : ''},
				{name : 'address2', value : ''},
				{name : 'pass1', value : 'jojo Bean'},
				{name : 'creditCard', value : ''},
				{name : 'expDate', value : ''},
				{name : 'saveCC', value : '<OFF>'},
				{name : 'buyFlights.x', value : '64'},
				{name : 'buyFlights.y', value : '11'}
			]
		}
	);

	lr.endTransaction('WT3_T25_Travel_Payment_Details', lr.AUTO);

	lr.thinkTime(27);
	lr.startTransaction('WT3_T33_Travel_Check_Itinerary');

	web.regFind(
		{
			text : 'Itinerary', 
			search : 'Body'
		}
	);

	web.image(
		{
			name : 'Itinerary Button', 
			alt : 'Itinerary Button', 
			ordinal : '1', 
			snapshot : 't7.inf'
		}
	);

	lr.endTransaction('WT3_T33_Travel_Check_Itinerary', lr.AUTO);

	lr.thinkTime(43);
	lr.startTransaction('WT3_T08_SignOut');

	web.regFind(
		{
			text : 'Welcome', 
			search : 'Body'
		}
	);

	web.image(
		{
			name : 'SignOff Button', 
			alt : 'SignOff Button', 
			ordinal : '1', 
			snapshot : 't8.inf'
		}
	);

	lr.endTransaction('WT3_T08_SignOut', lr.AUTO);

	return 0;
}

