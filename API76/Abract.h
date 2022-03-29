#pragma once

class CObj;

template <typename T>
class CAbstract
{
public:
	static CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->initirize();

		return pObj;
	}

	static CObj* CreateObj(int iX, int iY)
	{
		CObj* pObj = new T;
		pObj->SetPos(iX, iY);
		pObj->initirize();

		return pObj;
	}
	static CObj* CreateObj(int iX, int iY, bool IsRight)
	{
		CObj* pObj = new T;
		pObj->SetPos(iX, iY);
		pObj->SetIsRight(IsRight);
		pObj->initirize();
		return pObj;
	}
	static CObj* CreateObj(int iX, int iY, TCHAR* _pFramekey)
	{
		CObj* pObj = new T;
		pObj->SetPos(iX, iY);
		pObj->SetFrameKey(_pFramekey);
		pObj->initirize();
		return pObj;
	}
	static CObj* CreateObj(int iX, int iY, int iCX, int iCY, TCHAR* _pFramekey)
	{
		CObj* pObj = new T;
		pObj->SetPos(iX, iY);
		pObj->SetSize(iCX, iCY);
		pObj->SetFrameKey(_pFramekey);
		pObj->initirize();
		return pObj;
	}
	static CObj* CreateObj(int iX, int iY, TCHAR* _pFramekey, int iScene)
	{
		CObj* pObj = new T;
		pObj->SetPos(iX, iY);
		pObj->SetFrameKey(_pFramekey);
		pObj->SetScene(iScene);
		pObj->initirize();
		return pObj;
	}
};