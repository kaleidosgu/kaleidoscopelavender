#include "CMath.h"
#include <math.h>
#include "MathConstant.h"
CMath::CMath(void)
{
	_caldegree();
}
CMath::~CMath(void)
{
}
void CMath::_caldegree()
{
	for (int ang = 0; ang < 360; ang++)
	{
		// convert ang to radians
		float theta = (float)ang*PI/(float)180;

		// insert next entry into table
		cos_look[ang] = cos(theta);
		sin_look[ang] = sin(theta);

	} // end for ang
}
float CMath::getCos( unsigned int angle )
{
	float value = 0;
	if( _IsAngleValid(angle) )
	{
		value = cos_look[angle];
	}
	return value;
}
float CMath::getSin( unsigned int angle )
{
	float value = 0;
	if( _IsAngleValid(angle) )
	{
		value = sin_look[angle];
	}
	return value;
}
bool CMath::_IsAngleValid( unsigned int angle )
{
	bool bResult = false;
	if( angle < 360 )
	{
		bResult = true;
	}
	return bResult;
}