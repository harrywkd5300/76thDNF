#include "StdAfx.h"
#include "Logo.h"

CLogo::CLogo(void)
{
}

CLogo::~CLogo(void)
{
	Release();
}
void CLogo::Initialize()
{
	CBmpMgr::GetInstance()->LoadByScene(Logo);
	// MCI (Media Control Interface)
	// ����� �� ���� �ֺ� ��ġ�� �����ϴ� �������� ����� �������α׷��� �����ϴ� �������̽���.
	m_hVideo = MCIWndCreate(g_hWnd, NULL, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD
		, L"../Video/Logo.wmv");
	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);
	MCIWndPlay(m_hVideo); // �̵�� ���
}
int CLogo::Update()
{
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();
	if(KEYPRESS(dwKey, KEY_RETURN))
	{
		CSceneMgr::GetInstance()->SetScene(Menu);
		return 0;		
	}
	return 0;
}
void CLogo::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Menu"))->GetMemDC();

	BitBlt(hDC, 0, 0, WINCX, WINCY
		, hMemDC, 0, 0, SRCCOPY);
}
void CLogo::Release()
{
	MCIWndClose(m_hVideo);
}