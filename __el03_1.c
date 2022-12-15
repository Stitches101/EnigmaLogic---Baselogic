
//Enigma Block EL03_01: AHU system
//**********************************************************************************************************************************************//
//Main Function - AHU Management System
//**********************************************************************************************************************************************//
void el03_1_libenigma01(EL03_1_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0;
	FL in37 = 0, in38 = 0, in39 = 0, in40 = 0, in41 = 0, in42 = 0, in43 = 0, in44 = 0, in45 = 0, in46 = 0, in47 = 0;
	BIT in10 = 0, in11 = 0, in12 = 0, in13 = 0, in14 = 0, in15 = 0, in16 = 0, in17 = 0, in18 = 0, in19 = 0, in20 = 0,
		in21 = 0, in22 = 0, in23 = 0, in24 = 0, in25 = 0, in26 = 0, in27 = 0, in28 = 0, in29 = 0, in30 = 0, in31 = 0,
		in32 = 0, in33 = 0, in34 = 0, in35 = 0, in36 = 0, in49 = 0, in50 = 0;
	UI in48 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou10 = 0;
	BIT ou11 = 0, ou12 = 0, ou13 = 0, ou14 = 0, ou15 = 0, ou16 = 0;
	FL ou17 = 0, ou18 = 0, ou19 = 0, ou20 = 0, ou21 = 0, ou22 = 0, ou23 = 0, ou24 = 0, ou25 = 0, ou26 = 0, ou27 = 0,
		ou28 = 0, ou29 = 0, ou30 = 0, ou31 = 0, ou32 = 0, ou33 = 0, ou34 = 0, ou35 = 0, ou36 = 0, ou37 = 0, ou38 = 0, ou39 = 0, ou40 = 0;

	//Variable Local
	//**************************************************************************//
	UI status = 0, ias = 0;
	FL gr01 = 0, gr02 = 0, grmin = 0, grmax = 0;

	BIT x50 = 0, x51 = 0, x52 = 0, x54 = 0, x55 = 0, x56 = 0;//x == input
	BIT y50 = 0, y51 = 0, y52 = 0, y53 = 0, y54 = 0;//y == output
	BIT tvv = 0, avv = 0, skcv = 0, skgkw = 0, pumpvg = 0, pumptcvg = 0;//reset

	FL nu01 = 0;
	FL tvs = 0, avs = 0, tvk = 0, abk = 0, meng = 0, wtw = 0, racv = 0, ragkw = 0, pump = 0, pumptc = 0;//variables
	FL flow = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21, in22 = *io->Input22, in23 = *io->Input23, in24 = *io->Input24, in25 = *io->Input25, in26 = *io->Input26, in27 = *io->Input27, in28 = *io->Input28, in29 = *io->Input29, in30 = *io->Input30,
		in31 = *io->Input31, in32 = *io->Input32, in33 = *io->Input33, in34 = *io->Input34, in35 = *io->Input35, in36 = *io->Input36, in37 = *io->Input37, in38 = *io->Input38, in39 = *io->Input39, in40 = *io->Input40,
		in41 = *io->Input41, in42 = *io->Input42, in43 = *io->Input43, in44 = *io->Input44, in45 = *io->Input45, in46 = *io->Input46, in47 = *io->Input47, in48 = *io->Input48, in49 = *io->Input49, in50 = *io->Input50;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16, ou17 = *io->Output17, ou18 = *io->Output18, ou19 = *io->Output19, ou20 = *io->Output20,
		ou21 = *io->Output21, ou22 = *io->Output22, ou23 = *io->Output23, ou24 = *io->Output24, ou25 = *io->Output25, ou26 = *io->Output26, ou27 = *io->Output27, ou28 = *io->Output28, ou29 = *io->Output29, ou30 = *io->Output30,
		ou31 = *io->Output31, ou32 = *io->Output32, ou33 = *io->Output33, ou34 = *io->Output34, ou35 = *io->Output35, ou36 = *io->Output36, ou37 = *io->Output37, ou38 = *io->Output38, ou39 = *io->Output39, ou40 = *io->Output40;

	 
	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
		*io->__s31 = 0, *io->__s32 = 0, *io->__s33 = 0, *io->__s34 = 0, *io->__s35 = 0, *io->__s36 = 0, *io->__s37 = 0, *io->__s38 = 0, *io->__s39 = 0, *io->__s40 = 0;
		*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0, *io->__r05 = 0, *io->__r06 = 0, *io->__r07 = 0, *io->__r08 = 0, *io->__r09 = 0, *io->__r10 = 0;
	}
	//Reset System
	//**************************************************************************//
	if (in18 ==1)
	{
		*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0, *io->__r05 = 0, *io->__r06 = 0, *io->__r07 = 0, *io->__r08 = 0, *io->__r09 = 0, *io->__r10 = 0;
	}


	//IAS Status Input
	//**************************************************************************//
	ias = in48;

	//IAS Switch
	//**************************************************************************//
	switch (ias)
	{
	case 1://Peakload Heat
		x51 = 1, x52 = 0, x54 = 1;
		break;

	case 2://Heat
		x51 = 1, x52 = 0, x54 = 1;
		break;

	case 3://Neutral
		if (in50 == 1)
		{
			if (in08>=10)
			{
				x51 = 0, x52 = 1, x54 = 1;
			}
			else
			{
				x51 = 1, x52 = 0, x54 = 1;
			}
		}
		else
		{
			x51 = 1, x52 = 1, x54 = 1;
		}
		break;

	case 4://Cool
		x51 = 0, x52 = 1, x54 = 1;
		break;

	case 5://Peakload Cool
		x51 = 0, x52 = 1, x54 = 1;
		break;

	case 6://Load Heat
		x51 = 0, x52 = 1, x54 = 1;
		break;

	case 7://Load Cool
		x51 = 1, x52 = 0, x54 = 1;

	default:
		x51 = 0, x52 = 0, x54 = 0;
		break;
	}

	//System Status
	//**************************************************************************//
	if (in16 == 0 || *io->__r01 == 1)
	{
		status = 1;
		*io->__r01 = 1;
	}
	else if (in17 == 1 || *io->__r02 == 1)
	{
		status = 2;
		*io->__r02 = 1;
	}
	else if (in19 == 1 || *io->__r03 == 1)
	{
		status = 3;
		*io->__r03 = 1;
	}
	else if (in49 == 1 || *io->__r04 == 1)
	{
		status = 4;
		*io->__r04 = 1;
	}
	else if (in20 == 1)
	{
		status = 5;
	}
	else if (in21 == 1)
	{
		status = 6;
	}
	else
	{
		status = 0;
	}

	//System Switch
	//**************************************************************************//
	switch (status)
	{
	case 1://Fire Status
		ou25 = status;
		x56 = 1;
		if (in12 == 1 && (in13 == 0 && in14 == 0 && in15 == 0))//SVE H
		{
			tvs = 100, avs = 0, tvk = 100, abk = 0, meng = 0, wtw = 0;
			racv = in07, ragkw = in08, pump = 100, pumptc = in06;
			tvv = 1, avv = 0, skcv = 1, skgkw = 1, pumpvg = 1, pumptcvg = 1;
			flow = 100;
			x50 = 0, x51 = 1, x52 = 0, x54 = 1, x55 = 0;
		}
		else if (in13 == 1 && (in12 == 0 && in14 == 0 && in15 == 0))//SVE 0
		{
			tvs = 0, avs = 0, tvk = in44, abk = 0, meng = 0, wtw = 0;
			racv = in07, ragkw = in08, pump = 100, pumptc = in06;
			tvv = 0, avv = 0, skcv = 1, skgkw = 1, pumpvg = 1, pumptcvg = 1;
			flow = 100;
			x50 = 0, x51 = 1, x52 = 0, x54 = 1, x55 = 0;
		}
		else if (in14 == 1 && (in12 == 0 && in13 == 0 && in15 == 0))//EVE H
		{
			tvs = 0, avs = 100, tvk = 0, abk = 100, meng = 0, wtw = 0;
			racv = in07, ragkw = in08, pump = 100, pumptc = in06;
			tvv = 0, avv = 1, skcv = 1, skgkw = 1, pumpvg = 1, pumptcvg = 1;
			flow = 100;
			x50 = 0, x51 = 1, x52 = 0, x54 = 1, x55 = 0;
		}
		else if (in15 == 1 && (in12 == 0 && in13 == 0 && in14 == 0))//EVE 0
		{
			tvs = 0, avs = 100, tvk = 0, abk = in45, meng = 0, wtw = 0;
			racv = in07, ragkw = in08, pump = 100, pumptc = in06;
			tvv = 0, avv = 0, skcv = 1, skgkw = 1, pumpvg = 1, pumptcvg = 1;
			flow = 100;
			x50 = 0, x51 = 1, x52 = 0, x54 = 1, x55 = 0;
		}
		else//Fire Status
		{
			tvs = 0, avs = 0, tvk = 0, abk = 0, meng = 0, wtw = 0;
			racv = in07, ragkw = in08, pump = 100, pumptc = in06;
			tvv = 0, avv = 0, skcv = 1, skgkw = 1, pumpvg = 1, pumptcvg = 1;
			flow = 100;
			x50 = 0, x51 = 1, x52 = 0, x54 = 1, x55 = 0;
		}
		break;
	
	case 2://Maintenance Status
		ou25 = status;
		tvs = 0, avs = 0, tvk = 0, abk = 0, meng = 100, wtw = 0;
		racv = 0, ragkw = 0, pump = 0, pumptc = 0;
		tvv = 0, avv = 0, skcv = 0, skgkw = 0, pumpvg = 0, pumptcvg = 0;
		flow = 100;
		x50 = 0, x51 = 0, x52 = 0, x54 = 0, x55 = 0, x56 = 1;
		break;
	case 3://Water Pressure Status
		ou25 = status;
		tvs = 0, avs = 0, tvk = 0, abk = 0, meng = 100, wtw = 0;
		racv = 0, ragkw = 0, pump = 0, pumptc = 0;
		tvv = 0, avv = 0, skcv = 0, skgkw = 0, pumpvg = 0, pumptcvg = 0;
		flow = 100;
		x50 = 0, x51 = 0, x52 = 0, x54 = 0, x55 = 0, x56 = 1;
		break;

	case 4://Frost Status
		ou25 = status;
		tvs = 0, avs = 0, tvk = 0, abk = 0, meng = 100, wtw = 100;
		racv = 100, ragkw = 0, pump = 100, pumptc = 100;
		tvv = 0, avv = 0, skcv = 1, skgkw = 0, pumpvg = 1, pumptcvg = 1;
		flow = 100;
		x50 = 0, x51 = 0, x52 = 0, x54 = 0, x55 = 0, x56 = 1;
		break;

	case 5://Normal operation Mode Status
		ou25 = status;
		tvs = in01, avs = in02, tvk = in03, abk = in04, meng = in05, wtw = in06;
		racv = in07, ragkw = in08, pump = 100, pumptc = in06;
		tvv = in10, avv = in11, skcv = 1, skgkw = 1, pumpvg = 1, pumptcvg = 1;
		flow = in43;
		x50 = 1, x55 = 0, x56 = 0;
		break;

	case 6://Optimalisation Mode Status
		ou25 = status;
		tvs = in46, avs = in47, tvk = in03, abk = in04, meng = in05, wtw = in06;
		racv = in07, ragkw = in08, pump = 100, pumptc = in06;
		tvv = 1, avv = 1, skcv = 1, skgkw = 1, pumpvg = 1, pumptcvg = 1;
		flow = in43;
		x50 = 1, x55 = 1, x56 = 0;
		break;

	default:
		ou25 = status;
		tvs = 0, avs = 0, tvk = 0, abk = 0, meng = 100, wtw = 0;
		racv = 0, ragkw = 0, pump = 0, pumptc = 0;
		tvv = 0, avv = 0, skcv = 0, skgkw = 0, pumpvg = 0, pumptcvg = 0;
		flow = in43;
		x50 = 0, x51 = 0, x52 = 0, x54 = 0, x55 = 0, x56 = 0;
		break;
	}

	//Release VENT
	//**************************************************************************//
	timeSwitch(&x50, &in37, &in38, &ou31, &ou32, &y50, io->__s01, io->__s02, io->__s03);//VENT
	if (x50 == 1 && y50 ==0)
	{
		tvs = 0, avs = 0;
		tvv = 0, avv = 0;
	}
	else if (x50 == 0 && y50 == 1 && x56 == 0)
	{
		tvs = in01, avs = in02;
		tvv = in10, avv = in11;
	}
	//Release VENT OPT
	//**************************************************************************//
	else if (x50 == 1 && x55 == 1 && y50 == 0)
	{
		tvs = 0, avs = 0;
		tvv = 0, avv = 0;
	}
	else if (x55 == 0 && y50 == 1 && x56 == 1)
	{
		tvs = 0, avs = 0;
		tvv = 0, avv = 0;
	}
	//Release Heat Water Valve
	//**************************************************************************//
	timeSwitch(&x51, &in39, &in40, &ou33, &ou34, &y51, io->__s04, io->__s05, io->__s06);//Heat WATER VALVE
	if (x51 == 1 && y51 ==0)
	{
		racv = 0;
		skcv = 0;
	}
	else if (x51 == 0 && y51 == 1 && x56 == 0)
	{
		racv = in07;
		skcv = 1;
	}
	//Releas Cool Water Valve
	//**************************************************************************//
	timeSwitch(&x52, &in39, &in40, &ou35, &ou36, &y52, io->__s07, io->__s08, io->__s09);//Cool WATER VALVE
	if (x52 == 1 && y52 == 0)
	{
		ragkw = 0;
		skgkw = 0;
	}
	else if (x52 == 0 && y52 == 1 && x56 == 0)
	{
		ragkw = in08;
		skgkw = 1;
	}
	//Release PUMP
	//**************************************************************************//
	timeSwitch(&y51, &in41, &in42, &ou37, &ou38, &y53, io->__s10, io->__s11, io->__s12);// PUMP
	if (y51 == 1 && y53 == 0)
	{
		pump = 0;
		pumpvg = 0;
	}
	else if (y51 == 0 && y53 == 1 && x56 == 0)
	{
		pump = 100;
		pumpvg = 1;
	}
	//Releas PUMPTC
	//**************************************************************************//
	timeSwitch(&x54, &in41, &in42, &ou39, &ou40, &y54, io->__s13, io->__s14, io->__s15);//PUMPTC
	if (x54 == 1 && y54 == 0)
	{
		pumptc = 0;
		pumptcvg = 0;
	}
	else if (x54 == 0 && y54 == 1 && x56 == 0)
	{
		pumptc = in06;
		pumptcvg = 1;
	}
	






	//Status SVE
	//**************************************************************************//
	statusOutput(&tvv, &in27, &in22, &in32, &ou26, io->__s16);

	//Status EVE
	//**************************************************************************//
	statusOutput(&avv, &in28, &in23, &in33, &ou27, io->__s17);

	//Status ER
	//**************************************************************************//
	statusOutput(&pumptcvg, &in29, &in24, &in34, &ou28, io->__s18);

	//Status PUMP
	//**************************************************************************//
	statusOutput(&pumpvg, &in30, &in25, &in35, &ou29, io->__s19);

	//Status PUMPTC
	//**************************************************************************//
	statusOutput(&pumptcvg, &in31, &in26, &in36, &ou30, io->__s20);

	//Flow Outputs
	//**************************************************************************//

	flowOutput(&tvs, &flow, &ou01, io->__s30);
	flowOutput(&avs, &flow, &ou02, io->__s31);
	flowOutput(&tvk, &flow, &ou03, io->__s32);
	flowOutput(&abk, &flow, &ou04, io->__s33);
	flowOutput(&meng, &flow, &ou05, io->__s34);
	flowOutput(&wtw, &flow, &ou06, io->__s35);
	flowOutput(&racv, &flow, &ou07, io->__s36);
	flowOutput(&ragkw, &flow, &ou08, io->__s37);
	flowOutput(&pump, &flow, &ou09, io->__s38);
	flowOutput(&pumptc, &flow, &ou10, io->__s39);





	//Grafic SVE
	//**************************************************************************//

	gr01 = 12;
	gr02 = 15,3;
	grmin = 0;
	grmax = 100;

	//Grafic SVE
	//**************************************************************************//
	twoRamp(&ou01, &flow, &grmin, &grmin, &grmax, &gr01, &nu01, &ou17, io->__s21);

	//Grafic EVE
	//**************************************************************************//
	twoRamp(&ou02, &flow, &grmin, &grmin, &grmax, &gr01, &nu01, &ou18, io->__s22);

	//Grafic FAV
	//**************************************************************************//
	twoRamp(&ou03, &flow, &grmin, &grmin, &grmax, &gr02, &nu01, &ou19, io->__s23);

	//Grafic EAV
	//**************************************************************************//
	twoRamp(&ou04, &flow, &grmin, &grmin, &grmax, &gr02, &nu01, &ou20, io->__s24);

	//Grafic RCAV
	//**************************************************************************//
	twoRamp(&ou05, &flow, &grmin, &grmin, &grmax, &gr02, &nu01, &ou21, io->__s25);

	//Grafic ER
	//**************************************************************************//
	twoRamp(&ou06, &flow, &grmin, &grmin, &grmax, &gr01, &nu01, &ou22, io->__s26);

	//Grafic Heat Valve
	//**************************************************************************//
	twoRamp(&ou07, &flow, &grmin, &grmin, &grmax, &gr01, &nu01, &ou23, io->__s27);

	//Write Cool Valve
	//**************************************************************************//
	twoRamp(&ou08, &flow, &grmin, &grmin, &grmax, &gr01, &nu01, &ou24, io->__s28);


	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16, *io->Output17 = ou17, *io->Output18 = ou18, *io->Output19 = ou19, *io->Output20 = ou20,
		*io->Output21 = ou21, *io->Output22 = ou22, *io->Output23 = ou23, *io->Output24 = ou24, *io->Output25 = ou25, *io->Output26 = ou26, *io->Output27 = ou27, *io->Output28 = ou28, *io->Output29 = ou29, *io->Output30 = ou30,
		*io->Output31 = ou31, *io->Output32 = ou32, *io->Output33 = ou33, *io->Output34 = ou34, *io->Output35 = ou35, *io->Output36 = ou36, *io->Output37 = ou37, *io->Output38 = ou38, *io->Output39 = ou39, *io->Output40 = ou40;
}



