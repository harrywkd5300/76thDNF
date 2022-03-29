#pragma once
#include "obj.h"

class CFirewall :
	public CObj
{
	DWORD SkillOldTime;
	DWORD SkillCUrTime;
public:
	CFirewall(void);
	virtual ~CFirewall(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
