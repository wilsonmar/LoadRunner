/*! 
\file _ChangeLog.c
\brief Contains a short description of changes to the set of coding and data files.
*/

// v10 2015.08.15 wm: Add returnFlight Round-Trip to one-way outboundFlight
// v10 2015.08.13 am: Record Rec_Roundtrip_Ticket
// v10 2015.08.12 am: Import WT3_Flights_v01.csv file. Parameter FlightId and Add lr_save_string WT3_Flights_FlightId
// v10 2015.08.04 wm: Verify retry logic with MSO_SErrors on for 500 errors.
// v10 2015.08.?? wm: Fix Verbosity value default message.

// v10 2015.08.12 wm: Add _SELF to SignUp TargetFrame
// v10 2015.08.12 wm: Add Landing and SignIn after Cancel Itinerary.
// v10 2015.08.12 wm: Add outboundFlight capture in WT3_T23_Travel_Flight_Lookup for WT3_T24_Find_Flight
// v10 2015.08.06 wm: Add WT3_SignIn_isSignedIn. All trans pass.
// v10 2015 08.06 am: Run SignUpInOut logic
// v10 2015.08.05 wm: Add Cancel Checked.
// v10 2015.08.05 wm: Fix SignIn after SignUp.
// v10 2015.08.04 wm: Add Itineraries count.
// v10 2015.08.04 wm: Add print and reset function around output statements.
// v10 2015.08.02 wm: Add retry loop to Landing and SignUp based on Found_count.
// v10 2015.07.31 am: Arrange SignUp to handle error conditions
// v10 2015.07.30 wm: Fix SignUp to return to Landing page if user cannot be added and no cancel button is on screen.
// v10 2015.07.29 wm: Fix SignUpInOut to not login after SignUp already found.
// v10 2015.07.29 wm: Change UserId.dat to use jaja01 instead of jojo.
// v10 2015.07.26 wm: Returned UserId.dat to start with jojo01 instead of jojo.
// v10 2015.07.23 wm: Add parameters in reservations form and data setup function
// v10 2015.07.23 wm: Add logic for handling DBErr / MSO_SLoad script logic as described in v33 doc
// v10 2015.07.23 wm: Add Doxygen file headers.

// v09 2015.04.23 wm: Rename to parm_departDate and parm_returnDate
// v09 2015.04.23 am: Add lr_save_string functions
// v09 2015.04.23 am: Add "WT3_T24_Travel_Find_Flight" and "WT3_T30_Travel_Find_Flight2" Transacion name.
// v09 2015.04.23 am: Recorded Recording_Travel_For_Validation to validate the missing transaction.
// v09 2015.04.21 wm: Define parm_departDate, tomorrow
// v08 2015.04.17 wm: Add Travel function list, dates
// v07 2015.04.16 am: Add funnctions in Travel recording.
// v06 2015.04.17 am: Deleted TT, Replaced Start and End Transactions with wi start and end transaction.
// v06 2015.04.17 am: Moved the Recording_Travel Action into WT3_Travel

_ChangeLog()
{
	return 0;
}
