

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 1 EL01: Internal Analysis System
//**********************************************************************************************************************************************//
void el01_1_libenigma01(EL01_1_LIBENIGMA01 *io)
{

	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, 
		in10 = 0, in11 = 0, in12 = 0, in13 = 0, in14 = 0, in16 = 0;
	BIT in03 = 0, in04 = 0, in05 = 0, in15 = 0, in17 = 0, in18 = 0;
	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou10 = 0, ou11 = 0, ou16 = 0, ou17 = 0;
	BIT ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0;
	BIT ou12 = 0, ou14 = 0, ou15 = 0;
	UI ou13 = 0;

	//Variable Local
	//**************************************************************************//
	FL x09 = 0;

	UI x07 = 0, x08 = 0, time01 = 0;
	BIT x50 = 0;
	BIT y50 = 0;

	UI status = 0;
	BIT e01 = 0;
	BIT e02 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16, ou17 = *io->Output17;
	
	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = in01, *io->__s02 = in01, *io->__s03 = in01, *io->__s04 = in01, *io->__s05 = in01, *io->__s06 = in01, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
		*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0, *io->__r05 = 0, *io->__r06 = 0, *io->__r07 = 0, *io->__r08 = 0, *io->__r09 = 0, *io->__r10 = 0;
		*io->__s31 = 0, *io->__s32 = 0, *io->__s33 = 0;
	}

	//Reset System
	//**************************************************************************//
	if (in15 == 1)
	{
		*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0, *io->__r05 = 0, *io->__r06 = 0, *io->__r07 = 0, *io->__r08 = 0, *io->__r09 = 0, *io->__r10 = 0;
	}
	//Calculation
	//**************************************************************************//
	PLUGIN_ZEIT a;
	PLUGIN_GetLocalTime(&a);
	x08 = a.uiMinute;
	x07 = a.uiSecond;
	time01 = a.uiHour;

	//Summer Block
	//**************************************************************************//
	(in01 > in16) ? (e01 = 1) : (e01 = 0);
	(in01 < 10) ? (e02 = 1) : (e02 = 0);

	((time01 == 7 && x08 == 10 && e01 == 1) || (time01 == 8 && x08 == 10 && e01 == 1) || (time01 == 9 && x08 == 10 && e01 == 1)) ? (*io->__s33 += 1) : (*io->__s33);
	(*io->__s33 == 1) ? (ou15 = 1) : (ou15 = 0);
	(time01 == 18 && x08 == 10) ? (*io->__s33 = 0) : (*io->__s33);
	



	*io->__s34 += 1;

	if (*io->__s34 == 3600)
	{
		*io->__s34 = 0;
		(e01 == 1) ? (*io->__s31 += 1) : (*io->__s31);
	}
	if (*io->__s34 > 3600)
	{
		*io->__s34 = 0;
	}
	(time01 == 18 && x08 == 10) ? (*io->__s31 = 0) : (*io->__s31);
	(time01 == 18 && x08 == 10) ? (*io->__r09 = 0) : (*io->__r09);

	if (time01 == 17 && *io->__s31 >= 9 && *io->__r09 == 0)
	{
		*io->__s32 += 1;
		*io->__r09 = 1;
	}

	if (time01 == 17 && *io->__s31 < 9 && *io->__s32 > 0 && *io->__r09 == 0)
	{
		*io->__s32 -= 1;
		*io->__r09 = 1;
	}
	
	(*io->__s32 < 0) ? (*io->__s32 = 0) : (*io->__s32);
	(*io->__s32 == 5) ? (*io->__s32 = 4) : (*io->__s32);

	(e02 == 1) ? (*io->__s32 = 0) : (*io->__s32);
	(e02 == 1) ? (*io->__s33 = 0) : (*io->__s33);

	(*io->__s32 >= 1) ? (ou14 = 1) : (ou14 = 0);

	ou16 = *io->__s31;
	ou17 = *io->__s32;
	
	//Average Temperature
	//**************************************************************************//
	if (x08 == 0)
	{
		*io->__s01 = in01;
	}
	else if (x08 == 10)
	{
		*io->__s02 = in01;
	}
	else if (x08 == 20)
	{
		*io->__s03 = in01;
	}
	else if (x08 == 30)
	{
		*io->__s04 = in01;
	}
	else if (x08 == 40)
	{
		*io->__s05 = in01;
	}
	else if (x08 == 50)
	{
		*io->__s06 = in01;
	}
	if (in03 == 1)
	{
		x09 = in02;
		ou01 = in02;
	}
	else
	{
		x09 = ((*io->__s01 + *io->__s02 + *io->__s03 + *io->__s04 + *io->__s05 + *io->__s06) / 6);
		ou01 = x09;
	}
	
	//IAS Status
	//**************************************************************************//
	if (in06 >= in07 || in07 >= in08 || in12 >= in11 || in04 == 1 || *io->__r01 == 1)
	{
		status = 8;
		*io->__r01 = 1;
	}
	else if (x09 <= in06 && ou14 == 0 && ou15 == 0)
	{
		status = 1;
	}
	else if ((x09 <= in07 && ou14 == 0 && ou15 == 0) || in17 ==1)
	{
		status = 2;
	}
	else if (x09 < in08 && ou14 == 0 && ou15 == 0)
	{
		status = 3;
	}
	else if ((x09 >= in08 && in09 > in10) || ou14 == 1 || ou15 == 1 || in18 == 1)
	{
		status = 4;
	}
	else if (x09 >= in08 && in09 <= in10)
	{
		status = 5;
	}
	else if (x09 >= in11 && in05 == 0)
	{
		status = 6;
	}
	else if (x09 <= in12 && in05 == 0)
	{
		status = 7;
	}
	else
	{
		status = 0;
	}

	//IAS Switch
	//**************************************************************************//
	switch (status)
	{
	case 1://Peakload Heat
		ou13 = status;
		ou02 = 1, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou12 = 1;

		x50 = 0;
		break;

	case 2://Heat
		ou13 = status;
		ou02 = 0, ou03 = 1, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou12 = 1;

		x50 = 0;
		break;

	case 3://Neutral
		ou13 = status;
		ou02 = 0, ou03 = 0, ou04 = 1, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou12 = 1;

		x50 = 0;
		break;

	case 4://Cool
		ou13 = status;
		ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 1, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou12 = 1;

		x50 = 0;
		break;

	case 5://Peakload Cool
		ou13 = status;
		ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 1, ou07 = 0, ou08 = 0, ou09 = 0, ou12 = 1;

		x50 = 1;
		break;

	case 6://Load Heat
		ou13 = status;
		ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 1, ou08 = 0, ou09 = 0, ou12 = 0;

		x50 = 0;
		break;

	case 7://Load Cool
		ou13 = status;
		ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 1, ou09 = 0,ou12 = 0;

		x50 = 0;
		break;

	case 8://Error
		ou13 = status;
		ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 1, ou12 = 0;

		x50 = 0;
		break;
	default:
		ou13 = status;
		ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou12 = 0;
		break;
	}

	timeSwitch(&x50, &in13, &in14, &ou10, &ou11, &y50, io->__s07, io->__s08, io->__s09);
	if (x50 == 1 && y50 == 0)
	{
		ou05 = 1;
		ou06 = 0;
	}
	else if (x50 == 0 && y50 == 1)
	{
		ou05 = 0;
		ou06 = 1;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16, *io->Output17 = ou17;
}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 2
//**********************************************************************************************************************************************//
void el01_2_libenigma01(EL01_2_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0;

	//Variable Local
	//**************************************************************************//
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0;
	FL grmin = 0, grmax1 = 0, grmax2 = 0, grmax3 = 0, grmax4 = 0;
	FL gra01 = 0, gra02 = 0, gra03 = 0, gra04 = 0;
	FL nu01 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09;
	
	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
		*io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
		*io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0, *io->__s30 = 0;
		*io->__r01 = 0, *io->__r02 = 0, *io->__r03 = 0, *io->__r04 = 0, *io->__r05 = 0, *io->__r06 = 0, *io->__r07 = 0, *io->__r08 = 0, *io->__r09 = 0, *io->__r10 = 0;
	}


	//Conditions
	//**************************************************************************//
	if (in01 == 0 || in07 == 0)
	{
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0;
	}
	else
	{
		//Calculations
		//**************************************************************************//
		ou01 = (in02 / in07) * 100;
		ou02 = (in03 / in07) * 100;
		ou03 = (in04 / in07) * 100;
		ou04 = (in05 / in07) * 100;
		ou05 = (in06 / in07) * 100;

		grmin = 0;
		grmax1 = -100;
		grmax2 = -50;
		grmax3 = 50;
		grmax4 = 100;

		twoRamp(&in02, &in01, &grmin, &grmin, &in07, &grmax4, &nu01, &x05, io->__s06);
		twoRamp(&in03, &in01, &grmin, &grmin, &in07, &grmax3, &nu01, &x06, io->__s07);

		twoRamp(&in02, &in01, &grmin, &grmin, &in07, &grmax1, &nu01, &x01, io->__s01);
		twoRamp(&in03, &in01, &grmin, &grmin, &in07, &grmax2, &nu01, &x02, io->__s02);
		twoRamp(&in05, &in01, &grmin, &grmin, &in07, &grmax3, &nu01, &x03, io->__s03);
		twoRamp(&in06, &in01, &grmin, &grmin, &in07, &grmax4, &nu01, &x04, io->__s04);

		ou06 = x01 + x02 + x03 + x04;
		ou08 = x05 + x06;
		ou09 = x03 + x04;
		
		gra01 = -100;
		gra02 = -40;
		gra03 = 100;
		gra04 = 220;

		twoRamp(&ou06, &in01, &gra01, &gra02, &gra03, &gra04, &nu01, &ou07, io->__s05);


	}
	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09;
	

}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 3
//**********************************************************************************************************************************************//
void el01_3_libenigma01(EL01_3_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0;
	BIT in02 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0;

	//Variable Local
	//**************************************************************************//
	
	ULI x09 = 0, x10 = 0, x11 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03;


	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag() || *io->__s04 < 60)
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s05 = 0, *io->__s06 = 0;

		//Counter
		*io->__s04 += 1;
		

		//Buffer Clear
		for (x11 = 0; x11 < 1000; x11++)
		{
			*((io->__sa01) + x11) = 0;
		}

		ou01 = 1;
		ou03 = *io->__s04;
	}
	else
	{
		*io->__s05 += 1;
		x11 = 0;

		if (*io->__s05 == 120 && x11 == 0)
		{
			if (*io->__s06 == 0)
			{
				if (*io->__s01 < 999 && *io->__s06 == 0)
				{
					//Counter

					x09 = *io->__s01;
					*io->__s01 += 1;


					*((io->__sa01) + x09) = in01;

					//Clear Swap Memory
					*io->__s02 = 0;

					//Load Buffer
					for (x10 = 0; x10 < *io->__s01; x10++)
					{
						*io->__s02 += *((io->__sa01) + x10);
					}

					ou03 = *io->__s02 / *io->__s01;
				}
				else
				{

					//Clear Counter
					*io->__s01 = 0;
					x10 = 0;
					x09 = 0;
					*io->__s06 = 1;
				}
				ou01 = 2;
			}
			else
			{
				if (*io->__s01 < 999)
				{
					//Counter

					x09 = *io->__s01;
					*io->__s01 += 1;


					*((io->__sa01) + x09) = in01;

					//Clear Swap Memory
					*io->__s02 = 0;

					//Load Buffer
					for (x10 = 0; x10 <= 999; x10++)
					{
						*io->__s02 += *((io->__sa01) + x10);
					}

					ou03 = *io->__s02 / 999;
				}
				else
				{

					//Clear Counter
					*io->__s01 = 0;
					x10 = 0;
					x09 = 0;
				}
				ou01 = 3;
			}
			*io->__s05 = 0;
		}
	}
	if (in02 > 0)
	{
		//Clear Clean Counter
		*io->__s04 = 0;
	}

	ou02 = *io->__s01;
	
	

	//Write Output
		//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03;
}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 4
//**********************************************************************************************************************************************//
void el01_4_libenigma01(EL01_4_LIBENIGMA01 *io)
{

	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in10 = 0,
		in11 = 0, in12 = 0, in13 = 0, in14 = 0, in15 = 0, in16 = 0, in17 = 0, in18 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0;

	//Variable Local
	//**************************************************************************//
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0, x08 = 0, x09 = 0, x10 = 0,
		x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0;
	FL flow = 0;
	FL grmin = 0, grmax = 0;
	FL grmin1 = 0, grmax1 = 0;
	FL nu01 = 0;
	FL satemph = 0, satempc = 0;
	FL systemph = 0, systempc = 0;
	FL systemph2 = 0, systempc2 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0,
			*io->__s10 = 0, *io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;
	}
	if (in01 == 0 || in02 == 0 || in03 == 0 || in04 == 0 || in05 == 0 || in08 == 0 || in09 == 0 || in10 == 0 || in11 == 0 || in14 == 0 || in15 == 0 || in16 == 0 || in17 == 0)
	{
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0;
	}
	else
	{
		flow = 1;
		grmin = 0;
		grmax = 10;
		grmin1 = 0 - 10;
		grmax1 = 10;

		//System SA TEMP
		//**************************************************************************//
		if (in07 == 0 && in13 == 0)
		{
			x03 = in03;
		}
		else
		{
			twoRamp(&in07, &flow, &grmin, &in03, &grmax, &in05, &nu01, &x01, io->__s01);//max
			twoRamp(&in13, &flow, &grmin, &in03, &grmax, &in04, &nu01, &x02, io->__s02);//min
			twoRamp(&in18, &flow, &grmin1, &x01, &grmax1, &x02, &nu01, &x03, io->__s03);//temp
		}
		//System HEAT TEMP
		//**************************************************************************//
		if (in06 == 0 && in12 == 0)
		{
			x06 = in09;
		}
		else
		{
			twoRamp(&in06, &flow, &grmin, &in09, &grmax, &in11, &nu01, &x04, io->__s04);//max
			twoRamp(&in12, &flow, &grmin, &in09, &grmax, &in10, &nu01, &x05, io->__s05);//min
			twoRamp(&in18, &flow, &grmin1, &x04, &grmax1, &x05, &nu01, &x06, io->__s06);//temp
		}
		//System COOL TEMP
		//**************************************************************************//
		if (in06 == 0 && in12 == 0)
		{
			x09 = in15;
		}
		else
		{
			twoRamp(&in12, &flow, &grmin, &in15, &grmax, &in16, &nu01, &x07, io->__s07);//max
			twoRamp(&in06, &flow, &grmin, &in15, &grmax, &in17, &nu01, &x08, io->__s08);//min
			twoRamp(&in18, &flow, &grmin1, &x08, &grmax1, &x07, &nu01, &x09, io->__s09);//temp
		}
		//System SA TEMP Battery
		//**************************************************************************//
		x10 = (in01 / 2) + 1;
		x11 = (in01 / 2);

		x13 = (in02 / 2) + 1;
		x14 = (in02 / 2);

		twoRamp(&in18, &flow, &grmin1, &x10, &grmax1, &x11, &nu01, &x12, io->__s10);//heating Battery
		twoRamp(&in18, &flow, &grmin1, &x14, &grmax1, &x13, &nu01, &x15, io->__s11);//cooling Battery


		//SA Temp
		//**************************************************************************//
		satemph = x03 + x12;
		satempc = x03 - x15;

		//Temp to System
		//**************************************************************************//
		systemph = (satemph + x06 + satemph + x06 + in08) / 5;
		systempc = (satempc + x09 + satempc + x09 + in14) / 5;

		ou01 = systemph;
		ou02 = systempc;
		ou03 = x03;
		ou04 = x06;
		ou05 = x09;
		ou06 = satemph;
		ou07 = satempc;
		ou08 = x05;
		ou09 = x08;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09;
}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 5
//**********************************************************************************************************************************************//
void el01_5_libenigma01(EL01_5_LIBENIGMA01 *io)

