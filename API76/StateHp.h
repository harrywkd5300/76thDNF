#pragma once
//#include "obj.h"

class CStateHp : public CObj
{
public:
	CStateHp(void);
	virtual ~CStateHp(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
