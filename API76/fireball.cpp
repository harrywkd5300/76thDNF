#include "StdAfx.h"
#include "fireball.h"
#include "Player.h"

fireball::fireball(void)
{
}

fireball::~fireball(void)
{
	Release();
}
void fireball::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"fireball_L", (new CMyBitmap)->LoadBmp(L"../image/skill/fireball_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"fireball_R", (new CMyBitmap)->LoadBmp(L"../image/skill/fireball_R.bmp")));
	m_pFrameKey = L"fireball";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 8;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 80;
	ReStartFrame = 5;
	m_tFrame.dwFrameOld = GetTickCount();
	m_iAtk = 20;
	if(m_bIsRigth)
	{
		m_tInfo.iX += 30;
	}
	else
	{
		m_tInfo.iX -= 30;
	}
	m_tInfo.iCX = 81;
	m_tInfo.iCY = 114;
	m_iSpeed = 15;
	iCX = m_tInfo.iCX;
	iCY = m_tInfo.iCY;

	m_tInfo.iCX = 40;
	m_tInfo.iCY = 40;
	m_eRenderID = Render_skill;
}
int fireball::Update()
{
	if(m_bisDead)
		return 1;
	if(SkillStart)
	{
		if(m_bIsRigth)
			m_tInfo.iX += m_iSpeed;
		else 
			m_tInfo.iX -= m_iSpeed;
	}
	CObj::SkillFrameMove();
	CObj::Update();

	return 0;
}
void fireball::Render(HDC hdc)
{
	HDC hmemDC;
	int iBit = 0;
	if(m_bIsRigth)
	{
		hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[L"fireball_R"])->GetMemDC();
		iBit = -40;
	}
	else
	{
		hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[L"fireball_L"])->GetMemDC();
		iBit = -5;
	}

	if(SkillStart)
	{
		TransparentBlt(hdc, m_tRect.left + iBit+ g_iScrollX , m_tRect.top - 100, iCX, iCY, 
			hmemDC, m_tFrame.iFrameStart * iCX, m_tFrame.iScene * iCY
			, iCX ,iCY, RGB(255,0,255));
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right+ g_iScrollX, m_tRect.bottom);
	}
}
void fireball::Release()
{
}