#include "StdAfx.h"
#include "Dungeon1.h"
#include "Mouse.h"
#include "Player.h"
#include "DGDoor.h"
#include "Monster1.h"
#include "Monster2.h"

CDungeon1::CDungeon1(void)
{
}

CDungeon1::~CDungeon1(void)
{
	Release();
}
void CDungeon1::Initialize()
{
	g_iScrollX = 0;
	CBmpMgr::GetInstance()->LoadByScene(DG1);
	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(125, 580);
	CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();
	CObjMgr::GetInstance()->AddObject(new CDGDoor(L"Door_L", 50, 500), DOOR);
	CObjMgr::GetInstance()->AddObject(new CDGDoor(L"Door_R", 2350, 500), DOOR);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMouse>::CreateObj(), MOUSE);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster1>::CreateObj(800, 500), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster2>::CreateObj(500, 500), MONSTER);
	//CObjMgr::GetInstance()->AddObject(CAbstract<CMonster2>::CreateObj(1300, 600), MONSTER);
	CTileMgr::GetInstance()->LoadData(L"../Data/reshipon0.dat");
	CSoundMgr::GetInstance()->PlayBGM(L"amb_darkstage_01.ogg", CSoundMgr::Channel_BGM);
}
int CDungeon1::Update()
{
	CCollisionMgr::Collisionthreetail(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile(), DGSel, DG2, DG2);
	CCollisionMgr::CollisionRect(&(CObjMgr::GetInstance()->GetList(MONSTER)), &(CObjMgr::GetInstance()->GetList(PLAYER)));
	CCollisionMgr::CollisionSkill(&(CObjMgr::GetInstance()->GetList(SKILL)), &(CObjMgr::GetInstance()->GetList(MONSTER)));
	CTileMgr::GetInstance()->Update();
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}
void CDungeon1::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"reshipon1"))->GetMemDC();

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, 0, SRCCOPY);

	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CDungeon1::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(MOUSE);
	CObjMgr::GetInstance()->ReleaseObj(DOOR);
	CObjMgr::GetInstance()->ReleaseObj(SKILL);
	CObjMgr::GetInstance()->ReleaseObj(MONSTER);
	CTileMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);
}