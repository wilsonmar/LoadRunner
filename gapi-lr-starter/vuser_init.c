//// Functions defined in this file can be accesssed by Action and others, defined in this order:

	// vuser_init()
	// Utility functions:
		// wi_set_unique_id()
		// wi_set_Think_Time()

		// wi_start_transaction()
		// wi_end_transaction()
		// wi_startPrintingError()
		// wi_startPrintingInfo()
		// wi_startPrintingDebug()
		// wi_startPrintingTrace()
		// wi_stopPrinting()

		// wi_EncodePlainToURL()
		// wi_WriteDataToFile()
		// others from Floris and Stuart.
		
	// Custom functions performed only once before the first action iteration:
		// vi_set_Verbosity_attribute()
		// vi_set_RunType_attribute()
		
		// vi_set_URLSource_attribute()
		// vi_set_pURLtoShorten_file_recs()
		// vi_set_VTS3()

		
//// Define Statics (like built-in LR_PASS and LR_FAIL) and variables:
	#define FOUND 0
	// NOTE: No semicolon after static definitions.
	
//// Compiler directies used to reduce the szie of compiled executables (so more memory is available for more vusers instead of programs):
	

//// Run-Time Settings Attributes or command-line LPCSTR (LoadRunner Pointer C Strings) and associated variables:

	// TODO: 08. Specify 4 during script development, then 2 during test runs.
	LPCSTR			LPCSTR_Verbosity; // used within vi_set_Verbosity_attribute() below.
	int					  iVerbosity_default = 4; 
	int 			      iVerbosity;
							//   1 = wi_startPrintingError only will print.
							//   2 = wi_startPrintingError and wi_startPrintingInfo will print.
							//   3 = wi_startPrintingError and wi_startPrintingInfo and wi_startPrintingDebug will print.
							//   4 = wi_startPrintingError and wi_startPrintingInfo and wi_startPrintingDebug and wi_startPrintingTrace will print.

	LPCSTR			LPCSTR_RunType; // controls scope of script processing.

	// For use by wi_start_transaction():
	LPCSTR			  LPCSTR_ThinkTimeSecs;
	float			    floatThinkTimeSecs; // numeric.
	float			    floatThinkTimeSecs_default = 10.5; 
					
	// For google_apis:
	LPCSTR			LPCSTR_URLSource; // 1=local .dat file, 2=VTS, 3=Google spreadsheet online?, 4=MySQL?.
	int				      iURLSource_default = 2;
	int 			      iURLSource_setting;
	// For use by vi_set_pURLtoShorten_file_recs() of local file URLtoShorten.dat:
	long			nURLtoShorten_file_recs; // counter of rows available.
	long			nURLtoShorten_index; // like i.
	int				nURLtoShorten_done; // counter of rows processed.

	// TODO: 09. If not using VTS, comment out (substitute) # with //:
#define USE_VTS
#ifdef  USE_VTS
	// For use by VTS within vi_set_VTS3() below.
	// TODO: 10. Follow instructions in the Getting Started Hands-on Guide to install VTS, invoke VTS, and import data into it.
	// 		Invoke VTS from Windows 7 Start > All Programs > HP Software > Virtual Table Server.
	//		This invokes "C:\Program Files (x86)\HP\LoadRunner\bin\spsConfig.hta" -launchVtsUI
	//		QUESTION: From Windows 8?
	// TODO: 11. Import data before starting this script : Start > All Programs > HP Software > HP LoadRunner > Tools > Virtual Table Server.
	LPCSTR			LPCSTR_VTS_Host;
	//char*			       VTS_Host_default="localhost"; 
	char*		           VTS_Host_string; // = LPCSTR_VTS_Host; // "localhost"; // vts1_Server; //"localhost";

	LPCSTR			LPCSTR_VTS_Port;
	//int					  nVTS_Port_default=8888;
	int				          nPort; // = int(LPCSTR_VTS_Port); // int(vts1_Port); // 4000 is installation default; // or 8888;

	int				      nVTS_row_count; // &colcount
	int				iUpdate_shorturl_in_VTS; // 1=Yes, 0=No.

	// Naming based on examples within HP Function Reference:
	PVCI2			pvci = 0; // Windows internal process handle number.
	char 			**outValues  = NULL; // ** defines a C array.
	char 			**outColumns = NULL;
	char* 			cname; //column name
	unsigned short  status;
	char            *outvalue = NULL;
	char            *shorturl = NULL;
