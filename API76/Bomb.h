#pragma once
#include "obj.h"

class CBomb :
	public CObj
{
	int iXSize;
	int iYSize;
public:
	CBomb(void);
	virtual ~CBomb(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	void SetSize(int _iX, int _iY) { iXSize = _iX, iYSize = _iY; }
};
