#pragma once

#include "Game.h"

class CAnimation
{
public:
	CAnimation();
	CAnimation(const CAnimation& ani);
	~CAnimation();


private:

	unordered_map<string, PCLIP> m_mapClip;

	//int m_iFrameX;
	//int m_iFrameY;

	string m_strCurClip;

	PCLIP m_pClip;


	class CObj* m_pObj;



public:
	void SetObj(class CObj* pObj);
	void Update(float fDeltaTime);

	//void AddClip(const string& strTag, int curY, int SizeX, float fAnimationTime, ANIMATION_OPTION eOption);

	void AddClip(const string& strTag, const wstring& FileName, int sizeX, float m_fAnimationTime, ANIMATION_OPTION eOption);

	


	PCLIP FindClip(const string& strTag);

	void ChangeClip();
	void ChangeClip(const string& strTag);

	//void SetFrameSize(int x, int y);


	CAnimation* Clone();

	//	int m_iCurY;
	//int m_iCurX;
	//int m_iSizeX;

	//float m_fAnimationTime;
	//float m_fAnimationLimitTime;

	//ANIMATION_OPTION m_eOption;

};

