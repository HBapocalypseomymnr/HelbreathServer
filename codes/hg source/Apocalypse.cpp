In Game.cpp on CheckClientResponseTime()

////////////////////////////////////////////////
under :

				if (m_pClientList[i] == NULL) break;
				if ((m_pMapList[m_pClientList[i]->m_cMapIndex]->m_iUpperLevelLimit != 0) &&
					(m_pClientList[i]->m_iLevel > m_pMapList[m_pClientList[i]->m_cMapIndex]->m_iUpperLevelLimit) && 
					(m_pClientList[i]->m_iAdminUserLevel < 1)) {
					SendNotifyMsg(NULL, i, DEF_NOTIFY_TOBERECALLED, NULL, NULL, NULL, NULL);
					RequestTeleportHandler(i, "0   ");
				}

add
				if (m_pClientList[i] == NULL) break;
				if ((m_bIsCrusadeMode == FALSE) && (m_pClientList[i]->m_bIsInCombatantOnlyZone == TRUE) && (m_pMapList[i]->m_bIsCitizenLimit = TRUE)) {
					SendNotifyMsg(NULL, i, DEF_NOTIFY_TOBERECALLED, NULL, NULL, NULL, NULL);
					RequestTeleportHandler(i, "0   ");

				}
//////////////////////////////////////////////////
At The End iclientmotion_move_handler	

find

iSize = iComposeMoveMapData((short)(dX - 10), (short)(dY - 7), iClientH, cDir, cp);	
		iRet = m_pClientList[ iClientH ]->m_pXSock->iSendMsg(cData, iSize + 12 + 1 + 4);
		switch (iRet) {
		case DEF_XSOCKEVENT_QUENEFULL:
		case DEF_XSOCKEVENT_SOCKETERROR:
		case DEF_XSOCKEVENT_CRITICALERROR:
		case DEF_XSOCKEVENT_SOCKETCLOSED:
			DeleteClient(iClientH, TRUE, TRUE, TRUE, FALSE);
			return 0;
		}

Add
		//apocalypse gate teleport
		if (m_pMapList[m_pClientList[ iClientH ]->m_cMapIndex]->m_bIsGateAvailable == TRUE) {	
			bRet = m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->bApocalypseGateTeleporter(dX, dY, &*cTemp, &wV1, &wV2);
			if (bRet == 1) {
				RequestTeleportHandler(iClientH, "2   ", cTemp, wV1, wV2);
			}
		}

//////////////////////////////////////////////////

void CGame::RequestInitDataHandler at end add
//////////////////////////////////////////////////

		if (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_bIsGateAvailable == TRUE) {
		for (i = 0; i < cMapIndex->m_iTotalDynamicGate; i++) {
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_APOCGATEOPEN, m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_sDynamicGateX1, m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_sDynamicGateY1, NULL, m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cName);
		}
	}


////////////////////////////////////////////////
	In RequestTeleportHandler
//////////////////////////////////////////////////
find
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CONSTRUCTIONPOINT, m_pClientList[ iClientH ]->m_iConstructionPoint, m_pClientList[ iClientH ]->m_iWarContribution, 1, NULL);
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[ iClientH ]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
	
add
	if (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_bIsGateAvailable == TRUE) {
		for (iGate = 0; iGate < m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_iTotalDynamicGate; iGate++) {
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_APOCGATEOPEN, m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_sDynamicGateX1, m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_sDynamicGateY1, NULL, m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cName);
		}
	}

//////////////////////////////////////////////////
Search NpcKilledHandler. At the end add:

//////////////////////////////////////////////////
	// InferniaA
	if ((m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iTotalAliveObject == 0) &&
			(m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iApocalypseMobGenType == 1) &&
			(memcmp(m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_cName, "inferniaA", 9) == 0)) {
				m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_bIsInferniaAGate = TRUE;
	}

	// InferniaB
	if ((m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iTotalAliveObject == 0) &&
			(m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iApocalypseMobGenType == 1) &&
			(memcmp(m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_cName, "inferniaB", 9) == 0)) {
				m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_bIsInferniaBGate = TRUE;
	}

	// Procella
	if ((m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iTotalAliveObject == 0) &&
			(m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iApocalypseMobGenType == 1) &&
			(memcmp(m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_cName, "procella", 8) == 0)) {
				m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_bIsProcellaGate = TRUE;
	}

	// Abaddon
	if ((m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iTotalAliveObject == 0) && (
		m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iApocalypseMobGenType == 2)) {
		bApocalypseMobGenerator(m_pNpcList[iNpcH]->m_cMapIndex);
	}


	
	if (m_pNpcList[iNpcH]->m_bIsBossMob == TRUE) {
		iMapIndex = NULL;
		for (i = 1; i < DEF_MAXCLIENTS; i++)
		iMapIndex = m_pNpcList[iNpcH]->m_cMapIndex;
		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE) && (iMapIndex >= 0) && (iMapIndex < DEF_MAXMAPS) && (m_pMapList[iMapIndex] != NULL) && (m_pMapList[iMapIndex]->m_bInRecallImpossibleMap == TRUE)) {
				m_pClientList[i]->m_iTimeLeft_ForceRecall = 200;
				m_pClientList[i]->m_bIsImpossibleZone = TRUE;
				SendNotifyMsg(NULL, i, DEF_NOTIFY_FORCERECALLTIME,  m_pClientList[i]->m_iTimeLeft_ForceRecall , NULL, NULL, NULL);
		}
	}

