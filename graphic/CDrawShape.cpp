#include "CDrawShape.h"
#include "ColorDefine.h"
#include "SDL/SDL_image.h"
#include "../video/VideoDefine.h"
CDrawShape::CDrawShape(void)
{
	m_nX = 0;
	m_nY = 0;
	m_nRadius = 0;
}
CDrawShape::~CDrawShape(void)
{
}
void CDrawShape::DrawPixel( SDL_Surface* screen, Uint8 R, Uint8 G, Uint8 B, int x, int y)
{
	switch (screen->format->BytesPerPixel) 
	{
        case 4: 
		{ 
            Uint32 *bufp;
            bufp = ((Uint32 *)screen->pixels) + y*screen->pitch/4 + x;
			*bufp = GetColor32(R,G,B);
        }
        break;
    }
    SDL_UpdateRect(screen, x, y, 1, 1);
}
void CDrawShape::DrawCircle( SDL_Surface *screen, Uint8 R, Uint8 G, Uint8 B)
{
	int x = 0;
	int y = 0;
	const int backre = m_nRadius;
	for( int q = 0; q < backre; q++)
	{
		for( int i = 0; i < 360; i++)
		{
			x = q * m_mathConst.getCos(i) + m_nX;
			y = q * m_mathConst.getSin(i) + m_nY;
			if( x >=0 && y >=0 && (x < SCREEN_WIDTH && y < SCREEN_HEIGHT))
			{
				DrawPixel(screen,R,G,B,x,y);
			}
		}
	}
}
