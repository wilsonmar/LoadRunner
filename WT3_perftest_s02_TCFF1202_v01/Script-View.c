//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Script_View_Init()
{
	/* 2015.04.28 */
	truclient_step("2", "Evaluate JavaScript code // Log of run conditions....getUserIP );", "snapshot=Init_2.inf");
	truclient_step("3", "Evaluate JavaScript code // document. items : // ...ocEmbeds ); //=", "snapshot=Init_3.inf");
}

Script_View_Action()
{
	lr_start_transaction("T03_WT3_URL_Landing");
	truclient_step("1", "Navigate to 'http://127.0.0.1:1080/WebTours/index.htm'", "snapshot=Action_1.inf");
	lr_end_transaction("T03_WT3_URL_Landing",0);
	lr_start_transaction("T04_WT3_SignUp_Error");
	truclient_step("2", "Click on sign up now link", "snapshot=Action_2.inf");
	truclient_step("3", "Click on Username textbox", "snapshot=Action_3.inf");
	truclient_step("4", "Type jojo in Username textbox", "snapshot=Action_4.inf");
	truclient_step("5", "Type **** in Password passwordbox", "snapshot=Action_5.inf");
	truclient_step("6", "Type **** in Confirm passwordbox", "snapshot=Action_6.inf");
	truclient_step("7", "Click on register button", "snapshot=Action_7.inf");
	lr_end_transaction("T04_WT3_SignUp_Error",0);
	lr_start_transaction("T05_WT3_SignUp");
	truclient_step("8", "Click on jojo textbox", "snapshot=Action_8.inf");
	truclient_step("9", "Type jojo102 in jojo textbox", "snapshot=Action_9.inf");
	truclient_step("10", "Type **** in Password passwordbox", "snapshot=Action_10.inf");
	truclient_step("11", "Type **** in Confirm passwordbox", "snapshot=Action_11.inf");
	truclient_step("12", "Click on First Name textbox", "snapshot=Action_12.inf");
	truclient_step("13", "Type whatever in First Name textbox", "snapshot=Action_13.inf");
	truclient_step("14", "Type whatever in Last Name textbox", "snapshot=Action_14.inf");
	truclient_step("15", "Type whatever in Street Address textbox", "snapshot=Action_15.inf");
	truclient_step("16", "Type whatever in City/State/Zip textbox", "snapshot=Action_16.inf");
	truclient_step("17", "Click on register button", "snapshot=Action_17.inf");
	lr_end_transaction("T05_WT3_SignUp",0);
	lr_start_transaction("T08_WT3_SignIn_Error");
	truclient_step("18", "Click on Username textbox", "snapshot=Action_18.inf");
	truclient_step("19", "Type jojo in Username textbox", "snapshot=Action_19.inf");
	truclient_step("20", "Type *** in Password passwordbox", "snapshot=Action_20.inf");
	truclient_step("21", "Click on Login button", "snapshot=Action_21.inf");
	lr_end_transaction("T08_WT3_SignIn_Error",0);
	lr_start_transaction("T12_WT3_SignIn");
	truclient_step("22", "Click on Username textbox", "snapshot=Action_22.inf");
	truclient_step("23", "Type jojo102 in Username textbox", "snapshot=Action_23.inf");
	truclient_step("24", "Type **** in Password passwordbox", "snapshot=Action_24.inf");
	truclient_step("25", "Click on Login button", "snapshot=Action_25.inf");
	lr_end_transaction("T12_WT3_SignIn",0);
	lr_start_transaction("WT3_T21_Travel_Home");
	truclient_step("26", "Click on Home Button image", "snapshot=Action_26.inf");
	lr_end_transaction("WT3_T21_Travel_Home",0);
	lr_start_transaction("WT3_T22_Travel_Search_Flight");
	truclient_step("27", "Click on Search Flights Button image", "snapshot=Action_27.inf");
	lr_end_transaction("WT3_T22_Travel_Search_Flight",0);
	lr_start_transaction("WT3_T23_Travel_Flight_Lookup");
	truclient_step("28", "Select Los Angeles from Arrival City listbox", "snapshot=Action_28.inf");
	truclient_step("29", "Click on findFlights button", "snapshot=Action_29.inf");
	lr_end_transaction("WT3_T23_Travel_Flight_Lookup",0);
	lr_start_transaction("WT3_T24_Find_Flight");
	truclient_step("30", "Click on reserveFlights button", "snapshot=Action_30.inf");
	lr_end_transaction("WT3_T24_Find_Flight",0);
	lr_start_transaction("WT3_T25_Travel_Payment_Details");
	truclient_step("31", "Click on Credit Card textbox", "snapshot=Action_31.inf");
	truclient_step("32", "Type 123456789 in Credit Card textbox", "snapshot=Action_32.inf");
	truclient_step("33", "Click on Exp Date textbox", "snapshot=Action_33.inf");
	truclient_step("34", "Type 12/20 in Exp Date textbox", "snapshot=Action_34.inf");
	truclient_step("35", "Click on buyFlights button", "snapshot=Action_35.inf");
	lr_end_transaction("WT3_T25_Travel_Payment_Details",0);
	lr_start_transaction("WT3_T33_Travel_Check_Itinerary");
	truclient_step("36", "Double click on Itinerary Button image", "snapshot=Action_36.inf");
	lr_end_transaction("WT3_T33_Travel_Check_Itinerary",0);
	lr_start_transaction("T34_WT3_SignOut");
	truclient_step("37", "Click on SignOff Button image", "snapshot=Action_37.inf");
	lr_end_transaction("T34_WT3_SignOut",0);
}
