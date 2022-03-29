#pragma once

class CMyBitmap
{
	HDC m_hdc;
	HDC m_memDC;

	HBITMAP m_Bitmap;
	HBITMAP m_OldBitmap;
private:
	BITMAP bitmap;
public:
	CMyBitmap(void);
	~CMyBitmap(void);
public:
	HDC GetMemDC() { return m_memDC; }

public:
	CMyBitmap* LoadBmp(TCHAR* pFilePath);
	void Release();
};
