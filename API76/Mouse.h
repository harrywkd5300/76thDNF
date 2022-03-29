#pragma once
//#include "Obj.h"

class CMouse :
	public CObj
{
public:
	CMouse(void);
	virtual ~CMouse(void);

public:
	static POINT GetMouse()
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		return pt;
	}
public:
	POINT GetAgoMouse() { return m_ptAgoMouse; }
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();

private:
	POINT	m_ptMouse;
	POINT	m_ptAgoMouse;
	DWORD   m_dwTime;
	DWORD   m_dwClick;

};
