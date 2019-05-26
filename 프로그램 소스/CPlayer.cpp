#include "CPlayer.h"
#include "CInput.h"
#include "CCollider.h"
#include "CSceneManager.h"
#include "CAngleBullet.h"
#include "CFrontBullet.h"
#include "CCreateManager.h"
#include "CScene.h"
#include "CEffect.h"

CPlayer::CPlayer()
{

	m_iScore = 0;

	m_bLeft = true;
	m_bRight = true;

	m_iBomb = 1;
	m_iHomingMissile = 3;

	m_bDoubleJumpCycle = false;
	m_bTripleUpCycle = false;
	m_bBulletDistCycle = false;

	m_bBullet = false;
	m_bHomingMissile = false;
	m_bBomb = false;

	m_tCheck = POSITION(0.f, 0.f);

	m_iUnit = 3;

	SetLv(LV_1);

	m_bJump = false;
	m_bDoubleJump = false;

	m_fSpeed = 200.f;

	m_bCheat = false;

	m_iSpeed = 0;


	m_fBulletDistCycleTime = 0.f;
	m_fTripleUpCycleTime = 0.f;
	m_fDoubleJumpCycleTime = 0.f;

}

CPlayer::CPlayer(const CPlayer & ply) :
	CMoveObj(ply)
{



	m_fBulletDistCycleTime = 0.f;
	m_fTripleUpCycleTime = 0.f;
	m_fDoubleJumpCycleTime = 0.f;

	m_iSpeed = 0;


	// 초기 생성시...

	m_bLeft = true;
	m_bRight = true;

	m_iBomb = 1;
	m_iHomingMissile = 3;

	m_bDoubleJumpCycle = false;
	m_bTripleUpCycle = false;
	m_bBulletDistCycle = false;

	m_bBullet = false;
	m_bHomingMissile = false;
	m_bBomb = false;

	m_tCheck = POSITION(0.f, 0.f);

	m_iUnit = 3;

	SetLv(LV_1);

	m_bJump = false;
	m_bDoubleJump = false;

	m_fSpeed = 200.f;


	//// 지우기
	/*DoubleJumpCycle();
	BulletDistCycle();
	TripleUpCycle();*/

	m_iScore = 0;

	m_bCheat = false;

}


CPlayer::~CPlayer()
{
}

int CPlayer::GetUnit() const
{
	return m_iUnit;
}

int CPlayer::GetSpeed() const
{
	return m_iSpeed;
}

void CPlayer::SetLv(PLAYER_LV eLv)
{
	m_eLv = eLv;

	// 50 * 60


	switch (m_eLv)
	{
	case LV_1:

		m_fCycleLimitTime = 12.f;

		m_fBulletLimitTime = 1.f;

		
		
		break;

	case LV_2:

		m_fCycleLimitTime = 15.f;

		m_fBulletLimitTime = 0.8f;


		break;

	case LV_3:

		m_fCycleLimitTime = 18.f;

		m_fBulletLimitTime = 0.6f;



		break;
	}


	switch (m_eDirX)
	{
	case MD_LEFT:

		m_tRenderRect = { 50, (m_eLv) * 60, 100,(m_eLv + 1) * 60 };

		break;

	case MD_RIGHT:

		m_tRenderRect = { 0, (m_eLv) * 60, 50,(m_eLv + 1) * 60 };

		break;
	}

}

void CPlayer::FrontBullet()
{
	CFrontBullet* pFront = (CFrontBullet*)FIND_OBJECT("FrontBullet")->Clone();

	switch (m_eLv)
	{
	case LV_1:
		pFront->SetPower(250.f, 100.f, 100.f);
		pFront->SetDamage(2);
		
		break;

	case LV_2:
		pFront->SetDamage(3);

		pFront->SetPower(250.f, 120.f, 200.f);

		break;

	case LV_3:
		pFront->SetDamage(5);

		pFront->SetPower(250.f, 140.f, 300.f);


		break;
	}


	GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pFront);

	switch (m_eDirX)
	{
	case MD_LEFT:

		pFront->SetPos(GetLeft() - pFront->GetSize().x, GetTop() - 20.f);
		pFront->SetRenderRect(15, 0, 30, 20);

		break;

	case MD_RIGHT:

		pFront->SetPos(GetRight(), GetTop() - 20.f);

		break;
	}

	pFront->SetDir(m_eDirX);

	if (m_bBulletDistCycle)
	{
		pFront->SetPower(250.f, 600.f, 250.f);
	}
	


	if (m_bTripleUpCycle)
	{
		pFront = pFront->Clone();

		pFront->SetPower(pFront->GetPower(), pFront->GetPowerX() + 30.f, pFront->GetPowerY() + 30.f);

		GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pFront);


		pFront = pFront->Clone();

		pFront->SetPower(pFront->GetPower(), pFront->GetPowerX() + 30.f, pFront->GetPowerY() + 30.f);

		GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pFront);

	}
}

