#pragma once

#include "Game.h"

class CCreateManager
{
	DECLARE_SINGLE(CCreateManager);

private:
	unordered_map<string, class CObj*> m_mapObj;
	unordered_map<string, PBACKGROUND> m_mapLayer;



private:
	void ObjectCreate();
	void UICreate();
	void MonsterCreate();
	void BulletCreate();
	void StageCreate();
	void LayerCreate();
	void EffectCreate();



	
	void SetEffect(class CObj* pObj, const string& strTag, POSITION tPos, int l, int t, int r, int b);
	void SetObj(class CObj* pObj, const wstring& strLink, const string& strTag, POSITION tPos, _SIZE tSize, OBJECT_TYPE eType,
		int l, int t, int r, int b);
	void SetLayer(const wstring& strLink, const string& strTag, POSITION tPos, int l, int t, int r, int b);
	void SetStage(class CStage* pStage, POSITION tPos, const string& strTag);

	
	

public:
	class CObj* FindObj(const string& strTag);
	PBACKGROUND FindLayer(const string& strTag);


	bool Init();


};

