#pragma once

#include "Game.h"

class CTimer
{
	DECLARE_SINGLE(CTimer);

private:
	LARGE_INTEGER m_tTime, m_tSecond;

	float m_fDeltaTime;

public:
	void Update();
	bool Init();

	float GetDelta() const;
};

