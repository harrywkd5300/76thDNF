#pragma once

class CMaingame
{
	HDC m_hdc;
public:
	CMaingame(void);
	~CMaingame(void);
public:
	void initirize();
	void Update();
	void Render();
	void Release();
};
