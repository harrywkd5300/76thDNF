#include "StdAfx.h"
#include "Collision.h"
#include "Obj.h"
#include "Bomb.h"
#include "Spark.h"
#include "HpBar.h"


CCollisionMgr::CCollisionMgr(void)
{
}

CCollisionMgr::~CCollisionMgr(void)
{
}
void CCollisionMgr::CollisionRect(OBJLIST* pMonster, OBJLIST* pPlayer)
{
	OBJITER dst_begin = pMonster->begin();
	OBJITER dst_end = pMonster->end();

	DWORD hittime =GetTickCount();

	RECT rc = {};

	for( ; dst_begin != dst_end; ++dst_begin)
	{
		if(true == (*dst_begin)->GetDeadState())
			continue;

		OBJITER src_begin = pPlayer->begin();
		OBJITER src_end = pPlayer->end();

		for(; src_begin != src_end; ++src_begin)
		{
			if(true == (*src_begin)->GetDeadState())
				continue;
			if(IntersectRect(&rc, &((*dst_begin)->GetRect()), &((*src_begin)->GetRect())))
			{
				CObjMgr::GetInstance()->GetObj(PLAYER)->SetIsHitting();
			}
		}
	}
}

void CCollisionMgr::Collisiontail(CObj* pSrc, vector<CObj*>* tailVector, Scene eType)
{
	vector<CObj*>::iterator iter_begin = tailVector->begin();
	vector<CObj*>::iterator iter_end = tailVector->end();
	RECT rc = {};

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 2)
		{
			if(IntersectRect(&rc, &(pSrc->GetRect()),&((*iter_begin)->GetRect())))
			{
				if(pSrc->GetRect().bottom >= (*iter_begin)->GetRect().bottom)
				{
					CSceneMgr::GetInstance()->SetScene(eType);
					return;
				}
			}
		}
		if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 0 || dynamic_cast<CTile*>(*iter_begin)->GetDrawID()==1)
		{
			if(IntersectRect(&rc, &(pSrc->GetRect()),&((*iter_begin)->GetRect())))
			{
				int iLength = rc.right - rc.left;
				int iWidth  = rc.bottom - rc.top;
				if(iLength > iWidth)
				{
					if(rc.top == (*iter_begin)->GetRect().top)
					{
						pSrc->GetInfo().iY -= iWidth / 3;
						pSrc->GetInfo().iY -= iWidth / 3;
					}
					else if(rc.bottom == (*iter_begin)->GetRect().bottom)
					{
						pSrc->GetInfo().iY += iWidth / 3;
						pSrc->GetInfo().iY += iWidth / 3;
					}
				}
				else
				{
					if(rc.left == (*iter_begin)->GetRect().left)
					{
						pSrc->GetInfo().iX -= iLength / 3;
						pSrc->GetInfo().iX -= iLength / 3;
					}
					else if(rc.right == (*iter_begin)->GetRect().right)
					{
						pSrc->GetInfo().iX += iLength / 3;
						pSrc->GetInfo().iX += iLength / 3;
					}
				}
			}
		}
	}
}
void CCollisionMgr::Collisionmonster(list<CObj*>* pSrc, vector<CObj*>* tailVector)
{
	list<CObj*>::iterator iter_begin = pSrc->begin();
	list<CObj*>::iterator iter_end = pSrc->end();
	RECT rc = {};
	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(true == (*iter_begin)->GetDeadState())
			continue;
		vector<CObj*>::iterator dst_begin = tailVector->begin();
		vector<CObj*>::iterator dst_end = tailVector->end();
		for(; dst_begin != dst_end; ++dst_begin)
		{
			if(true == (*dst_begin)->GetDeadState())
				continue;
			if(dynamic_cast<CTile*>(*dst_begin)->GetDrawID() == 0 || dynamic_cast<CTile*>(*dst_begin)->GetDrawID()==1)
			{
				if(IntersectRect(&rc, &((*iter_begin)->GetRect()),&((*dst_begin)->GetRect())))
				{
					int iLength = rc.right - rc.left;
					int iWidth  = rc.bottom - rc.top;
					if(iLength > iWidth)
					{
						if(rc.top == (*dst_begin)->GetRect().top)
						{
							(*iter_begin)->GetInfo().iY -= iWidth / 3;
							(*iter_begin)->GetInfo().iY -= iWidth / 3;
						}
						else if(rc.bottom == (*dst_begin)->GetRect().bottom)
						{
							(*iter_begin)->GetInfo().iY += iWidth / 3 ;
							(*iter_begin)->GetInfo().iY += iWidth / 3 ;
						}
					}
					else
					{
						if(rc.left == (*dst_begin)->GetRect().left)
						{
							(*iter_begin)->GetInfo().iX -= iLength / 3 ;
							(*iter_begin)->GetInfo().iX -= iLength / 3 ;
						}
						else if(rc.right == (*dst_begin)->GetRect().right)
						{
							(*iter_begin)->GetInfo().iX += iLength / 3 ;
							(*iter_begin)->GetInfo().iX += iLength / 3 ;
						}
					}
				}
			}
		}
	}
}
void CCollisionMgr::Collisionthreetail(CObj* pSrc, vector<CObj*>* tailVector, Scene eType, Scene eType2, Scene eType3)
{
	vector<CObj*>::iterator iter_begin = tailVector->begin();
	vector<CObj*>::iterator iter_end = tailVector->end();
	RECT rc = {};

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 2)
		{
			if(IntersectRect(&rc, &(pSrc->GetRect()),&((*iter_begin)->GetRect())))
			{
				if((*iter_begin)->GetRect().right < 200)
				{
					if(pSrc->GetRect().bottom >= (*iter_begin)->GetRect().bottom)
					{
						CSceneMgr::GetInstance()->SetScene(eType);
						return;
					}
				}
				else if(900 < (*iter_begin)->GetRect().right && (*iter_begin)->GetRect().right < 1700)
				{
					if(pSrc->GetRect().bottom >= (*iter_begin)->GetRect().bottom)
					{
						CSceneMgr::GetInstance()->SetScene(eType2);
						return;
					}
				}
				else if(2100 < (*iter_begin)->GetRect().right)
				{
					if(pSrc->GetRect().bottom >= (*iter_begin)->GetRect().bottom)
					{
						CSceneMgr::GetInstance()->SetScene(eType3);
						return;
					}
				}
			}
		}
		if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 0 || dynamic_cast<CTile*>(*iter_begin)->GetDrawID()==1)
		{
			if(IntersectRect(&rc, &(pSrc->GetRect()),&((*iter_begin)->GetRect())))
			{
				int iLength = rc.right - rc.left;
				int iWidth  = rc.bottom - rc.top;
				if(iLength > iWidth)
				{
					if(rc.top == (*iter_begin)->GetRect().top)
					{
						pSrc->GetInfo().iY -= iWidth / 3;
						pSrc->GetInfo().iY -= iWidth / 3;
					}
					else if(rc.bottom == (*iter_begin)->GetRect().bottom)
					{
						pSrc->GetInfo().iY += iWidth / 3 ;
						pSrc->GetInfo().iY += iWidth / 3 ;
					}
				}
				else
				{
					if(rc.left == (*iter_begin)->GetRect().left)
					{
						pSrc->GetInfo().iX -= iLength / 3 ;
						pSrc->GetInfo().iX -= iLength / 3 ;
					}
					else if(rc.right == (*iter_begin)->GetRect().right)
					{
						pSrc->GetInfo().iX += iLength / 3 ;
						pSrc->GetInfo().iX += iLength / 3 ;
					}
				}
			}
		}
	}
}

