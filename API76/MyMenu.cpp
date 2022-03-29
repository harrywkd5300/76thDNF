#include "StdAfx.h"
#include "MyMenu.h"
#include "MyButton.h"

CMyMenu::CMyMenu(void)
{
}

CMyMenu::~CMyMenu(void)
{
	Release();
}
void CMyMenu::Initialize()
{
	CBmpMgr::GetInstance()->LoadByScene(Menu);

	CObjMgr::GetInstance()->AddObject(new CMyButton(L"Start", 300, 600, 116, 45), BUTTON);	
	CObjMgr::GetInstance()->AddObject(new CMyButton(L"Edit", 600, 600, 116, 45), BUTTON);	
	CObjMgr::GetInstance()->AddObject(new CMyButton(L"Exit", 900, 600, 116, 45), BUTTON);
}
int CMyMenu::Update()
{
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}
void CMyMenu::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Menu"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CMyMenu::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(BUTTON);
}