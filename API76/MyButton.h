#pragma once
#include "obj.h"

class CMyButton :
	public CObj
{
public:
	CMyButton(void);
	CMyButton(TCHAR* pFrameKey, int iX, int iY, int iCX, int iCY);
	virtual ~CMyButton(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	TCHAR*	m_pFrameKey;
	int		m_iFrame;
};
