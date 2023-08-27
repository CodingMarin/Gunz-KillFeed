//find
//  ZCombatChat			m_Chat;
//	ZCombatChat			m_AdminMsg;
//add below
ZNotifyKills		m_NotifyKills;

//find
//  void OutputChatMsg(const char* szMsg);
//	void OutputChatMsg(MCOLOR color, const char* szMsg);
//add below
void OutputNotifyKills(const char* szMsg);
