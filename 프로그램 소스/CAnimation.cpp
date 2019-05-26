#include "CAnimation.h"
#include "CObj.h"
#include "CCore.h"

CAnimation::CAnimation()
{
}

CAnimation::CAnimation(const CAnimation & ani)
{


	//m_iFrameX = ani.m_iFrameX;
	//m_iFrameY = ani.m_iFrameY;

	m_strCurClip = "";
	m_pClip = NULL;

	m_pObj = NULL;



	// 클립


	m_mapClip.clear();

	unordered_map<string, PCLIP>::const_iterator iter;
	unordered_map<string, PCLIP>::const_iterator iterEnd = ani.m_mapClip.end();

	for (iter = ani.m_mapClip.begin(); iter != iterEnd; ++iter)
	{
		PCLIP pClip = new CLIP;

		*pClip = *iter->second;


		vector<LPDIRECT3DTEXTURE9>  m_vecImage;


		for (int i = 0; i < iter->second->m_vecImage.size(); ++i)
		{
			m_vecImage.push_back(iter->second->m_vecImage[i]);
		}

		(*pClip).m_vecImage = m_vecImage;



		m_mapClip.insert(make_pair(iter->first, pClip));
	}


	// 키 + 값을데입한 것을 넣는다.

	// vector는 따로 데입.
}


CAnimation::~CAnimation()
{
	Safe_Delete_Map(m_mapClip);
}

void CAnimation::SetObj(CObj * pObj)
{
	m_pObj = pObj;
}

void CAnimation::Update(float fDeltaTime)
{

	/*
		int m_iCurY;
	int m_iCurX;
	int m_iSizeX;

	float m_fAnimationTime;
	float m_fAnimationLimitTime;

	ANIMATION_OPTION m_eOption;
	
	*/

	//m_pClip->m_fAnimationTime += fDeltaTime;

	//if (m_pClip->m_fAnimationTime >= m_pClip->m_fAnimationLimitTime)
	//{

	//	m_pClip->m_fAnimationTime -= m_pClip->m_fAnimationLimitTime;

	//	++m_pClip->m_iCurX;

	//	if (m_pClip->m_iCurX == m_pClip->m_iSizeX)
	//	{
	//		switch (m_pClip->m_eOption)
	//		{
	//		case AO_LOOP:
	//			m_pClip->m_iCurX = 0;

	//			break;

	//		case AO_ONCE_DESTROY:
	//			m_pObj->Die();

	//			break;
	//		}
	//	}

	//	// 적용

	//	m_pObj->SetRenderRect(m_pClip->m_iCurX * m_iFrameX, m_pClip->m_iCurY * m_iFrameY,
	//		(m_pClip->m_iCurX + 1) * m_iFrameX, (m_pClip->m_iCurY + 1) * m_iFrameY);
	//}


	m_pClip->m_fAnimationTime += fDeltaTime;

	if (m_pClip->m_fAnimationTime >= m_pClip->m_fAnimationLimitTime)
	{

		m_pClip->m_fAnimationTime -= m_pClip->m_fAnimationLimitTime;

		++m_pClip->m_iCurX;

		if (m_pClip->m_iCurX == m_pClip->m_iSizeX)
		{
			switch (m_pClip->m_eOption)
			{
			case AO_LOOP:
				m_pClip->m_iCurX = 0;

				break;

			case AO_ONCE_DESTROY:
				m_pObj->Die();

				return;
			}
		}

		// 적용

		// 벡터에 있는 사진을 오브젝트에 바로 데입

		m_pObj->SetTexture(m_pClip->m_vecImage[m_pClip->m_iCurX]);
		
	}
}

void CAnimation::AddClip(const string & strTag, const wstring & FileName, int sizeX, float m_fAnimationTime, ANIMATION_OPTION eOption)
{
	/*
	string m_strTag;
	int m_iCurX;
	int m_iSizeX;


	float m_fAnimationTime;
	float m_fAnimationLimitTime;

	vector<LPDIRECT3DTEXTURE9>  m_vecImage;

	ANIMATION_OPTION m_eOption;

	*/


	PCLIP pClip = new CLIP;

	pClip->m_eOption = eOption;

	pClip->m_strTag = strTag;

	pClip->m_iCurX = 0;

	pClip->m_iSizeX = sizeX;

	pClip->m_fAnimationTime = 0.f;

	pClip->m_fAnimationLimitTime = m_fAnimationTime / sizeX;



	for (int i = 0; i < sizeX; ++i)
	{
		wstring str = FileName + to_wstring(i) + L".png";

		LPDIRECT3DTEXTURE9 pTexture = NULL;

		D3DXCreateTextureFromFileEx(CCore::m_pd3dDevice, str.c_str(), NULL, NULL, 0, NULL,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, NULL, NULL, NULL, &pTexture);

		pClip->m_vecImage.push_back(pTexture);

	}

	
	m_mapClip.insert(make_pair(strTag, pClip));


}
//
//void CAnimation::AddClip(const string & strTag, int curY, int SizeX, float fAnimationTime, ANIMATION_OPTION eOption)
//{
//	PCLIP pClip = new CLIP;
//
//	pClip->m_eOption = eOption;
//
//	pClip->m_strTag = strTag;
//
//	pClip->m_iCurX = 0;
//
//	pClip->m_iCurY = curY;
//
//	pClip->m_iSizeX = SizeX;
//
//	pClip->m_fAnimationTime = 0.f;
//	
//	pClip->m_fAnimationLimitTime = fAnimationTime / SizeX;
//
//	m_mapClip.insert(make_pair(pClip->m_strTag, pClip));
//
//	
//		string m_strTag;
//	int m_iCurY;
//	int m_iCurX;
//	int m_iSizeX;
//
//	float m_fAnimationTime;
//	float m_fAnimationLimitTime;
//
//	ANIMATION_OPTION m_eOption;
//	
//	
//}

PCLIP CAnimation::FindClip(const string & strTag)
{
	unordered_map<string, PCLIP>::iterator iter = m_mapClip.find(strTag);

	if (iter == m_mapClip.end())
		return NULL;

	return iter->second;
}

void CAnimation::ChangeClip()
{
	if (m_mapClip.size() == 1)
	{
		ChangeClip(m_mapClip.begin()->first);
	}
}

void CAnimation::ChangeClip(const string & strTag)
{
	if (m_strCurClip == strTag)
		return;


	// 잡고 있던 것이 있으면 놓는다

	/*
	string m_strTag;
	int m_iCurX;
	int m_iSizeX;


	float m_fAnimationTime;
	float m_fAnimationLimitTime;

	vector<LPDIRECT3DTEXTURE9>  m_vecImage;

	ANIMATION_OPTION m_eOption;

	*/


	if (m_pClip)
	{
		m_pClip->m_fAnimationTime = 0.f;
		m_pClip->m_iCurX = 0;
	}


	m_pClip = FindClip(strTag);

	m_strCurClip = m_pClip->m_strTag;

	// 이것을 토대로 적용.

	m_pObj->SetTexture(m_pClip->m_vecImage[m_pClip->m_iCurX]);

}

//void CAnimation::SetFrameSize(int x, int y)
//{
//	m_iFrameX = x;
//	m_iFrameY = y;
//}

CAnimation * CAnimation::Clone()
{
	return new CAnimation(*this);
}
