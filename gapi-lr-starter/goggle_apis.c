/*
* \file google_apps.c
* \brief Functions to make calls to a Google API web service, the URL Shortener.
*
* Functions defined in this file:
*
*	get_long_url_to_shorten()
*	get_google_short_url()
*		set_oauthhelper_dll()
*		get_pJWTAssertion()
*		get_google_access_token()
*		update_shorturl_in_VTS()
*			set_pShortHostKey_from_url(char* strURL)
*		get_google_short_url_qrcode()
*			set_gen_QR_attribute()
*	get_long_url_from_short_url()
*
* This script needs these globals defined at the top of vuser_init file :
	LPCSTR			LPCSTR_URLSource; // 1=local .dat file, 2=VTS, 3=Google spreadsheet online?, 4=MySQL?.
	int				      iURLSource_default = 2;
	int 			      iURLSource_setting;

	// For use by vi_set_pURLtoShorten_file_recs() of local file URLtoShorten.dat:
	long			nURLtoShorten_file_recs; // counter of rows available.
	long			nURLtoShorten_index; // like i.
	int				nURLtoShorten_done; // counter of rows processed.
*/
	
goggle_apis()
{	
	return 0;
}


get_google_short_url(){
    
	// About this call: https://developers.google.com/url-shortener/v1/getting_started
	// Forum on this:   https://groups.google.com/forum/#!forum/google-url-shortener

	int rc=LR_PASS;
	int	bURLtoShorten_success=LR_PASS;

	rc=get_long_url_to_shorten();
	if( rc != LR_PASS ){ return rc; } // No input data to process.
	
	// Define the URL Shortener API Scope to Google:
	lr_save_string("https://www.googleapis.com/auth/urlshortener","pServiceScope");
					// Other Google API FAQ scopes: https://developers.google.com/gdata/faq#AuthScopes

	sprintf(       tempString1, "%s_access", lr_eval_string("{pTransSequence}") );
	lr_save_string(tempString1,"pTransName");
	rc=get_google_access_token();
	if( rc != LR_PASS ){ return rc; } // No input data to process.

	if( stricmp("NoOp",LPCSTR_RunType ) == FOUND ){ // "NoOp" or "NOOP" specified in Run-time Attribute "RunType" or command line option "-RunType".
		wi_startPrintingInfo();
		lr_output_message(">> RunType=\"%s. JWT=%s."
				,LPCSTR_SaveImageYN
				,lr_eval_string("{pJWTAssertion}")
				);
		wi_stopPrinting();
		return LR_PASS;
	}

		// Using parameter file "URLtoShorten.dat" containing parmeter "pURLtoShorten":
		web_reg_save_param_ex("ParamName=pLongURL","LB=\"longUrl\": \"","RB=\"",SEARCH_FILTERS,"Scope=body",LAST);	// the long  URL input to API server.
		web_reg_save_param_ex("ParamName=pShortURL","LB=\"id\": \"","RB=\"",SEARCH_FILTERS,"Scope=body",LAST); 		// the short URL output from server.

		// WARNING: Google does not check if there is a short code already generated for the URL before generating another one (which bit.ly does).
		web_add_header("Authorization", lr_eval_string("Bearer {pAccessToken}"));
	    web_add_header("Content-Type", "application/json");

		// TODO: 18. If you want to, change the transaction name suffix for shortenend url requests.
		sprintf( 	   tempString1, "%s_2shorturl", lr_eval_string("{pTransSequence}") );
		lr_save_string(tempString1,"pTransName");
	    wi_start_transaction();
	    web_custom_request("Shorten",
                       "URL=https://www.googleapis.com/urlshortener/v1/url",
                       "Method=POST",
                       "Body={\"longUrl\": \"{pURLtoShorten}\"}",
                       LAST);    
					// This code is the C equivalent of the Java at https://developers.google.com/api-client-library/java/apis/urlshortener/v1    
		// Google docs say output should look like this:
		//	{
		//		"kind": "urlshortener#url",\n
		//		"id": "http://goo.gl/jQVbkn",\n
		//		"longUrl": "http://www.hp.com/"\n
		//	}

		rc = wi_end_transaction();

		if( rc == LR_PASS ){
			bURLtoShorten_success=LR_PASS;
			nURLtoShorten_done++; // increment.
		}
		
		wi_startPrintingDebug();
	    lr_output_message(">> done=%d LongURL=%s to pShortURL=%s, seconds=%8.2f under %s."
		        ,nURLtoShorten_done 
				,lr_eval_string("{pLongURL}")
				,lr_eval_string("{pShortURL}")
				,floatHttpMilliseconds
				,lr_eval_string("{pRunConditions}")
				);
		wi_stopPrinting();
	
	#ifdef USE_VTS
	update_shorturl_in_VTS();
	#endif // USE_VTS

	#ifdef GEN_QR
	if( bURLtoShorten_success == LR_PASS ){
		// TODO: 19. Customize your own transaction name for calling get_google_short_url_qrcode().
		lr_save_string("get_google_short_url_qrcode","pTransName"); 
		get_google_short_url_qrcode(); // using pShortURL and pImageFilePath, depending on command flag LPCSTR_SaveImageYN.
	}
	#endif // GEN_QR

	return rc;
} // get_google_short_url()

