#include "StdAfx.h"
#include "MyEdit.h"
#include "Mouse.h"

CMyEdit::CMyEdit(void)
:MaxSize(1)
{
}

CMyEdit::~CMyEdit(void)
{
	CTileMgr::GetInstance()->SaveData();
	Release();
}

void CMyEdit::Initialize()
{
	CBmpMgr::GetInstance()->LoadByScene(Edit);
	MaxSize = 2;
	
	int iX = 0, iY = 0;

	for(int i = 0; i < TILEY; ++i)
	{
		for(int j = 0; j < TILEX * MaxSize ; ++j)
		{
			iX = TILECX * j + TILECX / 2;
			iY = TILECY * i + TILECY / 2;
			
			CTileMgr::GetInstance()->AddTile(CAbstract<CTile>::CreateObj(iX, iY));
		}
	}

}

int CMyEdit::Update()
{
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();

	static bool Flag = FALSE;


	if(KEYPRESS(dwKey, KEY_LBUTTON))
	{
		if(Flag == FALSE)
		{
			Picking();
			Flag = TRUE;
		}
	}
	else
	{
		Flag = FALSE;
	}

	if(KEYPRESS(dwKey, KEY_LEFT))
		g_iScrollX += 10;
	if(KEYPRESS(dwKey, KEY_RIGHT))
		g_iScrollX -= 10;

	CTileMgr::GetInstance()->Update();	

	return 0;
}

void CMyEdit::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"reshipon2"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, 0, SRCCOPY);
	CTileMgr::GetInstance()->Render(hDC);
}

void CMyEdit::Release()
{
	CBmpMgr::GetInstance()->DestroyInstance();
	CTileMgr::GetInstance()->DestroyInstance();
}

void CMyEdit::Picking()
{
	vector<CObj*>* pVecTile = CTileMgr::GetInstance()->GetVecTile();

	int iX = (CMouse::GetMouse().x - g_iScrollX) / TILECX;
	int iY = (CMouse::GetMouse().y - g_iScrollY) / TILECY;

	// 타일 공식
	int iIndex = iX + (TILEX * iY * MaxSize);

	CTile* pTile = dynamic_cast<CTile*>((*pVecTile)[iIndex]);
	int DrawId = pTile->GetDrawID();
	++DrawId;
	pTile->SetOption(DrawId, 1);
}

//void CMyEdit::Scroll()
//{
//	if(0 < g_iScrollX)
//		g_iScrollX = 0;
//
//	if(WINCX - (TILECX * TILEX) * 2 > g_iScrollX)
//		g_iScrollX = WINCX - (TILECX * TILEX) * 2;
//
//	g_iScrollX += 10; 
//}
//
