#ifndef _CMATH_H_
#define _CMATH_H_
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
	float cos_look[360];
	float sin_look[360];

};
#endif