void CPlayer::AngleBullet()
{

	list<CObj*>& DefaultList = GET_SINGLE(CSceneManager)->GetDefaultList();

	float fAngle = -PI / 2.f;

	CAngleBullet* pAngleBullet = (CAngleBullet*)FIND_OBJECT("AngleBullet")->Clone();

	// 속도 위치 각도
	switch (m_eLv)
	{
	case LV_1:

		pAngleBullet->SetSpeed(300.f);
		pAngleBullet->SetDamage(2);

		break;

	case LV_2:
		pAngleBullet->SetSpeed(400.f);
		pAngleBullet->SetDamage(3);

		break;

	case LV_3:
		pAngleBullet->SetSpeed(500.f);
		pAngleBullet->SetDamage(4);

		break;
	}

	pAngleBullet->SetPos(GetCenterX() - pAngleBullet->GetSize().x / 2.f, GetTop() - 20.f);

	pAngleBullet->SetAngle(fAngle);


	DefaultList.push_back(pAngleBullet);


	if (m_bTripleUpCycle)
	{
		// 좌
		pAngleBullet = pAngleBullet->Clone();

		pAngleBullet->SetPos(GetLeft() - pAngleBullet->GetSize().x, GetTop() - 10.f);

		pAngleBullet->SetAngle(fAngle - PI / 18.f);

		DefaultList.push_back(pAngleBullet);


		// 우

		pAngleBullet = pAngleBullet->Clone();

		pAngleBullet->SetPos(GetRight(), GetTop() - 10.f);

		pAngleBullet->SetAngle(fAngle + PI / 18.f);

		DefaultList.push_back(pAngleBullet);

	}
	

	// 위치 

	if (m_tPos.x < 0.f)
	{
		m_tPos.x = 0.f;
	}
	
	if (GetRight() > FULL_WIDTH)
	{
		m_tPos.x = FULL_WIDTH - m_tSize.x;
	}
}

void CPlayer::Bomb()
{
	CAngleBullet* pAngle = (CAngleBullet*)FIND_OBJECT("Bomb")->Clone();

	pAngle->SetPos(CScene::l + RS_WIDTH /2.f - 90.f, -400.f);

	GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pAngle);




	pAngle = (CAngleBullet*)FIND_OBJECT("BombBullet")->Clone();

	pAngle->SetPos(CScene::l, 0.f);

	GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pAngle);

}

void CPlayer::HomingMissile()
{

	list<CObj*>& DefaultList = GET_SINGLE(CSceneManager)->GetDefaultList();

	float fAngle = -PI / 2.f;

	CAngleBullet* pAngleBullet = (CAngleBullet*)FIND_OBJECT("HomingMissile")->Clone();

	pAngleBullet->SetDamage(2);




	pAngleBullet->SetHoming();

	pAngleBullet->SetPos(GetCenterX() - pAngleBullet->GetSize().x / 2.f, GetTop() - 20.f);

	pAngleBullet->SetAngle(fAngle);

	DefaultList.push_back(pAngleBullet);


		// 좌
		pAngleBullet = pAngleBullet->Clone();

		pAngleBullet->SetPos(GetLeft() - pAngleBullet->GetSize().x, GetTop() - 10.f);

		pAngleBullet->SetAngle(fAngle - PI / 18.f);

		DefaultList.push_back(pAngleBullet);


		// 우

		pAngleBullet = pAngleBullet->Clone();

		pAngleBullet->SetPos(GetRight(), GetTop() - 10.f);

		pAngleBullet->SetAngle(fAngle + PI / 18.f);

		DefaultList.push_back(pAngleBullet);

}

