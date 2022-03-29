#include "StdAfx.h"
#include "MyButton.h"
#include "Mouse.h"


CMyButton::CMyButton(void)
{
}

CMyButton::CMyButton(TCHAR* pFrameKey, int iX, int iY, int iCX, int iCY)
: m_pFrameKey(pFrameKey), m_iFrame(0)
{
	m_tInfo.iX = iX;
	m_tInfo.iY = iY;
	m_tInfo.iCX = iCX;
	m_tInfo.iCY = iCY;
}

CMyButton::~CMyButton(void)
{
	Release();
}

void CMyButton::initirize()
{
}

int CMyButton::Update()
{
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();

	CObj::Update();

	POINT pt = CMouse::GetMouse();

	// PtInRect: 마우스 커서 좌표가 임의의 사각형 안에 들어오면 true를 반환해준다.
	if(PtInRect(&m_tRect, pt))
	{
		if(KEYPRESS(dwKey, KEY_LBUTTON))
		{
			if(!lstrcmp(m_pFrameKey, L"Start"))
			{
				CSceneMgr::GetInstance()->SetScene(Stage);
				return 2;
			}
			else if(!lstrcmp(m_pFrameKey, L"Edit"))
			{
				CSceneMgr::GetInstance()->SetScene(Edit);
				return 2;
			}
			else if(!lstrcmp(m_pFrameKey, L"Exit"))
			{
				DestroyWindow(g_hWnd);
				return 2;
			}
			else if(!lstrcmp(m_pFrameKey, L"DGSelButton"))
			{
				CSceneMgr::GetInstance()->SetScene(DG1);
				return 2;
			}
		}

		m_iFrame = 1;
	}
	else
		m_iFrame = 0;


	return 0;
}

void CMyButton::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.iCX, m_tInfo.iCY
		, hMemDC, m_iFrame * m_tInfo.iCX, 0
		, m_tInfo.iCX, m_tInfo.iCY, RGB(255, 0, 255));	
}

void CMyButton::Release()
{
}
