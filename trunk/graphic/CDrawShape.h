#ifndef _CDRAWSHAPE_H
#define _CDRAWSHAPE_H
#include "SDL/SDL.h"
#include "../math/CMath.h"
class CDrawShape
{
public:
	CDrawShape(void);
	~CDrawShape(void);
	void DrawPixel( SDL_Surface* screen, Uint8 R, Uint8 G, Uint8 B, int x, int y );
	void DrawCircle( SDL_Surface *screen, Uint8 R, Uint8 G, Uint8 B);
private:
private:
	CMath m_mathConst;
	int m_nX;
	int m_nY;
	int m_nRadius;

};
#endif