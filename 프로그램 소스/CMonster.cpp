#include "CMonster.h"
#include "CScene.h"
#include "CCreateManager.h"
#include "CSceneManager.h"
#include "CBullet.h"
#include "CCollider.h"
#include "CPlayer.h"
#include "CItem.h"

int CMonster::m_tPattern[5][5] =
{
	{0, 0, 0, 0, 0},
	{1, 7, 1, 7, 0}, 
	{2, 7, 0, 0, 0},
	{0, 1, 7, 0, 0}, 
	{1, 6, 1, 6, 0}
};

int CMonster::m_iMonster;
int CMonster::m_iMonsterDie;

CMonster::CMonster()
{

	/*int m_iHp;

	int m_iRow;
	int m_iCol;

	float m_fBulleTime;
	float m_fBulletLimitTime;

	float m_fSecond;
	float m_fSecondLimitTime;*/

	m_iHp = 1;
	m_iRow = 0;
	m_iCol = 0;
	m_fBulletTime = 0.f;
	m_fBulletLimitTime = 0.f;
	m_fSecond = 0.f;
	m_fSecondLimitTime = 0.f;

	m_bUp = false;
	m_bDown = false;

	m_fUpTime = 0.f;
	m_fDownTime = 0.f;
}

CMonster::CMonster(const CMonster & mon) :
	CMoveObj(mon)
{

	m_iScore = mon.m_iScore;
	m_iHp = mon.m_iHp;
	m_iRow = 0;
	m_iCol = 0;
	m_fBulletTime = 0.f;
	m_fBulletLimitTime = mon.m_fBulletLimitTime;
	m_fSecond = 0.f;
	m_fSecondLimitTime = mon.m_fSecondLimitTime;

	m_bUp = false;
	m_bDown = false;

	m_fUpTime = 0.f;
	m_fDownTime = 0.f;
}


CMonster::~CMonster()
{
}

void CMonster::Attack()
{
	CObj* pBullet = FIND_OBJECT("MonsterBullet")->Clone();

	pBullet->SetPos(GetCenter());

	GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pBullet);
}

int CMonster::GetNumber(int cnt)
{
	switch (m_eDirX)
	{
	case MD_LEFT:

		// 변환해서 데입.

		switch (cnt)
		{
		case 7:
			cnt = 5;
			break;

		case 0 :
			cnt = 4;
			break;

		case 1:
			cnt = 3;

			break;
		}

		break;

	case MD_RIGHT:


		break;
	}

	return cnt;

}

int CMonster::GetScore() const
{
	return m_iScore;
}

void CMonster::SetScore(int score)
{
	m_iScore = score;
}

void CMonster::SetHp(int hp)
{
	m_iHp = hp;
}

void CMonster::SetBulletTime(float fTime)
{
	m_fBulletLimitTime = fTime;
}

void CMonster::SetSecondTime(float fTime)
{
	m_fSecondLimitTime = fTime;
}

bool CMonster::Init()
{
	// 위치 방향 패턴 angle

	int idx = rand() % 4;

	switch (idx)
	{
	case 0:
		SetPos(POS1);
		break;

	case 1:
		SetPos(POS2);

		break;

	case 2:
		SetPos(POS3);

		break;

	case 3:
		SetPos(POS4);

		break;
	}


	if (CScene::l + RS_WIDTH * 0.5f > m_tPos.x)
	{
		m_tRenderRect = { 0, 0, 250, 150 };

		m_eDirX = MD_RIGHT;

	}
	else
	{
		m_eDirX = MD_LEFT;
		m_tRenderRect = { 250, 0, 500, 150 };


	}

	m_iRow = rand() % 5;
	m_iCol = 0;

	
	SetAngle(GetNumber(m_tPattern[m_iRow][m_iCol]) * -PI / 4.f);


	++m_iMonster;

	return true;
}

void CMonster::UpdateAngle()
{
	++m_iCol;

	if (m_iCol == 5)
	{
		m_iCol = 0;

		m_iRow = rand() % 5;

	}

	SetAngle(GetNumber(m_tPattern[m_iRow][m_iCol]) * -PI / 4.f);
	
}

void CMonster::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);
}

void CMonster::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);

}

void CMonster::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);



	m_fSecond += fDeltaTime;

	if (m_fSecond >= m_fSecondLimitTime)
	{
		UpdateAngle();

		m_fSecond -= m_fSecondLimitTime;
	}

	MoveAngle(fDeltaTime);


	// 총알

	m_fBulletTime += fDeltaTime;

	if (m_fBulletTime >= m_fBulletLimitTime)
	{
		m_fBulletTime -= m_fBulletLimitTime;




		int idx = rand() % 100 + 1;

		if (idx <= 10)
		{
			int idx = rand() % 6;

			CItem* pItem = (CItem*)FIND_OBJECT("Item")->Clone();

			pItem->Init();

			pItem->SetPos(GetCenter());

			GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pItem);
		}
		else
		{
			Attack();

		}
		

		
	}


	if (CScene::l - 200.f > GetCenterX())
	{
		m_eDirX = MD_RIGHT;
		m_tRenderRect = { 0, 0, 250, 150 };


	}
	else if (CScene::l + RS_WIDTH + 200.f < GetCenterX())
	{
		m_eDirX = MD_LEFT;

		m_tRenderRect = { 250, 0, 500, 150 };

	}


	if (GetBottom() < 0.f)
	{
		m_bDown = true;

		m_fDownTime = 0.f;
	}


	if (GetBottom() > RS_HEIGHT / 2.f)
	{
		m_bUp = true;

		m_fUpTime = 0.f;
	}



	// 이동

	if (m_bUp)
	{
		m_fUpTime += fDeltaTime;

		if (m_fUpTime >= 1.f)
		{
			m_bUp = false;
		}

		MoveY(fDeltaTime, 100.f, MD_LEFT);
	}

	if (m_bDown)
	{

		m_fDownTime += fDeltaTime;

		if (m_fDownTime >= 1.f)
		{
			m_bDown = false;
		}

		MoveY(fDeltaTime, 100.f, MD_RIGHT);
	}


}

void CMonster::Render(float fDeltaTime)
{
	CMoveObj::Render(fDeltaTime);

}

CMonster * CMonster::Clone()
{
	return new CMonster(*this);
}

void CMonster::HitStart(CCollider * pSrc, CCollider * pDest)
{

	if (!m_bEnable)
		return;

	// 총알과 충돌
	CBullet* pBullet = (CBullet*)pDest->GetObj();

	int iDamage = pBullet->GetDamage();

	m_iHp -= iDamage;

	if (m_iHp <= 0)
	{
		m_bEnable = false;


		GET_SINGLE(CSceneManager)->GetPlayer()->AddScore(m_iScore);


		int idx = rand() % 100 + 1;

		if (idx >= 70)
		{
			int idx = rand() % 6;

			CItem* pItem = (CItem*)FIND_OBJECT("Item")->Clone();

			pItem->Init();

			pItem->SetPos(GetCenter());

			GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pItem);
		}

		--m_iMonster;


		++m_iMonsterDie;

		if (m_iMonsterDie == 15)
		{
			GET_SINGLE(CSceneManager)->GetPlayer()->SetLv(LV_2);
		}
		else if (m_iMonsterDie == 30)
		{
			GET_SINGLE(CSceneManager)->GetPlayer()->SetLv(LV_3);

		}

	}
}

void CMonster::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CMonster::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
