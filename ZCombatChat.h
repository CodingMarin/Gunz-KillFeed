//add
class ZNotifyKills
{
private:
protected:
	ZIDLResource* m_pIDLResource;
	unsigned long int	m_nLastChattingMsgTime;
	bool				m_bShowOutput;

	void UpdateChattingBox();
	void ProcessChatMsg();
public:
	MTextArea* m_pChattingOutput;


	int nLines;

	ZNotifyKills();
	virtual ~ZNotifyKills();
	bool Create(char* szOutputTxtarea, bool bUsePlayerList);
	void Destroy();

	void Update();
	void OutputChatMsg(const char* szMsg);
	void OutputChatMsg(MCOLOR color, const char* szMsg);

	void OnDraw(MDrawContext* pDC);
	void SetFont(MFont* pFont);

	void ShowOutput(bool bShow);
};
