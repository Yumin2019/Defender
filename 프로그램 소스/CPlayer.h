#pragma once
#include "CMoveObj.h"
class CPlayer :
	public CMoveObj
{
public:
	CPlayer();
	CPlayer(const CPlayer& ply);
	~CPlayer();


private:	
	bool m_bLeft;
	bool m_bRight;

	// 아이템

	int m_iBomb;
	int m_iHomingMissile;

	bool m_bDoubleJumpCycle;
	bool m_bTripleUpCycle;
	bool m_bBulletDistCycle;

	float m_fDoubleJumpCycleTime;
	float m_fTripleUpCycleTime;
	float m_fBulletDistCycleTime;

	float m_fCycleLimitTime;

	// 총알 재사용 대기 시간

	bool m_bBullet;
	float m_fBulletTime;
	float m_fBulletLimitTime;

	// 폭탄과 호밍 미사일

	bool m_bHomingMissile;
	float m_fHomingMissileTime;
	
	bool m_bBomb;
	float m_fBombTime;

	// limit define

	
	// 체크 포인트

	POSITION m_tCheck;

	int m_iUnit; // 유닛수.
	

	PLAYER_LV m_eLv;


	// Jump


	MOVE_DIR m_eDoubleJumpDir;

	bool m_bJump;
	
	float m_fSecond;

	bool m_bDoubleJump;

	float m_fPower;


	// 점수

	int m_iScore;

	bool m_bCheat;


	int m_iSpeed;

	


public:
	
	int GetUnit() const;

	int GetSpeed() const;


	void SetLv(PLAYER_LV eLv);


	// 총알 쏘는 것

	void FrontBullet();
	void AngleBullet();
	void Bomb();
	void HomingMissile();


	// 아이템 사용 효과

	void AddBomb();
	void AddHomingMissile();

	void Set();
	void DoubleJumpCycle();
	void BulletDistCycle();
	void TripleUpCycle();

	// 체크 포인트

	void SetCheck(POSITION tPos);

	// 장애물 충돌

	void ObstacleCollision();

	// 아이템 상황

	float GetBulletDistCycleTime() const;
	float GetTripleUpCycleTime() const;
	float GetDoubleJumpCycleTime() const;

	float GetCycleLimitTime() const;

	int GetBomb() const;
	int GetHomingMissile() const;

	bool IsBulletDistCycle() const;
	bool IstDoubleJumpCycle() const;
	bool IsTripleUpCycle() const;
	void SpeedUp();


	int GetScore() const;
	void AddScore(int score);

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CPlayer* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

