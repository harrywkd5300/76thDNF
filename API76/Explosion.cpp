#include "StdAfx.h"
#include "Explosion.h"
#include "Player.h"

CExplosion::CExplosion(void)
{
}

CExplosion::~CExplosion(void)
{
	Release();
}
void CExplosion::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"explosion", (new CMyBitmap)->LoadBmp(L"../image/skill/explosion.bmp")));
	m_pFrameKey = L"explosion";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 6;
	m_tFrame.dwFrameSpd = 50;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameOld = GetTickCount();
	m_tInfo.iCX = 709;
	m_tInfo.iCY = 709;
	m_eRenderID = Render_skill;
	m_iAtk = 50;
}
int CExplosion::Update()
{
	if(m_tFrame.iScene == 5 && m_tFrame.iFrameStart==6)
		return 1;
	ExplosionFrame();
	CObj::Update();
	return 0;
}
void CExplosion::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	if(SkillStart)
	{
		TransparentBlt(hdc, m_tRect.left + g_iScrollX + 50, m_tRect.top - 50 , 600 ,600, 
			hmemDC, m_tFrame.iFrameStart * m_tInfo.iCX, m_tFrame.iScene * m_tInfo.iCY
			,m_tInfo.iCX , m_tInfo.iCY, RGB(0,0,0));
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
	}
}
void CExplosion::Release()
{
}

void CExplosion::ExplosionFrame()
{
	if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
	{
		m_tFrame.dwFrameOld = GetTickCount();
		++m_tFrame.iFrameStart;
	}
	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
	{
		SkillStart = true;
		m_tFrame.iFrameStart = 0;
		++m_tFrame.iScene; 
	}
}