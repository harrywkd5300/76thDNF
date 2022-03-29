#pragma once
#include "obj.h"

class CMonster1 :
	public CObj
{
	bool OpenMonster;
	int iWidth;
	int iLength;
public:
	CMonster1(void);
	virtual ~CMonster1(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
