#include "StdAfx.h"
#include "NightHallow.h"
#include "Player.h"

CNightHallow::CNightHallow(void)
{
}

CNightHallow::~CNightHallow(void)
{
	Release();
}

void CNightHallow::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"nighthallow", (new CMyBitmap)->LoadBmp(L"../image/skill/nighthallow.bmp")));
	m_pFrameKey = L"nighthallow";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 15;
	m_tFrame.dwFrameSpd = 200;
	m_tFrame.dwFrameOld = GetTickCount();
	m_tInfo.iCX = 350;
	m_tInfo.iCY = 300;
	SkillEnd = false;
	ReStartFrame = 0;
	m_iAtk = 3;
	m_eRenderID = Render_Obj;
	playerFrameKey = CObjMgr::GetInstance()->GetObj(PLAYER)->GetFrameKey();
}
int CNightHallow::Update()
{
	CObj::SkillFrameMove();
	
	if(m_tFrame.iFrameStart == m_tFrame.iFrameEnd)
		return 1;

	CObj::Update();
	return 0;
}
void CNightHallow::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	if(!SkillStart)
	{
		if(playerFrameKey==L"player_L")
		{
			TransparentBlt(hdc, m_tRect.left + g_iScrollX, m_tRect.top, 400, 350, 
				hmemDC, m_tFrame.iFrameStart * 350, m_tFrame.iScene * 300
				,350 , 300, RGB(255,0,255));
		}
		else
		{
			TransparentBlt(hdc, m_tRect.left + g_iScrollX, m_tRect.top, 400, 350, 
				hmemDC, m_tFrame.iFrameStart * 350, m_tFrame.iScene * 300
				,350 , 300, RGB(255,0,255));
		}
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
	}
}
void CNightHallow::Release()
{

}