get_long_url_from_short_url(){
	int rc=LR_PASS;
	int i=0;
	
	// FIXME: Re
	
	return rc;
} // get_long_url_from_short_url()

get_long_url_to_shorten(){
	int rc=LR_PASS;
	int i=0;
	
	if( iURLSource_setting == 1 && nURLtoShorten_file_recs > 0 ){
		for( nURLtoShorten_index=1; nURLtoShorten_index < nURLtoShorten_file_recs +1; nURLtoShorten_index++ ){
			// Loop to skip data records marked No for usage.
			// Referencing data in file URLtoShorten.dat:
			if( stricmp( "N", lr_eval_string("{pURL_use}") ) == FOUND ){
				lr_advance_param("pURL_long"); // Increment file one record.
			} // else fall through to use it.
		}
		lr_save_string(lr_eval_string("{pURL_use}"),"pURLtoShorten");

	#ifdef USE_VTS
	}else
	if( iURLSource_setting == 2 ){ // (use VTS)

		// ENHANCEMENT: The alternative to this loop is to use an increment.

		// Scan through the VTS table from top to bottom.
		// If short_url is not blank in VTS table, it's alreadry processed, so skip to next row:
		for( i=1; i <= nVTS_row_count; i++ ){
			rc = vtc_query_column(pvci, "web", i, &outvalue); // retrieve single field from a designated row.
			if( outvalue == NULL || sizeof( outvalue ) <= 0 ){ // there is no longURL, so skip that row;
				wi_startPrintingTrace();
				lr_output_message(">> row %d \"web\" value is blank. Skipping to next row. rc=%d.", i, rc);
				wi_stopPrinting();
			}else{
				rc = vtc_query_column(pvci, "shorturl", i, &shorturl); // retrieve single field from a designated row.
				// FIXME: Why is rc=10111 ?
				if( shorturl == NULL || sizeof( shorturl ) <= 0 ){ // a blank cell, so it needs a shorturl.
					lr_save_string(outvalue,"pURLtoShorten");
					wi_startPrintingTrace();
					lr_output_message(">> row %d \"shorturl\" is needed for \"web\"=%s. rc=%d.", i, lr_eval_string("{pURLtoShorten}"), rc);
					wi_stopPrinting();
					vtc_free(outvalue);
					rc=0; // FIXME: Why need to override rc=10111 again?
					break; // break out of loop for this script to get a shorturl for the web URL in VTS.
				}else{ 
					// there is a shortURL already, so cycle back up to top for another
					// unless this is the last row in the table:
					if( i == nVTS_row_count ){
						wi_startPrintingTrace();
						lr_output_message(">> Last row at %d has a shorturl of \"%s\". So no more to process.", i, shorturl);
						wi_stopPrinting();
						vtc_free(shorturl);
						rc = LR_FAIL;
					}
				}
	   		}
		} // for loop

	#endif // USE_VTS

	// ENHANCEMENT: else option to retrieve from on-line Google spreadsheet, etc.

	}else{
		wi_startPrintingError();
       	lr_output_message(">> iURLSource_setting=%s is invalid.", iURLSource_setting);
		wi_stopPrinting();
		rc=LR_FAIL; // This would be a programming error since editing occurred before this.
	} // if( iURLSource_setting 
	
	return rc;
} // get_long_url_to_shorten()

