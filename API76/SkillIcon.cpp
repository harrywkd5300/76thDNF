#include "StdAfx.h"
#include "SkillIcon.h"
#include "Player.h"

CSkillIcon::CSkillIcon(void)
{
}

CSkillIcon::~CSkillIcon(void)
{
	Release();
}
void CSkillIcon::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"skill1", (new CMyBitmap)->LoadBmp(L"../image/skill/skill1.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"skill2", (new CMyBitmap)->LoadBmp(L"../image/skill/skill2.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"skill3", (new CMyBitmap)->LoadBmp(L"../image/skill/skill3.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"skill4", (new CMyBitmap)->LoadBmp(L"../image/skill/skill4.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"skill5", (new CMyBitmap)->LoadBmp(L"../image/skill/skill5.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"skill6", (new CMyBitmap)->LoadBmp(L"../image/skill/skill6.bmp")));
	m_tInfo.iCX = 28;
	m_tInfo.iCY = 28;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iScene = 0;
	m_tFrame.iFrameEnd = 2;
	m_eRenderID = Render_Obj;
	Skill1 = GetTickCount();
}
int CSkillIcon::Update()
{
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->bSkillCoolTime1)
	{
		if(m_pFrameKey == L"skill1")
			m_tFrame.iFrameStart = 1;
	}
	else
	{
		if(m_pFrameKey == L"skill1")
			m_tFrame.iFrameStart = 0;
	}
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->bSkillCoolTime2)
	{
		if(m_pFrameKey == L"skill2")
			m_tFrame.iFrameStart = 1;
	}
	else
	{
		if(m_pFrameKey == L"skill2")
			m_tFrame.iFrameStart = 0;
	}
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->bSkillCoolTime3)
	{
		if(m_pFrameKey == L"skill3")
			m_tFrame.iFrameStart = 1;
	}
	else
	{
		if(m_pFrameKey == L"skill3")
			m_tFrame.iFrameStart = 0;
	}
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->bSkillCoolTime4)
	{
		if(m_pFrameKey == L"skill4")
			m_tFrame.iFrameStart = 1;
	}
	else
	{
		if(m_pFrameKey == L"skill4")
			m_tFrame.iFrameStart = 0;
	}
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->bSkillCoolTime5)
	{
		if(m_pFrameKey == L"skill5")
			m_tFrame.iFrameStart = 1;
	}
	else
	{
		if(m_pFrameKey == L"skill5")
			m_tFrame.iFrameStart = 0;
	}
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->bSkillCoolTime6)
	{
		if(m_pFrameKey == L"skill6")
			m_tFrame.iFrameStart = 1;
	}
	else
	{
		if(m_pFrameKey == L"skill6")
			m_tFrame.iFrameStart = 0;
	}
	CObj::Update();
	return 0;
}
void CSkillIcon::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	TransparentBlt(hdc, m_tRect.left , m_tRect.top - 178,  37, 28, 
		hmemDC, m_tFrame.iFrameStart * 28, m_tFrame.iScene * 28
		, m_tInfo.iCX ,  m_tInfo.iCY, RGB(255,0,255));
}
void CSkillIcon::Release()
{

}