////////////////////////////////

On CheckClientResponseTime() before this:

****************************************
				if (m_pClientList[i] == NULL) break;
				m_pClientList[i]->m_iSuperAttackCount++;
				if (m_pClientList[i]->m_iSuperAttackCount > 12) {					
					m_pClientList[i]->m_iSuperAttackCount = 0;
					iMaxSuperAttack = (m_pClientList[i]->m_iLevel / 10);
					if (m_pClientList[i]->m_iSuperAttackLeft < iMaxSuperAttack) m_pClientList[i]->m_iSuperAttackLeft++;
					SendNotifyMsg(NULL, i, DEF_NOTIFY_SUPERATTACKLEFT, NULL, NULL, NULL, NULL);
				}
*****************************************
add this:


		if (m_bIsApocalypseMode == TRUE) {
					if (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "abaddon", 7) == 0) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATEOPEN, 167, 169, NULL, m_pClientList[i]->m_cMapName);
					}
				}

				if (m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsGateAvailable == TRUE) {
					if (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "icebound", 8) == 0) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATEOPEN, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1, NULL, m_pClientList[i]->m_cMapName);
					}
				}

				if (m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsInferniaAGate == TRUE) {
					if (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "inferniaA", 9) == 0) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATEOPEN, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1, NULL, m_pClientList[i]->m_cMapName);
					}
				}

				if (m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsInferniaBGate == TRUE) {
					if (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "inferniaB", 9) == 0) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATEOPEN, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1, NULL, m_pClientList[i]->m_cMapName);
					}
				}

				if (m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsProcellaGate == TRUE) {
					if (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "procella", 8) == 0) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATEOPEN, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1, NULL, m_pClientList[i]->m_cMapName);
					}
				}


				if (m_pClientList[i] == NULL) break;
				if ((m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsGateAvailable == TRUE) && (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "icebound", 8) == 0) &&
					((m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2))) {
						RequestTeleportHandler(i, "2   ", m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cDynamicGateDestMap, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtX, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtY);
				}

				if ((m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsGateAvailable == TRUE) && (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "toh3", 4) == 0) &&
					((m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2))) {
						RequestTeleportHandler(i, "2   ", m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cDynamicGateDestMap, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtX, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtY);
				}

				if ((m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsInferniaAGate == TRUE) && (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "inferniaA", 9) == 0) &&
					((m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2))) {
						RequestTeleportHandler(i, "2   ", m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cDynamicGateDestMap, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtX, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtY);
				}

				if ((m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsInferniaBGate == TRUE) && (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "inferniaB", 9) == 0) &&
					((m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2))) {
						RequestTeleportHandler(i, "2   ", m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cDynamicGateDestMap, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtX, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtY);
				}

				if ((m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsProcellaGate == TRUE) && (memcmp(m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cName, "procella", 8) == 0) &&
					((m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX1 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY1) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2) ||
					(m_pClientList[i]->m_sX == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateX2 && m_pClientList[i]->m_sY == m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateY2))) {
						RequestTeleportHandler(i, "2   ", m_pMapList[m_pClientList[i]->m_cMapIndex]->m_cDynamicGateDestMap, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtX, m_pMapList[m_pClientList[i]->m_cMapIndex]->m_sDynamicGateTgtY);
				}


//////////////////////////////////////

In Game.h you have to put this functions:
	////////////////////////APOCALYPSE////////////////////////////////
	void GlobalStartApocalypseMode();
	void GlobalEndApocalypseMode();
	void LocalStartApocalypseMode(DWORD dwApocalypseGUID);
	void LocalEndApocalypseMode();
	void _CreateApocalypseGUID(DWORD dwApocalypseGUID);
	BOOL bReadApocalypseGUIDFile(char * cFn);
	void RemoveEventNpc(int);
	void AbaddonThunder();
	void SendThunder(int iClient, short sX, short sY, short sV3, short sV4);
	BOOL bApocalypseMobGenerator(int iMapIndex);
	//////////////////////////////////////////////////////////////////

Then, in Game.h too put this:
	//////////// Apocalypse ////////////
	BOOL	m_bIsApocalypseMode;
	DWORD m_dwApocalypseGUID;
	////////////////////////////////////