//Enigma Block EL03_02: Heat Cold Storrage
//**********************************************************************************************************************************************//
//Main Function - Heat Cold Storrage System
//**********************************************************************************************************************************************//
void el03_2_libenigma01(EL03_2_LIBENIGMA01 *io)
{
	//Variable Input
//**************************************************************************//
	FL in01 = 0, in02 = 0, in04 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in10 = 0,
		in11 = 0, in12 = 0, in13 = 0, in14 = 0, in15 = 0, in16 = 0, in17 = 0, in18 = 0, in19 = 0, in20 = 0,
		in21 = 0, in22 = 0, in23 = 0, in24 = 0, in25 = 0, in26 = 0, in27 = 0, in28 = 0, in29 = 0, in30 = 0,
		in31 = 0, in32 = 0, in35 = 0, in36 = 0, in37 = 0, in38 = 0, in39 = 0, in46 = 0;

	BIT in40 = 0, in41 = 0, in42 = 0, in43 = 0, in44 = 0, in45 = 0;
	
	ULI  in03 = 0, in05 = 0, in33 = 0, in34 = 0;
	//Variable Output
	//**************************************************************************//
	FL ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou18 = 0, ou19 = 0, ou20 = 0, ou28 = 0, ou29 = 0, ou38 = 0, ou39 = 0, ou40 = 0;

	ULI ou01 = 0, ou02 = 0, ou22 = 0, ou23 = 0, ou33 = 0, ou34 = 0, ou35 = 0, ou36 = 0;

	BIT ou08 = 0, ou09 = 0, ou10 = 0, ou11 = 0, ou12 = 0, ou13 = 0, ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 0, ou21 = 0, ou24 = 0, ou25 = 0, ou26 = 0, ou27 = 0, ou30 = 0, ou31 = 0, ou32 = 0, ou37 = 0;


	//Variable Local
	//**************************************************************************//

	

	BIT x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0, x14 = 0, x15 = 0, x16 = 0, x17 = 0, x18 = 0, x19 = 0;
	
	ULI x08 = 0, x09 = 0, x10 = 0, x11 = 0, x12 = 0, x13 = 0;

	FL gr01 = 0;
	FL gr02 = 0;
	FL grmin = 0;
	FL grmax = 0;
	FL flow = 0;
	FL nu01 = 0;
	FL a01 = 0, a02 = 0, a03 = 0, a04 = 0, a05 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21, in22 = *io->Input22, in23 = *io->Input23, in24 = *io->Input24, in25 = *io->Input25, in26 = *io->Input26, in27 = *io->Input27, in28 = *io->Input28, in29 = *io->Input29, in30 = *io->Input30,
		in31 = *io->Input31, in32 = *io->Input32, in33 = *io->Input33, in34 = *io->Input34, in35 = *io->Input35, in36 = *io->Input36, in37 = *io->Input37, in38 = *io->Input38, in39 = *io->Input39, in40 = *io->Input40,
		in41 = *io->Input41, in42 = *io->Input42, in43 = *io->Input43, in44 = *io->Input44, in45 = *io->Input45, in46 = *io->Input46;

		ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16, ou17 = *io->Output17, ou18 = *io->Output18, ou19 = *io->Output19, ou20 = *io->Output20,
		ou21 = *io->Output21; ou22 = *io->Output22, ou23 = *io->Output23, ou24 = *io->Output24, ou25 = *io->Output25, ou26 = *io->Output26, ou27 = *io->Output27, ou28 = *io->Output28, ou29 = *io->Output29, ou30 = *io->Output30,
		ou31 = *io->Output31; ou32 = *io->Output32, ou33 = *io->Output33, ou34 = *io->Output34, ou35 = *io->Output35, ou36 = *io->Output36, ou37 = *io->Output37, ou38 = *io->Output38, ou39 = *io->Output39, ou40 = *io->Output40;


	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
			*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
			*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
			*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
			*io->__s31 = 0, *io->__s32 = 0;
			*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0;
	}


	//Reset System
	//**************************************************************************//
	if (in41 == 1 || ou17 == 1 || ou30 == 1)
	{
		*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0;
		x04 = 1, x05 = 1;

	}
	else
	{
		x04 = 0, x05 = 0;

	}


	//Release Load - Unload Cold Storage
	//**************************************************************************//
	(in01 >= in02 && ou15 == 0) ? (x16 = 1) : (x16 = 0);
	(in39 >= in04 && ou14 == 0) ? (x17 = 1) : (x17 = 0);
	
	(ou17 == 0 && ou30 == 0 && ou16 == 0 && x16 == 1) ? (ou14 = 1) : (ou14 = 0);
	(ou17 == 0 && ou30 == 0 && ou16 == 0 && x17 == 1) ? (ou15 = 1) : (ou15 = 0);

	(ou14 == 1 || ou16 == 1) ? (ou37 = 1) : (ou37 = 0);

	(in43 == 1 & in44 == 1 && ou15 == 1) ? (x14 = 1) : (x14 = 0);
	(in42 == 1 & in45 == 1 && ou14 == 1) ? (x15 = 1) : (x15 = 0);

	timeSwitch2(&x14, &in03, &in03, &ou01, &ou22, &ou12, &ou24, &ou26, io->__s01, io->__s02, io->__s03);
	timeSwitch2(&x15, &in05, &in05, &ou02, &ou23, &ou11, &ou25, &ou27, io->__s04, io->__s05, io->__s06);

	/*
	in01 = bit release
	in02 = uli time delay up
	in03 = uli time delay down
	ou01 = uli rest time delay up
	ou02 = uli rest time delay down
	ou03 = bit release
	ou04 = bit release up
	ou05 = bit release down

	mem01 = uli
	mem02 = uli 
	mem03 = bit
	*/


	//Temperature offset PI  controller load and unload flow
	//**************************************************************************//
	ou19 = in38 + in06;
	ou28 = in17 - in18;

	//Pressure and Frequence system Load Cold Storage
	//**************************************************************************//
	twoRamp(&in07, &in12, &in08, &in09, &in10, &in11, &nu01, &ou03, io->__s07);

	FL f01 = 0;
	FL f03 = 0;
	(ou14 == 1) ? (f01 = in14) : (f01 = 0);

	twoRamp(&in07, &in12, &in13, &f01, &in15, &in16, &nu01, &ou04, io->__s08);

	a01 = ((in14 / in16) * 100);
	a02 = ((in16 / in46) * 100);
	(ou14 == 1) ? (f03 = a01) : (f03 = 0);
	twoRamp(&in07, &in12, &in13, &f03, &in15, &a02, &nu01, &ou38, io->__s25);
	//Pressure and Frequence system Unoad Cold Storage
	//**************************************************************************//
	twoRamp(&in19, &in24, &in20, &in21, &in22, &in23, &nu01, &ou05, io->__s09);

	FL f02 = 0;
	FL f04 = 0;
	(ou15 == 1) ? (f02 = in26) : (f02 = 0);
	twoRamp(&in19, &in24, &in25, &f02, &in27, &in28, &nu01, &ou06, io->__s10);

	a03 = ((in26 / in28) * 100);
	a04 = ((in28 / in46) * 100);
	(ou15 == 1) ? (f04 = a03) : (f04 = 0);
	twoRamp(&in19, &in24, &in25, &f04, &in27, &a04, &nu01, &ou39, io->__s26);

	//Restmode
	//**************************************************************************//
	(ou12 == 0 && ou11 == 0 && x16 == 0 && x17 == 0) ? (x03 = 1) : (x03 = 0);

	ULI t01 = 0;
	ULI t03 = 0;
	t01 = 300;
	t03 = 10;
	ULI tr01 = 0, tr02 = 0;
	BIT b01 = 0, b02 = 0;
	timeSwitch2(&x03, &t03, &t01, &tr01, &tr02, &ou16, &b01, &b02, io->__s11, io->__s12, io->__s13);

	//Draining
	//**************************************************************************//
	*io->__s15 = 0;
	x08 = (in33 * 3600);
	x09 = (in34 * 3600);

	timeSwitchBit3(&ou12, &x08, &x04, &x10, &ou08, io->__s16, io->__s17);
	timeSwitchBit3(&ou11, &x08, &x05, &x11, &ou31, io->__s18, io->__s19);
	timeSwitchBit3(&ou12, &x09, &x04, &x12, &ou09, io->__s20, io->__s21);
	timeSwitchBit3(&ou11, &x09, &x05, &x13, &ou32, io->__s22, io->__s23);

	ou33 = (x11 / 3600);
	ou34 = (x13 / 3600);
	ou35 = (x10 / 3600);
	ou36 = (x12 / 3600);

	(ou08 == 1) ? (*io->__r01 = 1) : (*io->__r01);
	(ou31 == 1) ? (*io->__r02 = 1) : (*io->__r02);
	(ou09 == 1) ? (*io->__r03 = 1) : (*io->__r03);
	(ou32 == 1) ? (*io->__r04 = 1) : (*io->__r04);

	(ou09 == 1 && ou16 == 1) ? (x18 = 1) : (x18 = 0);
	(ou32 == 1 && ou16 == 1) ? (x19 = 1) : (x19 = 0);

	ULI t02 = 0;
	t02 = 300;
	ULI tr03 = 0, tr04 = 0;
	BIT b03 = 0, b04 = 0;
	timeSwitch2(&x18, &t02, &t02, &tr03, &tr04, &ou17, &b03, &b04, io->__s27, io->__s28, io->__s29);
	ULI tr05 = 0, tr06 = 0;
	BIT b05 = 0, b06 = 0;
	timeSwitch2(&x19, &t02, &t02, &tr05, &tr06, &ou30, &b05, &b06, io->__s30, io->__s31, io->__s32);



	/*
	in01 = bit release
	in02 = uli time delay
	in03 = bit reset
	ou01 = uli rest time delay
	ou02 = bit notification

	mem01 = uli
	mem02 = bit
	*/

	//HEATER
	//**************************************************************************//

	if (in35 < 7)
	{
		ou10 = 1;
		*io->__s24 = 1;
	}
	else if (*io->__s24 = 1 && in35 < 8)
	{
		ou10 = 1;
		*io->__s24 = 1;
	}
	else
	{
		ou10 = 0;
		*io->__s24 = 0;
	}


	//System Status
	//**************************************************************************//
	UI status = 0;
	if (in36 == 2)
	{
	status = 4;
	}
	else if (in40 == 1)
	{
		status = 5;
	}
	else if (in36 == 3)
	{
		status = 6;
	}
	else if (in36 == 4)
	{
		status = 7;
	}
	else if (in36 == 6)
	{
		status = 8;
	}
	else if (in36 == 7)
	{
		status = 9;
	}
	else if (in36 == 1 && ou14 == 1)
	{
		status = 1;
	}
	else if (in36 == 1 && ou15 == 1)
	{
		status = 2;
	}
	else if (in36 == 1 && ou16 == 1)
	{
		status = 3;
	}
	else
	{
		status = 0;
	}
	
	//System Switch
	//**************************************************************************//
	switch (status)
	{
	case 1://load cool storage
		ou18 = status;
		ou13 = 0;
		break;

	case 2://unload cool sotrage
		ou18 = status;
		ou13 = 0;
		break;
	case 3://Rest mode
		ou18 = status;
		ou13 = 0;
		break;
	case 4://System Stop
		ou18 = status;
		ou11 = 0, ou12 = 0;
		ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 0, ou30 = 0;
		ou13 = 1;
		break;
	case 5://Force Rest Mode
		ou18 = status;
		ou14 = 0, ou15 = 0, ou16 = 1, ou17 = 0, ou30 = 0;
		ou13 = 1;
		break;
	case 6://Force load cool storage
		ou18 = status;
		ou11 = 1, ou12 = 0;
		ou14 = 1, ou15 = 0, ou16 = 0, ou17 = 0, ou30 = 0;
		ou13 = 1;
		ou36 = 1;
		break;
	case 7://Force unload cool sotrage
		ou18 = status;
		ou11 = 0, ou12 = 1;
		ou14 = 0, ou15 = 1, ou16 = 0, ou17 = 0, ou30 = 0;
		ou13 = 1;
		ou36 = 0;
		break;
	case 8://Draining Cool Storage
		ou18 = status;
		ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 1, ou30 = 0;
		ou13 = 1;
		break;
	case 9://Draining Heat Storage
		ou18 = status;
		ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 0, ou30 = 1;
		ou13 = 1;
		break;
	default:
		ou18 = status;
		ou11 = 0, ou12 = 0, ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 0, ou30 = 0;
		ou13 = 1;
		break;
	}

	//Restmode
	//**************************************************************************//
	a05 = ((in32 / in46) * 100);

	if (ou16 == 1 && in42 == 1 & in45 == 1 && ou17 == 0 && ou30 == 0)
	{
		if (in29 < (in30 - in31))
		{
			ou07 = 1;
			ou29 = in32;
			ou40 = a05;
			*io->__s14 = 1;
		}
		else if (*io->__s14 == 1 && in29 < (in30 + in31))
		{
			ou07 = 1;
			ou29 = in32;
			ou40 = a05;
			*io->__s14 = 1;
		}
		else
		{
			ou07 = 0;
			ou29 = 0;
			ou40 = 0;

			*io->__s14 = 0;
		}

	}
	else
	{
		ou07 = 0;
		ou29 = 0;
		ou40 = 0;
		*io->__s14 = 0;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16, *io->Output17 = ou17, *io->Output18 = ou18, *io->Output19 = ou19, *io->Output20 = ou20,
		*io->Output21 = ou21, *io->Output22 = ou22, *io->Output23 = ou23, *io->Output24 = ou24, *io->Output25 = ou25, *io->Output26 = ou26, *io->Output27 = ou27, *io->Output28 = ou28, *io->Output29 = ou29, *io->Output30 = ou30,
		*io->Output31 = ou31, *io->Output32 = ou32, *io->Output33 = ou33, *io->Output34 = ou34, *io->Output35 = ou35, *io->Output36 = ou36, *io->Output37 = ou37, *io->Output38 = ou38, *io->Output39 = ou39, *io->Output40 = ou40;
}

