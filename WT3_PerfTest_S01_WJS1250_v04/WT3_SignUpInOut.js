function WT3_SignUpInOut()
{	
	
// var pCurrentTrans = 'WT3_T03_URL_Landing';
	
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
			text : 'Web Tours', search : 'Body'
		}
	);


// lr.startTransaction(pCurrentTrans);
lr.startTransaction('WT3_T03_URL_Landing');

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
	
//lr.endTransaction({pCurrentTrans}, lr.AUTO);
lr.endTransaction('WT3_T03_URL_Landing', lr.AUTO);
	
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
	

	
	web.regFind(
		{
			text : 'Welcome', search : 'Body'
		}
	);
	
	lr.startTransaction('WT3_T07_SignIn');

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

	lr.outputMessage("----->>>>Welcome ! You are Logged In as " + lr.evalString( "{UserIds_userid}" ));
	
	lr.endTransaction('WT3_T07_SignIn', lr.AUTO);
		

	lr.startTransaction('WT3_T08_SignOut');


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

/*
function testme(){
	lr.outputMessage("----->>>>Welcome ! You are Logged In as " + lr.evalString( "{UserIds_userid}" ));
    return 0;
}
*/