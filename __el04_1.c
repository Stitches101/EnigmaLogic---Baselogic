
static PLUGIN_TCP *tcp1 = NULL;
static PLUGIN_TCP *tcp2 = NULL;
static TCPS_SRV *tcps1 = NULL; 
static TCP_STREAM *tcpss = NULL;


static TCPS_SRV *tcps3 = NULL;
static TCP_STREAM *tcpss1 = NULL;

static TCP_STREAM *tcps2 = NULL;
//**********************************************************************************************************************************************//
//Main Function - EL04_01: TCP Server Connection Lean
//**********************************************************************************************************************************************//
void el04_1_libenigma01(EL04_1_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	BIT in01 = 0;
	FL in02 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0;
	UI in03;


	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou09 = 0;
	ULI ou02 = 0;
	ULI ou03 = 0;
	UI ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou10 = 0;


	//Variable Local
	//**************************************************************************//
	FL dataIn01 = 0;

	//Settings
	//**************************************************************************//
	FL poort = 59885;
	FL bytesIn = 0;
	FL bytesOut = 0;
	FL bytesRet = 0;



	//Read Input/Outputs
	//**************************************************************************//
	in01 = *io->Input01;
	in02 = *io->Input02;
	in03 = *io->Input03;
	in04 = *io->Input04;
	in05 = *io->Input05;
	in06 = *io->Input06;
	in07 = *io->Input07;

	ou01 = *io->Output01;
	ou02 = *io->Output02;
	ou03 = *io->Output03;
	ou04 = *io->Output04;
	ou05 = *io->Output05;
	ou06 = *io->Output06;
	ou07 = *io->Output07;
	ou08 = *io->Output08;
	ou09 = *io->Output09;
	ou10 = *io->Output10;


	//Set NULL
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0;
		*io->__s02 = 0;
		*io->__s03 = 0;
		*io->__b01 = 0;
		*io->__b02 = 0;


		UI Count03;
		for (Count03 = 0; Count03 < 100; Count03++)
		{
			{
				*((io->__sa01) + Count03) = 0;
			}
		}
	}

	//Buffer
	//**************************************************************************//

	UC buf1[4096];
	UC buf2[4096];





	//Initialisation
	//**************************************************************************//
	if (in01 > 0 && tcps3 == 0)
	{

		tcps3 = TCPSSRV_CreateServer(poort);//TCPS_SRV*   TCPSSRV_CreateServer    (int iPort);
		ou01 = TCPSSRV_AcceptRequested(tcps3);//aBOOL       TCPSSRV_AcceptRequested (TCPS_SRV* pTCPSSRV);
		ou02 = tcps3;
		ou03 = tcpss1;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 98;
		ou09 = 98;
		ou10 = 98;

	}
	else if (tcps3 > 0)
	{
		ou07 = 1;
		if (TCPSSRV_AcceptRequested(tcps3))
		{
			ou07 = 2;
			*io->__s01 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
			tcpss1 = TCPSSRV_Accept(tcps3, 10000);// TCP_STREAM* TCPSSRV_Accept(TCPS_SRV* pTCPSSRV, int iTimeoutMS);

			if (tcpss1 > 0)
			{
				ou07 = 3;
				if (TCPS_ConnectNblkComplete(tcpss1) == 0)
				{
					ou07 = 4;
					if (TCPS_GetRemotePort(tcpss1) > 0)
					{
						ou07 = 5;
						*io->__s01 = 5;

					}
				}
			}

		}



		//Send and Recieve Socket
		//**************************************************************************//
		if (*io->__s01 == 5)
		{
			ou08 = 0;
			//sprintf(buf1, "test %.2f", in02);

			*((io->__sa01) + 1) = *io->Input02;
			*((io->__sa01) + 2) = *io->Input04;
			*((io->__sa01) + 3) = *io->Input05;
			*((io->__sa01) + 4) = *io->Input06;
			*((io->__sa01) + 5) = *io->Input07;


			//sprintf(buf1, "server data %.2f", *(io->__sa01));

			UC *pos = buf1;
			UI Count;
			for (Count = 0; Count != 4; Count++) {
				if (Count) {
					pos += sprintf(pos, ", ");
				}
				pos += sprintf(pos, "%.2f", *((io->__sa01) + Count)); 
			}


			UC *pbuf1 = buf1;

			*io->__s02 = sizeof(buf1);




			//Casting
			//**************************************************************************//
			bytesIn = TCPS_ReceiveData(tcpss1, buf2, sizeof(buf2) + 1, 1000);
			*io->__b01 += bytesIn;
			sscanf(buf2, "%f%", &dataIn01);


			if (bytesIn > 0)
			{
				*io->__s04 = dataIn01;
				while (*io->__s02 > 0)
				{
					bytesOut = TCPS_SendData(tcpss1, buf1, sizeof(buf1) + 1);
					*io->__s03 = bytesOut;
					ou08 = 2;
					*io->__b02 += bytesOut;
					*io->__s02 -= *io->__s03;
				}

			}
		}
		else
		{
			*io->__s01 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
		}
		//Disconect and Close Socket
		//**************************************************************************//
		if (in01 == 0)
		{
			TCPSSRV_RemoveServer(&tcps3);
			TCPS_Disconnect(&tcpss1);
			*io->__s01 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
		}
		//Set Outputs
		//**************************************************************************//
		ou01 = TCPSSRV_AcceptRequested(tcps3);
		ou02 = tcps3;
		ou03 = tcpss1;
		ou04 = *io->__s02;
		ou05 = *io->__b01;
		ou06 = *io->__b02;
		ou09 = *io->__s04;
		ou10 = bytesOut;

	}
	else if (in01 == 0)
	{
		TCPSSRV_RemoveServer(&tcps3);//void        TCPSSRV_RemoveServer    (TCPS_SRV** ppTCPSSRV);
		TCPS_Disconnect(&tcpss1);
		ou01 = TCPSSRV_AcceptRequested(tcps3);
		ou02 = tcps3;
		ou03 = tcpss1;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 0;
		ou09 = 0;
		ou10 = 0;
	}
	else
	{
		ou01 = TCPSSRV_AcceptRequested(tcps3);
		ou02 = tcps3;
		ou03 = tcpss1;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 9884;
		ou09 = 9884;
		ou10 = 9884;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01;
	*io->Output02 = ou02;
	*io->Output03 = ou03;
	*io->Output04 = ou04;
	*io->Output05 = ou05;
	*io->Output06 = ou06;
	*io->Output07 = ou07;
	*io->Output08 = ou08;
	*io->Output09 = ou09;
	*io->Output10 = ou10;
}
//**********************************************************************************************************************************************//
//Function Declarations
//**********************************************************************************************************************************************//



