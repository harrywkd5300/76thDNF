#include "StdAfx.h"
#include "Thunder.h"
#include "Player.h"

CThunder::CThunder(void)
{

}
CThunder::~CThunder(void)
{
	Release();
}
void CThunder::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"thunder", (new CMyBitmap)->LoadBmp(L"../image/skill/thunder.bmp")));
	m_pFrameKey = L"thunder";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 7;
	m_tFrame.dwFrameSpd = 30;
	m_tFrame.dwFrameOld = GetTickCount();
	m_tInfo.iCX = 50;
	m_tInfo.iCY = 300;
	SkillOldTime = GetTickCount();
	SkillCUrTime = 0;
	m_iAtk = 5;
	m_eRenderID = Render_skill;
}
int CThunder::Update()
{
//#ifdef _DEBUG
//	system("cls");
//	cout << m_tInfo.iX << " , " << m_tInfo.iY << endl;
//#endif
	SkillCUrTime = GetTickCount();
	if(SkillOldTime + 5000 < SkillCUrTime)
		return 1;
	CObj::SkillFrameMove();
	CObj::Update();

	return 0;
}
void CThunder::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();
	if(SkillStart)
	{
		TransparentBlt(hdc, m_tRect.left + g_iScrollX - 50, m_tRect.top, 190, 306, 
			hmemDC, m_tFrame.iFrameStart * 190, m_tFrame.iScene * 306
			,190 , 306, RGB(255,0,255));
		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())	
			Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top, m_tRect.right + g_iScrollX, m_tRect.bottom);
	}
}
void CThunder::Release()
{

}