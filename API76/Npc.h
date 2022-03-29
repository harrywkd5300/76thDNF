#pragma once
#include "obj.h"

class CNpc :
	public CObj
{
	DWORD dTalkTime;
public:
	CNpc(void);
	virtual ~CNpc(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	bool bOpenShop;
};
