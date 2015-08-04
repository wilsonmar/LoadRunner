/*! 
\file wi_functions.c
\brief Contains functions to enhance capability that can be used by other LoadRunner scripts.
       These are designed so they should not need to be changed for a specific organization or system.
       
	// int wi_set_unique_id(){
	// int wi_set_timezone(){
	// int wi_load_kernel32_dll(){
	// int wi_get_vuser_pid(){
	// wi_save_request_header();
	// wi_show_user_agent(){

	// int wi_set_Think_Time(){

	// wi_set_Customer_attribute(){
	// wi_set_RunType_attribute(){
	// wi_set_URLSource_attribute(){

	// wi_start_transaction(){
	// wi_end_transaction(){
	// wi_retry_add_time( i ){

	// wi_setPrinting(){
	// wi_startPrintingError(){
	// wi_startPrintingInfo(){
	// wi_startPrintingDebug(){
	// wi_startPrintingTrace(){
	// wi_resetPrinting(){

	// wi_EncodePlainToOAuth(const char *sIn, char *sOut){
	// wi_EncodePlainToURL(const char *sIn, char *sOut){

	// int wi_WriteDataToFile(char *szFileName, const char *szBuf, int len){
	// int wi_set_Verbosity_attribute(){

	// int wi_set_pURLtoShorten_file_recs(){
	// int wi_set_VTS3(){


*/

wi_functions()
{
	return 0;
}


/****** Utility functions that are same for all scripts: ******/

int wi_set_unique_id(){
	int rc=LR_PASS;
	char*			my_controller_name;
	char*			my_host; // host_name of load generator (injector):
	int 			iScenarioID;
	char* 			vuser_group;
	int 			iVuserID; // -1 if run in VuGen.
	char* 			sVuserID[32]; // from lr_get_vuser_ip()
//	char 			my_unique_id[64]=""; // defined as global variable.
	int              vuser_pid=0; // Windows Process ID
	
	my_controller_name = lr_get_master_host_name(); 
	my_host = lr_get_host_name();
	vuser_pid = wi_get_vuser_pid();

	lr_whoami(&iVuserID, &vuser_group, &iScenarioID); // lr_whoami returns void by design (no rc).

	// NOTE: When run in VuGen: Controller=None, host=%MACHINENAME%, ScenarioID=0, vuser_group=None, iVuserID=-1.
  	wi_startPrintingInfo();
	lr_output_message(">> Controller=%s, Host=%s, ScenarioID=%d, Group=%s, Vuser=%d, PID=%d." 
  	                  ,my_controller_name ,my_host ,iScenarioID, vuser_group ,iVuserID, vuser_pid );
	wi_resetPrinting();
	
	sprintf( global_unique_id,"C%s.H%d.S%s.G%s.U%d.P%d"
			,my_controller_name
			,my_host
			,iScenarioID
			,vuser_group
			,iVuserID
			,vuser_pid
			);	
	lr_save_string(global_unique_id,"global_unique_id");

	return rc;
} // wi_set_unique_id


/// Specified during debugging to Toggle Breakpoint on a function (not if statement):
wi_noop(){
	return 0;
}


wi_load_kernel32_dll(){
	int rc=LR_PASS;
    static int is_kernel32_dll_loaded = FALSE; // A static C variable inside a function retains its value between invocations.
                                 // The FALSE value is assigned only on the first invocation.

	#ifdef  USING_WINDOWS

	char* dll_name = "KERNEL32.DLL"; // In C:/Windows/System32 that comes with Windows.
			// Its File Description: "Windows NT BASE API Client DLL".

	if (is_kernel32_dll_loaded == FALSE) {
        rc = lr_load_dll(dll_name);
        if (rc == 0) {
			is_kernel32_dll_loaded = TRUE;
        }else{
			is_kernel32_dll_loaded = FALSE;
            lr_error_message(">> Error loading %s.", dll_name);
            // lr_abort();
        }
    }

	#endif // USING_WINDOWS

	return rc;
}

/**
 * Gets the process ID of the mmdrv.exe process running the VuGen script calling this function.
 *
 * @return    This function returns the process ID of the calling process.
 *
 * Example code:
 *     // Print the vuser's process ID
 *     int vuser_pid; vuser_pid = wi_get_vuser_pid();
 *     lr_output_message("vuser_pid: %d", vuser_pid);
 *
 * Note: This function only works on Windows.
 * From lr-libc.
 */
