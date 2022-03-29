// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C�� ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iostream>
//#include <vld.h>
#include <io.h>

#pragma comment(lib, "msimg32.lib")
#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

// fmod Ȱ������ ����� ���̺귯�� �߰�.
#include "fmod.h"
#include "fmod.hpp"
#pragma comment(lib, "fmodex_vc.lib")

using namespace std;

#include "Include.h"
#include "Abract.h"
#include "ObjMgr.h"
#include "Collision.h"
#include "MathMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "TileMgr.h"
#include "CSkillMgr.h"
#include "EffectMgr.h"
#include "Uimgr.h"
#include "SoundMgr.h"

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
