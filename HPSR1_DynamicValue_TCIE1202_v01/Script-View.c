//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Script_View_Action()
{
	/* This file has error in step 5 to eval js innerhtml */
	truclient_step("2", "Navigate to 'C:\\LoadRunner\\HPSR1_w...amic_value.html'", "snapshot=Action_2.inf");
	truclient_step("3", "Verify Generate 's 'Visible Text' Contain Generate", "snapshot=Action_3.inf");
	truclient_step("4", "Click on Generate button", "snapshot=Action_4.inf");
	truclient_step("5", "Evaluate JavaScript code window.generated_data = ...nerated_data );", "snapshot=Action_5.inf");
}
