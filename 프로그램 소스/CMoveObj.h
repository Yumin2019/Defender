#pragma once
#include "CObj.h"
class CMoveObj :
	public CObj
{
public:
	CMoveObj();
	CMoveObj(const CMoveObj& obj);
	virtual ~CMoveObj();

protected:


	float m_fAngle;
	float m_fSpeed;
	MOVE_DIR m_eDirX;


	bool m_bPhysics;
	bool m_bFalling;
	int m_iFall;

public:

	// Move

	void MoveX(float fDeltaTime);
	void MoveX(float fDeltaTime, float fSpeed, MOVE_DIR eDir);
	void MoveY(float fDeltaTime, float fSpeed, MOVE_DIR eDir);
	void MoveAngle(float fDeltaTime);
	void MoveAngle(float fDeltaTime, float fSpeed);


	void SetFalling(bool flag);
	void SetDir(MOVE_DIR eDir);
	void SetAngle(float fAngle);
	void SetSpeed(float fSpeed);
	void SetPhysics(bool physics);


	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CMoveObj* Clone() = 0;
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest) = 0;
};

