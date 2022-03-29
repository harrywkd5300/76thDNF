#include "StdAfx.h"
#include "BossHpBar.h"
#include "Boss.h"

CBossHpBar::CBossHpBar(void)
{
}

CBossHpBar::~CBossHpBar(void)
{
	Release();
}
void CBossHpBar::initirize()
{
	if(m_pFrameKey == L"BossHpBar")
	{
		m_tInfo.iCX = 637; 
		m_tInfo.iCY = 36;
		m_tFrame.iScene = 0;
	}
	else if(m_pFrameKey == L"BossHp")
	{
		m_tInfo.iCX = 600; 
		m_tInfo.iCY = 26;
		m_tFrame.iScene = 0;
	}
	else if(m_pFrameKey == L"boss_face")
	{
		m_tInfo.iCX = 24; 
		m_tInfo.iCY = 24;
		m_tFrame.iScene = 0;
	}
}
int CBossHpBar::Update()
{
	CObj::Update();
	return 0;
}
void CBossHpBar::Render(HDC hdc)
{
	OBJITER iter_begin = CObjMgr::GetInstance()->GetList(MONSTER).begin();
	OBJITER iter_end = CObjMgr::GetInstance()->GetList(MONSTER).end();

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(m_pFrameKey != L"BossHp")
		{
			HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();
			TransparentBlt(hdc, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hmemDC, 0, 0
				, m_tInfo.iCX , m_tInfo.iCY, RGB(255,0,255));
		}
		else
		{
			HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();
			TransparentBlt(hdc, m_tRect.left , m_tRect.top, (*iter_begin)->GetIHp() , m_tInfo.iCY, hmemDC, 0, m_tFrame.iScene * m_tInfo.iCY
				, (*iter_begin)->GetIHp() , m_tInfo.iCY, RGB(255,0,255));
		}
	}

}
void CBossHpBar::Release()
{

}