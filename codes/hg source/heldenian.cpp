 If You Need Better InStrution Just Ask I Was Half Asleep When i grabed it Any ? just ask :P 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	m_bHeldenianInitiated = FALSE;
	m_cHeldenianModeType = FALSE;
	m_bIsHeldenianMode = FALSE;
	m_bHeldenianRunning	= FALSE;
	m_cHeldenianWinner = NULL;
	m_sLastHeldenianWinner = 0;
	m_cHeldenianModeType = 0;

	m_iHeldenianAresdenLeftTower = 0;
	m_iHeldenianElvineLeftTower = 0;
	m_iHeldenianAresdenDead = 0;
	m_iHeldenianElvineDead = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case MSGID_REQUEST_HELDENIAN_WINNER:
		if (bCheckSubLogSocketIndex() == FALSE) return FALSE;
		dwp  = (DWORD *)(G_cData50000 + DEF_INDEX4_MSGID);
		*dwp = MSGID_REQUEST_HELDENIAN_WINNER;
		wp   = (WORD *)(G_cData50000 + DEF_INDEX2_MSGTYPE);
		*wp  = DEF_MSGTYPE_CONFIRM;
		cp = (char *)(G_cData50000 + DEF_INDEX2_MSGTYPE + 2);

		if (m_cHeldenianVictoryType == 1)
			memcpy(cp, "aresden", 7);
		else if (m_cHeldenianVictoryType == 2)
			memcpy(cp, "elvine", 6);
		else 
			memcpy(cp, "draw", 4);

		cp += 7;
		
		ip = (int *)cp;
		ip = (int *)m_cHeldenianModeType;
		cp += 4;

		iRet = m_pSubLogSock[m_iCurSubLogSockIndex]->iSendMsg(G_cData50000, 21);
		iSendSize = 21;
		break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	IN checkclientresponsetime
find

								SendNotifyMsg(NULL, i, DEF_NOTIFY_TOBERECALLED, NULL, NULL, NULL, NULL);
								RequestTeleportHandler(i, "1 ");
					}
				}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
add
				if ((m_bIsHeldenianMode == TRUE) && (m_pMapList[m_pClientList[i]->m_cMapIndex] != 0)) {
					if (bCheckHeldenianMap(i, m_iBTFieldMapIndex, DEF_OWNERTYPE_PLAYER) == 1) {
						SetHeroFlag(i, DEF_OWNERTYPE_PLAYER, TRUE);
					}
					else {
						SetHeroFlag(i, DEF_OWNERTYPE_PLAYER, FALSE);
					}
				}	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (memcmp(cp, "/beginheldenian ", 16) == 0) {
			if (m_pClientList[iClientH]->m_iAdminUserLevel > 2) {
				ManualStartHeldenianMode(iClientH, cp, dwMsgSize - 21);
			}
			return;
		}
			
if (memcmp(cp, "/endheldenian", 14) == 0) {
			if (m_pClientList[iClientH]->m_iAdminUserLevel > 2) {
				ManualEndHeldenianMode(iClientH, cp, dwMsgSize - 21);
			}
			return;
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
at the end of npckilledhaddler
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (   (m_bIsHeldenianMode == TRUE) && (m_cHeldenianModeType == 1) 
		&& (m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_bIsHeldenianMap == TRUE) ) 
	{	if ((m_pNpcList[iNpcH]->m_sType == 87) || (m_pNpcList[iNpcH]->m_sType == 89)) 
		{	
			
		if (m_pNpcList[iNpcH]->m_cSide == 1) 
			{	m_iHeldenianAresdenLeftTower--;
				wsprintf(G_cTxt, "Aresden Tower Broken, Left TOWER %d", m_iHeldenianAresdenLeftTower);
				PutLogList(G_cTxt);
				bUpdateHeldenianStatus(-1);
			}
		
		else if (m_pNpcList[iNpcH]->m_cSide == 2) 
			{	m_iHeldenianElvineLeftTower--;
				wsprintf(G_cTxt, "Elvine Tower Broken, Left TOWER %d", m_iHeldenianElvineLeftTower);
				PutLogList(G_cTxt);
				bUpdateHeldenianStatus(-1);
		}
		if ((m_iHeldenianElvineLeftTower == 0) || (m_iHeldenianAresdenLeftTower == 0)) {
			GlobalEndHeldenianMode();

	}	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
case MSGID_REQUEST_HELDENIANNPC:
				RequestHeldenianScroll(iClientH, pData, dwMsgSize);
				break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::Effect_Damage_Spot

under
	if (cAttackerType == DEF_OWNERTYPE_NPC)
		if (m_pNpcList[sAttackerH] == NULL) return;

add
	if ((cAttackerType == DEF_OWNERTYPE_PLAYER) && (m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex] != 0) && 
		(m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsHeldenianMap == 1) && (m_bHeldenianInitiated == TRUE)) return;
under			
if (m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsFightZone == TRUE) 
			iDamage += iDamage/3;
add
		if (bCheckHeldenianMap(sAttackerH, m_iBTFieldMapIndex, DEF_OWNERTYPE_PLAYER) == 1) {
			iDamage += iDamage/3;
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::Effect_Damage_Spot_Type2
 

replace old one at top 

	if ((cAttackerType == DEF_OWNERTYPE_PLAYER) && (m_pClientList[sAttackerH] == NULL)) return;
	if ((cAttackerType == DEF_OWNERTYPE_NPC) && (m_pNpcList[sAttackerH] == NULL)) return;
	if ((cAttackerType == DEF_OWNERTYPE_PLAYER) && (m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex] != 0) && 
	(m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsHeldenianMap == 1) && (m_bHeldenianInitiated == TRUE)) return;

under
		if (m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsFightZone == TRUE) 
			iDamage += iDamage/3;
add
		if (bCheckHeldenianMap(sAttackerH, m_iBTFieldMapIndex, DEF_OWNERTYPE_PLAYER) == 1) {
			iDamage += iDamage/3;
		}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::Effect_Damage_Spot_DamageMove

under

		wWeaponType = ((m_pClientList[sAttackerH]->m_sAppr2 & 0x0FF0) >> 4);
		if (wWeaponType == 34) {
			iDamage += iDamage/3;
		}
add
		if (bCheckHeldenianMap(sAttackerH, m_iBTFieldMapIndex, DEF_OWNERTYPE_PLAYER) == 1) {
			iDamage += iDamage/3;
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
case DEF_NOTIFY_HELDENIANCOUNT:
		wp  = (WORD *)cp;
		*wp = (WORD)sV1;
		cp += 2;

		wp  = (WORD *)cp;
		*wp = (WORD)sV2;
		cp += 2;

		wp  = (WORD *)cp;
		*wp = (WORD)sV3;
		cp += 2;

		wp  = (WORD *)cp;
		*wp = (WORD)sV4;
		cp += 2;

		cp += 14;

		iRet = m_pClientList[iToH]->m_pXSock->iSendMsg(cData, 14);

		break;

		case DEF_NOTIFY_HELDENIANSTART:
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::ClientKilledHandler

	else sAttackerWeapon = 1;
	SendEventToNearClient_TypeA(iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTDYING, sDamage, sAttackerWeapon, NULL);
	m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->ClearOwner(12, iClientH, DEF_OWNERTYPE_PLAYER, m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY);
	m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->SetDeadOwner(iClientH, DEF_OWNERTYPE_PLAYER, m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY);
	if (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cType == DEF_MAPTYPE_NOPENALTY_NOREWARD) return;
	if ((m_pMapList[m_pClientList[iClientH]->m_cMapIndex] != NULL) &&
		(m_bIsHeldenianMode == TRUE) &&
		(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_bIsHeldenianMap == TRUE)) {
		if (m_pClientList[iClientH]->m_cSide == 1) {
			m_iHeldenianAresdenDead++;
		}
		else if (m_pClientList[iClientH]->m_cSide == 2) {
			m_iHeldenianElvineDead++;
		}
		bUpdateHeldenianStatus(-1);
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::RequestInitDataHandler
		add

		else if (m_bIsHeldenianMode == TRUE) {
				sSummonPoints = m_pClientList[iClientH]->m_iCharisma*300;
				if (sSummonPoints > DEF_MAXSUMMONPOINTS) sSummonPoints = DEF_MAXSUMMONPOINTS;
				if (m_pClientList[iClientH]->m_dwHeldenianGUID == NULL) {
					m_pClientList[iClientH]->m_dwHeldenianGUID = m_dwHeldenianGUID;
					m_pClientList[iClientH]->m_iConstructionPoint = sSummonPoints;
				}
				else if (m_pClientList[iClientH]->m_dwHeldenianGUID != m_dwHeldenianGUID) {
					m_pClientList[iClientH]->m_iConstructionPoint = sSummonPoints;
					m_pClientList[iClientH]->m_iWarContribution = 0;
					m_pClientList[iClientH]->m_dwHeldenianGUID = m_dwHeldenianGUID;
				}
				m_pClientList[iClientH]->m_cVar = 2;
				if (m_bIsHeldenianMode == TRUE) {
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CRUSADE, NULL, NULL, NULL, NULL);
					if (m_bHeldenianInitiated == FALSE) {
						SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANSTART, NULL, NULL, NULL, NULL);
					}
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CONSTRUCTIONPOINT, m_pClientList[iClientH]->m_iConstructionPoint, m_pClientList[iClientH]->m_iWarContribution, NULL, NULL);
					bUpdateHeldenianStatus(-1);
				}
			}

if (m_bIsHeldenianMode == TRUE) SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANTELEPORT, NULL, NULL, NULL, NULL, NULL);		
			if (m_bHeldenianInitiated == TRUE) SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANSTART, NULL, NULL, NULL, NULL, NULL);		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case GSM_STARTHELDENIAN:
			cp++;
			wp  = (WORD *)cp;
			wV1 = *wp;
			cp += 2;
			wp  = (WORD *)cp;
			wV2 = *wp;
			cp += 2;
			dwp = (DWORD *)cp;
			cp += 4;
			LocalStartHeldenianMode(wV1, wV2, *dwp);
			break;

		case GSM_ENDHELDENIAN:
			cp++;
		LocalEndHeldenianMode();
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::OnTimer(char cType)