#endif // USE_VTS

// TODO: 13. If not using QR image generation, comment out (substitute) # with //:
#define GEN_QR
#ifdef  GEN_QR
	LPCSTR			LPCSTR_SaveImageYN; // controls whether to get/get_google_short_url_qrcode_qrcode();
	char*			       SaveImageYN_default="N";
	char*			       strOutputLogFolder;
#endif // GEN_QR

//// Global variables:

	int 			iActionIterations = 0; // incremented within Action() to 
	unsigned int	original_log_option;
	char 			global_unique_id[128]=""; 

	// For update by wi_end_transaction():
	int 			  intHttpRetCode;
	int 			  intHttpMilliseconds;
	float 			floatHttpMilliseconds;
	int 			  intHttpSize;
	float 			floatHttpKBytes;

	// Temporary field names for local use within custom functions carried over from samples in LR docs:
	char*			tempChar1;
	char*			tempChar2;
	char			tempString1[256];
	char			tempString2[256];
	char*			token;

vuser_init(){

	int rc=LR_PASS;

	original_log_option = lr_get_debug_message(); // Save run-time setting as set in script or scenario.
	vi_set_Verbosity_attribute();
	wi_set_unique_id(); // sets global_unique_id.
	lr_save_string("no imposed impediments","pRunConditions"); // output in logs.

	rc=vi_set_RunType_attribute();
	rc=wi_set_Think_Time();
	rc=vi_set_URLSource_attribute();
	
	return rc;
} // vuser_init()

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
	vuser_pid = lrlib_get_vuser_pid();

	lr_whoami(&iVuserID, &vuser_group, &iScenarioID); // lr_whoami returns void by design (no rc).

	// NOTE: When run in VuGen: Controller=None, host=%MACHINENAME%, ScenarioID=0, vuser_group=None, iVuserID=-1.
  	wi_startPrintingInfo();
	lr_output_message(">> Controller=%s, Host=%s, ScenarioID=%d, Group=%s, Vuser=%d, PID=%d." 
  	                  ,my_controller_name ,my_host ,iScenarioID, vuser_group ,iVuserID, vuser_pid );
	wi_stopPrinting();
	
	sprintf( global_unique_id,"C%s.H%d.S%s.G%s.U%d.P%d"
			,my_controller_name
			,my_host
			,iScenarioID
			,vuser_group
			,iVuserID
			,vuser_pid
			);

	return rc;
} // wi_set_unique_id



/**
 * Gets the process ID of the mmdrv.exe process that is running the VuGen script that called
 * this function.
 *
 * @return    This function returns the process ID of the calling process.
 *
 * Example code:
 *     // Print the vuser's process ID
 *     int vuser_pid; vuser_pid = lrlib_get_vuser_pid();
 *     lr_output_message("vuser_pid: %d", vuser_pid);
 *
 * Note: This function only works on Windows.
 * From lr-libc.
 */
int lrlib_get_vuser_pid() {
    int rc=LR_PASS; // return code
    int pid=0; // the process id (usually 4 digits)
    static int is_msvcrt_dll_loaded = FALSE; // A static variable inside a function keeps its value between
                                   // invocations. The FALSE value is assigned only on the first
                                   // invocation.
    char* dll_name = "MSVCRT.DLL"; // This DLL contains the _getpid() function. It is a standard
                                   // Windows DLL, usually found in C:\WINDOWS\system32.
                                   // Note: on Windows platforms, if you do not specify a path,
                                   // lr_load_dll searches for the DLL using the standard sequence
                                   // used by the C++ function, LoadLibrary.

    // Only load the DLL the first time this function is called:
    if (is_msvcrt_dll_loaded == FALSE) {
        rc = lr_load_dll(dll_name);
        if (rc != 0) {
            lr_error_message("Error loading %s.", dll_name);
            lr_abort();
        }
        is_msvcrt_dll_loaded = TRUE;
    }

    pid = _getpid();

    return pid;
} // lrlib_get_vuser_pid


