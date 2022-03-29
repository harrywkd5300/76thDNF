#include "StdAfx.h"
#include "Monster2.h"
#include "Player.h"
#include "HpBar.h"

CMonster2::CMonster2(void)
{
}

CMonster2::~CMonster2(void)
{
	Release();
}
void CMonster2::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"MonsterHpBar", (new CMyBitmap)->LoadBmp(L"../image/etc/MonsterHpBar.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"monster2_face", (new CMyBitmap)->LoadBmp(L"../image/etc/monster2_face.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"MonsterHp", (new CMyBitmap)->LoadBmp(L"../image/etc/MonsterHp.bmp")));
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 80;
	m_tFrame.dwFrameOld = GetTickCount();
	m_pFrameKey = L"monster2_L";
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;
	m_iHitcount = 0;
	m_iSpeed = 5;
	m_eRenderID = Render_Obj;
	CollBox = 0;
	dSkillTime = GetTickCount();
	m_iHp = 597;
	m_iAtk = 20;
	dHitTime = GetTickCount();
	CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar>::CreateObj(350, 70, L"MonsterHpBar"), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar>::CreateObj(365, 75, L"MonsterHp"), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar>::CreateObj(50, 68, L"monster2_face"), UI);
}
int CMonster2::Update()
{	
//#ifdef _DEBUG
//	system("cls");
//	cout << m_tInfo.iX << endl;
//#endif
	if(m_bisDead)
		return 1;
	iWidth = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX - m_tInfo.iX;
	iLength = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY - m_tInfo.iY; 
	float iLine = sqrtf(float(iWidth*iWidth + iLength*iLength));
	float fAngle = acosf(iWidth / iLine);
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY > m_tInfo.iY)
		fAngle *= -1.f;
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX > m_tInfo.iX)
		m_pFrameKey = L"monster2_R";
	else
		m_pFrameKey = L"monster2_L";

	if(m_bIshit)
	{
		m_tFrame.iFrameStart = 0;
		m_tFrame.iScene = 3;
		m_tFrame.iFrameEnd = 5;
		m_tFrame.dwFrameSpd = 50;
		m_tFrame.dwFrameOld = GetTickCount();
		if(dHitTime + 2000 < GetTickCount())
		{
			m_bIshit = false;
			dHitTime = GetTickCount();
		}

	}
	else
	{
		if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
		{
			m_tFrame.dwFrameOld = GetTickCount();
			++m_tFrame.iFrameStart;
			if(m_tFrame.iScene != 0 || m_tFrame.iScene != 3)
			{
				m_tInfo.iX += int(cosf(fAngle) * m_iSpeed);
				m_tInfo.iY -= int(sinf(fAngle) * m_iSpeed);
			}
		}

		if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		{
			m_tFrame.iFrameStart = 0;
			if(iLine <= 500)
			{
				m_iSpeed = 5; 
				m_tFrame.iScene = 2;
				m_tFrame.iFrameStart = 0;
				m_tFrame.iFrameEnd = 7;
			}
			if(dSkillTime + 3000 < GetTickCount())
			{
				if(iLine <= 200)
				{
					m_tFrame.iScene = 1;
					m_tFrame.iFrameEnd = 8;
					m_iSpeed = 10;
					dSkillTime = GetTickCount();
				}
			}
		}
	}

	CObj::MonsterFrameMove();
	CObj::Update();
	return 0;
}
void CMonster2::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();
	TransparentBlt(hdc, m_tRect.left+g_iScrollX - 180, m_tRect.top -180, 456, 284, hmemDC, m_tFrame.iFrameStart * 456, m_tFrame.iScene * 284
		, 456 , 284, RGB(255,0,255));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		Rectangle(hdc, m_tRect.left+g_iScrollX, m_tRect.top, m_tRect.right+g_iScrollX, m_tRect.bottom);

}
void CMonster2::Release()
{

}