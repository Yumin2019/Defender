#pragma once
#include "CObj.h"
class CStaticObj :
	public CObj
{
public:
	CStaticObj();
	CStaticObj(const CStaticObj& obj);
	virtual ~CStaticObj();



public:

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CStaticObj* Clone() = 0;
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest) = 0;

};

