#pragma once
#include "scene.h"

class CDGSelect :
	public CScene
{
public:
	CDGSelect(void);
	virtual ~CDGSelect(void);
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
