//find 
//ZObject::OnDamaged(pAttacker,srcPos,damageType,weaponType,fDamage,fPiercingRatio,nMeleeType);
//if(damageType==ZD_MELEE) OnDamagedAnimation(pAttacker,nMeleeType);
//m_dwStatusBitPackingValue.Ref().m_bDamaged = true;
//add below

SetWeaponDamaged((MMatchWeaponType)weaponType);
ZPostLastWeaponUsed(weaponType);
