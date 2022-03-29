#pragma once

class CScene
{
protected:
	bool FirstCreate;
public:
	CScene(void);
	virtual ~CScene(void);

public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;
	virtual void Release() = 0;
};
