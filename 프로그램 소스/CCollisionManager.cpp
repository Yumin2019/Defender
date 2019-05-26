#include "CCollisionManager.h"
#include "CObj.h"
#include "CCollider.h"
#include "CMath.h"


DEFINITION_SINGLE(CCollisionManager);

CCollisionManager::CCollisionManager()
{
}


CCollisionManager::~CCollisionManager()
{
	m_CheckList.clear();
}

bool CCollisionManager::ObjectTypeCheck(OBJECT_TYPE eSrc, OBJECT_TYPE eDest)
{

	//enum OBJECT_TYPE
	//{
	//	OT_PLAYER,
	//	OT_MONSTER,
	//	OT_PLAYER_BULLET,
	//	OT_MONSTER_BULLET,
	//	OT_UI,
	//	OT_DOOR,
	//	OT_CHECK,
	//	OT_OBSTACLE,
	//	OT_MOUSE,
	//	OT_BUTTON,
	//	OT_ITEM
	//};

	// 마우스 도어 스태틱으로 ..

	switch (eSrc)
	{


	case OT_STAGE:

		switch (eDest)
		{
		case OT_PLAYER:
		case OT_PLAYER_BULLET:
		case OT_MONSTER_BULLET:
		case OT_ITEM:
			return true;
		}


		break;
	case OT_PLAYER:
	
		switch (eDest)
		{
		case OT_MONSTER_BULLET:
		case OT_DOOR:
		case OT_CHECK:
		case OT_OBSTACLE:
		case OT_ITEM:
		case OT_STAGE:
			return true;
		}


		break;

	case OT_MONSTER:

		switch (eDest)
		{
		case OT_PLAYER_BULLET:
			return true;
		}

		break;

	case OT_PLAYER_BULLET:

		switch (eDest)
		{
		case OT_MONSTER:
		case OT_MONSTER_BULLET:
		case OT_OBSTACLE:
		case OT_STAGE:

			return true;
		}

		break;

	case OT_MONSTER_BULLET:

		switch (eDest)
		{
		case OT_PLAYER:
		case OT_PLAYER_BULLET:
		case OT_STAGE:
			return true;
		}

		break;

	case OT_DOOR:
	case OT_CHECK:

		switch (eDest)
		{
		case OT_PLAYER:
			return true;
		}

		break;

	case OT_OBSTACLE:

		switch (eDest)
		{
		case OT_PLAYER:
		case OT_PLAYER_BULLET:

			return true;
		}

		break;

	case OT_MOUSE:

		switch (eDest)
		{
		case OT_BUTTON:
			return true;
		}

		break;

	case OT_BUTTON:
		switch (eDest)
		{
		case OT_MOUSE:
			return true;
		}


		break;

	case OT_ITEM:

		switch (eDest)
		{
		case OT_PLAYER:
		case OT_STAGE:

			return true;
		}

		break;
	}
	

	return false;
}

bool CCollisionManager::ColliderTypeCheck(COLLIDER_TYPE eSrc, COLLIDER_TYPE eDest)
{

	/*enum COLLIDER_TYPE
	{
		CT_RECT,
		CT_LEFT,
		CT_RIGHT,
		CT_GRAVITY
	};*/


	switch (eSrc)
	{
	case CT_RECT:

		switch (eDest)
		{
		case CT_RECT:
			return true;
		}

		break;

	case CT_LEFT:
	case CT_RIGHT:

		switch (eDest)
		{
		case CT_GRAVITY:
			return true;
		}


		break;

	case CT_GRAVITY:

		switch (eDest)
		{
		case CT_GRAVITY:
		case CT_LEFT:
		case CT_RIGHT:
			return true;
		}

		break;
	}
	return false;
}

void CCollisionManager::CollisionCheck(CObj * pSrc, CObj * pDest)
{
	// 충돌 리스트

	list<CCollider*>& SrcColliderList = pSrc->GetColliderList();
	list<CCollider*>& DestColliderList = pDest->GetColliderList();

	list<CCollider*>::iterator iter;
	list<CCollider*>::iterator iterEnd = SrcColliderList.end();

	for (iter = SrcColliderList.begin(); iter != iterEnd; ++iter)
	{

		list<CCollider*>::iterator m_iter;
		list<CCollider*>::iterator m_iterEnd = DestColliderList.end();


		for (m_iter = DestColliderList.begin(); m_iter != m_iterEnd; ++m_iter)
		{

			if (ColliderTypeCheck((*iter)->GetColliderType(), (*m_iter)->GetColliderType()))
			{

				if (CMath::RectToRect((*iter)->GetPos(), (*iter)->GetSize(), (*m_iter)->GetPos(), (*m_iter)->GetSize()))
				{
					
					if (!(*iter)->PrevCollision(*m_iter))
					{
						// 처음 충돌


						(*iter)->InsertColliderList(*m_iter);
						(*m_iter)->InsertColliderList(*iter);


						(*iter)->GetObj()->HitStart(*iter, *m_iter);
						(*m_iter)->GetObj()->HitStart(*m_iter, *iter);
					}
					else
					{
						// 충돌중



						(*iter)->GetObj()->HitStay(*iter, *m_iter);
						(*m_iter)->GetObj()->HitStay(*m_iter, *iter);
					}

				}
				else
				{
					if ((*iter)->PrevCollision(*m_iter))
					{
						// 방금 떨어짐.

						(*iter)->EraseColliderList(*m_iter);
						(*m_iter)->EraseColliderList(*iter);



						(*iter)->GetObj()->HitEnd(*iter, *m_iter);
						(*m_iter)->GetObj()->HitEnd(*m_iter, *iter);
					}

					// 아무 것도 아니다.
				}


			}

			// 충돌할 필요가 없다.

		}
	}
	
}

list<class CObj*>& CCollisionManager::GetList()
{
	return m_CheckList;
}

bool CCollisionManager::Init()
{
	return true;
}

void CCollisionManager::Update()
{
	// 충돌 검사.

	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_CheckList.end();

	for (iter = m_CheckList.begin(); iter != iterEnd; ++iter)
	{
		list<CObj*>::iterator m_iter = iter;

		++m_iter;


		for (; m_iter != iterEnd; ++m_iter)
		{
			if (ObjectTypeCheck((*iter)->GetObjectType(), (*m_iter)->GetObjectType()))
			{
				CollisionCheck(*iter, *m_iter);
			}
			// 충돌할 필요가 없다.
		
		}
	}


	m_CheckList.clear();
}
