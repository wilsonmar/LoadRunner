Recording()
{
	// This is a sample file for testing parsec.pl

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	// After parsec, this should be commented out after parsing:
	web_add_cookie("Something");

	// After parsec, all lines in this multi-line statement should be commented out:
	web_add_cookie("Something long"
		"and some more"
		"and even more");

	// After parsec, this should be converted to lr_think_time( floatThinkTime );
	lr_think_time(28);

	// After parsec, this should be converted to wi_start_transaction(); 
	lr_start_transaction("url");

	// After parsec, a web_reg_find() should be added here:
	web_url("watch.html", 
		"URL=http://www.wilsonmar.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	// After parsec, this should be converted to wi_end_transaction();
	lr_end_transaction("url",LR_AUTO);

	// After parsec, this should not be touched or duplicated:
	web_reg_find("Text=This repository",LAST);

	// After parsec, wi_start_transaction() should be added:
	web_url("signon.html", 
		"URL=http://github.com/wilsonmar/loadrunner", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	// After parsec, wi_end_transaction() should be added.
	
	return 0;
}