int wi_get_vuser_pid() {
    int rc=LR_PASS; // return code
    int pid=0; // the process id (usually 4 digits)
    static int is_msvcrt_dll_loaded = FALSE; // A static variable inside a function keeps its value between
                                   // invocations. The FALSE value is assigned only on the first
                                   // invocation.
    char* dll_name = "MSVCRT.DLL"; // This DLL contains the _getpid() function. It is a standard
                                   // Windows DLL, usually found in C:\WINDOWS\system32.
                                   // On Windows platforms, if a path is not specified,
                                   // lr_load_dll searches for the DLL using the standard sequence.

 	#ifdef  USING_WINDOWS

    // Only load the DLL the first time this function is called:
    if (is_msvcrt_dll_loaded == FALSE) {
        rc = lr_load_dll(dll_name);
        if (rc == 0) {
	        is_msvcrt_dll_loaded = TRUE;
		    pid = _getpid();
        }else{
	        is_msvcrt_dll_loaded = FALSE;
		    lr_error_message(">> Error loading %s to get WIN32 pid in wi_get_vuser_pid.", dll_name);
            // lr_abort();
        }
    }

	#endif // USING_WINDOWS

	return pid;
} // wi_get_vuser_pid



int wi_set_Think_Time(){
	char strTemp[48]; double doubleTemp;
	LPCSTR			  LPCSTR_ThinkTimeSecs;
	float			   floatThinkTimeSecs_default = 10.5;
 	// For use by wi_set_Think_Time() & wi_start_transaction():
	// float	floatThinkTimeSecs; // numeric.
					
  		 LPCSTR_ThinkTimeSecs = lr_get_attrib_string("ThinkTimeSecs");
	if(  LPCSTR_ThinkTimeSecs==NULL){ // Not specified.
	  	   floatThinkTimeSecs=floatThinkTimeSecs_default; // Default unless changed for subsequent transactions.

  	    wi_startPrintingDebug();
		lr_output_message(">> floatThinkTimeSecs=%8.2f from coded default.", floatThinkTimeSecs);
		wi_resetPrinting();
	}else{ // use value from command attribute: // floats have 24 significant bits, double 52.
		// Not using strtof() per http://pubs.opengroup.org/onlinepubs/009695399/functions/strtod.html
	    floatThinkTimeSecs= atof(LPCSTR_ThinkTimeSecs); // atof() requires definition at top of file.

	    wi_startPrintingDebug();
		lr_output_message(">> Attribute floatThinkTimeSecs=%8.3f.", floatThinkTimeSecs );
		wi_resetPrinting();
	 } // For ftoa see http://www.performancecompetence.com/wordpress/?p=318
	return LR_PASS;
} // wi_set_Think_Time()
	

wi_retry_add_time( int in_retries ){
	int rc=LR_PASS;
	int milliseconds;
	
	if( in_retries <= 0 ){
		return LR_PASS;
	}else{
		// Since lr_think_time is already used:
		// This is a cross-platforam approach to
		// TODO: Calculate geometrically more time with each successive retry:
		milliseconds = in_retries * 1000; // for now.

		#ifdef USING_WINDOWS
		if (is_kernel32_dll_loaded == FALSE) {
			rc=wi_load_kernel32_dll(); // unresolved symbol error will occur unless library is loaded.
			if( rc == LR_PASS ){
				Sleep(milliseconds); 				
			}
		}
		// TODO: Test sleep in Linux environment
		#elif _POSIX_C_SOURCE >= 199309L
		    struct timespec ts;
		    ts.tv_sec = milliseconds / 1000;
		    ts.tv_nsec = (milliseconds % 1000) * 1000000;
			// nanosleep() function is not supposed to effect the action or blockage of any signal.
		    nanosleep(&ts, NULL);
		#else
		    // Deprecated now:
		    usleep(milliseconds * 1000); // uses the useconds_t structure
		#endif

		return LR_PASS;
	}
}

void wi_sleep_ms(int milliseconds) // cross-platform sleep function
{
	// makes use of global data structures defined in vuser_init.c
#ifdef USING_WINDOWS
//	Debugging:
//	Sleep(milliseconds); // unresolved symbol error will occur unless library is included.
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
	// nanosleep() function is not supposed to effect the action or blockage of any signal.
    nanosleep(&ts, NULL);
#else
    // Deprecated now:
    usleep(milliseconds * 1000); // uses the useconds_t structure
#endif // USING_WINDOWS
}

