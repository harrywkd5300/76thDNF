#pragma once
#include "obj.h"

class CMonster :
	public CObj
{
public:
	CMonster(void);
	virtual ~CMonster(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
