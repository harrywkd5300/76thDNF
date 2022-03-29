#include "StdAfx.h"
#include "ObjMgr.h"
#include "Obj.h"

CObjMgr* CObjMgr::m_pInstance = NULL;

CObjMgr::CObjMgr(void)
{
}

CObjMgr::~CObjMgr(void)
{
	ReleaseAll();
}

void CObjMgr::AddObject(CObj* pObj, STATE eID)
{
	m_ObjList[eID].push_back(pObj);
}
void CObjMgr::UpdateObj()
{
	for(int i=0 ; i<END ; ++i)
	{
		OBJITER iter_begin = m_ObjList[i].begin();
		OBJITER iter_end   = m_ObjList[i].end();
		{
			for( ; iter_begin != iter_end ;)
			{
				int iEvent = (*iter_begin)->Update();
				if( DESTROYOBJ == iEvent)
				{
					safeDelete<CObj*>(*iter_begin);
					iter_begin = m_ObjList[i].erase(iter_begin);
				}
				else if( SCENECHANGE == iEvent)
					return;
				else
					++iter_begin;
			}
		}
	}
}
void CObjMgr::RenderObj(HDC hdc)
{
	for(int i=0 ; i<END ; ++i)
	{
		OBJITER iter_begin = m_ObjList[i].begin();
		OBJITER iter_end   = m_ObjList[i].end();
		for(; iter_begin != iter_end; ++iter_begin)
		{
			if(Render_Obj != (*iter_begin)->GetRenderType() && Render_skill != (*iter_begin)->GetRenderType() && 
				Render_Effect != (*iter_begin)->GetRenderType() && Render_UI != (*iter_begin)->GetRenderType())
			{
				(*iter_begin)->Render(hdc);
				continue;
			}
			RenderID eID = (*iter_begin)->GetRenderType();
			m_VecRender[eID].push_back((*iter_begin));
		}
	}

	sort(m_VecRender[Render_Obj].begin(), m_VecRender[Render_Obj].end(), CompareY<CObj*>);

	//_int iSize = m_VecRender[Render_Obj].size();

	//QuickSort(m_VecRender, Render_Obj, 0, iSize);


	for(int i = 0; i < Render_End; ++i)
	{
		for(size_t j = 0; j < m_VecRender[i].size(); ++j)
			(m_VecRender[i][j])->Render(hdc);

		m_VecRender[i].clear();
	}
}
void CObjMgr::ReleaseAll()
{
	for(int i = 0; i < END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), safeDelete<CObj*>);
		m_ObjList[i].clear();
	}	
}

void CObjMgr::ReleaseObj(STATE eID)
{
	for_each(m_ObjList[eID].begin(), m_ObjList[eID].end(), safeDelete<CObj*>);
	m_ObjList[eID].clear();
}
