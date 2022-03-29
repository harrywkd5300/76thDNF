#include "StdAfx.h"
#include "Maingame.h"
#include "player.h"
#include "Maps.h"

int g_iScrollX = 0;
int g_iScrollY = 0;

CMaingame::CMaingame(void)
{
}

CMaingame::~CMaingame(void)
{
	Release();
}
void CMaingame::initirize()
{
	CSoundMgr::GetInstance()->LoadSoundFile();
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"Back", (new CMyBitmap)->LoadBmp(L"../image/map/Back.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"BackBuffer", (new CMyBitmap)->LoadBmp(L"../image/map/BackBuffer.bmp")));

	m_hdc = GetDC(g_hWnd);

	CSceneMgr::GetInstance()->SetScene(Logo);
}
void CMaingame::Update()
{
	CSoundMgr::GetInstance()->UpdateSound();
	CKeyMgr::GetInstance()->KeyCheck();
	CSceneMgr::GetInstance()->Update();
}
void CMaingame::Render()
{
	HDC BackBuf = (CBmpMgr::GetInstance()->GetMapbit()[L"BackBuffer"])->GetMemDC();
	HDC MemDC = (CBmpMgr::GetInstance()->GetMapbit()[L"Back"])->GetMemDC();

	BitBlt(BackBuf, 0, 0, WINCX, WINCY, MemDC, 0, 0, SRCCOPY);
	CSceneMgr::GetInstance()->Render(BackBuf);

	BitBlt(m_hdc, 0, 0, WINCX, WINCY, BackBuf, 0, 0, SRCCOPY);

}
void CMaingame::Release()
{
	CSceneMgr::GetInstance()->DestroyInstance();
	CKeyMgr::GetInstance()->DestroyInstance();
	CBmpMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->DestroyInstance();
	ReleaseDC(g_hWnd, m_hdc);
}