void CCollisionMgr::CollisionSkill(OBJLIST* pSkill, OBJLIST* pMonster)
{
	OBJITER skill_begin = pSkill->begin();
	OBJITER skill_end = pSkill->end();

	RECT rc = {};

	for( ; skill_begin != skill_end ; ++skill_begin)
	{
		if(true == (*skill_begin)->GetDeadState())
			continue;

		OBJITER monster_begin = pMonster->begin();
		OBJITER monster_end = pMonster->end();

		for(; monster_begin != monster_end ; ++monster_begin)
		{
			if(true == (*monster_begin)->GetDeadState())
				continue;

			//if((*skill_begin)->GetFrameKey() == L"explosion")
			//{
			//	if((*skill_begin)->GetFrame().iFrameStart == (*skill_begin)->GetFrame().iFrameEnd)
			//	{
			//		(*monster_begin)->SetiHp((*skill_begin)->GetIAtk());
			//		if((*skill_begin)->GetInfo().iX > (*monster_begin)->GetInfo().iX)
			//		{
			//			(*monster_begin)->GetInfo().iX -= 50;
			//		}
			//		else
			//		{
			//			(*monster_begin)->GetInfo().iX += 50;
			//		}
			//	}
			//}
			if(IntersectRect(&rc, &((*skill_begin)->GetRect()), &((*monster_begin)->GetRect())))
			{
				int skillX = (*skill_begin)->GetInfo().iX;
				int skillY = (*skill_begin)->GetInfo().iY;

				if((*skill_begin)->GetSkillEnd() == true)
					(*skill_begin)->IsDead();

				(*monster_begin)->m_bIshit = true;
				(*monster_begin)->m_bIsHitTime = true;
				if((*skill_begin)->GetFrameKey() == L"fireball")
				{
					//CSoundMgr::GetInstance()->PlayBGM(L"fire_bomb.ogg", CSoundMgr::Channel_Eff);
					CEffectMgr::GetInstance()->SetEffect(bomb, skillX, skillY);
					dynamic_cast<CBomb*>(CObjMgr::GetInstance()->GetObj(EFFECT))->SetSize(120, 120);
					if((*skill_begin)->GetInfo().iX > (*monster_begin)->GetInfo().iX)
						(*monster_begin)->GetInfo().iX += 10;
					else
						(*monster_begin)->GetInfo().iX -= 10;
					(*monster_begin)->SetiHp((*skill_begin)->GetIAtk());
					if((*monster_begin)->GetIHp() <= 0)
						(*monster_begin)->IsDead();
				}
				else if((*skill_begin)->GetFrameKey() == L"buster")
				{
					//CSoundMgr::GetInstance()->PlayBGM(L"fire_bomb.ogg", CSoundMgr::Channel_Eff);
					CEffectMgr::GetInstance()->SetEffect(bomb, skillX, skillY);
					dynamic_cast<CBomb*>(CObjMgr::GetInstance()->GetObj(EFFECT))->SetSize(200, 200);

					if((*skill_begin)->GetInfo().iX > (*monster_begin)->GetInfo().iX)
						(*monster_begin)->GetInfo().iX += 5;
					else
						(*monster_begin)->GetInfo().iX -= 5;
					(*monster_begin)->SetiHp((*skill_begin)->GetIAtk());
					if((*monster_begin)->GetIHp() <= 0)
						(*monster_begin)->IsDead();
				}
				
				if((*monster_begin)->GetFrameKey() == L"Monster2_L" || (*monster_begin)->GetFrameKey() == L"Monster2_R" )
				{
					(*monster_begin)->SetIsHitting();
				}
				if((*skill_begin)->GetFrameKey() == L"nighthallow")
				{
					if((*skill_begin)->GetInfo().iX > (*monster_begin)->GetInfo().iX)
						(*monster_begin)->GetInfo().iX += 5;
					else
						(*monster_begin)->GetInfo().iX -= 5;
					(*monster_begin)->SetiHp((*skill_begin)->GetIAtk());
					if((*monster_begin)->GetIHp() <= 0)
						(*monster_begin)->IsDead();

				}
				else if((*skill_begin)->GetFrameKey() == L"thunder")
				{
					if((*skill_begin)->GetInfo().iX > (*monster_begin)->GetInfo().iX)
						(*monster_begin)->GetInfo().iX += 10;
					else
						(*monster_begin)->GetInfo().iX -= 10;
					(*monster_begin)->SetiHp((*skill_begin)->GetIAtk());
					if((*monster_begin)->GetIHp() <= 0)
						(*monster_begin)->IsDead();
				}
				else if((*skill_begin)->GetFrameKey() == L"firewall")
				{
					if((*skill_begin)->GetInfo().iX > (*monster_begin)->GetInfo().iX)
						(*monster_begin)->GetInfo().iX += 10;
					else
						(*monster_begin)->GetInfo().iX -= 10;
					(*monster_begin)->SetiHp((*skill_begin)->GetIAtk());
					if((*monster_begin)->GetIHp() <= 0)
						(*monster_begin)->IsDead();
				}
				else
				{
					if((*skill_begin)->GetRect().left > (*monster_begin)->GetRect().left)
						(*monster_begin)->GetInfo().iX -= 10;
					else
						(*monster_begin)->GetInfo().iX += 10;
					(*monster_begin)->SetiHp((*skill_begin)->GetIAtk());
					if((*monster_begin)->GetIHp() <= 0)
						(*monster_begin)->IsDead();
				}
			}
		}
	}
}