//Enigma Block EL03_03: Heat Cold Storrage
//**********************************************************************************************************************************************//
//Main Function - Heat Cold Storrage Error System
//**********************************************************************************************************************************************//
void el03_3_libenigma01(EL03_3_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL  in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in10 = 0,
		in11 = 0, in13 = 0, in15 = 0, in17 = 0, in19 = 0, in20 = 0,
		in21 = 0, in23 = 0, in25 = 0, in27 = 0, in29 = 0, in30 = 0,
		in31 = 0, in32 = 0, in37 = 0,
		in41 = 0, in42 = 0, in44 = 0, in46 = 0, in48 = 0;
	

	BIT in01 = 0, in02 = 0, in03 = 0, in51 = 0, in52 = 0, in53 = 0, in34 = 0, in35 = 0, in38 = 0, in40 = 0, in50 = 0, in54 = 0, in55 = 0, in56 = 0, in57 = 0;

	ULI in04 = 0,in12 = 0, in14 = 0, in33 = 0, in16 = 0, in18 = 0, in22 = 0, in24 = 0, in26 = 0, in28 = 0, in43 = 0, in45 = 0, in47 = 0, in49 = 0,in36 = 0,in39 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou10 = 0,
		ou11 = 0, ou12 = 0, ou13 = 0, ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 0, ou18 = 0, ou19 = 0, ou20 = 0,
		ou21 = 0, ou22 = 0, ou23 = 0, ou24 = 0, ou25 = 0, ou26 = 0, ou27 = 0, ou28 = 0,
		ou44 = 0, ou45 = 0, ou46 = 0, ou47 = 0;

	ULI ou29 = 0, ou30 = 0, ou40 = 0, ou41 = 0, ou31 = 0, ou32 = 0, ou33 = 0, ou34 = 0, ou35 = 0, ou36 = 0, ou37 = 0, ou38 = 0, ou39 = 0, ou48 = 0, ou49 = 0, ou50 = 0, ou51 = 0, ou52 = 0, ou53 = 0,ou42 = 0, ou43 = 0;
	//Variable Local
	//**************************************************************************//
	BIT x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0, x08 = 0, x09 = 0, x10 = 0,
		x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0, x16 = 0, x17 = 0, x18 = 0, x19 = 0, x20 = 0,
		x21 = 0, x22 = 0, x23 = 0, x24 = 0, x25 = 0, x26 = 0, x27 = 0, x28 = 0, x29 = 0, x30 = 0;

	ULI y01 = 0, y02 = 0, y03 = 0, y04 = 0, y05 = 0, y06 = 0, y07 = 0, y08 = 0, y09 = 0, y10 = 0;

	BIT e01 = 0, e02 = 0, e03 = 0, e04 = 0, e05 = 0, e06 = 0, e07 = 0, e08 = 0;
	BIT g01 = 0, g02 = 0, g03 = 0, g04 = 0;
	ULI g05 = 0, g06 = 0;
	ULI v01 = 0, v02 = 0, v03 = 0, v04 = 0, v05 = 0, v06 = 0, v07 = 0, v08 = 0, v09 = 0, v10 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21, in22 = *io->Input22, in23 = *io->Input23, in24 = *io->Input24, in25 = *io->Input25, in26 = *io->Input26, in27 = *io->Input27, in28 = *io->Input28, in29 = *io->Input29, in30 = *io->Input30,
		in31 = *io->Input31, in32 = *io->Input32, in33 = *io->Input33, in34 = *io->Input34, in35 = *io->Input35, in36 = *io->Input36, in37 = *io->Input37, in38 = *io->Input38, in39 = *io->Input39, in40 = *io->Input40,
		in41 = *io->Input41, in42 = *io->Input42, in43 = *io->Input43, in44 = *io->Input44, in45 = *io->Input45, in46 = *io->Input46, in47 = *io->Input47, in48 = *io->Input48, in49 = *io->Input49, in50 = *io->Input50,
		in51 = *io->Input51, in52 = *io->Input52, in53 = *io->Input53, in54 = *io->Input54, in55 = *io->Input55, in56 = *io->Input56, in57 = *io->Input57;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16, ou17 = *io->Output17, ou18 = *io->Output18, ou19 = *io->Output19, ou20 = *io->Output20,
		ou21 = *io->Output21, ou22 = *io->Output22, ou23 = *io->Output23, ou24 = *io->Output24, ou25 = *io->Output25, ou26 = *io->Output26, ou27 = *io->Output27, ou28 = *io->Output28, ou29 = *io->Output29, ou30 = *io->Output30,
		ou31 = *io->Output31, ou32 = *io->Output32, ou33 = *io->Output33, ou34 = *io->Output34, ou35 = *io->Output35, ou36 = *io->Output36, ou37 = *io->Output37, ou38 = *io->Output38, ou39 = *io->Output39, ou40 = *io->Output40,
		ou41 = *io->Output41, ou42 = *io->Output42, ou43 = *io->Output43, ou44 = *io->Output44, ou45 = *io->Output45, ou46 = *io->Output46, ou47 = *io->Output47, ou48 = *io->Output48, ou49 = *io->Output49, ou50 = *io->Output50,
		ou51 = *io->Output51, ou52 = *io->Output52, ou53 = *io->Output53;
	
	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
		*io->__s31 = 0, *io->__s32 = 0, *io->__s33 = 0, *io->__s34 = 0, *io->__s35 = 0, *io->__s36 = 0, *io->__s37 = 0, *io->__s38 = 0, *io->__s39 = 0, *io->__s40 = 0;
		*io->__s41 = 0, *io->__s42 = 0, *io->__s43 = 0, *io->__s44 = 0, *io->__s45 = 0, *io->__s46 = 0, *io->__s47 = 0, *io->__s48 = 0, *io->__s49 = 0, *io->__s50 = 0;
		*io->__s51 = 0, *io->__s52 = 0, *io->__s53 = 0, *io->__s54 = 0, *io->__s55 = 0, *io->__s56 = 0, *io->__s57 = 0, *io->__s58 = 0;
		*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0, *io->__r05 = 0, *io->__r06 = 0, *io->__r07 = 0, *io->__r08 = 0, *io->__r09 = 0, *io->__r10 = 0;
	}


	//Reset System
	//**************************************************************************//
	if (in50 == 1)
	{
		*io->__r05 = 0, *io->__r06 = 0, *io->__r07 = 0, *io->__r08 = 0, *io->__r09 = 0, *io->__r10 = 0;
		*io->__s29 = 0, *io->__s30 = 0;
	}

	//Valve Error 
	//**************************************************************************//
	(in01 == 1 && in51 == 0) ? (x01 = 1) : (x01 = 0);
	(in01 == 0 && in51 == 1) ? (x15 = 1) : (x15 = 0);
	(in01 == 0 && in56 == 0) ? (x27 = 1) : (x27 = 0);
	(in01 == 1 && in56 == 1) ? (x28 = 1) : (x28 = 0);
	timeSwitchBit3(&x01, &in04, &in50, &v01, &e01, io->__s01, io->__s02);
	timeSwitchBit3(&x15, &in04, &in50, &v02, &e02, io->__s45, io->__s46);
	timeSwitchBit3(&x27, &in04, &in50, &v07, &e03, io->__s51, io->__s52);
	timeSwitchBit3(&x28, &in04, &in50, &v08, &e04, io->__s53, io->__s54);
	(x01 == 1) ? (ou29 = v01) : (ou29 = v02);
	(x27 == 1) ? (ou52 = v07) : (ou52 = v08);
	(e01 == 0 && e02 == 0) ? (ou01 = 0) : (ou01 = 1);
	(e03 == 0 && e04 == 0) ? (ou45 = 0) : (ou45 = 1);

	//Valve Error 
	//**************************************************************************//
	(in02 == 1 && in52 == 0) ? (x02 = 1) : (x02 = 0);
	(in02 == 0 && in52 == 1) ? (x16 = 1) : (x16 = 0);
	(in02 == 0 && in57 == 0) ? (x29 = 1) : (x29 = 0);
	(in02 == 1 && in57 == 1) ? (x30 = 1) : (x30 = 0);
	timeSwitchBit3(&x02, &in04, &in50, &v03, &e05, io->__s03, io->__s04);
	timeSwitchBit3(&x16, &in04, &in50, &v04, &e06, io->__s47, io->__s48);
	timeSwitchBit3(&x29, &in04, &in50, &v09, &e07, io->__s55, io->__s56);
	timeSwitchBit3(&x30, &in04, &in50, &v10, &e08, io->__s57, io->__s58);
	(x02 == 1) ? (ou40 = v03) : (ou40 = v04);
	(x29 == 1) ? (ou53 = v09) : (ou53 = v10);
	(e05 == 0 && e06 == 0) ? (ou02 = 0) : (ou02 = 1);
	(e07 == 0 && e08 == 0) ? (ou46 = 0) : (ou46 = 1);

	//Valve Error 
	//**************************************************************************//
	(in03 == 1 && in53 == 0) ? (x03 = 1) : (x03 = 0);
	(in03 == 0 && in53 == 1) ? (x17 = 1) : (x17 = 0);
	timeSwitchBit3(&x03, &in04, &in50, &v05, &ou44, io->__s05, io->__s06);
	timeSwitchBit3(&x17, &in04, &in50, &v06, &ou47, io->__s49, io->__s50);
	(x03 == 1) ? (ou41 = v05) : (ou41 = v06);



	/*
	in01 = bit release
	in02 = uli time delay
	in03 = bit reset
	ou01 = uli rest time delay
	ou02 = bit notification

	mem01 = uli
	mem02 = bit
	*/

	//Minimum and maximum Flow Heat and cold storage
	//**************************************************************************//
	
	(in05 < in07 && in34 == 1) ? (g01 = 1) : (g01 = 0);
	(in05 > in08 && in34 == 1) ? (g02 = 1) : (g02 = 0);
	(in06 < in07 && in35 == 1) ? (g03 = 1) : (g03 = 0);
	(in06 > in08 && in35 == 1) ? (g04 = 1) : (g04 = 0);
	g05 = 120;
	timeSwitchBit3(&g01, &g05, &in50, &g06, &ou03, io->__g01, io->__r01);
	timeSwitchBit3(&g02, &g05, &in50, &g06, &ou04, io->__g02, io->__r02);
	timeSwitchBit3(&g03, &g05, &in50, &g06, &ou27, io->__g03, io->__r03);
	timeSwitchBit3(&g04, &g05, &in50, &g06, &ou28, io->__g04, io->__r04);


	//level sensor cold storage
	//**************************************************************************//
	(in09 < (in10 - in11)) && (in34 == 1 || in35 == 1)? (x04 = 1) : (x04 = 0);
	(in09 < (in10 - in13)) && (in34 == 1 || in35 == 1) ? (x05 = 1) : (x05 = 0);
	(in09 > (in10 + in15)) && (in34 == 1 || in35 == 1) ? (x06 = 1) : (x06 = 0);
	(in09 > (in10 + in17)) && (in34 == 1 || in35 == 1) ? (x07 = 1) : (x07 = 0);
	(in10 == 0) ? (ou05 = 1) : (ou05 = 0);
	timeSwitchBit3(&x04, &in12, &in50, &ou30, &ou06, io->__s07, io->__s08);
	timeSwitchBit3(&x05, &in14, &in50, &ou32, &ou07, io->__s09, io->__s10);
	timeSwitchBit3(&x06, &in16, &in50, &ou34, &ou08, io->__s11, io->__s12);
	timeSwitchBit3(&x07, &in18, &in50, &ou36, &ou09, io->__s13, io->__s14);
	
	//level sensor heat storage
	//**************************************************************************//
	(in19 < (in20 - in21)) && (in34 == 1 || in35 == 1) ? (x08 = 1) : (x08 = 0);
	(in19 < (in20 - in23)) && (in34 == 1 || in35 == 1) ? (x09 = 1) : (x09 = 0);
	(in19 > (in20 + in25)) && (in34 == 1 || in35 == 1) ? (x10 = 1) : (x10 = 0);
	(in19 > (in20 + in27)) && (in34 == 1 || in35 == 1) ? (x11 = 1) : (x11 = 0);
	(in20 == 0) ? (ou10 = 1) : (ou10 = 0);
	timeSwitchBit3(&x08, &in22, &in50, &ou31, &ou11, io->__s15, io->__s16);
	timeSwitchBit3(&x09, &in24, &in50, &ou33, &ou12, io->__s17, io->__s18);
	timeSwitchBit3(&x10, &in26, &in50, &ou35, &ou13, io->__s19, io->__s20);
	timeSwitchBit3(&x11, &in28, &in50, &ou37, &ou14, io->__s21, io->__s22);

	//Low Pressure Heat and cold storage
	//**************************************************************************//
	(in29 < in32) ? (x12 = 1) : (x12 = 0);
	(in30 < in32) ? (x13 = 1) : (x13 = 0);
	(in31 < in32) ? (x14 = 1) : (x14 = 0);
	timeSwitchBit3(&x12, &in33, &in50, &ou38, &ou15, io->__s23, io->__s24);
	timeSwitchBit3(&x13, &in33, &in50, &ou42, &ou16, io->__s25, io->__s26);
	timeSwitchBit3(&x14, &in33, &in50, &ou43, &ou17, io->__s27, io->__s28);

	//Pump Starts
	//**************************************************************************//
	if (in34 == 1)
	{
		if (in34 == 1 && *io->__r09 == 0)
		{
			*io->__r09 = 1;
			*io->__s29 += 1;
		}
	}
	else
	{
		*io->__r09 = 0;
	}

	if (in35 == 1)
	{
		if (in35 == 1 && *io->__r10 == 0)
		{
			*io->__r10 = 1;
			*io->__s30 += 1;
		}
	}
	else
	{
		*io->__r10 = 0;
	}

	y01 = (in36 * 3600);

	(*io->__s29 > 0) ? (x18 = 1) : (x18 = 0);
	(*io->__s30 > 0) ? (x19 = 1) : (x19 = 0);
	BIT b01 = 0;
	(in50 == 1) ? (b01 = 1) : (b01);

	timeSwitchBit3(&x18, &y01, &b01, &y02, &x20, io->__s31, io->__s32);
	(x20 == 1 && *io->__s29 <= in37) ? (*io->__s29 = 0) : (*io->__s29);
	(x20 == 1 && *io->__s29 <= in37) ? (b01 = 1) : (b01);
	(x20 == 1 && *io->__s29 >= in37) ? (*io->__r05 = 1) : (*io->__s29 = 0);
	(x20 == 1 && *io->__s29 >= in37) ? (b01 = 1) : (b01);
	(in50 == 1) ? (*io->__r05 = 0) : (*io->__r05);

	timeSwitchBit3(&x19, &y01, &b01, &y03, &x21, io->__s33, io->__s34);
	(x21 == 1 && *io->__s30 <= in37) ? (*io->__s30 = 0) : (*io->__s30);
	(x21 == 1 && *io->__s30 <= in37) ? (b01 = 1) : (b01);
	(x21 == 1 && *io->__s30 >= in37) ? (*io->__r06 = 1) : (*io->__s29 = 0);
	(x21 == 1 && *io->__s30 >= in37) ? (b01 = 1) : (b01);
	(in50 == 1) ? (*io->__r06 = 0) : (*io->__r06);

	(*io->__r05 == 1) ? (ou18 = 1) : (ou18 = 0);
	(*io->__r06 == 1) ? (ou19 = 1) : (ou19 = 0);

	//Draining Valve Check
	//**************************************************************************//
	(in38 == 1 && in55 == 0) ? (x22 = 1) : (x22 = 0);
	timeSwitchBit3(&x22, &in39, &in50, &ou39, &ou20, io->__s35, io->__s36);

	//Level switch
	//**************************************************************************//
	(in40 == 1) ? (*io->__r07 = 1) : (*io->__r07);
	(*io->__r07 == 1) ? (ou21 = 1) : (ou21 = 0);

	//Well Temperature
	//**************************************************************************//

	(in41 < in42) && (in34 == 1 || in35 == 1) ? (x23 = 1) : (x23 = 0);
	(in41 < in44) && (in34 == 1 || in35 == 1) ? (x24 = 1) : (x24 = 0);
	(in41 > in46) && (in34 == 1 || in35 == 1) ? (x25 = 1) : (x25 = 0);
	(in41 > in48) && (in34 == 1 || in35 == 1) ? (x26 = 1) : (x26 = 0);
	timeSwitchBit3(&x23, &in43, &in50, &ou48, &ou22, io->__s37, io->__s38);
	timeSwitchBit3(&x24, &in45, &in50, &ou49, &ou23, io->__s39, io->__s40);
	timeSwitchBit3(&x25, &in47, &in50, &ou50, &ou24, io->__s41, io->__s42);
	timeSwitchBit3(&x26, &in49, &in50, &ou51, &ou25, io->__s43, io->__s44);


	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16, *io->Output17 = ou17, *io->Output18 = ou18, *io->Output19 = ou19, *io->Output20 = ou20,
		*io->Output21 = ou21, *io->Output22 = ou22, *io->Output23 = ou23, *io->Output24 = ou24, *io->Output25 = ou25, *io->Output26 = ou26, *io->Output27 = ou27, *io->Output28 = ou28, *io->Output29 = ou29, *io->Output30 = ou30,
		*io->Output31 = ou31, *io->Output32 = ou32, *io->Output33 = ou33, *io->Output34 = ou34, *io->Output35 = ou35, *io->Output36 = ou36, *io->Output37 = ou37, *io->Output38 = ou38, *io->Output39 = ou39, *io->Output40 = ou40,
		*io->Output41 = ou41, *io->Output42 = ou42, *io->Output43 = ou43, *io->Output44 = ou44, *io->Output45 = ou45, *io->Output46 = ou46, *io->Output47 = ou47, *io->Output48 = ou48, *io->Output49 = ou49, *io->Output50 = ou50,
		*io->Output51 = ou51, *io->Output52 = ou52, *io->Output53 = ou53;
}

