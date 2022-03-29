#pragma once
#include "obj.h"

class CAuarShield :
	public CObj
{
public:
	CAuarShield(void);
	virtual ~CAuarShield(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
