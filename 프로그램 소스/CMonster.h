#pragma once
#include "CMoveObj.h"
class CMonster :
	public CMoveObj
{
public:
	CMonster();
	CMonster(const CMonster& mon);
	~CMonster();


public:
	static int m_iMonster;
	static int m_iMonsterDie;


private:
	static int m_tPattern[5][5];


	bool m_bUp;
	float m_fUpTime;
	

	bool m_bDown;
	float m_fDownTime;


	int m_iHp;

	int m_iRow;
	int m_iCol;
	
	float m_fBulletTime;
	float m_fBulletLimitTime;


	float m_fSecond;
	float m_fSecondLimitTime;


	int m_iScore;
	


	void Attack();

	int GetNumber(int cnt);

public:
	

	int GetScore() const;

	void SetScore(int score);
	void SetHp(int hp);
	void SetBulletTime(float fTime);
	void SetSecondTime(float fTime);

	bool Init();

	void UpdateAngle();

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CMonster* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