//**********************************************************************************************************************************************//
//Main Function - EL04_02: TCP Server Connection Lean
//**********************************************************************************************************************************************//
void el04_2_libenigma01(EL04_2_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	BIT in01 = 0;
	FL in02 = 0; 
	UI in03;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0;
	ULI ou02 = 0;
	BIT ou03 = 0;
	UI ou04 = 0;

	//Variable Local
	//**************************************************************************//
	BIT x02 = 0;
	UI x03 = 0;
	FL __s01;

	//Settings
	//**************************************************************************//
	UC ipaddr[20] = "127.0.0.1";
	FL poort = 59884;
	//FL poort = 3030;
	//Read Input/Outputs
	//**************************************************************************//
	in01 = *io->Input01;
	in02 = *io->Input02;
	in03 = *io->Input03;

	ou01 = *io->Output01;
	ou02 = *io->Output02;
	ou03 = *io->Output03;
	ou04 = *io->Output04;

	//Set NULL
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0;

	}

	//Buffer
	//**************************************************************************//

	UC buf1[25];


	//Casting
	//**************************************************************************//
	sprintf(buf1, "test %.2f", in02);


	//Initialisation
	//**************************************************************************//
	if (in01 > 0 && tcp2 == 0)
	{
		tcp2 = PLUGIN_TcpConnectNblkInit(ipaddr, poort);
		x03 = PLUGIN_TcpGetStatus(tcp2);

		ou01 = PLUGIN_TcpConnectionsAvailable();
		ou02 = tcp2;
		ou03 = 2300;
		ou04 = x03;

	}
	else if (tcp2 > 0) {

		//*io->__s01 += 1;
		x03 = PLUGIN_TcpGetStatus(tcp2);

		//Data Transmitting
		//**************************************************************************//
		//	Rueckgabewert:
		//0                       Undefinierter Zustand von pTCP
		//1                       Der Verbindungsaufbau wurde initiiert, aber noch nicht abgeschlossen
		//2                       Es besteht keine TCP - Verbindung
		//3                       Die TCP - Verbindung besteht

		if (x03 == 0)
		{
			x02 = 0;
		}
		if (x03 == 1)
		{
			x02 = 1;
		}
		if (x03 == 2)
		{
			x02 = 2;
		}
		if (x03 == 3)
		{
			PLUGIN_TcpConnectNblkComplete(tcp2);
			PLUGIN_TcpSendData(tcp2, buf1, 15);
			x02 = 3;
		}


		//Disconect en Close Socket
		//**************************************************************************//
		if (in01 == 0) {
		
			PLUGIN_TcpDisconnect(&tcp2);
		
		}
		//Set Outputs
		//**************************************************************************//
		ou01 = PLUGIN_TcpConnectionsAvailable();
		ou02 = tcp2;
		ou03 = PLUGIN_TcpConnectNblkComplete(tcp2);
		ou04 = x03;
	}
	else if (in01 == 0)
	{
			PLUGIN_TcpDisconnect(&tcp2);
			*io->__s01 = 0;
			ou01 = 98;
			ou02 = tcp2;
			ou03 = PLUGIN_TcpConnectionsAvailable();
			ou04 = PLUGIN_TcpGetStatus(tcp2);
	}
	else
	{
		*io->__s01 = 0;
		ou01 = 9884;
		ou02 = tcp2;
		ou03 = 0;
		ou04 = 0;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01;
	*io->Output02 = ou02;
	*io->Output03 = ou03;
	*io->Output04 = ou04;
}
	