int wi_set_Think_Time(){
	
 		 LPCSTR_ThinkTimeSecs = lr_get_attrib_string("ThinkTimeSecs");
	if(  LPCSTR_ThinkTimeSecs==NULL){ // Not specified.
	  	   floatThinkTimeSecs=floatThinkTimeSecs_default; // Default unless changed for subsequent transactions.
	  	wi_startPrintingDebug();
		lr_output_message(">> floatThinkTimeSecs=%8.2f from coded default.", floatThinkTimeSecs);
		wi_stopPrinting();
	}else{ // use value from command attribute:
	    floatThinkTimeSecs= atof(LPCSTR_ThinkTimeSecs); // atof() requires definition.
	  	wi_startPrintingDebug();
		lr_output_message(">> Attribute floatThinkTimeSecs=%8.3f.", floatThinkTimeSecs ); // FIXME: floatThinkTimeSecs=100721344.000 ?
		wi_stopPrinting();
	 }
 
	return LR_PASS;
} // wi_set_Think_Time()
	
wi_start_transaction(){
	// lr_save_string( strTransName,"pTransName" ); // defined in Action().
	lr_start_transaction(lr_eval_string("{pTransName}"));
	
	// lr_get_transaction_duration(lr_eval_string("{pTransName}"));
	web_reg_save_param_ex("ParamName=pJSONResponse","LB={","RB=}", "Notfound=warning", LAST); // captures JSON

	lr_think_time( floatThinkTimeSecs );
		
    return LR_PASS;
} // wi_start_transaction

int wi_end_transaction(){
	int rc=LR_PASS;
	
	/* Defined as globals at top of vuser_init():
	int 			  intHttpRetCode;
	int 			  intHttpMilliseconds;
	float 			floatHttpMilliseconds;
	int 			  intHttpSize;
	float 			floatHttpKBytes;
	*/

	// Using pTransName saved in wi_start_transaction before the transaction:
    lr_end_transaction(lr_eval_string("{pTransName}"),LR_AUTO);

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
    	lr_error_message(">> HTML Return Code=%d, pJSONResponse=%s." 
		                 , intHttpRetCode
		                 , lr_eval_string("{pJSONResponse}") 
		                 );
		wi_stopPrinting();
		rc=LR_FAIL;
	}

    return rc;
} // wi_end_transaction

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
		lr_set_debug_message( LR_MSG_CLASS_EXTENDED_LOG, LR_SWITCH_ON ); // (16) Extended logging.
	}
	return LR_PASS;
}
wi_stopPrinting(){

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
        }else if ( cCurChar=='=') {
        	strcpy(sCurStr,"%3D");
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
			wi_stopPrinting();
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
			wi_stopPrinting();

			wi_startPrintingError();
		    lr_output_message(">> Attribute \"Verbosity\" not recognized as valid value."
					,iVerbosity
					);
			wi_stopPrinting();
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
			wi_stopPrinting();
	}else{ // Ensure only acceptable values were input:
		if( stricmp("All",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=%s."
					,LPCSTR_RunType 
					);
			wi_stopPrinting();
       	}else
		if( stricmp("NoOp",LPCSTR_RunType ) == FOUND ){ // Run-time Attribute "RunType" or command line option "-RunType"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"RunType\"=%s for no operation."
					,LPCSTR_RunType 
					);
			wi_stopPrinting();
		}else{
			wi_startPrintingError();
		    lr_output_message(">> Attribute \"RunType\"=%s not valid. lr_exit() stopping script execution."
					,LPCSTR_RunType 
					);
			wi_stopPrinting();
			lr_exit(LR_EXIT_VUSER,LR_FAIL);
		}
	} // if(LPCSTR_RunType==NULL)

	return LR_PASS;
} // vi_set_RunType_attribute()

