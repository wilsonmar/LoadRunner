Travel()
{
	return 0;
}
Travel_functions()
{
	// call from within	Action.c.

	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("ChangeProfile",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T04_Select_My_System_Profile","pTransName");
//		rc=T04_Select_My_System_Profile();
	}


	if( stricmp("All",LPCSTR_RunType ) == FOUND
	||  stricmp("Personalize",LPCSTR_RunType ) == FOUND 
    ){
		lr_save_string("T06_Select_My_Personalizations","pTransName");
//		rc=T06_Select_My_Personalizations();
	}


	return 0;
}
