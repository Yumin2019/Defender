#include "CInput.h"

DEFINITION_SINGLE(CInput);

CInput::CInput() :
	m_pKey(NULL)
{
}


CInput::~CInput()
{
	Safe_Delete_Map(m_mapKey);
}

void CInput::Update()
{
	unordered_map<string, PKEYINFO>::iterator iter;
	unordered_map<string, PKEYINFO>::iterator iterEnd = m_mapKey.end();

	for (iter = m_mapKey.begin(); iter != iterEnd; ++iter)
	{
		int iSize = iter->second->vecKey.size();

		int cnt = 0;

		for (int i = 0; i < iSize; ++i)
		{
			if (GetAsyncKeyState(iter->second->vecKey[i]) & 0x80000000)
				++cnt;

		}

		if (cnt == iSize)
		{
			if (!iter->second->m_bDown && !iter->second->m_bPress)
			{
				iter->second->m_bDown = true;
			}
			else if (iter->second->m_bDown && !iter->second->m_bPress)
			{
				iter->second->m_bDown = false;
				iter->second->m_bPress = true;
			}
		}
		else
		{
			if (iter->second->m_bDown || iter->second->m_bPress)
			{
				iter->second->m_bDown = false;
				iter->second->m_bPress = false;
				iter->second->m_bUp = true;
			}
			else if (iter->second->m_bUp)
				iter->second->m_bUp = false;
		}
	}
}

bool CInput::Init()
{

	AddKey('A', "Attack");
	AddKey('W', "AttackUp");
	AddKey('E', "HomingMissile");
	AddKey('R', "Bomb");


	// 이동

	AddKey(VK_LEFT, "MoveLeft");
	AddKey(VK_RIGHT, "MoveRight");
	AddKey(VK_SPACE, "Jump");



	// 이니셜

	// A to Z

	for (int i = 0; i < 26; ++i)
	{
		string str = "";

		char a = 'A' + i;

		AddKey(a, (str + a).c_str());
	}

	// 엔더

	AddKey(VK_RETURN, "Enter");
	AddKey(VK_BACK, "Backspace");


	// 기능키

	AddKey(VK_F1, "Cheat");
	AddKey(VK_F2, "Upgrade");
	AddKey(VK_F3, "Degrade");
	AddKey(VK_F4, "StartScene");
	AddKey(VK_F5, "InGame1");
	AddKey(VK_F6, "InGame2");


	// 아이템 추가 키 



	// E 호밍, R 핵탄두..

	AddKey(VK_LCONTROL, 'E', "AddHoming");
	AddKey(VK_LCONTROL, 'R', "AddBomb");

	// 아이템 사용 

	AddKey(VK_LCONTROL, 'B', "BulletDist");
	AddKey(VK_LCONTROL, 'T', "TripleUp");
	AddKey(VK_LCONTROL, 'D', "DoubleJump");



	AddKey(VK_LBUTTON, "MouseLButton");

	return true;
}

PKEYINFO CInput::FindKey(const string & strTag)
{
	unordered_map<string, PKEYINFO>::iterator iter = m_mapKey.find(strTag);

	if (iter == m_mapKey.end())
		return NULL;

	return iter->second;
}

bool CInput::KeyDown(const string & strTag)
{

	PKEYINFO pKey = FindKey(strTag);

	return pKey->m_bDown;
}

bool CInput::KeyPress(const string & strTag)
{
	PKEYINFO pKey = FindKey(strTag);

	return pKey->m_bPress;
}

bool CInput::KeyUp(const string & strTag)
{
	PKEYINFO pKey = FindKey(strTag);

	return pKey->m_bUp;
}
