#pragma once
#include "CScene.h"
class CStartScene :
	public CScene
{
public:
	CStartScene();
	~CStartScene();


private:
	static bool m_bIntro;

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);
};

