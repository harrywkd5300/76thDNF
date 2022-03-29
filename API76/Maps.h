#pragma once
#include "obj.h"

class CMaps :
	public CObj
{
public:
	CMaps(void);
	~CMaps(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
