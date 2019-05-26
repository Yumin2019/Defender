#include "CItem.h"
#include "CCollider.h"
#include "CSceneManager.h"
#include "CPlayer.h"


CItem::CItem()
{
	m_fSecond = 0.f;

}

CItem::CItem(const CItem & item) :
	CMoveObj(item)
{
	m_fSecond = 0.f;
}


CItem::~CItem()
{
}

void CItem::SetItemTyepe(ITEM_TYPE eType)
{
	m_eItemType = eType;

	// 아이템 타입에 따라서 Render부분이 달라진다

	m_tRenderRect = { m_eItemType * 50, 0, (1 + m_eItemType) * 50, 50 };
}

ITEM_TYPE CItem::GetItemType() const
{
	return m_eItemType;
}

bool CItem::Init()
{
	// 랜덤 아이템
	

	// 아이템 확률 

	int idx = rand() % 100 + 1;

	/*
		IT_TRIPLE_UP,
	IT_HOMING_MISSILE,
	IT_BOMB,
	IT_SPEED_UP,
	IT_DOUBLE_JUMP,
	IT_BULLET_DIST
	
	*/

	if (idx <= 10) // 10
	{
		// 핵폭탄.
		m_eItemType = IT_BOMB;
	}
	else if (idx <= 30) // 20  
	{
		// 호밍
		m_eItemType = IT_HOMING_MISSILE;

	}
	else if (idx <= 50) // 20 
	{
		// 트리플 
		m_eItemType = IT_TRIPLE_UP;

	}
	else if (idx <= 65) // 15
	{
		// 스피드
		m_eItemType = IT_SPEED_UP;

	}
	else if (idx <= 85) // 20
	{
		// Double
		m_eItemType = IT_DOUBLE_JUMP;

	}
	else if (idx <= 100) // 15
	{
		// BulletDist
		m_eItemType = IT_BULLET_DIST;

	}

	m_tRenderRect = { m_eItemType * 50, 0, (1 + m_eItemType) * 50, 50 };


	return true;
}

void CItem::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);
}

void CItem::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);

}

void CItem::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);


	m_fSecond += fDeltaTime;

	if (m_fSecond >= 7.f)
	{
		m_bEnable = false;
	}
}

void CItem::Render(float fDeltaTime)
{
	CMoveObj::Render(fDeltaTime);

}

CItem * CItem::Clone()
{
	return new CItem(*this);
}

void CItem::HitStart(CCollider * pSrc, CCollider * pDest)
{
	if (!m_bEnable)
		return;


	switch (pDest->GetObj()->GetObjectType())
	{
	case OT_STAGE:

		// gravity라는것.

		m_bFalling = false;

		break;

	case OT_PLAYER:

		switch (pSrc->GetColliderType())
		{
		case CT_RECT:

			// 아이템 적용 효과 !
			

		{
			m_bEnable = false;

			CPlayer* pPlayer = GET_SINGLE(CSceneManager)->GetPlayer();

			switch (m_eItemType)
			{
			case IT_DOUBLE_JUMP:

				pPlayer->DoubleJumpCycle();

				break;

			case IT_BULLET_DIST:

				pPlayer->BulletDistCycle();

				break;

			case IT_TRIPLE_UP:

				pPlayer->TripleUpCycle();

				break;

			case IT_HOMING_MISSILE:

				pPlayer->AddHomingMissile();

				break;

			case IT_BOMB:

				pPlayer->AddBomb();

				break;

			case IT_SPEED_UP:

				pPlayer->SpeedUp();

				break;
			}

		}





			break;

		case CT_GRAVITY:
			break;
		}

		break;

	}
}

void CItem::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CItem::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