if ((m_bHeldenianRunning == TRUE) && (m_bIsHeldenianMode == TRUE)) {
		SetHeldenianMode();
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::OnStartGameSignal

bReadHeldenianGUIDFile("GameData\\HeldenianGUID.txt");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::requestteleporthandler

else if (m_bIsHeldenianMode == TRUE) {
				sSummonPoints = m_pClientList[iClientH]->m_iCharisma*300;
				if (sSummonPoints > DEF_MAXSUMMONPOINTS) sSummonPoints = DEF_MAXSUMMONPOINTS;
				if (m_pClientList[iClientH]->m_dwHeldenianGUID == NULL) {
					m_pClientList[iClientH]->m_dwHeldenianGUID = m_dwHeldenianGUID;
					m_pClientList[iClientH]->m_iConstructionPoint = sSummonPoints;
				}
				else if (m_pClientList[iClientH]->m_dwHeldenianGUID != m_dwHeldenianGUID) {
					m_pClientList[iClientH]->m_iConstructionPoint = sSummonPoints;
					m_pClientList[iClientH]->m_iWarContribution = 0;
					m_pClientList[iClientH]->m_dwHeldenianGUID = m_dwHeldenianGUID;
				}
				m_pClientList[iClientH]->m_cVar = 2;
				if (m_bIsHeldenianMode == TRUE) {
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANTELEPORT, NULL, NULL, NULL, NULL);
				}
				if (m_bHeldenianInitiated == TRUE) {
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANSTART, NULL, NULL, NULL, NULL);
				}
				SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CONSTRUCTIONPOINT, m_pClientList[iClientH]->m_iConstructionPoint, m_pClientList[iClientH]->m_iWarContribution, NULL, NULL);
				bUpdateHeldenianStatus(-1);
			}



find

		if (memcmp(m_pClientList[iClientH]->m_cMapName, "fight", 5) == 0) {
			wsprintf(G_cTxt, "Char(%s)-Enter(%s) Observer(%d)", m_pClientList[iClientH]->m_cCharName, m_pClientList[iClientH]->m_cMapName, m_pClientList[iClientH]->m_bIsObserverMode);
			PutLogEventFileList(G_cTxt);
		}

		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CONSTRUCTIONPOINT, m_pClientList[iClientH]->m_iConstructionPoint, m_pClientList[iClientH]->m_iWarContribution, 1, NULL);

		
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
add
		if (m_bIsHeldenianMode == TRUE) {
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANTELEPORT, NULL, NULL, NULL, NULL);
			if (m_bHeldenianInitiated == TRUE) {
				SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANSTART, NULL, NULL, NULL, NULL);
			}
			else {
				bUpdateHeldenianStatus(-1);
			}
		}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
case 33: // HeldenianMap
				if (bGetIsStringIsNumber(token) == FALSE) {
					PutLogList("(!!!) CRITICAL ERROR! Map Info file error CitizenLimit -  Wrong Data format.");
					delete pContents;
					delete pStrTok;
					return FALSE;
				}
				m_pMapList[iMapIndex]->m_bIsHeldenianMap = atoi(token);
				cReadModeA = 0;
				cReadModeB = 0;
				break;

			case 34: // HeldenianTower
				switch (cReadModeB) {
				case 1: // NpcID
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error Hedenian tower type id - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_stHeldenianTower[iIndex].sTypeID = atoi(token);
					cReadModeB = 2;
					break;
				case 2: // side 
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error Hedenian Tower Side - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_stHeldenianTower[iIndex].cSide = atoi(token);
					cReadModeB = 3;
					break;
				case 3: // sX
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error Hedenian Tower X pos - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_stHeldenianTower[iIndex].dX = atoi(token);
					cReadModeB = 4;
					break;
				case 4: // sY
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error Hedenian Tower Y pos - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_stHeldenianTower[iIndex].dY = atoi(token);
					iIndex++;
					cReadModeA = 0;
					cReadModeB = 0;
					break;
				}
				break;

			case 35: // HeldenianModeMap
				if (bGetIsStringIsNumber(token) == FALSE) {
					PutLogList("(!!!) CRITICAL ERROR! Map Info file error Hedenian Map Mode - Wrong Data format.");
					delete pContents;
					delete pStrTok;
					return FALSE;
				}
				m_pMapList[iMapIndex]->m_cHeldenianModeMap = atoi(token);
				cReadModeA = 0;
				cReadModeB = 0;
				break;

			case 36: // HeldenianWinningZone
				switch (cReadModeB) {
			case 1: 
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error HeldenianWinningZone - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sHeldenianWinningZoneX = atoi(token);
				cReadModeB = 2;
					break;
			case 2: 
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error HeldenianWinningZone - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_sHeldenianWinningZoneY = atoi(token);
						iIndex++;
					cReadModeA = 0;
					cReadModeB = 0;
					break;
				}
				break;

			case 37: // HeldenianGateDoor // 37
				switch (cReadModeB) {
				case 1: 
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error Heldenian Door Direction - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_stHeldenianGateDoor[iIndex].cDir = atoi(token);
					cReadModeB = 2;
					break;
				case 2:
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error Heldenian Door X pos - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_stHeldenianGateDoor[iIndex].dX = atoi(token);
					cReadModeB = 3;
					break;
				case 3:
					if (bGetIsStringIsNumber(token) == FALSE) {
						PutLogList("(!!!) CRITICAL ERROR! Map Info file error Heldenian Door Y pos - Wrong Data format.");
						delete pContents;
						delete pStrTok;
						return FALSE;
					}
					m_pMapList[iMapIndex]->m_stHeldenianGateDoor[iIndex].dY = atoi(token);
					iIndex++;
					cReadModeA = 0;
					cReadModeB = 0;
					break;
				}
				break;
