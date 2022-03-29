#pragma once

class CUimgr
{
	DECLARE_SINGLETON(CUimgr)
public:
	CUimgr(void);
	~CUimgr(void);
public:
	void Update();
	void Render(HDC hdc);
	void Release();
public:
	void SetUi(UitName pUiname, int PlayerX, int PlayerY);
};
