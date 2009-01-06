#ifndef _CCIRCLE_H_
#define _CCIRCLE_H_
#include "IObject.h"
#include "../graphic/CDrawShape.h"
class CCircle : public IObject
{
public:
	CCircle(void);
	~CCircle(void);
	virtual void Move();
	virtual void Init();
	virtual void Update();
	virtual void Draw();
private:
	int m_nRadius;
public:
	static CDrawShape draw;
};
#endif