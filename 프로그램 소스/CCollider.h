#pragma once

#include "Game.h"


class CCollider
{
public:
	CCollider();
	CCollider(const CCollider& col);
	~CCollider();



private:
	
	POSITION m_tPos;
	_SIZE m_tSize;
	POSITION m_tOffset;

	COLLIDER_TYPE m_eColliderType;

	class CObj* m_pObj;

	list<class CCollider*> m_CollisionList;

public:
	void SetSize(POSITION tSize);
	void SetOffset(POSITION tOffset);
	void SetColliderType(COLLIDER_TYPE eType);
	void SetObj(class CObj* pObj);

	// get
	POSITION GetPos() const;
	_SIZE GetSize() const;
	COLLIDER_TYPE GetColliderType() const;

	class CObj* GetObj() const;

	void Update();

	// Collider

	void EraseColliderList(CCollider* pCol);
	void InsertColliderList(CCollider* pCol);
	bool PrevCollision(CCollider* pCol);

	CCollider* Clone();
};