if (memcmp(token, "HeldenianMap", 12) == 0) {
				cReadModeA = 33;
				cReadModeB = 1;
			}

			if (memcmp(token, "HeldenianTower", 14) == 0) {
				cReadModeA = 34;
				cReadModeB = 1;
			}

			if (memcmp(token, "HeldenianModeMap", 16) == 0) {
				cReadModeA = 35;
				cReadModeB = 1;
			}

			if (memcmp(token, "HeldenianWinningZone", 20) == 0) {
				cReadModeA = 36;
				cReadModeB = 1;
			}

			if (memcmp(token, "HeldenianGateDoor", 17) == 0) {
				cReadModeA = 37;
				cReadModeB = 1;
			}

			if (memcmp(token, "[END-MAP-INFO]", 14) == 0) {
				cReadModeA = 0;
				cReadModeB = 0;
				goto RMI_SKIPDECODING;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
icreatenewnpc

Replace Old One
switch (m_pNpcList[i]->m_cActionLimit) {
 case 2: // fixed mechants
 case 3: // dummy
 case 5: // struct sade, crops
  m_pNpcList[i]->m_cBehavior = DEF_BEHAVIOR_STOP;   
  switch (m_pNpcList[i]->m_sType) {
  case 15: // ShopKeeper-W
  case 19: // Gandlf
  case 20: // Howard
  case 24: // Tom
  case 25: // William
  case 26: // Kennedy
   m_pNpcList[i]->m_cDir      = 3 + iDice(1,3);
   break;
  default:
   m_pNpcList[i]->m_cDir      = iDice(1,8);
   break;
  }
  break;
 case 8: // Heldenian gate
  m_pNpcList[i]->m_cDir      = 3;
  m_pNpcList[i]->m_cBehavior = DEF_BEHAVIOR_STOP; 
  if (m_pNpcList[i]->m_cArea > 0)
  { for(short sx1 = (sX - 1); sx1 <= sX + 1; sx1++)
   for(short sy1 = (sY - 1); sy1 <= sY + 1; sy1++)
   { m_pMapList[iMapIndex]->SetTempMoveAllowedFlag(sx1, sy1, FALSE);  
  } }
  break;

 default: 
  m_pNpcList[i]->m_cBehavior = DEF_BEHAVIOR_MOVE;
  m_pNpcList[i]->m_cDir      = 5;
  break;
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CGame::iCalculateAttackEffect

Replace Old One
	if (m_pClientList[sAttackerH] == NULL) return 0;
		if ((m_bAdminSecurity == TRUE) && (m_pClientList[sAttackerH]->m_iAdminUserLevel > 0) && (m_pClientList[sAttackerH]->m_bAdminAttackEnabled == FALSE)) return 0;
		if ((m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsAttackEnabled == FALSE) && (m_pClientList[sAttackerH]->m_iAdminUserLevel == 0)) return 0;
		if ((m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex] == NULL) && (m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsHeldenianMap == TRUE) && (m_bIsHeldenianMode == TRUE)) return 0;
		if ((m_bIsCrusadeMode == FALSE) && (m_pClientList[sAttackerH]->m_bIsPlayerCivil == TRUE) && (cTargetType == DEF_OWNERTYPE_PLAYER)) return 0;

find
			if (m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsFightZone == TRUE) {
				iAP_SM += iAP_SM/3;
				iAP_L  += iAP_L/3;
			}
add
			if (bCheckHeldenianMap(sAttackerH, m_iBTFieldMapIndex, DEF_OWNERTYPE_PLAYER) == 1) {
				iAP_SM += iAP_SM/3;
				iAP_L  += iAP_L/3;
			}
			
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::NotifyStartHeldenianFightMode()
{
 register int i, x;
	
	if ((m_bIsHeldenianMode != TRUE) && (m_bHeldenianInitiated != TRUE)) return;
	PutLogList("Heldenian Fight Start");
	m_bHeldenianInitiated = FALSE;
	for (i = 0; i < DEF_MAXMAPS; i++) {
		if (m_pMapList[i] != NULL) {
			if (m_pMapList[i]->m_bIsHeldenianMap == TRUE) {
				for (x = 0; x < DEF_MAXCLIENTS; x++) {
					if (m_pClientList[x] != NULL) {
						if (m_pClientList[x]->m_bIsInitComplete == TRUE) {
							if (m_pClientList[x]->m_cMapIndex == i) {
								SendNotifyMsg(NULL, x, DEF_NOTIFY_HELDENIANSTART, NULL, NULL, NULL, NULL);
							}
						}
					}
				}
			}
		}
	}
}

void CGame::RequestNpcSpeakTeleport(int iClientH, char * pData, DWORD dwMsgSize)
{

 char cMapName[11];
 int  tX, tY, cLoc;




			if ((m_bIsHeldenianMode == 1) && 
			(m_pClientList[iClientH]->m_bIsPlayerCivil != TRUE) && 
			((m_pClientList[iClientH]->m_cSide == 2 || (m_pClientList[iClientH]->m_cSide == 1)))) {
			if (m_cHeldenianModeType == 1) {
				ZeroMemory(cMapName, sizeof(cMapName));
				memcpy(cMapName, "BtField", 10);
				if (m_pClientList[iClientH]->m_cSide == 1) {
					tX = 68;
					tY = 225;
					cLoc = 1;
				}
				else if (m_pClientList[iClientH]->m_cSide == 2) {
					tX = 202;
					tY = 70;
					cLoc = 2;
				}
			}
			else if (m_cHeldenianModeType == 2) {
				ZeroMemory(cMapName, sizeof(cMapName));
				memcpy(cMapName, "HRampart", 10);
				if (m_pClientList[iClientH]->m_cSide == m_sLastHeldenianWinner) {
					tX = 81;
					tY = 42;
					cLoc = 3;
				}
				else {
					tX = 156;
					tY = 153;
					cLoc = 4;
				}
			RequestTeleportHandler(iClientH, "2   ", cMapName, tX, tY);

				}
			}
}



void CGame::RequestHeldenianScroll(int iClientH, char * pData, DWORD dwMsgSize)
{
 char cTmpName[21], cData[127], *cp;
 WORD *wp;
 DWORD *dwp;
 int iRet, iRequiredConstruction, iEraseReq;
 short *sp, *cV1;
 class CItem * pItem;

	if (m_bIsHeldenianMode == FALSE) return;
	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;
	if (m_pClientList[iClientH]->m_iGuildGUID == -1) return;
	ZeroMemory(cData, sizeof(cData));
	ZeroMemory(cTmpName, sizeof(cTmpName));
	iRequiredConstruction = 0;
	iEraseReq = 0;

	cp = (char *)(pData + DEF_INDEX2_MSGTYPE + 2);
	strncpy(cTmpName, cp, 20);
	cp += 20;

	if (memcmp(cTmpName, "Gail", 4) != 0) return;
	cV1 = (short *)cp;
	cp += 2;
	switch(*cV1) {
	case 875: iRequiredConstruction = 2000; break;
	case 876: iRequiredConstruction = 3000;	break;
	case 877: iRequiredConstruction = 1500;	break;
	case 878: iRequiredConstruction = 3000;	break;
	case 879: iRequiredConstruction = 4000;	break;
	case 880: iRequiredConstruction = 3000;	break;
	default:  iRequiredConstruction = 0;	break;	
	}
	if (iRequiredConstruction == 0) return;
	if (m_pClientList[iClientH]->m_iConstructionPoint < iRequiredConstruction) return;
	pItem = new class CItem;
	if (bInitItemAttr(pItem, *cV1) == FALSE) {
		delete pItem;
		return;
	}
	else {
		pItem->m_sTouchEffectType   = DEF_ITET_ID;
		pItem->m_sTouchEffectValue1 = iDice(1,100000);
		pItem->m_sTouchEffectValue2 = iDice(1,100000);
		pItem->m_sTouchEffectValue3 = (short)timeGetTime();
		pItem->m_sItemSpecEffectValue2 = 9;
		if (bAddClientItemList(iClientH, pItem, &iEraseReq) == TRUE) {
			if (m_pClientList[iClientH]->m_iCurWeightLoad < 0) m_pClientList[iClientH]->m_iCurWeightLoad = 0;
	
			dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
			*dwp = MSGID_REQUEST_HELDENIANSCROLL;
			wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
			*wp  = DEF_NOTIFY_ITEMPURCHASED;

			cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);
			*cp = 1;
			cp++;
				
			memcpy(cp, pItem->m_cName, 20);
			cp += 20;
				
			dwp  = (DWORD *)cp;
			*dwp = pItem->m_dwCount;
			cp += 4;
				
			*cp = pItem->m_cItemType;
			cp++;
				
			*cp = pItem->m_cEquipPos;
			cp++;
				
			*cp = (char)0;
			cp++;
				
			sp  = (short *)cp;
			*sp = pItem->m_sLevelLimit;
			cp += 2;
				
			*cp = pItem->m_cGenderLimit;
			cp++;
				
			wp = (WORD *)cp;
			*wp = pItem->m_wCurLifeSpan;
			cp += 2;
				
			wp = (WORD *)cp;
			*wp = pItem->m_wWeight;
			cp += 2;
				
			sp  = (short *)cp;
			*sp = pItem->m_sSprite;
			cp += 2;
				
			sp  = (short *)cp;
			*sp = pItem->m_sSpriteFrame;
			cp += 2;

			*cp = pItem->m_cItemColor;
			cp++;
				
			wp  = (WORD *)cp;
			*wp = iRequiredConstruction;
			cp += 2;
				
			iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 49);
			switch (iRet) {
			case DEF_XSOCKEVENT_QUENEFULL:
			case DEF_XSOCKEVENT_SOCKETERROR:
			case DEF_XSOCKEVENT_CRITICALERROR:
			case DEF_XSOCKEVENT_SOCKETCLOSED:
				DeleteClient(iClientH, TRUE, TRUE, TRUE, FALSE);
				return;
			}
			iCalcTotalWeight(iClientH);
			m_pClientList[iClientH]->m_iConstructionPoint -= iRequiredConstruction;
			SendNotifyMsg(NULL, DEF_NOTIFY_CONSTRUCTIONPOINT, m_pClientList[iClientH]->m_iConstructionPoint, m_pClientList[iClientH]->m_iWarContribution, TRUE, 0,0,0);
		}
		else {
			iCalcTotalWeight(iClientH);
			
			dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
			*dwp = MSGID_REQUEST_HELDENIANSCROLL;
			wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
			*wp  = DEF_NOTIFY_CANNOTCARRYMOREITEM;
			
			iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 6);
			switch (iRet) {
			case DEF_XSOCKEVENT_QUENEFULL:
			case DEF_XSOCKEVENT_SOCKETERROR:
			case DEF_XSOCKEVENT_CRITICALERROR:
			case DEF_XSOCKEVENT_SOCKETCLOSED:
				DeleteClient(iClientH, TRUE, TRUE);
				return;
			}
		}
	}
}




void CGame::GlobalEndHeldenianMode()
{char * cp, cData[32];
	DWORD * dwp;
	if (m_cHeldenianWinner == -1) return;
	if (m_bIsHeldenianMode == FALSE) return;
	ZeroMemory(cData, sizeof(cData));
	cp = (char *)cData;
	*cp = GSM_ENDHELDENIAN;
	cp++;
	dwp = (DWORD *)cp;
	*dwp = m_dwHeldenianGUID;
	cp += 4;
	dwp = (DWORD *)cp;
	*dwp = (int)m_cHeldenianWinner;
	cp += 4;
	bStockMsgToGateServer(cData, 9);
	LocalEndHeldenianMode();
}
void CGame::LocalEndHeldenianMode()
{
 register int i, x;
	
	if (m_bIsHeldenianMode == FALSE) return;
	m_bIsHeldenianMode = FALSE;
	m_bHeldenianInitiated = TRUE;
	m_dwHeldenianFinishTime = time(NULL);

	if (m_cHeldenianModeType == 1) {
			if (m_iHeldenianAresdenLeftTower > m_iHeldenianElvineLeftTower) {
				m_cHeldenianVictoryType = 1;
			}
			else if (m_iHeldenianAresdenLeftTower < m_iHeldenianElvineLeftTower) {
				m_cHeldenianVictoryType = 2;
			}
			else if (m_iHeldenianAresdenDead < m_iHeldenianElvineDead) {
				m_cHeldenianVictoryType = 1;
			}
			else if (m_iHeldenianAresdenDead > m_iHeldenianElvineDead) {
				m_cHeldenianVictoryType = 2;
			}
			else {
				m_sLastHeldenianWinner = m_cHeldenianVictoryType;
			}
		}
		else if (m_cHeldenianModeType == 2) {
			m_sLastHeldenianWinner = m_cHeldenianVictoryType;
		}
		m_sLastHeldenianWinner = m_cHeldenianVictoryType;
		if (bNotifyHeldenianWinner() == FALSE) {
		wsprintf(G_cTxt, "(!) HELDENIAN End. Winner %d", m_sLastHeldenianWinner);
			PutLogList(G_cTxt);		
		}
		for (i = 0; i < DEF_MAXMAPS; i++) {
			if ((i < 0) || (i > 100) || (m_pMapList[i] != NULL)) {
				for (x = 0; x < DEF_MAXCLIENTS; x++) {
					if ((m_pClientList[x] != NULL) && (m_pClientList[x]->m_bIsInitComplete == TRUE)) {
						SendNotifyMsg(NULL, x, DEF_NOTIFY_HELDENIANEND, NULL, NULL, NULL, NULL);
					}
				}
				RemoveOccupyFlags(i);
				}
			}
	
	CreateHeldenianGUID(m_dwHeldenianGUID, m_cHeldenianVictoryType);
}

