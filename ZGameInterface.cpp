//find
//ZGameInterface::ZGameInterface(const char* szName, MWidget* pParent, MListener* pListener) : ZInterface(szName,pParent,pListener)
//{
//add inside {
  LoadWeapons();
	LoadBlank();

//add new
#include <vector>
#include <iostream>
struct Emoji
{
	char A, B, C;
	char name[20];
	Emoji(char a, char b, char c, char* Name)
	{
		A = a;
		B = b;
		C = c;
		memset(Name, 0, 20);
		strcpy(name, Name);
	}
	Emoji(char a, char b, char* Name)
	{
		A = a;
		B = b;
		C = ' ';
		memset(Name, 0, 20);
		strcpy(name, Name);
	}

};

typedef std::vector<Emoji*> Emojis;

Emojis          m_Emoji;

typedef std::vector<Emoji*> Weapons;

Weapons          m_Weapons;

typedef std::vector<Emoji*> Blank;

Blank          m_Blank;

void ZGameInterface::LoadEmojis()
{
	m_Emoji.push_back(new Emoji(':', 'D', "happy.png"));
	m_Emoji.push_back(new Emoji(':', '*', "kiss.png"));
	m_Emoji.push_back(new Emoji(';', '/', "cry.png"));
	m_Emoji.push_back(new Emoji(';', '(', "crymore.png"));
	m_Emoji.push_back(new Emoji(':', 'S', "wut.png"));
	m_Emoji.push_back(new Emoji(':', 'P', "lick.png"));
	m_Emoji.push_back(new Emoji(':', '/', "angry.png"));
	m_Emoji.push_back(new Emoji(':', '(', "sad.png"));
	m_Emoji.push_back(new Emoji('<', '3', "love.png"));
	m_Emoji.push_back(new Emoji(';', ')', "wink.png"));
	m_Emoji.push_back(new Emoji(':', '|', "bru.png"));
	m_Emoji.push_back(new Emoji(':', ')', "smile.png"));
	m_Emoji.push_back(new Emoji(':', 'O', "sorprise.png"));
}

