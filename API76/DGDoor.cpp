#include "StdAfx.h"
#include "DGDoor.h"

CDGDoor::CDGDoor(void)
{
}
CDGDoor::CDGDoor(TCHAR* pFrameKey, int iX, int iY)
:m_pFrameKey(pFrameKey)
{
	m_tInfo.iX = iX;
	m_tInfo.iY = iY;
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 200;
	m_iFrame = 0;
}
CDGDoor::~CDGDoor(void)
{
	Release();
}
void CDGDoor::initirize()
{
}
int CDGDoor::Update()
{
	vector<CObj*>::iterator iter_begin = CTileMgr::GetInstance()->GetVecTile()->begin();
	vector<CObj*>::iterator iter_end = CTileMgr::GetInstance()->GetVecTile()->end();
	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID()==2)
		{
			m_iFrame = 1;
			break;
		}
		else
		{
			m_iFrame = 0;
		}
	}
	CObj::Update();
	return 0;
}
void CDGDoor::Render(HDC hDC)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->GetMapbit()[m_pFrameKey])->GetMemDC();

	TransparentBlt(hDC, m_tRect.left+g_iScrollX , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, 
		hmemDC, m_iFrame * 100, 0, 100 , 200, RGB(255,0,255));
}
void CDGDoor::Release()
{

}