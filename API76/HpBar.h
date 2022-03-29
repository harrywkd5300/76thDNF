#pragma once
#include "obj.h"

class CHpBar :
	public CObj
{
public:
	bool m_FirstHp;
	bool m_IsDraw;
public:
	CHpBar(void);
	virtual ~CHpBar(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
