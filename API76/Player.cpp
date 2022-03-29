#include "StdAfx.h"
#include "Player.h"
#include "StateHp.h"
#include "Inventory.h"
#include "SkillIcon.h"


CPlayer::CPlayer(void)
:m_fJumpPow(50.f), m_fJumpAcc(0.f), m_bIsJump(false), m_fJumpY(0.f), m_bTileView(false)
,FirstCreate(false)
{
}

CPlayer::~CPlayer(void)
{
	Release();
}
void CPlayer::initirize()
{	
	m_vInven.reserve(55);
	m_vEquipItem.reserve(3);
	m_pFrameKey = L"player_L";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();
	m_iHitcount = 0;
	m_bInven = false;

	m_eCurState = Stand;
	m_ePreState = m_eCurState;
	m_tInfo.iCX = 40;
	m_tInfo.iCY = 40;
	m_iSpeed = 3;
	m_dwTime = 0;
	m_dwClick = 100;
	m_eRenderID = Render_Obj;
	if(!FirstCreate)
	{
		m_iHp = 800;
		FirstCreate = true;
		bSkillCoolTime1 = false;
		bSkillCoolTime2 = false;
		bSkillCoolTime3 = false;
		bSkillCoolTime4 = false;
		bSkillCoolTime5 = false;
		bSkillCoolTime6 = false;
		CObjMgr::GetInstance()->AddObject(CAbstract<CStateHp>::CreateObj(62, 1003, L"hpbar"), UI);
		CObjMgr::GetInstance()->AddObject(CAbstract<CStateHp>::CreateObj(1140, 1003, L"mpbar"), UI);
		CObjMgr::GetInstance()->AddObject(CAbstract<CSkillIcon>::CreateObj(824, WINCY+150, L"skill1"), ICON);
		CObjMgr::GetInstance()->AddObject(CAbstract<CSkillIcon>::CreateObj(869, WINCY+150, L"skill2"), ICON);
		CObjMgr::GetInstance()->AddObject(CAbstract<CSkillIcon>::CreateObj(914, WINCY+150, L"skill3"), ICON);
		CObjMgr::GetInstance()->AddObject(CAbstract<CSkillIcon>::CreateObj(959, WINCY+150, L"skill4"), ICON);
		CObjMgr::GetInstance()->AddObject(CAbstract<CSkillIcon>::CreateObj(1004, WINCY+150, L"skill5"), ICON);
		CObjMgr::GetInstance()->AddObject(CAbstract<CSkillIcon>::CreateObj(1049, WINCY+150, L"skill6"), ICON);
	}
}
int CPlayer::Update()
{
//#ifdef _DEBUG
//	system("cls");
//	cout << m_vInven.size() << endl;
//#endif
	DWORD dwCurTime = GetTickCount();
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();

	if(m_bIsMove)
	{
		if(KEYPRESS(dwKey, O))
		{
			bSkillCoolTime6 = false;
			vector<CObj*>::iterator iter_begin = CTileMgr::GetInstance()->GetVecTile()->begin();
			vector<CObj*>::iterator iter_end = CTileMgr::GetInstance()->GetVecTile()->end();
			for( ; iter_begin != iter_end ; ++iter_begin)
			{
				if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID()==1)
				{
					dynamic_cast<CTile*>(*iter_begin)->SetOption(2, 1);
				}
			}
		}
		if(KEYPRESS(dwKey, I))
		{
			if(!m_bInven)
			{
				CObjMgr::GetInstance()->AddObject(CAbstract<CInventory>::CreateObj(850, 400), INVEN);
				m_bInven = true;
			}
		}
		if(KEYPRESS(dwKey, C))
		{
			m_eCurState = Jump;
			m_bIsJump = true;
			m_bIsMove = false;
			CSoundMgr::GetInstance()->PlaySound(L"wz_jump.ogg", CSoundMgr::Channel_Eff);
		}
		else if(KEYPRESS(dwKey, X))
		{
			m_eCurState = Attack;
			m_bIsMove = false;
			CSkillMgr::GetInstance()->SetSkill(Arrow, m_tInfo.iX, m_tInfo.iY);
			CSoundMgr::GetInstance()->PlaySound(L"wz_atk_01.ogg", CSoundMgr::Channel_Eff);
		}
		else if(KEYPRESS(dwKey, A))
		{
			if(!bSkillCoolTime1)
			{
				Skill1 = GetTickCount();
				bSkillCoolTime1 = true;
				m_eCurState = Casting;
				m_bIsMove = false;
				CSkillMgr::GetInstance()->SetSkill(Fireball, m_tInfo.iX, m_tInfo.iY);
				CSoundMgr::GetInstance()->PlaySound(L"wz_lanternfire.ogg", CSoundMgr::Channel_Eff);
			}
		}
		else if(KEYPRESS(dwKey, S))
		{
			if(!bSkillCoolTime2)
			{
				Skill2 = GetTickCount();
				bSkillCoolTime2 = true;
				m_eCurState = Casting;
				m_bIsMove = false;
				CSkillMgr::GetInstance()->SetSkill(Buster, m_tInfo.iX , m_tInfo.iY-400);
				CSoundMgr::GetInstance()->PlaySound(L"cr_meteo_01.ogg", CSoundMgr::Channel_Eff);
			}
		}
		else if(KEYPRESS(dwKey, D))
		{
			if(!bSkillCoolTime4)
			{
				Skill4 = GetTickCount();
				bSkillCoolTime4 = true;
				m_eCurState = Casting;
				m_bIsMove = false;
				if(m_pFrameKey == L"player_R")
					CSkillMgr::GetInstance()->SetSkill(night, m_tInfo.iX + 300 , m_tInfo.iY - 100);
				else
					CSkillMgr::GetInstance()->SetSkill(night, m_tInfo.iX - 300 , m_tInfo.iY - 100);
				CSoundMgr::GetInstance()->PlaySound(L"wz_nighth_02.ogg", CSoundMgr::Channel_Eff);
			}
		}
		else if(KEYPRESS(dwKey, Q))
		{
			m_eCurState = Casting2;
			m_bIsMove = false;
			CSkillMgr::GetInstance()->SetSkill(Shield, m_tInfo.iX , m_tInfo.iY);
			CSoundMgr::GetInstance()->PlaySound(L"wz_shield.ogg", CSoundMgr::Channel_Eff);
		}
		else if(KEYPRESS(dwKey, W))
		{
			if(!bSkillCoolTime5)
			{
				Skill5 = GetTickCount();
				bSkillCoolTime5 = true;
				m_eCurState = Casting2;
				m_bIsMove = false;
				OBJITER iter_begin = CObjMgr::GetInstance()->GetList(MONSTER).begin();
				OBJITER iter_end = CObjMgr::GetInstance()->GetList(MONSTER).end();
				for( ; iter_begin != iter_end ; ++iter_begin)
				{
					if(m_tInfo.iX + 400 > (*iter_begin)->GetInfo().iX || m_tInfo.iX - 400 < (*iter_begin)->GetInfo().iX )
					{
						CSkillMgr::GetInstance()->SetSkill(Firewall, (*iter_begin)->GetInfo().iX , (*iter_begin)->GetInfo().iY);
						CSoundMgr::GetInstance()->PlaySound(L"fire.ogg", CSoundMgr::Channel_Eff);
					}
				}
			}
		}
		else if(KEYPRESS(dwKey, F))
		{
			if(!bSkillCoolTime3)
			{
				Skill3 = GetTickCount();
				bSkillCoolTime3 = true;
				m_eCurState = Casting2;
				m_bIsMove = false;
				OBJITER iter_begin = CObjMgr::GetInstance()->GetList(MONSTER).begin();
				OBJITER iter_end = CObjMgr::GetInstance()->GetList(MONSTER).end();
				for( ; iter_begin != iter_end ; ++iter_begin)
				{
					if(m_tInfo.iX + 400 > (*iter_begin)->GetInfo().iX || m_tInfo.iX - 400 < (*iter_begin)->GetInfo().iX )
					{
						CSkillMgr::GetInstance()->SetSkill(thunder, (*iter_begin)->GetInfo().iX , (*iter_begin)->GetInfo().iY - 150);
						CSoundMgr::GetInstance()->PlaySound(L"wz_thunderc_02.ogg", CSoundMgr::Channel_Eff);
					}
				}
			}
		}
		else if(KEYPRESS(dwKey, R))
		{
			if(!bSkillCoolTime6)
			{
				Skill6 = GetTickCount();
				bSkillCoolTime6 = true;
				m_eCurState = Casting3;
				m_bIsMove = false;
				CSkillMgr::GetInstance()->SetSkill(Explosion, m_tInfo.iX , m_tInfo.iY-300);
				CSoundMgr::GetInstance()->PlaySound(L"wz_quasar_explosion_ready.ogg", CSoundMgr::Channel_Eff);
			}
		}
		else if(KEYPRESS(dwKey, KEY_LEFT))
		{
			m_iSpeed = 5;
			m_bIsRigth = false;
			if(KEYPRESS(dwKey, KEY_UP))
			{
				m_tInfo.iX -= m_iSpeed;
				m_tInfo.iY -= m_iSpeed;
				m_pFrameKey = L"player_L";
				m_eCurState = Walk;
			}
			else if(KEYPRESS(dwKey, KEY_DOWN))
			{	
				m_tInfo.iX -= m_iSpeed;		
				m_tInfo.iY += m_iSpeed;
				m_pFrameKey = L"player_L";
				m_eCurState = Walk;
			}
			else
			{
				m_tInfo.iX -= m_iSpeed;
				m_pFrameKey = L"player_L";
				m_eCurState = Walk;
			}
			if(KEYPRESS(dwKey, Z))
			{
				m_iSpeed = 8;
				m_tInfo.iX -= m_iSpeed ;
				m_pFrameKey = L"player_L";
				m_eCurState = Dash;
			}
			else if(KEYPRESS(dwKey, V))
			{
				m_bIsMove = false;
				m_pFrameKey = L"player_L";
				m_eCurState = DashAttack;
				CSoundMgr::GetInstance()->PlaySound(L"wz_dash_fall.ogg", CSoundMgr::Channel_Eff);
			}	
		}
		else if(KEYPRESS(dwKey, KEY_RIGHT))
		{
			m_iSpeed = 5;
			m_bIsRigth = true;
			if(KEYPRESS(dwKey, KEY_UP))
			{	
				m_tInfo.iX += m_iSpeed;		
				m_tInfo.iY -= m_iSpeed;	
				m_pFrameKey = L"player_R";
				m_eCurState = Walk;
			}
			else if(KEYPRESS(dwKey, KEY_DOWN))
			{	
				m_tInfo.iX += m_iSpeed;		
				m_tInfo.iY += m_iSpeed;
				m_pFrameKey = L"player_R";
				m_eCurState = Walk;
			}
			else
			{
				m_tInfo.iX += m_iSpeed;	
				m_pFrameKey = L"player_R";
				m_eCurState = Walk;
			}
			if(KEYPRESS(dwKey, Z))
			{
				m_iSpeed = 8;
				m_tInfo.iX += m_iSpeed;
				m_pFrameKey = L"player_R";
				m_eCurState = Dash;
			}
			else if(KEYPRESS(dwKey, V))
			{
				m_bIsMove = false;
				m_pFrameKey = L"player_R";
				m_eCurState = DashAttack;
				CSoundMgr::GetInstance()->PlaySound(L"wz_dash_fall.ogg", CSoundMgr::Channel_Eff);
			}
		}
		else if(KEYPRESS(dwKey, KEY_UP))
		{
			m_tInfo.iY -= m_iSpeed;
			m_eCurState = Walk;
		}
		else if(KEYPRESS(dwKey, KEY_DOWN))
		{
			m_tInfo.iY += m_iSpeed;
			m_eCurState = Walk;
		}
		else
		{
			m_eCurState = Stand;
		}
	}

	if(m_eCurState == DashAttack)
	{
		if(m_pFrameKey ==L"player_R")
		{
			m_tInfo.iX += m_iSpeed;
		}
		else
		{
			m_tInfo.iX -= m_iSpeed;
		}
	}
	static bool tileIn = FALSE;

	if(KEYPRESS(dwKey, P))
	{
		if(tileIn == FALSE)
		{
			if(m_bTileView)
				m_bTileView = false;
			else
				m_bTileView = true;
			tileIn = TRUE;
			vector<CObj*>::iterator iter_begin = CTileMgr::GetInstance()->GetVecTile()->begin();
			vector<CObj*>::iterator iter_end = CTileMgr::GetInstance()->GetVecTile()->end();
			for( ; iter_begin != iter_end ; ++iter_begin)
			{
				if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID()==2)
				{
					dynamic_cast<CTile*>(*iter_begin)->SetOption(1, 1);
				}
			}
		}
	}
	else
	{
		tileIn = FALSE;
	}

	if(m_bIshit)
	{
		++m_iHitcount;
		if(m_iHitcount==20)
		{
			m_bIshit = false;
			m_iHitcount = 0;
		}
		else if(m_iHitcount <= 10)
		{
			m_eCurState = Hit;
		}
	}
	if(bSkillCoolTime1)
	{
		if(Skill1 + 2000 < GetTickCount())
		{
			Skill1 = GetTickCount();
			bSkillCoolTime1 = false;
			m_bIsMove = true;
		}
	}
	if(bSkillCoolTime2)
	{
		if(Skill2 + 3000 < GetTickCount())
		{
			Skill2 = GetTickCount();
			bSkillCoolTime2 = false;
			m_bIsMove = true;
		}
	}
	if(bSkillCoolTime3)
	{
		if(Skill3 + 4000 < GetTickCount())
		{
			Skill3 = GetTickCount();
			bSkillCoolTime3 = false;
			m_bIsMove = true;
		}
	}
	if(bSkillCoolTime4)
	{
		if(Skill4 + 5000 < GetTickCount())
		{
			Skill4 = GetTickCount();
			bSkillCoolTime4 = false;
			m_bIsMove = true;
		}
	}
	if(bSkillCoolTime5)
	{
		if(Skill5 + 6000 < GetTickCount())
		{
			Skill5 = GetTickCount();
			bSkillCoolTime5 = false;
			m_bIsMove = true;
		}
	}
	if(bSkillCoolTime6)
	{
		if(Skill6 + 7000 < GetTickCount())
		{
			Skill6 = GetTickCount();
			bSkillCoolTime6 = false;
			m_bIsMove = true;
		}
	}
	StateChange();
	stateJump();
	Scroll();

	CObj::FrameMove();
	CObj::Update();
	
	return 0;
}
void CPlayer::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();
	
	m_fz = m_tInfo.iY - m_fJumpY;

	TransparentBlt(hdc, m_tRect.left + g_iScrollX -60, (int)m_fz -120, 170, 142, 
		hmemDC, m_tFrame.iFrameStart * 140, m_tFrame.iScene * 112
		, 140 , 112, RGB(255,0,255));
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		Rectangle(hdc, m_tRect.left + g_iScrollX,  m_tRect.top,  m_tRect.right + g_iScrollX,  m_tRect.bottom);
	CSkillMgr::GetInstance()->Render(hdc);
}
void CPlayer::Release()
{
	CSkillMgr::GetInstance()->DestroyInstance();
}

