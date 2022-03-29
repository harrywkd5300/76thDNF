#include "StdAfx.h"
#include "Inventory.h"
#include "Mouse.h"
#include "Player.h"
#include "Npc.h"
#include "Item.h"

CInventory::CInventory(void)
{
}

CInventory::~CInventory(void)
{
	Release();
}
void CInventory::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"Inven", (new CMyBitmap)->LoadBmp(L"../image/UI/Inven.bmp")));
	m_pFrameKey = L"Inven";
	m_tInfo.iCX = 258;
	m_tInfo.iCY = 521;
	m_ClickInfo.iX = m_tInfo.iX;
	m_ClickInfo.iY = m_tInfo.iY - 230;
	m_ClickInfo.iCX = 258;
	m_ClickInfo.iCY = 60;

	m_ClickInfo2.iX = m_tInfo.iX;
	m_ClickInfo2.iY = m_tInfo.iY + 70;
	m_ClickInfo2.iCX = 258;
	m_ClickInfo2.iCY = 210;

	m_ClickInfo3.iX = m_tInfo.iX - 105;
	m_ClickInfo3.iY = m_tInfo.iY - 20;
	m_ClickInfo3.iCX = 32; 
	m_ClickInfo3.iCY = 30;
	bSellClick = false;

	dClick = GetTickCount();

	PlisX = 0;
	PlisY = 0;

	iter_begin = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().begin();
	iter_end = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().end();
	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		(*iter_begin)->SetPos(m_tInfo.iX-105 + PlisX, m_tInfo.iY - 20 + PlisY);
		PlisX += 30;
		if(PlisX == 240)
		{
			PlisX = 0;
			PlisY += 30;
		}
		(*iter_begin)->initirize();
	}
	CObj::Update();
	m_eRenderID = Render_UI;

	iter_begin2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().begin();
	iter_end2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().end();
	for( ; iter_begin2 != iter_end2 ; ++iter_begin2)
	{
		if(dynamic_cast<CItem*>((*iter_begin2))->GetItemState() == CLOTH)
			(*iter_begin2)->SetPos(m_tInfo.iX - 22 , m_tInfo.iY-178);
		else if(dynamic_cast<CItem*>((*iter_begin2))->GetItemState() == PANTS)
			(*iter_begin2)->SetPos(m_tInfo.iX + 13 , m_tInfo.iY-178);
		else if(dynamic_cast<CItem*>((*iter_begin2))->GetItemState() == SHOSE)
			(*iter_begin2)->SetPos(m_tInfo.iX + 48 , m_tInfo.iY-178);
		else if(dynamic_cast<CItem*>((*iter_begin2))->GetItemState() == WEAPON)
			(*iter_begin2)->SetPos(m_tInfo.iX - 57 , m_tInfo.iY-178);

		(*iter_begin2)->initirize();
	}
}

