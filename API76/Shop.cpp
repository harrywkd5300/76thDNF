#include "StdAfx.h"
#include "Shop.h"
#include "Mouse.h"
#include "Player.h"
#include "Item.h"
#include "Npc.h"
#include "Inventory.h"

CShop::CShop(void)
{
}

CShop::~CShop(void)
{
	Release();
}
void CShop::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"Store", (new CMyBitmap)->LoadBmp(L"../image/UI/Store.bmp")));
	m_pFrameKey = L"Store";
	m_tInfo.iCX = 368;
	m_tInfo.iCY = 464;
	m_ClickInfo.iX = m_tInfo.iX;
	m_ClickInfo.iY = m_tInfo.iY - 210;
	m_ClickInfo.iCX = 368;
	m_ClickInfo.iCY = 40;

	dClickTime = GetTickCount();

	m_bBuyItem = false;
	CObj::Update();
	DeleteShop = false;
	m_eRenderID = Render_UI;
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX - 153, m_tInfo.iY - 134, L"coat2"), ITEM);
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX + 16, m_tInfo.iY - 134, L"coat3"), ITEM);
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX - 153, m_tInfo.iY - 74, L"pant2"), ITEM);
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX + 16, m_tInfo.iY - 74, L"pant3"), ITEM);
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX - 153, m_tInfo.iY - 14, L"shose2"), ITEM);
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX + 16, m_tInfo.iY - 14, L"shose3"), ITEM);
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX - 153, m_tInfo.iY + 44, L"weapon2"), ITEM);
	CObjMgr::GetInstance()->AddObject(CAbstract<CItem>::CreateObj(m_tInfo.iX + 16, m_tInfo.iY + 44, L"weapon3"), ITEM);
}
int CShop::Update()
{
	POINT pt = CMouse::GetMouse();
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();
	ClickRect();
	CObj::Update();

	OBJITER iter_begin = CObjMgr::GetInstance()->GetList(ITEM).begin();
	OBJITER iter_end = CObjMgr::GetInstance()->GetList(ITEM).end();
	if(PtInRect(&m_ClickRect, pt))
	{
		if(KEYPRESS(dwKey, KEY_LBUTTON))
		{
			POINT pt2 = dynamic_cast<CMouse*>(CObjMgr::GetInstance()->GetObj(MOUSE))->GetAgoMouse();

			m_tInfo.iX += pt.x - pt2.x;
			m_tInfo.iY += pt.y - pt2.y;
			m_ClickInfo.iX = m_tInfo.iX;
			m_ClickInfo.iY = m_tInfo.iY - 210;
			for( ; iter_begin != iter_end ; ++iter_begin)
			{
				(*iter_begin)->GetInfo().iX += pt.x - pt2.x;
				(*iter_begin)->GetInfo().iY += pt.y - pt2.y;
			}
		}
		else if(KEYPRESS(dwKey, KEY_RBUTTON))
		{
			dynamic_cast<CNpc*>(CObjMgr::GetInstance()->GetObj(NPC))->bOpenShop = false;
			return 1;
		}
	}

	if(m_bBuyItem == true)
	{
		if(dClickTime + 1000 < GetTickCount())
		{
			m_bBuyItem = false;
			dClickTime = GetTickCount();
		}
	}

	static bool ItemBuy = FALSE;

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(PtInRect(&(dynamic_cast<CItem*>((*iter_begin))->GetClickRect()), pt))
		{
			pBuyFrameKey = (*iter_begin)->GetFrameKey();
			if(!m_bBuyItem)
			{
				if(KEYPRESS(dwKey, KEY_LBUTTON))
				{
					if(ItemBuy == FALSE)
					{
						m_bBuyItem = true;
						dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().push_back(BuyItem(pBuyFrameKey));
						if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->m_bInven)
							dynamic_cast<CInventory*>(CObjMgr::GetInstance()->GetObj(INVEN))->initirize();
						ItemBuy = TRUE;
					}
				}
				else
					ItemBuy = false;
			}
		}
	}
	return 0;
}
void CShop::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();

	TransparentBlt(hdc, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, 
		hmemDC, 0, 0, m_tInfo.iCX , m_tInfo.iCY, RGB(255,0,255));

	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
	{
		Rectangle(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		Rectangle(hdc, m_ClickRect.left, m_ClickRect.top, m_ClickRect.right, m_ClickRect.bottom);
	}
}
void CShop::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(ITEM);
}

void CShop::ClickRect()
{
	m_ClickRect.left = m_ClickInfo.iX - m_ClickInfo.iCX / 2;
	m_ClickRect.top = m_ClickInfo.iY - m_ClickInfo.iCY / 2;
	m_ClickRect.right = m_ClickInfo.iX + m_ClickInfo.iCX / 2;
	m_ClickRect.bottom = m_ClickInfo.iY + m_ClickInfo.iCY / 2;
}
CObj* CShop::BuyItem(TCHAR* pFramekey)
{
	CObj* pItem = new CItem;
	pItem->SetFrameKey(pFramekey);
	return pItem;
}