void CGame::RequestHeldenianTeleport(int iClientH, char * pData, DWORD dwMsgSize)
{
 char cTmpName[21], * cp, cData[512], cMapName[11];
 WORD wResult;
 int iRet, iWhyReturn, iProcessed, tX, tY, cLoc, * ip;
 DWORD *dwp;

	iProcessed = 1;
	if (m_pClientList[iClientH] == NULL) return;

	cp = (char *)(pData + DEF_INDEX2_MSGTYPE + 2);
	ZeroMemory(cTmpName, sizeof(cTmpName));
	strcpy(cTmpName, cp);
	if (strcmp(cTmpName, "Gail") == 0) {

		ZeroMemory(cData, sizeof(cData));

		dwp  = (DWORD *)(cData);
		*dwp = MSGID_REQUEST_GAILTELEPORT;
		wResult = DEF_MSGTYPE_CONFIRM;
		cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);

		if ((m_bIsHeldenianMode == 1) && 
			(m_pClientList[iClientH]->m_bIsPlayerCivil != TRUE) && 
			((m_pClientList[iClientH]->m_cSide == 2 || (m_pClientList[iClientH]->m_cSide == 1)))) {
			if (m_cHeldenianModeType == 1) {
				ZeroMemory(cMapName, sizeof(cMapName));
				memcpy(cMapName, "BtField", 10);
				if (m_pClientList[iClientH]->m_cSide == 1) {
					tX = 68;
					tY = 225;
					cLoc = 1;
				}
				else if (m_pClientList[iClientH]->m_cSide == 2) {
					tX = 202;
					tY = 70;
					cLoc = 2;
				}
			}
			else if (m_cHeldenianModeType == 2) {
				ZeroMemory(cMapName, sizeof(cMapName));
				memcpy(cMapName, "HRampart", 10);
				if (m_pClientList[iClientH]->m_cSide == m_sLastHeldenianWinner) {
					tX = 81;
					tY = 42;
					cLoc = 3;
				}
				else {
					tX = 156;
					tY = 153;
					cLoc = 4;
				}
			}
			wResult = DEF_MSGTYPE_CONFIRM;
			iProcessed = 1;
			iWhyReturn = 0;
			goto SENDPLAYER;
		}
		wResult = DEF_MSGTYPE_REJECT;
		iProcessed = 0;
		iWhyReturn = 0;
	}
	
SENDPLAYER:;
	ip = (int *)cp;
	*ip = iProcessed; 
	cp += 4;

	ip = (int *)cp;
	*ip = cLoc; 
	cp += 4;

	memcpy((char *)cp, cMapName, 10);
	cp += 10;

	ip = (int *)cp;
	*ip = tX; 
	cp += 4;

	ip = (int *)cp;
	*ip = tY; 
	cp += 4;

	ip = (int *)cp;
	*ip = iWhyReturn; 
	cp += 4;

	iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 36);
	switch (iRet) {
		case DEF_XSOCKEVENT_QUENEFULL:
		case DEF_XSOCKEVENT_SOCKETERROR:
		case DEF_XSOCKEVENT_CRITICALERROR:
		case DEF_XSOCKEVENT_SOCKETCLOSED:
			DeleteClient(iClientH, TRUE, TRUE);
			break;
	}
}

void CGame::HeldenianWarStarter()
{SYSTEMTIME SysTime;
 int i;	
	GetLocalTime(&SysTime);
	if (var_89C == TRUE) return;
	if (var_8A0 == FALSE) return;
	for (i = 0; i < DEF_MAXSCHEDULE; i++) 
		if (m_bIsApocalypseMode == TRUE) return;
		if (m_bIsCrusadeMode == TRUE) return;
		if ((m_stHeldenianSchedule[i].iDay != SysTime.wDayOfWeek) &&
			(m_stHeldenianSchedule[i].StartiHour != SysTime.wHour) &&
			(m_stHeldenianSchedule[i].StartiMinute != SysTime.wMinute)) {
			wsprintf(G_cTxt,"Heldenian Start : time(%d %d:%d), index(%d)",SysTime.wDayOfWeek, SysTime.wHour, SysTime.wMinute, i);
			PutLogList(G_cTxt);
			PutLogFileList(G_cTxt);
			PutLogEventFileList(G_cTxt);
			var_8A0 = TRUE;
			GlobalStartHeldenianMode();
		}
}
void CGame::HeldenianWarEnder()
{}
void CGame::GlobalStartHeldenianMode()
{
 char cData[120], * cp;
 DWORD dwTime, * dwp;
 WORD * wp;

	dwTime = timeGetTime();
	ZeroMemory(cData,sizeof(cData));

	cp = (char *)cData;
	*cp = GSM_STARTHELDENIAN; // 21
	cp++;
	
	wp  = (WORD *)cp;
	*wp = m_cHeldenianModeType;
	cp += 2;

	wp  = (WORD *)cp;
	*wp = m_sLastHeldenianWinner;
	cp += 2;

	dwp = (DWORD *)cp;
	*dwp = dwTime;
	cp += 4;

	bStockMsgToGateServer(cData, 9);
	LocalStartHeldenianMode(m_cHeldenianModeType, m_sLastHeldenianWinner, dwTime);

}