void CPlayer::AddBomb()
{
	++m_iBomb;

	if (m_iBomb >= 3)
		m_iBomb = 2;

}

void CPlayer::AddHomingMissile()
{
	++m_iHomingMissile;
}

void CPlayer::Set()
{
	m_bLeft = true;
	m_bRight = true;
}

void CPlayer::DoubleJumpCycle()
{
	m_bDoubleJumpCycle = true;
	m_fDoubleJumpCycleTime = 0.f;
}

void CPlayer::BulletDistCycle()
{
	m_bBulletDistCycle = true;
	m_fBulletDistCycleTime = 0.f;
}

void CPlayer::TripleUpCycle()
{
	m_bTripleUpCycle = true;
	m_fTripleUpCycleTime = 0.f;
}

void CPlayer::SetCheck(POSITION tPos)
{
	m_tCheck = tPos;
}

void CPlayer::ObstacleCollision()
{

	if (!m_bCheat)
	{
		--m_iUnit;

		m_fSpeed = SPEED;

		m_iSpeed = 0;

		if (m_iUnit == 0)
		{
			// 게임 종료

			GET_SINGLE(CSceneManager)->EndScene();
		}
	}

	// 팡

	CEffect* pObj = (CEffect*)FIND_OBJECT("Pang")->Clone();

	pObj->SetPos(GetCenterX() - 55.f, GetCenterY() - 55.f);

	GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pObj);

	pObj->SetTarget(this);

	pObj->SetOffset(POSITION(-20.f, -10.f));

	m_tPos = m_tCheck;

}

float CPlayer::GetBulletDistCycleTime() const
{
	return m_fBulletDistCycleTime;
}

float CPlayer::GetTripleUpCycleTime() const
{
	return m_fTripleUpCycleTime;
}

float CPlayer::GetDoubleJumpCycleTime() const
{
	return m_fDoubleJumpCycleTime;
}

float CPlayer::GetCycleLimitTime() const
{
	return m_fCycleLimitTime;
}

int CPlayer::GetBomb() const
{
	return m_iBomb;
}

int CPlayer::GetHomingMissile() const
{
	return m_iHomingMissile;
}

bool CPlayer::IsBulletDistCycle() const
{
	return m_bBulletDistCycle;
}

bool CPlayer::IstDoubleJumpCycle() const
{
	return m_bDoubleJumpCycle;
}

bool CPlayer::IsTripleUpCycle() const
{
	return m_bTripleUpCycle;
}

void CPlayer::SpeedUp()
{

	if (m_iSpeed < 4) // 4로 제한
	{
		m_fSpeed *= 1.2f;

		++m_iSpeed;
	}
}

int CPlayer::GetScore() const
{
	return m_iScore;
}

void CPlayer::AddScore(int score)
{
 	m_iScore += score;
}

