#pragma once
#include "scene.h"

class CDungeon1 :
	public CScene
{
public:
	CDungeon1(void);
	virtual ~CDungeon1(void);
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
