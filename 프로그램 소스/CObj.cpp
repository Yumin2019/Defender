#include "CObj.h"
#include "CCollider.h"
#include "CCore.h"
#include "CScene.h"
#include "CAnimation.h"

CObj::CObj()
{
	


	m_tPos = POSITION(0.f, 0.f);
	m_tSize = POSITION(0.f, 0.f);

	m_pAnimation = NULL;
	m_pTexture = NULL;

	m_tRenderRect = { 0, 0, 0, 0 };


	m_bEnable = true;

}

CObj::CObj(const CObj & obj)
{

	m_tPos = obj.m_tPos;
	m_tSize = obj.m_tSize;
	m_eObjectType = obj.m_eObjectType;
	m_pAnimation = NULL;
	m_pTexture = NULL;

	m_tRenderRect = obj.m_tRenderRect;



	// 텍스처

	if (obj.m_pTexture)
	{
		m_pTexture = obj.m_pTexture;
	}


	m_ColliderList.clear();

	// Collider

	list<class CCollider*>::const_iterator iter;
	list<class CCollider*>::const_iterator iterEnd = obj.m_ColliderList.end();


	for (iter = obj.m_ColliderList.begin(); iter != iterEnd; ++iter)
	{
		CCollider* pCol = (*iter)->Clone();

		pCol->SetObj(this);

		pCol->Update();

		m_ColliderList.push_back(pCol);

	}


	// ANi

		// 오브젝트, ChangeClip FrameSize

	if (obj.m_pAnimation)
	{
		m_pAnimation = obj.m_pAnimation->Clone();

		m_pAnimation->SetObj(this);

		m_pAnimation->ChangeClip();
	}



	m_bEnable = true;



}


CObj::~CObj()
{
	// Collider 

	Safe_Delete_VecList(m_ColliderList);

	// ANi

	SAFE_DELETE(m_pAnimation);
}

void CObj::SetObjectType(OBJECT_TYPE eType)
{
	m_eObjectType = eType;
}

void CObj::SetPos(float x, float y)
{
	m_tPos = POSITION(x, y);
}

void CObj::SetPos(POSITION tPos)
{
	m_tPos = tPos;
}

void CObj::SetSize(float x, float y)
{
	m_tSize = POSITION(x, y);
}

void CObj::SetSize(_SIZE tSize)
{
	m_tSize = tSize;
}

void CObj::SetTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}


void CObj::SetRenderRect(int l, int t, int r, int b)
{
	m_tRenderRect = { l, t, r, b };
}

void CObj::SetAnimation(CAnimation * pAni)
{
	m_pAnimation = pAni;

	pAni->SetObj(this);
}

OBJECT_TYPE CObj::GetObjectType() const
{
	return m_eObjectType;
}

POSITION CObj::GetPos() const
{
	return m_tPos;
}

_SIZE CObj::GetSize() const
{
	return m_tSize;
}

list<class CCollider*>& CObj::GetColliderList()
{
	return m_ColliderList;
}

bool CObj::GetEnable() const
{
	return m_bEnable;
}

float CObj::GetCenterX() const
{
	return m_tPos.x + m_tSize.x / 2.f;
}

float CObj::GetCenterY() const
{
	return m_tPos.y + m_tSize.y / 2.f;
}

POSITION CObj::GetCenter() const
{
	return POSITION(GetCenterX(), GetCenterY());
}

void CObj::Die()
{
	m_bEnable = false;
}

void CObj::AddCollider(_SIZE tSize, POSITION tOffset, COLLIDER_TYPE eType)
{

	//POSITION m_tPos;
	//_SIZE m_tSize;
	//POSITION m_tOffset;

	//COLLIDER_TYPE m_eColliderType;

	//class CObj* m_pObj;


	CCollider* pCol = new CCollider;

	pCol->SetSize(tSize);
	pCol->SetOffset(tOffset);
	pCol->SetColliderType(eType);

	m_ColliderList.push_back(pCol);

	pCol->SetObj(this);

	pCol->Update();
}

void CObj::Input(float fDeltaTime)
{
}

void CObj::Collision(float fDeltaTime)
{
}

void CObj::Update(float fDeltaTime)
{
	// 애니메이션

	if (m_pAnimation)
	{
		m_pAnimation->Update(fDeltaTime);
	}


	// collidre

	list<CCollider*>::iterator iter;
	list<CCollider*>::iterator iterEnd = m_ColliderList.end();

	for (iter = m_ColliderList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Update();
	}
}

void CObj::Render(float fDeltaTime)
{

	D3DXVECTOR3 tCenter = { 0.f, 0.f, 0.f };
	D3DXVECTOR3 tPos = { m_tPos.x - CScene::l, m_tPos.y, 0.f };


	CCore::m_pSprite->Draw(m_pTexture, &m_tRenderRect, &tCenter, &tPos, 0xffffffff);
}

float CObj::GetLeft() const
{
	return m_tPos.x;
}

float CObj::GetRight() const
{
	return m_tPos.x + m_tSize.x;
}

float CObj::GetTop() const
{
	return m_tPos.y;
}

float CObj::GetBottom() const
{
	return m_tPos.y + m_tSize.y;
}
