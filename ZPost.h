inline void ZPostLastWeaponUsed(int nWeapon)
{
	ZPOSTCMD1(MC_FIND_WEAPON, MCommandParameterInt((MMatchWeaponType)nWeapon));
}
