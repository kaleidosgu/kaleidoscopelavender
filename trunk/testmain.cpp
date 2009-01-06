#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "graphic/CDrawShape.h"
#include "video/VideoDefine.h"
#include "Object/CCircle.h"
#include <string>
#include <cstdlib>
#include <vector>
//Screen attributes
#include "graphic/ColorDefine.h"
CCircle* circle;
Uint8 color1 = 0;
Uint8 color2 = 0;
Uint8 color3 = 0;

CDrawShape drawShape;
SDL_Surface *screen = NULL;
std::vector < CCircle* > m_vec;
//The event structure that will be used
SDL_Event event;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;    
    }
	//circle = new CCircle( screen );
    
    //Set the window caption
    SDL_WM_SetCaption( "Event test", NULL );
    
	srand( SDL_GetTicks() );
    //If everything initialized fine
    return true;
}

void clean_up()
{    
    //Quit SDL
    SDL_Quit();    
	for(std::vector < CCircle* >::iterator it = m_vec.begin(); it != m_vec.end(); ++it)
	{
		CCircle* tc = (*it);
		delete tc;
	}
	m_vec.clear();
}

int main( int argc, char* args[] )
{
    //Make sure the program waits for a quit
    bool quit = false;
    
    //Initialize
    if( init() == false )
    {
        return 1;    
    }
        
	CCircle* pLast = 0;
    //While the user hasn't quit
    while( quit == false )
    {
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
		for(std::vector < CCircle* >::iterator it = m_vec.begin(); it != m_vec.end(); ++it)
		{
			CCircle* tc = (*it);
			tc->Move();
			tc->Draw();
		}
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {			
			if( event.type == SDL_MOUSEBUTTONDOWN )
			{
				CCircle* newC = new CCircle(screen);
				m_vec.push_back(newC);
				if( event.button.button == SDL_BUTTON_LEFT )
				{
					newC->SetPos(event.button.x,event.button.y);
				}
				color1 = rand() % 255;
				color2 = rand() % 255;
				color3 = rand() % 255;
				pLast = newC;
			}
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }    
        }
		if( event.button.state == SDL_PRESSED )
		{
			for(std::vector < CCircle* >::iterator it = m_vec.begin(); it != m_vec.end(); ++it)
			{
				CCircle* tc = (*it);
				tc->Update();
			}
		}
		else if( event.button.state == SDL_RELEASED)
		{
			if( pLast )
			{
				pLast->StopUpdate();
				pLast->StartMove();
				pLast = 0;
			}
		}
		//Apply the surface to the screen    
		//Update the screen
		if( SDL_Flip( screen ) == -1 )
		{
			return 1;    
		}
    }
    
    //Free the surface and quit SDL
    clean_up();
        
    return 0;    
}
