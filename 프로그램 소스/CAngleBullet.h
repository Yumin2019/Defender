#pragma once
#include "CBullet.h"
class CAngleBullet :
	public CBullet
{
public:
	CAngleBullet();
	CAngleBullet(const CAngleBullet& bullet);
	~CAngleBullet();


private:
	bool m_bHomingMissile;



	void AngleUpdate();

public:


	void SetHoming();


	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CAngleBullet* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