vi_set_URLSource_attribute(){

	int rc=LR_PASS;
	
	   LPCSTR_URLSource = lr_get_attrib_string("URLSource"); // from run-time settings Attributes or command line "-URLSource".
 	if(LPCSTR_URLSource==NULL){ // Not specified in Run-Time Settings Attributes or command line.
		     iURLSource_setting=iURLSource_default;

			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\" not specified in command-line or run-time settings. Default to \"%d\".", iURLSource_setting );
			wi_stopPrinting();
	}else{ // Ensure only acceptable values were input:
		if( stricmp("All",iURLSource_setting ) == FOUND ){ // Run-time Attribute "URLSource" or command line option "-URLSource"
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\"=%s."
					,iURLSource_setting
					);
			wi_stopPrinting();
       	}else
		if( iURLSource_setting == 1 ){
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\"=%s for using file URLtoShorten.dat in script folder." ,iURLSource_setting );
			wi_stopPrinting();

		#ifdef USE_VTS
       	}else
		if( iURLSource_setting == 2 ){
			wi_startPrintingInfo();
		    lr_output_message(">> Attribute \"URLSource\"=%s for using VTS." ,iURLSource_setting);
			wi_stopPrinting();
		#endif // USE_VTS
		
		}else{
			wi_startPrintingError();
		    lr_output_message(">> Attribute \"URLSource\"=%s not valid. lr_exit() stopping script execution." ,iURLSource_setting );
			wi_stopPrinting();
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
		wi_stopPrinting();
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
				wi_stopPrinting();
			}
	    }else{
			// Add column "shorturl" to VTS for holding output from Google API calls:
			rc = vtc_create_column (pvci, "shorturl", &status); // status=1 is success.
				wi_startPrintingDebug();
				lr_output_message(">> rc=%d from vi_set_VTS3() with status=%d (should=1) when iURLSource_setting=%d.", rc, status, iURLSource_setting);
				wi_stopPrinting();
			if( status == 1 ){
				iUpdate_shorturl_in_VTS = 1; // 1=Yes

				wi_startPrintingInfo();
				lr_output_message(">> rc=%d with status=%d (should=1), so iUpdate_shorturl_in_VTS =%d (1=1Yes).", rc, status, iUpdate_shorturl_in_VTS );
				wi_stopPrinting();
			}else{
				iUpdate_shorturl_in_VTS = 0; // 0=No

				wi_startPrintingInfo();
				lr_output_message(">> rc=%d with status=%d (should=1), so iUpdate_shorturl_in_VTS =%d (0=NO).", rc, status, iUpdate_shorturl_in_VTS );
				wi_stopPrinting();
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
			wi_stopPrinting();
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
			wi_stopPrinting();
    }else{
     	nPort = atoi(LPCSTR_VTS_Port); 
	} // if(LPCSTR_VTS_Port==NULL)

    /// Connect using LoadRunner native functions:
 		pvci = vtc_connect( VTS_Host_string , nPort , VTOPT_KEEP_ALIVE ); // VTS_Host_string
	if( pvci <= 0){
	    wi_startPrintingDebug();
		lr_error_message(">> VTS pvci=%d (non-zero).", pvci);
		wi_stopPrinting();
	}else{
		rc = vtc_get_last_error(pvci);
		if( rc != LR_PASS ) {
		    wi_startPrintingDebug();
			lr_error_message(">> rc from vtc_get_last_error(pvci)=%d for VTC connection to %s port .", rc, VTS_Host_string,nPort);
			wi_stopPrinting();
			return LR_FAIL; // FAIL
		}

		// Count rows in VTS table:
		vtc_column_size(pvci, "web", &nVTS_row_count);
		wi_startPrintingInfo();
		lr_output_message(">> nVTS_row_count=%d.", nVTS_row_count);
		wi_stopPrinting();
	}

	return rc;
} // vi_set_VTS3()
#endif // USE_VTS


// END SCRIPT FILE //