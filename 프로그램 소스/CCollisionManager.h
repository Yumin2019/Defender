#pragma once

#include "Game.h"

class CCollisionManager
{
	DECLARE_SINGLE(CCollisionManager);

private:
	list<class CObj*> m_CheckList;




private:
	bool ObjectTypeCheck(OBJECT_TYPE eSrc, OBJECT_TYPE eDest);
	bool ColliderTypeCheck(COLLIDER_TYPE eSrc, COLLIDER_TYPE eDest);

	void CollisionCheck(class CObj* pSrc, class CObj* pDest);

public:
	list<class CObj*>& GetList();

	bool Init();
	void Update();



};

