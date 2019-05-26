#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = NULL; }

#define DECLARE_SINGLE(Type) \
private: \
static Type* m_pInst; \
public: \
static Type* GetInst()\
{\
if(!m_pInst) m_pInst = new Type; \
return m_pInst; \
}\
static void DestroyInst()\
{\
SAFE_DELETE(m_pInst); \
}\
private: \
Type(); \
~Type();

#define DEFINITION_SINGLE(Type) Type* Type::m_pInst = NULL
#define GET_SINGLE(Type) Type::GetInst()
#define DESTROY_SINGLE(Type) Type::DestroyInst()

#define PI 3.141592f
#define UI_WIDTH 250

#define RS_WIDTH 800
#define RS_HEIGHT 600

#define FULL_WIDTH 4000


#define ITEM_LIMIT_TIME 1.f



#define KEYDOWN(Key) CInput::GetInst()->KeyDown(Key)
#define KEYPRESS(Key) CInput::GetInst()->KeyPress(Key)
#define KEYUP(Key) CInput::GetInst()->KeyUp(Key)

#define SPEED 200.f

#define INFORM_WIDTH 700
#define INFORM_HEIGHT 500


#define POS1 POSITION(0.f, 100.f)
#define POS2 POSITION(0.f, 50.f)
#define POS3 POSITION(FULL_WIDTH, 100.f)
#define POS4 POSITION(FULL_WIDTH, 50.f)


#define FIND_OBJECT(Type) CCreateManager::GetInst()->FindObj(Type)
#define FIND_LAYER(Type) CCreateManager::GetInst()->FindLayer(Type)


template<typename T>
void Safe_Delete_VecList(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(*iter);
	}

	p.clear();
}


template<typename T>
void Safe_Delete_Map(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}

	p.clear();
}