---------------------------------------------------------------------------------------
In Game.cpp, in this function: "ChatMsgHandler" add this:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (memcmp(cp, "/beginapocalypse ", 17) == 0) {
			if (m_pClientList[iClientH]->m_iAdminUserLevel >= 3) {
				if (m_pClientList[iClientH]->m_bIsAdminCommandEnabled == FALSE) return;
				GlobalStartApocalypseMode();

				wsprintf(G_cTxt, "GM Order(%s): beginapocalypse", 
m_pClientList[iClientH]->m_cCharName);
				bSendMsgToLS(MSGID_GAMEMASTERLOG, iClientH, NULL, G_cTxt);
			}
			return;
		}

		if (memcmp(cp, "/endapocalypse ", 15) == 0) {
			if (m_pClientList[iClientH]->m_iAdminUserLevel >= 3) {
				if (m_pClientList[iClientH]->m_bIsAdminCommandEnabled == FALSE) return;
				GlobalEndApocalypseMode();

				wsprintf(G_cTxt, "GM Order(%s): endapocalypse", 
m_pClientList[iClientH]->m_cCharName);
				bSendMsgToLS(MSGID_GAMEMASTERLOG, iClientH, NULL, G_cTxt);
			}
			return;
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




In Game.cpp search this:
+++++++++++++++++++++++
		case GSM_BEGINCRUSADE:
			cp++;
			dwp = (DWORD *)cp;
			cp += 4;
			LocalStartCrusadeMode(*dwp);
			break;
+++++++++++++++++++++++
after this add:
***********************************************
		case GSM_BEGINAPOCALYPSE:
			cp++;
			dwp = (DWORD *)cp;
			cp += 4;
			LocalStartApocalypseMode(*dwp);
			break;

		case GSM_ENDAPOCALYPSE:
			cp++;
			LocalEndApocalypseMode();
			cp += 16;
			break;
***********************************************

In Game.cpp "OnStartGameSignal()", after bReadCrusadeGUIDFile add this:
-------------------
bReadApocalypseGUIDFile("GameData\\ApocalypseGUID.txt");
-------------------

Now, in function "OnTimer()" search: CrusadeWarStarter(); after that add:

AbaddonThunder();


Now in NetMessages.h add this:
******************************
#define GSM_BEGINAPOCALYPSE							0x13
#define GSM_ENDAPOCALYPSE							0x14
******************************
Now, in Netmessages.h add this:

///////////APOCALYPSE//////////////
#define DEF_NOTIFY_NORECALL						0x0BD1
#define DEF_NOTIFY_APOCGATESTARTMSG				0x0BD2
#define DEF_NOTIFY_APOCGATEENDMSG					0x0BD3
#define DEF_NOTIFY_APOCGATEOPEN					0x0BD4
#define DEF_NOTIFY_APOCGATECLOSE					0x0BD5
#define DEF_NOTIFY_ABADDONKILLED					0x0BD6
#define DEF_NOTIFY_APOCFORCERECALLPLAYERS			0x0BD7
#define DEF_NOTIFY_MONSTERCOUNT					0x0BE3

Now, in Map.h add this:

**************************************************
	//////////////// APOCALYPSE //////////////////
	BOOL	m_bIsCitizenLimit;
	int		m_iApocalypseBossMobNpcID, m_iApocalypseMobGenType;
	RECT  m_rcApocalypseBossMobRect;
	short	m_cDynamicGateType;
	short m_sDynamicGateX1;
	short m_sDynamicGateX2;
	short m_sDynamicGateY1;
	short m_sDynamicGateY2;
	int		m_iTotalDynamicGate;
	short	m_sDynamicGateTgtX;
	short	m_sDynamicGateTgtY;
	BOOL  m_bIsRecallImpossible;
	BOOL  m_bIsApocalypseMap;
	BOOL  m_bIsBossInMap;
	BOOL  m_bIsGateMap;
	BOOL	m_bIsGateAvailable;
	BOOL  m_bIsApocalypseMobSpawn;
	BOOL	m_bIsInferniaAGate, m_bIsInferniaBGate, m_bIsProcellaGate;
	char	m_cDynamicGateDestMap[11];
	int   m_iMaximumObjectDefault;
	//////////////////////////////////////////////
*****************************************************

In Map.cpp on CMap::CMap add:

////////////////////////////////////////////////////
	m_bIsCitizenLimit = 0;
	m_iApocalypseMobGenType = 0;
	m_iApocalypseBossMobNpcID = 0;
	m_cDynamicGateType = 0;
	m_sDynamicGateX1 = 0;
	m_sDynamicGateX2 = 0;
	m_sDynamicGateY1 = 0;
	m_sDynamicGateY2 = 0;
	m_bIsGateAvailable = FALSE;
	m_bIsApocalypseMobSpawn = FALSE;
	m_iTotalDynamicGate = 0;
	m_sDynamicGateTgtX = 0;
	m_sDynamicGateTgtY = 0;
	m_bIsRecallImpossible = FALSE;
	m_bIsApocalypseMap = FALSE;
	m_bIsBossInMap = FALSE;
	m_bIsGateMap = FALSE;
	m_bIsInferniaAGate = FALSE;
	m_bIsInferniaBGate = FALSE;
	m_bIsProcellaGate = FALSE;
	m_iMaximumObjectDefault = FALSE;
/////////////////////////////////////////////////////



///////////////////////////////////
			case 25:
				switch (cReadModeB) {
				case 1:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error 78 - Wrong Data 
format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->sMobEventAmount = atoi(token);
					cReadModeB = 0;
					break;
				}
				break;

			case 26: //ApocalypseMobGenType
				if (_bGetIsStringIsNumber(token) == FALSE) {
					PutLogList("(!!!) CRITICAL ERROR! Map Info file error 
ApocalypseMobGenType - Wrong Data format.");
					delete pContents;
					delete pStrTok;
					return FALSE;
				}
				m_pMapList[iMapIndex]->m_iApocalypseMobGenType = atoi(token);
				cReadModeA = 0;
				cReadModeB = 0;
				break;

			case 27: // ApocalypseBossMob
				switch (cReadModeB) {
				case 1:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error 
ApocalypseBossMob - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_iApocalypseBossMobNpcID = atoi(token);
					cReadModeB = 2;
					break;
				case 2:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error 
ApocalypseBossMob - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_rcApocalypseBossMobRect.left = atoi(token);
					cReadModeB = 3;
					break;
				case 3:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error 
ApocalypseBossMob - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_rcApocalypseBossMobRect.top = atoi(token);
					cReadModeB = 4;
					break;
				case 4:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error 
ApocalypseBossMob - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_rcApocalypseBossMobRect.right = atoi(token);
					cReadModeB = 5;
					break;
				case 5:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error 
ApocalypseBossMob - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_rcApocalypseBossMobRect.bottom = atoi(token);
					cReadModeA = 0;
					cReadModeB = 0;
					break;
				}
				break;

			case 28: //DynamicGateType
				if (_bGetIsStringIsNumber(token) == FALSE) {
					PutLogList("(!!!) CRITICAL ERROR! Map Info file error DynamicGateType - 
Wrong Data format.");
					delete pContents;
					delete pStrTok;
					return FALSE;
				}
				m_pMapList[iMapIndex]->m_cDynamicGateType = atoi(token);
				cReadModeA = 0;
				cReadModeB = 0;
				break;

			case 29: //DynamicGateCoord
				switch (cReadModeB) {
				case 1:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error DynamicGateCoord 
-  Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sDynamicGateX1 = atoi(token);
					cReadModeB = 2;
					break;

				case 2:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error DynamicGateCoord 
-  Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sDynamicGateY1 = atoi(token);
					cReadModeB = 3;
					break;

				case 3:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error DynamicGateCoord 
-  Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sDynamicGateX2 = atoi(token);
					cReadModeB = 4;
					break;

				case 4:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error DynamicGateCoord 
-  Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sDynamicGateY2 = atoi(token);
					cReadModeB = 5;
					break;

				case 5:
					memcpy(m_pMapList[iMapIndex]->m_cDynamicGateDestMap, token, 
strlen(token));
					cReadModeB = 6;
					break;

				case 6:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error DynamicGateCoord 
-  Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sDynamicGateTgtX = atoi(token);
					cReadModeB = 7;
					break;

				case 7:
					if (_bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error DynamicGateCoord 
-  Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sDynamicGateTgtY = atoi(token);
					m_pMapList[iMapIndex]->m_iTotalDynamicGate++;
					cReadModeA = 0;
					cReadModeB = 0;
					break;
				}
				break;

			case 30: // RecallImpossible
				if (_bGetIsStringIsNumber(token) == FALSE) {
					PutLogList("(!!!) CRITICAL ERROR! Map Info file error RecallImpossible 
-  Wrong Data format.");
					delete pContents;
					delete pStrTok;
					return FALSE;
				}
				m_pMapList[iMapIndex]->m_bIsRecallImpossible = atoi(token);
				cReadModeA = 0;
				cReadModeB = 0;
				break;

			case 31: // ApocalypseMap
				if (_bGetIsStringIsNumber(token) == FALSE) {
					PutLogList("(!!!) CRITICAL ERROR! Map Info file error ApocalypseMap -  
Wrong Data format.");
					delete pContents;
					delete pStrTok;
					return FALSE;
				}
				m_pMapList[iMapIndex]->m_bIsApocalypseMap = atoi(token);
				cReadModeA = 0;
				cReadModeB = 0;
				break;

			case 32: // CitizenLimit
				if (_bGetIsStringIsNumber(token) == FALSE) {
					PutLogList("(!!!) CRITICAL ERROR! Map Info file error CitizenLimit -  
Wrong Data format.");
					delete pContents;
					delete pStrTok;
					return FALSE;
				}
				m_pMapList[iMapIndex]->m_bIsCitizenLimit = atoi(token);
				cReadModeA = 0;
				cReadModeB = 0;
				break;
///////////////////////////

			if (memcmp(token, "ApocalypseMobGenType", 20) == 0) {
				cReadModeA = 26;
				cReadModeB = 1;
			}

			if (memcmp(token, "ApocalypseBossMob", 17) == 0) {
				cReadModeA = 27;
				cReadModeB = 1;
			}

			if (memcmp(token, "DynamicGateType", 15) == 0) {
				cReadModeA = 28;
				cReadModeB = 1;
			}

			if (memcmp(token, "DynamicGateCoord", 16) == 0) {
				cReadModeA = 29;
				cReadModeB = 1;
			}

			if (memcmp(token, "RecallImpossible", 16) == 0) {
				cReadModeA = 30;
				cReadModeB = 1;
			}

			if (memcmp(token, "ApocalypseMap", 13) == 0) {
				cReadModeA = 31;
				cReadModeB = 1;
			}

			if (memcmp(token, "CitizenLimit", 12) == 0) {
				cReadModeA = 32;
				cReadModeB = 1;
			}
			//////////////////////////
void CGame::GlobalStartApocalypseMode()
{
	char *cp, cData[120];
	DWORD *dwp, dwApocalypseGUID;

	dwApocalypseGUID = timeGetTime();

	ZeroMemory(cData, sizeof(cData));
	cp  = (char *)cData;
	*cp = GSM_BEGINAPOCALYPSE;
	cp++;

	dwp  = (DWORD *)cp;
	*dwp = dwApocalypseGUID;
	cp  += 4;

	bStockMsgToGateServer(cData, 5);

	LocalStartApocalypseMode(dwApocalypseGUID);
}

void CGame::GlobalEndApocalypseMode()
{
	char *cp, cData[120];

	ZeroMemory(cData, sizeof(cData));
	cp  = (char *)cData;
	*cp = GSM_ENDAPOCALYPSE;
	cp++;

	bStockMsgToGateServer(cData, 5);

	LocalEndApocalypseMode();
}
void CGame::LocalStartApocalypseMode(DWORD dwApocalypseGUID)
{
	register int i, j, k;

	if (m_bIsCrusadeMode == TRUE) return;
	if (m_bIsApocalypseMode == TRUE) return;

	if (dwApocalypseGUID != NULL) {
		_CreateApocalypseGUID(dwApocalypseGUID);
		m_dwApocalypseGUID = dwApocalypseGUID;
	}

	for (i = 0; i < DEF_MAXCLIENTS; i++) {
		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == 
TRUE)) {
			SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATESTARTMSG, NULL, NULL, NULL, 
NULL);
		}
	}

	for (j = 0; j < DEF_MAXMAPS; j++) {
		if (m_pMapList[j] != NULL) {
			if (m_pMapList[j]->m_cDynamicGateType == 1) {
				m_pMapList[j]->m_bIsApocalypseMobSpawn = 0;
				m_pMapList[j]->m_bIsGateAvailable = TRUE;
				m_bIsApocalypseMode = TRUE;
				for (i = 0; i < DEF_MAXCLIENTS; i++) {
					if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete 
== TRUE) &&
					(m_pClientList[i]->m_cMapIndex == j)) {
						for (k = 0; k < m_pMapList[j]->m_iTotalDynamicGate; k++) {
							SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATEOPEN, 
m_pMapList[j]->m_sDynamicGateX1,
							m_pMapList[j]->m_sDynamicGateY1, NULL, m_pMapList[j]->m_cName, NULL);
						}
					}
				}
			}
			else if (m_pMapList[j]->m_cDynamicGateType == 2) {
				m_pMapList[j]->m_bIsInferniaAGate = FALSE;
				m_pMapList[j]->m_bIsInferniaBGate = FALSE;
				m_pMapList[j]->m_bIsProcellaGate = FALSE;
				if ((m_pMapList[j]->m_iApocalypseMobGenType == 1) || 
(m_pMapList[j]->m_iApocalypseMobGenType == 2)) {
					m_pMapList[j]->m_iMaximumObjectDefault = 
m_pMapList[j]->m_iMaximumObject;
					m_pMapList[j]->m_iMaximumObject = 0;
					m_bIsApocalypseMode = TRUE;
					if (m_pMapList[j]->m_bIsApocalypseMap == TRUE) {
						for (i = 0; i < DEF_MAXCLIENTS; i++) {
							if ((m_pClientList[i] != NULL) &&
							(m_pClientList[i]->m_bIsInitComplete == TRUE) &&
							(m_pClientList[i]->m_iAdminUserLevel == 0) &&
							(m_pClientList[i]->m_cMapIndex == j)) {
								SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCFORCERECALLPLAYERS, NULL, 
NULL, NULL, NULL);
								RequestTeleportHandler(i, "1   ");
							}
						}
					}
					m_pMapList[j]->m_bIsApocalypseMobSpawn = FALSE;
					m_pMapList[j]->m_bIsBossInMap = FALSE;
				}
			}
		}
	}

	PutLogList("(!) Apocalypse Mode ON");
}void CGame::_CreateApocalypseGUID(DWORD dwApocalypseGUID)
{
	char *cp, cTxt[256], cFn[256], cTemp[1024];
	FILE *pFile;

	_mkdir("GameData");
	ZeroMemory(cFn, sizeof(cFn));

	strcat(cFn, "GameData");
	strcat(cFn, "\\");
	strcat(cFn, "\\");
	strcat(cFn, "ApocalypseGUID.txt");

	pFile = fopen(cFn, "wt");
	if (pFile == NULL) {
		wsprintf(cTxt, "(!) Cannot create ApocalypseGUID(%d) file", 
dwApocalypseGUID);
		PutLogList(cTxt);
	}
	else {
		ZeroMemory(cTemp, sizeof(cTemp));

		ZeroMemory(cTxt, sizeof(cTxt));
		wsprintf(cTxt, "ApocalypseGUID = %d\n", dwApocalypseGUID);
		strcat(cTemp, cTxt);

		cp = (char *)cTemp;
		fwrite(cp, strlen(cp), 1, pFile);

		wsprintf(cTxt, "(O) ApocalypseGUID(%d) file created", dwApocalypseGUID);
		PutLogList(cTxt);
	}
	if (pFile != NULL) fclose(pFile);
}

