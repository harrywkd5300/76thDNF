#include "StdAfx.h"
#include "StateHp.h"

CStateHp::CStateHp(void)
{
}

CStateHp::~CStateHp(void)
{
}
void CStateHp::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"hpbar", (new CMyBitmap)->LoadBmp(L"../image/UI/HP.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"mpbar", (new CMyBitmap)->LoadBmp(L"../image/UI/MP.bmp")));

	m_tInfo.iCX = 100;
	m_tInfo.iCY = 60;
	m_eRenderID = Render_UI;
}
int CStateHp::Update()
{
	CObj::Update();
	return 0;
}
void CStateHp::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();

	TransparentBlt(hdc, m_tRect.left , m_tRect.top - 250, m_tInfo.iCX, m_tInfo.iCY, 
		hmemDC, 0, 0, m_tInfo.iCX , m_tInfo.iCY, RGB(0,0,0));
}
void CStateHp::Release()
{

}