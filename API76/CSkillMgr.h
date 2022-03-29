#pragma once

class CSkillMgr
{
	DECLARE_SINGLETON(CSkillMgr)
	bool playerKey;
public:
	CSkillMgr(void);
	~CSkillMgr(void);
public:
	void Update();
	void Render(HDC hdc);
	void Release();

public:
	void SetSkill(Skillname eSkillname, int PlayerX, int PlayerY);
};
