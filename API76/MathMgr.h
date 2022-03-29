#pragma once

class CObj;
class CMathMgr
{
public:
	CMathMgr(void);
	~CMathMgr(void);
public:
	static float CalcDistance(CObj* pObj, CObj* pSrc);
	static float CalcRadian(CObj* pObj, CObj* pSrc);
	static float CalcDegree(CObj* pObj, CObj* pSrc);
};
