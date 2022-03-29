#include "StdAfx.h"
#include "Stage.h"
#include "Mouse.h"
#include "Player.h"
#include "Uibase.h"
#include "Npc.h"

CStage::CStage(void)
{
}

CStage::~CStage(void)
{
	Release();
}
void CStage::Initialize()
{
	CBmpMgr::GetInstance()->LoadByScene(Stage);
	if(FirstCreate==true)
	{
		CObjMgr::GetInstance()->AddObject(CAbstract<CPlayer>::CreateObj(614, 668), PLAYER);
		FirstCreate = false;
	}
	else
	{
		CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(550 , 650);
		CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();
	}
	CObjMgr::GetInstance()->AddObject(CAbstract<CMouse>::CreateObj(), MOUSE);
	CObjMgr::GetInstance()->AddObject(CAbstract<CUibase>::CreateObj(), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CNpc>::CreateObj(600, 480,56,110,L"Seria"), NPC);
	CTileMgr::GetInstance()->LoadData(L"../Data/SeriaRoom.dat");
	//CSoundMgr::GetInstance()->PlayBGM(L"amb_darkstage_01.ogg", CSoundMgr::Channel_BGM);
}

int CStage::Update()
{
	CCollisionMgr::Collisiontail(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile(), stage2);
	CTileMgr::GetInstance()->Update();
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}

void CStage::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"SeriaRoom"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}

void CStage::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(MOUSE);
	CObjMgr::GetInstance()->ReleaseObj(NPC);
	CTileMgr::GetInstance()->DestroyInstance();
}