{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in10 = 0,
		in11 = 0, in12 = 0, in13 = 0, in14 = 0, in15 = 0, in16 = 0, in19 = 0, in20 = 0,
		in21 = 0, in22 = 0, in23 = 0, in24 = 0, in25 = 0, in26 = 0, in27 = 0, in28 = 0, in29 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0,
		ou14 = 0, ou15 = 0, ou21 = 0, ou34 = 0, ou35 = 0;
	BIT ou28 = 0, ou29 = 0, ou30 = 0, ou31 = 0, ou32 = 0, ou33 = 0;

	UI ou36 = 0;
	//Variable Local
	//**************************************************************************//
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0, x08 = 0, x09 = 0, x10 = 0,
		x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0,
		x21 = 0, x22 = 0, x23 = 0, x24 = 0;

	FL ex01 = 0, ex02 = 0, ex03 = 0, ex04 = 0, ex05 = 0, ex06 = 0;
	FL power1 = 0, power2 = 0, power3 = 0, power4 = 0, power5 = 0, power6 = 0;
	FL add01 = 0, add02 = 0, add03 = 0, add04 = 0, add05 = 0, add06 = 0, add07 = 0, add08 = 0, add09 = 0;
	FL grmin = 0, grmax = 0, grmin01 = 0, grmax01 = 0, nu01 = 0, flow = 0;


	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21, in22 = *io->Input22, in23 = *io->Input23, in24 = *io->Input24, in25 = *io->Input25, in26 = *io->Input26, in27 = *io->Input27, in28 = *io->Input28, in29 = *io->Input29;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07,
		ou14 = *io->Output14, ou21 = *io->Output21, ou28 = *io->Output28, ou29 = *io->Output29, ou30 = *io->Output30, ou31 = *io->Output31, ou32 = *io->Output32, ou33 = *io->Output33, ou34 = *io->Output34, ou35 = *io->Output35, ou36 = *io->Output36;

	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0,
			*io->__s10 = 0, *io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0,
			*io->__s20 = 0, *io->__s21 = 0, *io->__s22 = 0, *io->__s23 = 0, *io->__s24 = 0, *io->__s25 = 0, *io->__s26 = 0, *io->__s27 = 0, *io->__s28 = 0, *io->__s29 = 0,
			*io->__s30 = 0, *io->__s31 = 0,* io->__s32 = 0;
	}

	//Power Output Zone
	//**************************************************************************//
	x01 = (in01 * in02) / 100;
	x02 = (x01 / in03) * 100;
	x03 = (in04 * in05) / 100;
	x04 = (x03 / in06) * 100;


	//Calculations Exponent
	//**************************************************************************//
	power1 = in24;
	power2 = in25;
	power3 = in26;
	power4 = in27;
	power5 = in28;
	power6 = in29;

	//Step 1 Temperature Output
	//**************************************************************************//
	//Calculations Step 1 HEAT
	x08 = in07 - in08;
	x09 = in10 / 100;
	ex01 = powf(x09, power1);
	add01 = ex01 * x08;

	//Calculations Step 1 COOL
	x10 = in09 - in08;
	x11 = in11 / 100;
	ex02 = powf(x11, power2);
	add02 = ex02 * x10;

	add03 = add01 + add02 + in08;

	//Step 2 Temperature Output
	//**************************************************************************//
	//Calculations Step 2 HEAT
	x12 = in12 - in13;
	x13 = in15 / 100;
	ex03 = powf(x13, power3);
	add04 = ex03 * x12;

	//Calculations Step 2 COOL
	x14 = in14 - in13;
	x15 = in16 / 100;
	ex04 = powf(x15, power4);
	add05 = ex04 * x14;

	add06 = add04 + add05 + in13;

	//Step Supply Air Temperature Output
	//**************************************************************************//
	//Calculations Step SAHEAT
	x21 = in19 - in20;
	x22 = in22 / 100;
	ex05 = powf(x22, power5);
	add07 = ex05 * x21;

	//Calculations Step SACOOL
	x23 = in21 - in20;
	x24 = in23 / 100;
	ex06 = powf(x24, power6);
	add08 = ex06 * x23;

	add09 = add07 + add08 + in20;

	//BA Output 
	//**************************************************************************//
	//Calculations Hot Cold
	if (in10 > 50 && in15 < 50)
	{
		ou28 = 0;
		ou29 = 1;
		ou30 = 0;
		ou31 = 0;
		ou32 = 0;
		ou36 = 2;
	}
	else if (in10 > 50 && in15 > 50)
	{
		ou28 = 1;
		ou29 = 0;
		ou30 = 0;
		ou31 = 0;
		ou32 = 0;
		ou36 = 1;
	}
	else if (in11 > 50 && in16 <50)
	{
		ou28 = 0;
		ou29 = 0;
		ou30 = 0;
		ou31 = 1;
		ou32 = 0;
		ou36 = 4;
	}
	else if (in11 > 50 && in16 > 50)
	{
		ou28 = 0;
		ou29 = 0;
		ou30 = 0;
		ou31 = 0;
		ou32 = 1;
		ou36 = 5;
	}
	else
	{
		ou28 = 0;
		ou29 = 0;
		ou30 = 1;
		ou31 = 0;
		ou32 = 0;
		ou36 = 3;
	}

	grmin = 50;
	grmax = 100;
	grmin01 = 11.9;
	grmax01 = 45.1;
	flow = 1;

	//BA Output 
	//**************************************************************************//
	twoRamp(&in22, &flow, &grmin, &in19, &grmax, &grmax01, &nu01, &ou35, io->__s31);//heating SA temperature
	twoRamp(&in23, &flow, &grmin, &in21, &grmax, &grmin01, &nu01, &ou34, io->__s32);//cooling SA temperature


	//Set Outputs
	ou01 = x01;
	ou02 = in01;
	ou03 = x02;
	ou04 = x03;
	ou05 = in04;
	ou06 = x04;
	ou07 = add03;
	ou14 = add06;
	ou21 = add09;

	//Error Output
	//**************************************************************************//
	if (in01 == 0 || in04 == 0 || ou07 == 0 || ou14 == 0 || ou21 == 0)
	{
		ou33 = 1;
	}
	else
	{
		ou33 = 0;
	}
	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output14 = ou14,
		*io->Output21 = ou21, *io->Output28 = ou28, *io->Output29 = ou29, *io->Output30 = ou30, *io->Output31 = ou31, *io->Output32 = ou32, * io->Output33 = ou33, *io->Output34 = ou34, *io->Output35 = ou35, *io->Output36 = ou36;


}
//**********************************************************************************************************************************************//
//Main Function - Enigma Block 6
//**********************************************************************************************************************************************//
void el01_6_libenigma01(EL01_6_LIBENIGMA01 *io)
{

	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0;

	//Variable Local
	//**************************************************************************//
	FL x01 = 0;
	FL flow = 0;
	FL grmin = 0, grmax = 0;
	FL grmin1 = 0, grmax1 = 0;
	FL nu01 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02;
	ou01 = *io->Output01;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0;
	}
	if (in01 > 10 && in02 == 0)
	{
		x01 = in01;
		grmin1 = 73;
		grmax1 = 100;
	}
	else if (in02 > 10 && in01 == 0)
	{
		x01 = in02;
		grmin1 = 47;
		grmax1 = 20;
	
	}
	else
	{
		x01 = 50;
		grmin1 = 0;
		grmax1 = 100;
	}
	//Calculations Power
	flow = 10;
	grmin = 0;
	grmax = 100;

	twoRamp(&x01, &flow, &grmin, &grmin1, &grmax, &grmax1, &nu01, &ou01, io->__s01);


	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01;
}
//**********************************************************************************************************************************************//
//Main Function - Enigma Block 7
//**********************************************************************************************************************************************//
void el01_7_libenigma01(EL01_7_LIBENIGMA01 *io)
{


	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0,
		in10 = 0, in11 = 0, in12 = 0, in13 = 0, in19 = 0, in20 = 0,
		in21 = 0, in22 = 0, in23 = 0, in24 = 0, in25 = 0, in26 = 0, in27 = 0, in28 = 0, in29 = 0, in30 = 0, in31 = 0,
		in32 = 0, in33 = 0, in34 = 0, in35 = 0, in36 = 0, in37 = 0, in38 = 0;
	BIT in14 = 0, in15 = 0, in16 = 0, in17 = 0, in18 = 0, in41 = 0;
	ULI in39 = 0, in40 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou08 = 0, ou09 = 0, ou10 = 0,
		ou11 = 0, ou16 = 0, ou17 = 0, ou18 = 0, ou19 = 0, ou20 = 0, ou21 = 0, ou22 = 0, ou23 = 0, ou24 = 0, ou25 = 0,
		ou26 = 0, ou27 = 0, ou34 = 0, ou35 = 0, ou42 = 0, ou43 = 0;
	BIT ou05 = 0, ou06 = 0, ou07 = 0, ou12 = 0, ou13 = 0, ou14 = 0, ou15 = 0, ou28 = 0, ou29 = 0, ou30 = 0, ou31 = 0,
		ou32 = 0, ou33 = 0, ou36 = 0, ou37 = 0, ou38 = 0, ou39 = 0, ou40 = 0, ou41 = 0, ou46 = 0, ou47 = 0;
	ULI ou44 = 0, ou45 = 0;

	//Variable Local
	//**************************************************************************//
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0, x06 = 0, x07 = 0, x08 = 0, x09 = 0, x10 = 0,
		x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0, x16 = 0, x17 = 0, x18 = 0, x19 = 0, x20 = 0,
		x21 = 0, x22 = 0, x23 = 0, x24 = 0, x25 = 0, x26 = 0, x27 = 0, x28 = 0, x29 = 0;
	BIT x50 = 0;

	FL systemtemph = 0, systemtempc = 0;
	FL nu01 = 0;
	FL flow = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21, in22 = *io->Input22, in23 = *io->Input23, in24 = *io->Input24, in25 = *io->Input25, in26 = *io->Input26, in27 = *io->Input27, in28 = *io->Input28, in29 = *io->Input29, in30 = *io->Input30,
		in31 = *io->Input31, in32 = *io->Input32, in33 = *io->Input33, in34 = *io->Input34, in35 = *io->Input35, in36 = *io->Input36, in37 = *io->Input37, in38 = *io->Input38, in39 = *io->Input39, in40 = *io->Input40,
		in41 = *io->Input41;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16, ou17 = *io->Output17, ou18 = *io->Output18, ou19 = *io->Output19, ou20 = *io->Output20,
		ou21 = *io->Output21, ou22 = *io->Output22, ou23 = *io->Output23, ou24 = *io->Output24, ou25 = *io->Output25, ou26 = *io->Output26, ou27 = *io->Output27, ou28 = *io->Output28, ou29 = *io->Output29, ou30 = *io->Output30,
		ou31 = *io->Output31, ou32 = *io->Output32, ou33 = *io->Output33, ou34 = *io->Output34, ou35 = *io->Output35, ou36 = *io->Output36, ou37 = *io->Output37, ou38 = *io->Output38, ou39 = *io->Output39, ou40 = *io->Output40,
		ou41 = *io->Output41, ou42 = *io->Output42, ou43 = *io->Output43, ou44 = *io->Output44, ou45 = *io->Output45, ou46 = *io->Output46, ou47 = *io->Output47;


	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0,
			*io->__s10 = 0, *io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0, *io->__s14 = 0, *io->__s15 = 0, *io->__s16 = 0, *io->__s17 = 0, *io->__s18 = 0, *io->__s19 = 0, *io->__s20 = 0;

	}
	if (in36 == 150 || in37 == 150)
	{
	
	}
	else
	{
		flow = 1;
	
		//System Disired Heat Temperature Output
		//**************************************************************************//
		x01 = ((in02 / in03) * 100) - in01; // Power Demand
		/*x02 = in08 / 2; // Temperature Band*/
		x03 = in04 - 10; // Heat curve - temperature band
		x04 = in04 + in08; // Heat curve + temperature band
		ou01 = in03;
		ou04 = x01;

		threeRamp(&x01, &flow, &in05, &x03, &in06, &in04, &in07, &x04, &nu01, &systemtemph, io->__s01);

		if (systemtemph > in33)
		{
			systemtemph = in33;
		}
		else if (systemtemph < in32)
		{
			systemtemph = in32;
		}

		ou02 = systemtemph;

		//System Disired Cool Temperature Output
		//**************************************************************************//
		x05 = ((in20 / in21) * 100) - in19; // Power Demand
		/*x06 = in26 / 2; // Temperature Band*/
		x07 = in22 - in26; // Cool curve - temperature band //was x06 update 26-05-2020
		x08 = in22 + 10; // Cool curve + temperature band
		ou08 = in21;
		ou11 = x05;

		threeRamp(&x05, &flow, &in23, &x08, &in24, &in22, &in25, &x07, &nu01, &systemtempc, io->__s02);

		if (systemtempc < in35)
		{
			systemtempc= in35;
		}
		else if (systemtempc > in34)
		{
			systemtempc = in34;
		}

		ou09 = systemtempc;

		//Heat Pump Temperature UP-Down Heat
		//**************************************************************************//
		x09 = in10 / 2; // Temperature Band
		x10 = systemtemph - x09; // Heat Temp - temperature band
		x11 = systemtemph + x09; // Heat Temp + temperature band
		ou18 = x10;
		ou19 = x11;
		x23 = 0 - x09;
		x24 = 0 + x09;

		//Heat Pump Temperature UP-Down Cool
		//**************************************************************************//
		x12 = in28 / 2; // Temperature Band
		x13 = systemtempc - x12; // Cool Temp - temperature band
		x14 = systemtempc + x12; // Cool Temp + temperature band
		ou23 = x13;
		ou24 = x14;
		x25 = 0 - x12;
		x26 = 0 + x12;

		//Heat Pump Power UP-Down Heat
		//**************************************************************************//
		x15 = in09 / 2; // Power Band
		x16 = in06 - x15; // disired power - power band
		x17 = in06 + x15; // disired power + power band
		ou16 = x16;
		ou17 = x17;

		//Heat Pump Power UP-Down Cool
		//**************************************************************************//
		x18 = in27 / 2; // Power Band
		x19 = in24 - x18; // disired power - power band
		x20 = in24 + x18; // disired power + power band
		ou21 = x19;
		ou22 = x20;

		//Temperature Difference
		//**************************************************************************//
		x21 = in36 - systemtemph;
		ou20 = x21;
		x22 = systemtempc - in37;
		ou25 = x22;

		//Temperature Boiler
		//**************************************************************************//
		ou34 = in11 + systemtemph;
		ou35 = in12 + systemtemph;

		//Temperature Cooler
		//**************************************************************************//
		ou42 = in29 + systemtempc;
		ou43 = in30 + systemtempc;
		//WP UP Heat
		//**************************************************************************//
		if (x21 < x23)
		{
			ou28 = 1;
		}
		else
		{
			ou28 = 0;
		}
		if (x01 > x17)
		{
			ou29 = 1;
		}
		else
		{
			ou29 = 0;
		}
		if ((ou28 == 1 || ou29 == 1) && (in14 == 1 || in15 == 1 || in16 == 1) && in41 == 1)
		{
			ou05 = 1;
		}
		else
		{
			ou05 = 0;
		}
		//WP Down Heat
		//**************************************************************************//
		if (x21 > x24)
		{
			ou30 = 1;
		}
		else
		{
			ou30 = 0;
		}
		if (x01 < x16)
		{
			ou31 = 1;
		}
		else
		{
			ou31 = 0;
		}
		if ((ou30 == 1 && ou31 == 1) || (in14 == 0 && in15 == 0 && in16 == 0) || ou04 < 10 || in41 == 0)
		{
			ou06 = 1;
		}
		else
		{
			ou06 = 0;
		}
		//WP UP Cool
		//**************************************************************************//
		if (x22 < x25)
		{
			ou36 = 1;
		}
		else
		{
			ou36 = 0;
		}
		if (x05 > x20)
		{
			ou37 = 1;
		}
		else
		{
			ou37 = 0;
		}
		if ((ou36 == 1 || ou37 == 1) && (in16 == 1 || in17 == 1 || in18 == 1) && in41 == 1)
		{
			ou12 = 1;
		}
		else
		{
			ou12 = 0;
		}
		//WP Down Cool
		//**************************************************************************//
		if (x22 > x26)
		{
			ou38 = 1;
		}
		else
		{
			ou38 = 0;
		}
		if (x05 < x19)
		{
			ou39 = 1;
		}
		else
		{
			ou39 = 0;
		}
		if ((ou38 == 1 && ou39 == 1) || (in16 == 0 && in17 == 0 && in18 == 0) || ou11 <10 || in41 == 0)
		{
			ou13 = 1;
		}
		else
		{
			ou13 = 0;
		}
		//Boiler Release 
		//**************************************************************************//
		//if (x21 < in11 || x21 < in12)
		if (x21 < in12)
		{
			if (x21 < in11)
			{
				ou32 = 1;
			}	
		}
		else
		{
			ou32 = 0;
		}
		if (x01 > in13)
		{

			ou33 = 1;
		}
		else
		{
			ou33 = 0;
		}
		if ((ou32 == 1 || ou33 == 1) && (in14 == 1 || in15 == 1) && in41 == 1)
		{
			ou07 = 1;
		}
		else
		{
			ou07 = 0;
		}
		//Cooler Release
		//**************************************************************************//
		//if (x22 < in29 || x21 < in30)
		if (x22 < in30)
		{
			if(x22 < in29)
			{
				ou40 = 1;
			}
		}
		else
		{
			ou40 = 0;
		}
		if (x05 > in31)
		{
			ou41 = 1;
		}
		else
		{
			ou41 = 0;
		}
		if ((ou40 == 1 || ou41 ==1 ) && (in17 == 1 || in18 == 1) && in41 == 1)
		{
			ou14 = 1;
		}
		else
		{
			ou14 = 0;
		}
		//Transfer Data 
		//**************************************************************************//
		ou03 = in13;
		ou10 = in31;

		//Cooler Present Release
		//**************************************************************************//
		x27 = in38 / 2; // Temperature Band
		x28 = systemtempc - x27; // Cool Temp - temperature band
		x29 = systemtempc + x27; // Cool Temp + temperature band
		ou26 = x28;
		ou27 = x29;
		if ((in37 <= systemtempc || in37 < x29) && (in17 == 1 || in18 == 1))
		{
			x50 = 1;
		}
		else
		{
			x50 = 0;
		}
		timeSwitch2(&x50, &in39, &in40, &ou44, &ou45, &ou15, &ou46, &ou47, io->__s03, io->__s04, io->__s05);

	}

	//Write Output
		//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16, *io->Output17 = ou17, *io->Output18 = ou18, *io->Output19 = ou19, *io->Output20 = ou20,
		*io->Output21 = ou21, *io->Output22 = ou22, *io->Output23 = ou23, *io->Output24 = ou24, *io->Output25 = ou25, *io->Output26 = ou26, *io->Output27 = ou27, *io->Output28 = ou28, *io->Output29 = ou29, *io->Output30 = ou30,
		*io->Output31 = ou31, *io->Output32 = ou32, *io->Output33 = ou33, *io->Output34 = ou34, *io->Output35 = ou35, *io->Output36 = ou36, *io->Output37 = ou37, *io->Output38 = ou38, *io->Output39 = ou39, *io->Output40 = ou40,
		*io->Output41 = ou41, *io->Output42 = ou42, *io->Output43 = ou43, *io->Output44 = ou44, *io->Output45 = ou45, *io->Output46 = ou46, *io->Output47 = ou47;

}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 8
//**********************************************************************************************************************************************//
void el01_8_libenigma01(EL01_8_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0;
	BIT in03 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou09 = 0;
	FL ou06 = 0, ou07 = 0, ou08 = 0;

	//Variable Local
	//**************************************************************************//
	UI status = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 1, *io->__s03 = 0, *io->__r01 = 0;
	}
	//Reset System
	//**************************************************************************//
	if (in03 == 1)
	{
		*io->__r01 = 0;
		*io->__s02 = 1;
		*io->__s01 = 0;
	}
	//Power Compute
	//**************************************************************************//
	if(*io->__r01 == 0 && *io->__s02 > 0)
	{
		if (in02 > 90)
		{
			*io->__s01 += 1;
			if (*io->__s01 == *io->__s03)
			{
				*io->__s01 = 0;
				*io->__s02 += 1;
				ou09 = 1;
			}
			else
			{
				ou09 = 0;
			}
		}
		else if (in02 < 20 && *io->__s02 > 1)
		{
			*io->__s01 += 1;
			if (*io->__s01 == *io->__s03)
			{
				*io->__s01 = 0;
				*io->__s02 -= 1;
				ou09 = 1;
			}
			else
			{
				ou09 = 0;
			}
		}
		else
		{
			*io->__s01 = 0;
			ou09 = 0;
		}
	}
	//Status Switch
	//**************************************************************************//
	if (*io->__s02 == 5 || *io->__r01 == 1)
	{
			status = 8;
			*io->__r01 = 1;
			
	}
	else if (*io->__s02 == 1)
	{
			status = 1;
			*io->__s03 = 7200;
	}
	else if (*io->__s02 == 2)
	{
			status = 2;
			*io->__s03 = 14400;
	}
	else if (*io->__s02 == 3)
	{
			status = 3;
			*io->__s03 = 21600;
	}
	else if (*io->__s02 == 4)
	{
			status = 4;
			*io->__s03 = 36000;
	}
	else
	{
			status = 0;
	}
	//Status Case Fibonacci
	//**************************************************************************//
	switch (status)
	{
	case 1:
		ou07 = status;
		ou01 = 1, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0;
		ou06 = in01 * 1;
		break;
	case 2:
		ou07 = status;
		ou01 = 0, ou02 = 1, ou03 = 0, ou04 = 0, ou05 = 0;
		ou06 = in01 * 2;
		break;
	case 3:
		ou07 = status;
		ou01 = 0, ou02 = 0, ou03 = 1, ou04 = 0, ou05 = 0;
		ou06 = in01 * 3;
		break;
	case 4:
		ou07 = status;
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 1, ou05 = 0;
		ou06 = in01 * 5;
		break;
	case 8:
		ou07 = status;
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 1;
		ou06 = in01 * 8;
		break;
	default:
		ou07 = status;
		break;
	}
	if (PLUGIN_GetStartFlag() || in03 == 1)
	{
		ou09 = 1;
	}
	ou08 = in01 * 8;

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09;

}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 9
//**********************************************************************************************************************************************//
void el01_9_libenigma01(EL01_9_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0;
	BIT in03 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou09 = 0;
	FL ou06 = 0, ou07 = 0, ou08 = 0;

	//Variable Local
	//**************************************************************************//
	UI status = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 1, *io->__s03 = 0, *io->__r01 = 0;
	}
	//Reset System
	//**************************************************************************//
	if (in03 == 1)
	{
		*io->__r01 = 0;
		*io->__s02 = 1;
		*io->__s01 = 0;
	}
	//Power Compute
	//**************************************************************************//
	if (*io->__r01 == 0 && *io->__s02 > 0)
	{
		if (in01 > 75 || in02 > 50)
		{
			*io->__s01 += 1;
			if (*io->__s01 == *io->__s03)
			{
				*io->__s01 = 0;
				*io->__s02 += 1;
				ou09 = 1;
			}
			else
			{
				ou09 = 0;
			}
		}
		else if ((in01 < 25 || in02 < 5) && *io->__s02 > 1)
		{
			*io->__s01 += 1;
			if (*io->__s01 == *io->__s03)
			{
				*io->__s01 = 0;
				*io->__s02 -= 1;
				ou09 = 1;
			}
			else
			{
				ou09 = 0;
			}
		}
		else
		{
			*io->__s01 = 0;
			ou09 = 0;
		}
	}
	//Status Switch
	//**************************************************************************//
	if (*io->__s02 == 5 || *io->__r01 == 1)
	{
		status = 8;
		*io->__r01 = 1;

	}
	else if (*io->__s02 == 1)
	{
		status = 1;
		*io->__s03 = 7200;
	}
	else if (*io->__s02 == 2)
	{
		status = 2;
		*io->__s03 = 14400;
	}
	else if (*io->__s02 == 3)
	{
		status = 3;
		*io->__s03 = 21600;
	}
	else if (*io->__s02 == 4)
	{
		status = 4;
		*io->__s03 = 36000;
	}
	else
	{
		status = 0;
	}
	//Status Case Fibonacci
	//**************************************************************************//
	switch (status)
	{
	case 1:
		ou07 = status;
		ou01 = 1, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0;
		ou06 = 1;
		break;
	case 2:
		ou07 = status;
		ou01 = 0, ou02 = 1, ou03 = 0, ou04 = 0, ou05 = 0;
		ou06 = 2;
		break;
	case 3:
		ou07 = status;
		ou01 = 0, ou02 = 0, ou03 = 1, ou04 = 0, ou05 = 0;
		ou06 = 3;
		break;
	case 4:
		ou07 = status;
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 1, ou05 = 0;
		ou06 = 5;
		break;
	case 8:
		ou07 = status;
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 1;
		ou06 = 8;
		break;
	default:
		ou07 = status;
		break;
	}
	if (PLUGIN_GetStartFlag() || in03 == 1)
	{
		ou09 = 1;
	}
	ou08 = 8;
	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09;

}



