#include "StdAfx.h"
#include "Buster.h"
#include "Player.h"

CBuster::CBuster(void)
:Mul(0.f)
{
}

CBuster::~CBuster(void)
{
	Release();
}
void CBuster::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"buster", (new CMyBitmap)->LoadBmp(L"../image/skill/buster.bmp")));
	m_pFrameKey = L"buster";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 2;
	m_tFrame.dwFrameSpd = 100;
	m_tFrame.dwFrameOld = GetTickCount();
	m_tInfo.iCX = 118;
	m_tInfo.iCY = 118;
	ReStartFrame = 0;
	m_iSpeed = 7;
	m_bIsRigth = CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight();
	DIeX =  CObjMgr::GetInstance()->GetObj(PLAYER)->GetRect().bottom;
	m_iAtk = 50;
	if(m_bIsRigth)
		m_tFrame.iScene = 1;
	else
		m_tFrame.iScene = 0;
	m_eRenderID = Render_skill
		;
}
int CBuster::Update()
{
	if(m_tRect.bottom >= DIeX)
		return 1;
	if(m_bIsRigth)
	{
		m_tInfo.iX += m_iSpeed;
		m_tInfo.iY += m_iSpeed;
	}
	else
	{
		m_tInfo.iX -= m_iSpeed;
		m_tInfo.iY += m_iSpeed;
	}
	CObj::SkillFrameMove();
	CObj::Update();
	return 0;
}
void CBuster::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	if(SkillStart)
	{
		TransparentBlt(hdc, m_tRect.left + g_iScrollX -50, m_tRect.top -70, 236, 236, 
			hmemDC, m_tFrame.iFrameStart * 118, m_tFrame.iScene * 118
			,118 , 118, RGB(255,0,255));
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())	
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
	}
}
void CBuster::Release()
{

}