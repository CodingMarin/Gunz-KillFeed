//add
ZNotifyKills::ZNotifyKills()
{
	m_nLastChattingMsgTime = 0;
	m_pIDLResource = ZApplication::GetGameInterface()->GetIDLResource();

	m_pChattingOutput = NULL;
	m_bShowOutput = true;
}

ZNotifyKills::~ZNotifyKills()
{

}

bool ZNotifyKills::Create(char* szOutputTxtarea, bool bUsePlayerList)
{

	MWidget* pWidget = m_pIDLResource->FindWidget("KillNotifications");
	if (pWidget != NULL)
	{
		pWidget->SetListener(ZGetCombatChatInputListener());
	}

	m_pChattingOutput = NULL;
	pWidget = m_pIDLResource->FindWidget(szOutputTxtarea);
	if (pWidget != NULL)
	{
		m_pChattingOutput = ((MTextArea*)pWidget);
	}

	if (m_pChattingOutput != NULL)
	{
		m_pChattingOutput->Clear();
	}
	return true;
}

void ZNotifyKills::Destroy()
{
	MWidget* pChatFrame = ZGetGameInterface()->GetIDLResource()->FindWidget("KillNotificationsFrame");
	//pChatFrame->Draw(false);
	pChatFrame->Hide();
	pChatFrame->SetVisible(false);
	pChatFrame->Enable(false);
	pChatFrame->Show(false);

	m_pChattingOutput = NULL;
}

void ZNotifyKills::Update()
{
	UpdateChattingBox();
}

void ZNotifyKills::UpdateChattingBox()
{
	if (m_pChattingOutput == NULL) return;

	if (m_pChattingOutput->GetLineCount() > 0)
	{
		unsigned long int nNowTime = timeGetTime();

#define CHAT_DELAY_TIME	3000
		if ((nNowTime - m_nLastChattingMsgTime) > CHAT_DELAY_TIME)
		{
			m_pChattingOutput->DeleteFirstLine();
			m_nLastChattingMsgTime = nNowTime;
		}
	}
}

void ZNotifyKills::OutputChatMsg(const char* szMsg)
{
	if (m_pChattingOutput == NULL) return;

	if (m_pChattingOutput->GetLineCount() == 0)
		for (int i = 0; i < (MAX_CHAT_OUTPUT_LINE - 1); i++) m_pChattingOutput->DeleteFirstLine();
	m_pChattingOutput->AddText(szMsg);

	ProcessChatMsg();
}

void ZNotifyKills::OutputChatMsg(MCOLOR color, const char* szMsg)
{
	if (m_pChattingOutput == NULL) return;

	if (m_pChattingOutput->GetLineCount() == 0)
		for (int i = 0; i < (MAX_CHAT_OUTPUT_LINE - 1); i++) m_pChattingOutput->DeleteFirstLine();
	m_pChattingOutput->AddText(szMsg, color);

	ProcessChatMsg();
}
void ZNotifyKills::ProcessChatMsg()
{
	while ((m_pChattingOutput->GetLineCount() > 9))
	{
		m_pChattingOutput->DeleteFirstLine();
	}


	if (m_pChattingOutput->GetLineCount() >= 1)
	{
		m_nLastChattingMsgTime = timeGetTime();
	}
}
void ZNotifyKills::OnDraw(MDrawContext* pDC)
{
	MWidget* pChatFrame = ZGetGameInterface()->GetIDLResource()->FindWidget("KillNotificationsFrame");
	MWidget* pChatArea = ZGetGameInterface()->GetIDLResource()->FindWidget("KillNotifications");
	pDC->SetColor(0xFF, 0xFF, 0xFF, 50);
	pChatArea->SetVisible(true);
	pChatArea->Enable(true);
	pChatFrame->SetVisible(true);
	pChatFrame->Enable(true);
	pChatFrame->Show(true);

}

void ZNotifyKills::SetFont(MFont* pFont)
{
	MFont* pFontFodase = MFontManager::Get("FONTa9b");
	ProcessChatMsg();
	m_pChattingOutput->SetFont(pFontFodase);
}


void ZNotifyKills::ShowOutput(bool bShow)
{
	if (m_pChattingOutput) m_pChattingOutput->Show(bShow);
	m_bShowOutput = bShow;
}
