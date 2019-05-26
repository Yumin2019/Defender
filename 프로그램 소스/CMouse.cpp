#include "CMouse.h"
#include "CCore.h"


CMouse::CMouse()
{
	m_hWnd = GET_SINGLE(CCore)->GetHandle();
}

CMouse::CMouse(const CMouse & mouse) :
	CUI(mouse)
{
	m_hWnd = mouse.m_hWnd;
}


CMouse::~CMouse()
{
}

void CMouse::Input(float fDeltaTime)
{
}

void CMouse::Collision(float fDeltaTime)
{
}

void CMouse::Update(float fDeltaTime)
{
	POINT tPoint;

	GetCursorPos(&tPoint);

	ScreenToClient(m_hWnd, &tPoint);

	m_tPos.x = tPoint.x;
	m_tPos.y = tPoint.y;

	CUI::Update(fDeltaTime);

}

void CMouse::Render(float fDeltaTime)
{
	CUI::Render(fDeltaTime);
}

CMouse * CMouse::Clone()
{
	return new CMouse(*this);
}

void CMouse::HitStart(CCollider * pSrc, CCollider * pDest)
{
}

void CMouse::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CMouse::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
