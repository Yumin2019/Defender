#include "CUI.h"
#include "CCore.h"


CUI::CUI()
{
}

CUI::CUI(const CUI & ui) :
	CStaticObj(ui)
{
}


CUI::~CUI()
{
}

void CUI::Input(float fDeltaTime)
{

}

void CUI::Collision(float fDeltaTime)
{
}

void CUI::Update(float fDeltaTime)
{
	CObj::Update(fDeltaTime);
}

void CUI::Render(float fDeltaTime)
{
	D3DXVECTOR3 tCenter = { 0.f, 0.f, 0.f };
	D3DXVECTOR3 tPos = { m_tPos.x, m_tPos.y, 0.f };


	CCore::m_pSprite->Draw(m_pTexture, &m_tRenderRect, &tCenter, &tPos, 0xffffffff);
}
