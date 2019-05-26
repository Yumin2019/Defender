#include "CInGameScene.h"
#include "CCore.h"
#include "CPlayer.h"
#include "CSceneManager.h"
#include "CCreateManager.h"
#include "CMonster.h"

CInGameScene::CInGameScene() :
	m_pScreen(NULL),
	m_pPlayer(NULL)
{
	m_bDoor = false;
}


CInGameScene::~CInGameScene()
{
}

void CInGameScene::MonsterCreate()
{
	int idx = rand() % 2 + 1;
	string monster = "Monster";

	if (m_eScene == S_INGAME2)
		idx += 2;

	monster += to_string(idx);

	CMonster* pMonster = (CMonster*)FIND_OBJECT(monster)->Clone();

	pMonster->Init();

	GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pMonster);


}

bool CInGameScene::Init()
{
	return true;
}

void CInGameScene::Input(float fDeltaTime)
{
	CScene::Input(fDeltaTime);


}

void CInGameScene::Collision(float fDeltaTime)
{
	CScene::Collision(fDeltaTime);

}

void CInGameScene::Update(float fDeltaTime)
{
	CScene::Update(fDeltaTime);

	// screen


	// layer


	list<PBACKGROUND>::iterator iter;
	list<PBACKGROUND>::iterator iterEnd = m_Background.end();

	for (iter = m_Background.begin(); iter != iterEnd; ++iter)
	{
		// 비율을 구한다.

		float fPercent = m_pPlayer->GetCenterX() / FULL_WIDTH;

		int width = fPercent * (*iter)->m_iWidth;

		// width 를 기준으로 left rigth 설정

		int l = width - RS_WIDTH * 0.5f;
		int r = width + RS_WIDTH * 0.5f;


		if (l < 0)
		{
			l = 0;
			r = RS_WIDTH;
		}

		else if (r > (*iter)->m_iWidth)
		{
			r = (*iter)->m_iWidth;

			l = r - RS_WIDTH;
		}


		(*iter)->m_tRenderRect.left = l;
		(*iter)->m_tRenderRect.right = r;
	}


	// screen 비율

	if (m_pScreen)
	{
		float fCenterX = m_pPlayer->GetCenterX();

		CScene::l = fCenterX - RS_WIDTH * 0.5f;
		int r = l + RS_WIDTH;

		if (CScene::l < 0)
		{
			CScene::l = 0;

			r = RS_WIDTH;
		}

		else if (r > FULL_WIDTH)
		{
			r = FULL_WIDTH;
			l = FULL_WIDTH - RS_WIDTH;
		}


		m_pScreen->m_tRenderRect.left = CScene::l;
		m_pScreen->m_tRenderRect.right = r;
	}



	// 몬스터


	if (m_bMonsterCycle)
	{
		m_fSecond += fDeltaTime;


		if (m_fSecond >= m_fSecondLimitTime)
		{

			m_fSecond -= m_fSecondLimitTime;

			MonsterCreate();

			++m_iMonster;

			if (m_iMonster == m_iMonsterMax)
			{
				m_bMonsterCycle = false;

			

			}
		}

	}


	if (!m_bDoor && !m_bMonsterCycle && CMonster::m_iMonster == 0)
	{
		// Door 생성.

		CObj* pDoor = FIND_OBJECT("Door")->Clone();

		pDoor->SetPos(FULL_WIDTH - 150.f, RS_HEIGHT - 200.f);

		GET_SINGLE(CSceneManager)->GetDefaultList().push_back(pDoor);

		m_bDoor = true;
	}


}

void CInGameScene::Render(float fDeltaTime)
{

	// 플레이어 기준 Backround

	if (m_pScreen)
	{

		D3DXVECTOR3 tCenter = { 0.f, 0.f, 0.f };
		D3DXVECTOR3 tPos = { m_pScreen->m_tPos.x , m_pScreen->m_tPos.y, 0.f };


		CCore::m_pSprite->Draw(m_pScreen->m_pTexture, &m_pScreen->m_tRenderRect, &tCenter, &tPos, 0xffffffff);
	}


	// Layer + obj
	CScene::Render(fDeltaTime);

}
