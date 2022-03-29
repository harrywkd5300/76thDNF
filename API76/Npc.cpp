#include "StdAfx.h"
#include "Npc.h"
#include "Player.h"
#include "Mouse.h"
#include "Stage.h"

CNpc::CNpc(void)
:bOpenShop(false)
{
}

CNpc::~CNpc(void)
{
	Release();
}
void CNpc::initirize()
{
	srand(unsigned(time(NULL)));
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 9;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 200;
	m_tFrame.dwFrameOld = GetTickCount();

	dTalkTime = GetTickCount();
}
int CNpc::Update()
{
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();
	CObj::FrameMove();


	if(dTalkTime + 4000 < GetTickCount())
	{
		if(rand()%2 == 1)
			CSoundMgr::GetInstance()->PlaySound(L"seria_amb_02.ogg", CSoundMgr::Channel_Eff);
		else
			CSoundMgr::GetInstance()->PlaySound(L"seria_amb_01.ogg", CSoundMgr::Channel_Eff);

		dTalkTime = GetTickCount();
	}
	CObj::Update();

	POINT pt = CMouse::GetMouse();
	if(PtInRect(&m_tRect, pt))
	{
		if(KEYPRESS(dwKey, KEY_LBUTTON))
		{
			if(!bOpenShop)
			{
				if(!lstrcmp(m_pFrameKey, L"Seria"))
				{
					bOpenShop = true;
					CUimgr::GetInstance()->SetUi(shop, 500, 400);
					return 2;
				}
			}
		}
	}



	return 0;
}
void CNpc::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();
	TransparentBlt(hdc, m_tRect.left + g_iScrollX, m_tRect.top, 70, 130, hmemDC, m_tFrame.iFrameStart * m_tInfo.iCX, m_tFrame.iScene * m_tInfo.iCY
		, m_tInfo.iCX , m_tInfo.iCY, RGB(255,0,255));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		Rectangle(hdc, m_tRect.left+ g_iScrollX, m_tRect.top, m_tRect.right+ g_iScrollX, m_tRect.bottom);
}
void CNpc::Release()
{

}