#include "CCreateManager.h"
#include "CCore.h"



#include "CAnimation.h"


// OBJECT 
#include "CStage.h"

#include "CUIButton.h"
#include "CUIPanel.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CFrontBullet.h"
#include "CAngleBullet.h"
#include "CDoor.h"
#include "CCheck.h"
#include "CItem.h"
#include "CMouse.h"
#include "CObstacle.h"
#include "CEffect.h"



DEFINITION_SINGLE(CCreateManager);

CCreateManager::CCreateManager()
{
}


CCreateManager::~CCreateManager()
{
	Safe_Delete_Map(m_mapObj);
	Safe_Delete_Map(m_mapLayer);
}

void CCreateManager::ObjectCreate()
{

	CPlayer* m_pPlayer = new CPlayer;

	SetObj(m_pPlayer, L"Texture/PlayerUnit.png", "Player", POSITION(0.f, 0.f), _SIZE(50.f, 46.f), OT_PLAYER, 0, 0, 50, 46);

	m_pPlayer->AddCollider(_SIZE(30.f, 44.f), POSITION(9.f, 7.f), CT_RECT);

	m_pPlayer->AddCollider(_SIZE(40.f, 20.f), POSITION(-5.f, 25.f), CT_LEFT);

	m_pPlayer->AddCollider(_SIZE(40.f, 20.f), POSITION(15.f, 25.f), CT_RIGHT);

	m_pPlayer->AddCollider(_SIZE(35.f, 5.f), POSITION(7.f, 55.f), CT_GRAVITY);





	// Door


	CDoor* pDoor = new CDoor;

	SetObj(pDoor, L"Texture/Door.png", "Door", POSITION(0.f, 0.f), _SIZE(100.f, 100.f), OT_DOOR, 0, 0, 100, 100);

	pDoor->AddCollider(_SIZE(64.f, 64.f), POSITION(18.f, 16.f), CT_RECT);



	// Check Point

	CCheck* pCheck = new CCheck;

	SetObj(pCheck, L"Texture/CheckPoint.png", "CheckPoint", POSITION(0.f, 0.f), _SIZE(100.f, 100.f), OT_CHECK, 0, 0, 100, 100);

	pCheck->AddCollider(_SIZE(34.f, 31.f), POSITION(34.f, 41.f), CT_RECT);


	// Item

	CItem* pItem = new CItem;

	SetObj(pItem, L"Texture/Item.png", "Item", POSITION(0.f, 0.f), _SIZE(50.f, 50.f), OT_ITEM, 0, 0, 0, 0);

	pItem->AddCollider(_SIZE(32.f, 32.f), POSITION(9.f, 7.f), CT_RECT);

	pItem->AddCollider(_SIZE(32.f, 32.f), POSITION(9.f, 7.f), CT_GRAVITY);



	// 장애물

	CObstacle* pObstacle = new CObstacle;

	SetObj(pObstacle, L"Texture/Obstacle2.png", "Obstacle2", POSITION(0.f, 0.f), _SIZE(100.f, 100.f), OT_OBSTACLE, 0, 0, 100, 100);

	pObstacle->AddCollider(_SIZE(86.f, 88.f), POSITION(6.f, 9.f), CT_RECT);



	pObstacle = new CObstacle;

	SetObj(pObstacle, L"Texture/Obstacle1.png", "Obstacle1", POSITION(0.f, 0.f), _SIZE(100.f, 100.f), OT_OBSTACLE, 0, 0, 100, 100);

	pObstacle->AddCollider(_SIZE(100.f ,100.f), POSITION(0.f, 0.f), CT_RECT);

}

