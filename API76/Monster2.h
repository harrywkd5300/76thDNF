#pragma once
#include "obj.h"

class CMonster2 :
	public CObj
{
	DWORD dSkillTime;
	DWORD dHitTime;
	int m_iHitcount;
	int iWidth;
	int iLength;
	int CollBox;
public:
	CMonster2(void);
	virtual ~CMonster2(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