void CGame::LocalStartHeldenianMode(short sV1, short sV2, DWORD dwHeldenianGUID)
{
	int i, x, z, iNamingValue;
 char cName[11], cTmp[21], cNpcWaypointIndex[10], cSide, cOwnerType;
 short sOwnerH;
 BOOL bRet;
 int dX, dY;
	if (m_bIsHeldenianMode == TRUE) return;
	m_cHeldenianModeType	= sV1;
	m_sLastHeldenianWinner	= sV2;
	m_cHeldenianWinner		= 0;
	m_bHeldenianInitiated = TRUE;
	
	m_iHeldenianAresdenLeftTower = 0;
	m_iHeldenianElvineLeftTower = 0;
	m_iHeldenianAresdenDead = 0;
	m_iHeldenianElvineDead = 0;
	m_dwHeldenianGUID		= dwHeldenianGUID;
	CreateHeldenianGUID(m_dwHeldenianGUID, m_sLastHeldenianWinner);
	

	// Tell that you can TP to battlefield, and about construction points
	for (i = 0; i < DEF_MAXCLIENTS; i++) 
	{	if (m_pClientList[i] != NULL) 
		{	if (m_pClientList[i]->m_bIsInitComplete != TRUE) break;
			m_pClientList[i]->m_cVar = 2;
			SendNotifyMsg(NULL, i, DEF_NOTIFY_HELDENIANTELEPORT,  NULL , NULL, NULL, NULL); // You can now, go to the battle field
			m_pClientList[i]->m_dwHeldenianGUID    = m_dwHeldenianGUID;				
			m_pClientList[i]->m_iWarContribution   = 0;
			m_pClientList[i]->m_iConstructionPoint = 10000 + (m_pClientList[i]->m_iCharisma * 100);
			if (m_pClientList[i]->m_iConstructionPoint > DEF_MAXHELDENIANSUMMONPOINT) m_pClientList[i]->m_iConstructionPoint = DEF_MAXHELDENIANSUMMONPOINT;
			m_pClientList[i]->m_cVar = 2;// character have been informed of heldenian starting...
			SendNotifyMsg(NULL, i, DEF_NOTIFY_CONSTRUCTIONPOINT, m_pClientList[i]->m_iConstructionPoint, m_pClientList[i]->m_iWarContribution, 0, NULL); //0: Tell player of acquired points
			bUpdateHeldenianStatus(i);
	}	}
	// Recall clients already on battlefield; remove any Heldenian mob, and create current war towers/gates
	for (x = 0; x < DEF_MAXMAPS; x++) 
	{	if (m_pMapList[x] == NULL) break;
		if (m_pMapList[x]->m_bIsHeldenianMap == TRUE) 
		{	RemoveOccupyFlags(x);
			for (i = 0; i < DEF_MAXCLIENTS; i++) // Tell everybody on Heldenian map and recall them
			{	if (   (m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE) 
			&& (m_pClientList[i]->m_iAdminUserLevel == 0)
			&& (m_pClientList[i]->m_cMapIndex == x)	)
				{	SendNotifyMsg(NULL, i, DEF_NOTIFY_0BE8, NULL , NULL, NULL, NULL);
				RequestTeleportHandler(i, "1   ", NULL, -1, -1);
			}	}
			for (i = 0; i < DEF_MAXNPCS; i++) // Remove summons from last Heldenian
			{	if (   (m_pNpcList[i] != NULL) && (m_pNpcList[i]->m_bIsKilled == FALSE) 
					&& (m_pNpcList[i]->m_cMapIndex == x))
				{	if (m_pNpcList[i]->m_bIsSummoned == TRUE) 
					{	NpcKilledHandler(NULL, NULL, i, NULL);
					}else
					{	// Remove most mobs, and other Mobs become neutral
						// All mobs become neutral as players don't have spells or attacks...
						if (iDice(1,10)!= 5)
						{	m_pNpcList[i]->m_bIsUnsummoned = TRUE; 	
							NpcKilledHandler(i, DEF_OWNERTYPE_NPC, i, 0);
							DeleteNpc(i);
						}else m_pNpcList[i]->m_cSide = 0; 
			}	}	}	
			
							if (m_cHeldenianModeType == 1) {
					if (strcmp(m_pMapList[x]->m_cName, "BtField") == 0) {
						for (i = 0; i < MAX_HELDENIANTOWER; i++) {
							iNamingValue = m_pMapList[x]->iGetEmptyNamingValue();
							if ((m_pMapList[x]->m_stHeldenianTower[i].sTypeID < 1)  || (m_pMapList[x]->m_stHeldenianTower[i].sTypeID > DEF_MAXNPCTYPES)) break;
							if (iNamingValue != -1) {
								dX = m_pMapList[x]->m_stHeldenianTower[i].dX;
								dY = m_pMapList[x]->m_stHeldenianTower[i].dY;
 								cSide = m_pMapList[x]->m_stHeldenianTower[i].cSide;
								for (z = 0; z < DEF_MAXNPCTYPES; z++) {
									if (m_pNpcConfigList[z] == NULL) break;
									if (m_pNpcConfigList[z]->m_sType == m_pMapList[x]->m_stHeldenianTower[i].sTypeID) {
										ZeroMemory(cTmp, sizeof(cTmp));
										strcpy(cTmp, m_pNpcConfigList[z]->m_cNpcName);
									}
								}
								ZeroMemory(cName, sizeof(cName));
								wsprintf(cName, "XX%d", iNamingValue);
								cName[0] = 95;
								cName[1] = i + 65;
								bRet = iCreateNewNpc(cTmp, cName, m_pMapList[x]->m_cName, (rand() % 3), 0, DEF_MOVETYPE_GUARD, &dX, &dY, cNpcWaypointIndex, NULL, NULL, cSide, FALSE, TRUE, FALSE, TRUE, NULL);
								if (bRet == FALSE) {
									m_pMapList[x]->SetNamingValueEmpty(iNamingValue);
								}
								else {
									m_pMapList[x]->GetOwner(&sOwnerH, &cOwnerType, dX, dY);
									if ((m_pNpcList[sOwnerH] != NULL) && (sOwnerH > 0) && (sOwnerH < DEF_MAXNPCS)) {
										m_pNpcList[sOwnerH]->m_iBuildCount = 0;
											}
								if (cSide == 1)	m_iHeldenianAresdenLeftTower += 1;
								if (cSide == 2) m_iHeldenianElvineLeftTower += 1;
					}	}	}
					wsprintf(G_cTxt,"HeldenianAresdenLeftTower : %d , HeldenianElvineLeftTower : %d", m_iHeldenianAresdenLeftTower, m_iHeldenianElvineLeftTower);
					PutLogList(G_cTxt);
					PutLogEventFileList(G_cTxt);
					bUpdateHeldenianStatus(-1);
				}
			}else if (m_cHeldenianModeType == 2) 
			{	// Set master flag
				if (strcmp(m_pMapList[x]->m_cName, "GodH") == 0) //	if (m_iGodHMapIndex == x) 
				{	bSetOccupyFlag(x, m_pMapList[x]->m_sHeldenianWinningZoneX, m_pMapList[x]->m_sHeldenianWinningZoneY
							, m_sLastHeldenianWinner, 616, 0, TRUE); 
				}
								// Set Gates
				if (strcmp(m_pMapList[x]->m_cName, "HRampart") == 0) 
				{	for (i = 0; i < DEF_MAXHELDENIANDOOR; i++) 
					{	if (m_pMapList[x]->m_stHeldenianGateDoor[i].dX < 1)  break;
						iNamingValue = m_pMapList[x]->iGetEmptyNamingValue();
						if (iNamingValue != -1) 
						{	dX = m_pMapList[x]->m_stHeldenianGateDoor[i].dX;
							dY = m_pMapList[x]->m_stHeldenianGateDoor[i].dY;
							ZeroMemory(cTmp, sizeof(cTmp));
							if (m_sLastHeldenianWinner == 1) strcpy(cTmp, "gate-a"); 
							else							 strcpy(cTmp, "gate-e"); 
							cSide = m_sLastHeldenianWinner;
							ZeroMemory(cName, sizeof(cName));
							wsprintf(cName, "XX%d", iNamingValue);
							cName[0] = 95;
							cName[1] = i + 65;
							//bRet = iCreateNewNpc(cTmp, cName, m_pMapList[x]->m_cName, 0, (rand() % 255), DEF_MOVETYPE_GUARD, &dX, &dY, cNpcWaypointIndex, NULL, NULL, m_sLastHeldenianWinner, FALSE, FALSE);
				bRet = iCreateNewNpc(cTmp, cName, m_pMapList[x]->m_cName, (rand() % 3), 0, DEF_MOVETYPE_RANDOM, &dX, &dY, cNpcWaypointIndex, NULL, NULL, m_sLastHeldenianWinner, FALSE, TRUE, FALSE, TRUE, NULL);
							
							
							if (bRet == FALSE) 

							{	m_pMapList[x]->SetNamingValueEmpty(iNamingValue);
							}else 
							{	m_pMapList[x]->GetOwner(&sOwnerH, &cOwnerType, dX, dY);
								if ((m_pNpcList[sOwnerH] != NULL) && (sOwnerH > 0) && (sOwnerH < DEF_MAXNPCS)) 
								{	m_pNpcList[sOwnerH]->m_iBuildCount = 0;
									m_pNpcList[sOwnerH]->m_cSide = cSide;
									m_pNpcList[sOwnerH]->m_cDir = m_pMapList[x]->m_stHeldenianGateDoor[i].cDir;
									wsprintf(G_cTxt,"(_) Gate installed at %d,%d", dX, dY);
									PutLogList(G_cTxt);
		
	
	}	}	}	}	}	}	}	}
	m_bIsHeldenianMode = TRUE;	
	wsprintf(G_cTxt,"(_) Heldenian mode ON. (type %d, last winner:%d)", m_cHeldenianModeType, m_sLastHeldenianWinner);
	PutLogList(G_cTxt);
	PutLogList(" ");
	PutLogEventFileList(G_cTxt);
	PutLogEventFileList(" ");
}


void CGame::ManualStartHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize)
{char cBuff[256], * token, seps[] = "= \t\n";
 class CStrTok * pStrTok;
	if (m_bIsHeldenianMode == TRUE) return;
	if (m_bIsApocalypseMode == TRUE) return;
	if (m_bIsCrusadeMode == TRUE) return;
		if (m_pClientList[iClientH]->m_iAdminUserLevel < 3)
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);

	ZeroMemory(cBuff, sizeof(cBuff));
	memcpy(cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok(cBuff, seps);
	token = pStrTok->pGet();
	token = pStrTok->pGet();
	
if (token != NULL) 
{
 if (token[0] == '1')
 {
  m_cHeldenianModeType = 1;
  ShowClientMsg(iClientH, " Heldenian Type 1 Started!");
bUpdateHeldenianStatus(-1);
 }
 else if (token[0] == '2')
 {
  m_cHeldenianModeType = 2;
  ShowClientMsg(iClientH, " Heldenian Type 2 Started!");
  bUpdateHeldenianStatus(-1);
 }
}
	
	delete pStrTok;
	wsprintf(G_cTxt,"Admin Order(%s): begin Heldenian", m_pClientList[iClientH]->m_cCharName);
	PutAdminLogFileList(G_cTxt);
	PutLogList(G_cTxt);
	PutLogEventFileList(G_cTxt);
	GlobalStartHeldenianMode();
}
void CGame::ManualEndHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize)
{char	seps[] = "= \t\n";
 char	* token, cBuff[256];
 class	CStrTok * pStrTok;
	if ((dwMsgSize)	<= 0) return;	
	if (iClientH == NULL) return;	
	if (m_bIsHeldenianMode == FALSE) return;
	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_iAdminUserLevel < 3) {
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return;
	}
	
	ZeroMemory(cBuff, sizeof(cBuff));
	memcpy(cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok(cBuff, seps);
	token = pStrTok->pGet();
	token = pStrTok->pGet();
	if (token == NULL) // draw
	{	m_cHeldenianWinner = 0;
		wsprintf(G_cTxt,"GM Order(%s): Heldenian terminated, Draw", m_pClientList[iClientH]->m_cCharName);
	}else if (token != NULL) 
{	if (bGetIsStringIsNumber(token) == TRUE) 
		{	switch(atoi(token)) {
			case 1:
				m_cHeldenianWinner = 1;
				wsprintf(G_cTxt,"GM Order(%s): Heldenian terminated, Aresden victory", m_pClientList[iClientH]->m_cCharName);
				break;
			case 2:
				m_cHeldenianWinner = 2;
				wsprintf(G_cTxt,"GM Order(%s): Heldenian terminated, Elvine victory", m_pClientList[iClientH]->m_cCharName);
				break;
			default:	
				m_cHeldenianWinner = 0;
				wsprintf(G_cTxt,"GM Order(%s): Heldenian terminated, Draw", m_pClientList[iClientH]->m_cCharName);
				break;
			}
		}else 
		{	m_cHeldenianWinner = 0;	
			wsprintf(G_cTxt,"GM Order(%s): Heldenian terminated, Draw", m_pClientList[iClientH]->m_cCharName);
		}
	}
	PutAdminLogFileList(G_cTxt);
	PutLogEventFileList(G_cTxt);
	PutLogList(G_cTxt);
	GlobalEndHeldenianMode();
	delete pStrTok;
}
void CGame::AutomatedHeldenianTimer()
{
 DWORD dwTime;
 int x, i;

	dwTime = time(NULL);
	if ((dwTime == m_dwHeldenianStartTime - 300) && (m_bHeldenianInitiated != TRUE) && (m_bIsHeldenianMode != TRUE)) {
		wsprintf(G_cTxt,"Heldenian Fight Start");
		PutLogFileList(G_cTxt);
		m_bIsHeldenianMode = FALSE;
		for (x = 0; x < DEF_MAXMAPS; x++) {
			if (m_pMapList[x] == NULL) return;
			if (m_pMapList[x]->m_bIsHeldenianMap == TRUE) return;
			for (i = 0; i < DEF_MAXCLIENTS; i++) {
				if (m_pClientList[i] != NULL) {
					if (m_pClientList[i]->m_bIsInitComplete != TRUE) return;
					if (m_pClientList[i]->m_cMapIndex == x) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_HELDENIANSTART, NULL , NULL, NULL, NULL);					
					}
				}
			}
		}
	}
	if ((dwTime > (m_dwHeldenianFinishTime - 180)) && (m_bHeldenianInitiated == TRUE) && (m_bIsHeldenianMode != FALSE)) {
		wsprintf(G_cTxt,"Heldenian Fight End");
		PutLogFileList(G_cTxt);
		m_bHeldenianInitiated = FALSE;
		for (x = 0; x < DEF_MAXMAPS; x++) {
			if (m_pMapList[x] == NULL) return;
			if (m_pMapList[x]->m_bIsHeldenianMap == TRUE) return;
			for (i = 0; i < DEF_MAXCLIENTS; i++) {
				if (m_pClientList[i] != NULL) {
					if (m_pClientList[i]->m_bIsInitComplete != TRUE) return;
					if (m_pClientList[i]->m_cMapIndex == x) {
						SendNotifyMsg(NULL, i, DEF_NOTIFY_0BE8, NULL , NULL, NULL, NULL);
						RequestTeleportHandler(i, "1   ", NULL, -1, -1);
					}
				}
			}
		}
	}
}

