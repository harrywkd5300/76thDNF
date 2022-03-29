#pragma once

#include "Tile.h"
class CTileMgr
{
	DECLARE_SINGLETON(CTileMgr)
	vector<CObj*>	m_vecTile;;
	int MaxSize;
public:
	CTileMgr(void);
	~CTileMgr(void);

public:
	void AddTile(CObj* pTile);
	void Update();
	void Render(HDC hDC);
	void Relaese();

public:
	void LoadData(TCHAR* pTilename);
	void SaveData();
	void Scroll();

public:
	vector<CObj*>* GetVecTile() { return &m_vecTile; }
};