wi_save_request_header(){
	
	web_save_header(REQUEST,"request_header");
	 
	return 0;
}

wi_show_user_agent(){
	// This makes use of the request_header captured by this invoked before a call:
	//    web_save_header(REQUEST,"request_header");
	// Which only needs to be done once if the client Agent String does not change during a run.
	
	char * headers = lr_eval_string("{request_header}");
 
 	lr_save_param_regexp(headers,
        strlen(headers),
   		"RegExp=User-Agent: (.+)\\r\\n",
   		"ResultParam=userAgent",
   		LAST );

	// {userAgent} is one of the run conditions shown one time for whole run:
		wi_startPrintingInfo();
 	lr_output_message(">> {userAgent}=%s.", lr_eval_string("{userAgent}"));
	// TODO: Intrepret raw agent string to summarize the browser name and version.
		wi_resetPrinting();

	return 0;
}
wi_start_transaction(){
	static float	floatThinkTimeSecs; // defined in wi_set_Think_Time().

	// lr_save_string( strTransName,"pTransName" ); // defined in Action().
	lr_start_transaction(lr_eval_string("{pTransName}"));
	
	// lr_get_transaction_duration(lr_eval_string("{pTransName}"));
	// web_reg_save_param_ex("ParamName=pJSONResponse","LB={","RB=}", "Notfound=warning", LAST); // captures JSON

	lr_think_time( floatThinkTimeSecs );
		
    return LR_PASS;
} // wi_start_transaction

int wi_end_transaction(){
	int rc=LR_PASS;
	int 			  intHttpRetCode;
	int 			  intHttpMilliseconds;
	float 			floatHttpMilliseconds;
	int 			  intHttpSize;
	float 			floatHttpKBytes;

	
	/* Defined as globals at top of vuser_init():
	int 			  intHttpRetCode;
	int 			  intHttpMilliseconds;
	float 			floatHttpMilliseconds;
	int 			  intHttpSize;
	float 			floatHttpKBytes;
	*/

	rc = lr_get_transaction_status( lr_eval_string("{pTransName}") );
	// Using pTransName saved in wi_start_transaction before the transaction:
	if( rc == LR_FAIL ){
		lr_end_transaction(lr_eval_string("{pTransName}"),LR_FAIL);
    	wi_startPrintingError();
    	lr_error_message(">> Iteration=%d User=\"%s\" Trans=%s FAIL ERROR." 
		                  ,iActionIterations
		                  ,lr_eval_string("{parmLoginUserID}")
		                  ,lr_eval_string("{pTransName}")
		                 );
		wi_resetPrinting();
	}else{
		lr_end_transaction(lr_eval_string("{pTransName}"),LR_AUTO);		
	}

    // Verify bad 400 HTTP return code from server and associated response such as "{error : invalid_grant}"
    // using LoadRunner internal function web_get_int_property():
	    intHttpRetCode 		= web_get_int_property(HTTP_INFO_RETURN_CODE);
  	    intHttpSize 		= web_get_int_property(HTTP_INFO_DOWNLOAD_SIZE);
	    intHttpMilliseconds = web_get_int_property(HTTP_INFO_DOWNLOAD_TIME);
	  floatHttpMilliseconds = (float)intHttpMilliseconds / 1000; // Convert from milliseconds to seconds.

	if (intHttpRetCode == 200 // no problem! OK
	||  intHttpRetCode == 304 // Already cached.
	){
		// move on.
	}else{
		wi_startPrintingError();
    	lr_output_message(">> Iteration=%d User=\"%s\" HTML Return Code=%d." 
		                  ,iActionIterations
		                  ,lr_eval_string("{parmLoginUserID}")
		                 , intHttpRetCode
		                ); // QUESTION: What does rc -1 mean?
		wi_resetPrinting();
		rc=LR_FAIL;
	}

    return rc;
} // wi_end_transaction

		
wi_setPrinting(){
	
	if( iVerbosity >= 1 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
	}else
	if( iVerbosity >= 2 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
	}else
	if( iVerbosity >= 3 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
		// No LR_MSG_CLASS_PARAMETERS because
	}else
	if( iVerbosity >= 4 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
		lr_set_debug_message( LR_MSG_CLASS_RESULT_DATA, LR_SWITCH_ON );
		lr_set_debug_message( LR_MSG_CLASS_FULL_TRACE , LR_SWITCH_ON ); 
		// No LR_MSG_CLASS_PARAMETERS because
	}else
	if( iVerbosity >= 5 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_EXTENDED_LOG, LR_SWITCH_ON ); // (16) Extended logging.
		lr_set_debug_message( LR_MSG_CLASS_RESULT_DATA, LR_SWITCH_ON );
	}

	return 0;
} // wi_setPrinting