set_oauthhelper_dll(){ // Called by get_pJWTAssertion() interations:

	int retVal = 0; // used for return from oauth_load_privatekey().

	// *** No need to change the rest of this file:
	
	lr_param_sprintf("pTimeExpire","%d",time(0)); // create initial seed where (now 10-digit) 1379510581 is for Sep. 18, 2013 at 7:24AM MT.
	lr_load_dll("oauthhelper.dll"); // Written by phillip.mayhew@rextencytech.com.
		// TODO: 20. In Run-time Settings > Miscellaneous, set to run as "Process" rather than "Thread".
		// TODO: 21. Specify in vugen.dat file in "C:\Program Files (x86)\HP\LoadRunner\dat" to load DLL globally for use by all Vuser scripts.
			// file mdrv.dat 
			// [HTTP] section 
			// WINNT_DLLS=kernel32.dll,vtclient.dll,user32.dll

		// TODO: 22. If loading from the script’s directory, specify the DLL is listed in the Controller’s Design View -> Details -> More -> Files.
		// If errors are only from Controller, copy the DLL to the same directory on all Load Generator machines.

	// Using values obtained from Google APIs Console for Project X Client ID associated with {GoogleAPIServiceEmail}:
	retVal = oauth_load_privatekey(lr_eval_string("{pServicePrivateKeyFile}"),"notasecret"); // Done only once.
	if( retVal != 0 ){
 		if( retVal == -1 ){
			lr_error_message(">> oauth_load_privatekey Failed to open p12 file, file not found, path incorrect.");
 		}else if( retVal == -2 ){
			lr_error_message(">> oauth_load_privatekey Error reading the PKCS#12 file, file permissions.");
 		}else if( retVal == -3 ){
			lr_error_message(">> oauth_load_privatekey Error parsing the PKCS#12 file, invalid certificate or invalid password.");
 		}else if( retVal == -4 ){
			lr_error_message(">> oauth_load_privatekey Key not set.");
 		}else{
			lr_error_message(">> oauth_load_privatekey retVal=%d.",retVal);
 		}
 	}

	return retVal;
} // set_oauthhelper_dll()


#ifdef USE_VTS
update_shorturl_in_VTS(){
	// Store the shorturl generated into the VTS table so the same value is not generated again.
	
	int rc=LR_PASS;
	
	if( iUpdate_shorturl_in_VTS == 1 ){
		// Operating on the current VTS index:
		rc = vtc_send_if_unique(pvci, "shorturl", lr_eval_string("{pShortURL}"), &status);

		wi_startPrintingTrace();
	    lr_output_message(">> update_shorturl_in_VTS rc=%d pShortURL=%s, rc=%d, status=%d (1=Pass, 0=Fail)."
		        ,nURLtoShorten_done 
				,lr_eval_string("{pShortURL}")
				,rc
				,status
				);
		wi_stopPrinting();
		if( status == 1 ){
			rc=LR_PASS;
		}else{
			rc=LR_FAIL;
		}
	}

    return rc;
} // update_shorturl_in_VTS()
#endif // USE_VTS

