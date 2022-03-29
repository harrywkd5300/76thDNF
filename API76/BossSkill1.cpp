#include "StdAfx.h"
#include "BossSkill1.h"
#include "Player.h"
#include "Boss.h"

CBossSkill1::CBossSkill1(void)
{
}

CBossSkill1::~CBossSkill1(void)
{
	Release();
}
void CBossSkill1::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"lukeeffect1", (new CMyBitmap)->LoadBmp(L"../image/effect/lukeeffect1.bmp")));
	m_pFrameKey = L"lukeeffect1";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 9;
	m_tInfo.iCX = 60;
	m_tInfo.iCY = 60;
	m_tFrame.dwFrameSpd = 120;
	m_tFrame.dwFrameOld = GetTickCount();
	m_eRenderID = Render_skill;
	EndSkill = false;
	m_iAtk = 50;
}
int CBossSkill1::Update()
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
void CBossSkill1::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	TransparentBlt(hdc, m_tRect.left + g_iScrollX - 50, m_tRect.top - 100, 150, 200, 
		hmemDC, m_tFrame.iFrameStart * 464, m_tFrame.iScene * 600
		,464 , 600, RGB(0,0,0));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())	
		Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
}
void CBossSkill1::Release()
{

}