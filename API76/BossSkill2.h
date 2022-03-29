#pragma once
#include "obj.h"

class CBossSkill2 :
	public CObj
{
	bool EndSkill;
public:
	CBossSkill2(void);
	virtual ~CBossSkill2(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
