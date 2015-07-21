Recording()
{

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/WebTours/index.htm", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	web_url("crx", 
		"URL=https://clients2.google.com/service/update2/crx?os=win&arch=x86&nacl_arch=x86-64&prod=chromecrx&prodchannel=stable&prodversion=41.0.2272.118&lang=en-US&x=id%3Dlccekmodgklaepjeofjdjpbminllajkg%26v%3D0.0.0.0%26uc%26ping%3Dr%253D-1%2526e%253D1&x=id%3Daohghmighlieiainnegkcijnfilokake%26v%3D0.9%26uc&x=id%3Dapdfllckaahabafndbhieahigkjlhalf%26v%3D6.4%26uc&x=id%3Dblpcfgokakmgnkcojhhkbfbldkacnbeo%26v%3D4.2.7%26uc&x=id%3Dcoobgpohoikkiipiblmjeljniedjpjpf%26v%3D0.0.0.30%26uc&x="
		"id%3Dnmmhkkegccagdldgiimedpiccmgmieda%26v%3D0.1.0.0%26uc&x=id%3Dpjkljhegncpnkpknbcohdijeoejaedia%26v%3D8.1%26uc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("l", 
		"URL=https://translate.googleapis.com/translate_a/l?client=chrome&cb=sl&hl=en&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw&alpha=1", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/javascript", 
		"Referer=", 
		"Snapshot=t10.inf", 
		LAST);

	web_custom_request("verify", 
		"URL=https://www.googleapis.com/chromewebstore/v1.1/items/verify", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"hash\":\"XW2IOf34vgAdA0AcSyxFNNibaSTfzEngHvxC4265Xv8=\",\"ids\":[\"aohghmighlieiainnegkcijnfilokake\"],\"protocol_version\":1}", 
		LAST);

	web_concurrent_start(NULL);

	web_url("seed", 
		"URL=https://clients4.google.com/chrome-variations/seed?osname=win", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t12.inf", 
		LAST);

	web_url("extension_0_3_0_2.crx", 
		"URL=http://cache.pack.google.com/crx/blobs/QgAAAC6zw0qH2DJtnXe8Z7rUJP05vsW-JrZVDRtyfQ0AGQs50EtkpH76PugAfZ_lV8loYXLGFrEgcPBL6raBXrMzFV5h5rBsL3g82oNNr1-2p7GlAMZSmuWiaL0RH1GdT0n813pTaF48FxqHcg/extension_0_3_0_2.crx", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/x-chrome-extension", 
		"Referer=", 
		"Snapshot=t13.inf", 
		LAST);

	web_url("client_model_v5.pb", 
		"URL=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5.pb", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t14.inf", 
		LAST);

	web_url("searchdomaincheck", 
		"URL=https://www.google.com/searchdomaincheck?format=url&type=chrome", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t15.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_think_time(42);

	web_url("login.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("query", 
		"URL=https://clients1.google.com/tbproxy/af/query?client=Google%20Chrome", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=text/plain", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><autofillquery clientversion=\"6.1.1715.1442/en (GGLL)\"><form signature=\"12525329521802119436\"><field signature=\"239111655\"/><field signature=\"2051817934\"/><field signature=\"2273916472\"/><field signature=\"1855613035\"/><field signature=\"4163345999\"/><field signature=\"2267517795\"/><field signature=\"1236818338\"/></form></autofillquery>", 
		LAST);

	lr_think_time(12);

	web_url("plugins_win.json", 
		"URL=https://www.gstatic.com/chrome/config/plugins_2/plugins_win.json", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t18.inf", 
		LAST);

	lr_think_time(13);

	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=jojo1", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=passwordConfirm", "Value=bean", ENDITEM, 
		"Name=firstName", "Value=whatever", ENDITEM, 
		"Name=lastName", "Value=whatever", ENDITEM, 
		"Name=address1", "Value=whatever", ENDITEM, 
		"Name=address2", "Value=whatever", ENDITEM, 
		"Name=register.x", "Value=53", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(96);

	lr_start_transaction("continue");

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("PREF=ID=cb22963409466525:TM=1407152021:LM=1423701561:S=pXj_qE_4NQ4gzCTB; DOMAIN=safebrowsing.google.com");

	lr_think_time(5);

	web_custom_request("downloads", 
		"URL=https://safebrowsing.google.com/safebrowsing/downloads?client=googlechrome&appver=41.0.2272.118&pver=3.0&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/vnd.google.safebrowsing-update", 
		"Referer=", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=text/plain", 
		"Body=goog-malware-shavar;a:161966-181957:s:152685-154217,154219-154260,154262-155415,155417-155781,155783-157480,157482-157836,157838-159256,159258-173438\ngoog-phish-shavar;a:376140-385545:s:205032-205482,205484-210689,210691-211187,211189-211461\ngoog-badbinurl-shavar;a:30166-56337:s:35190-35501,35503,35505-35512,35515-35516,35518-35539,35541,35543,35548,35550,35552,35554-35566,35568-35577,35579,35583-35602,35604-35605,35608-35618,35620,35622,35624,35627-35670,35673-35674,35676-35698,35703-35707"
		",35709-35716,35718-35720,35722-35725,35727-35737,35739-35745,35747-35752,35754,35756-35759,35761-35766,35768-35774,35776,35781-35782,35784-35799,35801-35806,35808,35810-35811,35813-35821,35823-35828,35831-35887,35889-35894,35896-35909,35911-35914,35916-35923,35925-35926,35928,35930,35933-35960,35962-35989,35991-36005,36007-36165,36167-36199,36201-40479,40481-40978,40981-40982,40984-41032,41034-41048,41050-41066,41068-41102,41104-41111,41113-41114,41116-41124,41126,41128-41129,41131-41185,"
		"41187-41193,41195-41207,41209-41211,41213-41219,41221-41232,41234,41236-41257,41259-41281,41283-41300,41302-41314,41316-41323,41325-41340,41342-41360,41362-41405,41407,41409-41422,41424-41509,41511-41647,41649-41750,41752-44894,44896-47516\ngoog-csdwhite-sha256;a:3-59:s:1-5\ngoog-downloadwhite-digest256;a:5-53:s:2-46\ngoog-badcrxids-digestvar;a:2-433:s:1-16\ngoog-badip-digest256;a:2289-2307:s:1755-1760,1762-1767\ngoog-unwanted-shavar;a:1-13915:s:1-7169\n", 
		LAST);

	lr_end_transaction("continue",LR_AUTO);

	web_add_cookie("PREF=ID=cb22963409466525:TM=1407152021:LM=1423701561:S=pXj_qE_4NQ4gzCTB; DOMAIN=safebrowsing-cache.google.com");

	web_concurrent_start(NULL);

	web_url("ChVnb29nLWJhZGJpbnVybC1zaGF2YXI4AUACSgwIABCSuAMYlrgDIAE", 
		"URL=https://safebrowsing-cache.google.com/safebrowsing/rd/ChVnb29nLWJhZGJpbnVybC1zaGF2YXI4AUACSgwIABCSuAMYlrgDIAE", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/vnd.google.safebrowsing-chunk", 
		"Referer=", 
		"Snapshot=t22.inf", 
		LAST);

	web_url("ChNnb29nLW1hbHdhcmUtc2hhdmFyOAFAAkoMCAEQ_8oKGIPLCiABSgwIABDGjQsYyo0LIAE", 
		"URL=https://safebrowsing-cache.google.com/safebrowsing/rd/ChNnb29nLW1hbHdhcmUtc2hhdmFyOAFAAkoMCAEQ_8oKGIPLCiABSgwIABDGjQsYyo0LIAE", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/vnd.google.safebrowsing-chunk", 
		"Referer=", 
		"Snapshot=t23.inf", 
		LAST);

	web_url("ChFnb29nLXBoaXNoLXNoYXZhcjgBQAJKDAgBEIb0DBiI9AwgAUoMCAAQisQXGI3EFyAB", 
		"URL=https://safebrowsing-cache.google.com/safebrowsing/rd/ChFnb29nLXBoaXNoLXNoYXZhcjgBQAJKDAgBEIb0DBiI9AwgAUoMCAAQisQXGI3EFyAB", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/vnd.google.safebrowsing-chunk", 
		"Referer=", 
		"Snapshot=t24.inf", 
		LAST);

	web_url("ChRnb29nLXVud2FudGVkLXNoYXZhcjgBQAJKCggAENxsGN5sIAE", 
		"URL=https://safebrowsing-cache.google.com/safebrowsing/rd/ChRnb29nLXVud2FudGVkLXNoYXZhcjgBQAJKCggAENxsGN5sIAE", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/vnd.google.safebrowsing-chunk", 
		"Referer=", 
		"Snapshot=t25.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_think_time(35);

	lr_start_transaction("signoff");

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}