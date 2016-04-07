//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : This script is prepared for the demo purpose for
                          http://wilsonmar.github.io/javascript-in-loadrunner/ article.
//"                      
//" Script Date        : Wed Apr 06 22:16:48 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function Action()
{
	var rc=0;
	var pEndPoint = 'http://api.search.yahoo.com/NewsSearchService/V1/';
   //var pEndPoint = 'http://127.0.0.1:1080/WebTours/index.htm';
	
	web.regFind(
		{
			text : 'Web Tours', search : 'Body'
		}
	);
	
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

var pCurrentTrans = 'WT3_T03_URL_Landing';
	
	lr.startTransaction(pCurrentTrans);
	
		web.url(
		{
			name : 'index.htm', 
			url : '{pProtocolHostPort}/WebTours/index.htm', 
			targetFrame : '', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : '', 
			snapshot : 't1.inf', 
			mode : 'HTML'
		}
	);

	lr.endTransaction(pCurrentTrans, lr.AUTO);

	web.regFind(
		{
			text : 'Welcome, <b>{UserIds_userid}</b>,', search : 'Body'
		}
	);

var pCurrentTrans = 'WT3_T07_SignIn';

	lr.startTransaction(pCurrentTrans);

	web.submitData(
		{
			name : 'login.pl', 
			action : '{pProtocolHostPort}/cgi-bin/login.pl', 
			method : 'POST', 
			targetFrame : 'body', 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/nav.pl?in=home', 
			snapshot : 't2.inf', 
			mode : 'HTML', 
			itemData : 
				[
					{ name : 'userSession', value : '{userSession}' }, 
					{ name : 'username', value : '{UserIds_userid}' }, 
					{ name : 'password', value : '{UserIds_pwd}' }, 
					{ name : 'JSFormSubmit', value : 'off' }, 
					{ name : 'login.x', value : '43' }, 
					{ name : 'login.y', value : '8' }
				]
		}
	);
	
	lr.outputMessage(">> Logged-in=" + lr.evalString( "{UserIds_userid}" ));

	lr.endTransaction(pCurrentTrans, lr.AUTO);
	

	web.regFind(
		{
			text : 'Find Flight', foundCount : 'departDate_isfound', search : 'Body'
		}
	);

var pCurrentTrans = 'WT3_T22_Travel_Search_Flight';
	
	lr.startTransaction(pCurrentTrans);

	rc=web.url(
		{
			name : 'Search Flights Button', 
			url : '{pProtocolHostPort}/cgi-bin/welcome.pl?page=search', 
			targetFrame : 'body', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/nav.pl?page=menu&in=home', 
			snapshot : 't3.inf', 
			mode : 'HTML'
		}
	);

	
	if( rc != 0 ){
   lr.outputMessage(">> ERROR Logged-in=" + lr.evalString( "{UserIds_userid}" ));
   // Handle error here:
   return rc;  // 
}else{
   lr.outputMessage(">> Logged-in=" + lr.evalString( "{UserIds_userid}" ));
   
}

	lr.endTransaction(pCurrentTrans, lr.AUTO);
	
	web.regFind(
		{
			text : 'Find Flight', search : 'Body'
		}
	);

	web.regSaveParamEx(
		{
			paramName : 'outboundFlight', 
			lb : 'name=\"outboundFlight\" value=\"', 
			rb : '\" checked', 
			scope : 'Body', 
			ignoreRedirections : 'No'
		}
	);

var pCurrentTrans = 'WT3_T23_Travel_Flight_Lookup';
	
	lr.startTransaction(pCurrentTrans);

	web.submitData(
		{
			name : 'reservations.pl', 
			action : '{pProtocolHostPort}/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/reservations.pl?page=welcome', 
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

		lr.endTransaction(pCurrentTrans, lr.AUTO);
	
	web.regFind(
		{
			text : 'Payment Details', search : 'Body'
		}
	);

var pCurrentTrans = 'WT3_T23_Travel_Flight_Lookup';
	
	lr.startTransaction(pCurrentTrans);

	web.submitData(
		{
			name : 'reservations.pl_2', 
			action : '{pProtocolHostPort}/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/reservations.pl', 
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
	
	lr.endTransaction(pCurrentTrans, lr.AUTO);

	web.regFind(
		{
			text : 'Invoice', search : 'Body'
		}
	);
	
var pCurrentTrans = 'WT3_T25_Travel_Payment_Details';
	
	lr.startTransaction(pCurrentTrans);
	
	web.submitData(
		{
			name : 'reservations.pl_3', 
			action : '{pProtocolHostPort}/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/reservations.pl', 
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

	lr.endTransaction(pCurrentTrans, lr.AUTO);

		web.regFind(
		{
			text : 'Itinerary', search : 'Body'
		}
	);

var pCurrentTrans = 'WT3_T33_Travel_Check_Itinerary';
	
	lr.startTransaction(pCurrentTrans);

	web.url(
		{
			name : 'Itinerary Button', 
			url : '{pProtocolHostPort}/cgi-bin/welcome.pl?page=itinerary', 
			targetFrame : 'body', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/nav.pl?page=menu&in=flights', 
			snapshot : 't7.inf', 
			mode : 'HTML'
		}
	);

		lr.endTransaction(pCurrentTrans, lr.AUTO);

		web.regFind(
		{
			text : 'Web Tours', search : 'All'
		}
	);

var pCurrentTrans = 'WT3_T08_SignOut';

	lr.startTransaction(pCurrentTrans);

	web.url(
		{
			name : 'SignOff Button', 
			url : '{pProtocolHostPort}/cgi-bin/welcome.pl?signOff=1', 
			targetFrame : 'body', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : '{pProtocolHostPort}/cgi-bin/nav.pl?page=menu&in=itinerary', 
			snapshot : 't8.inf', 
			mode : 'HTML'
		}
	);
			lr.endTransaction(pCurrentTrans, lr.AUTO);

	return 0;
}