//**********************************************************************************************************************************************//
//Main Function - EL04_03: TCP Server Connection Lean
//**********************************************************************************************************************************************//
void el04_3_libenigma01(EL04_3_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	BIT in01 = 0;
	FL in02 = 0;
	UI in03;


	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou09 = 0;
	ULI ou02 = 0;
	ULI ou03 = 0;
	UI ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou10 = 0;


	//Variable Local
	//**************************************************************************//
	FL dataIn01 = 0;

	//Settings
	//**************************************************************************//
	FL poort = 59880;
	FL bytesIn = 0;
	FL bytesOut = 0;
	FL bytesRet = 0;



	//Read Input/Outputs
	//**************************************************************************//
	in01 = *io->Input01;
	in02 = *io->Input02;
	in03 = *io->Input03;

	ou01 = *io->Output01;
	ou02 = *io->Output02;
	ou03 = *io->Output03;
	ou04 = *io->Output04;
	ou05 = *io->Output05;
	ou06 = *io->Output06;
	ou07 = *io->Output07;
	ou08 = *io->Output08;
	ou09 = *io->Output09;
	ou10 = *io->Output10;


	//Set NULL
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0;
		*io->__s02 = 0;
		*io->__s03 = 0;
		*io->__b01 = 0;
		*io->__b02 = 0;
	}

	//Buffer
	//**************************************************************************//

	UC buf1[4096];
	UC buf2[4096];





	//Initialisation
	//**************************************************************************//
	if (in01 > 0 && tcps1 == 0)
	{
		tcps1 = TCPSSRV_CreateServer(poort);
		ou01 = TCPSSRV_AcceptRequested(tcps1);
		ou02 = tcps1;
		ou03 = tcpss;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 98;
		ou09 = 98;
		ou10 = 98;

	}
	else if (tcps1 > 0) 
	{
		ou07 = 1;
		if (TCPSSRV_AcceptRequested(tcps1))
		{
			ou07 = 2;
			*io->__s01 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
			tcpss = TCPSSRV_Accept(tcps1, 10000);

			if (tcpss > 0)
			{
				ou07 = 3;
				if (TCPS_ConnectNblkComplete(tcpss) == 0)
				{
					ou07 = 4;
					if (TCPS_GetRemotePort(tcpss) > 0)
					{
						ou07 = 5;
						*io->__s01 = 5;
						
					}
				}
			}

		}
		//Send and Recieve Socket
		//**************************************************************************//
		if (*io->__s01 == 5)
		{
			ou08 = 0;
			sprintf(buf1, "test %.2f", in02);
			*io->__s02 = sizeof(buf1);
			//Casting
			//**************************************************************************//
			

			bytesIn = TCPS_ReceiveData(tcpss, buf2, sizeof(buf2) + 1, 1000);
			*io->__b01 += bytesIn;
			sscanf(buf2, "%f%", &dataIn01);
			

			if (bytesIn > 0)
			{
				*io->__s04 = dataIn01;
				while (*io->__s02 > 0)
				{
					bytesOut = TCPS_SendData(tcpss, buf1, sizeof(buf1) + 1);
					*io->__s03 = bytesOut;
					ou08 = 2;
					*io->__b02 += bytesOut;
					*io->__s02 -= *io->__s03;
				}
			
			}
		}
		else
		{
			*io->__s01 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
		}
		//Disconect and Close Socket
		//**************************************************************************//
		if (in01 == 0) 
		{
			TCPSSRV_RemoveServer(&tcps1);
			TCPS_Disconnect(&tcpss);
			*io->__s01 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
		}
		//Set Outputs
		//**************************************************************************//
		ou01 = TCPSSRV_AcceptRequested(tcps1);
		ou02 = tcps1;
		ou03 = tcpss;
		ou04 = *io->__s02;
		ou05 = *io->__b01;
		ou06 = *io->__b02;
		ou09 = *io->__s04;
		ou10 = bytesOut;
		
	}
	else if (in01 == 0)
	{
		TCPSSRV_RemoveServer(&tcps1);
		TCPS_Disconnect(&tcpss);
		ou01 = TCPSSRV_AcceptRequested(tcps1);
		ou02 = tcps1;
		ou03 = tcpss;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 0;
		ou09 = 0;
		ou10 = 0;
	}
	else
	{
		ou01 = TCPSSRV_AcceptRequested(tcps1);
		ou02 = tcps1;
		ou03 = tcpss;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 9884;
		ou09 = 9884;
		ou10 = 9884;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01;
	*io->Output02 = ou02;
	*io->Output03 = ou03;
	*io->Output04 = ou04;
	*io->Output05 = ou05;
	*io->Output06 = ou06;
	*io->Output07 = ou07;
	*io->Output08 = ou08;
	*io->Output09 = ou09;
	*io->Output10 = ou10;
}
//**********************************************************************************************************************************************//
//Function Declarations
//**********************************************************************************************************************************************//


