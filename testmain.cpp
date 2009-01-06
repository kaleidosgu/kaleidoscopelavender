#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "graphic/CDrawShape.h"
#include "video/VideoDefine.h"
#include <string>
#include <cstdlib>
//Screen attributes
#include "graphic/ColorDefine.h"

bool bStart = false;
bool bStartMove = false;
Uint8 color1 = 0;
Uint8 color2 = 0;
Uint8 color3 = 0;

CDrawShape drawShape;
//The surfaces
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;

//The event structure that will be used
SDL_Event event;

SDL_Surface *load_image( std::string filename ) 
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    
    //Return the optimized image
    return optimizedImage;
}

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
    
    //Set the window caption
    SDL_WM_SetCaption( "Event test", NULL );
    
	srand( SDL_GetTicks() );
    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the image
    image = load_image( "x.gif" );
    
    //If there was an error in loading the image
    if( image == NULL )
    {
        return false;    
    }    
    //If everything loaded fine
    return true;    
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( image );
    
    //Quit SDL
    SDL_Quit();    
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
    
    //Load the files	
    if( load_files() == false )
    {
        return 1;    
    }
    
    //While the user hasn't quit
    while( quit == false )
    {
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
		if( bStartMove )
		{
			drawShape.move();		
		}
		if( bStart )
		{
			drawShape.DrawCircle(screen,color1,color2,color3);
		}
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {			
			if( event.type == SDL_MOUSEBUTTONDOWN )
			{
				bStart = true;
				if( event.button.button == SDL_BUTTON_LEFT )
				{
					drawShape.SetPos(event.button.x,event.button.y);
				}
				color1 = rand() % 255;
				color2 = rand() % 255;
				color3 = rand() % 255;
				drawShape.InitRadius();
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
			drawShape.AddRadius();
			bStartMove = false;
		}
		else if( event.button.state == SDL_RELEASED)
		{
			bStartMove = true;
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
