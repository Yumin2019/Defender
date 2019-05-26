#pragma once
#include "CUI.h"

class CEffect :
	public CUI
{
public:
	CEffect();
	CEffect(const CEffect& effect);
	~CEffect();


private:
	POSITION m_tOffset;
	class CObj* m_pObj;

public:


	void SetTarget(class CObj* pTarget);
	void SetOffset(POSITION tPos);


	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CEffect* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

