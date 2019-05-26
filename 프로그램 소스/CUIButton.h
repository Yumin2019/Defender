#pragma once
#include "CUI.h"
class CUIButton :
	public CUI
{
public:
	CUIButton();
	CUIButton(const CUIButton& button);
	~CUIButton();



private:
	BUTTON_TYPE m_eButtonType;

public:

	void SetButtonType(BUTTON_TYPE eType);

	BUTTON_TYPE GetButtonType() const;

	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CUIButton* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);
};