//**********************************************************************************************************************************************//
//Main Function - Enigma Block 10
//**********************************************************************************************************************************************//
void el01_10_libenigma01(EL01_10_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0;

	//Variable Local
	//**************************************************************************//

	FL p01 = 0, p02 = 0;

	FL grmin = 0, grmaxh = 0, grmaxc = 0;
	FL grmin1 = 0, grmax1 = 0;
	FL nu01 = 0;
	FL flow = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0;
	}


	//Total Power Calculations
	//**************************************************************************//
	p01 = (in01 * in02);
	p02 = (in03 * in04);

	ou01 = p01;
	ou02 = p02;


	//Power Calculations
	//**************************************************************************//
	flow = 1;
	grmin = 0;
	grmin1 = 2.2;
	grmax1 = 0.2;
	grmaxh = (in05 * 3);
	grmaxc = (in07 * 3);//3 step fibo

	//Power Outputs
	//**************************************************************************//
	twoRamp(&in01, &flow, &grmin, &grmin1, &in05, &grmax1, &nu01, &ou03, io->__s01);	//Step 1 Heat
	twoRamp(&in02, &flow, &grmin, &grmin1, &in06, &grmax1, &nu01, &ou04, io->__s02);	//Step 2 Heat

	twoRamp(&in03, &flow, &grmin, &grmin1, &in07, &grmax1, &nu01, &ou05, io->__s03);	//Step 1 Cool
	twoRamp(&in04, &flow, &grmin, &grmin1, &in08, &grmax1, &nu01, &ou06, io->__s04);	//Step 2 Cool

	twoRamp(&p01, &flow, &grmin, &grmin1, &grmaxh, &grmax1, &nu01, &ou07, io->__s05);	//Step Heat Supply Air Temp
	twoRamp(&p02, &flow, &grmin, &grmin1, &grmaxc, &grmax1, &nu01, &ou08, io->__s06);	//Step Cool Supply Air Temp



	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08;
}


