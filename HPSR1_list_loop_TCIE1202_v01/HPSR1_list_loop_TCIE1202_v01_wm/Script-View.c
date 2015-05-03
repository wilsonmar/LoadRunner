//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Script_View_Init()
{
	truclient_step("1", "If ( false )", "snapshot=Init_1.inf");
	{
		truclient_step("1.1", "Navigate to 'C:\\TruClient\\Tutorial...te\\links.html '", "snapshot=Init_1.1.inf");
	}
	truclient_step("2", "If ( false )", "snapshot=Init_2.inf");
	{
		truclient_step("2.1", "Navigate to http://stormhelp.saas.hp.../html/links.html", "snapshot=Init_2.1.inf");
	}
}

Script_View_A1_EvalXPathMatchParam()
{
	truclient_step("1", "If ( true )", "snapshot=A1_EvalXPathMatchParam_1.inf");
	{
		truclient_step("1.1", "Navigate to http://stormhelp.saas.hp.../html/links.html", "snapshot=A1_EvalXPathMatchParam_1.1.inf");
	}
	truclient_step("2", "For ( var i = 1 ; i < 2 ; i++ )", "snapshot=A1_EvalXPathMatchParam_2.inf");
	{
		truclient_step("2.1", "Click on Link 1 this is an examp... link", "snapshot=A1_EvalXPathMatchParam_2.1.inf");
		truclient_step("2.2", "Evaluate JavaScript code LR.advanceParam('LinkText');", "snapshot=A1_EvalXPathMatchParam_2.2.inf");
		truclient_step("2.3", "Click on Back to Links page link", "snapshot=A1_EvalXPathMatchParam_2.3.inf");
	}
}

Script_View_A2_EvalXPathArgsContext()
{
	truclient_step("1", "Navigate to 'http://stormhelp.saas.h...html/links.html'", "snapshot=A2_EvalXPathArgsContext_1.inf");
	truclient_step("2", "For ( var i = 1 ; i < 2 ; i++ )", "snapshot=A2_EvalXPathArgsContext_2.inf");
	{
		truclient_step("2.1", "Click on Link 1 this is an examp... link", "snapshot=A2_EvalXPathArgsContext_2.1.inf");
		truclient_step("2.2", "Click on Back to Links page link", "snapshot=A2_EvalXPathArgsContext_2.2.inf");
	}
}

Script_View_A3_EvalXPath_DOM_ArgsContext()
{
	truclient_step("1", "Navigate to 'http://stormhelp.saas.h...html/links.html'", "snapshot=A3_EvalXPath_DOM_ArgsContext_1.inf");
	truclient_step("2", "For ( var i = 1 ; i < 2 ; i++ )", "snapshot=A3_EvalXPath_DOM_ArgsContext_2.inf");
	{
		truclient_step("2.1", "Click on Link 1 this is an examp... link", "snapshot=A3_EvalXPath_DOM_ArgsContext_2.1.inf");
		truclient_step("2.2", "Click on Back to Links page link", "snapshot=A3_EvalXPath_DOM_ArgsContext_2.2.inf");
	}
}

Script_View_A4_Descriptors_Editor()
{
	truclient_step("1", "Navigate to 'C:\\LoadRunner\\HPSR1\\links.html'", "snapshot=A4_Descriptors_Editor_1.inf");
	truclient_step("2", "If ( true )", "snapshot=A4_Descriptors_Editor_2.inf");
	{
		truclient_step("2.1", "For ( var i = 1 ; i < 2 ; i++ )", "snapshot=A4_Descriptors_Editor_2.1.inf");
		{
			truclient_step("2.1.1", "Click on Link 1 this is an examp... link", "snapshot=A4_Descriptors_Editor_2.1.1.inf");
			truclient_step("2.1.2", "Click on Back to Links page link", "snapshot=A4_Descriptors_Editor_2.1.2.inf");
		}
	}
}
