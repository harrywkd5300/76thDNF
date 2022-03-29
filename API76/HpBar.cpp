#include "StdAfx.h"
#include "HpBar.h"
#include "Monster1.h"

CHpBar::CHpBar(void)
{
}

CHpBar::~CHpBar(void)
{
	Release();
}
void CHpBar::initirize()
{
	iHpPer = 0;
	m_FirstHp = false;
	m_IsDraw = false;


	if(m_pFrameKey == L"MonsterHpBar")
	{
		m_tInfo.iCX = 629; 
		m_tInfo.iCY = 32;
		m_tFrame.iScene = 0;
	}
	else if(m_pFrameKey == L"MonsterHp")
	{
		m_tInfo.iCX = 597; 
		m_tInfo.iCY = 9;
		m_tFrame.iScene = 0;
	}
	else if(m_pFrameKey == L"monster1_face")
	{
		m_tInfo.iCX = 24; 
		m_tInfo.iCY = 24;
		m_tFrame.iScene = 0;
	}
	else if(m_pFrameKey == L"monster2_face")
	{
		m_tInfo.iCX = 24; 
		m_tInfo.iCY = 24;
		m_tFrame.iScene = 0;
	}
}
int CHpBar::Update()
{
	//OBJITER iter_begin = CObjMgr::GetInstance()->GetList(MONSTER).begin();
	//OBJITER iter_end = CObjMgr::GetInstance()->GetList(MONSTER).end();

	//for( ; iter_begin != iter_end ; ++iter_begin)
	//{
	//	int MonsterHp = (*iter_begin)->m_iMaxHp;
	//	if(MonsterHp == (*iter_begin)->GetIHp())
	//		continue;
	//	(*iter_begin)->iHpPer = m_tInfo.iCX ;
	//}
	CObj::Update();
	return 0;
}
void CHpBar::Render(HDC hdc)
{
	OBJITER iter_begin = CObjMgr::GetInstance()->GetList(MONSTER).begin();
	OBJITER iter_end = CObjMgr::GetInstance()->GetList(MONSTER).end();

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if((*iter_begin)->m_bIshit)
		{
			if(m_pFrameKey != L"MonsterHp")
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

}
void CHpBar::Release()
{

}