wi_startPrintingError(){

		lr_set_debug_message( 542 , LR_SWITCH_OFF ); // to unset all selections.
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_ON ); // LR_SWITCH_ON (=1) means suppress output.
	if( iVerbosity >= 1 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
	}
	return LR_PASS;
}
wi_startPrintingInfo(){

		lr_set_debug_message( 542 , LR_SWITCH_OFF ); // to unset all selections.
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_ON ); // LR_SWITCH_ON (=1) means suppress output.
	if( iVerbosity >= 2 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
	}
	return LR_PASS;
}
wi_startPrintingDebug(){

		lr_set_debug_message( 542 , LR_SWITCH_OFF ); // to unset all selections.
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_ON ); // LR_SWITCH_ON (=1) means suppress output.
	if( iVerbosity >= 3 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
		// No LR_MSG_CLASS_PARAMETERS because
	}
	return LR_PASS;
}

wi_startPrintingTrace(){

		lr_set_debug_message( 542 , LR_SWITCH_OFF ); // to unset all selections.
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_ON ); // LR_SWITCH_ON (=1) means suppress output.
	if( iVerbosity >= 4 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_BRIEF_LOG  , LR_SWITCH_ON ); // (1) (Standard) logging.
		lr_set_debug_message( LR_MSG_CLASS_RESULT_DATA, LR_SWITCH_ON );
		lr_set_debug_message( LR_MSG_CLASS_FULL_TRACE , LR_SWITCH_ON ); 
		// No LR_MSG_CLASS_PARAMETERS because
	}
	if( iVerbosity >= 5 ){
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF ); // LR_SWITCH_OFF (=0) means stop suppressing output.
		lr_set_debug_message( LR_MSG_CLASS_EXTENDED_LOG, LR_SWITCH_ON ); // (16) Extended logging.
	}
	return LR_PASS;
}

wi_resetPrinting(){

	lr_set_debug_message( 542 , LR_SWITCH_OFF ); // to unset all selections.
	// Using bit-wise compare. See http://www.jds.net.au/tech-tips/loadrunner-log-options/
	if( original_log_option & LR_MSG_CLASS_JIT_LOG_ON_ERROR ){
		// Send messges only when an error occurs:
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_ON ); // to ON = 1; 
	}else{
		// Send messges only when an error occurs:
		lr_set_debug_message( LR_MSG_CLASS_JIT_LOG_ON_ERROR, LR_SWITCH_OFF );
	}

	// Revert to specifications in Run-time Settings:
	lr_set_debug_message( original_log_option, LR_SWITCH_ON );

	return LR_PASS;
}


