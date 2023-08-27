//find
/*
  case MC_MATCH_STAGE_ENTERBATTLE:
	{
		unsigned char nParam;
		pCommand->GetParameter(&nParam, 0, MPT_UCHAR);

		MCommandParameter* pParam = pCommand->GetParameter(1);
		if (pParam->GetType() != MPT_BLOB) break;
		void* pBlob = pParam->GetPointer();

		MTD_PeerListNode* pPeerNode = (MTD_PeerListNode*)MGetBlobArrayElement(pBlob, 0);
		OnStageEnterBattle(MCmdEnterBattleParam(nParam), pPeerNode);
	}
	break;
*/
//add below
case MC_FIND_WEAPON:
	{
		int WeaponType;

		pCommand->GetParameter(&WeaponType, 0, MPT_INT);

		ZCharacter* pCharacter = (ZCharacter*)ZGetCharacterManager()->Find(pCommand->GetSenderUID());
		if (pCharacter == NULL) break;

		pCharacter->GetStatus().CheckCrc();
		pCharacter->GetStatus().Ref().LastWeapon = (MMatchWeaponType)WeaponType;
		pCharacter->GetStatus().MakeCrc();
	}
	break;

//find
/*
  if (ZGetMyUID() == pOwnerCharacter->GetUID())
	{
		ZItem* pSelItem = pOwnerCharacter->GetItems()->GetSelectedWeapon();
		if (pSelItem && pSelItem->GetDesc() &&
			pSelItem->GetDesc()->IsSpendableItem())
		{
			ZMyItemNode* pItemNode = ZGetMyInfo()->GetItemList()->GetEquipedItem((MMatchCharItemParts)sel_type);
			if (pItemNode)
			{
				pItemNode->SetItemCount(pItemNode->GetItemCount() - 1);
				ZPostRequestUseSpendableNormalItem(pItemNode->GetUID());
			}
		}
	}
*/
//add below
  pOwnerCharacter->SetWeaponDamaged(pItem->GetDesc()->m_nWeaponType.Ref());
	ZPostLastWeaponUsed(pItem->GetDesc()->m_nWeaponType.Ref());


//find
/*
  if(Z_VIDEO_DYNAMICLIGHT)
		ZGetStencilLight()->AddLightSource( v1, 2.0f, 75 );
*/
//add below
  pOwnerCharacter->SetWeaponDamaged(pItem->GetDesc()->m_nWeaponType.Ref());
	ZPostLastWeaponUsed(pItem->GetDesc()->m_nWeaponType.Ref());


//find
/*
  if(wtype == MWT_SHOTGUN)
	{
		OnPeerShot_Shotgun(pItem,pOwnerCharacter,fShotTime,pos,to);
		return;
	} else {
		OnPeerShot_Range(sel_type,uid,fShotTime,pos,to);

		rvector position;
		pOwnerCharacter->GetWeaponTypePos( weapon_dummy_muzzle_flash , &position );
		if( ZGetConfiguration()->GetVideo()->bDynamicLight )
		{
			RGetDynamicLightManager()->AddLight( GUNFIRE, position );
		}
	}
*/
//add below
  pOwnerCharacter->SetWeaponDamaged(pItem->GetDesc()->m_nWeaponType.Ref());
	ZPostLastWeaponUsed(pItem->GetDesc()->m_nWeaponType.Ref());