BOOL CGame::bReadApocalypseGUIDFile(char * cFn)
{
FILE * pFile;
HANDLE hFile;
DWORD  dwFileSize;
char * cp, * token, cReadMode;
char seps[] = "= \t\n";
class CStrTok * pStrTok;

	cReadMode = 0;

	hFile = CreateFile(cFn, GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, 
NULL);
	dwFileSize = GetFileSize(hFile, NULL);
	if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);

	pFile = fopen(cFn, "rt");
	if (pFile == NULL) {
		PutLogList("(!) Cannot open ApocalypseGUID file.");
		return FALSE;
	}
	else {
		PutLogList("(!) Reading ApocalypseGUID file...");
		cp = new char[dwFileSize+2];
		ZeroMemory(cp, dwFileSize+2);
		fread(cp, dwFileSize, 1, pFile);

		pStrTok = new class CStrTok(cp, seps);
		token = pStrTok->pGet();

		while( token != NULL )   {

			if (cReadMode != 0) {
				switch (cReadMode) {
				case 1:
					m_dwApocalypseGUID = atoi(token);
					wsprintf(G_cTxt, "ApocalypseGUID = %d", m_dwApocalypseGUID);
					PutLogList(G_cTxt);
					cReadMode = 0;
					break;
				}
			}
			else {
				if (memcmp(token, "ApocalypseGUID", 11) == 0) cReadMode = 1;
			}

			token = pStrTok->pGet();
		}

		delete pStrTok;
		delete cp;
	}
	if (pFile != NULL) fclose(pFile);

	return TRUE;
}
void CGame::LocalEndApocalypseMode()
{
	register int i, j;

	if (m_bIsApocalypseMode == FALSE) return;
	m_bIsApocalypseMode = FALSE;

	for (i = 0; i < DEF_MAXCLIENTS; i++) {
		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == 
TRUE)) {
			SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATEENDMSG, NULL, NULL, NULL, 
NULL);
		}
	}

	for (j = 0; j < DEF_MAXMAPS; j++) {
		if (m_pMapList[j] != NULL) {
			if ((m_pMapList[j]->m_bIsGateAvailable == TRUE) || 
(m_pMapList[j]->m_bIsInferniaAGate == TRUE) ||
			(m_pMapList[j]->m_bIsInferniaBGate == TRUE) || 
(m_pMapList[j]->m_bIsProcellaGate == TRUE)) {
				m_pMapList[j]->m_bIsGateAvailable = FALSE;
				m_pMapList[j]->m_bIsInferniaAGate = FALSE;
				m_pMapList[j]->m_bIsInferniaBGate = FALSE;
				m_pMapList[j]->m_bIsProcellaGate = FALSE;
				if (m_pMapList[j]->m_iApocalypseMobGenType != 0) {
					m_pMapList[j]->m_iMaximumObject = 
m_pMapList[j]->m_iMaximumObjectDefault;
				}
				for (i = 0; i < DEF_MAXCLIENTS; i++) {
					if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete 
== TRUE) &&
					(m_pClientList[i]->m_cMapIndex == j)) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATECLOSE, 
m_pMapList[j]->m_sDynamicGateX1,
						m_pMapList[j]->m_sDynamicGateY1, NULL, m_pMapList[j]->m_cName);
					}
				}
			}
		}
	}

	PutLogList("(!) Apocalypse Mode OFF");
	_CreateApocalypseGUID(m_dwApocalypseGUID);
}
void CGame::AbaddonThunder()
{
	int iResult;
	register int i, j;
	DWORD dwTime = timeGetTime();

	if (iDice(1, 15) != 13) return;

	for (i = 0; i < DEF_MAXCLIENTS; i++) {
		if (m_pClientList[i] != NULL) {
			if (memcmp(m_pClientList[i]->m_cMapName, "abaddon", 7) == 0) {
				switch (iDice(1,4)) {
					case 1:
					for (j = 0; j < 10; j++) {
						SendThunder(i, m_pClientList[i]->m_sX-iDice(1,7), 
m_pClientList[i]->m_sY+iDice(1,5), 253, m_pClientList[i]->m_sType);
						//SendThunder(i, m_pClientList[i]->m_sX-iDice(1,7), 
m_pClientList[i]->m_sY+iDice(1,5), 253, m_pClientList[i]->m_sType);
						//SendThunder(i, m_pClientList[i]->m_sX-iDice(1,10), 
m_pClientList[i]->m_sY+iDice(1,8), 253, m_pClientList[i]->m_sType);
					}
					break;

					case 2:
						SendThunder(i, m_pClientList[i]->m_sX+iDice(1,7), 
m_pClientList[i]->m_sY-iDice(1,5), 253, m_pClientList[i]->m_sType);
					break;

					case 3:
						SendThunder(i, m_pClientList[i]->m_sX+iDice(1,7), 
m_pClientList[i]->m_sY+5-iDice(1,9), 253, m_pClientList[i]->m_sType);
					break;

					case 4:
						SendThunder(i, m_pClientList[i]->m_sX+5-iDice(1,9), 
m_pClientList[i]->m_sY+7-iDice(1,4), 253, m_pClientList[i]->m_sType);
					break;
				}

				if (m_pClientList[i]->m_iAdminUserLevel > 0) continue;

				iResult = iDice(1,20) + 100;
				if (m_pClientList[i]->m_cMagicEffectStatus[DEF_MAGICTYPE_PROTECT] == 5) 
{
					iResult /= 2;
				}
				m_pClientList[i]->m_iHP -= iResult;
				if (m_pClientList[i]->m_iHP <= 0) {
					ClientKilledHandler(i, NULL, NULL, iResult);
				}
				else if (iResult > 0) {
					m_pClientList[i]->m_iLastDamage = dwTime;
					SendNotifyMsg(NULL, i, DEF_NOTIFY_HP, NULL, NULL, NULL, NULL);
					SendEventToNearClient_TypeA(i, DEF_OWNERTYPE_PLAYER, 
MSGID_EVENT_MOTION, DEF_OBJECTDAMAGE, iResult, NULL, NULL);
					if (m_pClientList[i]->m_bSkillUsingStatus[19] != TRUE) {
						m_pMapList[m_pClientList[i]->m_cMapIndex]->ClearOwner(0, i, 
DEF_OWNERTYPE_PLAYER, m_pClientList[i]->m_sX, m_pClientList[i]->m_sY);
						m_pMapList[m_pClientList[i]->m_cMapIndex]->SetOwner(i, 
DEF_OWNERTYPE_PLAYER, m_pClientList[i]->m_sX, m_pClientList[i]->m_sY);
					}
					if (m_pClientList[i]->m_cMagicEffectStatus[DEF_MAGICTYPE_HOLDOBJECT] != 
0) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_MAGICEFFECTOFF, 
DEF_MAGICTYPE_HOLDOBJECT, 2, NULL, NULL);
						bRemoveFromDelayEventList(i, DEF_OWNERTYPE_PLAYER, 
DEF_MAGICTYPE_HOLDOBJECT);
						m_pClientList[i]->m_cMagicEffectStatus[ DEF_MAGICTYPE_HOLDOBJECT ] = 
NULL;
					}
				}
			}
		}
	}
}
void CGame::SendThunder(int iClient, short sX, short sY, short sV3, short sV4)
{
	char  * cp, cData[100];
	DWORD * dwp;
	WORD * wp;
	short * sp;
	int iRet;

	ZeroMemory(cData, sizeof(cData));

	dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
	*dwp = MSGID_EVENT_COMMON;

	wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
	*wp  = DEF_COMMONTYPE_MAGIC;
	cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);

	sp  = (short *)cp;
	*sp = sX;
	cp += 2;

	sp  = (short *)cp;
	*sp = sY;
	cp += 2;

	sp  = (short *)cp;
	*sp = sX;
	cp += 2;

	sp  = (short *)cp;
	*sp = sY;
	cp += 2;

	sp  = (short *)cp;
	*sp = sV3;
	cp += 2;

	sp  = (short *)cp;
	*sp = sV4;
	cp += 2;

	iRet = m_pClientList[iClient]->m_pXSock->iSendMsg(cData, 18);
}

