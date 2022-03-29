#include "StdAfx.h"
#include "TileMgr.h"

IMPLEMENT_SINGLETON(CTileMgr)
CTileMgr::CTileMgr(void)
{
}

CTileMgr::~CTileMgr(void)
{
	Relaese();
}
void CTileMgr::AddTile(CObj* pTile)
{
	m_vecTile.push_back(pTile);
}
void CTileMgr::Update()
{
	MaxSize = CSceneMgr::GetInstance()->GetMaxWidth();
	//MaxSize = 2;

	int iCullX = (-g_iScrollX) / TILECX;
	int iCullY = (-g_iScrollY) / TILECY;

	int iCullEndX = (WINCX * MaxSize) / TILECX;
	int iCullEndY = WINCY / TILECY;

	for(int i = iCullY; i < iCullY + iCullEndY + 2; ++i)
	{
		for(int j = iCullX; j < iCullX + iCullEndX + 2; ++j)
		{
			int iIndex = j + (TILEX * i * MaxSize);

			if(0 > iIndex || m_vecTile.size() <= (size_t)iIndex)
				continue;

			m_vecTile[iIndex]->Update();
		}
	}
	Scroll();
}
void CTileMgr::Render(HDC hDC)
{
	int iCullX = (-g_iScrollX) / TILECX;
	int iCullY = (-g_iScrollY) / TILECY;

	int iCullEndX = (WINCX * MaxSize) / TILECX;
	int iCullEndY = WINCY / TILECY;

	for(int i = iCullY; i < iCullY + iCullEndY + 2; ++i)
	{
		for(int j = iCullX; j < iCullX + iCullEndX + 2; ++j)
		{
			int iIndex = j + (TILEX * MaxSize * i);

			if(0 > iIndex || m_vecTile.size() <= (size_t)iIndex)
				continue;

			m_vecTile[iIndex]->Render(hDC);
		}
	}
}
void CTileMgr::Relaese()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), safeDelete<CObj*>);
}

void CTileMgr::LoadData(TCHAR* pTilename)
{
	// WINAPI에서 제공하는 파일 개방 함수.
	HANDLE hFile = CreateFile(pTilename, GENERIC_READ, 0, NULL, OPEN_EXISTING
		, FILE_ATTRIBUTE_NORMAL, NULL);

	// 파일 개방 실패시 NULL이 아닌 INVALID_HANDLE_VALUE값을 반환.
	if(INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, pTilename, L"Load Failed", MB_OK);
		return;
	}

	DWORD dwByte = 0;

	INFO tInfo = {};
	int iDrawID = 0;
	int iOption = 0;

	while(true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, NULL);
		ReadFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		ReadFile(hFile, &iOption, sizeof(int), &dwByte, NULL);

		if(0 == dwByte)
			break;

		CObj* pTile = new CTile;
		pTile->SetInfo(tInfo);
		dynamic_cast<CTile*>(pTile)->SetOption(iDrawID, iOption);

		m_vecTile.push_back(pTile);
	}

	CloseHandle(hFile);
}

void CTileMgr::SaveData()
{
	// WINAPI에서 제공하는 파일 개방 함수.
	HANDLE hFile = CreateFile(L"../Data/reshipon2.dat", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS
		, FILE_ATTRIBUTE_NORMAL, NULL);

	// 파일 개방 실패시 NULL이 아닌 INVALID_HANDLE_VALUE값을 반환.
	if(INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/Tile.dat", L"Save Failed", MB_OK);
		return;
	}

	DWORD dwByte = 0;

	INFO tInfo = {};
	int iDrawID = 0;
	int iOption = 0;

	for(size_t i = 0; i < m_vecTile.size(); ++i)
	{
		CTile* pTile = dynamic_cast<CTile*>(m_vecTile[i]);

		tInfo = pTile->GetInfo();
		iDrawID = pTile->GetDrawID();
		iOption = pTile->GetOption();

		WriteFile(hFile, &tInfo, sizeof(INFO), &dwByte, NULL);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		WriteFile(hFile, &iOption, sizeof(int), &dwByte, NULL);
	}	

	CloseHandle(hFile);
}
void CTileMgr::Scroll()
{
	if(0 < g_iScrollX)
		g_iScrollX = 0;

	if(WINCX - (TILECX * TILEX) * MaxSize > g_iScrollX)
		g_iScrollX = WINCX - (TILECX * TILEX) * MaxSize;
}