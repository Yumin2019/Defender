#include "CFrontBullet.h"



CFrontBullet::CFrontBullet()
{
}

CFrontBullet::CFrontBullet(const CFrontBullet & bullet) :
	CBullet(bullet)
{
	m_fPowerX = bullet.m_fPowerX;
	m_fPowerY = bullet.m_fPowerY;
	m_fPower = bullet.m_fPower;
}


CFrontBullet::~CFrontBullet()
{
}

float CFrontBullet::GetPower() const
{
	return m_fPower;
}

float CFrontBullet::GetPowerX() const
{
	return m_fPowerX;
}

float CFrontBullet::GetPowerY() const
{
	return m_fPowerY;
}

void CFrontBullet::SetPower(float fPower, float fPowerX, float fPowerY)
{
	m_fPower = fPower;
	m_fPowerX = fPowerX;
	m_fPowerY = fPowerY;
}

void CFrontBullet::Input(float fDeltaTime)
{
	CBullet::Input(fDeltaTime);
}

void CFrontBullet::Collision(float fDeltaTime)
{
	CBullet::Collision(fDeltaTime);

}

void CFrontBullet::Update(float fDeltaTime)
{
	CBullet::Update(fDeltaTime);



	m_fSecond += fDeltaTime;

	if (m_fSecond >= 0.1f)
	{
		m_fSecond -= 0.1f;

		m_fPower -= 20.f;
	}


	if(m_fPower + m_fPowerX > 0.f)
	MoveX(fDeltaTime, m_fPower + m_fPowerX, m_eDirX);


	if(m_fPower + m_fPowerY > 0.f)
	MoveY(fDeltaTime, m_fPower + m_fPowerY, MD_LEFT);
	
}

void CFrontBullet::Render(float fDeltaTime)
{
	CBullet::Render(fDeltaTime);

}

CFrontBullet * CFrontBullet::Clone()
{
	return new CFrontBullet(*this);
}

void CFrontBullet::HitStart(CCollider * pSrc, CCollider * pDest)
{
	CBullet::HitStart(pSrc, pDest);
}

void CFrontBullet::HitStay(CCollider * pSrc, CCollider * pDest)
{
	CBullet::HitStay(pSrc, pDest);

}

void CFrontBullet::HitEnd(CCollider * pSrc, CCollider * pDest)
{
	CBullet::HitEnd(pSrc, pDest);

}
