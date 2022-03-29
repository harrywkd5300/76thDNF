#pragma once
#include "obj.h"

class CUibase :
	public CObj
{
public:
	CUibase(void);
	virtual ~CUibase(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