wi_EncodePlainToOAuth(const char *sIn, char *sOut){
/*
 *   wi_EncodePlainToOAuth converts a plain text string to an URL-form string, based on
 *   http://tools.ietf.org/html/rfc5849#section-3.6
 *   Characters in the unreserved character set as defined by
 *   http://www.faqs.org/rfcs/rfc3986.html
 *   http://tools.ietf.org/html/rfc5849
 *   [RFC3986], Section 2.3 (ALPHA, DIGIT, "-", ".", "_", "~") MUST NOT be encoded.
 *
 *   web_convert_param() with "TargetEncoding=URL cannot be used because it has a different encoding scheme
 *   This method is different from the encoding scheme used by the
 *   "application/x-www-form-urlencoded" content-type (for example, it
 *   encodes space characters as "%20" and not using the "+" character).
 *  
 *   Implements C library at http://liboauth.sourceforge.net//
 *   Verify using: http://oauth.googlecode.com/svn/code/javascript/example/signature.html
 *   https://dev.twitter.com/oauth/overview/percent-encoding-parameters
 *
 *   Parameters: sIn  - input string to be encoded to OAuth format
 *               sOut - output buffer
 *     Note: the size of "sOut" parameter should be at least equal to triple size
 *           of "sIn" parameter plus one character(for end-terminator '\0')
 *
 *   Author: Wilson Mar 
 *
 *   Examples: "a-._~"       -> "a-._~"
 *             "a b"         -> "a%20b"
 *             "%&*+="       -> "%25%26%2A%3D"
 */
    int i;
    char cCurChar;
    char sCurStr[4] = {0};
    sOut[0] = '\0';

    for (i = 0; cCurChar = sIn[i]; i++){
        // if this is a digit or an alphabetic letter:
        if (isdigit(cCurChar) || isalpha(cCurChar)
                || cCurChar=='-'
                || cCurChar=='.'
                || cCurChar=='_'
                || cCurChar=='~'
                || cCurChar=='='
                || cCurChar=='&'
           ){ // then write the current character "as is":
            sprintf(sCurStr, "%c", cCurChar);
        }else if ( cCurChar=='%') {
        	strcpy(sCurStr,"%25");
     // }else if ( cCurChar=='&') {
     //   	strcpy(sCurStr,"%26");
        }else if ( cCurChar=='*') {
        	strcpy(sCurStr,"%2A");
        }else if ( cCurChar=='+') {
        	strcpy(sCurStr,"%2B");
      //}else if ( cCurChar=='=') {
      //  	strcpy(sCurStr,"%3D");
        }else{ // convert it to hex-form such as "_" -> "%5F" :
            sprintf(sCurStr, "%%%X", cCurChar);
        }
        // append current item to the output string
        strcat(sOut, sCurStr);
    }
    return LR_PASS;
} // wi_EncodePlainToURL

wi_EncodePlainToURL(const char *sIn, char *sOut){
/*
 *   wi_EncodePlainToURL converts a plain text string to an URL-form string.
 *   
 *   Parameters: sIn  - input string to be encoded to URL format
 *               sOut - output buffer
 *     Note: the size of "sOut" parameter should be at least equal to triple size
 *           of "sIn" parameter plus one character(for end-terminator '\0')
 *
 *   Author: Dmitry Motevich at http://motevich.blogspot.com/2007/09/loadrunner-convert-text-to-url-format.html
 *
 *   Examples: "a"           -> "a"
 *             "a b"         -> "a%20b"
 *             "a b_cc:\/c%" -> "a%20b%5Fcc%3A%2Fc%25"
 */
    int i;
    char cCurChar;
    char sCurStr[4] = {0};
    sOut[0] = '\0';

    for (i = 0; cCurChar = sIn[i]; i++){
        // if this is a digit or an alphabetic letter:
        if (isdigit(cCurChar) || isalpha(cCurChar)) {
            // then write the current character "as is"
            sprintf(sCurStr, "%c", cCurChar);
        }else{ // convert it to hex-form. "_" -> "%5F" :
            sprintf(sCurStr, "%%%X", cCurChar);
        }
        // append current item to the output string
        strcat(sOut, sCurStr);
    }
    return LR_PASS;
} // wi_EncodePlainToURL


int wi_WriteDataToFile(char *szFileName, const char *szBuf, int len){
	
	// This code is explained at http://motevich.blogspot.com/2007/10/loadrunner-save-download-file-server.html?m=1
	// Used as an example at     http://www.pha.com.au/kb/index.php/Downloading_and_Saving_a_File_Using_LoadRunner
	
	int hFile;
    
	// lr_output_message(">> file=%s of %d. hFile=%d.",szFileName, len, hFile); // for debugging.
    hFile = fopen(szFileName,"wb");
    if (hFile == NULL){
        lr_error_message("Cannot create or open the file: %s of len=%d", szFileName, len);
        return LR_FAIL;
    }
    fwrite(szBuf, len, 1, hFile);
    fclose(hFile);

    return LR_PASS;
}  //wi_WriteDataToFile



/****** Customized functions that are unique to each script: ******/

