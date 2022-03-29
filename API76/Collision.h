#pragma once


class CObj;
class CCollisionMgr
{
public:
	CCollisionMgr(void);
	~CCollisionMgr(void);

public:
	static void CollisionRect(OBJLIST* pMonster, OBJLIST* pPlayer);
	static void Collisiontail(CObj* pSrc, vector<CObj*>* tailVector, Scene eType);
	static void Collisionthreetail(CObj* pSrc, vector<CObj*>* tailVector, Scene eType, Scene eType2, Scene eType3);
	static void CollisionSkill(OBJLIST* pSkill, OBJLIST* pMonster);
	static void Collisionmonster(list<CObj*>* pSrc, vector<CObj*>* tailVector);
public:

};
