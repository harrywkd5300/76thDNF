#pragma once
#include "scene.h"

class CDungeon2 :
	public CScene
{
public:
	CDungeon2(void);
	virtual ~CDungeon2(void);

public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
