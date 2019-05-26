#pragma once
#include "CStaticObj.h"
class CObstacle :
	public CStaticObj
{
public:
	CObstacle();
	CObstacle(const CObstacle& obs);
	~CObstacle();



public:

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CObstacle* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

