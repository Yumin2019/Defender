#include "CMath.h"




bool CMath::RectToRect(const _tagPosition & tSrcPos, const _tagPosition & tSrcSize,
	const _tagPosition & tDestPos, const _tagPosition & tDestSize)
{
	float srcL = tSrcPos.x;
	float srcR = tSrcPos.x + tSrcSize.x;

	float srcT = tSrcPos.y;
	float srcB = tSrcPos.y + tSrcSize.y;

	float destL = tDestPos.x;
	float destR = tDestPos.x + tDestSize.x;

	float destT = tDestPos.y;
	float destB = tDestPos.y + tDestSize.y;

	if (srcL > destR)
		return false;

	else if (srcR < destL)
		return false;

	else if (srcT > destB)
		return false;

	else if (srcB < destT)
		return false;

	return true;
}

float CMath::GetAngle(const _tagPosition & tSrcPos, const _tagPosition & tDestPos)
{
	float width = tDestPos.x - tSrcPos.x;

	float height = tDestPos.y - tSrcPos.y;

	float fDist = sqrt(width * width + height * height);


	float fAngle = acosf(width / fDist);

	if (tSrcPos.y > tDestPos.y)
	{
		fAngle = PI * 2.f - fAngle;
	}


	return fAngle;

}

float CMath::GetDist(const _tagPosition & tSrcPos, const _tagPosition & tDestPos)
{

	float width = tDestPos.x - tSrcPos.x;

	float height = tDestPos.y - tSrcPos.y;

	return sqrt(width * width + height * height);
}
