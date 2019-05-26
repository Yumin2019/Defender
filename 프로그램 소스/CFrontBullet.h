#pragma once
#include "CBullet.h"
class CFrontBullet :
	public CBullet
{
public:
	CFrontBullet();
	CFrontBullet(const CFrontBullet& bullet);
	 ~CFrontBullet();

private:
	float m_fPowerX;
	float m_fPowerY;
	float m_fPower;

public:

	float GetPower() const;
	float GetPowerX() const;
	float GetPowerY() const;

	void SetPower(float fPower, float fPowerX, float fPowerY);

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CFrontBullet* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

