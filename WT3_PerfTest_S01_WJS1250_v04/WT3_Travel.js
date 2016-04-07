function WT3_Travel()
{

	web.regFind(
		{
				text : 'Find Flight', saveCount: 'departDate_isfound' , search : 'Body'
		}
	);
		

	web.regSaveParamEx(
		{
			paramName : 'departDate', 
			lb : 'name=\"departDate\" value=\"', 
			rb : '\"', 
			scope : 'Body', 
			requestUrl : '*/reservations.pl*'
		}
	);


/*Correlation comment - Do not change!  Original value='02/07/2016' Name ='returnDate' Type ='RecordReplay'*/
	web.regSaveParamEx(
		{
			paramName : 'returnDate', 
			lb : 'name=\"returnDate\" value=\"', 
			rb : '\"', 
			scope : 'Body', 
			requestUrl : '*/reservations.pl*'
		}
	);

lr.startTransaction('WT3_T22_Travel_Search_Flight');

	web.image(
		{
			name : 'Search Flights Button', 
			alt : 'Search Flights Button', 
			snapshot : 't3.inf'
		}
	);
	
	
//	lr.outputMessage("Your Depart  " + lr.evalString( "{FindFlight_Count}" ));


	lr.endTransaction('WT3_T22_Travel_Search_Flight', lr.AUTO);

	lr.thinkTime(33);
	lr.startTransaction('WT3_T23_Travel_Flight_Lookup');

	web.regFind(
		{
			text : 'Flight departing from', search : 'Body'
		}
	);

	web.regSaveParamEx(
		{
			paramName : 'outboundFlight', 
			lb : 'name=\"outboundFlight\" value=\"', 
			rb : '\" checked', 
			scope : 'Body', 
			ignoreRedirections : 'No'
		}
	);

	web.submitForm(
		{
			name : 'reservations.pl', 
			snapshot : 't4.inf', 
			itemData : 
				[
					{ name : 'depart', value : '{WT3_Flights_DepartCity}' }, 
					{ name : 'departDate', value : '{departDate}' }, 
					{ name : 'arrive', value : '{WT3_Flights_ArriveCity}' }, 
					{ name : 'returnDate', value : '{returnDate}' }, 
					{ name : 'numPassengers', value : '1' }, 
					{ name : 'roundtrip', value : '<OFF>' }, 
					{ name : 'seatPref', value : 'None' }, 
					{ name : 'seatType', value : 'Coach' }, 
					{ name : 'findFlights.x', value : '56' }, 
					{ name : 'findFlights.y', value : '8' }
				]
		}
	);

	lr.endTransaction('WT3_T23_Travel_Flight_Lookup', lr.AUTO);

	lr.startTransaction('WT3_T24_Find_Flight');

	web.regFind(
		{
			text : 'Payment Details', search : 'Body'
		}
	);

	web.submitForm(
		{
			name : 'reservations.pl_2', 
			snapshot : 't5.inf', 
			itemData : 
				[
					{ name : 'outboundFlight', value : '{outboundFlight}' }, 
					{ name : 'reserveFlights.x', value : '31' }, 
					{ name : 'reserveFlights.y', value : '9' }
				]
		}
	);

	lr.endTransaction('WT3_T24_Find_Flight', lr.AUTO);

	lr.startTransaction('WT3_T25_Travel_Payment_Details');

	web.regFind(
		{
			text : 'Invoice', search : 'Body'
		}
	);

	web.submitForm(
		{
			name : 'reservations.pl_3', 
			snapshot : 't6.inf', 
			itemData :  [
				{name : 'firstName', value : 'jojo'},
				{name : 'lastName', value : 'Bean'},
				{name : 'address1', value : ''},
				{name : 'address2', value : ''},
				{name : 'pass1', value : 'jojo Bean'},
				{name : 'creditCard', value : ''},
				{name : 'expDate', value : ''},
				{name : 'saveCC', value : '<OFF>'},
				{name : 'buyFlights.x', value : '64'},
				{name : 'buyFlights.y', value : '11'}
			]
		}
	);

	lr.endTransaction('WT3_T25_Travel_Payment_Details', lr.AUTO);

	lr.startTransaction('WT3_T33_Travel_Check_Itinerary');

	web.regFind(
		{
			text : 'Itinerary', search : 'Body'
		}
	);

	web.image(
		{
			name : 'Itinerary Button', 
			alt : 'Itinerary Button', 
			ordinal : '1', 
			snapshot : 't7.inf'
		}
	);

	lr.endTransaction('WT3_T33_Travel_Check_Itinerary', lr.AUTO);

	lr.startTransaction('WT3_T08_SignOut');


	web.image(
		{
			name : 'SignOff Button', 
			alt : 'SignOff Button', 
			ordinal : '1', 
			snapshot : 't8.inf'
		}
	);

	lr.endTransaction('WT3_T08_SignOut', lr.AUTO);

	return 0;
}