BOOL CGame::bApocalypseMobGenerator(int iMapIndex)
{
	char cNpcName[21], cName[11], cSA, cNpcWaypointIndex[11];
	int iProbSA, iKindSA, dX, dY, iNamingValue;
	BOOL bFirmBerserk = FALSE, bRet;
	register int i;

	if (m_pMapList[iMapIndex]->m_bIsBossInMap == TRUE) return FALSE;
	iNamingValue = m_pMapList[iMapIndex]->iGetEmptyNamingValue();

	for (i = 0; i < DEF_MAXMAPS; i++) {
		if (iNamingValue == -1) {
	}
	else {
		ZeroMemory(cName, sizeof(cName));
		switch(m_pMapList[iMapIndex]->m_iApocalypseBossMobNpcID) {
			case 10:  strcpy(cNpcName,"Slime");        iProbSA = 5;  iKindSA = 1; 
break;
			case 16:  strcpy(cNpcName,"Giant-Ant");    iProbSA = 10; iKindSA = 2; 
break;
			case 14:  strcpy(cNpcName,"Orc");          iProbSA = 15; iKindSA = 1; 
break;
			case 18:  strcpy(cNpcName,"Zombie");       iProbSA = 15; iKindSA = 3; 
break;
			case 11:  strcpy(cNpcName,"Skeleton");     iProbSA = 35; iKindSA = 8; 
break;
			case 6:   strcpy(cNpcName,"Orc-Mage");     iProbSA = 30; iKindSA = 7; 
break;
			case 17:  strcpy(cNpcName,"Scorpion");     iProbSA = 15; iKindSA = 3; 
break;
			case 12:  strcpy(cNpcName,"Stone-Golem");  iProbSA = 25; iKindSA = 5; 
break;
			case 13:  strcpy(cNpcName,"Cyclops");      iProbSA = 35; iKindSA = 8; 
break;
			case 22:  strcpy(cNpcName,"Amphis");       iProbSA = 20; iKindSA = 3; 
break;
			case 23:  strcpy(cNpcName,"Clay-Golem");   iProbSA = 20; iKindSA = 5; 
break;
			case 24:  strcpy(cNpcName,"Guard-Aresden");iProbSA = 20; iKindSA = 1; 
break;
			case 25:  strcpy(cNpcName,"Guard-Elvine"); iProbSA = 20; iKindSA = 1; 
break;
			case 26:  strcpy(cNpcName,"Guard-Neutral");iProbSA = 20; iKindSA = 1; 
break;
			case 27:  strcpy(cNpcName,"Hellbound");    iProbSA = 20; iKindSA = 1; 
break;
			case 29:  strcpy(cNpcName,"Orge");         iProbSA = 20; iKindSA = 1; 
break;
			case 30:  strcpy(cNpcName,"Liche");        iProbSA = 30; iKindSA = 8; 
break;
			case 31:  strcpy(cNpcName,"Demon");        iProbSA = 20; iKindSA = 8; 
break;
			case 32:  strcpy(cNpcName,"Unicorn");      iProbSA = 35; iKindSA = 7; 
break;
			case 33:  strcpy(cNpcName,"WereWolf");     iProbSA = 25; iKindSA = 1; 
break;
			case 34:  strcpy(cNpcName,"Dummy");        iProbSA = 5;  iKindSA = 1; 
break;
			case 35:  strcpy(cNpcName,"Attack-Dummy"); iProbSA = 5;  iKindSA = 1; 
break;
			case 48:  strcpy(cNpcName,"Stalker");      iProbSA = 20; iKindSA = 3; 
break;
			case 49:  strcpy(cNpcName,"Hellclaw");		 iProbSA = 20; iKindSA = 
8;	break;
			case 50:  strcpy(cNpcName,"Tigerworm");    iProbSA = 20; iKindSA = 8; 
break;
			case 53:  strcpy(cNpcName,"Dark-Elf");      iProbSA = 20; iKindSA = 8; 
break;
			case 54:  strcpy(cNpcName,"Beholder");      iProbSA = 20; iKindSA = 8; 
break;
			case 55:  strcpy(cNpcName,"Gagoyle");       iProbSA = 20; iKindSA = 8; 
break;
			case 57:   strcpy(cNpcName,"Giant-Frog");		iProbSA = 10; iKindSA = 2; 
break;
			case 58:   strcpy(cNpcName,"Mountain-Giant");	iProbSA = 25; iKindSA = 1; 
break;
			case 59:   strcpy(cNpcName,"Ettin");			iProbSA = 20; iKindSA = 8; break;
			case 60:   strcpy(cNpcName,"Cannibal-Plant");	iProbSA = 20; iKindSA = 5; 
break;
			case 61:   strcpy(cNpcName,"Rudolph");			iProbSA = 20; iKindSA = 1; 
break;
			case 62:   strcpy(cNpcName,"DireBoar");			iProbSA = 20; iKindSA = 1; 
break;
			case 63:   strcpy(cNpcName,"Frost");			iProbSA = 20; iKindSA = 8; break;
			case 65:   strcpy(cNpcName,"Ice-Golem");		iProbSA = 20; iKindSA = 8; 
break;
			case 66:   strcpy(cNpcName,"Wyvern");			iProbSA = 20; iKindSA = 1; break;
			case 5:    strcpy(cNpcName,"Rabbit");			iProbSA = 20; iKindSA = 1; break;
			case 67:   strcpy(cNpcName,"McGaffin");			iProbSA = 20; iKindSA = 1; 
break;
			case 68:   strcpy(cNpcName,"Perry");			iProbSA = 20; iKindSA = 1; break;
			case 69:   strcpy(cNpcName,"Devlin");			iProbSA = 20; iKindSA = 1; break;
			case 70:   strcpy(cNpcName,"Barlog");     iProbSA = 20; iKindSA = 1; 
break;
			case 71:   strcpy(cNpcName,"Centaurus");  iProbSA = 20; iKindSA = 1; 
break;
			case 72:   strcpy(cNpcName,"Claw-Turtle"); iProbSA = 20; iKindSA = 1; 
break;
			case 73:   strcpy(cNpcName,"Fire-Wyvern"); iProbSA = 20; iKindSA = 1; 
break;
			case 74:   strcpy(cNpcName,"Giant-Crayfish"); iProbSA = 20; iKindSA = 1; 
break;
			case 75:   strcpy(cNpcName,"Giant-Lizard"); iProbSA = 20; iKindSA = 1; 
break;
			case 76:   strcpy(cNpcName,"Giant-Plant"); iProbSA = 20; iKindSA = 1; 
break;
			case 77:   strcpy(cNpcName,"MasterMage-Orc"); iProbSA = 20; iKindSA = 1; 
break;
			case 78:   strcpy(cNpcName,"Minotaurs"); iProbSA = 20; iKindSA = 1; 
break;
			case 79:   strcpy(cNpcName,"Nizie"); iProbSA = 20; iKindSA = 1; break;
			case 80:   strcpy(cNpcName,"Tentocle"); iProbSA = 20; iKindSA = 1; break;
			case 81:   strcpy(cNpcName,"Abaddon"); iProbSA = 20; iKindSA = 1; break;
			default:   strcpy(cNpcName, "Orc"); iProbSA = 15; iKindSA = 1; break;
		}

		cSA = _cGetSpecialAbility(iKindSA);
		if (iDice(1,5) == 1) {
			bFirmBerserk = TRUE;
		}
		ZeroMemory(cName, sizeof(cName));
		wsprintf(cName, "XX%d", iNamingValue);
		cName[0] = '_';
		cName[1] = i + 65;
		bRet = bCreateNewNpc(cNpcName, cName, m_pMapList[iMapIndex]->m_cName, 53, 
cSA, DEF_MOVETYPE_RANDOMAREA, &dX, &dY, cNpcWaypointIndex, 
&m_pMapList[iMapIndex]->m_rcApocalypseBossMobRect, i, -1, FALSE, FALSE, 
bFirmBerserk, FALSE, FALSE);

		if (bRet == FALSE) {
			m_pMapList[iMapIndex]->SetNamingValueEmpty(iNamingValue);
			return FALSE;
		}

		else{
			m_pNpcList[bRet]->m_bIsBossMob = TRUE;
			m_pMapList[iMapIndex]->m_bIsBossInMap = TRUE;
			return TRUE;
			}
		}
	}
	return FALSE;
}
And it's all. If it's wrong tell me and I will help you :)
NOTE: I coded it in my ex-gameserver 2.20 original. If you can't find 
something tell me.


