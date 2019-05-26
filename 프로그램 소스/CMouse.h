#pragma once
#include "CUI.h"
class CMouse :
	public CUI
{
public:
	CMouse();
	CMouse(const CMouse& mouse);
	~CMouse();



private:
	HWND m_hWnd;



public:


	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CMouse* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

