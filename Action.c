Action()
{
	int rc=LR_PASS;
	
	// All or LogInOut or LandingOnly
	//	lr_save_string("T01_URL_Landing" ,"pTransSequence");
		rc=T01_URL_Landing();

	// All or LogInOut
		rc=T02_Login();

	// All or ChangeProfile
		rc=T04_Select_My_System_Profile();
/*
	// All or Personalize
		rc=T06_Select_My_Personalizations();

	// All
		rc=T07_Home();

	// All or LogInOut
		rc=T08_Sign_out();
*/
	return 0;
}
