/*! 
\file _ChangeLog.c
\brief Contains a short description of changes to the set of coding and data files.
*/
// TODO: v?? 2015.07.24 am: Fixed the web_reg_find issue with longin
// TODO: v?? 2015.07.24 am: Add logic for handling "Internal Server Error" MSO_SErrors.

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
