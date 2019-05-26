#pragma once
#include "CMoveObj.h"
class CBullet :
	public CMoveObj
{
public:
	CBullet();
	CBullet(const CBullet& bullet);
	virtual ~CBullet();


protected:

	float m_fHeartTime;
	float m_fHeartLimitTime;


	int m_iDamage;


	float m_fSecond;
	float m_fSecondLimitTime;



public:

	void SetHeartTime(float fTime);

	void SetDamage(int damage);

	int GetDamage() const;

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CBullet* Clone() = 0;
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

