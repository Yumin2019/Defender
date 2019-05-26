#include "CMoveObj.h"



CMoveObj::CMoveObj()
{

	m_eDirX = MD_RIGHT;

	m_fAngle = 0.f;
	m_fSpeed = 0.f;
	m_bPhysics = true;

	m_bFalling = true;

	m_iFall = 0;
}

CMoveObj::CMoveObj(const CMoveObj & obj) :
	CObj(obj)
{
	m_eDirX = obj.m_eDirX;

	m_fAngle = obj.m_fAngle;
	m_fSpeed = obj.m_fSpeed;
	m_bPhysics = obj.m_bPhysics;

	m_bFalling = true;

	m_iFall = 0;


	//m_bPhysics = false;
}


CMoveObj::~CMoveObj()
{
}

void CMoveObj::MoveX(float fDeltaTime)
{
	m_tPos.x += fDeltaTime * m_eDirX * m_fSpeed;
}

void CMoveObj::MoveX(float fDeltaTime, float fSpeed, MOVE_DIR eDir)
{
	m_tPos.x += fDeltaTime * eDir * fSpeed;

}

void CMoveObj::MoveY(float fDeltaTime, float fSpeed, MOVE_DIR eDir)
{
	m_tPos.y += fDeltaTime * fSpeed * eDir;
}

void CMoveObj::MoveAngle(float fDeltaTime)
{
	m_tPos.x += fDeltaTime * m_fSpeed * cosf(m_fAngle);
	m_tPos.y += fDeltaTime * m_fSpeed * sinf(m_fAngle);
}

void CMoveObj::MoveAngle(float fDeltaTime, float fSpeed)
{
	m_tPos.x += fDeltaTime * fSpeed * cosf(m_fAngle);
	m_tPos.y += fDeltaTime * fSpeed * sinf(m_fAngle);
}

void CMoveObj::SetFalling(bool flag)
{
	m_bFalling = flag;
}

void CMoveObj::SetDir(MOVE_DIR eDir)
{
	m_eDirX = eDir;
}

void CMoveObj::SetAngle(float fAngle)
{
	m_fAngle = fAngle;
}

void CMoveObj::SetSpeed(float fSpeed)
{
	m_fSpeed = fSpeed;
}

void CMoveObj::SetPhysics(bool physics)
{
	m_bPhysics = physics;
}

void CMoveObj::Input(float fDeltaTime)
{
	CObj::Input(fDeltaTime);
}

void CMoveObj::Collision(float fDeltaTime)
{
	CObj::Collision(fDeltaTime);

}

void CMoveObj::Update(float fDeltaTime)
{
	CObj::Update(fDeltaTime);


	// ม฿ทย

	if (m_bPhysics)
	{
		if (m_bFalling)
		{

			++m_iFall;

			if (m_iFall < 20)
				MoveY(fDeltaTime, 250.f, MD_RIGHT);
			else if (m_iFall < 40)
				MoveY(fDeltaTime, 350.f, MD_RIGHT);
			else if (m_iFall < 60)
				MoveY(fDeltaTime, 450.f, MD_RIGHT);
			else
				MoveY(fDeltaTime, 500.f, MD_RIGHT);

		}

		else
		{

			m_iFall = 0;
		}


	}

}

void CMoveObj::Render(float fDeltaTime)
{
	CObj::Render(fDeltaTime);

}