void ZGameInterface::LoadWeapons()
{
	m_Weapons.push_back(new Emoji('\xbd', 'Q', "sword.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'W', "suicidio.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'E', "dagger.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'R', "dualdagger.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'T', "dualpistol.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'Y', "singlepistol.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'U', "smg.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'I', "smgx2.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'O', "kodachis.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'P', "rifle.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'A', "rocket.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'S', "shotgun.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'D', "sniper.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'F', "lmg.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'G', "mina.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'H', "grenade.png"));
	m_Weapons.push_back(new Emoji('\xbd', 'J', "trap.png"));
}

void ZGameInterface::LoadBlank()
{
	m_Blank.push_back(new Emoji('\xbd', 'K', "blank.png"));
}

unsigned long int MMColorSetKillFeed[] =
{
	0xFF808080,0xFFFF0000,0xFF00FF00,0xFF0000FF,0xFFFFFF00,0xFF800000,
	0xFF008000,0xFF000080,0xFF808000,0xFFFFFFFF,0xFF00FFFF,0xFF388E8E,
	0xFF7D9EC0,0xFFC67171,0xFFF5F5DC,0xFFA9A9A9,0xFFEECFA1,0xFFEE7600,
	0xFFCDC0B0,0xFF000000,0xFF8B2323,0xFFCDAA7D,0xFF458B00,0xFFD2691E,
	0xFF6495ED,0xFFFFB90F,0xFF8B008B,0xFF2F4F4F,0xFF7CFC00,0xFFEEE685,
	0xFF8470FF,0xFFFFE4E1,0xFFEE4000,0xFF8E8E38,0xFFFFA54F,0xFFFF6347,
	0xFF8B8B00,0xFFF5F5F5,0xFF00E5EE,0xFF708090,0xFFF4A460,0xFF03FE4A,
	0xFFFFE4E0,0xFFEE4001,0xFF8E8E3E,
};

int MDrawContext::TextMultiLine(MRECT& r, const char* szText, int nLineGap, bool bAutoNextLine, int nIndentation, int nSkipLine, MPOINT* pPositions)
{
	bool bColorSupport = true;

	MBeginProfile(99, "MDrawContext::TextMultiLine");

	int nLine = 0;
	MFont* pFont = GetFont();

	int nLength = strlen(szText);
	int xRight = 0;
	int ArmasxRight = 0;

	int y = r.y;
	char* szCurrent = (char*)szText;
	MPOINT* pCurrentPos = pPositions;
	do {
			MCOLOR prevColor = GetColor();
			SetColor(0, 0, 0, 255 * ((int)Z_ETC_CHATOPACITY / 100.f));
			//SetColor(0xFF000000);
			char* szCurrentCpy = GetPureText(szCurrent);
			FillRectangle(r.x, y, pFont->GetWidth(szCurrentCpy), pFont->GetHeight());
			pFont->GetWidth(szCurrentCpy), 200.f * 1.1 / 800.f * (float)MGetWorkspaceWidth();
			SetColor(prevColor);	
		int nX = nLine == 0 ? 0 : nIndentation;

		int nOriginalCharCount = MMGetNextLinePos(pFont, szCurrent, r.w - nX, bAutoNextLine, true);

		if (nSkipLine <= nLine)
		{
			int nCharCount = min(nOriginalCharCount, MAX_CHAR_A_LINE);
			char buffer[256];
			if (bColorSupport) {

				// Text
#define FLUSHPOS(_Pos)		if(pCurrentPos!=NULL){	\
								for(int i=0; buffer[i]!=NULL; i++){	\
									pCurrentPos[i+szCurrent-szText].x = _Pos+pFont->GetWidth(buffer, i);	\
									pCurrentPos[i+szCurrent-szText].y = y;	\
								}	\
							}

#define FLUSH				if(buffer[0]) { Text(r.x+nLastX+xRight, y, buffer); FLUSHPOS(r.x+nLastX); nLastX=nX; buffer[0]=0;pcurbuf=buffer; }

//Armas
#define ARMASFLUSHPOS(_Pos)		if(pCurrentPos!=NULL){	\
								for(int i=0; buffer[i]!=NULL; i++){	\
									pCurrentPos[i+szCurrent-szText].x = _Pos+pFont->GetWidth(buffer, i);	\
									pCurrentPos[i+szCurrent-szText].y = y;	\
																																}	\
																}

#define ARMASFLUSH				if(buffer[0]) { Text(r.x+nLastX+ArmasxRight, y, buffer); ARMASFLUSHPOS(r.x+nLastX); nLastX=nX; buffer[0]=0;pcurbuf=buffer; }

				int nLastX = nX;

				buffer[0] = 0;
				char* pcurbuf = buffer;
				for (int i = 0; i < nCharCount; i++)
				{

					unsigned char c = szCurrent[i], cc = szCurrent[i + 1];

					if (c == '^' && ('0' <= cc) && (cc <= 'Z'))
					{

						FLUSH;
						SetColor(MCOLOR(MMColorSetKillFeed[cc - '0']));
						i++;
						continue;
					}

					for (Emojis::iterator emoji = m_Emoji.begin(); emoji != m_Emoji.end(); emoji++) {

						if (szCurrent[i - 1] == ' ' && szCurrent[i] == (*emoji)->A && szCurrent[i + 1] == (*emoji)->B) {
							FLUSH;
							SetBitmap(MBitmapManager::Get((*emoji)->name));
							int nSize = 30;
							Draw((r.x + nX) + xRight, y, nSize, nSize);
							c = ' ';
							cc = ' ';
							szCurrent[i] = ' ';
							szCurrent[i + 1] = ' ';
							xRight += 10;
						}
					}
					for (Emojis::iterator emoji = m_Blank.begin(); emoji != m_Blank.end(); emoji++) {

						if (szCurrent[i] == (*emoji)->A && szCurrent[i + 1] == (*emoji)->B) {
							ARMASFLUSH;
							SetBitmap(MBitmapManager::Get((*emoji)->name));
							Draw((r.x + nX) + ArmasxRight, y, 1, 1);
							c = ' ';
							cc = ' ';
							szCurrent[i] = ' ';
							szCurrent[i + 1] = ' ';
							y += 30;
						}
					}

					for (Emojis::iterator emoji = m_Weapons.begin(); emoji != m_Weapons.end(); emoji++) {

						if (szCurrent[i] == (*emoji)->A && szCurrent[i + 1] == (*emoji)->B) {
							ARMASFLUSH;
							SetBitmap(MBitmapManager::Get((*emoji)->name));
							int nSize = 20;
							Draw((r.x + nX) + ArmasxRight, y, 70, 20);
							//Draw((r.x + nX) + ArmasxRight, y, nSize, nSize);
							c = ' ';
							cc = ' ';
							szCurrent[i] = ' ';
							szCurrent[i + 1] = ' ';
							ArmasxRight += 20;
						}
					}
					if (ZGetGame() && ZGetConfiguration()->GetEtc()->bEmote)
					{

						unsigned char cminus = szCurrent[i - 1], c = szCurrent[i], cc = szCurrent[i + 1], ccc = szCurrent[i + 2], cccc = szCurrent[i + 3];

						if (c == '^' && ('0' <= cc) && (cc <= 'Z'))
						{
							xRight = 0;
							FLUSH;
							i++;
							continue;
						}

						else if (c == ':' && (cc == 'D' || cc == 'd'))
						{
							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("1.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
							else if ((cminus == ' ') && (c == ':') && (cc == 'D' || cc == 'd') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("1.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
						}


						else if (c == ':' && (')' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("3.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ':') && (cc == ')') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("3.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
						}
						else if (c == ':' && ('(' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("4.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ':') && (cc == '(') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("4.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}
						else if (c == ':' && ('P' == cc || 'p' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("5.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ':') && ('P' == cc || 'p' == cc) && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("5.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}
						else if (c == ':' && ('/' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("6.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ':') && (cc == '/') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("6.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}
						else if (c == '<' && ('3' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("7.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == '<') && (cc == '3') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("7.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}
						else if (c == '^' && ('_' == cc) && ('^' == ccc))
						{
							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("8.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								ccc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								szCurrent[i + 2] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
							else if ((cminus == ' ') && (c == '^') && (cc == '_') && (ccc == '^') && (cccc == ' ' || !cccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("8.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								ccc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								szCurrent[i + 2] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
						}
						else if ((c == 'O' || c == 'o') && (':' == cc) && (')' == ccc))
						{
							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("9.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								ccc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								szCurrent[i + 2] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
							else if ((cminus == ' ') && (c == 'O' || c == 'o') && (cc == ':') && (ccc == ')') && (cccc == ' ' || !cccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("9.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								ccc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								szCurrent[i + 2] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
						}
						else if (c == ':' && ('@' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("10.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ':') && (cc == '@') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("10.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}

						else if (c == ';' && ('(' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("2.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ';') && (cc == '(') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("2.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}

						else if (c == ';' && (')' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("12.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ';') && (cc == ')') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("12.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}
						else if (c == ':' && ('O' == cc || 'o' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("13.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ':') && ('O' == cc || 'o' == cc) && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("13.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;


							}
						}
						else if (c == '-' && ('_' == cc) && ('-' == ccc))
						{
							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("14.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								ccc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								szCurrent[i + 2] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
							else if ((cminus == ' ') && (c == '-') && (cc == '_') && (ccc == '-') && (cccc == ' ' || !cccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("14.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								ccc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								szCurrent[i + 2] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;
							}
						}
						else if (c == ':' && ('*' == cc))
						{

							if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("15.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
							else if ((cminus == ' ') && (c == ':') && (cc == '*') && (ccc == ' ' || !ccc)) {
								FLUSH;
								SetBitmap(MBitmapManager::Get("15.png"));
								Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
								c = ' ';
								cc = ' ';
								szCurrent[i] = ' ';
								szCurrent[i + 1] = ' ';
								xRight = (float)RGetScreenWidth() / (float)1920 * 6;

							}
						}
						else if ((cminus == ' ') && (c == ':') && (cc == 'v') && (ccc == ' ' || !ccc)) {
							FLUSH;
							SetBitmap(MBitmapManager::Get("16.png"));
							Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
							c = ' ';
							cc = ' ';
							szCurrent[i] = ' ';
							szCurrent[i + 1] = ' ';
							xRight = (float)RGetScreenWidth() / (float)1920 * 6;

						}
					}
					else if (c == ':' && ('7' == cc))
					{

						if (strlen(szText) == strlen(ZGetMyInfo()->GetCharName()) + 5) {
							FLUSH;
							SetBitmap(MBitmapManager::Get("17.png"));
							Draw((r.x + nX), y, (float)RGetScreenWidth() / (float)800 * 11, (float)RGetScreenWidth() / (float)800 * 11);
							c = ' ';
							cc = ' ';
							szCurrent[i] = ' ';
							szCurrent[i + 1] = ' ';
							xRight = (float)RGetScreenWidth() / (float)1920 * 6;

						}
						else if (c == ':' && ('M' == cc || 'm' == cc))
						{

						}
					}
					int w;

					*(pcurbuf++) = c;
					if (c > 127 && i < nCharCount) {
						*(pcurbuf++) = cc;
						w = pFont->GetWidth(szCurrent + i, 2);
						i++;
					}
					else w = pFont->GetWidth(szCurrent + i, 1);

					*pcurbuf = 0;

					nX += w;
				}

				FLUSH;
			}
			else
			{
				strncpy(buffer, szCurrent, nCharCount);
				buffer[nCharCount] = 0;
				Text(r.x + nX, y, buffer);
				FLUSHPOS(r.x + nX);
			}
			y += pFont->GetHeight() + nLineGap;
		}

		szCurrent += nOriginalCharCount;
		nLine++;
		if (y >= r.y + r.h) break;
	} while (szCurrent < szText + nLength);

	MEndProfile(99);
	return nLine - nSkipLine;
}
