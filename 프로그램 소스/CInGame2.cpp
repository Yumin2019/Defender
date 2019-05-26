#include "CInGame2.h"
#include "CPlayer.h"
#include "CLayer.h"
#include "CCreateManager.h"
#include "CSceneManager.h"
#include "CMonster.h"



bool CInGame2::m_bClear;


CInGame2::CInGame2()
{
}


CInGame2::~CInGame2()
{
}

bool CInGame2::Init()
{

	m_bDoor = false;


	m_eScene = S_INGAME2;

	if (!CScene::Init())
		return false;




	m_pPlayer = GET_SINGLE(CSceneManager)->GetPlayer();


	if (!m_pPlayer)
	{
		m_pPlayer = (CPlayer*)FIND_OBJECT("Player")->Clone();
	}

	GET_SINGLE(CSceneManager)->SetPlayer(m_pPlayer);

	list<CObj*>& DefaultList = FindLayer("DefaultLayer")->GetList();
	list<CObj*>& UIList = FindLayer("UILayer")->GetList();
	list<CObj*>& PanelList = FindLayer("PanelLayer")->GetList();


	DefaultList.push_back(m_pPlayer);

	// �������� ����

	DefaultList.push_back(FIND_OBJECT("Stage1")->Clone());





	m_pPlayer->SetPos(100.f, RS_HEIGHT - 300.f);

	m_pPlayer->Update(0.f);

	m_pPlayer->SetFalling(true);

	// üũ����Ʈ

	m_pPlayer->SetCheck(POSITION(60.f, 440.f));


	CObj* pCheck = FIND_OBJECT("CheckPoint")->Clone();

	pCheck->SetPos(1923.f, 356.f);

	DefaultList.push_back(pCheck);



	// ���̾�

	m_pScreen = FIND_LAYER("InGame2-1");

	m_Background.push_back(FIND_LAYER("InGame2-2"));


	// Image



	// UI


	UIList.push_back(FIND_OBJECT("BulletDistText")->Clone());
	UIList.push_back(FIND_OBJECT("DoubleJumpText")->Clone());
	UIList.push_back(FIND_OBJECT("TripleUpText")->Clone());
	UIList.push_back(FIND_OBJECT("ItemSlot")->Clone());

	// �̹���. 
	UIList.push_back(FIND_OBJECT("BombImage")->Clone());
	UIList.push_back(FIND_OBJECT("HomingImage")->Clone());
	UIList.push_back(FIND_OBJECT("SpeedImage")->Clone());
	UIList.push_back(FIND_OBJECT("PlayerImage")->Clone());
	UIList.push_back(FIND_OBJECT("MonsterCount")->Clone());


	UIList.push_back(FIND_OBJECT("Number")->Clone());


	m_pPlayer->Set();





	// ��ֹ�

	CObj* pObs = FIND_OBJECT("Obstacle2")->Clone();

	pObs->SetPos(698.f, 436.f);

	DefaultList.push_back(pObs);


	pObs = FIND_OBJECT("Obstacle1")->Clone();

	pObs->SetPos(1641.f, 435.f);

	DefaultList.push_back(pObs);




	pObs = FIND_OBJECT("Obstacle2")->Clone();

	pObs->SetPos(2044.f, 372.f);

	DefaultList.push_back(pObs);



	pObs = FIND_OBJECT("Obstacle1")->Clone();

	pObs->SetPos(2938.f, 438.f);

	DefaultList.push_back(pObs);





	// ���� ������

	m_iMonster = 0;
	m_iMonsterMax = 20;
	m_fSecond = 0.f;
	m_fSecondLimitTime = 7.f;
	m_bMonsterCycle = true;



	return true;
}

void CInGame2::Input(float fDeltaTime)
{
	CInGameScene::Input(fDeltaTime);
}

void CInGame2::Collision(float fDeltaTime)
{
	CInGameScene::Collision(fDeltaTime);

}

void CInGame2::Update(float fDeltaTime)
{
	CInGameScene::Update(fDeltaTime);

}

void CInGame2::Render(float fDeltaTime)
{
	CInGameScene::Render(fDeltaTime);

}
