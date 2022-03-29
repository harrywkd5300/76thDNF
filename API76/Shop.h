#pragma once
#include "obj.h"


class CShop :
	public CObj
{
	INFO m_ClickInfo;
	RECT m_ClickRect;
	INFO m_ItemInfo;
	RECT m_ItemRect;
	bool m_bBuyItem;
	DWORD dClickTime;
	TCHAR* pBuyFrameKey;
public:
	bool DeleteShop;
public:
	CShop(void);
	virtual ~CShop(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	void ClickRect();
	CObj* BuyItem(TCHAR* pFramekey);
};
