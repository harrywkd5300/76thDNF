#include "StdAfx.h"
#include "Obj.h"

CObj::CObj(void)
:m_bisDead(false), m_fz(0.f), m_bIsMove(true), m_bIsRigth(false), ReStartFrame(0), SkillStart(false)
,thunderBOOL(false), m_bIshit(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}

CObj::~CObj(void)
{
}

int CObj::Update()
{
	m_tRect.left   = m_tInfo.iX - m_tInfo.iCX / 2;
	m_tRect.top    = m_tInfo.iY - m_tInfo.iCY / 2;
	m_tRect.right  = m_tInfo.iX + m_tInfo.iCX / 2;
	m_tRect.bottom = m_tInfo.iY + m_tInfo.iCY / 2;
	return 0;
}

void CObj::FrameMove()
{
	if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
	{
		m_tFrame.dwFrameOld = GetTickCount();
		++m_tFrame.iFrameStart;
	}

	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
	{
		CObjMgr::GetInstance()->GetObj(PLAYER)->SetState(true);
		m_tFrame.iFrameStart = 0;
	}
}
void CObj::MonsterFrameMove()
{
	if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
	{
		m_tFrame.dwFrameOld = GetTickCount();
		++m_tFrame.iFrameStart;
	}
	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
	{
		m_tFrame.iFrameStart = ReStartFrame;
	}
}

void CObj::SkillFrameMove()
{
	if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
	{
		m_tFrame.dwFrameOld = GetTickCount();
		++m_tFrame.iFrameStart;
	}
	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
	{
		SkillStart = true;
		thunderBOOL = true;
		m_tFrame.iFrameStart = ReStartFrame;
	}
}
