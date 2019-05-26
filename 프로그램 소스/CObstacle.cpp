#include "CObstacle.h"
#include "CCollider.h"
#include "CPlayer.h"
#include "CSceneManager.h"
#include "CItem.h"
#include "CCreateManager.h"

CObstacle::CObstacle()
{
}

CObstacle::CObstacle(const CObstacle & obs) :
	CStaticObj(obs)
{
}


CObstacle::~CObstacle()
{
}

void CObstacle::Input(float fDeltaTime)
{
	CStaticObj::Input(fDeltaTime);
}

void CObstacle::Collision(float fDeltaTime)
{
	CStaticObj::Collision(fDeltaTime);

}

void CObstacle::Update(float fDeltaTime)
{
	CStaticObj::Update(fDeltaTime);

}

void CObstacle::Render(float fDeltaTime)
{
	CStaticObj::Render(fDeltaTime);

}

CObstacle * CObstacle::Clone()
{
	return new CObstacle(*this);
}

void CObstacle::HitStart(CCollider * pSrc, CCollider * pDest)
{


	if (!m_bEnable)
		return;

	// 아이템 생성

	switch (pDest->GetObj()->GetObjectType())
	{
	case OT_PLAYER:

		// 플레이어 충돌함수.

		GET_SINGLE(CSceneManager)->GetPlayer()->ObstacleCollision();


		break;

	case OT_PLAYER_BULLET:


		// 아이템 생성.


		int idx = rand() % 100 + 1;

		if (idx >= 70)
		{
			int idx = rand() % 6;

			CItem* pItem = (CItem*)FIND_OBJECT("Item")->Clone();

			pItem->Init();

			pItem->SetPos(GetCenter());

			GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pItem);

		}

		m_bEnable = false;

		break;
	}
}

void CObstacle::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CObstacle::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
