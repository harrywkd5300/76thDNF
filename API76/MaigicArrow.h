#pragma once
#include "obj.h"

class CMaigicArrow :
	public CObj
{
public:
	CMaigicArrow(void);
	virtual ~CMaigicArrow(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