//**********************************************************************************************************************************************//
//Main Function - Enigma Block 11
//**********************************************************************************************************************************************//
void el01_11_libenigma01(EL01_11_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in11 = 0, in12 = 0, in14 = 0, in15 = 0, in16 = 0, in17 = 0, in18 = 0, in19 = 0, in20 = 0, in21 = 0;
	BIT in05 = 0,in10 = 0, in13 = 0;
	
	//Variable Output
	//**************************************************************************//
	BIT ou07 = 0, ou10 = 0;
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou08 = 0, ou09 = 0, ou11 = 0, ou12 = 0, ou13 = 0, ou14 = 0, ou15 = 0, ou16 = 0;

	//Variable Local
	//**************************************************************************//
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0;
	FL flow = 0, flowh = 0, flowc = 0;

	FL grmin = 0, grmax = 0;
	FL grmin1 = 0, grmax1 = 0;
	FL grmin2 = 0, grmax2 = 0;
	FL grmin3 = 0, grmax3 = 0;
	FL grmin4 = 0, grmax4 = 0;
	FL nu01 = 0;
	FL rtin01 = 0, rtin02 = 0, avrgrt = 0;
	FL setrtin01 = 0, setrtin02 = 0, optrt = 0, optrtmin = 0, optrtmax = 0;
	FL minrt = 0, maxrt = 0;
	FL cah = 0, cac = 0;
	FL midheat = 0, midcool = 0;
	FL speed = 0, speed1 = 0, slow = 0, slow1 = 0;
	

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20,
		in21 = *io->Input21;

	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10, ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0, *io->__s07 = 0, *io->__s08 = 0, *io->__s09 = 0, *io->__s10 = 0, *io->__s11 = 0, *io->__s12 = 0, *io->__s13 = 0;
	}
	//Setpoint Room Temperature
	//**************************************************************************//
	if (in10 == 1)
	{
		setrtin01 = in08;
		setrtin02 = in09;
	}
	else
	{
		setrtin01 = in06;
		setrtin02 = in07;
	}
	//Optimum Room Temperature
	//**************************************************************************//
	optrt = (setrtin01 + setrtin02) / 2;
	minrt = setrtin01 - 1;
	maxrt = setrtin02 + 1;

	//Cool Available
	//**************************************************************************//
	/*cah = in14 + in11;
	cac = in14 - in12;*/

	if (in13 == 1)
	{
		ou07 = 1;
	}
	else
	{
		ou07 = 0;
	}

	//Room Temperature
	//**************************************************************************//
	if (in05 == 1 && ou07 == 1)
	{
		ou09 = 2;
		ou10 = 0;
		rtin01 = in03;
		rtin02 = in04;
	}
	else
	{
		ou09 = 1;
		ou10 = 0;
		rtin01 = in01;
		rtin02 = in02;
	}
	if (in01 < minrt || in02 < minrt || in03 < minrt || in04 < minrt)
	{
		ou09 = 0;
		ou10 = 1;
	}
	//Average Room Temperature
	//**************************************************************************//
	avrgrt = (rtin01 + rtin02) / 2;

	//Zone Analyse
	//**************************************************************************//

	flow = 1;
	grmin = 0;
	grmax = 100;

	twoRamp(&avrgrt, &flow, &optrt, &grmin, &minrt, &grmax, &nu01, &ou03, io->__s01);//toCold
	twoRamp(&avrgrt, &flow, &optrt, &grmin, &setrtin01, &grmax, &nu01, &ou04, io->__s02);//Cold
	twoRamp(&avrgrt, &flow, &optrt, &grmin, &setrtin02, &grmax, &nu01, &ou05, io->__s03);//Hot
	twoRamp(&avrgrt, &flow, &optrt, &grmin, &maxrt, &grmax, &nu01, &ou06, io->__s04);//toHot

	//Setpoint Supply Water Temperature
	//**************************************************************************//
	grmin1 = optrt - 4;
	grmax1 = optrt + 4;
	grmin2 = optrt - 2;
	grmax2 = optrt + 2;
	midheat = (optrt + in16) / 2;
	midcool = (optrt + in17) / 2;
	speed = 1;
	speed1 = 0.1;
	slow = 0.1;
	slow1 = 0.01;
	optrtmin = optrt - 0.5;
	optrtmax = optrt + 0.5;

	twoRamp(&in20, &flow, &slow, &slow1, &speed, &speed1, &nu01, &flowh, io->__s05);//Average Heating Speed
	twoRamp(&in21, &flow, &slow, &slow1, &speed, &speed1, &nu01, &flowc, io->__s06);//Average Cooling Speed


	twoRamp(&in19, &flowh, &optrt, &optrtmax, &setrtin01, &midheat, &nu01, &x01, io->__s07);//max temperature
	twoRamp(&in18, &flow, &optrt, &x01, &minrt, &in16, &nu01, &grmax3, io->__s08);//max temperature

	twoRamp(&in19, &flowc, &optrt, &optrtmin, &setrtin02, &midcool, &nu01, &x02, io->__s09);//min temperature
	twoRamp(&in18, &flow, &optrt, &x02, &maxrt, &in17, &nu01, &grmin3, io->__s10);//min temperature


	threeRamp(&avrgrt, &flow, &grmin1, &grmax2, &optrt, &optrt, &grmax1, &grmin2, &nu01, &x03, io->__s11);//return water temperature

	grmin4 = x03 - 2;
	grmax4 = x03 + 2;


	if (ou10 == 1)
	{
		x05 = optrt;
	}
	else
	{
		threeRamp(&in15, &flow, &grmin4, &grmax2, &x03, &x03, &grmax4, &grmin2, &nu01, &x05, io->__s12);//return water temperature
	}

	if (in05 == 1 && ou07 == 1)
	{
		grmax3 = optrtmax;
	}
	else
	{
		grmin3 = optrtmin;
	}
	threeRamp(&x05, &flow, &grmax2, &grmax3, &optrt, &optrt, &grmin2, &grmin3, &nu01, &x04, io->__s13);//supply water temperature
	
	//Set Outputs
	//**************************************************************************//
	ou01 = avrgrt;
	ou02 = optrt;
	ou08 = x04;
	ou11 = x03;
	ou12 = x05;
	ou13 = x01;
	ou14 = grmax3;
	ou15 = x02;
	ou16 = grmin3;

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10, *io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16;

}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 12
//**********************************************************************************************************************************************//
void el01_12_libenigma01(EL01_12_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0;
	BIT ou08 = 0;

	//Variable Local
	//**************************************************************************//
	FL grmin = 0, grmax = 0;
	FL nu01 = 0;
	FL avrgrt = 0;
	FL setrtin01 = 0, setrtin02 = 0, optrt = 0;
	FL minrt = 0, maxrt = 0;
	FL flow = 0;
	FL minmidrt = 0, maxmidrt = 0;
	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0;
	}
	//Setpoint Room Temperature
	//**************************************************************************//
	setrtin01 = in01 - 1;
	setrtin02 = in02 + 1;

	//Optimum Room Temperature
	//**************************************************************************//
	
	if (in01 == in02 || in01 > in02)
	{
		ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0;
		ou08 = 1;
	}
	else
	{
		optrt = (setrtin01 + setrtin02) / 2;


		minmidrt = (in01 + ((optrt - in01) / 2));
		maxmidrt = (in02 - ((in02 - optrt) / 2));
		((optrt - minmidrt) > 1) ? (minmidrt = (in01 + 1)) : (minmidrt);
		((maxmidrt - optrt) > 1) ? (maxmidrt = (in02 - 1)) : (maxmidrt);

		minrt = in01 - 2;
		maxrt = in02 + 2;


		//Room Temperature
		//**************************************************************************//
		avrgrt = in03;

		//Zone Analyse
		//**************************************************************************//
		flow = 1;
		grmin = 0;
		grmax = 100;

		twoRamp(&avrgrt, &flow, &minmidrt, &grmin, &minrt, &grmax, &nu01, &ou01, io->__s01);//toCold      //twoRamp(&avrgrt, &flow, &optrt, &grmin, &minrt, &grmax, &nu01, &ou01, io->__s01);//toCold 13-10-2022 aangepast
		twoRamp(&avrgrt, &flow, &minmidrt, &grmin, &setrtin01, &grmax, &nu01, &ou02, io->__s02);//Cold    //twoRamp(&avrgrt, &flow, &optrt, &grmin, &setrtin01, &grmax, &nu01, &ou02, io->__s02);//Cold
		twoRamp(&avrgrt, &flow, &maxmidrt, &grmin, &setrtin02, &grmax, &nu01, &ou03, io->__s03);//Hot    //	twoRamp(&avrgrt, &flow, &optrt, &grmin, &setrtin02, &grmax, &nu01, &ou03, io->__s03);//Hot   
		twoRamp(&avrgrt, &flow, &maxmidrt, &grmin, &maxrt, &grmax, &nu01, &ou04, io->__s04);//toHot      //	twoRamp(&avrgrt, &flow, &optrt, &grmin, &maxrt, &grmax, &nu01, &ou04, io->__s04);//toHot
		ou05 = optrt;
		ou06 = minmidrt;
		ou07 = maxmidrt;
		ou08 = 0;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08;

}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 13
//**********************************************************************************************************************************************//
void el01_13_libenigma01(EL01_13_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou10 = 0, ou11 = 0, ou12 = 0;

	//Variable Local
	//**************************************************************************//

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10, ou11 = *io->Output11, ou12 = *io->Output12;

	//Output Heat Valve
	//**************************************************************************//
	if (in01 < 25)
	{
		ou01 = 1, ou02 = 0, ou03 = 0;
	}
	else if (in01 > 75 )
	{
		ou01 = 0, ou02 = 0, ou03 = 1;
	}
	else
	{
		ou01 = 0, ou02 = 1, ou03 = 0;
	}
	//Output Cool Valve
	//**************************************************************************//
	if (in02 < 25)
	{
		ou04 = 1, ou05 = 0, ou06 = 0;
	}
	else if (in02 > 75)
	{
		ou04 = 0, ou05 = 0, ou06 = 1;
	}
	else
	{
		ou04 = 0, ou05 = 1, ou06 = 0;
	}
	//Output Supply Air Valve
	//**************************************************************************//
	if (in03 < 25)
	{
		ou07 = 1, ou08 = 0, ou09 = 0;
	}
	else if (in03> 75)
	{
		ou07 = 0, ou08 = 0, ou09 = 1;
	}
	else
	{
		ou07 = 0, ou08 = 1, ou09 = 0;
	}
	//Output Exhaust Air Valve
	//**************************************************************************//
	if (in04 < 25)
	{
		ou10 = 1, ou11 = 0, ou12 = 0;
	}
	else if (in04> 75)
	{
		ou10 = 0, ou11 = 0, ou12 = 1;
	}
	else
	{
		ou10 = 0, ou11 = 1, ou12 = 0;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10, *io->Output11 = ou11, *io->Output12 = ou12;

}



//**********************************************************************************************************************************************//
//Main Function - Enigma Block 14
//**********************************************************************************************************************************************//
void el01_14_libenigma01(EL01_14_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in10 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0;

	//Variable Local
	//**************************************************************************//
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0;
	FL he01 = 0, he02 = 0, he03 = 0, he04 = 0, co01 = 0, co02 = 0, co03 = 0, co04 = 0;


	FL ex01 = 0, ex02 = 0, ex03 = 0, ex04 = 0;
	FL power1 = 0, power2 = 0, power3 = 0, power4 = 0;
	FL add01 = 0, add02 = 0, add03 = 0, add04 = 0, add05 = 0, add06 = 0;


	FL grmin = 0, grmax = 0;
	FL grmin1 = 0, grmax1 = 0;
	FL nu01 = 0;
	FL setpwin01 = 0, setpwin02 = 0, setpwin03 = 0, setpwin04 = 0;
	FL flow = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10;
	ou01 = *io->Output01, ou02 = *io->Output02;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0;
	}
	//Calculations
	//**************************************************************************//
	x01 = (in07 / in06) * 100;
	x02 = (in08 / in06) * 100;
	x03 = (in09 / in06) * 100;
	x04 = (in10 / in06) * 100;
	
	setpwin01 = (x01 + x01 + x03 + x04) / 4;
	setpwin02 = (x01 + x03 + x03 + x04) / 4;
	setpwin03 = (x02 + x02 + x03 + x04) / 4;
	setpwin04 = (x02 + x03 + x03 + x04) / 4;

	//Zone Analyse
	//**************************************************************************//
	flow = 1;
	grmin = 30;
	grmax = 60;
	grmin1 = 2.2;
	grmax1 = 0.2;

	twoRamp(&setpwin01, &flow, &grmin, &grmin1, &grmax, &grmax1, &nu01, &power1, io->__s01);//Power1- Heating
	twoRamp(&setpwin02, &flow, &grmin, &grmin1, &grmax, &grmax1, &nu01, &power2, io->__s02);//Power2- Heating
	twoRamp(&setpwin03, &flow, &grmin, &grmin1, &grmax, &grmax1, &nu01, &power3, io->__s03);//Power1- Cooling
	twoRamp(&setpwin04, &flow, &grmin, &grmin1, &grmax, &grmax1, &nu01, &power4, io->__s04);//Power2- Cooling

	//Step 2 Heat Temperature Output
	//**************************************************************************//
	//Calculations Step2 SAHEAT1
	he01 = in05 - in01;
	he02 = x01 / 100;
	ex01 = powf(he02, power1);
	add02 = ex01 * he01;

	add01 = add02  + in01;

	//Step 2 Cool Temperature Output
	//**************************************************************************//
	//Calculations Step SACOOl1
	co01 = in03 - in02;
	co02 = x02 / 100;
	ex03 = powf(co02, power3);
	add05 = ex03 * co01;

	add04 = add05 + in02;

	ou01 = add01;
	ou02 = add04;

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02;

}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 15
//**********************************************************************************************************************************************//
void el01_15_libenigma01(EL01_15_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0;

	//Variable Local
	//**************************************************************************//
	FL roomquality = 0;
	FL setrqinhigh = 0, setrqinlow = 0;


	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04;

	//Initialization
	//**************************************************************************//

	//Setpoint Room Temperature
	//**************************************************************************//
	setrqinhigh = in01;
	setrqinlow = in02;

	//Room Temperature
	//**************************************************************************//
	roomquality = in03;

	//Zone Analyse
	//**************************************************************************//
	if (in01 == in02 || in01 < in02)
	{
		ou01 = 0, ou02 = 0, ou03 = 0;
		ou04 = 1;
	}
	else
	{
		(roomquality > setrqinhigh) ? (ou01 = 1) : (ou01 = 0);
		(roomquality < setrqinhigh && roomquality > setrqinlow) ? (ou02 = 1) : (ou02 = 0);
		(roomquality < setrqinlow) ? (ou03 = 1) : (ou03 = 0);
		ou04 = 0;
	}



	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04;

}

