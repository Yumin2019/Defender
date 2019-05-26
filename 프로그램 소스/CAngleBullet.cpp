#include "CAngleBullet.h"
#include "CSceneManager.h"
#include "CMath.h"
#include "CScene.h"
#include "CCore.h"
#include "CCollider.h"

CAngleBullet::CAngleBullet()
{
	m_bHomingMissile = false;
}

CAngleBullet::CAngleBullet(const CAngleBullet & bullet) :
	CBullet(bullet)
{
	m_bHomingMissile = bullet.m_bHomingMissile;
}


CAngleBullet::~CAngleBullet()
{
}

void CAngleBullet::AngleUpdate()
{
	list<CObj*>& DefaultList = GET_SINGLE(CSceneManager)->GetDefaultList();

	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = DefaultList.end();


	CObj* pTarget = NULL;

	float fDist = 9999.f;

	for (iter = DefaultList.begin(); iter != iterEnd; ++iter)
	{
		switch ((*iter)->GetObjectType())
		{
			// 나 호밍
		case OT_MONSTER:
		case OT_OBSTACLE:
		case OT_MONSTER_BULLET:


			float ffDist = CMath::GetDist(GetCenter(), (*iter)->GetCenter());

			if (ffDist < fDist)
			{
				fDist = ffDist;

				pTarget = *iter;
			}


			break;
		}
	}


	// 여기에는 가장 짧은 오브젝트가 잡혀있다.

	if (pTarget)
	{
		SetAngle(CMath::GetAngle(GetCenter(), pTarget->GetCenter()));
	}
}

void CAngleBullet::SetHoming()
{
	m_bHomingMissile = true;
}

void CAngleBullet::Input(float fDeltaTime)
{
	CBullet::Input(fDeltaTime);
}

void CAngleBullet::Collision(float fDeltaTime)
{
	CBullet::Collision(fDeltaTime);

}

void CAngleBullet::Update(float fDeltaTime)
{
	CBullet::Update(fDeltaTime);

	if (m_bHomingMissile)
	{
		m_fSecond += fDeltaTime;

		if (m_fSecond >= 1.f)
		{
			AngleUpdate();

			MoveAngle(fDeltaTime, 700.f);
		}
		else
		{
			MoveAngle(fDeltaTime, 100.f);
		}
	}
	else
	{
		MoveAngle(fDeltaTime);
	}

}

void CAngleBullet::Render(float fDeltaTime)
{

	if (GetObjectType() == OT_PLAYER_BULLET)
	{
		if (m_tSize.x == 0.f)
		{
			CBullet::Render(fDeltaTime);

			return;
		}


		D3DXMATRIX tMatrix;
		D3DXVECTOR3 tPos = { m_tPos.x - CScene::l, m_tPos.y, 0.f };

		D3DXMatrixTransformation2D(&tMatrix, NULL, NULL, NULL, NULL, m_fAngle, &(D3DXVECTOR2)tPos);

		CCore::m_pSprite->SetTransform(&tMatrix);

		CCore::m_pSprite->Draw(m_pTexture, &m_tRenderRect, NULL, NULL, 0xffffffff);

		// Back

		D3DXMatrixTransformation2D(&tMatrix, NULL, NULL, NULL, NULL, NULL, NULL);

		CCore::m_pSprite->SetTransform(&tMatrix);

	}
	else
	{
		CBullet::Render(fDeltaTime);

	}



}

CAngleBullet * CAngleBullet::Clone()
{
	return new CAngleBullet(*this);
}

void CAngleBullet::HitStart(CCollider * pSrc, CCollider * pDest)
{
	CBullet::HitStart(pSrc, pDest);

	
}

void CAngleBullet::HitStay(CCollider * pSrc, CCollider * pDest)
{
	CBullet::HitStay(pSrc, pDest);

}

void CAngleBullet::HitEnd(CCollider * pSrc, CCollider * pDest)
{
	CBullet::HitEnd(pSrc, pDest);

}
