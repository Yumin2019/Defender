#pragma once
#include "CInGameScene.h"
class CInGame2 :
	public CInGameScene
{
public:
	CInGame2();
	~CInGame2();


public:
	static bool m_bClear;

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);
};

