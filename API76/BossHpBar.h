#pragma once
#include "obj.h"

class CBossHpBar :
	public CObj
{
public:
	CBossHpBar(void);
	virtual ~CBossHpBar(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
