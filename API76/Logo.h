#pragma once
#include "scene.h"

class CLogo :
	public CScene
{
public:
	CLogo(void);
	virtual ~CLogo(void);
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
private:
	HWND	m_hVideo; // ������ ����� �ϱ����� ������â �ڵ�.
};
