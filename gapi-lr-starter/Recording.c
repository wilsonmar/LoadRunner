Recording()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	web_url("l6MS.info", 
		"URL=http://goo.gl/l6MS.info", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("goo.gl", 
		"URL=http://goo.gl/?authed=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://www.google.com/uds/api/visualization/1.0/c87ae63acdbfcaca6f5ce7a34423cfbc/ui+en.css", ENDITEM, 
		"Url=http://www.google.com/uds/api/visualization/1.0/c87ae63acdbfcaca6f5ce7a34423cfbc/format+en,default+en,ui+en,geochart+en,corechart+en.I.js", ENDITEM, 
		"Url=/gwt/7967027EDBA445C608CA3B1F9608C883.cache.png", ENDITEM, 
		"Url=http://www.google.com/images/logos/url_shortener_logo.gif", ENDITEM, 
		"Url=/gwt/13C06F1CF8B6EAE4BBFE06245F2DDBF1.cache.png", ENDITEM, 
		"Url=https://www.gstatic.com/recaptcha/api2/r20150202092117/recaptcha__en.js", ENDITEM, 
		"Url=http://ssl.gstatic.com/gb/js/scm_6d7c1becb4ec17fdbc2dbc497c14b75a.js", ENDITEM, 
		"Url=https://apis.google.com/js/api.js", ENDITEM, 
		"Url=https://apis.google.com/_/scs/apps-static/_/js/k=oz.gapi.en_US.oAjF-LPHIRQ.O/m=gapi_iframes,gapi_iframes_style_common/rt=j/sv=1/d=1/ed=1/am=EQ/rs=AGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ/t=zcms/cb=gapi.loaded_0", ENDITEM, 
		"Url=https://apis.google.com/_/scs/apps-static/_/js/k=oz.gapi.en_US.oAjF-LPHIRQ.O/m=gapi_iframes_style_bubble/exm=gapi_iframes,gapi_iframes_style_common/rt=j/sv=1/d=1/ed=1/am=EQ/rs=AGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ/t=zcms/cb=gapi.loaded_1", ENDITEM, 
		"Url=http://ssl.gstatic.com/s2/oz/images/stars/po/bubblev1/border_3.gif", ENDITEM, 
		"Url=http://ssl.gstatic.com/s2/oz/images/stars/po/bubblev1/bubbleSprite_3.png", ENDITEM, 
		"Url=http://ssl.gstatic.com/s2/oz/images/stars/po/bubblev1/bubbleDropR_3.png", ENDITEM, 
		"Url=http://ssl.gstatic.com/s2/oz/images/stars/po/bubblev1/bubbleDropB_3.png", ENDITEM, 
		"Url=https://ssl.gstatic.com/s2/oz/images/stars/po/bubblev1/spacer.gif", ENDITEM, 
		"Url=https://ssl.gstatic.com/s2/oz/images/stars/po/bubblev1/border_3.gif", ENDITEM, 
		"Url=https://www.google.com/webpagethumbnail?c=41&r=4&s=300&d=http://cnn.com/&a=AIYkKU9UaJDVAB2qu8zKEDSL9wIohHdCSg", ENDITEM, 
		LAST);

	web_submit_data("bgprogram", 
		"Action=http://goo.gl/api/bgprogram", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=http://goo.gl/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=security_token", "Value=", ENDITEM, 
		"Name=ie_document_mode", "Value=10", ENDITEM, 
		LAST);

	web_url("anchor", 
		"URL=https://www.google.com/recaptcha/api2/anchor?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&co=aHR0cDovL2dvby5nbA%3D%3D&hl=en&v=r20150202092117&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://goo.gl/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/js/bg/YSzt6aFlaDOxCZP7s7crcmzyqldYrCzMlbxlcW09vjM.js", "Referer=https://www.google.com/recaptcha/api2/anchor?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&co=aHR0cDovL2dvby5nbA%3D%3D&hl=en&v=r20150202092117&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		"Url=https://www.gstatic.com/recaptcha/api2/logo_48.png", "Referer=https://www.google.com/recaptcha/api2/anchor?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&co=aHR0cDovL2dvby5nbA%3D%3D&hl=en&v=r20150202092117&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		"Url=https://fonts.gstatic.com/s/roboto/v15/RxZJdnzeo3R5zSexge8UUT8E0i7KZn-EPnyo3HZu7kw.woff", "Referer=https://www.google.com/recaptcha/api2/anchor?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&co=aHR0cDovL2dvby5nbA%3D%3D&hl=en&v=r20150202092117&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		"Url=https://fonts.gstatic.com/s/roboto/v15/2UX7WLTfW3W8TclTUvlFyQ.woff", "Referer=https://www.google.com/recaptcha/api2/anchor?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&co=aHR0cDovL2dvby5nbA%3D%3D&hl=en&v=r20150202092117&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		LAST);

	lr_start_transaction("long to short");

	web_url("frame", 
		"URL=https://www.google.com/recaptcha/api2/frame?c=03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://goo.gl/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("reload", 
		"Action=https://www.google.com/recaptcha/api2/reload?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://www.google.com/recaptcha/api2/frame?c=03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ#id=I1_1423849155648"
		"&parent=http%3A%2F%2Fgoo.gl&pfname=&rpctoken=79024433", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=c", "Value=03AHJ_VutNZQJOJl_wW2kcj_tP7LdNudSOedFyRrvehZs3S2aH5TuWJOez7EwwPmuqn-LsJ8LZnfaQgw0HLN758QpN7SB7rXlzQNS8eNdAmvAEZ-VK_nYPFXKsve0SAW_sGmZG9IcQyni-SNnuEwvah-4dI4451X5WGLTgLs1BKdn_cTlmR--TYDdzdv_K1l5WCrfODpf-L3mk_mj0ldldrk1nR1QH5ZyUmIvnzkbYV7vJuWMvpl4nswI", ENDITEM, 
		"Name=reason", "Value=fi", ENDITEM, 
		"Name=fbg", "Value=EL-y6a7uo0fy4Dyk2vEBIPyZj-PmZk09rSHMlRWctpmm3Ti28splzB39mTGJkLWjylGj3uuddlAUeoV3vTje7qKSO-2GOMh4V7fiHleTKcOGn_-eGvT04RREVgU6WGLWZhGsdZTg7sSUvAGgVGj12AyldT2eGVwxCB268pceg2E3RyvEQDmlLNgqhX3t0H0Sl8to0Ln80wMMgWE27zasg1nqtZKvAZuMQOHxESpdzvidXcz0fjHqOEJJFOk1BUGhVao7-bdpedRixCcg03PP55Iy4RU-rTAB4S5boif9Xd-T1RtRZZgNoXObIU9GbshyK9xfOVRZOkImSsdSNfyKSV7tdXU_tLjzQM4gmlwYlJR4hNzkJLgXCJsWzOuMm-CVAerVqRlbzUfuYqzMGjXqdw", ENDITEM, 
		EXTRARES, 
		"Url=payload?c=03AHJ_Vuukp5b1n-l6mB_3B_vDBkvC0z_CoiJFNw-WI2X_O9ZCTUgzdKuFbC8ov0vRqwoim5vdXuxoKGDlrDHsGsx7ndGnyZu4DciUKu-HL0Xsovq456A1nlNaqSHDBB8YLysoxXNrV41u_5MYTChGclkRngUNmIN5Ppi6l0z1tnaT0qmT7WWuaG4yGCwN36Qev1cePxTsnFMyErAa4gtmbqfAJzsCcFaT0SSX74GYl5EgOuHilBH0D2c&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV", "Referer=https://www.google.com/recaptcha/api2/frame?c="
		"03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		"Url=https://www.gstatic.com/recaptcha/api2/refresh.png", "Referer=https://www.google.com/recaptcha/api2/frame?c=03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		"Url=https://www.gstatic.com/recaptcha/api2/info.png", "Referer=https://www.google.com/recaptcha/api2/frame?c=03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		"Url=https://www.gstatic.com/recaptcha/api2/audio.png", "Referer=https://www.google.com/recaptcha/api2/frame?c=03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		"Url=https://www.gstatic.com/recaptcha/api2/image.png", "Referer=https://www.google.com/recaptcha/api2/frame?c=03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", ENDITEM, 
		LAST);

	web_custom_request("userverify", 
		"URL=https://www.google.com/recaptcha/api2/userverify?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.google.com/recaptcha/api2/frame?c=03AHJ_VusEo2vyruIBw_tynq-niGN2pgUySWM0NMDDap4vGfPvgM4S1jb6B0kXmAw3CATbmerOObs5HbyL70xPwuhShr15pdbGYQK7wShwzHarEqe-9mPTX1JQhM-agTpSWGunh5iP8Cqxtgpx-SRH2bfIMob_emLtv4GAuRt3op0DBI8lhgdwgn7KInGnEyJsGCds63G3Nfpe&hl=en&k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&v=r20150202092117&bg="
		"!dHJHUdBpihs-jOZBf4zTutwExMoHAAAA7lcAAAANLwC9DguobJekGAxozk006P0Y7IAtX1zXS4vhdzLYZYN_y2ljtCLI5X0VdD0JJtpyhtHzXa2JM59bPV_ft0Fh98kt00g969O4gYx39hGMrqFSxTgpmP3H0ofwduh88bFfZSpRAwghfNnvkiy_xaB_ClGSquzZC8Mcvq0YfR70f5L8EO_BiF7vv5QpwMwM99ScnwS9LC8hS0w-lCNPp9KuMeUWb9xnyA7yWzYdjZnc6FF9yzDqn9ImVPn8DAuVAycM&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ#id=I1_1423849155648"
		"&parent=http%3A%2F%2Fgoo.gl&pfname=&rpctoken=79024433", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded;charset=utf-8", 
		"Body=c=03AHJ_Vuukp5b1n-l6mB_3B_vDBkvC0z_CoiJFNw-WI2X_O9ZCTUgzdKuFbC8ov0vRqwoim5vdXuxoKGDlrDHsGsx7ndGnyZu4DciUKu-HL0Xsovq456A1nlNaqSHDBB8YLysoxXNrV41u_5MYTChGclkRngUNmIN5Ppi6l0z1tnaT0qmT7WWuaG4yGCwN36Qev1cePxTsnFMyErAa4gtmbqfAJzsCcFaT0SSX74GYl5EgOuHilBH0D2c&response=eyJyZXNwb25zZSI6ImlybGlnIn0%3D&t=6874&ct=6874&bg="
		"!zMpHFeua7sL-DChBYmVRwz9_LP8HAAABCVcAAAAcLwDHlIH1aKtMkO1bq8JFbwzQhAlMfPyeehq-duDDeNFfSqtbdP3OAjFCqRrnnVAN3yvjJYepfl2qqdoncZedQuL0cyTVS_iyPzZT82PdXo1XQYQrv1HsFOVzbrlWMS3oG7mMi3NW921d1piiPYQJykjWm7isz54WAUNbEFhvLyda_iiGrz4KJ0oZaSrELfRcjon_mzXTbQkWf5QZ-j-cEYo8F6jfRZZZsKFVyamSTmj-QYOLYHUBwKVb_B849CNrraS1x6_PL8dgHA", 
		LAST);

	web_custom_request("shorten", 
		"URL=http://goo.gl/api/shorten", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://goo.gl/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"Body=url=http%3A%2F%2Fcnn.com&captcha_challenge=03AHJ_VutTEE88os0LebDK1B0MXgtLFXZ5_BXUhoBPjSan1-hVBtzBQrGbdq3vrXpFw22Mpfo9v6dV62jzQyUex-FSCdBMSbg4Ps_R-wHvmGMT6Sw1HM_Eccn-tEnLlbwKG9I39uxzI7ShUpanMFFUrJxbd_VcucPU778_Yw1fEY4aLUAECAOWnZ9RSsEFSv5ITmUQWkn1lDtkkli0lUGHaDlhVqv7eIzDQsmoVvg_Vh9syQCEiVaVOlSDc9ZIApvKAR8Si1DRvT2CAYpvX9HIyrd3ZxAYCxfLBw&captcha_response="
		"03AHJ_VutTEE88os0LebDK1B0MXgtLFXZ5_BXUhoBPjSan1-hVBtzBQrGbdq3vrXpFw22Mpfo9v6dV62jzQyUex-FSCdBMSbg4Ps_R-wHvmGMT6Sw1HM_Eccn-tEnLlbwKG9I39uxzI7ShUpanMFFUrJxbd_VcucPU778_Yw1fEY4aLUAECAOWnZ9RSsEFSv5ITmUQWkn1lDtkkli0lUGHaDlhVqv7eIzDQsmoVvg_Vh9syQCEiVaVOlSDc9ZIApvKAR8Si1DRvT2CAYpvX9HIyrd3ZxAYCxfLBw&security_token=&typed_url=cnn.com&botguard_response="
		"!8vFCboY50nvQlJpElgnLXlnpfV0CAAAAlFIAAAANKgD6-0sm2Kby6vpRUv9Y_1u_KeWYP6Ljs-HWYL1K2jhLiA-Wk_tOQvoZBp1e13yvrsTS_vovhkjlW4Dy5pt274iKtSQIndcK_Pp4OOxUdTH3iSVKcifa8PeT2zTMGYgEh2GlgDpgDjEx4MFZZyc4HdmZBF_heMn_mGdDt2Ur20WDuENpGImVJxb0WoDxyYi_klCFD_ggE6Ai-um98XQiu8Jf6c_RV-VYLNpxCbnj-GV8Qx1ikxE09IRun4Q7o0pihn7SplvCe7rPpABTWcEv84n1k4QLI4nr_jBRHKppjxQ95Du_nwjBS503ANnWYd4vKn1s6HwVDHjXAaM68A", 
		LAST);

	web_url("anchor_2", 
		"URL=https://www.google.com/recaptcha/api2/anchor?k=6LchOvkSAAAAABtPQPc0LH1A6rqU5WR9CXFssNJV&co=aHR0cDovL2dvby5nbA%3D%3D&hl=en&v=r20150202092117&usegapi=1&jsh=m%3B%2F_%2Fscs%2Fapps-static%2F_%2Fjs%2Fk%3Doz.gapi.en_US.oAjF-LPHIRQ.O%2Fm%3D__features__%2Fam%3DEQ%2Frt%3Dj%2Fd%3D1%2Ft%3Dzcms%2Frs%3DAGLTcCNpM51T3Qub8yuxQB_gPzx8VaZ5DQ", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://goo.gl/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(23);

	web_url("qsml.aspx", 
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

/* Added by Async CodeGen.
ID=LongPoll_0
ScanType = Recording

The following URLs are considered part of this conversation:
	http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US
	http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.i&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US
	http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.in&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US
	http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.info&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US

TODO - The following callbacks have been added to AsyncCallbacks.c.
Add your code to the callback implementations as necessary.
	LongPoll_0_RequestCB
	LongPoll_0_ResponseCB
 */
	web_reg_async_attributes("ID=LongPoll_0", 
		"Pattern=LongPoll", 
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US", 
		"RequestCB=LongPoll_0_RequestCB", 
		"ResponseCB=LongPoll_0_ResponseCB", 
		LAST);

	web_url("qsml.aspx_2", 
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

/* Removed by Async CodeGen.
ID = LongPoll_0
 */
	/*
 web_url("qsml.aspx_3",
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.i&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t12.inf",
		"Mode=HTML",
		LAST); 
	*/

/* Removed by Async CodeGen.
ID = LongPoll_0
 */
	/*
 web_url("qsml.aspx_4",
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.in&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t13.inf",
		"Mode=HTML",
		LAST); 
	*/

/* Removed by Async CodeGen.
ID = LongPoll_0
 */
	/*
 web_url("qsml.aspx_5",
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.info&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t14.inf",
		"Mode=HTML",
		LAST); 
	*/

/* Added by Async CodeGen.
ID = LongPoll_0
 */
	web_stop_async("ID=LongPoll_0", 
		LAST);

	web_url("SR00.info", 
		"URL=http://goo.gl/SR00.info", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("analytics", 
		"Action=http://goo.gl/api/analytics", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=http://goo.gl/#analytics/goo.gl/SR00/all_time", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=url", "Value=http://goo.gl/SR00", ENDITEM, 
		"Name=security_token", "Value=", ENDITEM, 
		EXTRARES, 
		"Url=http://ajax.googleapis.com/ajax/static/modules/gviz/1.0/core/tooltip.css", "Referer=http://goo.gl/#analytics/goo.gl/SR00/all_time", ENDITEM, 
		"Url=http://chart.googleapis.com/chart?cht=qr&chs=100x100&choe=UTF-8&chld=H|0&chl=http://goo.gl/SR00", "Referer=http://goo.gl/#analytics/goo.gl/SR00/all_time", ENDITEM, 
		"Url=http://www.gstatic.com/charts/regioncoder/0/geocodes/countries_en.js", "Referer=http://goo.gl/#analytics/goo.gl/SR00/all_time", ENDITEM, 
		"Url=http://www.gstatic.com/charts/geochart/10/mapfiles/world_COUNTRIES.js", "Referer=http://goo.gl/#analytics/goo.gl/SR00/all_time", ENDITEM, 
		LAST);

	lr_think_time(17);

	lr_start_transaction("short to qr");

	web_url("qsml.aspx_6", 
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

/* Added by Async CodeGen.
ID=LongPoll_1
ScanType = Recording

The following URLs are considered part of this conversation:
	http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US
	http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.q&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US
	http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.qr&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US

TODO - The following callbacks have been added to AsyncCallbacks.c.
Add your code to the callback implementations as necessary.
	LongPoll_1_RequestCB
	LongPoll_1_ResponseCB
 */
	web_reg_async_attributes("ID=LongPoll_1", 
		"Pattern=LongPoll", 
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US", 
		"RequestCB=LongPoll_1_RequestCB", 
		"ResponseCB=LongPoll_1_ResponseCB", 
		LAST);

	web_url("qsml.aspx_7", 
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

/* Removed by Async CodeGen.
ID = LongPoll_1
 */
	/*
 web_url("qsml.aspx_8",
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.q&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t19.inf",
		"Mode=HTML",
		LAST); 
	*/

/* Removed by Async CodeGen.
ID = LongPoll_1
 */
	/*
 web_url("qsml.aspx_9",
		"URL=http://api.bing.com/qsml.aspx?query=http%3A%2F%2Fgoo.gl%2FSR00.qr&maxwidth=32765&rowheight=20&sectionHeight=200&FORM=IE10SS&market=en-US",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t20.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://chart.googleapis.com/chart?cht=qr&chs=150x150&choe=UTF-8&chld=H&chl=http://goo.gl/SR00", ENDITEM,
		"URL=http://chart.googleapis.com/favicon.ico", ENDITEM,
		LAST); 
	*/

/* Added by Async CodeGen.
ID = LongPoll_1
 */
	web_stop_async("ID=LongPoll_1", 
		LAST);

	lr_end_transaction("short to qr",LR_AUTO);

	lr_end_transaction("long to short",LR_AUTO);

	return 0;
}