//**********************************************************************************************************************************************//
//Main Function - EL04_04: TCP Server2 Connection Lean
//**********************************************************************************************************************************************//
void el04_4_libenigma01(EL04_4_LIBENIGMA01 *io)
{
	//Variable Input
	//**************************************************************************//
	BIT in01 = 0;
	FL in02 = 0;
	UI in03;


	//Variable Output
	//**************************************************************************//
	BIT ou01 = 0;
	BIT ou02 = 0;
	BIT ou03 = 0;
	UI ou04 = 0;

	//Variable Local
	//**************************************************************************//
	BIT x02 = 0;
	UI x03 = 0;
	FL __s01;

	//Settings
	//**************************************************************************//
	FL poort = 59881;
	UC ipaddr[20] = "10.14.13.34";
	UI poort1 = 0;
	UC ipaddr1[20];

	//Read Input/Outputs
	//**************************************************************************//
	in01 = *io->Input01;
	ou01 = *io->Output01;
	ou02 = *io->Output02;
	ou03 = *io->Output03;
	ou04 = *io->Output04;


	//Set NULL
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0;
	}

	//Buffer
	//**************************************************************************//

	UC buf1[25];


	//Casting
	//**************************************************************************//
	in02 = 100;
	sprintf(buf1, "test %.2f", in02);


	//TCP_STREAM* TCPS_ConnectNblkInit(const char* cpIpAddr, int iPort);
	//aBOOL       TCPS_ConnectNblkComplete(TCP_STREAM* pTCPS);
	//void        TCPS_Disconnect(TCP_STREAM** ppTCPS);
	//TCPS_STATUS TCPS_GetStatus(TCP_STREAM* pTCPS);
	//const char* TCPS_GetRemoteIP(TCP_STREAM* pTCPS);
	//int         TCPS_GetRemotePort(TCP_STREAM* pTCPS);
	//int         TCPS_SendData(TCP_STREAM* pTCPS, const char* cpData, int iCount);
	//int         TCPS_ReceiveData(TCP_STREAM* pTCPS, char* cpBuffer, int iBufferSize, int iTimeoutMS);
	//aBOOL       TCPS_RequestSigIo(TCP_STREAM* pTCPS);
	//aBOOL       TCPS_IsDataAvailable(TCP_STREAM* pTCPS);
	//void        TCPS_SetReceiveIdleTimeout(TCP_STREAM* pTCPS, int iTimeout);



	//aBOOL SOCKET_BASE_create(SOCKET_BASE *sbThisSocket);
	//aBOOL SOCKET_BASE_bind(SOCKET_BASE *sbThisSocket, const int iPort);
	//aBOOL SOCKET_BASE_listen(SOCKET_BASE *sbThisSocket);
	//aBOOL SOCKET_BASE_accept(SOCKET_BASE *sbThisSocket, SOCKET_BASE *comm_socket);
	//aBOOL SOCKET_BASE_connect(SOCKET_BASE *sbThisSocket, const char* cpHostIP, const int iPort);
	//aBOOL SOCKET_BASE_SendData(SOCKET_BASE *sbThisSocket, const char* cpData, int iCount);
	//int   SOCKET_BASE_ReceiveData(SOCKET_BASE *sbThisSocket, const char** pcpData);
	//int   SOCKET_BASE_ReceiveDataTimeout(SOCKET_BASE *sbThisSocket, const char** pcpData, int iTimeoutSeconds);
	//aBOOL SOCKET_BASE_is_valid(SOCKET_BASE *sbThisSocket);
	//void  SOCKET_BASE_disconnect(SOCKET_BASE *sbThisSocket);


	//Initialisation
	//**************************************************************************//
	if (in01 > 0 && tcps2 == 0)
	{
		tcps2 = TCPS_ConnectNblkInit(ipaddr, poort);
		ou01 = tcps2;
		ou02 = 0;
		ou03 = 1;
		ou04 = 1;
	}
	else if (tcps2 > 0) {

		if (TCPS_ConnectNblkComplete(tcps2) == 1)
		{
			*ipaddr1 = TCPS_GetRemoteIP(tcps2);
			poort1 = TCPS_GetRemotePort(tcps2);


			
			TCPS_SendData(tcps2, buf1, 15);


			ou01 = tcps2;
			ou02 = TCPS_GetStatus(tcps2);
			ou03 = TCPS_GetStatus(tcps2);
			ou04 = 3;
		}
		else
		{
			ou01 = tcps2;
			ou02 = 0;
			ou03 = 2;
			ou04 = 2;
		}


		//Disconect en Close Socket
		//**************************************************************************//
		if (in01 == 0)
		{
			TCPS_Disconnect(&tcps2);
		}
		//Set Outputs
		//**************************************************************************//
		ou01 = tcps2;
		ou02 = 4;
		ou03 = 4;
		ou04 = 4;
	}
	else if (in01 == 0)
	{
		TCPS_Disconnect(&tcps2);
		ou01 = tcps2;
		ou02 = 25;
		ou03 = 25;
		ou04 = 25;
	}
	else
	{
		ou01 = tcps2;
		ou02 = 10;
		ou03 = 10;
		ou04 = 10;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01;
	*io->Output02 = ou02;
	*io->Output03 = ou03;
	*io->Output04 = ou04;
}
//**********************************************************************************************************************************************//
//Function Declarations
//**********************************************************************************************************************************************//


