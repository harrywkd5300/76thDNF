#pragma once

#define WINCX 1200
#define WINCY 800

#define PI 3.14f
#define GRAVITY 9.8f

#define TILEX 30
#define TILEY 20

#define TILECX 40
#define TILECY 40

#define DESTROYOBJ 1
#define SCENECHANGE 2

#define KEYPRESS(DST, SRC) (DST & SRC)

#define DECLARE_SINGLETON(ClassName)	\
public:									\
	static ClassName* GetInstance()		\
	{									\
		if(NULL == m_pInstance)			\
			m_pInstance = new ClassName;\
		return m_pInstance;				\
	}									\
	void DestroyInstance()				\
	{									\
		if(m_pInstance)					\
		{								\
			delete m_pInstance;			\
			m_pInstance = NULL;			\
		}								\
	}									\
private:								\
	static ClassName* m_pInstance;


#define IMPLEMENT_SINGLETON(ClassName)	\
ClassName* ClassName::m_pInstance = NULL;