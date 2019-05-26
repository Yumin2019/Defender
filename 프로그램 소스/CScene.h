#pragma once

#include "Game.h"

class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	static int l;


protected:
	list<class CLayer*> m_LayerList;
	list<PBACKGROUND> m_Background;


	float m_fSecond;
	float m_fSecondLimitTime;
	SCENE m_eScene;


public:

	SCENE GetScene() const;
	CLayer* FindLayer(const string& strTag);


	class CLayer* CreateLayer(const string& strTag);

	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);
};

