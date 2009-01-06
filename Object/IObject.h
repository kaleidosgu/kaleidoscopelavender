#ifndef _IOBJECT_H
#define _IOBJECT_H
#include "../math/CMath.h"
class IObject
{
public:
	IObject(void);
	~IObject(void);
	virtual void Move();
	virtual void SetPos( int x, int y );
	virtual void Draw();
	virtual void Init();
	virtual void Update();
protected:
	int	m_nX;
	int m_nY;
	static CMath m_mathConst;
};
#endif