#include "CCheck.h"
#include "CSceneManager.h"
#include "CPlayer.h"


CCheck::CCheck()
{
}

CCheck::CCheck(const CCheck & check) :
	CStaticObj(check)
{
}


CCheck::~CCheck()
{
}

void CCheck::Input(float fDeltaTime)
{
	CStaticObj::Input(fDeltaTime);
}

void CCheck::Collision(float fDeltaTime)
{
	CStaticObj::Collision(fDeltaTime);

}

void CCheck::Update(float fDeltaTime)
{
	CStaticObj::Update(fDeltaTime);

}

void CCheck::Render(float fDeltaTime)
{
	CStaticObj::Render(fDeltaTime);

}

CCheck * CCheck::Clone()
{
	return new CCheck(*this);
}

void CCheck::HitStart(CCollider * pSrc, CCollider * pDest)
{

	
		GET_SINGLE(CSceneManager)->GetPlayer()->SetCheck(POSITION(GetCenterX(), GetCenterY() - 20.f));


		m_bEnable = false;

}

void CCheck::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CCheck::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
