#include "StdAfx.h"
#include "DGSelect.h"
#include "Mouse.h"
#include "MyButton.h"

CDGSelect::CDGSelect(void)
{
}

CDGSelect::~CDGSelect(void)
{
	Release();
}
void CDGSelect::Initialize()
{
	CBmpMgr::GetInstance()->LoadByScene(DGSel);	
	CObjMgr::GetInstance()->AddObject(new CMyButton(L"DGSelButton", 500, 300, 250, 160), BUTTON);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMouse>::CreateObj(), MOUSE);	
}
int CDGSelect::Update()
{
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}
void CDGSelect::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"DGSelMap"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::GetInstance()->GetObj(BUTTON)->Render(hDC);
	CObjMgr::GetInstance()->GetObj(MOUSE)->Render(hDC);
}
void CDGSelect::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(BUTTON);
	CObjMgr::GetInstance()->ReleaseObj(MOUSE);

}