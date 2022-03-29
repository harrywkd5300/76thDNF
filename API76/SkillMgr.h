#pragma once

class CSkillMgr
{
	static CSkillMgr* m_pInstance;

public:
	CSkillMgr(void);
	~CSkillMgr(void);
public:
	static CBmpMgr* GetInstance()
	{
		if(NULL == m_pInstance)
			m_pInstance = new CBmpMgr;
		return m_pInstance;
	}
	void DestroyInstance()
	{
		if(m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
};
