#include "StdAfx.h"
#include "Boss.h"
#include "Player.h"
#include "BossHpBar.h"

CBoss::CBoss(void)
{
}

CBoss::~CBoss(void)
{
}
void CBoss::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"BossHp", (new CMyBitmap)->LoadBmp(L"../image/etc/BossHp.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"BossHpBar", (new CMyBitmap)->LoadBmp(L"../image/etc/BossHpBar.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"boss_face", (new CMyBitmap)->LoadBmp(L"../image/etc/boss_face.bmp")));
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 9;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();
	m_pFrameKey = L"BossOn";
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;
	m_iSpeed = 10;
	m_eRenderID = Render_Obj;
	OpenMonster = true;
	dSkillTime = GetTickCount();
	iMaxSize = 0;
	iMaxHeight = 0;
	iSkill1Count = 0;
	dDieTime = GetTickCount();
	m_iHp = 600;
	m_iAtk = 40;
	CObjMgr::GetInstance()->AddObject(CAbstract<CBossHpBar>::CreateObj(350, 70, L"BossHpBar"), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CBossHpBar>::CreateObj(365, 70, L"BossHp"), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CBossHpBar>::CreateObj(50, 68, L"boss_face"), UI);
}
int CBoss::Update()
{
	if(m_iHp <= 0)
	{
		CSoundMgr::GetInstance()->PlaySound(L"luke_die.ogg", CSoundMgr::Channel_Mon);
		if(dDieTime + 3000 < GetTickCount())
		{
			if(m_bisDead)
				return 1;
		}
	}
	srand(unsigned(time(NULL)));
	iWidth = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX - m_tInfo.iX;
	iLength = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY - m_tInfo.iY; 
	float iLine = sqrtf(float(iWidth*iWidth + iLength*iLength));
	float fAngle = acosf(iWidth / iLine);
	if(CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY > m_tInfo.iY)
		fAngle *= -1.f;
	if(OpenMonster)
	{
		if(iLine <= 500)
		{
			if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
			{
				m_tFrame.dwFrameOld = GetTickCount();
				++m_tFrame.iFrameStart;
			}
			if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			{
				m_tFrame.iFrameStart = 0;
				++m_tFrame.iScene;
				if(m_tFrame.iScene > 3)
				{
					OpenMonster = false;
					m_tFrame.iScene = 4;
					m_pFrameKey = L"Boss_L";
					m_tFrame.iFrameEnd = 7;
					m_tFrame.dwFrameSpd = 200;
				}
			}
		}
	}
	else
	{
		if(CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX > m_tInfo.iX)
			m_pFrameKey = L"Boss_R";
		else
			m_pFrameKey = L"Boss_L";

		if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
		{
			m_tFrame.dwFrameOld = GetTickCount();
			++m_tFrame.iFrameStart;
			if(m_tFrame.iScene == 4)
			{
				m_tInfo.iX += int(cosf(fAngle) * m_iSpeed);
				m_tInfo.iY -= int(sinf(fAngle) * m_iSpeed);
			}
		}
		if(m_tFrame.iScene ==4)
		{
			if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			{
				m_tFrame.iFrameStart = 0;
				if(dSkillTime + 5000 < GetTickCount())
				{
					if(rand()%2==0)
					{
						m_tFrame.iScene = 0;
						m_tFrame.iFrameEnd = 7;
						m_tFrame.dwFrameSpd = 200;
						CSoundMgr::GetInstance()->PlaySound(L"luke_skill_01.ogg", CSoundMgr::Channel_Mon);
					}
					else
					{
						m_tFrame.iScene = 3;
						m_tFrame.iFrameEnd = 2;
						m_tFrame.dwFrameSpd = 200;
						CSoundMgr::GetInstance()->PlaySound(L"luke_skill_02_1.ogg", CSoundMgr::Channel_Mon);
					}
				}
			}
		}
		else if(m_tFrame.iScene >= 0 && m_tFrame.iScene < 3)
		{
			if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			{
				if(iSkill1Count != 5)
				{
					iSkill1Count += 1;
					int UserX = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX;
					int UserY = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY;
					CSkillMgr::GetInstance()->SetSkill(BossSkill1, UserX, UserY);
				}
				else
					iSkill1Count =0;

				++m_tFrame.iScene;
				m_tFrame.iFrameStart = 0;
				if(m_tFrame.iScene == 3)
				{
					m_tFrame.iScene = 4;
					m_tFrame.iFrameEnd = 7;
					dSkillTime = GetTickCount();
				}
			}
		}
		else if(m_tFrame.iScene ==3)
		{
			if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			{
				if(iSkill1Count != 3)
				{
					iSkill1Count += 1;
					int UserX = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iX;
					int UserY = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().iY;
					CSkillMgr::GetInstance()->SetSkill(BossSkill2, UserX, UserY - 120);
				}
				else if(iSkill1Count == 3)
				{
					iSkill1Count = 0;
					m_tFrame.iScene = 4;
					m_tFrame.iFrameEnd = 7;
					dSkillTime = GetTickCount();
					m_tFrame.dwFrameSpd = 150;
				}
			}
		}
	}
	CObj::Update();
	return 0;
}
void CBoss::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();
	TransparentBlt(hdc, m_tRect.left + g_iScrollX - 50, m_tRect.top - 200, 255, 301 , hmemDC, m_tFrame.iFrameStart * 255, m_tFrame.iScene * 301
		, 255 , 301, RGB(255,0,255));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		Rectangle(hdc, m_tRect.left+ g_iScrollX, m_tRect.top, m_tRect.right+ g_iScrollX, m_tRect.bottom);

}
void CBoss::Release()
{

}