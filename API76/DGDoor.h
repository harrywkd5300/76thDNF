#pragma once
#include "obj.h"

class CDGDoor :
	public CObj
{
	TCHAR*	m_pFrameKey;
	int m_iFrame;
public:
	CDGDoor(void);
	CDGDoor(TCHAR* pFrameKey, int iX, int iY);
	virtual ~CDGDoor(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
