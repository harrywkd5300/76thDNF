#include "StdAfx.h"
#include "Firewall.h"
#include "Player.h"

CFirewall::CFirewall(void)
{
}
CFirewall::~CFirewall(void)
{
	Release();
}
void CFirewall::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"firewall", (new CMyBitmap)->LoadBmp(L"../image/skill/firewall.bmp")));
	m_pFrameKey = L"firewall";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 12;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 30;
	m_tFrame.dwFrameOld = GetTickCount();
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;
	SkillOldTime = GetTickCount();
	SkillCUrTime = 0;
	m_iSpeed = 10;
	m_eRenderID = Render_skill;
	ReStartFrame = 2;
	m_iAtk = 5;
}
int CFirewall::Update()
{
	SkillCUrTime = GetTickCount();
	if(SkillOldTime + 5000 < SkillCUrTime)
		return 1;
	CObj::SkillFrameMove();
	CObj::Update();

	return 0;
}
void CFirewall::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	if(SkillStart)
	{
		TransparentBlt(hdc, m_tRect.left + g_iScrollX - 80, m_tRect.top - 140, 246, 270, 
			hmemDC, m_tFrame.iFrameStart * 246, m_tFrame.iScene * 270
			,246 , 270, RGB(255,0,255));
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
	}
}
void CFirewall::Release()
{

}

