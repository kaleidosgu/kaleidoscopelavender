#include "CDrawShape.h"
#include "ColorDefine.h"
#include "SDL/SDL_image.h"
#include "../video/VideoDefine.h"
CDrawShape::CDrawShape(void)
{
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
