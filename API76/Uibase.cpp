#include "StdAfx.h"
#include "Uibase.h"

CUibase::CUibase(void)
{
}

CUibase::~CUibase(void)
{
	Release();
}
void CUibase::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"mainhud", (new CMyBitmap)->LoadBmp(L"../image/UI/mainhud.bmp")));
	m_pFrameKey = L"mainhud";
	m_tInfo.iX = 600;
	m_tInfo.iY = WINCY+100;
	m_tInfo.iCX = 1200;
	m_tInfo.iCY = 91;
	m_eRenderID = Render_Obj;
}
int CUibase::Update()
{
	CObj::Update();
	return 0;
}
void CUibase::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();

	TransparentBlt(hdc, m_tRect.left , m_tRect.top - 146, m_tInfo.iCX, m_tInfo.iCY, 
		hmemDC, 0, 0, 1200 , 91, RGB(0,0,0));
}
void CUibase::Release()
{

}