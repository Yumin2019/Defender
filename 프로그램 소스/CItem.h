#pragma once
#include "CMoveObj.h"
class CItem :
	public CMoveObj
{
public:
	CItem();
	CItem(const CItem& item);
	~CItem();


private:
	ITEM_TYPE m_eItemType;


	float m_fSecond;

public:

	void SetItemTyepe(ITEM_TYPE eType);

	ITEM_TYPE GetItemType() const;

	bool Init();

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CItem* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