void CPlayer::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);

	// 이동

	if (KEYPRESS("MoveLeft") && m_bLeft)
	{
		m_eDirX = MD_LEFT;

		MoveX(fDeltaTime);



		switch (m_eDirX)
		{
		case MD_LEFT:

			m_tRenderRect = { 50, (m_eLv) * 60, 100,(m_eLv + 1) * 60 };

			break;

		case MD_RIGHT:

			m_tRenderRect = { 0, (m_eLv) * 60, 50,(m_eLv + 1) * 60 };

			break;
		}

	}

	else if (KEYPRESS("MoveRight") && m_bRight)
	{
		m_eDirX = MD_RIGHT;

		MoveX(fDeltaTime);


		switch (m_eDirX)
		{
		case MD_LEFT:

			m_tRenderRect = { 50, (m_eLv) * 60, 100,(m_eLv + 1) * 60 };

			break;

		case MD_RIGHT:

			m_tRenderRect = { 0, (m_eLv) * 60, 50,(m_eLv + 1) * 60 };

			break;
		}
	}


	// 지우기 

	//if (KEYPRESS("MoveUp"))
	//{
	//	MoveY(fDeltaTime, 1000.f, MD_LEFT);
	//}
	//else if (KEYPRESS("MoveDown"))
	//{
	//	MoveY(fDeltaTime, 1000.f, MD_RIGHT);
	//}


	// 공격

	if (KEYDOWN("Attack") && !m_bBullet)
	{

		m_bBullet = true;
		m_fBulletTime = 0.f;

		FrontBullet();
	}

	if (KEYDOWN("AttackUp") && !m_bBullet)
	{
		m_bBullet = true;
		m_fBulletTime = 0.f;

		AngleBullet();
	}

	if (KEYDOWN("HomingMissile") && !m_bHomingMissile && m_iHomingMissile != 0)
	{
		m_bHomingMissile = true;
		m_fHomingMissileTime = 0.f;

		HomingMissile();

		--m_iHomingMissile;

	}

	if (KEYDOWN("Bomb") && !m_bBomb && m_iBomb != 0)
	{
		m_bBomb = true;
		m_fBombTime = 0.f;

		Bomb();

		--m_iBomb;
	}


	// 점프

	if (KEYDOWN("Jump") && !m_bFalling && !m_bJump)
	{
		m_fSecond = 0.f;
		m_bJump = true;
	}
	else if (KEYDOWN("Jump") && m_bFalling && !m_bDoubleJump && m_bDoubleJumpCycle)
	{

		if (m_eLv == LV_3)
			return;


		if (m_bJump)
		{
			m_bJump = false;
		}


		m_fSecond = 0.f;
		m_bDoubleJump = true;
		

		m_eDoubleJumpDir = m_eDirX;

		// 파워

		switch (m_eLv)
		{
		case LV_1:
			m_fPower = 80.f;
			break;

		case LV_2:
			m_fPower = 100.f;

			break;

		case LV_3:
			m_fPower = 120.f;

			break;
		}


	}





	// 체크 포인트

	//if (KEYDOWN("C"))
	//{
	//	m_tPos = m_tCheck;
	//}

	if (KEYDOWN("Cheat"))
	{
		m_bCheat = !m_bCheat;
	}



	// 업그레이드 디그레이드

	if (KEYDOWN("Upgrade"))
	{
		switch (m_eLv)
		{
		case LV_1:
			SetLv(LV_2);

			break;

		case LV_2:
			SetLv(LV_3);

			break;

		case LV_3:
			break;
		}
	}


	if (KEYDOWN("Degrade"))
	{
		switch (m_eLv)
		{
		case LV_1:
			break;

		case LV_2:
			SetLv(LV_1);

			break;

		case LV_3:
			SetLv(LV_2);

			break;
		}
	}


	// 아이템 추가 

	if (KEYDOWN("AddBomb"))
	{
		AddBomb();
	}

	if (KEYDOWN("AddHoming"))
	{
		AddHomingMissile();
	}

	// 아이템 적용
	if (KEYDOWN("BulletDist"))
	{
		BulletDistCycle();
	}

	if (KEYDOWN("TripleUp"))
	{
		TripleUpCycle();
	}

	if (KEYDOWN("DoubleJump"))
	{
		DoubleJumpCycle();
	}

}

void CPlayer::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);

}

