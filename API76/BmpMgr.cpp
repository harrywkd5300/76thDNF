#include "StdAfx.h"
#include "BmpMgr.h"

IMPLEMENT_SINGLETON(CBmpMgr)

CBmpMgr::CBmpMgr(void)
{
}

CBmpMgr::~CBmpMgr(void)
{
	Release();
}
void CBmpMgr::LoadByScene(Scene eScene)
{
	switch(eScene)
	{
	case Logo:
		m_Mapbit.insert(
			make_pair(L"Menu", (new CMyBitmap)->LoadBmp(L"../image/etc/Menu.bmp")));
		break;
	case Menu:
		m_Mapbit.insert(
			make_pair(L"Edit", (new CMyBitmap)->LoadBmp(L"../Image/etc/Edit.bmp")));
		m_Mapbit.insert(
			make_pair(L"Exit", (new CMyBitmap)->LoadBmp(L"../Image/etc/Exit.bmp")));
		m_Mapbit.insert(
			make_pair(L"Start", (new CMyBitmap)->LoadBmp(L"../Image/etc/GameStart.bmp")));
		break;
	case Edit:
		m_Mapbit.insert(
			make_pair(L"reshipon2", (new CMyBitmap)->LoadBmp(L"../image/map/reshipon2.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOff", (new CMyBitmap)->LoadBmp(L"../image/tail/TileDoorOff.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOn", (new CMyBitmap)->LoadBmp(L"../image/tail/TileDoorOn.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileFalse", (new CMyBitmap)->LoadBmp(L"../image/tail/TileFalse.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileTrue", (new CMyBitmap)->LoadBmp(L"../image/tail/TileTrue.bmp")));

	case Stage:
		m_Mapbit.insert(
			make_pair(L"SeriaRoom", (new CMyBitmap)->LoadBmp(L"../image/map/SeriaRoom.bmp")));
		m_Mapbit.insert(
			make_pair(L"Seria", (new CMyBitmap)->LoadBmp(L"../image/npc/Seria.bmp")));
		m_Mapbit.insert(
			make_pair(L"player_R", (new CMyBitmap)->LoadBmp(L"../image/player/player_R.bmp")));
		m_Mapbit.insert(
			make_pair(L"player_L", (new CMyBitmap)->LoadBmp(L"../image/player/player_L.bmp")));
		m_Mapbit.insert(
			make_pair(L"Mouse", (new CMyBitmap)->LoadBmp(L"../image/etc/Mouse.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOff", (new CMyBitmap)->LoadBmp(L"../image/tail/TileDoorOff.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOn", (new CMyBitmap)->LoadBmp(L"../image/tail/TileDoorOn.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileFalse", (new CMyBitmap)->LoadBmp(L"../image/tail/TileFalse.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileTrue", (new CMyBitmap)->LoadBmp(L"../image/tail/TileTrue.bmp")));	
		break;
	case stage2:
		m_Mapbit.insert(
			make_pair(L"village", (new CMyBitmap)->LoadBmp(L"../image/map/village.bmp")));
	case DGSel:
		m_Mapbit.insert(
			make_pair(L"DGSelMap", (new CMyBitmap)->LoadBmp(L"../image/map/DGSelMap.bmp")));
		m_Mapbit.insert(
			make_pair(L"DGSelButton", (new CMyBitmap)->LoadBmp(L"../image/map/DGSelButton.bmp")));
		break;
	case DG1:
		m_Mapbit.insert(
			make_pair(L"reshipon1", (new CMyBitmap)->LoadBmp(L"../image/map/reshipon1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Door_L", (new CMyBitmap)->LoadBmp(L"../image/map/Door_L.bmp")));
		m_Mapbit.insert(
			make_pair(L"Door_R", (new CMyBitmap)->LoadBmp(L"../image/map/Door_R.bmp")));
		m_Mapbit.insert(
			make_pair(L"monster1_L", (new CMyBitmap)->LoadBmp(L"../image/monster/monster1_L.bmp")));
		m_Mapbit.insert(
			make_pair(L"monster1_R", (new CMyBitmap)->LoadBmp(L"../image/monster/monster1_R.bmp")));
		m_Mapbit.insert(
			make_pair(L"monster2_L", (new CMyBitmap)->LoadBmp(L"../image/monster/monster2_L.bmp")));
		m_Mapbit.insert(
			make_pair(L"monster2_R", (new CMyBitmap)->LoadBmp(L"../image/monster/monster2_R.bmp")));
		break;
	case DG2:
		m_Mapbit.insert(
			make_pair(L"reshipon2", (new CMyBitmap)->LoadBmp(L"../image/map/reshipon2.bmp")));
	case Boss:
		m_Mapbit.insert(
			make_pair(L"reshipon1", (new CMyBitmap)->LoadBmp(L"../image/map/reshipon1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Door_L", (new CMyBitmap)->LoadBmp(L"../image/map/Door_L.bmp")));
		m_Mapbit.insert(
			make_pair(L"BossOn", (new CMyBitmap)->LoadBmp(L"../image/monster/BossOn.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss_L", (new CMyBitmap)->LoadBmp(L"../image/monster/Boss_L.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss_R", (new CMyBitmap)->LoadBmp(L"../image/monster/Boss_R.bmp")));
	}
}

void CBmpMgr::Release()
{
	map<const TCHAR*, CMyBitmap*>::iterator iter_begin = m_Mapbit.begin();
	map<const TCHAR*, CMyBitmap*>::iterator iter_end = m_Mapbit.end();

	for(; iter_begin != iter_end; ++iter_begin)
		safeDelete<CMyBitmap*>(iter_begin->second);
	m_Mapbit.clear();
}

CMyBitmap* CBmpMgr::FindBmp(const TCHAR* pFindKey)
{
	map<const TCHAR*, CMyBitmap*>::iterator iter_find = find_if(m_Mapbit.begin()
		, m_Mapbit.end(), CStringCmp(pFindKey));

	if(iter_find == m_Mapbit.end())
		return NULL;

	return iter_find->second;
}
