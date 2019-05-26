#include "CCollider.h"
#include "CObj.h"


CCollider::CCollider()
{



	m_tPos = POSITION(0.f, 0.f);
	m_tSize = POSITION(0.f, 0.f);
	m_tOffset = POSITION(0.f, 0.f);

	m_pObj = NULL;


}

CCollider::CCollider(const CCollider & col)
{

	m_tPos = POSITION(0.f, 0.f);
	m_tSize = col.m_tSize;
	m_tOffset = col.m_tOffset;

	m_eColliderType = col.m_eColliderType;

	m_pObj = NULL;
}


CCollider::~CCollider()
{
	list<CCollider*>::iterator iter;
	list<CCollider*>::iterator iterEnd = m_CollisionList.end();

	for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->EraseColliderList(this);

	}


	m_CollisionList.clear();
}

void CCollider::SetSize(POSITION tSize)
{
	m_tSize = tSize;
}

void CCollider::SetOffset(POSITION tOffset)
{
	m_tOffset = tOffset;
}

void CCollider::SetColliderType(COLLIDER_TYPE eType)
{
	m_eColliderType = eType;
}

void CCollider::SetObj(CObj * pObj)
{
	m_pObj = pObj;
}

POSITION CCollider::GetPos() const
{
	return m_tPos;
}

_SIZE CCollider::GetSize() const
{
	return m_tSize;
}

COLLIDER_TYPE CCollider::GetColliderType() const
{
	return m_eColliderType;
}

CObj * CCollider::GetObj() const
{
	return m_pObj;
}

void CCollider::Update()
{
	m_tPos = m_pObj->GetPos() + m_tOffset;
}

void CCollider::EraseColliderList(CCollider * pCol)
{
	list<CCollider*>::iterator iter;
	list<CCollider*>::iterator iterEnd = m_CollisionList.end();

	for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter)
	{
		if (*iter == pCol)
		{
			m_CollisionList.erase(iter);

			return;
		}
	}
}

void CCollider::InsertColliderList(CCollider * pCol)
{
	m_CollisionList.push_back(pCol);
}

bool CCollider::PrevCollision(CCollider * pCol)
{
	list<CCollider*>::iterator iter;
	list<CCollider*>::iterator iterEnd = m_CollisionList.end();

	for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter)
	{
		if (*iter == pCol)
		{

			return true;
		}
	}


	return false;
}

CCollider * CCollider::Clone()
{
	return new CCollider(*this);
}
