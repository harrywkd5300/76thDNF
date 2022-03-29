#pragma once

class CObj;
class CObjMgr
{
	static CObjMgr* m_pInstance;
	OBJLIST m_ObjList[END];
	vector<CObj*> m_VecRender[Render_End];
public:
	CObjMgr(void);
	~CObjMgr(void);
public:
	CObj* GetObj(STATE eID) { return m_ObjList[eID].front(); }
	OBJLIST& GetList(STATE eID) { return m_ObjList[eID]; }

public:
	void AddObject(CObj* pObj, STATE eID);
	void UpdateObj();
	void RenderObj(HDC hdc);
	void ReleaseAll();
	void ReleaseObj(STATE eID);

public:
	static CObjMgr* GetInstance()
	{
		if(NULL == m_pInstance)
			m_pInstance = new CObjMgr;
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
