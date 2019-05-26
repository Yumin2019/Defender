#pragma once
#include "CScene.h"
class CInGameScene :
	public CScene
{
public:
	CInGameScene();
	virtual ~CInGameScene();


protected:

	PBACKGROUND m_pScreen;

	class CPlayer* m_pPlayer;

	int m_iMonster;
	int m_iMonsterMax;

	bool m_bMonsterCycle;

	bool m_bDoor;

	void MonsterCreate();

public:

	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);
};

