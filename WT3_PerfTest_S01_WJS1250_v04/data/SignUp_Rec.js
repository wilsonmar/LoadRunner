//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//" Script Title       : 
//"                      
//" Script Date        : Wed Feb 24 16:10:11 2016
//"                       
//"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

function SignUp_Rec()
{
	web.url(
		{
			name : 'index.htm', 
			url : 'http://127.0.0.1:1080/WebTours/index.htm', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : '', 
			snapshot : 't9.inf', 
			mode : 'HTML'
		}
	);

	//  Request with GET method to URL "http://127.0.0.1:1080/favicon.ico" failed during recording. Server response : 404
	lr.startTransaction('Click_SignUpNow_Link');

	lr.saveString(lr.decrypt('56ce2a43e'), 'PasswordParameter');

	lr.thinkTime(37);
	web.url(
		{
			name : 'login.pl', 
			url : 'http://127.0.0.1:1080/cgi-bin/login.pl?username=&password={PasswordParameter}&getInfo=true', 
			resource : 0, 
			recContentType : 'text/html', 
			referer : 'http://127.0.0.1:1080/WebTours/home.html', 
			snapshot : 't10.inf', 
			mode : 'HTML'
		}
	);

	lr.endTransaction('Click_SignUpNow_Link', lr.AUTO);

	lr.startTransaction('Input_Information');

	lr.saveString(lr.decrypt('56ce2a43fa8ac360'), 'PasswordParameter');

	lr.thinkTime(83);
	web.submitForm(
		{
			name : 'login.pl_2', 
			snapshot : 't11.inf', 
			itemData :  [
				{name : 'username', value : 'test00'},
				{name : 'password', value : '{PasswordParameter}'},
				{name : 'passwordConfirm', value : 'bean'},
				{name : 'firstName', value : ''},
				{name : 'lastName', value : ''},
				{name : 'address1', value : ''},
				{name : 'address2', value : ''},
				{name : 'register.x', value : '53'},
				{name : 'register.y', value : '3'}
			]
		}
	);

	lr.endTransaction('Input_Information', lr.AUTO);

	lr.thinkTime(47);
	lr.startTransaction('Click_Continue');

	web.image(
		{
			name : 'button_next.gif', 
			src : '/WebTours/images/button_next.gif', 
			snapshot : 't12.inf'
		}
	);

	lr.endTransaction('Click_Continue', lr.AUTO);

	lr.thinkTime(21);
	lr.startTransaction('SignOut');

	web.image(
		{
			name : 'SignOff Button', 
			alt : 'SignOff Button', 
			snapshot : 't13.inf'
		}
	);

	lr.endTransaction('SignOut', lr.AUTO);

	return 0;
}