int vi_set_Verbosity_attribute(){

	   LPCSTR_Verbosity = lr_get_attrib_string("Verbosity"); // from Run-time settings Attributes or command line.
	if(LPCSTR_Verbosity==NULL){                 // Not specified in Run-Time Settings Attributes or command line.
            iVerbosity=iVerbosity_default; // =default.
		    wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"Verbosity\" not specified in command-line or run-time settings. Default to \"%d\"."
					,iVerbosity
					);
			wi_resetPrinting();
		// NOTE: Don't return LR_FAIL; // fail here because default can be used.
	}else{
		iVerbosity=atoi(LPCSTR_Verbosity);
	} // if(LPCSTR_Verbosity==NULL)

	// TODO: 23. Set each web_set_max_html_param_len based on the largest individual server response detrermined from initial runs.	   
	if( iVerbosity == 1 ){
	    web_set_max_html_param_len("10240"); 
	}else
	if( iVerbosity == 2 ){
	    web_set_max_html_param_len("10240");
	}else
	if( iVerbosity == 3 ){
	    web_set_max_html_param_len("10240");
	}else
	if( iVerbosity == 4 ){
	    web_set_max_html_param_len("10240");
	}else
	if( iVerbosity == 5 ){
	    web_set_max_html_param_len("20240");
	}else{
	   	iVerbosity=iVerbosity_default; // =default.
		    wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"Verbosity\" not specified in command-line or run-time settings. Default to \"%d\"."
					,iVerbosity
					);
			wi_resetPrinting();

			wi_startPrintingError();
		    lr_output_message(">> Attribute \"Verbosity\" not recognized as valid value."
					,iVerbosity
					);
			wi_resetPrinting();
	}
	return LR_PASS;
} // vi_set_Verbosity_attribute()

