#pragma once

class CEffectMgr
{
	DECLARE_SINGLETON(CEffectMgr)
public:
	CEffectMgr(void);
	~CEffectMgr(void);
public:
	void Update();
	void Render(HDC hdc);
	void Release();
public:
	void SetEffect(EffectName peffectname, int PlayerX, int PlayerY);
};
