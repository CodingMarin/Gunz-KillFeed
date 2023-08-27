//find
//void ZMyCharacter::InitStatus()
//{
//add inside {
  SetWeaponDamaged(MWT_NONE);
	ZPostLastWeaponUsed(MWT_NONE);

//find
//void ZMyCharacter::OnDamaged(ZObject* pAttacker, rvector srcPos, ZDAMAGETYPE damageType, MMatchWeaponType weaponType, float fDamage, float fPiercingRatio, int nMeleeType)
//{
//add inside {
  SetWeaponDamaged(weaponType);
	ZPostLastWeaponUsed(weaponType);
