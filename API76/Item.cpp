#include "StdAfx.h"
#include "Item.h"
#include "Player.h"
#include "Mouse.h"

CItem::CItem(void)
:m_BuyItem(false)
{
}

CItem::~CItem(void)
{
	Release();
}
void CItem::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"coat1", (new CMyBitmap)->LoadBmp(L"../image/item/coat1.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"coat2", (new CMyBitmap)->LoadBmp(L"../image/item/coat2.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"coat3", (new CMyBitmap)->LoadBmp(L"../image/item/coat3.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"pant1", (new CMyBitmap)->LoadBmp(L"../image/item/pant1.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"pant2", (new CMyBitmap)->LoadBmp(L"../image/item/pant2.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"pant3", (new CMyBitmap)->LoadBmp(L"../image/item/pant3.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"shose1", (new CMyBitmap)->LoadBmp(L"../image/item/shose1.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"shose2", (new CMyBitmap)->LoadBmp(L"../image/item/shose2.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"shose3", (new CMyBitmap)->LoadBmp(L"../image/item/shose3.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"weapon1", (new CMyBitmap)->LoadBmp(L"../image/item/weapon1.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"weapon2", (new CMyBitmap)->LoadBmp(L"../image/item/weapon2.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"weapon3", (new CMyBitmap)->LoadBmp(L"../image/item/weapon3.bmp")));
	m_tInfo.iCX = 28;
	m_tInfo.iCY = 28;
	m_ClickInfo.iX = m_tInfo.iX + 60;
	m_ClickInfo.iY = m_tInfo.iY + 10;
	m_ClickInfo.iCX = 165;
	m_ClickInfo.iCY = 50;
	m_IsEquip = false;

	if(m_pFrameKey == L"coat1" || m_pFrameKey == L"coat2" || m_pFrameKey == L"coat3")
		itemstat = CLOTH;
	else if(m_pFrameKey == L"pant1" || m_pFrameKey == L"pant2" || m_pFrameKey == L"pant3")
		itemstat = PANTS;
	else if(m_pFrameKey == L"shose1" || m_pFrameKey == L"shose2" || m_pFrameKey == L"shose3")
		itemstat = SHOSE;
	else
		itemstat = WEAPON;

	m_eRenderID = Render_UI;
	CObj::Update();
}
int CItem::Update()
{
	m_ClickInfo.iX = m_tInfo.iX + 60;
	m_ClickInfo.iY = m_tInfo.iY + 10;
	ClickRect();
	CObj::Update();
	return 0;
}
void CItem::Render(HDC hdc)
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
void CItem::Release()
{

}
void CItem::ClickRect()
{
	m_ClickRect.left = m_ClickInfo.iX - m_ClickInfo.iCX / 2;
	m_ClickRect.top = m_ClickInfo.iY - m_ClickInfo.iCY / 2;
	m_ClickRect.right = m_ClickInfo.iX + m_ClickInfo.iCX / 2;
	m_ClickRect.bottom = m_ClickInfo.iY + m_ClickInfo.iCY / 2;
}