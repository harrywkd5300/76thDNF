#include "StdAfx.h"
#include "CSkillMgr.h"
#include "Obj.h"
#include "Player.h"
#include "MaigicArrow.h"
#include "fireball.h"
#include "Buster.h"
#include "Thunder.h"
#include "NightHallow.h"
#include "AuarShield.h"
#include "Firewall.h"
#include "Explosion.h"
#include "BossSkill1.h"
#include "BossSkill2.h"


IMPLEMENT_SINGLETON(CSkillMgr)
CSkillMgr::CSkillMgr(void)
{

}

CSkillMgr::~CSkillMgr(void)
{
	Release();
}

void CSkillMgr::Release()
{
	CObjMgr::GetInstance()->ReleaseAll();
}
void CSkillMgr::SetSkill(Skillname eSkillname, int PlayerX, int PlayerY)
{
	switch(eSkillname)
	{
	case Arrow:
		CObjMgr::GetInstance()->AddObject(CAbstract<CMaigicArrow>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case Fireball:
		CObjMgr::GetInstance()->AddObject(CAbstract<fireball>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case Buster:
		CObjMgr::GetInstance()->AddObject(CAbstract<CBuster>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case thunder:
		CObjMgr::GetInstance()->AddObject(CAbstract<CThunder>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case night:
		CObjMgr::GetInstance()->AddObject(CAbstract<CNightHallow>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case Shield:
		CObjMgr::GetInstance()->AddObject(CAbstract<CAuarShield>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case Firewall:
		CObjMgr::GetInstance()->AddObject(CAbstract<CFirewall>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case Explosion:
		CObjMgr::GetInstance()->AddObject(CAbstract<CExplosion>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case BossSkill1:
		CObjMgr::GetInstance()->AddObject(CAbstract<CBossSkill1>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	case BossSkill2:
		CObjMgr::GetInstance()->AddObject(CAbstract<CBossSkill2>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), SKILL);
		break;
	}
}
void CSkillMgr::Update()
{
}
void CSkillMgr::Render(HDC hdc)
{
}