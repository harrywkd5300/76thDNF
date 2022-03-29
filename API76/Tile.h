#pragma once
#include "obj.h"

class CTile :
	public CObj
{
	int	m_iDrawID;
	int m_iOption;
	TCHAR* m_pFrameKey;
public:
	CTile(void);
	virtual ~CTile(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	int GetDrawID() { return m_iDrawID; }
	int GetOption() { return m_iOption; }

public:
	void SetOption(int iDrawID, int iOption)
	{
		m_iDrawID = iDrawID;
		m_iOption = iOption;
	}
	//void SetFrameKey(TCHAR* m_prame) { m_pFrameKey = m_prame; }
};
