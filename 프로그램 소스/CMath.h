#pragma once

#include "Game.h"


class CMath
{
public:


	static bool RectToRect(const _tagPosition& tSrcPos, const _tagPosition& tSrcSize, const _tagPosition& tDestPos, const _tagPosition& tDestSize);

	static float GetAngle(const _tagPosition& tSrcPos, const _tagPosition& tDestPos);

	static float GetDist(const _tagPosition& tSrcPos, const _tagPosition& tDestPos);

};

