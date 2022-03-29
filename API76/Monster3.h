#pragma once
#include "obj.h"

class CMonster3 :
	public CObj
{
public:
	CMonster3(void);
	virtual ~CMonster3(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
