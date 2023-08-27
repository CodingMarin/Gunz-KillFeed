//find
//  m_AdminMsg.Create("CombatChatOutputAdmin", false);
//	MFont* pFont = MFontManager::Get("FONTb11b");
//	m_AdminMsg.SetFont(pFont);
//	m_AdminMsg.m_pChattingOutput->ReleaseFocus();
//add below

  m_NotifyKills.Create("KillNotifications", true);
	m_NotifyKills.ShowOutput(ZGetConfiguration()->GetViewGameChat());
	m_NotifyKills.m_pChattingOutput->ReleaseFocus();
	MFont* pFontCustom3 = MFontManager::Get("FONTa7");
	m_NotifyKills.SetFont(pFontCustom3);

//find
//m_Chat.OnDraw(pDC);
//
//		if (!m_bSkipUIDrawByRule)
//		{
//add inside {

  m_NotifyKills.OnDraw(pDC);

//add new
void ZCombatInterface::OutputNotifyKills(const char* szMsg)
{
	m_NotifyKills.OutputChatMsg(szMsg);
}

//find
//void ZCombatInterface::ShowInfo(bool bVisible)
//{
//add inside {
pWidget = m_pIDLResource->FindWidget(ZIITEM_COMBAT_NOTFRAME);
	if (pWidget != NULL)
	{
		pWidget->Show(bVisible);
	}

//find
//m_Chat.Update();
//m_AdminMsg.Update();
//add below
m_NotifyKills.Update();
