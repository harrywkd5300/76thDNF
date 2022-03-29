#pragma once
#include "scene.h"

class CStage :
	public CScene
{
public:
	CStage(void);
	virtual ~CStage(void);

public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
