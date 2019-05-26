#include "CInGame1.h"
#include "CPlayer.h"
#include "CLayer.h"
#include "CCreateManager.h"
#include "CSceneManager.h"
#include "CMonster.h"

CInGame1::CInGame1()
{
}


CInGame1::~CInGame1()
{
}

bool CInGame1::Init()
{

	CMonster::m_iMonster = 0;
	PlaySound(TEXT("Sound/Stage1.wav"), NULL, SND_ASYNC | SND_LOOP);
	m_bDoor = false;


	m_eScene = S_INGAME1;

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

	// 스테이지 데입

	DefaultList.push_back(FIND_OBJECT("Stage1")->Clone());

	m_pPlayer->Set();



	m_pPlayer->SetPos(100.f, RS_HEIGHT - 300.f);

	m_pPlayer->Update(0.f);

	m_pPlayer->SetFalling(true);

	// 체크포인트

	m_pPlayer->SetCheck(POSITION(60.f, 440.f));


	CObj* pCheck = FIND_OBJECT("CheckPoint")->Clone();

	pCheck->SetPos(1923.f, 356.f);

	DefaultList.push_back(pCheck);


	
	   // 레이어

	m_pScreen = FIND_LAYER("InGame1-1");

	m_Background.push_back(FIND_LAYER("InGame1-2"));


	// Image



	// UI

	UIList.push_back(FIND_OBJECT("BulletDistText")->Clone());
	UIList.push_back(FIND_OBJECT("DoubleJumpText")->Clone());
	UIList.push_back(FIND_OBJECT("TripleUpText")->Clone());
	UIList.push_back(FIND_OBJECT("ItemSlot")->Clone());

	// 이미지. 
	UIList.push_back(FIND_OBJECT("BombImage")->Clone());
	UIList.push_back(FIND_OBJECT("HomingImage")->Clone());
	UIList.push_back(FIND_OBJECT("SpeedImage")->Clone());
	UIList.push_back(FIND_OBJECT("PlayerImage")->Clone());
	UIList.push_back(FIND_OBJECT("MonsterCount")->Clone());


	UIList.push_back(FIND_OBJECT("Number")->Clone());



	 



	// 장애물

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





	// 레벨 디자인

	m_iMonster = 0;
	m_iMonsterMax = 20;
	m_fSecond = 0.f;
	m_fSecondLimitTime = 5.f;
	m_bMonsterCycle = true;



	return true;
}

void CInGame1::Input(float fDeltaTime)
{
	CInGameScene::Input(fDeltaTime);
}

void CInGame1::Collision(float fDeltaTime)
{
	CInGameScene::Collision(fDeltaTime);

}

void CInGame1::Update(float fDeltaTime)
{
	CInGameScene::Update(fDeltaTime);

}

void CInGame1::Render(float fDeltaTime)
{
	CInGameScene::Render(fDeltaTime);

}
