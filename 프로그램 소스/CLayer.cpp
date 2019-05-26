#include "CLayer.h"
#include "CObj.h"
#include "CCollisionManager.h"

CLayer::CLayer() :
	m_bEnable(true)
{
}

CLayer::~CLayer()
{

	// 플레이어를 제외하고 날린다.

	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if ((*iter)->GetObjectType() == OT_PLAYER)
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			SAFE_DELETE(*iter);
			++iter;
		}
	}


	m_ObjList.clear();

}

list<class CObj*>& CLayer::GetList()
{
	return m_ObjList;
}

bool CLayer::GetEnable() const
{
	return m_bEnable;
}

string CLayer::GetTag() const
{
	return m_strTag;
}

void CLayer::SetTag(const string & strTag)
{
	m_strTag = strTag;
}

void CLayer::SetEnable(bool enable)
{
	m_bEnable = enable;
}

void CLayer::Input(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if ((*iter)->GetEnable())
		{
			(*iter)->Input(fDeltaTime);

			++iter;
		}
		else
		{
			SAFE_DELETE(*iter);
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
	}
}

void CLayer::Collision(float fDeltaTime)
{

	list<CObj*>& CheckList = GET_SINGLE(CCollisionManager)->GetList();


	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetEnable())
		{
			CheckList.push_back(*iter);
		}
	}
}

void CLayer::Update(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if ((*iter)->GetEnable())
		{
			(*iter)->Update(fDeltaTime);

			++iter;
		}
		else
		{
			SAFE_DELETE(*iter);
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
	}
}

void CLayer::Render(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if ((*iter)->GetEnable())
		{
			(*iter)->Render(fDeltaTime);

			++iter;
		}
		else
		{
			SAFE_DELETE(*iter);
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
	}
}
