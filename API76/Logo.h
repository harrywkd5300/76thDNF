#pragma once
#include "scene.h"

class CLogo :
	public CScene
{
public:
	CLogo(void);
	virtual ~CLogo(void);
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
private:
	HWND	m_hVideo; // 동영상 재생을 하기위한 윈도우창 핸들.
};
