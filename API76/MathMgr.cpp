#include "StdAfx.h"
#include "MathMgr.h"
#include "Obj.h"

CMathMgr::CMathMgr(void)
{

}

CMathMgr::~CMathMgr(void)
{

}
float CalcDistance(CObj* pObj, CObj* pSrc)
{
	int iWidth = pObj->GetInfo().iX - pSrc->GetInfo().iX;
	int iHeight = pObj->GetInfo().iY - pSrc->GetInfo().iY;

	return sqrtf(float(iWidth*iWidth + iHeight*iHeight));

}
float CalcRadian(CObj* pObj, CObj* pSrc)
{
	int iWidth = pObj->GetInfo().iX - pSrc->GetInfo().iX;
	int iHeight = pObj->GetInfo().iY - pSrc->GetInfo().iY;
	float fDist = sqrtf(float(iWidth*iWidth + iHeight*iHeight));
	float fAngle = acosf(iWidth / fDist);

	if(pObj->GetInfo().iY > pSrc->GetInfo().iY)
		fAngle *= -1.f;

	return fAngle;
}
float CalcDegree(CObj* pObj, CObj* pSrc)
{
	int iWidth = pObj->GetInfo().iX - pSrc->GetInfo().iX;
	int iHeight = pObj->GetInfo().iY - pSrc->GetInfo().iY;
	float fDist = sqrtf(float(iWidth*iWidth + iHeight*iHeight));
	float fAngle = acosf(iWidth / fDist);

	if(pObj->GetInfo().iY > pSrc->GetInfo().iY)
		fAngle *= -1.f;

	return fAngle * 180.f / PI;
}