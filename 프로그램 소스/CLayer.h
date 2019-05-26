#pragma once

#include "Game.h"


class CLayer
{
public:
	CLayer();
	~CLayer();

private:
	string m_strTag;
	bool m_bEnable;

	list<class CObj*> m_ObjList;

public:
	list<class CObj*>& GetList();
	
	bool GetEnable() const;
	string GetTag() const;

	void SetTag(const string& strTag);
	void SetEnable(bool enable);

	
	void Input(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Update(float fDeltaTime);
	void Render(float fDeltaTime);
};

