#include "CUIButton.h"
#include "CInput.h"
#include "CSceneManager.h"
#include "CCore.h"
#include "CUIPanel.h"

CUIButton::CUIButton()
{
}

CUIButton::CUIButton(const CUIButton & button) :
	CUI(button)
{
	m_eButtonType = button.m_eButtonType;
}


CUIButton::~CUIButton()
{
}

void CUIButton::SetButtonType(BUTTON_TYPE eType)
{
	m_eButtonType = eType;
}

BUTTON_TYPE CUIButton::GetButtonType() const
{
	return m_eButtonType;
}

void CUIButton::Input(float fDeltaTime)
{
	CUI::Input(fDeltaTime);
}

void CUIButton::Collision(float fDeltaTime)
{
	CUI::Collision(fDeltaTime);

}

void CUIButton::Update(float fDeltaTime)
{
	CUI::Update(fDeltaTime);

}

void CUIButton::Render(float fDeltaTime)
{
	switch (m_eButtonType)
	{
	case BT_ARROW_LEFT:
		if (CUIPanel::m_iCurX == 0)
			return;
	}
	CUI::Render(fDeltaTime);

}

CUIButton * CUIButton::Clone()
{
	return new CUIButton(*this);
}

void CUIButton::HitStart(CCollider * pSrc, CCollider * pDest)
{

	switch (m_eButtonType)
	{
	case BT_ARROW_LEFT:
		if (CUIPanel::m_iCurX == 0)
			return;
	}


	// 마우스와 충돌

	switch (m_eButtonType)
	{
	case BT_HOME:

		m_tRenderRect = { 0, 50, 50, 100 };


		break;

	case BT_ARROW_LEFT:
	case BT_ARROW_RIGHT:

		m_tRenderRect = { 100, 0, 200, 50 };


		break;


	default:
		m_tRenderRect = { 0, 75, 250, 150 };

		break;
	}

}

void CUIButton::HitStay(CCollider * pSrc, CCollider * pDest)
{

	switch (m_eButtonType)
	{
	case BT_ARROW_LEFT:
		if (CUIPanel::m_iCurX == 0)
			return;
	}


	if (KEYDOWN("MouseLButton"))
	{
		switch (m_eButtonType)
		{

		case BT_START:

			GET_SINGLE(CSceneManager)->InGame1();

			break;

		case BT_METHOD:

			CUIPanel::m_iSizeX = 3;
			CUIPanel::m_iCurX = 0;

			GET_SINGLE(CSceneManager)->CreateInform(m_eButtonType);
			
			GET_SINGLE(CSceneManager)->ObjMoveToBox("UILayer");

			break;

		case BT_RANK:

			CUIPanel::m_iCurX = 0;
			CUIPanel::m_iSizeX = 1;

			// Scene Manager에서 패널을 생성해준다.

			GET_SINGLE(CSceneManager)->CreateInform(m_eButtonType);

			GET_SINGLE(CSceneManager)->ObjMoveToBox("UILayer");



			break;

		case BT_QUIT:

			CCore::m_bLoop = false;

			break;

		case BT_ARROW_RIGHT:

			++CUIPanel::m_iCurX;

			if (CUIPanel::m_iCurX == CUIPanel::m_iSizeX)
			{
				// inform erase 
				// return.

				// 패널을 모두 사용했으니, 패널 List를 날리고... 다시 스위치를 킨다.

				// UI 복구

				GET_SINGLE(CSceneManager)->ObjMoveToLayer("UILayer");

				GET_SINGLE(CSceneManager)->LayerSwitch("PanelLayer", false);
			}

			break;

		case BT_ARROW_LEFT:

			--CUIPanel::m_iCurX;

			break;

		case BT_HOME:

			GET_SINGLE(CSceneManager)->StartScene();

			break;


		case BT_RETRY:
			// InGame1로 가되 기존의 정보를 날린다.

			GET_SINGLE(CSceneManager)->ErasePlayer();

			GET_SINGLE(CSceneManager)->InGame1();

			break;
			
		}
	}
}

void CUIButton::HitEnd(CCollider * pSrc, CCollider * pDest)
{


	switch (m_eButtonType)
	{
	case BT_HOME:

		m_tRenderRect = { 0, 0, 50, 50 };

		break;

	case BT_ARROW_LEFT:
		if (CUIPanel::m_iCurX == 0)
			return;

	case BT_ARROW_RIGHT:

		m_tRenderRect = { 0, 0, 100, 50 };


		break;


	default:
		m_tRenderRect = { 0, 0, 250, 75 };

		break;
	}
}
