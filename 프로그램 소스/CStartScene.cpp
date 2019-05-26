#include "CStartScene.h"
#include "CPlayer.h"
#include "CLayer.h"
#include "CCreateManager.h"

bool CStartScene::m_bIntro;


CStartScene::CStartScene()
{
}


CStartScene::~CStartScene()
{
}

bool CStartScene::Init()
{
	m_eScene = S_START;

	if (!CScene::Init())
		return false;


	m_Background.push_back(FIND_LAYER("StartScene"));


	// 마우스 및 버튼.


	list<CObj*>& DefaultList = FindLayer("DefaultLayer")->GetList();
	list<CObj*>& UIList = FindLayer("UILayer")->GetList();
	list<CObj*>& PanelList = FindLayer("PanelLayer")->GetList();



	if (!m_bIntro)
	{
		// 인트로가 나온 적이 없다면..

		PanelList.push_back(FIND_OBJECT("Intro")->Clone());

		PlaySound(TEXT("Sound/Intro.wav"), NULL, SND_ASYNC);
	}
	else
	{
		PlaySound(TEXT("Sound/Others.wav"), NULL, SND_ASYNC | SND_LOOP);

		UIList.push_back(FIND_OBJECT("StartButton")->Clone());
		UIList.push_back(FIND_OBJECT("MethodButton")->Clone());
		UIList.push_back(FIND_OBJECT("RankButton")->Clone());
		UIList.push_back(FIND_OBJECT("QuitButton")->Clone());
		UIList.push_back(FIND_OBJECT("Mouse")->Clone());

	}

	return true;
}

void CStartScene::Input(float fDeltaTime)
{
	CScene::Input(fDeltaTime);
}

void CStartScene::Collision(float fDeltaTime)
{
	CScene::Collision(fDeltaTime);

}

void CStartScene::Update(float fDeltaTime)
{
	CScene::Update(fDeltaTime);

	if (!m_bIntro)
	{
		m_fSecond += fDeltaTime;

		if (m_fSecond >= 6.f)
		{
			PlaySound(TEXT("Sound/Others.wav"), NULL, SND_ASYNC | SND_LOOP);

			list<CObj*>& UIList = FindLayer("UILayer")->GetList();

			UIList.push_back(FIND_OBJECT("StartButton")->Clone());
			UIList.push_back(FIND_OBJECT("MethodButton")->Clone());
			UIList.push_back(FIND_OBJECT("RankButton")->Clone());
			UIList.push_back(FIND_OBJECT("QuitButton")->Clone());
			UIList.push_back(FIND_OBJECT("Mouse")->Clone());


			m_bIntro = true;
		}
	}
}

void CStartScene::Render(float fDeltaTime)
{
	CScene::Render(fDeltaTime);

}