void CGame::SetHeldenianMode()
{
 SYSTEMTIME SysTime;

	GetLocalTime(&SysTime);
	m_dwHeldenianStartHour = SysTime.wHour;
	m_dwHeldenianStartMinute = SysTime.wMinute;
		
	if (m_cHeldenianModeType != 2) {
		m_cHeldenianVictoryType = m_cHeldenianWinner;
	}
}

void CGame::NotifyStartHeldenianMode()
{
 register int i, x;
	
	if (m_bIsHeldenianMode == TRUE) return;
	if (m_bHeldenianInitiated == TRUE) return;
	if (var_88C != TRUE) {
		PutLogList("Heldenian Fight Start");
		m_bHeldenianInitiated = FALSE;
		for (i = 0; i < DEF_MAXMAPS; i++) {
			if (m_pMapList[i] == NULL) return;
			if (m_pMapList[i]->m_bIsHeldenianMap != TRUE) return;
			for (x = 0; x < DEF_MAXCLIENTS; x++) {
				if (m_pClientList[x] == NULL) return;
				if (m_pClientList[x]->m_bIsInitComplete != TRUE) return;
				if (m_pClientList[x]->m_cMapIndex == i) {
					SendNotifyMsg(NULL, x, DEF_NOTIFY_HELDENIANSTART, NULL, NULL, NULL, NULL);
				}
			}
		}
	}
}

void CGame::HeldenianEndWarNow()
{	if (m_bIsHeldenianMode == FALSE) return;
	DWORD dwTime = timeGetTime();
	if (dwTime < m_dwHeldenianFinishTime) return;
	if (m_cHeldenianModeType == 1) 
	{	if (m_iBTFieldMapIndex == -1) return;		
		// Type 1: BtField, victory depends on Tower destroyed...
				if (m_cHeldenianWinner == -1)
		{	if (m_iHeldenianAresdenLeftTower > m_iHeldenianElvineLeftTower) 
			{	m_cHeldenianWinner = 1;
			}else if (m_iHeldenianAresdenLeftTower < m_iHeldenianElvineLeftTower) 
			{	m_cHeldenianWinner = 2;
			}else if (m_iHeldenianAresdenFlags < m_iHeldenianElvineFlags)
			{	m_cHeldenianWinner = 1;
			}else if (m_iHeldenianAresdenFlags > m_iHeldenianElvineFlags) 
			{	m_cHeldenianWinner = 2;
			
		}	}		
	}else if (m_cHeldenianModeType == 2)
	{	if (m_iGodHMapIndex == -1) return;
		// Type 2: Victory for defenders if no victory before
		if (m_cHeldenianWinner == -1)
		{	m_cHeldenianWinner = m_sLastHeldenianWinner;
	}	}
	//bSendMsgToLS(MSGID_REQUEST_HELDENIAN_WINNER, NULL, 1, NULL);
	switch(m_cHeldenianWinner) {
	case 1: 
		wsprintf(G_cTxt, "Heldenian Terminated, Aresden victory.");
		bCrusadeLog(MSGID_REQUEST_HELDENIAN_WINNER, NULL, (int)m_cHeldenianModeType , "Aresden victory.");
		break;
	case 2: 
		wsprintf(G_cTxt, "Heldenian Terminated, Elvine victory.");
		bCrusadeLog(MSGID_REQUEST_HELDENIAN_WINNER, NULL, (int)m_cHeldenianModeType , "Elvine victory.");
		break;
	default: 
		wsprintf(G_cTxt, "Heldenian Terminated, Draw.");
		bCrusadeLog(MSGID_REQUEST_HELDENIAN_WINNER, NULL, (int)m_cHeldenianModeType , "Draw.");
		break;
	}
	PutLogEventFileList(G_cTxt);
	PutLogList(G_cTxt);
	GlobalEndHeldenianMode();
}


void CGame::RemoveHeldenianNpc(int iNpcH)
{
	if (m_pNpcList[iNpcH] == NULL) return;
	if (m_pNpcList[iNpcH]->m_bIsKilled == TRUE) return;

	m_pNpcList[iNpcH]->m_bIsKilled = TRUE;
	m_pNpcList[iNpcH]->m_iHP = 0;
	m_pNpcList[iNpcH]->m_iLastDamage = 0;
	m_pNpcList[iNpcH]->m_dwRegenTime = 0;
	m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iTotalAliveObject--;

	ReleaseFollowMode(iNpcH, DEF_OWNERTYPE_NPC);
	m_pNpcList[iNpcH]->m_iTargetIndex = 0;
	m_pNpcList[iNpcH]->m_cTargetType = 0;
			
	SendEventToNearClient_TypeA(iNpcH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTDYING, NULL, 1, NULL);
	m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->ClearOwner(10, iNpcH, DEF_OWNERTYPE_NPC, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY);
	m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->SetDeadOwner(iNpcH, DEF_OWNERTYPE_NPC, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY);
	m_pNpcList[iNpcH]->m_cBehavior = 4;
	m_pNpcList[iNpcH]->m_sBehaviorTurnCount = 0;
	m_pNpcList[iNpcH]->m_dwDeadTime = timeGetTime();

}

void CGame::CreateHeldenianGUID(DWORD dwHeldenianGUID, int iWinnerSide)
{
 char * cp, cTxt[256], cFn[256], cTemp[1024];	
 FILE * pFile;
		
	_mkdir("GameData");
	ZeroMemory(cFn, sizeof(cFn));
	strcat(cFn,"GameData");
	strcat(cFn,"\\");
	strcat(cFn,"\\");					  
	strcat(cFn,"HeldenianGUID.Txt");
		
	pFile = fopen(cFn, "wt");
	if (pFile == NULL) {
		wsprintf(cTxt, "(!) Cannot create HeldenianGUID(%d) file", dwHeldenianGUID);
		PutLogList(cTxt);
	}
	else {
		ZeroMemory(cTemp, sizeof(cTemp));
		
		ZeroMemory(cTxt, sizeof(cTxt));
		wsprintf(cTxt, "HeldenianGUID = %d\n", dwHeldenianGUID);
		strcat(cTemp, cTxt);

		ZeroMemory(cTxt, sizeof(cTxt));
		wsprintf(cTxt, "winner-side = %d\n", iWinnerSide);
		strcat(cTemp, cTxt);
		
		cp = (char *)cTemp;
		fwrite(cp, strlen(cp), 1, pFile);
		
	wsprintf(G_cTxt, "(_) HeldenianGUID (%d) file created. (Winner %d)", dwHeldenianGUID, iWinnerSide);
		PutLogList(G_cTxt);
	}
	if (pFile != NULL) fclose(pFile);
}
void CGame::HeldenianVictoryNow(int iSide) 
{	if (m_bHeldenianInitiated == FALSE) return;
	DWORD dwTime = timeGetTime();
	m_bHeldenianInitiated = FALSE;	
	m_cHeldenianWinner = iSide;
	switch(m_cHeldenianWinner) {
	case 1: 
		wsprintf(G_cTxt, "Aresden victory.");
		bCrusadeLog(MSGID_REQUEST_HELDENIAN_WINNER, NULL, (int)m_cHeldenianModeType, "Aresden victory.");		
		break;
	case 2: 
		wsprintf(G_cTxt, "Elvine victory.");
		bCrusadeLog(MSGID_REQUEST_HELDENIAN_WINNER, NULL, (int)m_cHeldenianModeType, "Elvine victory.");
		break;
	default: 
		wsprintf(G_cTxt, "Draw.");
		bCrusadeLog(MSGID_REQUEST_HELDENIAN_WINNER, NULL, (int)m_cHeldenianModeType, "Draw.");
		break;
	}
	PutLogList(G_cTxt);
	PutLogEventFileList(G_cTxt);

	m_dwHeldenianFinishTime   = timeGetTime() + 5*60*1000;  // war will end in 5 minutes
	int m;	
register int j, n;
	for (m = 0; m < DEF_MAXMAPS; m++)
	{	if (m_pMapList[m] == NULL) break;
		if (m_pMapList[m]->m_bIsHeldenianMap == TRUE) 
		{	for (j = 0; j < DEF_MAXCLIENTS; j++)
			{	if (   (m_pClientList[j] != NULL)
					&& (m_pClientList[j]->m_bIsInitComplete == TRUE)
					&& (m_pClientList[j]->m_cMapIndex == m))
				{	bUpdateHeldenianStatus(j);
					SendNotifyMsg(NULL, j, DEF_NOTIFY_HELDENIANEND,  m_cHeldenianWinner, NULL, NULL, NULL); // Victory defeat screen
					if (   (m_pClientList[j]->m_cSide != iSide)// recall loosers only
						&& (m_pClientList[j]->m_iAdminUserLevel == 0))
					{	SendNotifyMsg(NULL, j, DEF_NOTIFY_0BE8, NULL , NULL, NULL, NULL);
						m_pClientList[j]->m_bIsWarLocation = TRUE;
						m_pClientList[j]->m_iTimeLeft_ForceRecall = 3;
						//RequestTeleportHandler(j, "1   ", NULL, -1, -1);
			}	}	}
			for (n = 0; n < DEF_MAXNPCS; n++)
			{	if (   (m_pNpcList[n] != NULL) 
					&& (m_pNpcList[n]->m_cMapIndex == m)
					&& (m_pNpcList[n]->m_cSide != iSide))
				{	if (m_pNpcList[n]->m_bIsSummoned == TRUE) 
					{	NpcKilledHandler(NULL, NULL, n, NULL);
					}else
					{	m_pNpcList[n]->m_cSide = 0; // All mobs become neutral as players no more have spells or attacks...
	}	}	}	}	
			}
	
	CreateHeldenianGUID(m_dwHeldenianGUID, m_cHeldenianWinner);
}

