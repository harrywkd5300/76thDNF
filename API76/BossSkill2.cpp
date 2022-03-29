#include "StdAfx.h"
#include "Player.h"
#include "BossSkill2.h"

CBossSkill2::CBossSkill2(void)
{
}

CBossSkill2::~CBossSkill2(void)
{
	Release();
}
void CBossSkill2::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"lukeeffect5", (new CMyBitmap)->LoadBmp(L"../image/effect/lukeeffect5.bmp")));
	m_pFrameKey = L"lukeeffect5";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 16;
	m_tInfo.iCX = 50;
	m_tInfo.iCY = 300;
	m_tFrame.dwFrameSpd = 120;
	m_tFrame.dwFrameOld = GetTickCount();
	m_eRenderID = Render_skill;
	EndSkill = false;
	m_iAtk = 5;
	//m_tInfo.iY -= 120;
}
int CBossSkill2::Update()
{
	if(EndSkill)
		return 1;

	if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
	{
		m_tFrame.dwFrameOld = GetTickCount();
		++m_tFrame.iFrameStart;
	}
	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
	{
		EndSkill = true;
	}

	CObj::Update();
	return 0;
}
void CBossSkill2::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	TransparentBlt(hdc, m_tRect.left - 50 + g_iScrollX, m_tRect.top -130, 100, 500, 
		hmemDC, m_tFrame.iFrameStart * 290, m_tFrame.iScene * 934
		,290 , 934, RGB(0,0,0));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())	
		Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);

}
void CBossSkill2::Release()
{

}