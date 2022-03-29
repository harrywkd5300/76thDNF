#pragma once
#include "obj.h"

class CExplosion :
	public CObj
{
public:
	CExplosion(void);
	virtual ~CExplosion(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	void ExplosionFrame();
};