vi_set_RunType_attribute(){

	LPCSTR_RunType = lr_get_attrib_string("RunType"); // from run-time settings Attributes or command line.
 	if(LPCSTR_RunType==NULL){ // Not specified in Run-Time Settings Attributes or command line.
	   LPCSTR_RunType="All"; // =default.
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\" not specified in command-line or run-time settings. Default to \"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
	}else{ // Ensure only acceptable values were input:
		if( stricmp("All",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=\"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();

		}else
		if( stricmp("LandingOnly",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=\"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
       	}else
		if( stricmp("SignUp",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=\"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
       	}else
		if( stricmp("SignUpInOut",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=\"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
       	}else
		if( stricmp("SignInOnly",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=\"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
       	}else
		if( stricmp("SignInErr",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=\"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();	
		}else
		if( stricmp("SignInOut",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=\"%s\"."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
		}else
		if( stricmp("NoOp",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=%s for no operation."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
		}else{
			wi_startPrintingError();
		    lr_output_message(">> Attribute \"RunType\"=%s not valid. lr_exit() stopping script execution."
					,LPCSTR_RunType 
					);
			wi_resetPrinting();
			lr_exit(LR_EXIT_VUSER,LR_FAIL);
		}
	} // if(LPCSTR_RunType==NULL)

	return LR_PASS;
} // vi_set_RunType_attribute()


vi_set_UseCase_attribute(){

	LPCSTR_UseCase = lr_get_attrib_string("UseCase"); // from run-time settings Attributes or command line.
 	if(LPCSTR_UseCase==NULL){ // Not specified in Run-Time Settings Attributes or command line.
	   LPCSTR_UseCase="All"; // =default.
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"UseCase\" not specified in command-line or run-time settings. Default to \"%s\"."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();
	}else{ // Ensure only acceptable values were input:

		if( stricmp("Home",LPCSTR_UseCase ) == FOUND ){ // Run-time Attribute "UseCase" or command line option "-UseCase"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"UseCase\"=\"%s\"."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();

		}else
		if( stricmp("Book",LPCSTR_UseCase ) == FOUND ){ // Run-time Attribute "UseCase" or command line option "-UseCase"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"UseCase\"=\"%s\"."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();

		}else
		if( stricmp("Search",LPCSTR_UseCase ) == FOUND ){ // Run-time Attribute "UseCase" or command line option "-UseCase"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"UseCase\"=\"%s\"."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();

		}else
		if( stricmp("Itinerary",LPCSTR_UseCase ) == FOUND ){ // Run-time Attribute "UseCase" or command line option "-UseCase"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"UseCase\"=\"%s\"."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();

		}else
		if( stricmp("All",LPCSTR_UseCase ) == FOUND ){ // Run-time Attribute "UseCase" or command line option "-UseCase"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"UseCase\"=\"%s\"."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();

		}else
		if( stricmp("NoOp",LPCSTR_UseCase ) == FOUND ){ // Run-time Attribute "UseCase" or command line option "-UseCase"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"UseCase\"=%s for no operation."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();
		}else{
			wi_startPrintingError();
		    lr_output_message(">> Attribute \"UseCase\"=%s not valid. lr_exit() stopping script execution."
					,LPCSTR_UseCase 
					);
			wi_resetPrinting();
			lr_exit(LR_EXIT_VUSER,LR_FAIL);
		}
	} // if(LPCSTR_UseCase==NULL)

	return LR_PASS;
} // vi_set_UseCase_attribute()

vi_set_URLSource_attribute(){

	int rc=LR_PASS;
	
	   LPCSTR_URLSource = lr_get_attrib_string("URLSource"); // from run-time settings Attributes or command line "-URLSource".
 	if(LPCSTR_URLSource==NULL){ // Not specified in Run-Time Settings Attributes or command line.
		     iURLSource_setting=iURLSource_default;

			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\" not specified in command-line or run-time settings. Default to \"%d\".", iURLSource_setting );
			wi_resetPrinting();
	}else{ // Ensure only acceptable values were input:
		if( stricmp("All",iURLSource_setting ) == FOUND ){ // Run-time Attribute "URLSource" or command line option "-URLSource"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\"=%s."
					,iURLSource_setting
					);
			wi_resetPrinting();
       	}else
		if( iURLSource_setting == 1 ){
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\"=%s for using file URLtoShorten.dat in script folder." ,iURLSource_setting );
			wi_resetPrinting();

		#ifdef USE_VTS
       	}else
		if( iURLSource_setting == 2 ){
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\"=%s for using VTS." ,iURLSource_setting);
			wi_resetPrinting();
		#endif // USE_VTS
		
		}else{
			wi_startPrintingError();
		    lr_output_message(">> Attribute \"URLSource\"=%s not valid. lr_exit() stopping script execution." ,iURLSource_setting );
			wi_resetPrinting();
			lr_exit(LR_EXIT_VUSER,LR_FAIL);
		}
	} // if(iURLSource_setting==NULL)

	// Regardless of iURLSource_setting selection,
	// define number of records in file (for all iURLSource_setting options because this is the fall-back):
	    nURLtoShorten_file_recs = vi_set_pURLtoShorten_file_recs();
	if( nURLtoShorten_file_recs == -1 ){
		lr_error_message("> vi_set_pURLtoShorten_file_recs() nURLtoShorten_file_recs=%d",nURLtoShorten_file_recs);
	}else{
	  	wi_startPrintingInfo();
		lr_output_message(">> nURLtoShorten_file_recs=%d.", nURLtoShorten_file_recs);
		wi_resetPrinting();
	}

	#ifdef USE_VTS
    if( iURLSource_setting == 2 ){
	    rc=vi_set_VTS3(); // Find the count of records in VTS table into nVTS_row_count.
		if( rc != LR_PASS ){
	    	// TODO: 12. If you prefer, if VTS cannot be used, change coding to error out instead of falling back if records were found earlier:
	    	if( nURLtoShorten_file_recs > 0 ){ // if records were found earlier?
				iURLSource_setting = 1; // use local data source
				
				wi_startPrintingInfo();
				lr_output_message(">> rc=%d fall-back to local data source with nURLtoShorten_file_recs=%f when iURLSource_setting=%d.", rc, nURLtoShorten_file_recs, iURLSource_setting);
				wi_resetPrinting();
			}
	    }else{
			// Add column "shorturl" to VTS for holding output from Google API calls:
			rc = vtc_create_column (pvci, "shorturl", &status); // status=1 is success.
				wi_startPrintingDebug();
				lr_output_message(">> rc=%d from vi_set_VTS3() with status=%d (should=1) when iURLSource_setting=%d.", rc, status, iURLSource_setting);
				wi_resetPrinting();
			if( status == 1 ){
				iUpdate_shorturl_in_VTS = 1; // 1=Yes

				wi_startPrintingInfo();
				lr_output_message(">> rc=%d with status=%d (should=1), so iUpdate_shorturl_in_VTS =%d (1=1Yes).", rc, status, iUpdate_shorturl_in_VTS );
				wi_resetPrinting();
			}else{
				iUpdate_shorturl_in_VTS = 0; // 0=No

				wi_startPrintingInfo();
				lr_output_message(">> rc=%d with status=%d (should=1), so iUpdate_shorturl_in_VTS =%d (0=NO).", rc, status, iUpdate_shorturl_in_VTS );
				wi_resetPrinting();
			}
	    }
    }
	#endif // USE_VTS

	return LR_PASS;
} // vi_set_URLSource_attribute()


int vi_set_pURLtoShorten_file_recs(){
	
	int nURLtoShorten_file_rec=2; // beging looping from second row after saving first row's value:
	lr_save_string(lr_eval_string("{pURL_long}"),"pURLtoShorten_first");
	lr_advance_param("pURLtoShorten"); // Increment file one record.

	// Loop through file until the first value appears again:
	while( 1==1 ){ // true
		// Catch if cycled back to first row:
		if( stricmp( lr_eval_string("{pURLtoShorten_first}"),lr_eval_string("{pURL_long}") ) == FOUND ){
			// lr_output_message(">> pURLtoShorten=%s", lr_eval_string("{pURL_long}") );
			return nURLtoShorten_file_rec - 1;
		}else{
			lr_advance_param("pURLtoShorten"); // Increment file one record.
			nURLtoShorten_file_rec = nURLtoShorten_file_rec + 1;
			// lr_output_message(">> nURLtoShorten_file_rec=%d pURLtoShorten=%s", nURLtoShorten_file_rec, lr_eval_string("{pURL_long}"));
		}
	}
	
	return LR_FAIL;
} // vi_set_pURLtoShorten_file_recs()


#ifdef USE_VTS
int vi_set_VTS3(){

	int rc=LR_PASS;
	
	// Using VTS3 (Virtual Table Service version 3) available since LR 11.52+:
	// See blog by its developer at http://h30499.www3.hp.com/t5/HP-LoadRunner-and-Performance/The-New-Virtual-Table-Server-VTS-in-LoadRunner-11-52/ba-p/6069435#.Ukt79rHnb4Y
	// HP Support article at http://support.openview.hp.com/selfsolve/document/KM305130

       LPCSTR_VTS_Host = lr_get_attrib_string("VTS_Host"); // from Run-time settings Attributes or command line.
 	if(LPCSTR_VTS_Host==NULL){                 // Not specified in Run-Time Settings Attributes or command line.
 	          VTS_Host_string="localhost"; // VTS_Host_default; // such as "localhost"; 

			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"VTS_Host\" not specified in command-line or run-time settings. Default to \"%s\"."
					,VTS_Host_string
					);
			wi_resetPrinting();
    }else{
		sprintf( VTS_Host_string ,"%s",LPCSTR_VTS_Host);
	} // if(LPCSTR_VTS_Host==NULL)
       

       LPCSTR_VTS_Port = lr_get_attrib_string("VTS_Port"); // from Run-time settings Attributes or command line.
 	if(LPCSTR_VTS_Port==NULL){             // Not specified in Run-Time Settings Attributes or command line.
 	             nPort=8787; // nVTS_Port_default; // such as 8787 or 8888;
		    wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"VTS_Port\" not specified in command-line or run-time settings. Default to \"%d\"."
					,nPort 
					);
			wi_resetPrinting();
    }else{
     	nPort = atoi(LPCSTR_VTS_Port); 
	} // if(LPCSTR_VTS_Port==NULL)

    /// Connect using LoadRunner native functions:
 		pvci = vtc_connect( VTS_Host_string , nPort , VTOPT_KEEP_ALIVE ); // VTS_Host_string
	if( pvci <= 0){
	    wi_startPrintingDebug();
		lr_error_message(">> VTS pvci=%d (non-zero).", pvci);
		wi_resetPrinting();
	}else{
		rc = vtc_get_last_error(pvci);
		if( rc != LR_PASS ) {
		    wi_startPrintingDebug();
			lr_error_message(">> rc from vtc_get_last_error(pvci)=%d for VTC connection to %s port .", rc, VTS_Host_string,nPort);
			wi_resetPrinting();
			return LR_FAIL; // FAIL
		}

		// Count rows in VTS table:
		vtc_column_size(pvci, "web", &nVTS_row_count);
		wi_startPrintingInfo();
		lr_output_message(">> nVTS_row_count=%d.", nVTS_row_count);
		wi_resetPrinting();
	}

	return rc;
} // vi_set_VTS3()
#endif // USE_VTS

