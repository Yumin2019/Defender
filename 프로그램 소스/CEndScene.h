#pragma once
#include "CScene.h"
class CEndScene :
	public CScene
{
public:
	CEndScene();
	~CEndScene();


private:
	END_SCENE m_eEndScene;

	char m_strName[6];

	int m_iIndex;

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);
};

