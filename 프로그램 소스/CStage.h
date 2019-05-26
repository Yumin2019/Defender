#pragma once
#include "CStaticObj.h"
class CStage :
	public CStaticObj
{
public:
	CStage();
	CStage(const CStage& stage);
	~CStage();



public:

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CStage* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

