#pragma once
#include "scene.h"

class CMyEdit :
	public CScene
{
	int MaxSize;
public:
	CMyEdit(void);
	virtual ~CMyEdit(void);
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();

private:
	void Picking();
	void Scroll();
};