//Enigma Block EL03_04: Heat Cold Storrage
//**********************************************************************************************************************************************//
//Main Function - Heatpump System
//**********************************************************************************************************************************************//
void el03_4_libenigma01(EL03_4_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in10 = 0,
		in11 = 0, in13 = 0, in14 = 0, in16 = 0, in17 = 0, in19 = 0, in20 = 0,
		in22 = 0, in24 = 0, in26 = 0, in28 = 0, in29 = 0, in30 = 0,
		in31 = 0, in32 = 0, in33 = 0, in39 = 0, in41 = 0;

		BIT in35 = 0, in36 = 0, in40 = 0, in43 = 0, in44 = 0, in45 = 0, in46 = 0, in47 = 0, in48 = 0, in49 = 0, in50 = 0, in51 = 0, in52 = 0;

		ULI in42 = 0, in09 = 0, in37 = 0, in38 = 0,in12 = 0, in18 = 0, in15 = 0,in21 = 0, in23 = 0, in25 = 0, in27 = 0;

		UI in34 = 0;
	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou10 = 0,
		ou11 = 0, ou12 = 0, ou13 = 0, ou38 = 0;

	ULI	ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 0, ou18 = 0, ou19 = 0, ou20 = 0,
		ou21 = 0, ou22 = 0, ou23 = 0, ou24 = 0, ou25 = 0;

	UI ou37 = 0;

	FL ou05 = 0, ou26 = 0, ou27 = 0, ou28 = 0, ou29 = 0, ou30 = 0, ou31 = 0, ou32 = 0, ou33 = 0, ou34 = 0, ou35 = 0, ou36 = 0;
	//Variable Local
	//**************************************************************************//
	BIT x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0, x08 = 0, x09 = 0, x10 = 0,
		x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0, x16 = 0, x17 = 0, x18 = 0, x19 = 0, x20 = 0,
		x21 = 0, x22 = 0, x23 = 0, x24 = 0, x25 = 0, x26 = 0, x27 = 0, x28 = 0, x29 = 0, x30 = 0;

	BIT r01 = 0, r02 = 0, r03 = 0, r04 = 0;

	FL y01 = 0, y02 = 0, y03 = 0, y04 = 0, y05 = 0, y06 = 0;
	FL a01 = 0, a02 = 0, a03 = 0, a04 = 0, a05 = 0, a06 = 0;
	FL b01 = 0, b02 = 0, b03 = 0, b04 = 0, b05 = 0, b06 = 0;
	FL c01 = 0, c02 = 0, c03 = 0, c04 = 0, c05 = 0, c06 = 0;

	ULI t01 = 0, t02 = 0, t03 = 0, t04 = 0;
	ULI d01 = 0, d02 = 0, d03 = 0, d04 = 0;
	ULI e01 = 0, e02 = 0, e03 = 0, e04 = 0;
	ULI f01 = 0, f02 = 0, f03 = 0, f04 = 0;
	ULI p01 = 0, p02 = 0, p03 = 0, p04 = 0, p05 = 0, p06 = 0, p07 = 0, p08 = 0, p09 = 0, p10 = 0, p11 = 0, p12 = 0;

	UI status = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21, in22 = *io->Input22, in23 = *io->Input23, in24 = *io->Input24, in25 = *io->Input25, in26 = *io->Input26, in27 = *io->Input27, in28 = *io->Input28, in29 = *io->Input29, in30 = *io->Input30,
		in31 = *io->Input31, in32 = *io->Input32, in33 = *io->Input33, in34 = *io->Input34, in35 = *io->Input35, in36 = *io->Input36, in37 = *io->Input37, in38 = *io->Input38, in39 = *io->Input39, in40 = *io->Input40,
		in41 = *io->Input41, in42 = *io->Input42, in43 = *io->Input43, in44 = *io->Input44, in45 = *io->Input45, in46 = *io->Input46, in47 = *io->Input47, in48 = *io->Input48, in49 = *io->Input49, in50 = *io->Input50,
		in51 = *io->Input51, in52 = *io->Input52;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16, ou17 = *io->Output17, ou18 = *io->Output18, ou19 = *io->Output19, ou20 = *io->Output20,
		ou21 = *io->Output21, ou22 = *io->Output22, ou23 = *io->Output23, ou24 = *io->Output24, ou25 = *io->Output25, ou26 = *io->Output26, ou27 = *io->Output27, ou28 = *io->Output28, ou29 = *io->Output29, ou30 = *io->Output30,
		ou31 = *io->Output31, ou32 = *io->Output32, ou33 = *io->Output33, ou34 = *io->Output34, ou35 = *io->Output35, ou36 = *io->Output36, ou37 = *io->Output37, ou38 = *io->Output38;
	
	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0;
	}

	//Temperature setrpoints
	//**************************************************************************//
	FL hph01 = 0;
	hph01 = in01 + in02;
	ou26 = hph01;

	FL hpc01 = 0;
	hpc01 = in19;
	ou31 = hpc01;
	//Release gasheater
	//**************************************************************************//
	((in41 < (in01 + in03)) || in40 == 1 ) ? (x02 = 1) : (x02 = 0);

	timeSwitch2(&x02, &in42, &in42, &ou25, &ou25, &ou13, &x03, &x03, io->__s01, io->__s02, io->__s03);


	/*
	in01 = bit release
	in02 = uli time delay up
	in03 = uli time delay down
	ou01 = uli rest time delay up
	ou02 = uli rest time delay down
	ou03 = bit release
	ou04 = bit release up
	ou05 = bit release down

	mem01 = uli
	mem02 = uli
	mem03 = bit
	*/

	//Release Heatpump Heat mode
	//**************************************************************************//
	(in40 == 0 && in47 == 1 && in45 == 0 && in46 == 0 && ou03 == 0 && ou04 == 0) ? (ou11 = 1) : (ou11 = 0);

	//Releas Heatpump Cool mode
	//**************************************************************************//
	(in40 == 0 && in48 == 1 && in45 == 0 && in46 == 0 && ou01 == 0 && ou02 == 0) ? (ou12 = 1) : (ou12 = 0);


	//Throttle Valve Load Cool Storage
	//**************************************************************************//
	(ou11 == 1) ? (ou09 = 1) : (ou09 = 0);

	//Throttle Valve Unload Cool Storage
	//**************************************************************************//
	(ou12 == 1) ? (ou10 = 1) : (ou10 = 0);


	
	//Circulation Pump Condensor
	//**************************************************************************//
	((ou09 == 1 && in43 == 1) || (ou10 == 1 && in44 ==1) || in36 == 1 || in35 == 1) ? (x12 = 1) : (x12 = 0);

	p01 = 0;
	p03 = in37 * 60;

	timeSwitch2(&x12, &p01, &p03, &p02, &p04, &ou07, &x11, &x11, io->__s20, io->__s21, io->__s22);

	ou22 = p04 / 60;


	//Circulation Pump Evaporator
	//**************************************************************************//
	((ou09 == 1 && in43 == 1) || (ou10 == 1 && in44 == 1) || in36 == 1 || in35 == 1) ? (x14 = 1) : (x14 = 0);

	p05 = 0;
	p07 = in38 * 60;

	timeSwitch2(&x14, &p05, &p07, &p06, &p08, &ou08, &x11, &x11, io->__s23, io->__s24, io->__s25);

	ou23 = p08 / 60;

	//Release Heatpump Heat Stages
	//**************************************************************************//
	(in40 == 0 && in47 == 1 && in45 == 0 && in46 == 0 && ou09 == 1 && in43 == 1) ? (*io->__r01 = 1) : (*io->__r01 = 0);

	//Release Heatpump Cool Stages
	//**************************************************************************//
	(in40 == 0 && in48 == 1 && in45 == 0 && in46 == 0 && ou10 == 1 && in44 == 1) ? (*io->__r02 = 1) : (*io->__r02 = 0);

	//Heatpump HEAT Stage 1
	//**************************************************************************//
	if (ou11 == 1)
	{

		y01 = hph01 + in08;
		ou27 = y01;
		if (in07 == 0)
		{
			(in04 < y01 && *io->__r01 == 1) ? (*io->__s04 = 1) : (*io->__s04);
		}
		else if (in07 == 1)
		{
			(in05 < y01 && *io->__r01 == 1) ? (*io->__s04 = 1) : (*io->__s04);
		}
		else if (in07 == 2)
		{
			(in06 < y01 && *io->__r01 == 1) ? (*io->__s04 = 1) : (*io->__s04);
		}

		y04 = hph01 + in11;
		ou28 = y04;

		if (in10 == 0)
		{
			(in04 > y04 || *io->__r01 == 0) ? (*io->__s04 = 0) : (*io->__s04);
		}
		else if (in10 == 1)
		{
			(in05 > y04 || *io->__r01 == 0) ? (*io->__s04 = 0) : (*io->__s04);
		}
		else if (in10 == 2)
		{
			(in06 > y04 || *io->__r01 == 0) ? (*io->__s04 = 0) : (*io->__s04);
		}
	}
	else
	{
		*io->__s04 = 0;
	}
		(*io->__s04 == 1) ? (x04 = 1) : (x04 = 0);

		t01 = in09 * 60;
		t03 = in12 * 60;

		timeSwitch2(&x04, &t01, &t03, &t02, &t04, &ou01, &x03, &x03, io->__s05, io->__s06, io->__s07);

		ou14 = t02 / 60;
		ou15 = t04 / 60;

		//Heatpump HEAT Stage 2
	//**************************************************************************//
	if (ou11 == 1)
	{
			a01 = hph01 + in14;
			ou29 = a01;

			if (in13 == 0)
			{
				(in04 < a01 && *io->__r01 == 1) ? (*io->__s08 = 1) : (*io->__s08);
			}
			else if (in13 == 1)
			{
				(in05 < a01 && *io->__r01 == 1) ? (*io->__s08 = 1) : (*io->__s08);
			}
			else if (in13 == 2)
			{
				(in06 < a01 && *io->__r01 == 1) ? (*io->__s08 = 1) : (*io->__s08);
			}

			a04 = hph01 + in17;
			ou30 = a04;
			if (in16 == 0)
			{
				(in04 > a04 || *io->__r01 == 0) ? (*io->__s08 = 0) : (*io->__s08);
			}
			else if (in16 == 1)
			{
				(in05 > a04 || *io->__r01 == 0) ? (*io->__s08 = 0) : (*io->__s08);
			}
			else if (in16 == 2)
			{
				(in06 > a04 || *io->__r01 == 0) ? (*io->__s08 = 0) : (*io->__s08);
			}

	}
	else
	{
		*io->__s08 = 0;
	}

		(*io->__s08 == 1) ? (x06 = 1) : (x06 = 0);

		d01 = in15 * 60;
		d03 = in18 * 60;

		timeSwitch2(&x06, &d01, &d03, &d02, &d04, &ou02, &x05, &x05, io->__s09, io->__s10, io->__s11);

		ou16 = d02 / 60;
		ou17 = d04 / 60;
	
	//Heatpump Cool Stage 1
	//**************************************************************************//
	if (ou12 == 1)
	{
			b01 = hpc01 + in20;//12 + 2 = 14
			ou32 = b01;
			(in28 > b01 && *io->__r02 == 1) ? (*io->__s12 = 1) : (*io->__s12); // 14 > 6

			b02 = hpc01 + in22;//12 + 0 = 12
			ou33 = b02;
			(in28 < b02 || *io->__r02 == 0) ? (*io->__s12 = 0) : (*io->__s12);//12 > 6 
	}
	else
	{
		*io->__s12 = 0;
	}
	(*io->__s12 == 1) ? (x08 = 1) : (x08 = 0);

	e01 = in21 * 60;
	e03 = in23 * 60;

	timeSwitch2(&x08, &e01, &e03, &e02, &e04, &ou03, &x07, &x07, io->__s13, io->__s14, io->__s15);

	ou18 = e02 / 60;
	ou19 = e04 / 60;


	//Heatpump Cool Stage 2
	//**************************************************************************//
	if (ou12 == 1)
	{
		c01 = hpc01 + in24;
		ou34 = c01;
		(in28 > c01 && *io->__r02 == 1) ? (*io->__s16 = 1) : (*io->__s16);

		c02 = hpc01 + in26;
		ou35 = c02;
		(in28 < c02 || *io->__r02 == 0) ? (*io->__s16 = 0) : (*io->__s16);
	}
	else
	{
		*io->__s16 = 0;
	}
	(*io->__s16 == 1) ? (x10 = 1) : (x10 = 0);

	f01 = in25 * 60;
	f03 = in27 * 60;

	timeSwitch2(&x10, &f01, &f03, &f02, &f04, &ou04, &x09, &x09, io->__s17, io->__s18, io->__s19);

	ou20 = f02 / 60;
	ou21 = f04 / 60;

	//Evapurator Valve control Temperature
	//**************************************************************************//
	ou36 = in29;
	(*io->__s04 == 1) ? (ou05 = in30) : (ou05);
	(*io->__s08 == 1) ? (ou05 = in31) : (ou05);
	(*io->__s12 == 1) ? (ou05 = in32) : (ou05);
	(*io->__s16 == 1) ? (ou05 = in33) : (ou05);

	//Release Bit Heatpump
	//**************************************************************************//
	(*io->__s04 == 1 || *io->__s08 == 1 || *io->__s10 == 1 || *io->__s16 == 1 || ou01 == 1 || ou02 == 1 || ou03 == 1 || ou04 == 1) ? (ou38 = 1) : (ou38 = 0);



	//System Status
	//**************************************************************************//
	
	if (in39 == 2)
	{
		status = 2;
	}
	else if (in39 == 1)
	{
		status = 1;
	}
	else
	{
		status = 0;
	}

	//System Switch
	//**************************************************************************//
	switch (status)
	{
	case 1://Auto
		break;
	case 2://System Stop
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou10 = 0,
			ou11 = 0, ou12 = 0, ou13 = 0, ou38 = 0;
		ou37 = 0;
		ou05 = 0, ou26 = 0, ou27 = 0, ou28 = 0, ou29 = 0, ou30 = 0, ou31 = 0, ou32 = 0, ou33 = 0, ou34 = 0, ou35 = 0, ou36 = 0;
		break;
	default:
		break;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16, *io->Output17 = ou17, *io->Output18 = ou18, *io->Output19 = ou19, *io->Output20 = ou20,
		*io->Output21 = ou21, *io->Output22 = ou22, *io->Output23 = ou23, *io->Output24 = ou24, *io->Output25 = ou25, *io->Output26 = ou26, *io->Output27 = ou27, *io->Output28 = ou28, *io->Output29 = ou29, *io->Output30 = ou30,
		*io->Output31 = ou31, *io->Output32 = ou32, *io->Output33 = ou33, *io->Output34 = ou34, *io->Output35 = ou35, *io->Output36 = ou36, *io->Output37 = ou37, *io->Output38 = ou38;

}

