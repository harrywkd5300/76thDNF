#pragma once
//#include "obj.h"

class CInventory :
	public CObj
{
	INFO m_ClickInfo;
	RECT m_ClickRect;
	INFO m_ClickInfo2;
	RECT m_ClickRect2;
	INFO m_ClickInfo3;
	RECT m_ClickRect3;
	vector<CObj*>::iterator iter_begin;
	vector<CObj*>::iterator iter_end;

	vector<CObj*>::iterator iter_begin2;
	vector<CObj*>::iterator iter_end2;
	int PlisX;
	int PlisY;
	bool bSellClick;
	DWORD dClick;
public:
	CInventory(void);
	virtual ~CInventory(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	void ClickRect();
};
