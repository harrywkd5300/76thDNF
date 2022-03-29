#include "StdAfx.h"
#include "MaigicArrow.h"
#include "Player.h"

CMaigicArrow::CMaigicArrow(void)
{
}

CMaigicArrow::~CMaigicArrow(void)
{
	Release();
}
void CMaigicArrow::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"MagicArrow", (new CMyBitmap)->LoadBmp(L"../image/skill/MagicArrow.bmp")));
	m_pFrameKey = L"MagicArrow";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 80;
	m_tFrame.dwFrameOld = GetTickCount();
	m_iAtk = 10;
	if(m_bIsRigth)
	{
		m_tInfo.iX += 40;
	}
	else
	{
		m_tInfo.iX -= 40;
	}
	m_tInfo.iCX = 40;
	m_tInfo.iCY = 40;
	m_iSpeed = 20;
	m_eRenderID = Render_skill;
}
int CMaigicArrow::Update()
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
void CMaigicArrow::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	if(SkillStart)
	{
		TransparentBlt(hdc, m_tRect.left + g_iScrollX, m_tRect.top - 80, 36, 36, 
			hmemDC, m_tFrame.iFrameStart * 36, m_tFrame.iScene * 36
			,36 , 36, RGB(255,0,255));
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
	}
}
void CMaigicArrow::Release()
{

}