get_google_access_token(){
		int rc=LR_PASS;
	char sOut[256]; // used by wi_EncodePlainToURL()

	rc=get_pJWTAssertion(); // into parameter pJWTAssertion used by this function.
	if( rc != LR_PASS ){ return rc; } // No input data to process.

		if( stricmp("Token",LPCSTR_RunType ) == FOUND ){ // "Token" or "TOKEN" specified in Run-time Attribute "RunType" or command line option "-RunType".
			wi_startPrintingTrace();
		    lr_output_message(">> RunType=\"%s\". JWT=%s."
					,LPCSTR_RunType 
					,lr_eval_string("{pJWTAssertion}")
					);
			wi_stopPrinting();
			return LR_PASS;
		}

	    web_add_header("Content-Type","application/x-www-form-urlencoded");
	    web_add_header("X-Frame-Options","deny"); // to protect against drag'n drop clickjacking attacks in older browsers.
	    web_reg_save_param_ex("ParamName=pAccessToken","LB=\"access_token\" : \"","RB=\"",SEARCH_FILTERS,"Scope=body",LAST);

	    // Example: "Body=grant_type=urn%3Aietf%3Aparams%3Aoauth%3Agrant-type%3Ajwt-bearer&assertion={pJWTAssertion}",
	    wi_EncodePlainToOAuth("grant_type=urn:ietf:params:oauth:grant-type:jwt-bearer&assertion=",sOut );
	    lr_save_string(sOut,"pJWTAssertion_request");
			wi_startPrintingTrace();
		    lr_output_message(">> sOut=\"%s\"."
					,lr_eval_string("{pJWTAssertion_request}")
					);
			wi_stopPrinting();
				
		// TODO: 15. If you want to, change the transaction name suffix for access authorization requests.
		sprintf( 	   tempString1, "%s_1access", lr_eval_string("{pTransSequence}") );
		lr_save_string(tempString1,"pTransName");
	    wi_start_transaction();
	    // web_rest("Token",
	    web_custom_request("Token",
                       "URL=https://accounts.google.com/o/oauth2/token",
                       "Method=POST",
                       //"ResType=JSON",
                       "Body={pJWTAssertion_request}{pJWTAssertion}",
                       LAST);
                       // The %3A are urlencoded from colons. (but %2D for the dash causes an "Invalid request" response):
                       // "Body=grant_type=urn:ietf:params:oauth:grant-type:jwt-bearer&assertion={pJWTAssertion}",
                       // 		Common name for "jwt-bearer" is JWT Bearer Token Grant Type Profile for OAuth 2.0
                       // 		Defined at http://tools.ietf.org/html/draft-ietf-oauth-jwt-bearer-04
	    rc = wi_end_transaction();
	    // "Error -27796: Could not resolve address of hot accounts.google.com" is issued if there in no internet connection.
	    // Google API does not issue "error_description" such as "Audience validation failed".

		/* The response should look something like:
		{
  			"access_token" : "1/_5pUwJZs9a545HSeXXXXXuNGITp1XtHhZXXxxyyaacqkbc",
			"token_type" : "Bearer",
			"expires_in" : 3600
		}
		*/
		
    return rc;
} // get_google_access_token()

