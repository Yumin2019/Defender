#include "CEndScene.h"
#include "CInGame2.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CCreateManager.h"
#include "CObj.h"
#include "CPlayer.h"
#include "CCore.h"
#include "CLayer.h"

CEndScene::CEndScene()
{
}


CEndScene::~CEndScene()
{
}

bool CEndScene::Init()
{




	m_iIndex = 0;

	fill_n(m_strName, 6, NULL);

	if (!CScene::Init())
		return false;




	list<CObj*>& DefaultList = FindLayer("DefaultLayer")->GetList();
	list<CObj*>& UIList = FindLayer("UILayer")->GetList();
	list<CObj*>& PanelList = FindLayer("PanelLayer")->GetList();




	if (CInGame2::m_bClear)
	{
		// 클리어 화면


		PlaySound(TEXT("Sound/Intro.wav"), NULL, SND_ASYNC);


		m_eEndScene = ES_ENDING;

		// 엔딩 카운드 시작 클리어화면 

		m_Background.push_back(FIND_LAYER("Clear"));

		PanelList.push_back(FIND_OBJECT("Ending")->Clone());

	}
	else
	{
		
		m_Background.push_back(FIND_LAYER("Gameover"));

		// gameover 화면 이니셜 바로 시작.


		m_eEndScene = ES_INITIAL;

		PlaySound(TEXT("Sound/EndScene.wav"), NULL, SND_ASYNC | SND_LOOP);

	}




	return true;
}

void CEndScene::Input(float fDeltaTime)
{
	CScene::Input(fDeltaTime);
}

void CEndScene::Collision(float fDeltaTime)
{
	CScene::Collision(fDeltaTime);

}

void CEndScene::Update(float fDeltaTime)
{
	CScene::Update(fDeltaTime);


	/*
	
	ES_ENDING,
	ES_INITIAL,
	ES_END
	
	*/
	switch (m_eEndScene)
	{
	case ES_ENDING:

		m_fSecond += fDeltaTime;

		if (m_fSecond >= 3.f)
		{
			m_fSecond = 0.f;
			m_eEndScene = ES_INITIAL;

			PlaySound(TEXT("Sound/EndScene.wav"), NULL, SND_ASYNC | SND_LOOP);

			CInGame2::m_bClear = false;

		}

		break;
		

	case ES_INITIAL:


		// 이니셜 입력

		

		// A to Z
		string str = "";

		for (int i = 0; i < 26; ++i)
		{
			char a = 'A' + i;


			if (KEYDOWN((str + a).c_str()) && m_iIndex < 5)
			{
				m_strName[m_iIndex++] = a;

			}
		}

		
		if (KEYDOWN("Backspace"))
		{
			m_iIndex = 0;

			fill_n(m_strName, 6, NULL);
		}

		if (KEYDOWN("Enter") && (m_iIndex != 0))
		{
			m_eEndScene = ES_END;

			// 데이터 저장

			GET_SINGLE(CSceneManager)->AddScore(SCORE(m_strName, GET_SINGLE(CSceneManager)->GetPlayer()->GetScore()));

			// 스코어 패널을 띄워버림.


			list<CObj*>& PanelList = GET_SINGLE(CSceneManager)->GetPanelList();

			PanelList.push_back(FIND_OBJECT("RankInform")->Clone());

			PanelList.push_back(FIND_OBJECT("HomeButton")->Clone());
			PanelList.push_back(FIND_OBJECT("RetryButton")->Clone());

			PanelList.push_back(FIND_OBJECT("Mouse")->Clone());




			// 아직 안 ㅎㅁ.
			
			// 버튼 x

			// 리트리 or home 버튼만.

		}




		break;

	}

}

void CEndScene::Render(float fDeltaTime)
{

	CScene::Render(fDeltaTime);


	switch (m_eEndScene)
	{
	case ES_INITIAL:

		// 자기가 입력한 것을 보여준다.
		
		RECT rc = { 0, 0, 0, 0 };

		CCore::m_pFont->DrawTextA(CCore::m_pSprite, m_strName, -1, &rc, DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));


		break;
	}

}
