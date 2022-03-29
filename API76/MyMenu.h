#pragma once
#include "scene.h"

class CMyMenu :
	public CScene
{
public:
	CMyMenu(void);
	virtual ~CMyMenu(void);
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