BOOL CGame::bReadHeldenianGUIDFile(char * cFn)
{
 FILE * pFile;
 HANDLE hFile;
 DWORD  dwFileSize;
 char * cp, * token, cReadMode;
 char seps[] = "= \t\n";
 class CStrTok * pStrTok;

	cReadMode = 0;

	hFile = CreateFile(cFn, GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL);
	dwFileSize = GetFileSize(hFile, NULL);
	if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);

	pFile = fopen(cFn, "rt");
	if (pFile == NULL) {
		PutLogList("(!) Cannot open HeldenianGUID file.");
		return FALSE;
	}
	else {
		PutLogList("(!) Reading HeldenianGUID file...");
		cp = new char[dwFileSize+2];
		ZeroMemory(cp, dwFileSize+2);
		fread(cp, dwFileSize, 1, pFile);

		pStrTok = new class CStrTok(cp, seps);
		token = pStrTok->pGet();

		while( token != NULL )   {
			
			if (cReadMode != 0) {
				switch (cReadMode) {
				case 1:
					m_dwHeldenianGUID = atoi(token);
					wsprintf(G_cTxt, "(!) HeldenianGUID = %d", m_dwHeldenianGUID);
					PutLogList(G_cTxt);
					cReadMode = 0;
					break;

				case 2:
					// New 13/05/2004 Changed
					m_sLastHeldenianWinner = atoi(token);
					wsprintf(G_cTxt, "(!) HeldenianWinnerSide = %d", m_sLastHeldenianWinner);
					PutLogList(G_cTxt);
					cReadMode = 0;
					break;
				}
			}
			else {
				if (memcmp(token, "HeldenianGUID", 11) == 0) cReadMode = 1;
				if (memcmp(token, "winner-side", 11) == 0) cReadMode = 2;
			}
			
			token = pStrTok->pGet();
		}

		delete pStrTok;
		delete cp;
	}
	if (pFile != NULL) fclose(pFile);

	return TRUE;
}


BOOL CGame::bNotifyHeldenianWinner()
{
	if (var_88C == 0) {
		bSendMsgToLS(MSGID_REQUEST_HELDENIAN_WINNER, NULL, 1, NULL);
		return TRUE;
	}
	else {
		return FALSE;
	}

}

BOOL CGame::bCheckHeldenianMap(int sAttackerH, int iMapIndex, char cType) 
{	if (m_bHeldenianInitiated == FALSE) return FALSE;
 short tX, tY;
 BOOL iRet;
class CTile * pTile;
	iRet = FALSE;
	if (cType == DEF_OWNERTYPE_PLAYER) 
	{	if (m_pClientList[sAttackerH] == NULL)					return FALSE;
		if (m_pClientList[sAttackerH]->m_cSide < 1)				return FALSE;
		if (m_pClientList[sAttackerH]->m_cSide > 2)				return FALSE;
		iMapIndex = m_pClientList[sAttackerH]->m_cMapIndex;
		if (m_pMapList[iMapIndex]->m_bIsHeldenianMap != TRUE)	return FALSE;
		if (m_iGodHMapIndex  == iMapIndex)						return FALSE;
		tX = m_pClientList[sAttackerH]->m_sX;
		tY = m_pClientList[sAttackerH]->m_sY;
		if (   (tX <= 0) || (tX >= m_pMapList[iMapIndex]->m_sSizeX) 
			|| (tY <= 0) || (tY >= m_pMapList[iMapIndex]->m_sSizeY)) return FALSE;
		pTile = (class CTile *)(m_pMapList[iMapIndex]->m_pTile + tX + tY*m_pMapList[iMapIndex]->m_sSizeY);
		if (pTile == NULL) return FALSE;
		if (pTile->m_iOccupyStatus != NULL) 
		{	if (pTile->m_iOccupyStatus < 0) 
			{	if (m_pClientList[sAttackerH]->m_cSide == 1) 
				{	iRet = TRUE;
				}
			}else if (pTile->m_iOccupyStatus > 0) 
			{	if (m_pClientList[sAttackerH]->m_cSide == 2) 
				{	iRet = TRUE;
		}	}	}		
	}else if (cType == DEF_OWNERTYPE_NPC) 
	{	if (m_pNpcList[sAttackerH] == NULL)						return FALSE;
		if (m_pNpcList[sAttackerH]->m_cSide < 1)				return FALSE;
		if (m_pNpcList[sAttackerH]->m_cSide > 2)				return FALSE;
		iMapIndex = m_pNpcList[sAttackerH]->m_cMapIndex;
		if (m_pMapList[iMapIndex]->m_bIsHeldenianMap != TRUE)	return FALSE;	
		if (m_iGodHMapIndex  == iMapIndex)						return FALSE;
		tX = m_pNpcList[sAttackerH]->m_sX;
		tY = m_pNpcList[sAttackerH]->m_sY;
		if (   (tX <= 0) || (tX >= m_pMapList[iMapIndex]->m_sSizeX) 
			|| (tY <= 0) || (tY >= m_pMapList[iMapIndex]->m_sSizeY)) return FALSE;
		pTile = (class CTile *)(m_pMapList[iMapIndex]->m_pTile + tX + tY*m_pMapList[iMapIndex]->m_sSizeY);
		if (pTile == NULL) return FALSE;
		if (pTile->m_iOccupyStatus != NULL) 
		{	if (pTile->m_iOccupyStatus < 0) 
			{	if (m_pNpcList[sAttackerH]->m_cSide == 1) 
				{	iRet = TRUE;
				}
			}else if (pTile->m_iOccupyStatus > 0) 
				{	if (m_pNpcList[sAttackerH]->m_cSide == 2) 
				{	iRet = TRUE;
	}	}	}	}
	return iRet;
}
BOOL CGame::bUpdateHeldenianStatus(int iClientH)
{	if (m_bIsHeldenianMode == FALSE)  return FALSE;
	if (m_cHeldenianModeType != 1)		  return FALSE; 
	if (iClientH != -1) 
	{	if (   (m_pClientList[iClientH] != NULL) 
		//	&& (m_pClientList[iClientH]->m_bIsInitComplete == TRUE)
			&& (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_bIsHeldenianMap == TRUE) 
			&& (m_pClientList[iClientH]->m_cMapIndex == m_iBTFieldMapIndex)) 
		{	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HELDENIANCOUNT, m_iHeldenianAresdenLeftTower, m_iHeldenianElvineLeftTower, m_iHeldenianAresdenDead, NULL, m_iHeldenianElvineDead, NULL);
			return TRUE;
		}
	}else // Update for everybody
	{
BOOL bFlag = TRUE;
int iShortCutIndex = 0;
int i;
		while(bFlag)
		{	i = m_iClientShortCut[iShortCutIndex];
			iShortCutIndex++;
			if (i == 0) 
			{	bFlag = FALSE;	
			}else
			{	if (   (m_pClientList[i] != NULL) 
					&& (m_pClientList[i]->m_bIsInitComplete == TRUE)
					&& (m_pMapList[m_pClientList[i]->m_cMapIndex]->m_bIsHeldenianMap == TRUE) 
					&& (m_pClientList[i]->m_cMapIndex == m_iBTFieldMapIndex)) 
							{	SendNotifyMsg(NULL, i, DEF_NOTIFY_HELDENIANCOUNT, m_iHeldenianAresdenLeftTower
								, m_iHeldenianElvineLeftTower, m_iHeldenianAresdenDead, NULL, m_iHeldenianElvineDead, NULL);
	}
		
	return TRUE;
}
		}
	}
}

