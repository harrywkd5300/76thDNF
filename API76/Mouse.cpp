#include "StdAfx.h"
#include "Mouse.h"

CMouse::CMouse(void)
{
}

CMouse::~CMouse(void)
{
	Release();
}
void CMouse::initirize()
{
	m_tInfo.iCX = 32;
	m_tInfo.iCY = 32;
	m_dwTime = GetTickCount();
	m_dwClick = 500;
	m_eRenderID = Render_UI;
}
int CMouse::Update()
{
//#ifdef _DEBUG
//	system("cls");
//	cout << m_tInfo.iX << " , " << m_tInfo.iY << endl;
//#endif
	GetCursorPos(&m_ptMouse);
	ScreenToClient(g_hWnd, &m_ptMouse);

	m_tInfo.iX = m_ptMouse.x;
	m_tInfo.iY = m_ptMouse.y;

	m_ptAgoMouse.x = m_ptMouse.x;
	m_ptAgoMouse.y = m_ptMouse.y;

	CObj::Update();
	return 0;
}
void CMouse::Render(HDC hDC)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(L"Mouse"))->GetMemDC();
	TransparentBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, 
		hmemDC, m_tFrame.iFrameStart * m_tInfo.iCX, m_tFrame.iScene * m_tInfo.iCY
		, m_tInfo.iCX , m_tInfo.iCY, RGB(255,0,255));;
	ShowCursor(false);
}
void CMouse::Release()
{

}