void CCreateManager::UICreate()
{


	CUIButton* pButton = new CUIButton;

	SetObj(pButton, L"Texture/Play.png", "StartButton", POSITION(RS_WIDTH / 2.f + 100.f, 0.f + 200.f), _SIZE(250.f, 75.f), OT_BUTTON, 0, 0, 250, 75);

	pButton->AddCollider(_SIZE(250.f, 75.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_START);


	pButton = new CUIButton;

	SetObj(pButton, L"Texture/Method.png", "MethodButton", POSITION(RS_WIDTH / 2.f + 100.f, 80.f + 200.f), _SIZE(250.f, 75.f), OT_BUTTON, 0, 0, 250, 75);

	pButton->AddCollider(_SIZE(250.f, 75.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_METHOD);


	pButton = new CUIButton;

	SetObj(pButton, L"Texture/Rank.png", "RankButton", POSITION(RS_WIDTH / 2.f + 100.f, 160.f + 200.f), _SIZE(250.f, 75.f), OT_BUTTON, 0, 0, 250, 75);

	pButton->AddCollider(_SIZE(250.f, 75.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_RANK);


	pButton = new CUIButton;

	SetObj(pButton, L"Texture/Quit.png", "QuitButton", POSITION(RS_WIDTH / 2.f + 100.f, 240.f + 200.f), _SIZE(250.f, 75.f), OT_BUTTON, 0, 0, 250, 75);

	pButton->AddCollider(_SIZE(250.f, 75.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_QUIT);


	// home & retry

	pButton = new CUIButton;

	SetObj(pButton, L"Texture/HomeButton.png", "HomeButton", POSITION(RS_WIDTH - 300.f, RS_HEIGHT - 200.f), _SIZE(0.f, 0.f), OT_BUTTON, 0, 0, 50, 50);

	pButton->AddCollider(_SIZE(50.f, 50.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_HOME);


	pButton = new CUIButton;

	SetObj(pButton, L"Texture/RetryButton.png", "RetryButton", POSITION(RS_WIDTH - 300.f, RS_HEIGHT - 100.f), _SIZE(250.f, 75.f), OT_BUTTON, 0, 0, 250, 75);

	pButton->AddCollider(_SIZE(250.f, 75.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_RETRY);

	
	// Arrow 좌 우

	
	pButton = new CUIButton;

	SetObj(pButton, L"Texture/ArrowLeft.png", "ArrowLeft", POSITION(60.f, 30.f), _SIZE(100.f, 50.f), OT_BUTTON, 0, 0, 100, 50);

	pButton->AddCollider(_SIZE(100.f, 50.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_ARROW_LEFT);



	pButton = new CUIButton;

	SetObj(pButton, L"Texture/ArrowRight.png", "ArrowRight", POSITION(640.f, 30.f), _SIZE(100.f, 50.f), OT_BUTTON, 0, 0, 100, 50);

	pButton->AddCollider(_SIZE(100.f, 50.f), POSITION(0.f, 0.f), CT_RECT);

	pButton->SetButtonType(BT_ARROW_RIGHT);




	// 인트로 

	CUIPanel* pPanel = new CUIPanel;

	SetEffect(pPanel, "Intro", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

	pPanel->SetPanelType(PT_IMAGE);

	CAnimation* pAni = new CAnimation;

	pAni->AddClip("Intro", L"Texture/Animation/Intro", 2, 6.f, AO_ONCE_DESTROY);

	pPanel->SetAnimation(pAni);


	// 엔딩

	pPanel = new CUIPanel;

	SetEffect(pPanel, "Ending", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

	pPanel->SetPanelType(PT_IMAGE);

	pAni = new CAnimation;

	pAni->AddClip("Ending", L"Texture/Animation/Ending", 3, 5.f, AO_ONCE_DESTROY);

	pPanel->SetAnimation(pAni);


	/*
	
	CEffect* pEffect = new CEffect;

	SetEffect(pEffect, "EffectA", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

	CAnimation* pAni = new CAnimation;

	pAni->AddClip("Effect", L"Texture/Effect/A", 5, 2.f, AO_ONCE_DESTROY);

	pEffect->SetAnimation(pAni);
	
	*/





	// UI

	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/DoubleJumpText.png", "DoubleJumpText", POSITION(5.f, 90.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, 0, 32);

	pPanel->SetPanelType(PT_DOUBLE_JUMP);


	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/BulletDistText.png", "BulletDistText", POSITION(5.f, 50.f + 90.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, 0, 31);

	pPanel->SetPanelType(PT_BULLET_DIST);


	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/TripleUpText.png", "TripleUpText", POSITION(5.f, 100.f + 90.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, 0, 32);

	pPanel->SetPanelType(PT_TRIPLE_UP);




	// 400 - 180   64 간격으로 . 

	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/Item.png", "HomingImage", _SIZE(220.f + 64.f * 0 + 5.f, 25.f), POSITION(0.f, 0.f), OT_UI, 50, 0, 100, 50);

	pPanel->SetPanelType(PT_IMAGE);



	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/Item.png", "BombImage", POSITION(220.f + 64.f * 1 + 5.f, 25.f), _SIZE(0.f, 0.f), OT_UI, 100, 0, 150, 50);

	pPanel->SetPanelType(PT_IMAGE);


	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/Item.png", "SpeedImage", POSITION(220.f + 64.f * 2 + 5.f, 25.f), _SIZE(0.f, 0.f), OT_UI, 150, 0, 200, 50);

	pPanel->SetPanelType(PT_IMAGE);


	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/MonsterCount.png", "MonsterCount", POSITION(RS_WIDTH - 70.f, 75.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, 50, 50);

	pPanel->SetPanelType(PT_IMAGE);


	// 플레이어 이미지

	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/PlayerImage.png", "PlayerImage", POSITION(0.f, 0.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, 48, 59);

	pPanel->SetPanelType(PT_PLAYER_IMAGE);





	// Inform


	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/MethodInform.png", "MethodInform", POSITION(50.f, 50.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, INFORM_WIDTH, INFORM_HEIGHT);

	pPanel->SetPanelType(PT_INFORM);



	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/RankInform.png", "RankInform", POSITION(50.f, 50.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, INFORM_WIDTH, INFORM_HEIGHT);

	pPanel->SetPanelType(PT_SCORE);




	// 아이템 슬롯

	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/ItemSlot.png", "ItemSlot", POSITION(RS_WIDTH / 2.f - 180.f, 20.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, 360, 60);

	pPanel->SetPanelType(PT_IMAGE);


	// 번호

	pPanel = new CUIPanel;

	SetObj(pPanel, L"Texture/Number.png", "Number", POSITION(0.f, 0.f), _SIZE(0.f, 0.f), OT_UI, 0, 0, 0, 0);

	pPanel->SetPanelType(PT_NUMBER);




	// 마우스

	CMouse* pMouse = new CMouse;

	SetObj(pMouse, L"Texture/Mouse.png", "Mouse", POSITION(0.f, 0.f), _SIZE(0.f, 0.f), OT_MOUSE, 0, 0, 25, 32);

	pMouse->AddCollider(_SIZE(3.f, 3.f), POSITION(5.f, 1.f), CT_RECT);


}

void CCreateManager::MonsterCreate()
{

	// ahstmxj

	CMonster* pMonster = new CMonster;

	SetObj(pMonster, L"Texture/Monster1.png", "Monster1", POSITION(0.f, 0.f), _SIZE(250.f, 150.f), OT_MONSTER, 0, 0, 250, 150);

	pMonster->AddCollider(_SIZE(178.f, 50.f), POSITION(28.f, 49.f), CT_RECT);

	pMonster->SetPhysics(false);

	pMonster->SetHp(7);

	pMonster->SetScore(5);

	pMonster->SetBulletTime(3.f);

	pMonster->SetSecondTime(0.5f);

	pMonster->SetSpeed(180.f);



	pMonster = new CMonster;

	SetObj(pMonster, L"Texture/Monster2.png", "Monster2", POSITION(0.f, 0.f), _SIZE(250.f, 150.f), OT_MONSTER, 0, 0, 250, 150);

	pMonster->AddCollider(_SIZE(143.f, 64.f), POSITION(42.f, 37.f), CT_RECT);

	pMonster->SetPhysics(false);

	pMonster->SetHp(9);

	pMonster->SetScore(10);

	pMonster->SetBulletTime(2.f);

	pMonster->SetSecondTime(0.5f);

	pMonster->SetSpeed(230.f);


	pMonster = new CMonster;

	SetObj(pMonster, L"Texture/Monster3.png", "Monster3", POSITION(0.f, 0.f), _SIZE(250.f, 150.f), OT_MONSTER, 0, 0, 250, 150);

	pMonster->AddCollider(_SIZE(143.f, 64.f), POSITION(42.f, 37.f), CT_RECT);

	pMonster->SetPhysics(false);

	pMonster->SetHp(15);

	pMonster->SetScore(15);

	pMonster->SetBulletTime(1.0f);

	pMonster->SetSecondTime(0.5f);

	pMonster->SetSpeed(250.f);


	pMonster = new CMonster;

	SetObj(pMonster, L"Texture/Monster4.png", "Monster4", POSITION(0.f, 0.f), _SIZE(250.f, 150.f), OT_MONSTER, 0, 0, 250, 150);

	pMonster->AddCollider(_SIZE(175.f, 108.f), POSITION(33.f, 23.f), CT_RECT);

	pMonster->SetPhysics(false);

	pMonster->SetHp(19);

	pMonster->SetScore(20);

	pMonster->SetBulletTime(0.5f);

	pMonster->SetSecondTime(0.5f);

	pMonster->SetSpeed(300.f);
}

void CCreateManager::BulletCreate()
{
	CAngleBullet* pAngle = new CAngleBullet;

	SetObj(pAngle, L"Texture/MonsterBullet.png", "MonsterBullet", POSITION(0.f, 0.f), POSITION(80.f, 120.f), OT_MONSTER_BULLET, 0, 0, 80, 120);

	pAngle->AddCollider(_SIZE(48.f, 78.f), POSITION(17.f, 23.f), CT_RECT);

	pAngle->AddCollider(_SIZE(48.f, 78.f), POSITION(17.f, 23.f), CT_GRAVITY);
	
	pAngle->SetHeartTime(2.f);

	



	CFrontBullet* pFront = new CFrontBullet;

	SetObj(pFront, L"Texture/Front.png", "FrontBullet", POSITION(0.f, 0.f), _SIZE(15.f, 20.f), OT_PLAYER_BULLET, 0, 0, 15, 20);

	pFront->AddCollider(_SIZE(11.f, 16.f), POSITION(1.f, 3.f), CT_RECT);
	pFront->AddCollider(_SIZE(11.f, 16.f), POSITION(1.f, 3.f), CT_GRAVITY);

	pFront->SetHeartTime(2.f);


	pAngle = new CAngleBullet;

	SetObj(pAngle, L"Texture/HomingMissile.png", "HomingMissile", POSITION(0.f, 0.f), _SIZE(40.f, 40.f), OT_PLAYER_BULLET, 0, 0, 40, 40);

	pAngle->AddCollider(_SIZE(16.f, 16.f), POSITION(10.f, 13.f), CT_RECT);

	pAngle->AddCollider(_SIZE(16.f, 16.f), POSITION(10.f, 13.f), CT_GRAVITY);

	pAngle->SetHeartTime(2.f);

	pAngle->SetPhysics(false);




	pAngle = new CAngleBullet;

	SetObj(pAngle, L"Texture/Front.png", "AngleBullet", POSITION(0.f, 0.f), _SIZE(15.f, 20.f), OT_PLAYER_BULLET, 0, 0, 15, 20);

	pAngle->AddCollider(_SIZE(11.f, 16.f), POSITION(1.f, 3.f), CT_RECT);
	pAngle->AddCollider(_SIZE(11.f, 16.f), POSITION(1.f, 3.f), CT_GRAVITY);

	pAngle->SetHeartTime(2.f);
	
	pAngle->SetPhysics(false);




	pAngle = new CAngleBullet;

	SetObj(pAngle, L"Texture/Bomb.png", "Bomb", POSITION(0.f, 0.f), _SIZE(0.f, 0.f), OT_PLAYER_BULLET, 0, 0, 186, 400);

	pAngle->SetHeartTime(3.f);

	pAngle->SetSpeed(200.f);

	pAngle->SetAngle(PI / 2.f);


	// 공격용.

	pAngle = new CAngleBullet;

	pAngle->SetTexture(NULL);

	pAngle->SetSize(RS_WIDTH, RS_HEIGHT);

	pAngle->SetObjectType(OT_PLAYER_BULLET);

	pAngle->SetHeartTime(0.1f);

	pAngle->SetSpeed(0.f);

	pAngle->AddCollider(_SIZE(RS_WIDTH, RS_HEIGHT), POSITION(0.f, 0.f), CT_RECT);

	pAngle->SetDamage(20);

	m_mapObj.insert(make_pair("BombBullet", pAngle));


}

void CCreateManager::StageCreate()
{
	CStage* pStage = new CStage;

	SetStage(pStage, POSITION(0.f, 0.f), "Stage1");

	// 1
	pStage->AddCollider(_SIZE(208.f, 32.f), POSITION(243.f, 0.f + 450.f), CT_GRAVITY);

	// 2
	pStage->AddCollider(_SIZE(366.f, 27.f), POSITION(181.f, 35.f + 450.f), CT_GRAVITY);

	// 3
	pStage->AddCollider(_SIZE(1470.f, 86.f), POSITION(0.f, 64.f + 450.f), CT_GRAVITY);

	// 4
	pStage->AddCollider(_SIZE(209.f, 32.f), POSITION(904.f, 0.f + 450.f), CT_GRAVITY);

	// 5
	pStage->AddCollider(_SIZE(368.f, 29.f), POSITION(842.f, 34.f + 450.f), CT_GRAVITY);

	// 6
	pStage->AddCollider(_SIZE(463.f, 19.f), POSITION(1921.f, 0.f + 450.f), CT_GRAVITY);

	// 7
	pStage->AddCollider(_SIZE(947.f, 44.f), POSITION(1854.f, 21.f + 450.f), CT_GRAVITY);

	// 8
	pStage->AddCollider(_SIZE(2422.f, 85.f), POSITION(1579.f, 67.f + 450.f), CT_GRAVITY);

	// 9
	pStage->AddCollider(_SIZE(156.f, 29.f), POSITION(3334.f, 0.f + 450.f), CT_GRAVITY);

	// 10
	pStage->AddCollider(_SIZE(325.f, 33.f), POSITION(3167.f, 32.f + 450.f), CT_GRAVITY);


}

void CCreateManager::LayerCreate()
{
	// 지형 레이어 추가할 것.

	// StartScene

	SetLayer(L"Texture/StartScene.png", "StartScene", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);
	 

	// 인게임 1
	SetLayer(L"Texture/InGame1-1.png", "InGame1-1", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

	SetLayer(L"Texture/InGame1-2.png", "InGame1-2", POSITION(0.f, RS_HEIGHT - 150.f), 0, 0, RS_WIDTH, 150.f);

	// 인게임 2

	SetLayer(L"Texture/InGame2-1.png", "InGame2-1", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

	SetLayer(L"Texture/InGame2-2.png", "InGame2-2", POSITION(0.f, RS_HEIGHT - 150.f), 0, 0, RS_WIDTH, 150.f);



	// EndScene

	// Gameover

	SetLayer(L"Texture/Gameover.png", "Gameover", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

	// Clear

	SetLayer(L"Texture/Clear.png", "Clear", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

}

void CCreateManager::EffectCreate()
{
	CEffect* pEffect = new CEffect;

	SetEffect(pEffect, "EffectA", POSITION(0.f, 0.f), 0, 0, RS_WIDTH, RS_HEIGHT);

	CAnimation* pAni = new CAnimation;

	pAni->AddClip("Effect", L"Texture/Effect/A", 5, 2.f, AO_ONCE_DESTROY);

	pEffect->SetAnimation(pAni);





	pEffect = new CEffect;

	SetEffect(pEffect, "Pang", POSITION(0.f, 0.f), 0, 0, 110, 110);

	pAni = new CAnimation;

	pAni->AddClip("Effect", L"Texture/Effect/Pang", 5, 0.5f, AO_ONCE_DESTROY);

	pEffect->SetAnimation(pAni);


	// 총알 이펙트


	pEffect = new CEffect;

	SetEffect(pEffect, "BulletEffect", POSITION(0.f, 0.f), 0, 0, 78, 78);

	pAni = new CAnimation;

	pAni->AddClip("Effect", L"Texture/Effect/Bullet", 3, 0.3f, AO_ONCE_DESTROY);

	pEffect->SetAnimation(pAni);

}

void CCreateManager::SetEffect(CObj * pObj, const string & strTag, POSITION tPos, int l, int t, int r, int b)
{
	pObj->SetTexture(NULL);

	pObj->SetPos(tPos);

	pObj->SetSize(_SIZE(0.f, 0.f));

	pObj->SetObjectType(OT_UI);

	pObj->SetRenderRect(l, t, r, b);

	m_mapObj.insert(make_pair(strTag, pObj));

}

void CCreateManager::SetObj(CObj * pObj, const wstring & strLink, const string & strTag,
	POSITION tPos, _SIZE tSize, 
	OBJECT_TYPE eType, int l, int t, int r, int b)
{

	LPDIRECT3DTEXTURE9 pTexture = NULL;

	D3DXCreateTextureFromFileEx(CCore::m_pd3dDevice, strLink.c_str(), NULL, NULL, 0, NULL,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, NULL, NULL, NULL, &pTexture);

	pObj->SetTexture(pTexture);

	pObj->SetPos(tPos);

	pObj->SetSize(tSize);

	pObj->SetObjectType(eType);

	pObj->SetRenderRect(l, t, r, b);

	m_mapObj.insert(make_pair(strTag, pObj));
	
	/*

	OBJECT_TYPE m_eObjectType;

	POSITION m_tPos;
	_SIZE m_tSize;

	LPDIRECT3DTEXTURE9 m_pTexture;

	RECT m_tRenderRect;

	list<class CCollider*> m_ColliderList;

	class CAnimation* m_pAnimation;

	bool m_bEnable;

	*/

}

void CCreateManager::SetLayer(const wstring & strLink, const string & strTag,
	POSITION tPos, int l, int t, int r, int b)
{

	D3DXIMAGE_INFO info;

	PBACKGROUND pBack = new BACKGROUND;

	D3DXCreateTextureFromFileEx(CCore::m_pd3dDevice, strLink.c_str(), NULL, NULL, 0, NULL,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, NULL, &info, NULL, &pBack->m_pTexture);

	pBack->m_iHeight = info.Height;
	pBack->m_iWidth = info.Width;


	pBack->m_tPos = tPos;

	pBack->m_tRenderRect = { l, t, r, b };

	m_mapLayer.insert(make_pair(strTag, pBack));

	/*
	int m_iWidth;
int m_iHeight;

LPDIRECT3DTEXTURE9 m_pTexture;
POSITION m_tPos;
RECT m_tRenderRect;

	*/
}

void CCreateManager::SetStage(CStage* pStage, POSITION tPos, const string & strTag)
{

	pStage->SetObjectType(OT_STAGE);

	pStage->SetPos(tPos);

	m_mapObj.insert(make_pair(strTag, pStage));

	/*

	OBJECT_TYPE m_eObjectType;

	POSITION m_tPos;
	_SIZE m_tSize;

	LPDIRECT3DTEXTURE9 m_pTexture;

	RECT m_tRenderRect;

	list<class CCollider*> m_ColliderList;

	class CAnimation* m_pAnimation;

	bool m_bEnable;

	*/



}

CObj * CCreateManager::FindObj(const string & strTag)
{
	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strTag);

	if (iter == m_mapObj.end())
		return NULL;

	return iter->second;
}

PBACKGROUND CCreateManager::FindLayer(const string & strTag)
{
	unordered_map<string, PBACKGROUND>::iterator iter = m_mapLayer.find(strTag);

	if (iter == m_mapLayer.end())
		return NULL;

	return iter->second;
}

bool CCreateManager::Init()
{

	ObjectCreate();

	UICreate();

	MonsterCreate();

	BulletCreate();

	StageCreate();
	
	LayerCreate();

	EffectCreate();

	return true;
}
