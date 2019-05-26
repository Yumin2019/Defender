#pragma once
#include "CInGameScene.h"
class CInGame1 :
	public CInGameScene
{
public:
	CInGame1();
	~CInGame1();



public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);
};

