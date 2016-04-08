//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Tue Apr 05 13:15:10 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function Recording()
{
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

	web.setSocketsOption('SSL_VERSION', 'TLS1.1');

	lr.saveString(lr.decrypt('57040ebe3a7ccc12'), 'PasswordParameter');

	lr.thinkTime(52);
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
			itemData :  [
				{name : 'userSession', value : '118257.075415148zAicitipDVzzzzzHDztQHpAiQQ'},
				{name : 'username', value : 'jojo'},
				{name : 'password', value : '{PasswordParameter}'},
				{name : 'JSFormSubmit', value : 'off'},
				{name : 'login.x', value : '43'},
				{name : 'login.y', value : '10'}
			]
		}
	);

	lr.thinkTime(5);
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

	lr.thinkTime(13);
	web.url(
		{
			name : 'iecompatviewlist.xml', 
			url : 'https://iecvlist.microsoft.com/IE10/1152921505002013023/iecompatviewlist.xml', 
			targetFrame : '', 
			resource : 0, 
			recContentType : 'text/xml', 
			referer : '', 
			snapshot : 't4.inf', 
			mode : 'HTML', 
			extraRes :  [
				{url : 'https://ieonline.microsoft.com/iedomainsuggestions/ie10/201604/suggestions.en-US', referer : ''}
			]
		}
	);

	lr.thinkTime(15);
	web.submitData(
		{
			name : 'reservations.pl', 
			action : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome', 
			snapshot : 't5.inf', 
			mode : 'HTML', 
			itemData :  [
				{name : 'advanceDiscount', value : '0'},
				{name : 'depart', value : 'Denver'},
				{name : 'departDate', value : '04/06/2016'},
				{name : 'arrive', value : 'Denver'},
				{name : 'returnDate', value : '04/07/2016'},
				{name : 'numPassengers', value : '1'},
				{name : 'seatPref', value : 'None'},
				{name : 'seatType', value : 'Coach'},
				{name : '.cgifields', value : 'roundtrip'},
				{name : '.cgifields', value : 'seatType'},
				{name : '.cgifields', value : 'seatPref'},
				{name : 'findFlights.x', value : '36'},
				{name : 'findFlights.y', value : '10'}
			]
		}
	);

	lr.thinkTime(16);
	web.submitData(
		{
			name : 'reservations.pl_2', 
			action : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			method : 'POST', 
			targetFrame : '', 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/cgi-bin/reservations.pl', 
			snapshot : 't6.inf', 
			mode : 'HTML', 
			itemData :  [
				{name : 'outboundFlight', value : '000;0;04/06/2016'},
				{name : 'numPassengers', value : '1'},
				{name : 'advanceDiscount', value : '0'},
				{name : 'seatType', value : 'Coach'},
				{name : 'seatPref', value : 'None'},
				{name : 'reserveFlights.x', value : '45'},
				{name : 'reserveFlights.y', value : '7'}
			]
		}
	);

	return 0;
}

