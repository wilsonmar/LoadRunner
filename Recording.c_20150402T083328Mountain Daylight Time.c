// parsec.pl processed this file on 20150402T083328Mountain Daylight Time.
Recording()
{
	// This is a sample file for testing parsec.pl

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	// This should be commented out after parsing:
	// 	web_add_cookie("Something");

	// All lines in this multi-line statement should be commented out:
	// 	web_add_cookie("Something long"
	// 		"and some more"
	// 		"and even more");

	lr_think_time( floatThinkTime ); // TODO: substitute so number remains, and only once.
	lr_think_time( floatThinkTime ); // TODO: substitute so number remains, and only once.

	// During parsing this should be converted to two lines: lr_save_string("url","pTransName");
	// and wi_start_transaction("url"); 
	lr_save_string("url","pTransName");
	wi_start_transaction(); // in wi_functions.c

	web_url("signon.html", 
		"URL=https://paqa1.daytonastate.edu/PAQA1/signon.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	// This should be converted to wi_end_transaction(); during parsing:
	wi_end_transaction(); // in wi_functions.c

	return 0;
}
