#include "CScene.h"
#include "CLayer.h"
#include "CCore.h"

int CScene::l;


CScene::CScene()
{
}


CScene::~CScene()
{
	Safe_Delete_VecList(m_LayerList);
}

SCENE CScene::GetScene() const
{
	return m_eScene;
}

CLayer * CScene::FindLayer(const string & strTag)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
			return *iter;
	}


	return NULL;
}

CLayer * CScene::CreateLayer(const string & strTag)
{
	CLayer* pLayer = new CLayer;

	pLayer->SetTag(strTag);

	m_LayerList.push_back(pLayer);

	return pLayer;
}

bool CScene::Init()
{
	m_fSecond = 0.f;
	m_fSecondLimitTime = 0.f;


	CreateLayer("DefaultLayer");
	CreateLayer("UILayer");
	CreateLayer("PanelLayer");

	return true;
}

void CScene::Input(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetEnable())
		{
			(*iter)->Input(fDeltaTime);
		}
		else
		{
			Safe_Delete_VecList((*iter)->GetList());
		}
	}
}

void CScene::Collision(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetEnable())
		{
			(*iter)->Collision(fDeltaTime);
		}
		else
		{
			Safe_Delete_VecList((*iter)->GetList());
		}
	}
}

void CScene::Update(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetEnable())
		{
			(*iter)->Update(fDeltaTime);
		}
		else
		{
			Safe_Delete_VecList((*iter)->GetList());
		}
	}
}

void CScene::Render(float fDeltaTime)
{

	// 백그라운드

	{
		list<PBACKGROUND>::iterator iter;
		list<PBACKGROUND>::iterator iterEnd = m_Background.end();

		for (iter = m_Background.begin(); iter != iterEnd; ++iter)
		{

			D3DXVECTOR3 tCenter = { 0.f, 0.f, 0.f };
			D3DXVECTOR3 tPos = { (*iter)->m_tPos.x , (*iter)->m_tPos.y, 0.f };


			CCore::m_pSprite->Draw((*iter)->m_pTexture, &(*iter)->m_tRenderRect, &tCenter, &tPos, 0xffffffff);


		}



	}

	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetEnable())
		{
			(*iter)->Render(fDeltaTime);
		}
		else
		{
			Safe_Delete_VecList((*iter)->GetList());
		}
	}
}
