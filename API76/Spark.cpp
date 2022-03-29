#include "StdAfx.h"
#include "Spark.h"
#include "Player.h"

CSpark::CSpark(void)
{
}

CSpark::~CSpark(void)
{
	Release();
}
void CSpark::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"spark", (new CMyBitmap)->LoadBmp(L"../image/effect/spark.bmp")));
	m_pFrameKey = L"spark";
	m_tInfo.iCX = 50;
	m_tInfo.iCY = 50;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;
	m_tFrame.dwFrameSpd = 100;
	m_tFrame.dwFrameOld = GetTickCount();
	m_eRenderID = Render_Effect;
	sparkTime = GetTickCount();
}
int CSpark::Update()
{
	if(m_bisDead)
		return 1;
	if(sparkTime + 3000 < GetTickCount())
	{
		++m_tFrame.iFrameStart;
	}
	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
	{
		return 1;
	}
	sparkTime = GetTickCount();
	CObj::Update();
	return 0;
}
void CSpark::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	TransparentBlt(hdc, m_tRect.left + g_iScrollX, m_tRect.top - 100, 150, 150, 
		hmemDC, m_tFrame.iFrameStart * 150, m_tFrame.iScene * 150
		,150 ,150, RGB(0,0,0));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())	
		Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
}
void CSpark::Release()
{

}