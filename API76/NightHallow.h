#pragma once
#include "obj.h"

class CNightHallow :
	public CObj
{
	bool SkillEnd;
	TCHAR* playerFrameKey;
public:
	CNightHallow(void);
	virtual ~CNightHallow(void);

public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
