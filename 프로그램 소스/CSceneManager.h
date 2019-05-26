#pragma once

#include "Game.h"

class CSceneManager
{
	DECLARE_SINGLE(CSceneManager);

private:
	class CScene* m_pScene;
	class CScene* m_pNextScene;
	class CPlayer* m_pPlayer;

	vector<SCORE> m_vecScore;


	// 박스

	list<class CObj*> m_BoxList;


private:
	template<typename T>
	T* CreateScene(SCENE_TYPE eType)
	{
		T* pScene = new T;

		if (!pScene->Init())
		{
			SAFE_DELETE(pScene);
			return NULL;
		}


		switch (eType)
		{
		case ST_CURRENT:

			SAFE_DELETE(m_pScene);

			m_pScene = pScene;

			break;

		case ST_NEXT:

			SAFE_DELETE(m_pNextScene);

			m_pNextScene = pScene;

			break;
		}


		return pScene;
	}




	// score sort

	static bool ScoreSort(const SCORE& tSrc, const SCORE tDest);


public:
	void ErasePlayer();

	void CreateInform(BUTTON_TYPE eType);
	void EraseInform();

	void ObjMoveToBox(const string& strTag);
	void ObjMoveToLayer(const string& strTag);


	void AddScore(SCORE tScore);


	vector<SCORE>& GetScoreVec();

	void SetPlayer(class CPlayer* pPlayer);
	class CPlayer* GetPlayer() const;


	bool Init();
	void Input(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Update(float fDeltaTime);
	void Render(float fDeltaTime);


	// 씬
	
	void StartScene();
	void InGame1();
	void InGame2();
	void EndScene();

	SCENE GetScene() const;


	// Layer 가져오기

	list<class CObj*>& GetDefaultList();
	list<class CObj*>& GetUIList();
	list<class CObj*>& GetPanelList();

	void LayerSwitch(const string& strTag, bool enable);

};

