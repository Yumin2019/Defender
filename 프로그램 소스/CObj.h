#pragma once



#include "Game.h"


class CObj
{
public:
	CObj();
	CObj(const CObj& obj);
	virtual ~CObj();


protected:
	OBJECT_TYPE m_eObjectType;

	POSITION m_tPos;
	_SIZE m_tSize;

	LPDIRECT3DTEXTURE9 m_pTexture;

	RECT m_tRenderRect;

	list<class CCollider*> m_ColliderList;

	class CAnimation* m_pAnimation;

	bool m_bEnable;

public:
	// SET
	void SetObjectType(OBJECT_TYPE eType);
	void SetPos(float x, float y);
	void SetPos(POSITION tPos);
	void SetSize(float x, float y);
	void SetSize(_SIZE tSize);
	void SetTexture(LPDIRECT3DTEXTURE9 pTexture);
	void SetRenderRect(int l, int t, int r, int b);
	void SetAnimation(class CAnimation* pAni);

	// Get
	OBJECT_TYPE GetObjectType() const;
	POSITION GetPos() const;
	_SIZE GetSize() const;
	list<class CCollider*>& GetColliderList();
	bool GetEnable() const;

	float GetCenterX() const;
	float GetCenterY() const;
	POSITION GetCenter() const;


	void Die();


	void AddCollider(_SIZE tSize, POSITION tOffset, COLLIDER_TYPE eType);



	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);


	float GetLeft() const;
	float GetRight() const;
	float GetTop() const;
	float GetBottom() const;

	virtual CObj* Clone() = 0;
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest) = 0;
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest) = 0;
};

