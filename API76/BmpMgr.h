#pragma once

#include "MyBitmap.h"

class CBmpMgr
{
	DECLARE_SINGLETON(CBmpMgr)
	map<const TCHAR*, CMyBitmap*> m_Mapbit;
private:
	CBmpMgr(void);
	~CBmpMgr(void);

public:
	void LoadByScene(Scene eScene);

public:
	CMyBitmap* FindBmp(const TCHAR* pFindKey);

public:
	map<const TCHAR*, CMyBitmap*>& GetMapbit() {  return m_Mapbit; }
	void Release();


};
