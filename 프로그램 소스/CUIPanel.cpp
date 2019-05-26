#include "CUIPanel.h"
#include "CPlayer.h"
#include "CSceneManager.h"
#include "CCore.h"
#include "CMonster.h"

int CUIPanel::m_iCurX;
int CUIPanel::m_iSizeX;

CUIPanel::CUIPanel()
{
}

CUIPanel::CUIPanel(const CUIPanel & panel) :
	CUI(panel)
{
	m_ePanelType = panel.m_ePanelType;
}


CUIPanel::~CUIPanel()
{
}

void CUIPanel::SetPanelType(PANEL_TYPE eType)
{
	m_ePanelType = eType;
}

void CUIPanel::NumberRender(POSITION tPos, int cnt)
{
	int Count = to_string(cnt).size();

	--Count;

	D3DXVECTOR3 tCenter = { 0.f, 0.f, 0.f };


	for (int i = Count; i >= 0; --i)
	{
		int num = cnt % 10;

		m_tRenderRect = { num * 30, 0, (num + 1) * 30, 50 }; //바텀 하드코딩.


		D3DXVECTOR3 m_tPos = { tPos.x + i * 30.f, tPos.y, 0.f };

		CCore::m_pSprite->Draw(m_pTexture, &m_tRenderRect, &tCenter, &m_tPos, 0xffffffff);

		cnt /= 10;

	}



}

void CUIPanel::DoubleJumpUpdate()
{
	CPlayer* pPlayer = GET_SINGLE(CSceneManager)->GetPlayer();

	float fPercent = pPlayer->GetDoubleJumpCycleTime() / pPlayer->GetCycleLimitTime();

	int width = 236 * fPercent;

	m_tRenderRect.right = 236 - width;

}

void CUIPanel::BulletDistUpdate()
{
	CPlayer* pPlayer = GET_SINGLE(CSceneManager)->GetPlayer();

	float fPercent = pPlayer->GetBulletDistCycleTime() / pPlayer->GetCycleLimitTime();

	int width = 219 * fPercent;

	m_tRenderRect.right = 219 - width;
}

void CUIPanel::TripleUpUpdate()
{
	CPlayer* pPlayer = GET_SINGLE(CSceneManager)->GetPlayer();

	float fPercent = pPlayer->GetTripleUpCycleTime() / pPlayer->GetCycleLimitTime();

	int width = 172 * fPercent;

	m_tRenderRect.right = 172 - width;
}

void CUIPanel::Input(float fDeltaTime)
{
	CUI::Input(fDeltaTime);
}

void CUIPanel::Collision(float fDeltaTime)
{
	CUI::Collision(fDeltaTime);

}

void CUIPanel::Update(float fDeltaTime)
{
	CUI::Update(fDeltaTime);



	switch (m_ePanelType)
	{
	case PT_BULLET_DIST:

		BulletDistUpdate();

		break;

	case PT_DOUBLE_JUMP:

		DoubleJumpUpdate();

		break;

	case PT_TRIPLE_UP:

		TripleUpUpdate();

		break;

	case PT_INFORM:



		break;

			//PT_INFORM,
			//PT_BULLET_DIST,
			//PT_DOUBLE_JUMP,
			//PT_TRIPLE_UP,
			//PT_IMAGE,
			//PT_NUMBER,
			//PT_SCORE // 는 따로.
	}
}

void CUIPanel::Render(float fDeltaTime)
{

	switch (m_ePanelType)
	{
	case PT_NUMBER:

		// 출력할 위치에 출력.
		

			{
		CPlayer* pPlayer = GET_SINGLE(CSceneManager)->GetPlayer();

		NumberRender(POSITION(10.f, 250.f), pPlayer->GetScore());


		

		// 미사일 수

		NumberRender(POSITION(220.f + 64.f * 0 + 5.f, 25.f), pPlayer->GetHomingMissile());


		// 핵탄두 수

		NumberRender(POSITION(220.f + 64.f * 1 + 5.f, 25.f), pPlayer->GetBomb());

		
		// 스피드 개수

		NumberRender(POSITION(220.f + 64.f * 2 + 5.f, 25.f), pPlayer->GetSpeed());


		// 남은 적
		
		NumberRender(POSITION(RS_WIDTH - 70.f, 25.f), CMonster::m_iMonster);

		/*
		
		
		", "HomingImage", _SIZE(220.f + 64.f * 0 + 5.f, 25.f), POSITION(
		
		", "BombImage", POSITION(220.f + 64.f * 1 + 5.f, 25.f), _SIZE(0.
		
		", "SpeedImage", POSITION(220.f + 64.f * 2 + 5.f, 25.f), _SIZE(0
		
		
		
		*/


			}



		break;


	case PT_PLAYER_IMAGE:

		// 플레이어의 남은 유닛수에 따라서, 출력을 달리함.

	{


		int cnt = GET_SINGLE(CSceneManager)->GetPlayer()->GetUnit();

		
		for (int i = 0; i < cnt; ++i)
		{


			D3DXVECTOR3 tCenter = { 0.f, 0.f, 0.f };

			D3DXVECTOR3 tPos = { m_tPos.x + i * 40.f, m_tPos.y, 0.f };

			CCore::m_pSprite->Draw(m_pTexture, &m_tRenderRect, &tCenter, &tPos, 0xffffffff);


		}

	}


		break;

	case PT_IMAGE:

		CUI::Render(fDeltaTime);


		break;

	case PT_SCORE:

		CUI::Render(fDeltaTime);


		// 글자

		{

			vector<SCORE>& ScoreVec = GET_SINGLE(CSceneManager)->GetScoreVec();


			vector<SCORE>::iterator iter;
			vector<SCORE>::iterator iterEnd = ScoreVec.end();


			int cnt = 0;


			RECT rc = { 150, 176, 0, 0 };  // 156 + 124 

			for (iter = ScoreVec.begin(); iter != iterEnd; ++iter)
			{
				

				string str = (*iter).m_strName + " : " + to_string((*iter).m_iScore);

				// 이것을 폰트로 출력

				CCore::m_pFont->DrawTextA(CCore::m_pSprite, str.c_str(), -1, &rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));

				++cnt;

				if (cnt == 3)
					break;

				rc.top += 124;

			}


		}



		break;

	case PT_INFORM:

		m_tRenderRect = { INFORM_WIDTH * m_iCurX, 0,INFORM_WIDTH * (m_iCurX + 1), INFORM_HEIGHT };



		CUI::Render(fDeltaTime);


		break;

	case PT_BULLET_DIST:

		if (GET_SINGLE(CSceneManager)->GetPlayer()->IsBulletDistCycle())
		{
			CUI::Render(fDeltaTime);

		}

		break;

	case PT_DOUBLE_JUMP:

		if (GET_SINGLE(CSceneManager)->GetPlayer()->IstDoubleJumpCycle())
		{
			CUI::Render(fDeltaTime);

		}
		break;

	case PT_TRIPLE_UP:

		if (GET_SINGLE(CSceneManager)->GetPlayer()->IsTripleUpCycle())
		{
			CUI::Render(fDeltaTime);

		}
		break;


	default:
		CUI::Render(fDeltaTime);

	}

}

CUIPanel * CUIPanel::Clone()
{
	return new CUIPanel(*this);
}

void CUIPanel::HitStart(CCollider * pSrc, CCollider * pDest)
{
}

void CUIPanel::HitStay(CCollider * pSrc, CCollider * pDest)
{
}

void CUIPanel::HitEnd(CCollider * pSrc, CCollider * pDest)
{
}
