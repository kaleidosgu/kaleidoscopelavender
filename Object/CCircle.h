#ifndef _CCIRCLE_H_
#define _CCIRCLE_H_
#include "IObject.h"
#include "../graphic/CDrawShape.h"
struct SDL_Surface;
class CCircle : public IObject
{
public:
	CCircle(SDL_Surface* screen);
	~CCircle(void);
	virtual void Move();
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	void StopUpdate();
	void StartMove();
private:
	int m_nRadius;
	SDL_Surface* m_pScreen;
	bool m_bUpdate;
	bool m_bMove;
public:
	static CDrawShape m_draw;
};
#endif