//**********************************************************************************************************************************************//
//Main Function - Enigma Block 98 -- Roomcontroller
//**********************************************************************************************************************************************//
void el01_98_libenigma01(EL01_98_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0;

	BIT in08 = 0;


	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0;

	//Variable Local
	//**************************************************************************/
	FL grmin1 = 0, grmax1 = 0;
	FL grmin2 = 0, grmax2 = 0;
	FL grmin3 = 0, grmax3 = 0;
	FL grmin4 = 0, grmax4 = 0;
	FL grmin5 = 0, grmax5 = 0;
	FL grmin6 = 0, grmax6 = 0;

	UI status01 = 0;
	FL flow = 0;
	FL nu01 = 0;
	FL tex = 0, qex = 0, sex = 0, rex = 0, thy = 0, qhy = 0;
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0, x05 = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08;
	
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0, *io->__s06 = 0;
	}

	//Day - Night
//**************************************************************************//
	if (in08 == 1)
	{

		//Calculations Timers
		//**************************************************************************//
		flow = 1;
		grmin1 = 5;
		grmin2 = 1.5;

		grmax1 = 120;
		grmax2 = 0.5;

		twoRamp(&in05, &flow, &grmin1, &grmin2, &grmax1, &grmax2, &nu01, &x01, io->__s01);//Time to cold
		twoRamp(&in06, &flow, &grmin1, &grmin2, &grmax1, &grmax2, &nu01, &x02, io->__s02);//Time to hot
		(x01 <= x02) ? (x05 = x01) : (x05 = x02);//

		x03 = in01 + in02; // Power Heating + Cooling
		x04 = in03 + in04; // Power Supply + Return
		grmin3 = 2;
		grmin4 = 0.4;//only for qex
		grmax3 = 6;
		grmax4 = 0.1;
		twoRamp(&x03, &flow, &grmin3, &x05, &grmax3, &grmax4, &nu01, &tex, io->__s03);//Exponent Temperature
		twoRamp(&x04, &flow, &grmin3, &grmin4, &grmax3, &grmax4, &nu01, &qex, io->__s04);//Exponent Quality
		twoRamp(&in03, &flow, &grmin3, &x05, &grmax3, &grmax4, &nu01, &sex, io->__s05);//Exponent Supply Air 
		twoRamp(&in04, &flow, &grmin3, &x05, &grmax3, &grmax4, &nu01, &rex, io->__s06);//Exponent Return Air 

		//Room Selector
		//**************************************************************************//
		if (in07 == 5)
		{
			status01 = 1;
			// Conference Room
		}
		else
		{
			status01 = 2;
		}
		//Rythem Status Day
		//**************************************************************************//
		switch (status01)
		{
		case 1://Conference Room
			thy = 0.5;
			qhy = 0;
			tex = 0.5;
			qex = 0.1;
			sex = 0.5;
			rex = 0.5;
			ou07 = 1;
			break;
		case 2://Normal Rooms
			thy = 1;
			qhy = 1;
			ou07 = 2;
			break;
		}
	}
	else
	{
		tex = 1.5;
		qex = 1.5;
		sex = 2;
		rex = 2;
		thy = 1;
		qhy = 1;
		ou07 = 0;
	}


	ou01 = tex;
	ou02 = qex;
	ou03 = sex;
	ou04 = rex;
	ou05 = thy;
	ou06 = qhy;

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07;

}


	//**********************************************************************************************************************************************//
	//Main Function - Enigma Block 99
	//**********************************************************************************************************************************************//
