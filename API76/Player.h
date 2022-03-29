#pragma once
//#include "Obj.h"

class CPlayer :
	public CObj
{
	float		m_fJumpPow;		
	float		m_fJumpAcc;
	float		m_fJumpY;
	int			m_iHitcount;

	bool		m_bIsJump;
	bool		m_bTileView;
	bool		m_bIsMove;

	DWORD		m_dwTime;
	DWORD		m_dwClick;
	vector<CObj*> m_vInven;
	vector<CObj*> m_vEquipItem;
	bool FirstCreate;


	DWORD Skill1;
	DWORD Skill2;
	DWORD Skill3;
	DWORD Skill4;
	DWORD Skill5;
	DWORD Skill6;

public:
	enum State { Stand, Walk, Dash, DashAttack, Attack, Casting, Casting2, Casting3,  Hit, Jump, Down, End };
	bool        m_bInven;
private:
	State		m_ePreState;
	State		m_eCurState;
public:
	CPlayer(void);
	virtual ~CPlayer(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Release();
	void SetViewINVEN() { m_bInven = false; }
private:
	void StateChange();
	void stateJump();
	void Scroll();
	//void SetItemlist(vector<CObj*>* pItem) { m_vInven = pItem; }
public:
	bool TileView() { return m_bTileView; }
	bool Setplayermove() { m_bIsMove = false; }
public:
	float GetJumpY() { return m_fJumpY; }
	vector<CObj*>& GetInven() { return m_vInven; }
	vector<CObj*>& GetEquipItem() { return m_vEquipItem; }
};
