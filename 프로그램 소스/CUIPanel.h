#pragma once
#include "CUI.h"
class CUIPanel :
	public CUI
{
public:
	CUIPanel();
	CUIPanel(const CUIPanel& panel);
	~CUIPanel();



public:
	static int m_iCurX;
	static int m_iSizeX;


private:
	PANEL_TYPE m_ePanelType;



public:

	void SetPanelType(PANEL_TYPE eType);

	void NumberRender(POSITION tPos, int cnt);

	void DoubleJumpUpdate();
	void BulletDistUpdate();
	void TripleUpUpdate();



	virtual void Input(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void Render(float fDeltaTime);

	virtual CUIPanel* Clone();
	virtual void HitStart(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitStay(class CCollider* pSrc, class CCollider* pDest);
	virtual void HitEnd(class CCollider* pSrc, class CCollider* pDest);

};

