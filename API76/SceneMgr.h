#pragma once

class CScene;
class CSceneMgr
{
private:
	DECLARE_SINGLETON(CSceneMgr)
	CScene* m_pScene;
	Scene	m_eCurScene;
	int MaxWidth;
public:
	CSceneMgr(void);
	~CSceneMgr(void);

public:
	void SetScene(Scene eType);
	int GetMaxWidth() { return MaxWidth; }
public:
	Scene GetCurScene() { return m_eCurScene; }
public:
	void Update();
	void Render(HDC hdc);
	void Release();
};
