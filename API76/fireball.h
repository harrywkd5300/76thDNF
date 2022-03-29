#pragma once
#include "obj.h"


class fireball :
		public CObj
{
	int iCX;
	int iCY;
public:
	fireball(void);
	virtual ~fireball(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
