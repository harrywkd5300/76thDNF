#include "StdAfx.h"
#include "Uimgr.h"
#include "Shop.h"

IMPLEMENT_SINGLETON(CUimgr)
CUimgr::CUimgr(void)
{
}

CUimgr::~CUimgr(void)
{
	Release();;
}
void CUimgr::SetUi(UitName pUiname, int PlayerX, int PlayerY)
{
	switch(pUiname)
	{
	case shop:
		CObjMgr::GetInstance()->AddObject(CAbstract<CShop>::CreateObj(PlayerX ,PlayerY), SHOP);
		break;
	}
}
void CUimgr::Update()
{

}
void CUimgr::Render(HDC hdc)
{

}
void CUimgr::Release()
{
	CObjMgr::GetInstance()->DestroyInstance();
}