void CPlayer::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);

	// 아이템 사용 효과

	if (m_bDoubleJumpCycle)
	{
		m_fDoubleJumpCycleTime += fDeltaTime;

		if (m_fDoubleJumpCycleTime >= m_fCycleLimitTime)
		{
			m_bDoubleJumpCycle = false;
		}
	}

	if (m_bTripleUpCycle)
	{
		m_fTripleUpCycleTime += fDeltaTime;

		if (m_fTripleUpCycleTime >= m_fCycleLimitTime)
		{
			m_bTripleUpCycle = false;
		}
	}


	if (m_bBulletDistCycle)
	{
		m_fBulletDistCycleTime += fDeltaTime;

		if (m_fBulletDistCycleTime >= m_fCycleLimitTime)
		{
			m_bBulletDistCycle = false;
		}
	}

	// 총알 재사용 대기시간

	if (m_bBullet)
	{
		m_fBulletTime += fDeltaTime;

		if (m_fBulletTime >= m_fBulletLimitTime)
		{
			m_bBullet = false;
		}
	}

	if (m_bHomingMissile)
	{
		m_fHomingMissileTime += fDeltaTime;

		if (m_fHomingMissileTime >= ITEM_LIMIT_TIME)
		{
			m_bHomingMissile = false;
		}
	}

	if (m_bBomb)
	{
		m_fBombTime += fDeltaTime;

		if (m_fBombTime >= ITEM_LIMIT_TIME)
		{
			m_bBomb = false;
		}
	}



	// 점프 

	if (m_bJump)
	{
		m_fSecond += fDeltaTime;

		if (m_fSecond >= 0.3f)
		{
			m_bJump = false;
		}

		MoveY(fDeltaTime, 700.f, MD_LEFT);
	}
	else if (m_bDoubleJump)
	{
		m_fSecond += fDeltaTime;

		if (m_fSecond >= 0.1f)
		{
			m_fPower -= 20.f;
		}


		if (m_fSpeed + m_fPower > 0.f)
		{

			switch (m_eDoubleJumpDir)
			{
			case MD_LEFT:
				
				if(m_bLeft)
				MoveX(fDeltaTime, 300.f + m_fSpeed + m_fPower, m_eDoubleJumpDir);

				break;

			case MD_RIGHT:

				if(m_bRight)
				MoveX(fDeltaTime, 300.f + m_fSpeed + m_fPower, m_eDoubleJumpDir);

				break;
			}

		}


		if (300.f + m_fPower > 0.f)
		{
			MoveY(fDeltaTime, 300.f + m_fPower, MD_LEFT);

		}

	}


	if ( GetTop() > RS_HEIGHT + 200.f)
	{
		ObstacleCollision();
	}
}

void CPlayer::Render(float fDeltaTime)
{
	CMoveObj::Render(fDeltaTime);

}

CPlayer * CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::HitStart(CCollider * pSrc, CCollider * pDest)
{

	switch (pDest->GetColliderType())
	{
	case CT_GRAVITY:


		switch (pSrc->GetColliderType())
		{

		case CT_GRAVITY:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{

				m_bFalling = false;

				m_bJump = false;
				m_bDoubleJump = false;
			}


			break;

		case CT_LEFT:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{
				m_bLeft = false;
			}

			break;

		case CT_RIGHT:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{
				m_bRight = false;
			}

			break;

		}
		

		break;

	

	case CT_RECT:


		// 몬스터 총알, 아이템, 도어, check

		switch (pDest->GetObj()->GetObjectType())
		{
		case OT_MONSTER_BULLET:

 			ObstacleCollision();

			// 빵 ! 이펙트 추가.


			break;

		case OT_ITEM:

			// 효과는 아이템에서


			break;

		case OT_DOOR:


			break;

		case OT_CHECK:

			
			break;
		}

		break;

	}

}

void CPlayer::HitStay(CCollider * pSrc, CCollider * pDest)
{
	switch (pDest->GetColliderType())
	{
	case CT_GRAVITY:


		switch (pSrc->GetColliderType())
		{

		case CT_GRAVITY:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{

				m_bFalling = false;


			/*	m_bJump = false;
				m_bDoubleJump = false;*/
			}


			break;

		case CT_LEFT:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{
				m_bLeft = false;
			}

			break;

		case CT_RIGHT:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{
				m_bRight = false;
			}

			break;

		}


		break;

	}
}

void CPlayer::HitEnd(CCollider * pSrc, CCollider * pDest)
{
	switch (pDest->GetColliderType())
	{
	case CT_GRAVITY:


		switch (pSrc->GetColliderType())
		{

		case CT_GRAVITY:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{
				m_bFalling = true;

			}


			break;

		case CT_LEFT:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{
				m_bLeft = true;
			}

			break;

		case CT_RIGHT:

			if (pDest->GetObj()->GetObjectType() == OT_STAGE)
			{
				m_bRight = true;
			}

			break;

		}


		break;



	case CT_RECT:



		switch (pDest->GetObj()->GetObjectType())
		{
		case OT_MONSTER_BULLET:




			break;

		case OT_ITEM:



			break;

		case OT_DOOR:


			break;

		case OT_CHECK:


			break;
		}

		break;

	}
}
