Recording_URL()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t95.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("header.html", 
		"URL=http://127.0.0.1:1080/WebTours/header.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/index.htm", 
		"Snapshot=t96.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/index.htm", 
		"Snapshot=t98.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("hp_logo.png", 
		"URL=http://127.0.0.1:1080/WebTours/images/hp_logo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://127.0.0.1:1080/WebTours/header.html", 
		"Snapshot=t97.inf", 
		LAST);

	web_url("webtours.png", 
		"URL=http://127.0.0.1:1080/WebTours/images/webtours.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://127.0.0.1:1080/WebTours/header.html", 
		"Snapshot=t99.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("home.html", 
		"URL=http://127.0.0.1:1080/WebTours/home.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t100.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t101.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_url("mer_login.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/mer_login.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t102.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	lr_think_time(11);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t103.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userSession", "Value=116556.785257189fQQfDiQpztVzzzzHDfQHcpDDHif", ENDITEM, 
		"Name=username", "Value=jaja12", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=36", ENDITEM, 
		"Name=login.y", "Value=0", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	web_concurrent_start(NULL);

	web_url("nav.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t104.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("login.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t109.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("itinerary.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/itinerary.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t105.inf", 
		LAST);

	web_url("flights.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/flights.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t106.inf", 
		LAST);

	web_url("in_home.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/in_home.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t107.inf", 
		LAST);

	web_url("signoff.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/signoff.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t108.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t110.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("itinerary.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t111.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t112.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("cancelallreservations.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/cancelallreservations.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t113.inf", 
		LAST);

	web_url("cancelreservation.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/cancelreservation.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t114.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("home.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/home.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t115.inf", 
		LAST);

	web_url("in_itinerary.gif", 
		"URL=http://127.0.0.1:1080/WebTours/images/in_itinerary.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t116.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_think_time(19);

	web_submit_data("itinerary.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t117.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-788-jC", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-1557-jC", ENDITEM, 
		"Name=3", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-2327-jC", ENDITEM, 
		"Name=4", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-3096-jC", ENDITEM, 
		"Name=5", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-3865-jC", ENDITEM, 
		"Name=6", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-4634-jC", ENDITEM, 
		"Name=7", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-5403-jC", ENDITEM, 
		"Name=8", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297416-6173-jC", ENDITEM, 
		"Name=removeFlights.x", "Value=53", ENDITEM, 
		"Name=removeFlights.y", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	return 0;
}