#pragma once
#include "obj.h"

class CItem :
	public CObj
{
	INFO m_ClickInfo;
	RECT m_ClickRect;
	bool m_BuyItem;
public:
	bool m_IsEquip;
public:
	CItem(void);
	virtual ~CItem(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	void ClickRect();
	INFO GetClickInfo() { return m_ClickInfo; }
	RECT GetClickRect() { return m_ClickRect; }
	void SetBuyItem() { m_BuyItem = true; }
	ItemState GetItemState() { return itemstat; }
};
