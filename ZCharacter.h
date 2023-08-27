//find
//struct ZCharacterStatus
//{
//add inside
MMatchWeaponType LastWeapon;

//find
//ZCharacterStatus() :
//add inside
LastWeapon(MWT_NONE),

//find
//void SetAdminHide(bool bHide) { m_dwStatusBitPackingValue.Ref().m_bAdminHide = bHide; }
//add below
MMatchWeaponType WType;
void SetWeaponDamaged(MMatchWeaponType wWeapon) { WType = wWeapon; }
MMatchWeaponType GetWeaponDamaged() { return WType; }
MMatchWeaponType GetLastW() { return GetStatus().Ref().LastWeapon; }
