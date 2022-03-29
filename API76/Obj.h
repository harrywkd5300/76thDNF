#pragma once

class CObj
{
protected:
	TCHAR* m_pFrameKey;
	INFO m_tInfo;
	RECT m_tRect;
	FRAME m_tFrame;

	int m_iAtk;
	int m_iHp;
	int m_iMp;

	int ReStartFrame;
	bool SkillStart;
	bool thunderBOOL;
	int iSkill1Count;
	//bool bSkillCoolTime;

	bool m_bisDead;
	bool m_bIsMove;
	bool m_bIsRigth;
	int m_iSpeed;

	RenderID	m_eRenderID;
	float m_fz;
public:
	bool bSkillCoolTime1;
	bool bSkillCoolTime2;
	bool bSkillCoolTime3;
	bool bSkillCoolTime4;
	bool bSkillCoolTime5;
	bool bSkillCoolTime6;
	int m_iMaxHp;
	int iHpPer;
public:
	CObj(void);
	virtual ~CObj(void);
public:
	ItemState itemstat;
	bool m_bIsHitTime;
	bool m_bIshit;
	INFO& GetInfo() { return m_tInfo; }
	RECT& GetRect() { return m_tRect; }
	FRAME& GetFrame() { return m_tFrame; }
	void SetInfo(INFO& rInfo) { m_tInfo = rInfo; }
public:
	virtual void initirize() = 0;
	virtual int Update();
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;
public:
	void FrameMove();
	void MonsterFrameMove();
	void SkillFrameMove();
public:
	void Setfz(float _fz) { m_fz = _fz;  }
	float Getfz() { return m_fz; }
public:
	void SetPos(int iX, int iY) {  m_tInfo.iX = iX, m_tInfo.iY = iY; }
	void SetSize(int iX, int iY) {  m_tInfo.iCX = iX, m_tInfo.iCY = iY; }
	void IsDead() { m_bisDead = true; }
	void SetState(bool MoveEnd) { m_bIsMove=MoveEnd; }
	void SetIsRight(bool isright) { m_bIsRigth= isright; }
	void SetIsHitting() { m_bIshit = true; }
	void SetiHp(int iAtk) { m_iHp -= iAtk; }
	void SetScene(int iWantScene) { m_tFrame.iScene = iWantScene; }
	void SetFrameKey(TCHAR* selFrameKey) { m_pFrameKey = selFrameKey; }
public:
	bool GetIsRight() { return m_bIsRigth; }
	bool GetSkillEnd() { return SkillStart; }
	bool GetState() { return m_bIsMove; }
	bool GetDeadState() { return m_bisDead; }
	bool GethitState() { return m_bIshit; }
public:
	int GetSkillCount() { return iSkill1Count; }
	int GetIAtk() { return m_iAtk; }
	int GetIHp()  { return m_iHp; }
	TCHAR* GetFrameKey() {  return m_pFrameKey;  }
	RenderID GetRenderType() { return m_eRenderID; }
};