//Enigma Block EL03_05: Heat Cold Storrage
//**********************************************************************************************************************************************//
//Main Function - Heatpump Error System
//**********************************************************************************************************************************************//
void el03_5_libenigma01(EL03_5_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in04 = 0, in05 = 0, in14 = 0, in15 = 0;
		
	BIT in07 = 0, in08 = 0, in09 = 0, in10 = 0, in11 = 0, in12 = 0, in17 = 0;

	ULI in03 = 0, in06 = 0, in13 = 0, in16 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou03 = 0, ou05 = 0, ou08 = 0, ou11 = 0;
		

	ULI	ou02 = 0, ou04 = 0, ou06 = 0, ou07 = 0, ou09 = 0, ou10 = 0, ou12 = 0;
	
	//Variable Local
	//**************************************************************************//
	BIT x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0, x08 = 0, x09 = 0, x10 = 0,
		x11 = 0;


	ULI v01 = 0, v02 = 0, v03 = 0, v04 = 0, v05 = 0, v06 = 0, v07 = 0, v08 = 0;

	BIT e01 = 0, e02 = 0, e03 = 0, e04 = 0, e05 = 0, e06 = 0, e07 = 0, e08 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12;
	

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0;
	}

		/*
		in01 = bit release
		in02 = uli time delay
		in03 = bit reset
		ou01 = uli rest time delay
		ou02 = bit notification

		mem01 = uli
		mem02 = bit
		*/

	//Minimum Outlet Temperature Evaporator
	//**************************************************************************//
	(in01 < in02) ? (x01 = 1) : (x01 = 0);
	timeSwitchBit3(&x01, &in03, &in17, &ou02, &ou01, io->__s01, io->__s02);

	//Differential Pressure Evaporator
	//**************************************************************************//
	(in04 < in05) ? (x02 = 1) : (x02 = 0);
	timeSwitchBit3(&x02, &in06, &in17, &ou04, &ou03, io->__s03, io->__s04);

	//Valve Error Load Cool Storage
	//**************************************************************************//
	(in07 == 1 && in08 == 0) ? (x03 = 1) : (x03 = 0);
	(in07 == 0 && in08 == 1) ? (x04 = 1) : (x04 = 0);
	(in07 == 0 && in09 == 0) ? (x05 = 1) : (x05 = 0);
	(in07 == 1 && in09 == 1) ? (x06 = 1) : (x06 = 0);

	timeSwitchBit3(&x03, &in13, &in17, &v01, &e01, io->__s05, io->__s06);
	timeSwitchBit3(&x04, &in13, &in17, &v02, &e02, io->__s07, io->__s08);
	timeSwitchBit3(&x05, &in13, &in17, &v03, &e03, io->__s09, io->__s10);
	timeSwitchBit3(&x06, &in13, &in17, &v04, &e04, io->__s11, io->__s12);

	(e01 == 0 && e02 == 0 && e03 == 0 && e04 == 0) ? (ou05 = 0) : (ou05 = 1);
	(x03 == 1) ? (ou06 = v01) : (ou06 = v02);
	(x05 == 1) ? (ou07 = v03) : (ou07 = v04);

	//Valve Error Unload Cool Storage
	//**************************************************************************//
	(in10 == 1 && in11 == 0) ? (x07 = 1) : (x07 = 0);
	(in10 == 0 && in11 == 1) ? (x08 = 1) : (x08 = 0);
	(in10 == 0 && in12 == 0) ? (x09 = 1) : (x09 = 0);
	(in10 == 1 && in12 == 1) ? (x10 = 1) : (x10 = 0);

	timeSwitchBit3(&x07, &in13, &in17, &v05, &e05, io->__s13, io->__s14);
	timeSwitchBit3(&x08, &in13, &in17, &v06, &e06, io->__s15, io->__s16);
	timeSwitchBit3(&x09, &in13, &in17, &v07, &e07, io->__s17, io->__s18);
	timeSwitchBit3(&x10, &in13, &in17, &v08, &e08, io->__s19, io->__s20);

	(e05 == 0 && e06 == 0 && e07 == 0 && e08 == 0) ? (ou08 = 0) : (ou08 = 1);
	(x07 == 1) ? (ou09 = v05) : (ou09 = v06);
	(x09 == 1) ? (ou10 = v07) : (ou10 = v08);

	//Presure Error System
	//**************************************************************************//
	(in14 < in15) ? (x11 = 1) : (x11 = 0);
	timeSwitchBit3(&x11, &in16, &in17, &ou12, &ou11, io->__s21, io->__s22);

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12;

}

