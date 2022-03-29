#include "StdAfx.h"
#include "Maps.h"

CMaps::CMaps(void)
{
}

CMaps::~CMaps(void)
{
	Release();
}

void CMaps::initirize()
{
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"SeriaRoom", (new CMyBitmap)->LoadBmp(L"../image/map/SeriaRoom.bmp")));
}
int CMaps::Update()
{
	return 0;
}
void CMaps::Render(HDC hdc)
{
	HDC MemDC = (CBmpMgr::GetInstance()->GetMapbit()[L"SeriaRoom"])->GetMemDC();
	BitBlt(hdc, 0, 0, WINCX, WINCY, MemDC, 0, 0, SRCCOPY);
}
void CMaps::Release()
{

}