//**********************************************************************************************************************************************//
//Main Function - EL04_05: DATA Extract
//**********************************************************************************************************************************************//
void el04_5_libenigma01(EL04_5_LIBENIGMA01 *io)
{
	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou02 = 0, ou03 = 0, ou04 = 0;
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0;


	//Variable Local
	//**************************************************************************//
	FL x01 = 0, x02 = 0, x03 = 0, x04 = 0;
	char x05;
	FL el02 = 0;
	ULI i = 0;


	//Read Input/Outputs
	//**************************************************************************//
	ou01 = *io->Output01;
	ou02 = *io->Output02;
	ou03 = *io->Output03;
	ou04 = *io->Output04;

	//TCPS_SRV el;
	//TCPS_SRV *el_ptr = &el;

	//EL04_6_LIBENIGMA01 el02;
	//EL04_6_LIBENIGMA01 *el_ptr2 = &el02;
	//el02 = el04_6_libenigma01(&x05);

	//plugin_f_I_EL04_600 el02;

	x01 = tcps3->m_sock;
	x02 = tcps3->m_iLocalPort;
	//x03 = (FL*)&sps_vari[BDF_plugin_f_SP_I237];
	//x04 = el02->Input02;


	ou01 = x01;
	ou02 = x02;
	ou03 = x03;
	ou04 = x04;
	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01;
	*io->Output02 = ou02;
	*io->Output03 = ou03;
	*io->Output04 = ou04;



}

//**********************************************************************************************************************************************//
//Main Function - EL04_06: DATA Input
//**********************************************************************************************************************************************//
void el04_6_libenigma01(EL04_6_LIBENIGMA01 *io)
{
	//Variable Output
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0;





	//Read Input/Outputs
	//**************************************************************************//
	in01 = *io->Input01;
	in02 = *io->Input02;
	in03 = *io->Input03;
	in04 = *io->Input04;

	//Write Output
	//**************************************************************************//


}



