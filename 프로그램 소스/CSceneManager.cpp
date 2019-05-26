#include "CSceneManager.h"
#include "CLayer.h"
#include "CCreateManager.h"
#include "CObj.h"

 // SCENE

#include "CInGame1.h"
#include "CInGame2.h"
#include "CStartScene.h"
#include "CEndScene.h"
#include "CInput.h"


#include <algorithm>

#include "CMonster.h"



DEFINITION_SINGLE(CSceneManager);

CSceneManager::CSceneManager()
{
	m_pScene = NULL;
	m_pNextScene = NULL;
	m_pPlayer = NULL;




	FILE* pFile = NULL;

	fopen_s(&pFile, "Score.sc", "rb");


	if (pFile)
	{
		int iSize = 0;

		fread(&iSize, 4, 1, pFile);

		// 개수만큼 읽는다.

		for (int i = 0; i < iSize; ++i)
		{

			// 이름의 길이를 저장

			int cnt = 0;

			fread(&cnt, 4, 1, pFile);


			//string -> array

			char arr[6];

			fill_n(arr, 6, NULL);

			// 이름의 길이 만큼 저장

			fread(arr, 1, cnt, pFile);

			// 점수를 저장

			int score = 0;

			fread(&score, 4, 1, pFile);



			// 이 정보를 바탕으로 데입

			m_vecScore.push_back(SCORE(arr, score));
		}


		fclose(pFile);

	}

	sort(m_vecScore.begin(), m_vecScore.end(), ScoreSort);
}


CSceneManager::~CSceneManager()
{
	SAFE_DELETE(m_pScene);
	SAFE_DELETE(m_pNextScene);
	SAFE_DELETE(m_pPlayer);



	FILE* pFile = NULL;

	fopen_s(&pFile, "Score.sc", "wb");

	// 점수 저장

	int iSize = m_vecScore.size();

	fwrite(&iSize, 4, 1, pFile);

	// 개수만큼 저장

	for (int i = 0; i < iSize; ++i)
	{

		// 이름의 길이를 저장

		int cnt = m_vecScore[i].m_strName.size();

		fwrite(&cnt, 4, 1, pFile);


		//string -> array

		char arr[6];
		
		fill_n(arr, 6, NULL);

		strcpy_s(arr, m_vecScore[i].m_strName.c_str());

		// 이름의 길이 만큼 저장

		fwrite(arr, 1, cnt, pFile);

		// 점수를 저장

		int score = m_vecScore[i].m_iScore;

		fwrite(&score, 4, 1, pFile);
	}


	fclose(pFile);

}

bool CSceneManager::ScoreSort(const SCORE & tSrc, const SCORE tDest)
{
	return tSrc.m_iScore > tDest.m_iScore;
}

void CSceneManager::ErasePlayer()
{
	SAFE_DELETE(m_pPlayer);
}

void CSceneManager::CreateInform(BUTTON_TYPE eType)
{
	// 패널에다가 인포정보를 넣고, 마우스도 넣어준다. 좌우 도

	list<CObj*>& PanelList = GetPanelList();


	switch (eType)
	{
	case BT_METHOD:

		PanelList.push_back(FIND_OBJECT("MethodInform")->Clone());

		break;

	case BT_RANK:

		PanelList.push_back(FIND_OBJECT("RankInform")->Clone());

		break;
	}



	PanelList.push_back(FIND_OBJECT("ArrowLeft")->Clone());
	PanelList.push_back(FIND_OBJECT("ArrowRight")->Clone());
	PanelList.push_back(FIND_OBJECT("Mouse")->Clone());

	// Panel리스트를 킨다는 소리는 UI에 있는 것을 박스로 보낸다는 의미.


	LayerSwitch("PanelLayer", true);
}

void CSceneManager::EraseInform()
{
}

