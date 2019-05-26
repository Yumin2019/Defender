#include "CDoor.h"
#include "CPlayer.h"
#include "CSceneManager.h"
#include "CInGame2.h"


CDoor::CDoor()
{
}

CDoor::CDoor(const CDoor & door) :
	CStaticObj(door)
{
}


CDoor::~CDoor()
{
}

void CDoor::Input(float fDeltaTime)
{
	CStaticObj::Input(fDeltaTime);
}

void CDoor::Collision(float fDeltaTime)
{
	CStaticObj::Collision(fDeltaTime);

}

void CDoor::Update(float fDeltaTime)
{
	CStaticObj::Update(fDeltaTime);

}

void CDoor::Render(float fDeltaTime)
{
	CStaticObj::Render(fDeltaTime);

}

CDoor * CDoor::Clone()
{
	return new CDoor(*this);
}

void CDoor::HitStart(CCollider * pSrc, CCollider * pDest)
{
	switch (GET_SINGLE(CSceneManager)->GetScene())
	{
	case S_INGAME1:

		GET_SINGLE(CSceneManager)->InGame2();

		break;

	case S_INGAME2:


		CInGame2::m_bClear = true;

		GET_SINGLE(CSceneManager)->EndScene();

		break;

	}
}

void CDoor::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CDoor::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
