//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Script_View_Init()
{
	/* 2015.04.28 This script demonstrates recording, verification, and repeatable replay of upload UI controls across various UI libraries - as part of the TruClient Hands-on Guide. */
	truclient_step("2", "Evaluate JavaScript code // Log of run conditions....getUserIP );", "snapshot=Init_2.inf");
	truclient_step("3", "Evaluate JavaScript code // document. items : // ...ocEmbeds ); //=", "snapshot=Init_3.inf");
}

Script_View_Action()
{
	lr_start_transaction("T03_WT3_URL_Landing");
	truclient_step("1", "Navigate to 'http://127.0.0.1:1080/WebTours/index.htm'", "snapshot=Action_1.inf");
	lr_end_transaction("T03_WT3_URL_Landing",0);
	truclient_step("2", "Verify sign up now 's 'Visible Text' Contain sign up now", "snapshot=Action_2.inf");
	lr_start_transaction("T04_WT3_SignUp_Error");
	truclient_step("3", "Click on sign up now link", "snapshot=Action_3.inf");
	truclient_step("4", "Click on Username textbox", "snapshot=Action_4.inf");
	truclient_step("5", "Type jojo in Username textbox", "snapshot=Action_5.inf");
	truclient_step("6", "Type **** in Password passwordbox", "snapshot=Action_6.inf");
	truclient_step("7", "Type **** in Confirm passwordbox", "snapshot=Action_7.inf");
	truclient_step("8", "Click on register button", "snapshot=Action_8.inf");
	lr_end_transaction("T04_WT3_SignUp_Error",0);
	truclient_step("9", "Verify Your username is taken.... 's 'Visible Text' Contain Your username is taken. ... a unique name).", "snapshot=Action_9.inf");
	lr_start_transaction("T05_WT3_SignUp");
	truclient_step("10", "Click on jojo textbox", "snapshot=Action_10.inf");
	truclient_step("11", "Type jojo102 in jojo textbox", "snapshot=Action_11.inf");
	truclient_step("12", "Type **** in Password passwordbox", "snapshot=Action_12.inf");
	truclient_step("13", "Type **** in Confirm passwordbox", "snapshot=Action_13.inf");
	truclient_step("14", "Click on First Name textbox", "snapshot=Action_14.inf");
	truclient_step("15", "Type whatever in First Name textbox", "snapshot=Action_15.inf");
	truclient_step("16", "Type whatever in Last Name textbox", "snapshot=Action_16.inf");
	truclient_step("17", "Type whatever in Street Address textbox", "snapshot=Action_17.inf");
	truclient_step("18", "Type whatever in City/State/Zip textbox", "snapshot=Action_18.inf");
	truclient_step("19", "Click on register button", "snapshot=Action_19.inf");
	lr_end_transaction("T05_WT3_SignUp",0);
	lr_start_transaction("T08_WT3_SignIn_Error");
	truclient_step("20", "Click on Username textbox", "snapshot=Action_20.inf");
	truclient_step("21", "Type jojo in Username textbox", "snapshot=Action_21.inf");
	truclient_step("22", "Type *** in Password passwordbox", "snapshot=Action_22.inf");
	truclient_step("23", "Click on Login button", "snapshot=Action_23.inf");
	lr_end_transaction("T08_WT3_SignIn_Error",0);
	truclient_step("24", "Verify Web Tours Error Incorrect... 's 'Visible Text' Contain Web Tours Error - Incorrect Password", "snapshot=Action_24.inf");
	lr_start_transaction("T12_WT3_SignIn");
	truclient_step("25", "Click on Username textbox", "snapshot=Action_25.inf");
	truclient_step("26", "Type jojo102 in Username textbox", "snapshot=Action_26.inf");
	truclient_step("27", "Type **** in Password passwordbox", "snapshot=Action_27.inf");
	truclient_step("28", "Click on Login button", "snapshot=Action_28.inf");
	lr_end_transaction("T12_WT3_SignIn",0);
	truclient_step("29", "Verify Welcome, 's 'Visible Text' Contain Welcome, jojo102, to the...hen you're done!", "snapshot=Action_29.inf");
	lr_start_transaction("WT3_T21_Travel_Home");
	truclient_step("30", "Click on Home Button image", "snapshot=Action_30.inf");
	lr_end_transaction("WT3_T21_Travel_Home",0);
	truclient_step("31", "Verify Search Flights Button 's 'Visible Text' Contain [Value]", "snapshot=Action_31.inf");
	lr_start_transaction("WT3_T22_Travel_Search_Flight");
	truclient_step("32", "Click on Search Flights Button image", "snapshot=Action_32.inf");
	lr_end_transaction("WT3_T22_Travel_Search_Flight",0);
	truclient_step("33", "Verify Find Flight 's 'Visible Text' Contain Find Flight", "snapshot=Action_33.inf");
	lr_start_transaction("WT3_T23_Travel_Flight_Lookup");
	truclient_step("34", "Select Los Angeles from Arrival City listbox", "snapshot=Action_34.inf");
	truclient_step("35", "Click on findFlights button", "snapshot=Action_35.inf");
	lr_end_transaction("WT3_T23_Travel_Flight_Lookup",0);
	truclient_step("36", "Verify Flight departing from... 's 'Visible Text' Contain Flight departing from", "snapshot=Action_36.inf");
	lr_start_transaction("WT3_T24_Find_Flight");
	truclient_step("37", "Click on reserveFlights button", "snapshot=Action_37.inf");
	lr_end_transaction("WT3_T24_Find_Flight",0);
	truclient_step("38", "Verify Payment Details 's 'Visible Text' Contain Payment Details", "snapshot=Action_38.inf");
	lr_start_transaction("WT3_T25_Travel_Payment_Details");
	truclient_step("39", "Click on Credit Card textbox", "snapshot=Action_39.inf");
	truclient_step("40", "Type 123456789 in Credit Card textbox", "snapshot=Action_40.inf");
	truclient_step("41", "Click on Exp Date textbox", "snapshot=Action_41.inf");
	truclient_step("42", "Type 12/20 in Exp Date textbox", "snapshot=Action_42.inf");
	truclient_step("43", "Click on buyFlights button", "snapshot=Action_43.inf");
	lr_end_transaction("WT3_T25_Travel_Payment_Details",0);
	truclient_step("44", "Verify Invoice 's 'Visible Text' Contain Invoice", "snapshot=Action_44.inf");
	lr_start_transaction("WT3_T33_Travel_Check_Itinerary");
	truclient_step("45", "Double click on Itinerary Button image", "snapshot=Action_45.inf");
	lr_end_transaction("WT3_T33_Travel_Check_Itinerary",0);
	truclient_step("46", "Verify Itinerary 's 'Visible Text' Contain Itinerary", "snapshot=Action_46.inf");
	lr_start_transaction("T34_WT3_SignOut");
	truclient_step("47", "Click on SignOff Button image", "snapshot=Action_47.inf");
	lr_end_transaction("T34_WT3_SignOut",0);
	truclient_step("48", "Verify administration 's 'Visible Text' Contain administration", "snapshot=Action_48.inf");
}
