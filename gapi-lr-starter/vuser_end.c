vuser_end(){
	
	wi_startPrintingInfo();
	lr_output_message(">> iActionIterations=%i, nURLtoShorten_done=%i.", iActionIterations ,nURLtoShorten_done );
	wi_stopPrinting();

	#ifdef USE_VTS
	if( iURLSource_setting == 2 ){
		vtc_disconnect( pvci ); // disconnect currently open pvci.
	}
	#endif // USE_VTS

	return LR_PASS;
}