BOOL CGame::__bSetOccupyFlag(char cMapIndex, int dX, int dY, int iSide, int iEKNum, int iClientH, BOOL bAutoFlag)
{register int ix,iy;
 int   iDynamicObjectIndex, iIndex;
 class CTile * pTile;
 DWORD dwTime = timeGetTime();	
	if (m_pMapList[cMapIndex] == NULL)									return FALSE;
	if ((m_bHeldenianInitiated == FALSE)&&(bAutoFlag == FALSE))		return FALSE; // War must be started is player flag
	if (m_cHeldenianWinner = NULL)										return FALSE; // War must not be finished
	if ((m_cHeldenianModeType == 1) && (m_iBTFieldMapIndex != cMapIndex))	return FALSE; // Type 1: only on BattleField
	if (   (m_cHeldenianModeType == 2) && (m_iRampartMapIndex != cMapIndex)				  // Type 2: 
		&& (m_iGodHMapIndex  != cMapIndex))                             return FALSE; // allowed only in HRampart / GodH
	if (   (m_cHeldenianModeType == 2) 										   			  // Type 2: 
		&& (m_iGodHMapIndex  == cMapIndex)											  // on GodH, allowed only
		&& (bAutoFlag == FALSE)														  // as autoflag
		&& (m_pClientList[iClientH] != NULL))									
	{	if (m_pClientList[iClientH]->m_cSide == m_sLastHeldenianWinner) return FALSE; // for attackers only
		if (m_pClientList[iClientH]->m_iGuildRank != 0)					return FALSE; // for a gm only
		if (   (abs(m_pMapList[cMapIndex]->m_sHeldenianWinningZoneX - dX) > 2)
			|| (abs(m_pMapList[cMapIndex]->m_sHeldenianWinningZoneY - dY) > 2)) return FALSE; // and in wining zone only
	}	
	if (   (dX < 25) || (dX >= m_pMapList[cMapIndex]->m_sSizeX - 25)
		|| (dY < 25) || (dY >= m_pMapList[cMapIndex]->m_sSizeY - 25))	return FALSE;

	pTile = (class CTile *)(m_pMapList[cMapIndex]->m_pTile + dX + dY*m_pMapList[cMapIndex]->m_sSizeY);
	if (pTile->m_iAttribute != NULL)									return FALSE;
	if (pTile->m_iOccupyFlagIndex != NULL)								return FALSE;
	if (pTile->m_bIsMoveAllowed == FALSE)								return FALSE;
	if (m_pMapList[cMapIndex]->m_iTotalOccupyFlags >= DEF_MAXOCCUPYFLAG) 
	{	return FALSE;
	}
	if (bAutoFlag == FALSE) // Flag set by a character
	{	if (m_pClientList[iClientH] == NULL) return FALSE;	
		switch (m_pClientList[iClientH]->m_cSide) {
		case 1:	// Aresden
			iDynamicObjectIndex = iAddDynamicObjectList(NULL, NULL, DEF_DYNAMICOBJECT_ARESDENFLAG1, cMapIndex, dX, dY, NULL, NULL);	
			break;
		case 2: // Elvine	
			iDynamicObjectIndex = iAddDynamicObjectList(NULL, NULL, DEF_DYNAMICOBJECT_ELVINEFLAG1, cMapIndex, dX, dY, NULL, NULL);	
			break;
		default: // Others
			return FALSE;
			break;
		}	
		if (iDynamicObjectIndex == NULL) return FALSE;
		iIndex = m_pMapList[cMapIndex]->iRegisterOccupyFlag(dX, dY, iSide, iEKNum, iDynamicObjectIndex);
		if (iIndex == -1) PutLogList("Error registering OccupyFlag.");	
		for (ix = dX-iEKNum; ix <= dX+iEKNum; ix++) 
		for (iy = dY-iEKNum; iy <= dY+iEKNum; iy++) 
		{	if ((ix == dX) && (iy == dY)) 
			{}else 
			{	pTile = (class CTile *)(m_pMapList[cMapIndex]->m_pTile + ix + iy*m_pMapList[cMapIndex]->m_sSizeY);			
				if (pTile->m_iOccupyFlagIndex == NULL) 
				{	switch (m_pClientList[iClientH]->m_cSide) {
					case 1:	// Aresden 
						pTile->m_iOccupyStatus -= iEKNum; 
						break;
					case 2: // Elvine	
						pTile->m_iOccupyStatus += iEKNum; 
						break;
					default:
						pTile->m_iOccupyStatus = 0;
						break;
		}
				}	
		switch (m_pClientList[iClientH]->m_cSide) {
		case 1:	// Aresden 
			m_iHeldenianAresdenFlags ++;
			break;
		case 2: // Elvine	
			m_iHeldenianElvineFlags ++;				
			break;
		}
		wsprintf(G_cTxt, "PC(%s) \tused Flag...\t%s(%d %d)"
			, m_pClientList[iClientH]->m_cCharName
			, m_pClientList[iClientH]->m_cMapName
			, dX
			, dY);
		PutItemLogFileList(G_cTxt);
		PutLogEventFileList(G_cTxt);
		PutLogList(G_cTxt);	
		// Heldenian type 2 is won !
		if (   (m_pClientList[iClientH]->m_iGuildRank == 0)					// only by GuildMaster
			&& (m_pClientList[iClientH]->m_cSide != m_sLastHeldenianWinner) // only by attacker side
			&& (m_iGodHMapIndex == cMapIndex))								// only on GodHMap
		{	m_pClientList[iClientH]->m_iWarContribution   += (1000 * iEKNum); // double bonus for gm putting the flag...
			HeldenianVictoryNow(m_pClientList[iClientH]->m_cSide);
		//GlobalEndHeldenianMode();
		}
		// give some Summon points in case the character was killed, he will be able to catch more scrolls..
		m_pClientList[iClientH]->m_iConstructionPoint += (1000 * iEKNum);
		m_pClientList[iClientH]->m_iWarContribution   += (100 * iEKNum);
		bUpdateHeldenianStatus(-1);
		if (m_pClientList[iClientH]->m_iConstructionPoint > DEF_MAXHELDENIANSUMMONPOINT) m_pClientList[iClientH]->m_iConstructionPoint = DEF_MAXHELDENIANSUMMONPOINT;
	}
}
	}
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
client.cpp

	m_dwHeldenianGUID = NULL;
client.h
	DWORD m_dwHeldenianGUID;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
game.h


#define DEF_DEF_MAXHELDENIANDOOR		10
#define DEF_MAXHELDENIAN				10
#define MAX_HELDENIANTOWER				200
#define DEF_MAXHELDENIANSUMMONPOINT		300


void HeldenianEndWarNow();
void NotifyStartHeldenianFightMode();
void RequestHeldenianScroll(int iClientH, char * pData, DWORD dwMsgSize);
void HeldenianVictoryNow(int iSide); 
void SetHeldenianMode();
void AutomatedHeldenianTimer();
	void LocalStartHeldenianMode(short sV1, short sV2, DWORD dwHeldenianGUID);
	void GlobalStartHeldenianMode();
	void HeldenianWarEnder();
	void HeldenianWarStarter();
	BOOL bUpdateHeldenianStatus(int iClientH);
	void CreateHeldenianGUID(DWORD dwHeldenianGUID, int iWinnerSide);
	void ManualStartHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void ManualEndHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void NotifyStartHeldenianMode();
    void GlobalEndHeldenianMode();
	void LocalEndHeldenianMode();
	BOOL bNotifyHeldenianWinner();
	void RemoveHeldenianNpc(int iNpcH);
	void RemoveOccupyFlags(int iMapIndex);
	void RequestHeldenianTeleport(int iClientH, char * pData, DWORD dwMsgSize);
	BOOL bCheckHeldenianMap(int sAttackerH, int iMapIndex, char cType);
	BOOL bReadHeldenianGUIDFile(char * cFn);
	

		struct {
		int iDay;
		int StartiHour;
		int StartiMinute;
		int EndiHour;
		int EndiMinute;
	} m_stHeldenianSchedule[DEF_MAXHELDENIAN];

		int   m_cHeldenianWinner;
		BOOL	m_bIsHeldenianMode;
	BOOL	m_bIsHeldenianTeleport;
	char	m_cHeldenianModeType;
	char m_cHeldenianVictoryType, m_sLastHeldenianWinner;
	int m_iHeldenianAresdenDead, m_iHeldenianElvineDead, m_cHeldenianFirstDestroyedTowerWinner, var_A38, var_88C;
	int m_iHeldenianAresdenLeftTower, m_iHeldenianElvineLeftTower, m_iHeldenianAresdenFlags, m_iHeldenianElvineFlags;
	DWORD m_dwHeldenianGUID, m_dwHeldenianStartHour, m_dwHeldenianStartMinute, m_dwHeldenianStartTime, m_dwHeldenianFinishTime;
	BOOL m_bHeldenianInitiated;
	BOOL m_bHeldenianRunning;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
map.cpp
		m_bIsHeldenianMap = FALSE;

		for (i = 0; i < DEF_MAXHELDENIANDOOR; i++) {
		m_stHeldenianGateDoor[i].cDir = 0;
		m_stHeldenianGateDoor[i].dX = 0;
		m_stHeldenianGateDoor[i].dY = 0;
	}

	for (i = 0; i < DEF_MAXHELDENIANTOWER; i++) {
		m_stHeldenianTower[i].sTypeID = 0;
		m_stHeldenianTower[i].cSide = 0;
		m_stHeldenianTower[i].dX = 0;
		m_stHeldenianTower[i].dY = 0;
		
	}
	map.h
		#define DEF_MAXHELDENIANDOOR	200
		#define DEF_MAXHELDENIANTOWER	200

		short m_sHeldenianTowerType, m_sHeldenianTowerXPos, m_sHeldenianTowerYPos, m_sHeldenianWinningZoneX, m_sHeldenianWinningZoneY;
	char  m_cHeldenianTowerSide;
	char  m_cHeldenianModeMap;


	struct {
		char  cDir;
		short dX;
		short dY;
	} m_stHeldenianGateDoor[DEF_MAXHELDENIANDOOR];

	struct {
		short sTypeID;
		char  cSide;
		short dX;
		short dY;
		
	} m_stHeldenianTower[DEF_MAXHELDENIANTOWER];


	BOOL m_bIsHeldenianMap;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 If You Need Better InStrution Just Ask I Was Half Asleep When i grabed it Any ? just ask :P 


