#include "CEffect.h"
#include "CCore.h"
#include "CScene.h"

CEffect::CEffect()
{
	m_tOffset = POSITION(0.f, 0.f);

	m_pObj = NULL;
}

CEffect::CEffect(const CEffect & effect) :
	CUI(effect)
{
	m_tOffset = effect.m_tOffset;

	m_pObj = NULL;
}


CEffect::~CEffect()
{
}

void CEffect::SetTarget(CObj * pTarget)
{
	m_pObj = pTarget;
}

void CEffect::SetOffset(POSITION tPos)
{
	m_tOffset = tPos;
}

void CEffect::Input(float fDeltaTime)
{
	CUI::Input(fDeltaTime);
}

void CEffect::Collision(float fDeltaTime)
{
	CUI::Collision(fDeltaTime);

}

void CEffect::Update(float fDeltaTime)
{

	if (m_pObj)
	{
		m_tPos = m_pObj->GetPos() + m_tOffset;
	}

	CUI::Update(fDeltaTime);


}

void CEffect::Render(float fDeltaTime)
{

	
	//CUI::Render(fDeltaTime);


	D3DXVECTOR3 tCenter = { 0.f, 0.f, 0.f };
	D3DXVECTOR3 tPos = { m_tPos.x - CScene::l, m_tPos.y, 0.f };


	CCore::m_pSprite->Draw(m_pTexture, &m_tRenderRect, &tCenter, &tPos, 0xffffffff);

}

CEffect * CEffect::Clone()
{
	return new CEffect(*this);
}

void CEffect::HitStart(CCollider * pSrc, CCollider * pDest)
{
}

void CEffect::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CEffect::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
