#pragma once

typedef struct tagInfo
{
	int iX;
	int iY;
	int iCX;
	int iCY;
}INFO;

typedef struct tagFrame
{
	int iFrameStart;
	int iFrameEnd;
	int iScene;

	DWORD dwFrameOld;
	DWORD dwFrameSpd;
}FRAME;