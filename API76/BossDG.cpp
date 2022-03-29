#include "StdAfx.h"
#include "BossDG.h"
#include "Player.h"
#include "DGDoor.h"
#include "Mouse.h"
#include "Boss.h"

CBossDG::CBossDG(void)
{
}

CBossDG::~CBossDG(void)
{
	Release();
}
void CBossDG::Initialize()
{
	g_iScrollX += 1195;
	CBmpMgr::GetInstance()->LoadByScene(DG2);
	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(100, 550);
	CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();
	CObjMgr::GetInstance()->AddObject(new CDGDoor(L"Door_L", 50, 500), DOOR);
	CObjMgr::GetInstance()->AddObject(CAbstract<CBoss>::CreateObj(1200, 550), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMouse>::CreateObj(), MOUSE);
	CTileMgr::GetInstance()->LoadData(L"../Data/reshipon0.dat");
	CSoundMgr::GetInstance()->PlayBGM(L"amb_darkstage_01.ogg", CSoundMgr::Channel_BGM);
}
int CBossDG::Update()
{	
	CCollisionMgr::Collisiontail(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile(), DG2);
	CCollisionMgr::CollisionRect(&(CObjMgr::GetInstance()->GetList(MONSTER)), &(CObjMgr::GetInstance()->GetList(PLAYER)));
	CCollisionMgr::CollisionSkill(&(CObjMgr::GetInstance()->GetList(SKILL)), &(CObjMgr::GetInstance()->GetList(MONSTER)));
	CTileMgr::GetInstance()->Update();	
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}
void CBossDG::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"reshipon1"))->GetMemDC();

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, 0, SRCCOPY);

	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CBossDG::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(MOUSE);
	CObjMgr::GetInstance()->ReleaseObj(DOOR);
	CObjMgr::GetInstance()->ReleaseObj(SKILL);
	CObjMgr::GetInstance()->ReleaseObj(MONSTER);
	CTileMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);
}