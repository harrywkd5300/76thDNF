#include "StdAfx.h"
#include "Monster1.h"
#include "Player.h"
#include "HpBar.h"

CMonster1::CMonster1(void)
{
}

CMonster1::~CMonster1(void)
{
	Release();
}
void CMonster1::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"MonsterHpBar", (new CMyBitmap)->LoadBmp(L"../image/etc/MonsterHpBar.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"monster1_face", (new CMyBitmap)->LoadBmp(L"../image/etc/monster1_face.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"MonsterHp", (new CMyBitmap)->LoadBmp(L"../image/etc/MonsterHp.bmp")));
	OpenMonster = 0;
	OpenMonster = true;
	m_bIshit = false;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 9;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 80;
	m_tFrame.dwFrameOld = GetTickCount();
	m_pFrameKey = L"monster1_R";
	m_tInfo.iCX = 40;
	m_tInfo.iCY = 40;
	m_iSpeed = 5;
	m_eRenderID = Render_Obj;
	iWidth = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX - m_tInfo.iX;
	iLength = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY - m_tInfo.iY;
	m_iHp = 597;
	m_iMaxHp = m_iHp;
	iHpPer = 0; 
	m_iAtk = 20;
	m_bIsHitTime = false;
	CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar>::CreateObj(350, 70, L"MonsterHpBar"), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar>::CreateObj(365, 75, L"MonsterHp"), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar>::CreateObj(50, 68, L"monster1_face"), UI);
}
int CMonster1::Update()
{
//#ifdef _DEBUG
//	system("cls");
//	cout << m_iHp << endl;
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
		m_pFrameKey = L"monster1_L";
	else
		m_pFrameKey = L"monster1_R";

	if(OpenMonster)
	{
		if(iLine <= 300)
		{
			if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
			{
				m_tFrame.dwFrameOld = GetTickCount();
				++m_tFrame.iFrameStart;
			}
			if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			{
				m_tFrame.iFrameStart = 0;
				OpenMonster = false;
				m_tFrame.iScene = 1;
				m_tFrame.iFrameEnd = 11;
			}
		}
	}
	else
	{
		if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
		{
			m_tFrame.dwFrameOld = GetTickCount();
			++m_tFrame.iFrameStart;
			if(m_tFrame.iScene != 2)
			{
				m_tInfo.iX += int(cosf(fAngle) * m_iSpeed);
				m_tInfo.iY -= int(sinf(fAngle) * m_iSpeed);
			}
		}

		if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		{
			m_tFrame.iFrameStart = 0;
			if(iLine <= 50)
			{
				m_tFrame.iScene = 2;
				m_tFrame.iFrameEnd = 10;
			}
			else
			{
				m_tFrame.iScene = 1;
				m_tFrame.iFrameEnd = 11;
			}
		}
	}
	CObj::Update();
	return 0;
}
void CMonster1::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();
	TransparentBlt(hdc, m_tRect.left + g_iScrollX -30, m_tRect.top - 80, 125, 103, hmemDC, m_tFrame.iFrameStart * 125, m_tFrame.iScene * 103
		, 125 , 103, RGB(255,0,255));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		Rectangle(hdc, m_tRect.left+ g_iScrollX, m_tRect.top, m_tRect.right+ g_iScrollX, m_tRect.bottom);
}
void CMonster1::Release()
{

}