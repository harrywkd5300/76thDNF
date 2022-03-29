#pragma once
#include "obj.h"

class CBuster :
	public CObj
{
	float Mul;
	int DIeX;
public:
	CBuster(void);
	virtual ~CBuster(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
