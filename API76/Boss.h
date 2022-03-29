#pragma once
#include "obj.h"

class CBoss :
	public CObj
{
	DWORD dSkillTime;
	DWORD dDieTime;
	bool OpenMonster;
	int iWidth;
	int iLength;
	int iMaxSize;
	int iMaxHeight;
public:
	CBoss(void);
	virtual ~CBoss(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
