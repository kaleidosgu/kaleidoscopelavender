#ifndef _CMATH_H_
#define _CMATH_H_
#include "MathConstant.h"
class CMath
{
public:
	CMath(void);
	~CMath(void);
	float getCos( unsigned int angle );
	float getSin( unsigned int angle );
private:
	void _caldegree();
	bool _IsAngleValid( unsigned int angle );
private:
	float cos_look[MAX_ANGLE];
	float sin_look[MAX_ANGLE];

};
#endif