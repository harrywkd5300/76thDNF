#pragma once
#include "scene.h"

class CBossDG :
	public CScene
{
public:
	CBossDG(void);
	virtual ~CBossDG(void);
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