void CSceneManager::ObjMoveToBox(const string & strTag)
{
	list<CObj*>& List = m_pScene->FindLayer(strTag)->GetList();

	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = List.end();

	for (iter = List.begin(); iter != iterEnd; ++iter)
	{
		m_BoxList.push_back(*iter);
	}

	List.clear();
}

void CSceneManager::ObjMoveToLayer(const string & strTag)
{
	list<CObj*>& List = m_pScene->FindLayer(strTag)->GetList();

	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_BoxList.end();

	for (iter = m_BoxList.begin(); iter != iterEnd; ++iter)
	{
		List.push_back(*iter);
	}

	m_BoxList.clear();


}

void CSceneManager::AddScore(SCORE tScore)
{
	m_vecScore.push_back(tScore);

	
	sort(m_vecScore.begin(), m_vecScore.end(), ScoreSort);
}

vector<SCORE>& CSceneManager::GetScoreVec()
{
	return m_vecScore;
}

void CSceneManager::SetPlayer(CPlayer * pPlayer)
{
	m_pPlayer = pPlayer;
}

CPlayer * CSceneManager::GetPlayer() const
{
	return m_pPlayer;
}

bool CSceneManager::Init()
{
	CreateScene<CStartScene>(ST_CURRENT);

	return true;
}

void CSceneManager::Input(float fDeltaTime)
{
	if (KEYDOWN("StartScene"))
	{
		switch (m_pScene->GetScene())
		{
		case S_START:
			break;

		case S_INGAME1:
		case S_INGAME2:
		case S_END:

			StartScene();

			break;
		}
	}

	if (KEYDOWN("InGame1"))
	{

		switch (m_pScene->GetScene())
		{
		case S_INGAME1:

			break;

		case S_START:
		case S_INGAME2:
		case S_END:

			InGame1();

			break;
		}

	}


	if (KEYDOWN("InGame2"))
	{

		switch (m_pScene->GetScene())
		{
		case S_INGAME2:
			break;

		case S_INGAME1:
		case S_START:
		case S_END:

			InGame2();

			break;
		}
	}



	if (m_pNextScene)
	{
		SAFE_DELETE(m_pScene);

		m_pScene = m_pNextScene;

		m_pNextScene = NULL;


		switch (m_pScene->GetScene())
		{
		case S_START:
			SAFE_DELETE(m_pPlayer);

			break;


		case S_INGAME2:
		case S_INGAME1:

			CMonster::m_iMonster = 0;


			break;

		case S_END:
			break;
		}


	}


	


	// 장면 전환

	m_pScene->Input(fDeltaTime);
}

void CSceneManager::Collision(float fDeltaTime)
{
	m_pScene->Collision(fDeltaTime);

}

void CSceneManager::Update(float fDeltaTime)
{
	m_pScene->Update(fDeltaTime);

}

void CSceneManager::Render(float fDeltaTime)
{
	m_pScene->Render(fDeltaTime);

}

void CSceneManager::StartScene()
{
	CreateScene<CStartScene>(ST_NEXT);

}

void CSceneManager::InGame1()
{
	CreateScene<CInGame1>(ST_NEXT);

}

void CSceneManager::InGame2()
{
	CreateScene<CInGame2>(ST_NEXT);

}

void CSceneManager::EndScene()
{
	CreateScene<CEndScene>(ST_NEXT);

}

SCENE CSceneManager::GetScene() const
{
	return m_pScene->GetScene();
}

list<class CObj *>& CSceneManager::GetDefaultList()
{
	return m_pScene->FindLayer("DefaultLayer")->GetList();
}

list<class CObj*>& CSceneManager::GetUIList()
{
	return m_pScene->FindLayer("UILayer")->GetList();

}

list<class CObj*>& CSceneManager::GetPanelList()
{
	return m_pScene->FindLayer("PanelLayer")->GetList();

}

void CSceneManager::LayerSwitch(const string & strTag, bool enable)
{
	m_pScene->FindLayer(strTag)->SetEnable(enable);
}
