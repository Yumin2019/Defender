#include "CTimer.h"

DEFINITION_SINGLE(CTimer);

CTimer::CTimer()
{
}


CTimer::~CTimer()
{
}

void CTimer::Update()
{
	LARGE_INTEGER tTime;

	QueryPerformanceCounter(&tTime);

	m_fDeltaTime = (tTime.QuadPart - m_tTime.QuadPart) / (float)m_tSecond.QuadPart;

	m_tTime = tTime;
}

bool CTimer::Init()
{
	QueryPerformanceCounter(&m_tTime);
	QueryPerformanceFrequency(&m_tSecond);

	return true;
}

float CTimer::GetDelta() const
{
	return m_fDeltaTime;
}