//Enigma Block EL03_06: Heat Cold Storrage
//**********************************************************************************************************************************************//
//Main Function - Drycooler System
//**********************************************************************************************************************************************//
void el03_6_libenigma01(EL03_6_LIBENIGMA01 *io)
{

		//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in07 = 0, in08 = 0, in10 = 0, in11 = 0, in13 = 0;

	BIT in16 = 0, in17 = 0, in18 = 0, in19 = 0, in20 = 0, in21 = 0, in22 = 0, in23 = 0, in24 = 0, in25 = 0;

	ULI in06 = 0, in09 = 0, in12 = 0, in14 = 0, in15 = 0, in26 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0,ou07 = 0,ou10 = 0;


	ULI	ou08 = 0, ou09 = 0, ou11 = 0, ou12 = 0;

	//Variable Local
	//**************************************************************************//
	BIT x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0;

	ULI d01 = 0, d02 = 0, d03 = 0, d04 = 0, d05 = 0, d06 = 0, d07 = 0, d08 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21, in22 = *io->Input22, in23 = *io->Input23, in24 = *io->Input24, in25 = *io->Input25, in26 = *io->Input26;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0;
	}

	//Release Drycooler 
		if (in17 == 1)
		{
			//Drycooler
			//**************************************************************************//


			if (in04 == 0)
			{
				(in01 > in05) ? (*io->__s01 = 1) : (*io->__s01);
			}
			else if (in04 == 1)
			{
				(in02 > in05) ? (*io->__s01 = 1) : (*io->__s01);
			}
			else if (in04 == 2)
			{
				(in03 > in05) ? (*io->__s01 = 1) : (*io->__s01);
			}

			if (in07 == 0)
			{
				(in01 < in08) ? (*io->__s01 = 0) : (*io->__s01);
			}
			else if (in07 == 1)
			{
				(in02 < in08) ? (*io->__s01 = 0) : (*io->__s01);
			}
			else if (in07 == 2)
			{

				(in03 < in08) ? (*io->__s01 = 0) : (*io->__s01);

			}

			(*io->__s01 == 1) ? (x01 = 1) : (x01 = 0);

			d01 = in06 * 60;
			d03 = in09 * 60;

			timeSwitch2(&x01, &d01, &d03, &d02, &d04, &ou10, &x02, &x02, io->__s02, io->__s03, io->__s04);

			ou08 = d02 / 60;
			ou09 = d04 / 60;


			//Throttle Valve TSA 
			//**************************************************************************//
			(ou10 == 1 || in16 == 1) ? (ou01 = 1) : (ou01 = 0);
			((ou10 == 1 || in16 == 1) && x06 == 0) ? (ou02 = 1) : (ou02 = 0);

			//Pumps TSA 
			//**************************************************************************//
			((ou10 == 1 && in18 == 1 && in20 == 1) || (in16 == 1 && in18 == 1 && in20 == 1) || (ou10 == 1 && in18 == 1 && in22 == 1 && in24 == 1)) ? (x03 = 1) : (x03 = 0);
			(x03 == 1) ? (ou03 = 1) : (ou03 = 0);
			(x03 == 1) ? (ou04 = 1) : (ou04 = 0);

			/*
			in01 = bit release
			in02 = uli time delay up
			in03 = uli time delay down
			ou01 = uli rest time delay up
			ou02 = uli rest time delay down
			ou03 = bit release
			ou04 = bit release up
			ou05 = bit release down

			mem01 = uli
			mem02 = uli
			mem03 = bit
			*/


			//Short Circuit
			//**************************************************************************//
			if (ou10 == 1)
			{
				(in10 > in11) ? (x05 = 1) : (x05 = 0);
				d05 = in12 * 60;
				d07 = in26 * 60;

				timeSwitch2(&x05, &d05, &d07, &d06, &d08, &x06, &x04, &x04, io->__s05, io->__s06, io->__s07);

				ou11 = d06 / 60;
				ou12 = d08 / 60;

				//Throttle Valve Short Circuit
				//**************************************************************************//
				(x06 == 1 || in16 == 1) ? (ou05 = 1) : (ou05 = 0);
				(x06 == 1 || in16 == 1) ? (ou06 = 1) : (ou06 = 0);
				(x06 == 1 || in16 == 1) ? (ou02 = 0) : (ou06 = 0);

				//Pump Short Circuit
				//**************************************************************************//
				((x06 == 1 && in22 == 1 && in24 == 1 && in21 == 0) || (in16 == 1 && in22 == 1 && in24 == 1 && in21 == 0)) ? (x07 = 1) : (x07 = 0);
				(x07 == 1) ? (ou07 = 1) : (ou07 = 0);
			}
		}
		else
		{
			ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou10 = 0;
		}
	//System Status
//**************************************************************************//
	UI status = 0;
	if (in13 == 2)
	{
		status = 2;
	}
	else if (in13 == 1)
	{
		status = 1;
	}
	else
	{
		status = 0;
	}

	//System Switch
	//**************************************************************************//
	switch (status)
	{
	case 1://Auto
		break;
	case 2://System Stop
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou10 = 0;
		break;
	default:
		break;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12;
}

//Enigma Block EL03_07: Heat Cold Storrage
//**********************************************************************************************************************************************//
//Main Function - Drycooler Erro System
//**********************************************************************************************************************************************//
void el03_7_libenigma01(EL03_7_LIBENIGMA01 *io)
{
	//Variable Input
//**************************************************************************//
	FL in01 = 0, in02 = 0;

	BIT in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in10 = 0, in11 = 0, in12 = 0, in13 = 0, in14 = 0, in15 = 0, in17 = 0;

	ULI in03 = 0, in16 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou03 = 0, ou06 = 0, ou09 = 0, ou12 = 0;
	ULI	ou02 = 0, ou04 = 0, ou05 = 0, ou07 = 0, ou08 = 0, ou10 = 0, ou11 = 0, ou13 = 0, ou14 = 0;

	//Variable Local
	//**************************************************************************//
	BIT x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0, x08 = 0, x09 = 0, x10 = 0,
		x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0, x16 = 0, x17 = 0;

	ULI v01 = 0, v02 = 0, v03 = 0, v04 = 0, v05 = 0, v06 = 0, v07 = 0, v08 = 0, v09 = 0, v10 = 0,
		v11 = 0, v12 = 0, v13 = 0, v14 = 0, v15 = 0, v16 = 0;

	BIT e01 = 0, e02 = 0, e03 = 0, e04 = 0, e05 = 0, e06 = 0, e07 = 0, e08 = 0, e09 = 0, e10 = 0,
		e11 = 0, e12 = 0, e13 = 0, e14 = 0, e15 = 0, e16 = 0;
	
	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12,ou13 = *io->Output13, ou14 = *io->Output14;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
		*io->__s31 = 0, *io->__s32 = 0, *io->__s33 = 0, *io->__s34 = 0;
	}

	/*
	in01 = bit release
	in02 = uli time delay
	in03 = bit reset
	ou01 = uli rest time delay
	ou02 = bit notification

	mem01 = uli
	mem02 = bit
	*/

	//Supply Throttle Valve TSA 
	//**************************************************************************//
	(in04 == 1 && in05 == 0) ? (x01 = 1) : (x01 = 0);
	(in04 == 0 && in05 == 1) ? (x02 = 1) : (x02 = 0);
	(in04 == 0 && in06 == 0) ? (x03 = 1) : (x03 = 0);
	(in04 == 1 && in06 == 1) ? (x04 = 1) : (x04 = 0);

	timeSwitchBit3(&x01, &in16, &in17, &v01, &e01, io->__s01, io->__s02);
	timeSwitchBit3(&x02, &in16, &in17, &v02, &e02, io->__s03, io->__s04);
	timeSwitchBit3(&x03, &in16, &in17, &v03, &e03, io->__s05, io->__s06);
	timeSwitchBit3(&x04, &in16, &in17, &v04, &e04, io->__s07, io->__s08);
	 
	(e01 == 0 && e02 == 0 && e03 == 0 && e04 == 0) ? (ou03 = 0) : (ou03 = 1);
	(x01 == 1) ? (ou04 = v01) : (ou04 = v02);
	(x03 == 1) ? (ou05 = v03) : (ou05 = v04);

	//Return Throttle Valve TSA
	//**************************************************************************//
	(in07 == 1 && in08 == 0) ? (x05 = 1) : (x05 = 0);
	(in07 == 0 && in08 == 1) ? (x06 = 1) : (x06 = 0);
	(in07 == 0 && in09 == 0) ? (x07 = 1) : (x07 = 0);
	(in07 == 1 && in09 == 1) ? (x08 = 1) : (x08 = 0);

	timeSwitchBit3(&x05, &in16, &in17, &v05, &e05, io->__s09, io->__s10);
	timeSwitchBit3(&x06, &in16, &in17, &v06, &e06, io->__s11, io->__s12);
	timeSwitchBit3(&x07, &in16, &in17, &v07, &e07, io->__s13, io->__s14);
	timeSwitchBit3(&x08, &in16, &in17, &v08, &e08, io->__s15, io->__s16);

	(e05 == 0 && e06 == 0 && e07 == 0 && e08 == 0) ? (ou06 = 0) : (ou06 = 1);
	(x05 == 1) ? (ou07 = v05) : (ou07 = v06);
	(x07 == 1) ? (ou08 = v07) : (ou08 = v08);

	//Supply Throttle Valve Short Circuit
	//**************************************************************************//
	(in10 == 1 && in11 == 0) ? (x09 = 1) : (x09 = 0);
	(in10 == 0 && in11 == 1) ? (x10 = 1) : (x10 = 0);
	(in10 == 0 && in12 == 0) ? (x11 = 1) : (x11 = 0);
	(in10 == 1 && in12 == 1) ? (x12 = 1) : (x12 = 0);

	timeSwitchBit3(&x09, &in16, &in17, &v09, &e09, io->__s17, io->__s18);
	timeSwitchBit3(&x10, &in16, &in17, &v10, &e10, io->__s19, io->__s20);
	timeSwitchBit3(&x11, &in16, &in17, &v11, &e11, io->__s21, io->__s22);
	timeSwitchBit3(&x12, &in16, &in17, &v12, &e12, io->__s23, io->__s24);

	(e09 == 0 && e10 == 0 && e11 == 0 && e12 == 0) ? (ou09 = 0) : (ou09 = 1);
	(x09 == 1) ? (ou10 = v09) : (ou10 = v10);
	(x11 == 1) ? (ou11 = v11) : (ou11 = v12);

	//Return Throttle Valve Short Circuit
	//**************************************************************************//
	(in13 == 1 && in14 == 0) ? (x13 = 1) : (x13 = 0);
	(in13 == 0 && in14 == 1) ? (x14 = 1) : (x14 = 0);
	(in13 == 0 && in15 == 0) ? (x15 = 1) : (x15 = 0);
	(in13 == 1 && in15 == 1) ? (x16 = 1) : (x16 = 0);

	timeSwitchBit3(&x13, &in16, &in17, &v13, &e13, io->__s25, io->__s26);
	timeSwitchBit3(&x14, &in16, &in17, &v14, &e14, io->__s27, io->__s28);
	timeSwitchBit3(&x15, &in16, &in17, &v15, &e15, io->__s29, io->__s30);
	timeSwitchBit3(&x16, &in16, &in17, &v16, &e16, io->__s31, io->__s32);

	(e13 == 0 && e14 == 0 && e15 == 0 && e16 == 0) ? (ou12 = 0) : (ou12 = 1);
	(x13 == 1) ? (ou13 = v13) : (ou13 = v14);
	(x15 == 1) ? (ou14 = v15) : (ou14 = v16);

	//Presure Error System
	//**************************************************************************//
	(in01 < in02) ? (x17 = 1) : (x17 = 0);
	timeSwitchBit3(&x17, &in03, &in17, &ou02, &ou01, io->__s33, io->__s34);



	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, * io->Output13 = ou13, *io->Output14 = ou14;

}

