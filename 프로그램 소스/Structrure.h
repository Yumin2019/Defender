#pragma once

typedef struct _tagPosition
{
	float x, y;

	_tagPosition() :
		x(0.f),
		y(0.f)
	{}

	_tagPosition(float x, float y) :
		x(x),
		y(y)
	{}

	void operator=(const _tagPosition& tPos)
	{
		x = tPos.x;
		y = tPos.y;
	}

	_tagPosition operator+(const _tagPosition& tPos)
	{
		_tagPosition m_tPos;

		m_tPos.x = tPos.x + x;
		m_tPos.y = tPos.y + y;

		return m_tPos;
	}
}POSITION, _SIZE;


typedef struct _tagBackground
{
	int m_iWidth;
	int m_iHeight;

	LPDIRECT3DTEXTURE9 m_pTexture;
	POSITION m_tPos;
	RECT m_tRenderRect;

}BACKGROUND, *PBACKGROUND;


//typedef struct _tagAnimation
//{
//
//	string m_strTag;
//	int m_iCurY;
//	int m_iCurX;
//	int m_iSizeX;
//
//	float m_fAnimationTime;
//	float m_fAnimationLimitTime;
//
//	ANIMATION_OPTION m_eOption;
//
//}CLIP, *PCLIP;

typedef struct _tagAnimation2
{
	string m_strTag;
	int m_iCurX;
	int m_iSizeX;


	float m_fAnimationTime;
	float m_fAnimationLimitTime;

	vector<LPDIRECT3DTEXTURE9>  m_vecImage;

	ANIMATION_OPTION m_eOption;


}CLIP, *PCLIP;


typedef struct _tagScore
{
	string m_strName;

	int m_iScore;

	_tagScore(string Name, int score) :
		m_strName(Name),
		m_iScore(score)
	{}
	
}SCORE;