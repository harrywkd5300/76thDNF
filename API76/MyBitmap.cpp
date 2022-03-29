#include "StdAfx.h"
#include "MyBitmap.h"

CMyBitmap::CMyBitmap(void)
{
}

CMyBitmap::~CMyBitmap(void)
{
	Release();
}

CMyBitmap* CMyBitmap::LoadBmp(TCHAR* pFilePath)
{
	m_hdc = GetDC(g_hWnd);
	m_memDC = CreateCompatibleDC(m_hdc);

	m_Bitmap = (HBITMAP)LoadImage(NULL, pFilePath, IMAGE_BITMAP, 0, 0
		, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GetObject(m_Bitmap, sizeof(BITMAP),&bitmap);

	if(NULL == m_Bitmap)
	{
		MessageBox(g_hWnd, pFilePath, L"Load Image Fail!!", MB_OK);
		return NULL;
	}
	m_OldBitmap = (HBITMAP)SelectObject(m_memDC, m_Bitmap);

	ReleaseDC(g_hWnd, m_hdc);

	return this;
}
void CMyBitmap::Release()
{
	SelectObject(m_memDC, m_OldBitmap); 
	DeleteObject(m_Bitmap);
	DeleteDC(m_memDC);
}