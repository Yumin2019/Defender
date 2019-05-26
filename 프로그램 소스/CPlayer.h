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

	// ������

	int m_iBomb;
	int m_iHomingMissile;

	bool m_bDoubleJumpCycle;
	bool m_bTripleUpCycle;
	bool m_bBulletDistCycle;

	float m_fDoubleJumpCycleTime;
	float m_fTripleUpCycleTime;
	float m_fBulletDistCycleTime;

	float m_fCycleLimitTime;

	// �Ѿ� ���� ��� �ð�

	bool m_bBullet;
	float m_fBulletTime;
	float m_fBulletLimitTime;

	// ��ź�� ȣ�� �̻���

	bool m_bHomingMissile;
	float m_fHomingMissileTime;
	
	bool m_bBomb;
	float m_fBombTime;

	// limit define

	
	// üũ ����Ʈ

	POSITION m_tCheck;

	int m_iUnit; // ���ּ�.
	

	PLAYER_LV m_eLv;


	// Jump


	MOVE_DIR m_eDoubleJumpDir;

	bool m_bJump;
	
	float m_fSecond;

	bool m_bDoubleJump;

	float m_fPower;


	// ����

	int m_iScore;

	bool m_bCheat;


	int m_iSpeed;

	


public:
	
	int GetUnit() const;

	int GetSpeed() const;


	void SetLv(PLAYER_LV eLv);


	// �Ѿ� ��� ��

	void FrontBullet();
	void AngleBullet();
	void Bomb();
	void HomingMissile();


	// ������ ��� ȿ��

	void AddBomb();
	void AddHomingMissile();

	void Set();
	void DoubleJumpCycle();
	void BulletDistCycle();
	void TripleUpCycle();

	// üũ ����Ʈ

	void SetCheck(POSITION tPos);

	// ��ֹ� �浹

	void ObstacleCollision();

	// ������ ��Ȳ

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

