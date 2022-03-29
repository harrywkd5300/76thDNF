#include "StdAfx.h"
#include "SceneMgr.h"
#include "Stage.h"
#include "Stage2.h"
#include "MyMenu.h"
#include "MyEdit.h"
#include "DGSelect.h"
#include "Dungeon1.h"
#include "Dungeon2.h"
#include "BossDG.h"
#include "Logo.h"

IMPLEMENT_SINGLETON(CSceneMgr)

CSceneMgr::CSceneMgr(void)
:m_pScene(NULL)
{
}

CSceneMgr::~CSceneMgr(void)
{
	Release();
}
void CSceneMgr::SetScene(Scene eType)
{
	MaxWidth = 1;
	if(m_pScene)
		safeDelete<CScene*>(m_pScene);

	switch(eType)
	{
	case Logo:
		m_pScene = new CLogo;
		break;
	case Menu:
		m_pScene = new CMyMenu;
		break;
	case Edit:
		m_pScene = new CMyEdit;
		break;
	case Stage:
		m_pScene = new CStage;
		MaxWidth = 1;
		break;
	case stage2:
		m_pScene = new CStage2;
		MaxWidth = 2;
		break;
	case DGSel:
		m_pScene = new CDGSelect;
		MaxWidth = 1;
		break;
	case DG1:
		m_pScene = new CDungeon1;
		MaxWidth = 2;
		break;
	case DG2:
		m_pScene = new CDungeon2;
		MaxWidth = 2;
		break;
	case Boss:
		m_pScene = new CBossDG;
		MaxWidth = 2;
		break;
	}
	m_pScene->Initialize();
	m_eCurScene = eType;
}

void CSceneMgr::Update()
{
	m_pScene->Update();
}
void CSceneMgr::Render(HDC hdc)
{
	m_pScene->Render(hdc);
}

void CSceneMgr::Release()
{
	safeDelete<CScene*>(m_pScene);
}