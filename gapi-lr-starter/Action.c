// This script is a full-featured example of how to make calls to Google's URL Shortener web services API
// using naming conventions and coding practices which facilitate flexibility during load test projects within large enterprises.

// This script obtains long URL to shorten from file URLtoShorten.dat in the script's folder or from VTS.
// Each Action iteration creates one.
// The source of long URLs can be specified by a run-time attribute (or command-line parameter).
// Long URLs in VTS is from the “web” field from a sample file.
	
// Calls to Google API are done with credentials stored in file google_urlshortener_credentials.dat and
// the .p12 file saved into the script's folder after being crated using the Google API Console.
// Signing using the SHA256 algorithm is performed by the LoadRunner OAuth2 oauthhelper.dll developed by phillip.mayhew@rextencytech.com.

// VTS also holds the output in the “shorturl” column the script creates.
// A check is made to see if output shortened URL is already available in a column for same row containing the long URL.
// OAuth tokens are re-usedif it is still before the expiration time-frame.

// Optionally, a QR code image file is generated to a designated folder if the SaveImageYN attribute is set to Y.

// Thanks to reviewers Jason and team from HP R&D Shanghai.
// Wilsonmar@gmail.com designed and coded the script, wrote tutorials, and managed the project.

// DISCLAIMER: Permission to use, copy, modify and distribute this software and its documentation for any purpose and without fee is hereby granted,
// provided that the above copyright notice appear in all copies, and that both the copyright notice and this permission notice appear in supporting documentation, 
// and that the name of <Phillip Mayhew, Wilson Mar, and HP> not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.
// Copyright holders makes no representations about the suitability of this software for any purpose. It is provided "as is" without express or implied warranty.
// <Phillip Mayhew, Wilson Mar, and HP> DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
// IN NO EVENT SHALL copyright holders BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

// These manual actions are described (with sample screen prints) in another document:
	// TODO: 01. Obtain your own credentials from the Google APIs Console at https://code.google.com/apis/console/b/0/ or https://cloud.google.com/console#/project

	// Rather than using a command like lr_save_string("123456789012@developer.gserviceaccount.com","GoogleAPIServiceEmail");
	// TODO: 02. Update file google_urlshortener_credentials.dat 1st field with the Google API Project name assigned to you by Google.

	// TODO: 03. Update file google_urlshortener_credentials.dat 2nd field with the Google Service Email assigned to you by Google.
	// TODO: 04. Update file google_urlshortener_credentials.dat 3rd field with the GoogleAPIFingerprin prefix assigned to you by Google.


// Functions in this file are repeated for each Action iteration, defined in the sequence below (in calling hierarchy):
	// Action()

		
Action(){
	int rc=LR_PASS;

	// TODO: 05. At the Google API Console, generate the Public key infrastructure fingerprint private file.
	// TODO: 06. Save the fingerprint file as file "google-urlshortener.p12" file in the script folder.
	// TODO: 07. If you don't want to use the default name for the fingerprint file "notasecret", change it here:
				lr_save_string("google_urlshortener.p12","pServicePrivateKeyFile");

	    iActionIterations++; // increment from zero value defined in vuser_init.
	if( iActionIterations == 1 ){ // The first interation only (instead of putting this in vuser_init):
	   	rc=set_oauthhelper_dll(); // From Philip Mayhew. Needed by get_google_short_url().
		if( rc != LR_PASS ){ return rc; } // No input data to process.
		
		#ifdef GEN_QR
	   	// FIXME: Code to obtain Windows user Documents folder path (Reg Query "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" |findstr "Personal">>DocPath.dat)
	   	// TODO: 16. Specify folder where QR code image files (for each short URL) get stored:

				
		   	strOutputLogFolder=(char *)getenv("TEMP"); // returns zero if valid.
		  	lr_output_message(">> strOutputLogFolder=%s.", strOutputLogFolder);

		lr_save_string("C:\\Temp\\","pImageFilePath"); // Double back slashes for escaping back slash in get_google_short_url_qrcode().
		wi_startPrintingInfo();
	  	lr_output_message(">> pImageFilePath=%s.", lr_eval_string("{pImageFilePath}"));
		wi_stopPrinting();

		rc=set_gen_QR_attribute();
		if( rc != LR_PASS ){ return rc; } // Disable the feature.
		#endif // GEN_QR
	}

		// TODO: 17. Customize your own transaction name prefix for get_google_short_url call.
		lr_save_string("get_google_short_url" ,"pTransSequence");
		rc=get_google_short_url(); // to obtain LR parameter {pShortURL} by calling get_google_access_token() which calls get_pJWTAssertion().
	
	//FUTURE ENHANCEMENTS: 
	//  Add retrieval of URL shortened:
	//  Add recognition of expired token and get new token using refresh token instead of auth token.
	//  Add other Google APIs, Amazon APIs, etc. using same data:
	//  set_google_other_api();
	//  Add API calls for other fields in data (email gravatar from MD5, Zip code, lat/long calc, validations, etc.
	
	return rc;
} // Action()

