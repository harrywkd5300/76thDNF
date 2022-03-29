#include "StdAfx.h"
#include "AuarShield.h"
#include "Player.h"

CAuarShield::CAuarShield(void)
{
}

CAuarShield::~CAuarShield(void)
{
	Release();
}
void CAuarShield::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"aurashield", (new CMyBitmap)->LoadBmp(L"../image/skill/aurashield.bmp")));
	m_pFrameKey = L"aurashield";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 80;
	m_tFrame.dwFrameOld = GetTickCount();
	m_tInfo.iCX = 40;
	m_tInfo.iCY = 40;
	m_eRenderID = Render_Obj;
	m_iHp += 100;
}
int CAuarShield::Update()
{
	float PJumpY = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetJumpY();
	m_tInfo.iX = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX;
	m_tInfo.iY = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY + 15;
	CObj::SkillFrameMove();
	CObj::Update();

	return 0;
}
void CAuarShield::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	if(SkillStart)
	{
		float PJumpY = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetJumpY();
		TransparentBlt(hdc, m_tRect.left + g_iScrollX - 35, m_tRect.top  - 120 - (int)PJumpY, 123,116, 
			hmemDC, m_tFrame.iFrameStart * 123, m_tFrame.iScene * 116
			,123 ,116, RGB(255,0,255));
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())		
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
	}
}
void CAuarShield::Release()
{

}