void CPlayer::stateJump()
{	
	if(m_bIsJump)
	{
		m_fJumpAcc += 0.3f;
		m_fJumpY = m_fJumpPow * m_fJumpAcc - GRAVITY * m_fJumpAcc * m_fJumpAcc * 0.5f;
		if(m_fz > m_tInfo.iY)
		{
			m_fJumpAcc = 0.f;
			m_bIsJump = false;
			m_fJumpY = 0.f;
			m_fz = 0.f;
			m_bIsMove = true;
		}
	}
}

void CPlayer::Scroll()
{
	if(600+200 < m_tInfo.iX + g_iScrollX)
		g_iScrollX -= m_iSpeed;
	else if(600-200 > m_tInfo.iX + g_iScrollX)
		g_iScrollX += m_iSpeed;

	if(0 <= g_iScrollX)
		g_iScrollX = 0;
	else if(-1200 > g_iScrollX)
		g_iScrollX = - 1200;

}
void CPlayer::StateChange()
{
	if(m_eCurState != m_ePreState)
	{
		switch(m_eCurState)
		{
		case Stand:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iScene = 0;
			m_tFrame.dwFrameSpd = 400;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case Walk:			
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 9;
			m_tFrame.iScene = 2;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case Jump:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iScene = 4;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case Attack:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 8;
			m_tFrame.iScene = 6;
			m_tFrame.dwFrameSpd = 100;
			m_tFrame.dwFrameOld = GetTickCount();
			break;	
		case Dash:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iScene = 3;
			m_tFrame.dwFrameSpd = 80;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case Casting:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 6;
			m_tFrame.iScene = 7;
			m_tFrame.dwFrameSpd = 100;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case Casting2:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iScene = 8;
			m_tFrame.dwFrameSpd = 100;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case Casting3:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 10;
			m_tFrame.iScene = 11;
			m_tFrame.dwFrameSpd = 100;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case Hit:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.iScene = 9;
			m_tFrame.dwFrameSpd = 100;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case DashAttack:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 12;
			m_tFrame.iScene = 5;
			m_tFrame.dwFrameSpd = 60;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		}
	}
	m_ePreState = m_eCurState;
}