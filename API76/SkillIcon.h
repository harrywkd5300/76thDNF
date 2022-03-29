#pragma once
//#include "obj.h"

class CSkillIcon :
	public CObj
{
	DWORD Skill1;
public:
	CSkillIcon(void);
	virtual ~CSkillIcon(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
