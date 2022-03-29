#include "StdAfx.h"
#include "Dungeon2.h"
#include "Mouse.h"
#include "Player.h"
#include "DGDoor.h"
#include "Monster1.h"
#include "Monster2.h"

CDungeon2::CDungeon2(void)
{
}

CDungeon2::~CDungeon2(void)
{
	Release();
}
void CDungeon2::Initialize()
{
	g_iScrollX += 1195;
	CBmpMgr::GetInstance()->LoadByScene(DG2);
	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(150, 590);
	CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();
	CObjMgr::GetInstance()->AddObject(new CDGDoor(L"Door_L", 50, 500), DOOR);
	CObjMgr::GetInstance()->AddObject(new CDGDoor(L"Door_R", 2350, 500), DOOR);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMouse>::CreateObj(), MOUSE);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster1>::CreateObj(800, 700), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster2>::CreateObj(400, 600), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster2>::CreateObj(1500, 600), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster1>::CreateObj(1200, 600), MONSTER);
	CTileMgr::GetInstance()->LoadData(L"../Data/reshipon2.dat");
	CSoundMgr::GetInstance()->PlayBGM(L"amb_darkstage_01.ogg", CSoundMgr::Channel_BGM);
}
int CDungeon2::Update()
{	
	CCollisionMgr::CollisionRect(&(CObjMgr::GetInstance()->GetList(MONSTER)), &(CObjMgr::GetInstance()->GetList(PLAYER)));
	//CCollisionMgr::Collisionmonster(CObjMgr::GetInstance()->GetObj(MONSTER), CTileMgr::GetInstance()->GetVecTile());
	CCollisionMgr::CollisionSkill(&(CObjMgr::GetInstance()->GetList(SKILL)), &(CObjMgr::GetInstance()->GetList(MONSTER)));
	CTileMgr::GetInstance()->Update();
	CCollisionMgr::Collisionthreetail(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile(), DGSel, DG2, Boss);
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}
void CDungeon2::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"reshipon2"))->GetMemDC();

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, 0, SRCCOPY);

	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CDungeon2::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(MOUSE);
	CObjMgr::GetInstance()->ReleaseObj(DOOR);
	CObjMgr::GetInstance()->ReleaseObj(SKILL);
	CObjMgr::GetInstance()->ReleaseObj(MONSTER);
	CTileMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);
}