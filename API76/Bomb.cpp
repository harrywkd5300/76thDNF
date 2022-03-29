#include "StdAfx.h"
#include "Player.h"
#include "Bomb.h"

CBomb::CBomb(void)
{
}

CBomb::~CBomb(void)
{
	Release();
}

void CBomb::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"bomb", (new CMyBitmap)->LoadBmp(L"../image/effect/bomb.bmp")));
	m_pFrameKey = L"bomb";
	m_tInfo.iCX = 50;
	m_tInfo.iCY = 50;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;
	m_tFrame.dwFrameSpd = 100;
	m_tFrame.dwFrameOld = GetTickCount();
	m_eRenderID = Render_Effect;
	if(m_bIsRigth)
		m_tFrame.iScene = 0;
	else
		m_tFrame.iScene = 1;

}
int CBomb::Update()
{
	if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
	{
		m_tFrame.dwFrameOld = GetTickCount();
		++m_tFrame.iFrameStart;
	}
	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		return 1;
	CObj::Update();
	return 0;
}
void CBomb::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	TransparentBlt(hdc, m_tRect.left + g_iScrollX, m_tRect.top - 100, iXSize, iYSize, 
		hmemDC, m_tFrame.iFrameStart * 259, m_tFrame.iScene * 235
		,259 ,235, RGB(255,0,255));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())	
		Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
}
void CBomb::Release()
{

}