get_pJWTAssertion(){
	int rc=0;
	char * signature = 0;

	// Before getting here, example: lr_save_string("8525975153@developer.gserviceaccount.com","GoogleAPIServiceEmail");

	// Each vuser gets its own tokens.
	
    // Google will return "Invalid Request' if the current time sent is off more than a just a few seconds from Google's server, so:
	// TODO: 14. Wherever machine this runs on needs to be synced to NTP or time.gov for UTC (GMT) timezone.

    // Google returns "invalid_grant" 400 error response if the previous token has not expired yet.
    // So loop is needed to re-use tokens until its expiration:
    lr_param_sprintf("pTimeNow","%d",time(0)); // where time(0) generates 10-digits.
    if( strcmp( lr_eval_string("{pTimeNow}"), lr_eval_string("{pTimeExpire}")) < 0 ){
    	wi_startPrintingTrace();
    	// Re-use assertion saved for use instead of running get_pJWTAssertion() again now.
		lr_output_message(">> JWT assertion token reuse: pTimeNow=%s, pTimeExpire=%s"
		                  ,lr_eval_string("{pTimeNow}")
		                  ,lr_eval_string("{pTimeExpire}") 
		                 );
    	wi_stopPrinting();
	} else {
    	// First iteration or generated one expired:
	    lr_param_sprintf("pTimeExpire","%d",time(0)+1800); // Google allows up to 3600 (one hour).
    }

	    // The spec this should follow is http://tools.ietf.org/id/draft-jones-json-web-token-08.html#rfc.section.3.1
	    lr_param_sprintf("JWTBody",
	                 "{\"iss\":\"%s\","
	                 "\"scope\":\"%s\","
	                 "\"aud\":\"https://accounts.google.com/o/oauth2/token\","
	                 "\"exp\":%s,\"iat\":%s}",
	                 lr_eval_string("{GoogleAPIServiceEmail}"),
	                 lr_eval_string("{pServiceScope}"),
	                 lr_eval_string("{pTimeExpire}"),
	                 lr_eval_string("{pTimeNow}"));
	                 // "aud" (audit) without back-slashes is: https://accounts.google.com/o/oauth2/token
	                 // "prn" (principal) is not set because it's not applicable for Gmail accounts, only Google Apps accounts granted domain-wide delegation access by an administrator.
					
		// Encode Header dot Claim set:
		lr_param_sprintf("pEncoded","%s.%s",
                     oauth_url_escape(oauth_encode_base64(0,"{\"alg\":\"RS256\",\"typ\":\"JWT\"}")),
                     oauth_url_escape(oauth_encode_base64(0,lr_eval_string("{JWTBody}"))));
   						// "alg:RS256" = algorithm RSA P-256 SHA-256 used by Google APIs
   						// "alg:HS256" = used by Google Wallet and OpenID
   						// "alg:ES256" = algorithm ECDSA P-256 SHA-256 used by Salesforce
						// Microsoft Live Connect API
						
	    signature = (char*)oauth_sign_rsa_sha256( lr_eval_string("{pEncoded}") );
	    lr_param_sprintf("pJWTAssertion","%s.%s",
                     lr_eval_string("{pEncoded}"),
                     oauth_url_escape(signature));
				    // Verify assertion output on-line using https://developers.google.com/commerce/wallet/digital/docs/jwtdecoder
					// 										 https://developers.google.com/wallet/digital/docs/jwtdecoder

		wi_startPrintingTrace();
		lr_output_message(">> JWTBody=%s."
		                 ,lr_eval_string("{JWTBody}")
		                 );
		lr_output_message(">> pEncoded=%s."
		                 ,lr_eval_string("{pEncoded}")
		                 );
		lr_output_message(">> pJWTAssertion=%s."
		                 ,lr_eval_string("{pJWTAssertion}")
		                 );
		lr_output_message(">> signature=%s."
	                     ,signature
		                 );
    	wi_stopPrinting();

   	return rc;
} // get_pJWTAssertion()


set_pShortHostKey_from_url(char* strURL){
	// From URL supplied with the call, extract the pShortHostKey LR parameter string:
	
		token = (char *)strtok( strURL,"/"); // Get the first token before the separator character.
		if(!token) { // blank means separator character not found.
			// move on.
		}else{
			token = (char *)strtok(NULL, "/"); // Get the number after.
			lr_save_string(token,"pShortHostKey");
			token = (char *)strtok(NULL, "/"); // Get the number after.
			lr_save_string(token,"pShortHostKey");
			// lr_output_message(">> token=%s",token);
		}

	return LR_PASS;
} // set_pShortHostKey_from_url()


