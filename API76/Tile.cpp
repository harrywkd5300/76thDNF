#include "StdAfx.h"
#include "Tile.h"

CTile::CTile(void)
:m_iDrawID(0), m_iOption(0)
{
}

CTile::~CTile(void)
{
	Release();
}
void CTile::initirize()
{
	m_tInfo.iCX = TILECX;
	m_tInfo.iCY = TILECY;
}

int CTile::Update()
{
	CObj::Update();
	return 0;
}

void CTile::Render(HDC hdc)
{
	HDC hMemDC;
	if(m_iDrawID == 1)
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileDoorOff"))->GetMemDC();
	else if(m_iDrawID == 2)
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileDoorOn"))->GetMemDC();
	else if(m_iDrawID == 3)
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileTrue"))->GetMemDC();
	else
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileFalse"))->GetMemDC();

	if(m_iDrawID > 4)
		m_iDrawID = 0;

	TransparentBlt(hdc, m_tRect.left + g_iScrollX, m_tRect.top + g_iScrollY, m_tInfo.iCX, m_tInfo.iCY
		, hMemDC, 0, 0
		, m_tInfo.iCX, m_tInfo.iCY, RGB(255, 255, 255));	
}

void CTile::Release()
{
}
