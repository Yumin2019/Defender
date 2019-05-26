#include "CStaticObj.h"



CStaticObj::CStaticObj()
{
}

CStaticObj::CStaticObj(const CStaticObj & obj) :
	CObj(obj)
{
}


CStaticObj::~CStaticObj()
{
}

void CStaticObj::Input(float fDeltaTime)
{
	CObj::Input(fDeltaTime);
}

void CStaticObj::Collision(float fDeltaTime)
{
	CObj::Collision(fDeltaTime);

}

void CStaticObj::Update(float fDeltaTime)
{
	CObj::Update(fDeltaTime);

}

void CStaticObj::Render(float fDeltaTime)
{
	CObj::Render(fDeltaTime);

}
