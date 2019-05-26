#pragma once
#include "CStaticObj.h"
class CUI :
	public CStaticObj
{
public:
	CUI();
	CUI(const CUI& ui);
	virtual ~CUI();



public:

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CUI* Clone() = 0;
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest) = 0;
};

