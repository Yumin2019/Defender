#include "CStage.h"



CStage::CStage()
{
}

CStage::CStage(const CStage & stage) :
	CStaticObj(stage)
{

	m_tPos = POSITION(0.f, 0.f);
}


CStage::~CStage()
{
}

void CStage::Input(float fDeltaTime)
{
}

void CStage::Collision(float fDeltaTime)
{
}

void CStage::Update(float fDeltaTime)
{
}

void CStage::Render(float fDeltaTime)
{
}

CStage * CStage::Clone()
{
	return new CStage(*this);
}

void CStage::HitStart(CCollider * pSrc, CCollider * pDest)
{
}

void CStage::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CStage::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