//add new
#define PREFIX "\xbd"
char* GetWeaponName(MMatchWeaponType WeaponType)
{
	static char szType[38][64] =
	{
		"MWT_NONE",

		// Melee Weapons
		"E",  // MWT_DAGGER
		"R",  // MWT_DUAL_DAGGER
		"Q",  // MWT_KATANA
		"O",  // MWT_DOUBLE_KATANA
		"L",  // MWT_GREAT_SWORD

		// Range Weapons
		"Y",  // MWT_PISTOL
		"T",  // MWT_PISTOLx2
		"Y",  // MWT_REVOLVER
		"T",  // MWT_REVOLVERx2
		"U",  // MWT_SMG
		"I",  // MWT_SMGx2
		"S",  // MWT_SHOTGUN
		"S",  // MWT_SAWED_SHOTGUN
		"P",  // MWT_RIFLE
		"F",  // MWT_MACHINEGUN
		"A",  // MWT_ROCKET
		"D",  // MWT_SNIFER

		"G",  // MWT_MED_KIT
		"G",  // MWT_REPAIR_KIT
		"MWT_BULLET_KIT",
		"MWT_FLASH_BANG",
		"H",  // MWT_FRAGMENTATION
		"MWT_SMOKE_GRENADE",
		"H",  // MWT_FRAGMENTATION
		"MWT_SKILL",

		"MWT_ENCHANT_FIRE",
		"MWT_ENCHANT_COLD",
		"MWT_ENCHANT_LIGHTNING",
		"MWT_ENCHANT_POISON",

		"MWT_POTION",
		"J",
		"MWT_DYNAMITYE",

		"MWT_STUNGRENADE",
		"MWT_LANDMINE",
		"MWT_SPYCASE",

		"MWT_END" };
	return szType[WeaponType];
}

//find 
//void ZGame::OnPeerDieMessage(ZCharacter* pVictim, ZCharacter* pAttacker)
//{
//add inside {
char szFeed[512];
		if (RGetIsWidthScreen() || RGetIsLongScreen())
		{
			switch (pAttacker->GetTeamID())
			{
			case MMT_ALL:
				sprintf(szFeed, "%sK   %s   %s%s             %s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			case MMT_RED:
				sprintf(szFeed, "%sK   ^1%s   %s%s             ^H%s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			case MMT_BLUE:
				sprintf(szFeed, "%sK   ^H%s   %s%s             ^1%s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			default:
				sprintf(szFeed, "%sK   %s   %s%s             %s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			}
			if (pVictim == pAttacker)
			{
				switch (pAttacker->GetTeamID())
				{
				case MMT_RED:
					sprintf(szFeed, "%sK %sW                ^1%s", PREFIX, PREFIX, pAttacker->GetProperty()->GetName());
					break;
				case MMT_BLUE:
					sprintf(szFeed, "%sK %sW                ^H%s", PREFIX, PREFIX, pAttacker->GetProperty()->GetName());
					break;
				default:
					sprintf(szFeed, "%sK %sW                ^M%s", PREFIX, PREFIX, pAttacker->GetProperty()->GetName());
					break;
				}
			}
		}
		else {
			switch (pAttacker->GetTeamID())
			{
			case MMT_ALL:
				sprintf(szFeed, "%sK   ^1%s   %s%s                   %s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			case MMT_RED:
				sprintf(szFeed, "%sK   ^1%s   %s%s                    ^H%s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			case MMT_BLUE:
				sprintf(szFeed, "%sK   ^H%s   %s%s                    ^1%s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			default:
				sprintf(szFeed, "%sK   ^1%s   %s%s                   %s", PREFIX, pAttacker->GetProperty()->GetName(), PREFIX, GetWeaponName(pAttacker->GetLastW()), pVictim->GetProperty()->GetName());
				break;
			}

			if (pVictim == pAttacker)
			{
				switch (pAttacker->GetTeamID())
				{
				case MMT_RED:
					sprintf(szFeed, "%sK %sW                       ^1%s", PREFIX, PREFIX, pAttacker->GetProperty()->GetName());
					break;
				case MMT_BLUE:
					sprintf(szFeed, "%sK %sW                       ^H%s", PREFIX, PREFIX, pAttacker->GetProperty()->GetName());
					break;
				default:
					sprintf(szFeed, "%sK %sW                       ^M%s", PREFIX, PREFIX, pAttacker->GetProperty()->GetName());
					break;
				}
			}
		ZGetCombatInterface()->OutputNotifyKills(szFeed);
		ZGetCombatInterface()->OutputNotifyKills("\n");
	}
