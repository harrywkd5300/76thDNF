#pragma once

class CKeyMgr
{
	DECLARE_SINGLETON(CKeyMgr)
private:
	DWORD m_dwKey;
public:
	CKeyMgr(void);
	~CKeyMgr(void);

public:
	DWORD Getkey() { return m_dwKey; }
	void KeyCheck();
};
