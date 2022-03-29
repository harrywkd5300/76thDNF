#include "StdAfx.h"
#include "EffectMgr.h"
#include "Bomb.h"
#include "Spark.h"

IMPLEMENT_SINGLETON(CEffectMgr)

CEffectMgr::CEffectMgr(void)
{
}

CEffectMgr::~CEffectMgr(void)
{
	Release();
}
void CEffectMgr::SetEffect(EffectName peffectname, int PlayerX, int PlayerY)
{
	switch(peffectname)
	{
	case bomb:
		CObjMgr::GetInstance()->AddObject(CAbstract<CBomb>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), EFFECT);
		break;
	case spark:
		CObjMgr::GetInstance()->AddObject(CAbstract<CSpark>::CreateObj(PlayerX, PlayerY, CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsRight()), EFFECT);
		break;
	}
}
void CEffectMgr::Update()
{

}
void CEffectMgr::Render(HDC hdc)
{

}
void CEffectMgr::Release()
{

}