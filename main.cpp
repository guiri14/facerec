#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL ){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }
    //Load image
    SDL_Surface* face = IMG_Load("yalefaces/subject01.normal");
    SDL_PixelFormat *fmt;
    fmt = face->format;
    printf("Pixel bytes: %d\n", fmt->BitsPerPixel);

    SDL_LockSurface(face);
    Uint8 index;
    SDL_Color *color;
    index = *(Uint8 *)face->pixels;
    color = &fmt->palette->colors[index];
    SDL_UnlockSurface(face);
    printf("Pixel color-> Red: %d, Green: %d, Blue: %d. Index: %d\n",
      color->r, color->g, color->b, index);

    screenSurface = SDL_GetWindowSurface( window );
    SDL_BlitSurface(face, NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface( window );
    SDL_Delay( 2000 );

    SDL_DestroyWindow( window );

    SDL_Quit();
    return 0;

}