#ifdef GEN_QR
get_google_short_url_qrcode(){
	int rc=0;
		char            strFileName[256]; // largest size of file.
		char           *szBuf;
		unsigned long   nLength;

	if( stricmp("Y",LPCSTR_SaveImageYN ) == FOUND ){ // Run-time Attribute "SaveImageYN" or command line option "-SaveImageYN"
	   // continue if SaveImageYN was specified with Y
	}else{
		return LR_PASS;
	}

		set_pShortHostKey_from_url( lr_eval_string("{pShortURL}") ); // from get_google_short_url()
			//wi_startPrintingTrace();
			//lr_output_message(">> pShortHostKey=\"%s\"." ,lr_eval_string("{pShortHostKey}") );
			//wi_stopPrinting();

		// For shortened URL http://goo.gl/AC4IW", details are at http://goo.gl/#analytics/goo.gl/AC4IW/all_time
		// {pShortHostKey}=AC4IW in example: URL http://goo.gl/AC4IW.qr redirects to 
		// The QR code impage at http://chart.googleapis.com/chart?cht=qr&chs=100x100&choe=UTF-8&chld=H|0&chl=http://goo.gl/AC4IW
		web_reg_save_param_ex("ParamName=pImage", "LB=\r\n\r\n", "RB=\"",  "Notfound=warning", LAST); // The \r\n\r\n is to begin capture after the two blank lines between HTTP header and body.
		web_reg_save_param_ex("ParamName=pImage_len", "LB=Content-Length: ", "Notfound=warning", "RB=\r\n", LAST);

		sprintf(       tempString1, "%s_3image", lr_eval_string("{pTransSequence}") );
		lr_save_string(tempString1,"pTransName");
	    wi_start_transaction();
	    
    // This URL was obtained from the DNS-level redirect in the HTML header in response to request for .qr, such as:
    // The document has moved <A 
    //        HREF="http://chart.googleapis.com/chart?cht=qr&amp;chs=150x150&amp;choe=UTF-8&amp;chld=H&amp;chl=http://goo.gl/x6wUIS">here</A>.\n
    	// &amp; needs to be coverted to & character in URLs.
    	
		// WARNING: The 150x150 in this URL may change over time as more characters are needed for uniqueness.
		// Previously,  100x100 was being returned:
		//    "URL={pShortURL}.qr",
		web_url("imagefile",
	        "URL=http://chart.googleapis.com/chart?cht=qr&chs=150x150&choe=UTF-8&chld=H&chl={pShortURL}",
	        "Resource=1",
	        "RecContentType=image/png",
	        "Snapshot=t1.inf",
	        LAST);
		// FIXME: File created has black box at bottom.
	
	    rc = wi_end_transaction();

		// strFileName=wi_define_FileName():
		lr_save_datetime("%Y%m%d%H%M%S", DATE_NOW, "pYMDHMS"); // YYMMDDHHMMSS (12 char), no micro seconds
		sprintf(strFileName, "%s%s_%d_T%s_%s_%s.png"
		        ,lr_eval_string("{pImageFilePath}")
				,global_unique_id
				,iActionIterations
				,lr_eval_string("{pYMDHMS}")
		        ,lr_eval_string("{pShortHostKey}")
		        ,lr_eval_string("{pImage_len}")
		       );

		lr_eval_string_ext("{pImage}", strlen("{pImage}"), &szBuf, &nLength, 0, 0, -1);
		// lr_eval_string_ext( in_str, in_len,    pointer out_str, out_len, Reserved for future use. 
		if( nLength <= 0 ){
			lr_error_message(">> No image returned for %s.",strFileName);
		}else{
			if( wi_WriteDataToFile(strFileName, szBuf, nLength) == LR_PASS ){
				wi_startPrintingInfo();
				lr_output_message(">> QRcode_image file created at \"%s\".",strFileName);
				wi_stopPrinting();
			   	// TODO: 23. Remember after runs to clear out the files to an archive filer.
			}else{
				wi_startPrintingError();
				lr_error_message(">>> QRcode_image file NOT created at \"%s\".",strFileName);
				wi_stopPrinting();
			}
		}
	return rc;
} // retrieve_pShortURL_qrcode()
#endif // GEN_QR


#ifdef GEN_QR
int set_gen_QR_attribute(){

	   LPCSTR_SaveImageYN = lr_get_attrib_string("SaveImageYN"); // from run-time settings or command line.
 	if(LPCSTR_SaveImageYN==NULL){
	   LPCSTR_SaveImageYN=SaveImageYN_default; // ="N"; as N=No default.
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"SaveImageYN\" not specified. QR image files NOT generated from short URLs by default. [in vuser_init]"
					,LPCSTR_SaveImageYN 
					);
			wi_stopPrinting();
	}else{
		if( stricmp("Y",LPCSTR_SaveImageYN ) == FOUND ){ // Run-time Attribute "SaveImageYN" or command line option "-SaveImageYN"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"SaveImageYN\"=%s. QR image files generated from short URLs. [in vuser_init]"
					,LPCSTR_SaveImageYN 
					);
			wi_stopPrinting();
		}else{
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"SaveImageYN\"=%s. QR image files NOT generated from short URLs. [in vuser_init]"
					,LPCSTR_SaveImageYN 
					);
			wi_stopPrinting();
		}
	}
	
	return LR_PASS;
} // set_gen_QR_attribute()
#endif // GEN_QR

// END OF FILE //