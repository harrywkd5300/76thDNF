#pragma once
#include "obj.h"

class CBossSkill1 :
	public CObj
{
	bool EndSkill;
public:
	CBossSkill1(void);
	virtual ~CBossSkill1(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