//Enigma Block EL03_08: Heat Cold Storrage
//**********************************************************************************************************************************************//
//Main Function - Well Tester System
//**********************************************************************************************************************************************//
void el03_8_libenigma01(EL03_8_LIBENIGMA01 *io)
{
	//Variable Input
//**************************************************************************//
	BIT in01 = 0, in09 = 0, in10 = 0, in11 = 0;

	FL in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou141 = 0;
	FL ou142 = 0;
	ULI ou143 = 0;
	UI status = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou10 = 0, ou11 = 0, ou12 = 0, ou13 = 0, ou14 = 0, ou15 = 0, ou16 = 0, ou17 = 0, ou18 = 0, ou19 = 0, ou20 = 0, ou21 = 0, ou22 = 0, ou23 = 0, ou24 = 0, ou25 = 0, ou26 = 0, ou27 = 0, ou28 = 0, ou29 = 0, ou30 = 0, ou31 = 0, ou32 = 0, ou33 = 0
		, ou34 = 0, ou35 = 0, ou36 = 0, ou37 = 0, ou38 = 0, ou39 = 0, ou40 = 0, ou41 = 0, ou42 = 0, ou43 = 0, ou44 = 0, ou45 = 0, ou46 = 0, ou47 = 0, ou48 = 0, ou49 = 0, ou50 = 0, ou51 = 0, ou52 = 0, ou53 = 0, ou54 = 0, ou55 = 0, ou56 = 0, ou57 = 0, ou58 = 0, ou59 = 0, ou60 = 0, ou61 = 0, ou62 = 0, ou63 = 0
		, ou64 = 0, ou65 = 0, ou66 = 0, ou67 = 0, ou68 = 0, ou69 = 0, ou70 = 0, ou71 = 0, ou72 = 0, ou73 = 0, ou74 = 0, ou75 = 0, ou76 = 0, ou77 = 0, ou78 = 0, ou79 = 0, ou80 = 0, ou81 = 0, ou82 = 0, ou83 = 0, ou84 = 0, ou85 = 0, ou86 = 0, ou87 = 0, ou88 = 0, ou89 = 0, ou90 = 0, ou91 = 0, ou92 = 0, ou93 = 0
		, ou94 = 0, ou95 = 0, ou96 = 0, ou97 = 0, ou98 = 0, ou99 = 0, ou100 = 0, ou101 = 0, ou102 = 0, ou103 = 0, ou104 = 0, ou105 = 0, ou106 = 0, ou107 = 0, ou108 = 0, ou109 = 0, ou110 = 0, ou111 = 0, ou112 = 0, ou113 = 0, ou114 = 0, ou115 = 0, ou116 = 0, ou117 = 0, ou118 = 0, ou119 = 0, ou120 = 0, ou121 = 0, ou122 = 0, ou123 = 0,
		ou124 = 0, ou125 = 0, ou126 = 0, ou127 = 0, ou128 = 0, ou129 = 0, ou130 = 0, ou131 = 0, ou132 = 0, ou133 = 0, ou134 = 0, ou135 = 0, ou136 = 0, ou137 = 0, ou138 = 0, ou139 = 0, ou140 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10, in11 = *io->Input11;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10, ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16, ou17 = *io->Output17, ou18 = *io->Output18, ou19 = *io->Output19, ou20 = *io->Output20,
		ou21 = *io->Output21, ou22 = *io->Output22, ou23 = *io->Output23, ou24 = *io->Output24, ou25 = *io->Output25, ou26 = *io->Output26, ou27 = *io->Output27, ou28 = *io->Output28, ou29 = *io->Output29, ou30 = *io->Output30, ou31 = *io->Output31, ou32 = *io->Output32, ou33 = *io->Output33, ou34 = *io->Output34, ou35 = *io->Output35, ou36 = *io->Output36, ou37 = *io->Output37, ou38 = *io->Output38, ou39 = *io->Output39, ou40 = *io->Output40,
		ou41 = *io->Output41, ou42 = *io->Output42, ou43 = *io->Output43, ou44 = *io->Output44, ou45 = *io->Output45, ou46 = *io->Output46, ou47 = *io->Output47, ou48 = *io->Output48, ou49 = *io->Output49, ou50 = *io->Output50, ou51 = *io->Output51, ou52 = *io->Output52, ou53 = *io->Output53, ou54 = *io->Output54, ou55 = *io->Output55, ou56 = *io->Output56, ou57 = *io->Output57, ou58 = *io->Output58, ou59 = *io->Output59, ou60 = *io->Output60,
		ou61 = *io->Output61, ou62 = *io->Output62, ou63 = *io->Output63, ou64 = *io->Output64, ou65 = *io->Output65, ou66 = *io->Output66, ou67 = *io->Output67, ou68 = *io->Output68, ou69 = *io->Output69, ou70 = *io->Output70, ou71 = *io->Output71, ou72 = *io->Output72, ou73 = *io->Output73, ou74 = *io->Output74, ou75 = *io->Output75, ou76 = *io->Output76, ou77 = *io->Output77, ou78 = *io->Output78, ou79 = *io->Output79, ou80 = *io->Output80,
		ou81 = *io->Output81, ou82 = *io->Output82, ou83 = *io->Output83, ou84 = *io->Output84, ou85 = *io->Output85, ou86 = *io->Output86, ou87 = *io->Output87, ou88 = *io->Output88, ou89 = *io->Output89, ou90 = *io->Output90, ou91 = *io->Output91, ou92 = *io->Output92, ou93 = *io->Output93, ou94 = *io->Output94, ou95 = *io->Output95, ou96 = *io->Output96, ou97 = *io->Output97, ou98 = *io->Output98, ou99 = *io->Output99, ou100 = *io->Output100,
		ou101 = *io->Output101, ou102 = *io->Output102, ou103 = *io->Output103, ou104 = *io->Output104, ou105 = *io->Output105, ou106 = *io->Output106, ou107 = *io->Output107, ou108 = *io->Output108, ou109 = *io->Output109, ou110 = *io->Output110, ou111 = *io->Output111, ou112 = *io->Output112, ou113 = *io->Output113, ou114 = *io->Output114, ou115 = *io->Output115, ou116 = *io->Output116, ou117 = *io->Output117, ou118 = *io->Output118, ou119 = *io->Output119, ou120 = *io->Output120,
		ou121 = *io->Output121, ou122 = *io->Output122, ou123 = *io->Output123, ou124 = *io->Output124, ou125 = *io->Output125, ou126 = *io->Output126, ou127 = *io->Output127, ou128 = *io->Output128, ou129 = *io->Output129, ou130 = *io->Output130, ou131 = *io->Output131, ou132 = *io->Output132, ou133 = *io->Output133, ou134 = *io->Output134, ou135 = *io->Output135, ou136 = *io->Output136, ou137 = *io->Output137, ou138 = *io->Output138, ou139 = *io->Output139, ou140 = *io->Output140,
		ou141 = *io->Output141, ou142 = *io->Output142, ou143 = *io->Output143;


	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
		*io->__s31 = 0, *io->__s32 = 0, *io->__s33 = 0, *io->__s34 = 0, *io->__s35 = 0, *io->__s36 = 0, *io->__s37 = 0, *io->__s38 = 0, *io->__s39 = 0, *io->__s40 = 0;
		*io->__s41 = 0, *io->__s42 = 0, *io->__s43 = 0, *io->__s44 = 0, *io->__s45 = 0, *io->__s46 = 0, *io->__s47 = 0, *io->__s48 = 0, *io->__s49 = 0, *io->__s50 = 0;
		*io->__s51 = 0, *io->__s52 = 0, *io->__s53 = 0, *io->__s54 = 0, *io->__s55 = 0, *io->__s56 = 0, *io->__s57 = 0, *io->__s58 = 0, *io->__s59 = 0, *io->__s60 = 0;
		*io->__s61 = 0, *io->__s62 = 0, *io->__s63 = 0, *io->__s64 = 0, *io->__s65 = 0, *io->__s66 = 0, *io->__s67 = 0, *io->__s68 = 0, *io->__s69 = 0, *io->__s70 = 0;
		*io->__s71 = 0, *io->__s72 = 0, *io->__s73 = 0, *io->__s74 = 0, *io->__s75 = 0, *io->__s76 = 0, *io->__s77 = 0, *io->__s78 = 0, *io->__s79 = 0, *io->__s80 = 0;
		*io->__s81 = 0, *io->__s82 = 0, *io->__s83 = 0, *io->__s84 = 0, *io->__s85 = 0, *io->__s86 = 0, *io->__s87 = 0, *io->__s88 = 0, *io->__s89 = 0, *io->__s90 = 0;
		*io->__s91 = 0, *io->__s92 = 0, *io->__s93 = 0, *io->__s94 = 0, *io->__s95 = 0, *io->__s96 = 0, *io->__s97 = 0, *io->__s98 = 0, *io->__s99 = 0, *io->__s100 = 0;
		*io->__s101 = 0, *io->__s102 = 0, *io->__s103 = 0, *io->__s104 = 0, *io->__s105 = 0, *io->__s106 = 0, *io->__s107 = 0, *io->__s108 = 0, *io->__s109 = 0, *io->__s110 = 0;
		*io->__s111 = 0, *io->__s112 = 0, *io->__s113 = 0, *io->__s114 = 0, *io->__s115 = 0, *io->__s116 = 0, *io->__s117 = 0, *io->__s118 = 0, *io->__s119 = 0, *io->__s120 = 0;
		*io->__s121 = 0, *io->__s122 = 0, *io->__s123 = 0, *io->__s124 = 0, *io->__s125 = 0, *io->__s126 = 0, *io->__s127 = 0, *io->__s128 = 0, *io->__s129 = 0, *io->__s130 = 0;
		*io->__s131 = 0, *io->__s132 = 0, *io->__s133 = 0, *io->__s134 = 0, *io->__s135 = 0, *io->__s136 = 0, *io->__s137 = 0, *io->__s138 = 0, *io->__s139 = 0, *io->__s140 = 0;
		*io->__t01 = 0, *io->__r01 = 0, *io->__r02 = 0;
	}

	if (in01 == 1 && *io->__r02 == 0)
	{
		*io->__r02 = 1;
		*io->__s71 = *io->__s01, *io->__s72 = *io->__s02, *io->__s73 = *io->__s03, *io->__s74 = *io->__s04, *io->__s75 = *io->__s05, *io->__s76 = *io->__s06, *io->__s77 = *io->__s07, *io->__s78 = *io->__s08, *io->__s79 = *io->__s09, *io->__s80 = *io->__s10;
		*io->__s81 = *io->__s11, *io->__s82 = *io->__s12, *io->__s83 = *io->__s13, *io->__s84 = *io->__s14, *io->__s85 = *io->__s15, *io->__s86 = *io->__s16, *io->__s87 = *io->__s17, *io->__s88 = *io->__s18, *io->__s89 = *io->__s19, *io->__s90 = *io->__s20;
		*io->__s91 = *io->__s21, *io->__s92 = *io->__s22, *io->__s93 = *io->__s23, *io->__s94 = *io->__s24, *io->__s95 = *io->__s25, *io->__s96 = *io->__s26, *io->__s97 = *io->__s27, *io->__s98 = *io->__s28, *io->__s99 = *io->__s29, *io->__s100 = *io->__s30;
		*io->__s101 = *io->__s31, *io->__s102 = *io->__s32, *io->__s103 = *io->__s33, *io->__s104 = *io->__s34, *io->__s105 = *io->__s35, *io->__s106 = *io->__s36, *io->__s107 = *io->__s37, *io->__s108 = *io->__s38, *io->__s109 = *io->__s39, *io->__s110 = *io->__s40;
		*io->__s111 = *io->__s41, *io->__s112 = *io->__s42, *io->__s113 = *io->__s43, *io->__s114 = *io->__s44, *io->__s115 = *io->__s45, *io->__s116 = *io->__s46, *io->__s117 = *io->__s47, *io->__s118 = *io->__s48, *io->__s119 = *io->__s49, *io->__s120 = *io->__s50;
		*io->__s121 = *io->__s51, *io->__s122 = *io->__s52, *io->__s123 = *io->__s53, *io->__s124 = *io->__s54, *io->__s125 = *io->__s55, *io->__s126 = *io->__s56, *io->__s127 = *io->__s57, *io->__s128 = *io->__s58, *io->__s129 = *io->__s59, *io->__s130 = *io->__s60;
		*io->__s131 = *io->__s61, *io->__s132 = *io->__s62, *io->__s133 = *io->__s63, *io->__s134 = *io->__s64, *io->__s135 = *io->__s65, *io->__s136 = *io->__s66, *io->__s137 = *io->__s67, *io->__s138 = *io->__s68, *io->__s139 = *io->__s69, *io->__s140 = *io->__s70;
		

		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
		*io->__s31 = 0, *io->__s32 = 0, *io->__s33 = 0, *io->__s34 = 0, *io->__s35 = 0, *io->__s36 = 0, *io->__s37 = 0, *io->__s38 = 0, *io->__s39 = 0, *io->__s40 = 0;
		*io->__s41 = 0, *io->__s42 = 0, *io->__s43 = 0, *io->__s44 = 0, *io->__s45 = 0, *io->__s46 = 0, *io->__s47 = 0, *io->__s48 = 0, *io->__s49 = 0, *io->__s50 = 0;
		*io->__s51 = 0, *io->__s52 = 0, *io->__s53 = 0, *io->__s54 = 0, *io->__s55 = 0, *io->__s56 = 0, *io->__s57 = 0, *io->__s58 = 0, *io->__s59 = 0, *io->__s60 = 0;
		*io->__s61 = 0, *io->__s62 = 0, *io->__s63 = 0, *io->__s64 = 0, *io->__s65 = 0, *io->__s66 = 0, *io->__s67 = 0, *io->__s68 = 0, *io->__s69 = 0, *io->__s70 = 0;
		*io->__t01 = 0;
		*io->__r01 = 1;
		status = 0;
		
	}
	if (in11 == 1)
	{
		*io->__t01 = 0;
		*io->__r01 = 0;
		*io->__r02 = 0;
		status = 0;
	}
	if (*io->__r01 == 1 && in09 == 1 && in10 == 1)
	{

		*io->__t01 += 1;
		(*io->__t01 > 0 && *io->__t01 < 302) ? (status = 1) : (status);
		(*io->__t01 > 302 && *io->__t01 < 422) ? (status = 2) : (status);
		(*io->__t01 > 422 && *io->__t01 < 542) ? (status = 3) : (status);
		(*io->__t01 > 542 && *io->__t01 < 662) ? (status = 4) : (status);
		(*io->__t01 > 662 && *io->__t01 < 782) ? (status = 5) : (status);
		(*io->__t01 > 782 && *io->__t01 < 902) ? (status = 6) : (status);
		(*io->__t01 > 902 && *io->__t01 < 1022) ? (status = 7) : (status);
		(*io->__t01 > 1022 && *io->__t01 < 1142) ? (status = 8) : (status);
		(*io->__t01 > 1142 && *io->__t01 < 1262) ? (status = 9) : (status);
		(*io->__t01 > 1262 && *io->__t01 < 1562) ? (status = 10) : (status);

	
		if (*io->__t01 == 300)
		{
			*io->__s01 = in02, *io->__s02 = in03, *io->__s03 = in04, *io->__s04 = in05, *io->__s05 = in06, *io->__s06 = in07, *io->__s07 = in08;
		}
		else if (*io->__t01 == 420)
		{
			*io->__s08 = in02, *io->__s09 = in03, *io->__s10 = in04, *io->__s11 = in05, *io->__s12 = in06, *io->__s13 = in07, *io->__s14 = in08;
		}
		else if (*io->__t01 == 540)
		{
			*io->__s15 = in02, *io->__s16 = in03, *io->__s17 = in04, *io->__s18 = in05, *io->__s19 = in06, *io->__s20 = in07, *io->__s21 = in08;
		}
		else if (*io->__t01 == 660)
		{
			*io->__s22 = in02, *io->__s23 = in03, *io->__s24 = in04, *io->__s25 = in05, *io->__s26 = in06, *io->__s27 = in07, *io->__s28 = in08;
		}
		else if (*io->__t01 == 780)
		{
			*io->__s29 = in02, *io->__s30 = in03, *io->__s31 = in04, *io->__s32 = in05, *io->__s33 = in06, *io->__s34 = in07, *io->__s35 = in08;
		}
		else if (*io->__t01 == 900)
		{
			*io->__s36 = in02, *io->__s37 = in03, *io->__s38 = in04, *io->__s39 = in05, *io->__s40 = in06, *io->__s41 = in07, *io->__s42 = in08;
		}
		else if (*io->__t01 == 1020)
		{
			*io->__s43 = in02, *io->__s44 = in03, *io->__s45 = in04, *io->__s46 = in05, *io->__s47 = in06, *io->__s48 = in07, *io->__s49 = in08;
		}
		else if (*io->__t01 == 1140)
		{
			*io->__s50 = in02, *io->__s51 = in03, *io->__s52 = in04, *io->__s53 = in05, *io->__s54 = in06, *io->__s55 = in07, *io->__s56 = in08;
		}
		else if (*io->__t01 == 1260)
		{
			*io->__s57 = in02, *io->__s58 = in03, *io->__s59 = in04, *io->__s60 = in05, *io->__s61 = in06, *io->__s62 = in07, *io->__s63 = in08;
		}
		else if (*io->__t01 == 1560)
		{
			*io->__s64 = in02, *io->__s65 = in03, *io->__s66 = in04, *io->__s67 = in05, *io->__s68 = in06, *io->__s69 = in07, *io->__s70 = in08;
		}
		if (*io->__t01 >= 1570)
		{
			*io->__t01 = 0;
			*io->__r01 = 0;
			*io->__r02 = 0;
			status = 0;
		}
	}
	else
	{
		*io->__t01 = 0;
		status = 0;
	}
		//Frequency
		//**************************************************************************//
		switch (status)
		{
		case 0:
			ou141 = 0, ou142 = 0;	
			break;
		case 1:
			ou141 = 1, ou142 = 10;
			break;
		case 2:
			ou141 = 1, ou142 = 20;
			break;
		case 3:
			ou141 = 1, ou142 = 30;
			break;
		case 4:
			ou141 = 1, ou142 = 40;
			break;
		case 5:
			ou141 = 1, ou142 = 50;
			break;
		case 6:
			ou141 = 1, ou142 = 60;
			break;
		case 7:
			ou141 = 1, ou142 = 70;
			break;
		case 8:
			ou141 = 1, ou142 = 80;
			break;
		case 9:
			ou141 = 1, ou142 = 90;
			break;
		case 10:
			ou141 = 1, ou142 = 100;
			break;
		default:
			ou141 = 0, ou142 = 0;
			break;
		}
	ou01 = *io->__s01, ou02 = *io->__s02, ou03 = *io->__s03, ou04 = *io->__s04, ou05 = *io->__s05, ou06 = *io->__s06, ou07 = *io->__s07, ou08 = *io->__s08, ou09 = *io->__s09, ou10 = *io->__s10, ou11 = *io->__s11, ou12 = *io->__s12, ou13 = *io->__s13, ou14 = *io->__s14, ou15 = *io->__s15, ou16 = *io->__s16, ou17 = *io->__s17, ou18 = *io->__s18, ou19 = *io->__s19, ou20 = *io->__s20;
	ou21 = *io->__s21, ou22 = *io->__s22, ou23 = *io->__s23, ou24 = *io->__s24, ou25 = *io->__s25, ou26 = *io->__s26, ou27 = *io->__s27, ou28 = *io->__s28, ou29 = *io->__s29, ou30 = *io->__s30, ou31 = *io->__s31, ou32 = *io->__s32, ou33 = *io->__s33, ou34 = *io->__s34, ou35 = *io->__s35, ou36 = *io->__s36, ou37 = *io->__s37, ou38 = *io->__s38, ou39 = *io->__s39, ou40 = *io->__s40;
	ou41 = *io->__s41, ou42 = *io->__s42, ou43 = *io->__s43, ou44 = *io->__s44, ou45 = *io->__s45, ou46 = *io->__s46, ou47 = *io->__s47, ou48 = *io->__s48, ou49 = *io->__s49, ou50 = *io->__s50, ou51 = *io->__s51, ou52 = *io->__s52, ou53 = *io->__s53, ou54 = *io->__s54, ou55 = *io->__s55, ou56 = *io->__s56, ou57 = *io->__s57, ou58 = *io->__s58, ou59 = *io->__s59, ou60 = *io->__s60;
	ou61 = *io->__s61, ou62 = *io->__s62, ou63 = *io->__s63, ou64 = *io->__s64, ou65 = *io->__s65, ou66 = *io->__s66, ou67 = *io->__s67, ou68 = *io->__s68, ou69 = *io->__s69, ou70 = *io->__s70, ou71 = *io->__s71, ou72 = *io->__s72, ou73 = *io->__s73, ou74 = *io->__s74, ou75 = *io->__s75, ou76 = *io->__s76, ou77 = *io->__s77, ou78 = *io->__s78, ou79 = *io->__s79, ou80 = *io->__s80;
	ou81 = *io->__s81, ou82 = *io->__s82, ou83 = *io->__s83, ou84 = *io->__s84, ou85 = *io->__s85, ou86 = *io->__s86, ou87 = *io->__s87, ou88 = *io->__s88, ou89 = *io->__s89, ou90 = *io->__s90, ou91 = *io->__s91, ou92 = *io->__s92, ou93 = *io->__s93, ou94 = *io->__s94, ou95 = *io->__s95, ou96 = *io->__s96, ou97 = *io->__s97, ou98 = *io->__s98, ou99 = *io->__s99, ou100 = *io->__s100;
	ou101 = *io->__s101, ou102 = *io->__s102, ou103 = *io->__s103, ou104 = *io->__s104, ou105 = *io->__s105, ou106 = *io->__s106, ou107 = *io->__s107, ou108 = *io->__s108, ou109 = *io->__s109, ou110 = *io->__s110, ou111 = *io->__s111, ou112 = *io->__s112, ou113 = *io->__s113, ou114 = *io->__s114, ou115 = *io->__s115, ou116 = *io->__s116, ou117 = *io->__s117, ou118 = *io->__s118, ou119 = *io->__s119, ou120 = *io->__s120;
	ou121 = *io->__s121, ou122 = *io->__s122, ou123 = *io->__s123, ou124 = *io->__s124, ou125 = *io->__s125, ou126 = *io->__s126, ou127 = *io->__s127, ou128 = *io->__s128, ou129 = *io->__s129, ou130 = *io->__s130, ou131 = *io->__s131, ou132 = *io->__s132, ou133 = *io->__s133, ou134 = *io->__s134, ou135 = *io->__s135, ou136 = *io->__s136, ou137 = *io->__s137, ou138 = *io->__s138, ou139 = *io->__s139, ou140 = *io->__s140;

	ou143 = *io->__t01;
	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10, *io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16, *io->Output17 = ou17, *io->Output18 = ou18, *io->Output19 = ou19, *io->Output20 = ou20,
		* io->Output21 = ou21, *io->Output22 = ou22, *io->Output23 = ou23, *io->Output24 = ou24, *io->Output25 = ou25, *io->Output26 = ou26, *io->Output27 = ou27, *io->Output28 = ou28, *io->Output29 = ou29, *io->Output30 = ou30, *io->Output31 = ou31, *io->Output32 = ou32, *io->Output33 = ou33, *io->Output34 = ou34, *io->Output35 = ou35, *io->Output36 = ou36, *io->Output37 = ou37, *io->Output38 = ou38, *io->Output39 = ou39, *io->Output40 = ou40,
		*io->Output41 = ou41, *io->Output42 = ou42, *io->Output43 = ou43, *io->Output44 = ou44, *io->Output45 = ou45, *io->Output46 = ou46, *io->Output47 = ou47, *io->Output48 = ou48, *io->Output49 = ou49, *io->Output50 = ou50, *io->Output51 = ou51, *io->Output52 = ou52, *io->Output53 = ou53, *io->Output54 = ou54, *io->Output55 = ou55, *io->Output56 = ou56, *io->Output57 = ou57, *io->Output58 = ou58, *io->Output59 = ou59, *io->Output60 = ou60,
		*io->Output61 = ou61, *io->Output62 = ou62, *io->Output63 = ou63, *io->Output64 = ou64, *io->Output65 = ou65, *io->Output66 = ou66, *io->Output67 = ou67, *io->Output68 = ou68, *io->Output69 = ou69, *io->Output70 = ou70, *io->Output71 = ou71, *io->Output72 = ou72, *io->Output73 = ou73, *io->Output74 = ou74, *io->Output75 = ou75, *io->Output76 = ou76, *io->Output77 = ou77, *io->Output78 = ou78, *io->Output79 = ou79, *io->Output80 = ou80,
		*io->Output81 = ou81, *io->Output82 = ou82, *io->Output83 = ou83, *io->Output84 = ou84, *io->Output85 = ou85, *io->Output86 = ou86, *io->Output87 = ou87, *io->Output88 = ou88, *io->Output89 = ou89, *io->Output90 = ou90, *io->Output91 = ou91, *io->Output92 = ou92, *io->Output93 = ou93, *io->Output94 = ou94, *io->Output95 = ou95, *io->Output96 = ou96, *io->Output97 = ou97, *io->Output98 = ou98, *io->Output99 = ou99, *io->Output100 = ou100,
		*io->Output101 = ou101, *io->Output102 = ou102, *io->Output103 = ou103, *io->Output104 = ou104, *io->Output105 = ou105, *io->Output106 = ou106, *io->Output107 = ou107, *io->Output108 = ou108, *io->Output109 = ou109, *io->Output110 = ou110, *io->Output111 = ou111, *io->Output112 = ou112, *io->Output113 = ou113, *io->Output114 = ou114, *io->Output115 = ou115, *io->Output116 = ou116, *io->Output117 = ou117, *io->Output118 = ou118, *io->Output119 = ou119, *io->Output120 = ou120,
		*io->Output121 = ou121, *io->Output122 = ou122, *io->Output123 = ou123, *io->Output124 = ou124, *io->Output125 = ou125, *io->Output126 = ou126, *io->Output127 = ou127, *io->Output128 = ou128, *io->Output129 = ou129, *io->Output130 = ou130, *io->Output131 = ou131, *io->Output132 = ou132, *io->Output133 = ou133, *io->Output134 = ou134, *io->Output135 = ou135, *io->Output136 = ou136, *io->Output137 = ou137, *io->Output138 = ou138, *io->Output139 = ou139, *io->Output140 = ou140,
		*io->Output141 = ou141, *io->Output142 = ou142, *io->Output143 = ou143;







}