void el01_99_libenigma01(EL01_99_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0;
	BIT	in04 = 0, in05 = 0;

	//Variable Output
	//**************************************************************************//
	BIT ou04 = 0, ou05 = 0;
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou09 = 0, ou10 = 0, ou11 = 0, ou12 = 0, ou13 = 0, ou14 = 0, ou15 = 0, ou16 = 0;

	//Variable Local
	//**************************************************************************//


	FL grmin = 0, grmax = 0;
	FL grmin1 = 0, grmax1 = 0;
	FL grmin2 = 0, grmax2 = 0;
	FL grmin3 = 0, grmax3 = 0;
	FL grmin4 = 0, grmax4 = 0;
	FL grmin5 = 0, grmax5 = 0;

	FL grmin6 = 0, grmax6 = 0;
	FL grmin7 = 0, grmax7 = 0;
	FL opt = 0, optrt = 0;


	FL nu01 = 0;
	UI status01 = 0, status02 = 0;
	UI time01 = 0, time02 = 0, time03 = 0;
	FL flow = 0;

	FL thigh = 0, tlow = 0;
	FL qhigh = 0, qlow = 0;

	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05;
	ou01 = *io->Output01, ou02 = *io->Output02, ou03 = *io->Output03, ou04 = *io->Output04, ou05 = *io->Output05, ou06 = *io->Output06, ou07 = *io->Output07, ou08 = *io->Output08, ou09 = *io->Output09, ou10 = *io->Output10,
		ou11 = *io->Output11, ou12 = *io->Output12, ou13 = *io->Output13, ou14 = *io->Output14, ou15 = *io->Output15, ou16 = *io->Output16;

	//Initialization
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0, *io->__s02 = 0, *io->__s03 = 0, *io->__s04 = 0, *io->__s05 = 0;
	}
	//Time
	//**************************************************************************//
	PLUGIN_ZEIT b;
	PLUGIN_GetLocalTime(&b);
	time01 = b.uiMinute;
	time02 = b.uiHour;
	time03 = b.uiMonth;

	//Supply Air Temperature
	//**************************************************************************//

	flow = 1;
	grmin2 = 10;
	grmin3 = 16;

	grmax2 = 20;
	grmax3 = 12;
	twoRamp(&in01, &flow, &grmin2, &grmin3, &grmax2, &grmax3, &nu01, &ou14, io->__s03);//Supply Air Minimum Temperature

	grmin4 = 10;
	grmin5 = 30;

	grmax4 = -5;
	grmax5 = 45;
	twoRamp(&in01, &flow, &grmin4, &grmin5, &grmax4, &grmax5, &nu01, &ou15, io->__s04);//Supply Air Maximum Temperature


	//Leakrate
	//**************************************************************************//

	grmin6 = -10;
	grmin7 = 0.6;

	grmax6 = 23;
	grmax7 = 0.4;

	opt = 15;
	optrt = 0.2;

	threeRamp(&in01, &flow, &grmin6, &grmin7, &opt, &optrt, &grmax6, &grmax7, &nu01, &ou16, io->__s05);//leakrate


	//Day - Night
	//**************************************************************************//
	if (in05 == 1)
	{
		thigh = 21.5;
		tlow = 20.5;


		//Hour status
		//**************************************************************************//
		if (time02 == 8 || time02 == 9)
		{
			status01 = 1;
		}
		else if (time02 == 10 || time02 == 11 || time02 == 12)
		{
			status01 = 2;
		}
		else if (time02 == 13 || time02 == 14)
		{
			status01 = 3;
		}
		else if (time02 == 15 || time02 == 16 || time02 == 17 || time02 == 18)
		{
			status01 = 4;
		}
		else
		{
			status01 = 5;
		}

		//Month status
		//**************************************************************************//
		if (time03 == 1 || time03 == 2)
		{
			status02 = 1;
		}
		else if (time03 == 3 || time03 == 4)
		{
			status02 = 2;
		}
		else if (time03 == 5 || time03 == 6)
		{
			status02 = 3;
		}
		else if (time03 == 7 || time03 == 8)
		{
			status02 = 4;
		}
		else if (time03 == 9 || time03 == 10)
		{
			status02 = 5;
		}
		else if (time03 == 11 || time03 == 12)
		{
			status02 = 6;
		}
		//Rythem Status Day
		//**************************************************************************//
		switch (status01)
		{
		case 1://Wake up

			thigh += 0.3;
			tlow += 0.3;
			ou10 = 0.3;

			if (time01 < 15 && time02 == 8)
			{
				qhigh = 100;
				qlow = 200;
				ou05 = 1;
			}
			else
			{
				qhigh = 500;
				qlow = 800;
				ou05 = 0;
			}
			break;

		case 2://Morning Production
			thigh += 0.1;
			tlow += 0.1;
			ou10 = 0.1;

			if (time01 < 15 && time02 == 10)
			{
				qhigh = 100;
				qlow = 200;
				ou05 = 1;
			}
			else
			{
				qhigh = 500;
				qlow = 800;
				ou05 = 0;
			}
			break;
		case 3://Afternoon Break 
			ou10 = 0;

			if (time01 < 15 && time02 == 13)
			{
				qhigh = 100;
				qlow = 200;
				ou05 = 1;
			}
			else
			{
				qhigh = 500;
				qlow = 800;
				ou05 = 0;
			}
			break;
		case 4://Afternoon Production
			thigh -= 0.3;
			tlow -= 0.3;
			ou10 = 0 - 0.3;

			if (time01 < 15 && time02 == 15)
			{
				qhigh = 100;
				qlow = 200;
				ou05 = 1;
			}
			else
			{
				qhigh = 500;
				qlow = 800;
				ou05 = 0;
			}
			break;
		case 5://in between
			qhigh = 800;
			qlow = 1200;
			ou10 = 98;
			break;
		default:
			ou10 = 99;
			break;
		}

		//Rythem Status Month
		//**************************************************************************//
		switch (status02)
		{
		case 1://January February
			if (in01 <= 10 && in01 > 5)
			{
				thigh += 0.2;
				tlow += 0.2;
				ou11 = 0.2;
			}
			else if (in01 <= 5 && in01 > 0)
			{
				thigh += 0.3;
				tlow += 0.3;
				ou11 = 0.3;
			}
			else if (in01 <= 0)
			{
				thigh += 0.5;
				tlow += 0.5;
				ou11 = 0.5;
			}
			else
			{
				ou11 = 0;
			}
			ou13 = 30;
			break;
		case 2://March April
			if (in01 >= 15 && in01 < 20)
			{
				thigh -= 0.2;
				tlow -= 0.2;
				ou11 = 0 - 0.2;
			}
			else if (in01 >= 20)
			{
				thigh -= 0.3;
				tlow -= 0.3;
				ou11 = 0 - 0.3;
			}
			else
			{
				ou11 = 0;
			}
			ou13 = 25;
			break;
		case 3://May June
			if (in01 >= 15 && in01 < 20)
			{
				thigh -= 0.3;
				tlow -= 0.3;
				ou11 = 0 - 0.3;
			}
			else if (in01 >= 20 && in01 < 23)
			{
				thigh -= 0.4;
				tlow -= 0.4;
				ou11 = 0 - 0.4;
			}
			else if (in01 >= 23)
			{
				flow = 1;
				grmin = 23;
				grmax = 28;
				grmin1 = 0.0;
				grmax1 = 2.5;
				twoRamp(&in01, &flow, &grmin, &grmin1, &grmax, &grmax1, &nu01, &ou12, io->__s01);//Summer night release and temperure ramp

				thigh += ou12;
				ou11 = ou12;
				tlow -= 0.3;
				ou03 = 1;
				ou04 = 1;
			}
			else
			{
				thigh -= 0.1;
				tlow -= 0.1;
				ou11 = 0 - 0.1;
			}
			ou13 = 20;
			break;
		case 4://July August
			if (in01 >= 15 && in01 < 20)
			{
				thigh -= 0.4;
				tlow -= 0.4;
				ou11 = 0 - 0.4;
			}
			else if (in01 >= 20 && in01 < 23)
			{
				thigh -= 0.5;
				tlow -= 0.5;
				ou11 = 0 - 0.5;
			}
			else if (in01 >= 23)
			{
				flow = 1;
				grmin = 23;
				grmax = 28;
				grmin1 = 0.0;
				grmax1 = 2.5;
				twoRamp(&in01, &flow, &grmin, &grmin1, &grmax, &grmax1, &nu01, &ou12, io->__s02);//Summer night release and temperure ramp

				thigh += ou12;
				ou11 = ou12;
				tlow -= 0.5;
				ou03 = 1;
				ou04 = 1;
			}
			else
			{
				thigh -= 0.2;
				tlow -= 0.2;
				ou11 = 0 - 0.2;
			}
			ou13 = 20;
			break;
		case 5://September October
			if (in01 <= 15 && in01 > 10)
			{
				thigh += 0.2;
				tlow += 0.2;
				ou11 = 0.2;
			}
			else if (in01 <= 10 && in01 > 5)
			{
				thigh += 0.3;
				tlow += 0.3;
				ou11 = 0.3;
			}
			else if (in01 <= 5)
			{
				thigh += 0.4;
				tlow += 0.4;
				ou11 = 0.4;
			}
			else
			{
				ou11 = 0;
			}
			ou13 = 25;
			break;
		case 6://November December
			if (in01 <= 10 && in01 > 5)
			{
				thigh += 0.3;
				tlow += 0.3;
				ou11 = 0.3;
			}
			else if (in01 <= 5 && in01 > 0)
			{
				thigh += 0.5;
				tlow += 0.5;
				ou11 = 0.5;
			}
			else if (in01 <= 0)
			{
				thigh += 0.6;
				tlow += 0.6;
				ou11 = 0.6;
			}
			else
			{
				ou11 = 0;
			}
			ou13 = 30;
			break;
		default:
			ou11 = 99;
			ou13 = 20;
			break;
		}


		//Intern or extern setpoint
		//**************************************************************************//
		if (in04 == 1)
		{
			thigh += in02;
			tlow += in03;
			qhigh = 500;
			qlow = 800;
		}
	}
	else
	{
		thigh = 25;
		tlow = 17;
		qhigh = 800;
		qlow = 1200;
		ou13 = 25;
	}


		ou01 = status01;
		ou02 = status02;
		ou06 = thigh;
		ou07 = tlow;
		ou08 = qhigh;
		ou09 = qlow;

		//Write Output
		//**************************************************************************//
		*io->Output01 = ou01, *io->Output02 = ou02, *io->Output03 = ou03, *io->Output04 = ou04, *io->Output05 = ou05, *io->Output06 = ou06, *io->Output07 = ou07, *io->Output08 = ou08, *io->Output09 = ou09, *io->Output10 = ou10,
		*io->Output11 = ou11, *io->Output12 = ou12, *io->Output13 = ou13, *io->Output14 = ou14, *io->Output15 = ou15, *io->Output16 = ou16;

}





