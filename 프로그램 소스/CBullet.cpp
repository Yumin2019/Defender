#include "CBullet.h"
#include "CCollider.h"
#include "CSceneManager.h"
#include "CCreateManager.h"

CBullet::CBullet()
{
	m_fHeartLimitTime = 0.f;
	m_fHeartTime = 0.f;


	m_iDamage = 1;

	m_fSecond = 0.f;
	m_fSecondLimitTime = 0.f;
}

CBullet::CBullet(const CBullet & bullet) :
	CMoveObj(bullet)
{
	m_fHeartLimitTime = bullet.m_fHeartLimitTime;
	m_fHeartTime = 0.f;


	m_iDamage = bullet.m_iDamage;


	m_fSecond = 0.f;
	m_fSecondLimitTime = bullet.m_fSecondLimitTime;
}


CBullet::~CBullet()
{
}

void CBullet::SetHeartTime(float fTime)
{
	m_fHeartLimitTime = fTime;
}

void CBullet::SetDamage(int damage)
{
	m_iDamage = damage;
}

int CBullet::GetDamage() const
{
	return m_iDamage;
}

void CBullet::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);
}

void CBullet::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);

}

void CBullet::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);


	m_fHeartTime += fDeltaTime;

	if (m_fHeartTime >= m_fHeartLimitTime)
	{
		m_bEnable = false;
	}
}

void CBullet::Render(float fDeltaTime)
{
	CMoveObj::Render(fDeltaTime);

}


void CBullet::HitStart(CCollider * pSrc, CCollider * pDest)
{
	

	if (GetSize().x == RS_WIDTH)
	{

		return;
		// 핵탄두 이펙트.
/*
			CObj* pEffect = FIND_OBJECT("EffectA")->Clone();

			GET_SINGLE(CSceneManager)->GetPanelList().push_back(pEffect);*/


			// 주위 몬스터 삭제.
	}


	// 무언가 충돌을 했지만 , rect나 gravity ...

	switch (pSrc->GetColliderType())
	{
	case CT_GRAVITY:

		
		switch(pDest->GetColliderType())
		{
		case CT_LEFT:
		case CT_RIGHT:
			return;
		}



		

		m_bEnable = false;

		{
			CObj* pEffect = FIND_OBJECT("BulletEffect")->Clone();

			pEffect->SetPos(GetCenterX() - 39.f, GetCenterY() - 39.f);

			GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pEffect);
		}

		break;

	case CT_RECT:

		m_bEnable = false;


		{
			CObj* pEffect = FIND_OBJECT("BulletEffect")->Clone();

			pEffect->SetPos(GetCenterX()-39.f, GetCenterY() - 39.f);

			GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pEffect);
		}

		break;
	}

}

void CBullet::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CBullet::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
