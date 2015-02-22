Action(){
	int rc=0;
	
		// After “Enable running JavaScript code” is enabled in Run-Time Settings > Internet Protocol > Preferences > Set advanced options > Options
	    rc=web_js_run(
	        "Code=getWorkingAdultRandomBirthDate('YYYY-MM-DD');",
	        "ResultParam=birth_date_iso",
	        SOURCES,
	        "File=lr_js_date_lib.js", ENDITEM,
	        LAST);
		// web_js_reset() not invoked to leave js code in memory for repeated calls.

		lr_output_message(">> birth_date=\"%s\" rc=%d.", lr_eval_string("{birth_date_iso}"), rc);
		
	return rc;
}