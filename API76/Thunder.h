#pragma once
#include "obj.h"

class CThunder :
	public CObj
{
	DWORD SkillOldTime;
	DWORD SkillCUrTime;
public:
	CThunder(void);
	virtual ~CThunder(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