int CInventory::Update()
{
	iter_begin = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().begin();
	iter_end = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().end();

	iter_begin2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().begin();
	iter_end2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().end();

	POINT pt = CMouse::GetMouse();
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();
	ClickRect();
	if(PtInRect(&m_ClickRect, pt))
	{
		POINT pt2 = dynamic_cast<CMouse*>(CObjMgr::GetInstance()->GetObj(MOUSE))->GetAgoMouse();

		if(KEYPRESS(dwKey, KEY_LBUTTON))
		{
			m_tInfo.iX += pt.x - pt2.x;
			m_tInfo.iY += pt.y - pt2.y;
			m_ClickInfo.iX = m_tInfo.iX;
			m_ClickInfo.iY = m_tInfo.iY - 230;
			m_ClickInfo2.iX = m_tInfo.iX;
			m_ClickInfo2.iY = m_tInfo.iY+70;
			m_ClickInfo3.iX = m_tInfo.iX - 105;
			m_ClickInfo3.iY = m_tInfo.iY - 20;
			for( ; iter_begin != iter_end ; ++iter_begin)
			{
				(*iter_begin)->GetInfo().iX += pt.x - pt2.x;
				(*iter_begin)->GetInfo().iY += pt.y - pt2.y;
				(*iter_begin)->Update();
			}
			for( ; iter_begin2 != iter_end2 ; ++iter_begin2)
			{
				(*iter_begin2)->GetInfo().iX += pt.x - pt2.x;
				(*iter_begin2)->GetInfo().iY += pt.y - pt2.y;
				(*iter_begin2)->Update();
			}
		}
		else if(KEYPRESS(dwKey, KEY_RBUTTON))
		{
			dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->SetViewINVEN();
			return 1;
		}
	}

	static bool ItemSel = FALSE;

	if(dynamic_cast<CNpc*>(CObjMgr::GetInstance()->GetObj(NPC))->bOpenShop)
	{
		if(PtInRect(&m_ClickRect2, pt))
		{
			if(KEYPRESS(dwKey, KEY_LBUTTON))
			{
				if(ItemSel == FALSE)
				{
					int iX = (CMouse::GetMouse().x - m_ClickInfo3.iX) / 32;
					int iY = (CMouse::GetMouse().y - m_ClickInfo3.iY) / 30;
					int iIndex = iX + (8 * iY);
					iter_begin = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().begin();
					iter_end = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().end();
					if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().size() != 0)
					{
						int iCount = 0;
						for( ; iter_begin != iter_end ; ++iter_begin)
						{
							if(iCount == iIndex)
							{					
								dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().erase(iter_begin);
								initirize();
								ItemSel = TRUE;
								return 0;
							}
							else
								++iCount;
						}
					}
					ItemSel = TRUE;
				}
			}
			else
				ItemSel = FALSE;
		}
	}
	else
	{
		if(PtInRect(&m_ClickRect2, pt))
		{
			if(KEYPRESS(dwKey, KEY_LBUTTON))
			{
				if(ItemSel == FALSE)
				{
					int iX = (CMouse::GetMouse().x - m_ClickInfo3.iX) / 32;
					int iY = (CMouse::GetMouse().y - m_ClickInfo3.iY) / 30;
					int iIndex = iX + (8 * iY);
					iter_begin = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().begin();
					iter_end = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().end();
					int iCount = 0;
					for( ; iter_begin != iter_end ; ++iter_begin)
					{
						if(iCount == iIndex)
						{
							if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().empty())
							{
								dynamic_cast<CItem*>((*iter_begin))->m_IsEquip = true;
								dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().push_back((*iter_begin));
								dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().erase(iter_begin);
								initirize();
								ItemSel = TRUE;
								return 0;
							}
							else
							{
								dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().push_back((*iter_begin));
								dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().erase(iter_begin);
								initirize();
								ItemSel = TRUE;
								return 0;
							}
						}
						else
							++iCount;
						ItemSel = TRUE;
					}
				}
			}
			else
				ItemSel = FALSE;
		}
	}
	CObj::Update();
	return 0;

}
void CInventory::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();

	TransparentBlt(hdc, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, 
		hmemDC, 0, 0, m_tInfo.iCX , m_tInfo.iCY, RGB(255,0,255));

	iter_begin = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().begin();
	iter_end = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().end();
	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		(*iter_begin)->Render(hdc);
	}

	
	iter_begin2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().begin();
	iter_end2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().end();
	for( ; iter_begin2 != iter_end2 ; ++iter_begin2)
	{
		(*iter_begin2)->Render(hdc);
	}



	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
	{
		Rectangle(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		Rectangle(hdc, m_ClickRect.left, m_ClickRect.top, m_ClickRect.right, m_ClickRect.bottom);
		Rectangle(hdc, m_ClickRect2.left, m_ClickRect2.top, m_ClickRect2.right, m_ClickRect2.bottom);
		Rectangle(hdc, m_ClickRect3.left, m_ClickRect3.top, m_ClickRect3.right, m_ClickRect3.bottom);
	}
}
void CInventory::Release()
{

}
void CInventory::ClickRect()
{
	m_ClickRect.left = m_ClickInfo.iX - m_ClickInfo.iCX / 2;
	m_ClickRect.top = m_ClickInfo.iY - m_ClickInfo.iCY / 2;
	m_ClickRect.right = m_ClickInfo.iX + m_ClickInfo.iCX / 2;
	m_ClickRect.bottom = m_ClickInfo.iY + m_ClickInfo.iCY / 2;

	m_ClickRect2.left = m_ClickInfo2.iX - m_ClickInfo2.iCX / 2;
	m_ClickRect2.top = m_ClickInfo2.iY - m_ClickInfo2.iCY / 2;
	m_ClickRect2.right = m_ClickInfo2.iX + m_ClickInfo2.iCX / 2;
	m_ClickRect2.bottom = m_ClickInfo2.iY + m_ClickInfo2.iCY / 2;

	m_ClickRect3.left = m_ClickInfo3.iX - m_ClickInfo3.iCX / 2;
	m_ClickRect3.top = m_ClickInfo3.iY - m_ClickInfo3.iCY / 2;
	m_ClickRect3.right = m_ClickInfo3.iX + m_ClickInfo3.iCX / 2;
	m_ClickRect3.bottom = m_ClickInfo3.iY + m_ClickInfo3.iCY / 2;
}


						//int iCount = 0;
						//for( ; iter_begin != iter_end ; ++iter_begin)
						//{
						//	if(iCount == iIndex)
						//	{
						//		if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().empty())
						//		{
						//			dynamic_cast<CItem*>((*iter_begin))->m_IsEquip = true;
						//			dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().push_back((*iter_begin));
						//			dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().erase(iter_begin);
						//		}
						//		else
						//		{
						//			iter_begin2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().begin();
						//			iter_end2 = dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().end();
						//			for( ; iter_begin2 != iter_end2 ; ++iter_begin2)
						//			{
						//				if(dynamic_cast<CItem*>((*iter_begin))->GetItemState() == dynamic_cast<CItem*>((*iter_begin2))->GetItemState())
						//				{
						//					dynamic_cast<CItem*>((*iter_begin2))->m_IsEquip = false;
						//					dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().push_back((*iter_begin2));
						//					dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().erase(iter_begin2);
						//				}
						//				else
						//				{
						//					dynamic_cast<CItem*>((*iter_begin))->m_IsEquip = true;
						//					dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetEquipItem().push_back((*iter_begin));
						//					dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->GetInven().push_back((*iter_begin2));
						//				}
						//			}
						//		}
						//		initirize();
						//		ItemSel = TRUE;
						//		return 0;
						//	}
						//	else
						//		++iCount;
						//}
