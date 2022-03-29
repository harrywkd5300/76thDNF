#include "StdAfx.h"
#include "Stage2.h"
#include "Mouse.h"
#include "Player.h"


CStage2::CStage2(void)
{

}

CStage2::~CStage2(void)
{
	Release();
}
void CStage2::Initialize()
{
	g_iScrollX -= 500;
	CBmpMgr::GetInstance()->LoadByScene(stage2);
	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(1300 , 500);
	CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();
	CObjMgr::GetInstance()->AddObject(CAbstract<CMouse>::CreateObj(), MOUSE);
	CTileMgr::GetInstance()->LoadData(L"../Data/village.dat");
	CSoundMgr::GetInstance()->PlayBGM(L"amb_tenth_forest.ogg", CSoundMgr::Channel_BGM);
}
int CStage2::Update()
{
	CCollisionMgr::Collisionthreetail(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile(), DGSel, Stage, DGSel);
	CTileMgr::GetInstance()->Update();
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}
void CStage2::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"village"))->GetMemDC();

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, 0, SRCCOPY);

	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CStage2::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(MOUSE);
	CTileMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);
}