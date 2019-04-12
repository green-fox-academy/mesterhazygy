#include <iostream>
#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

void drawLolz(int, int, int);
bool init();
void close();

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

void drawLolz( int x, int y, int size)
{
    if (size < 4)
        return;

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 0xFF);
    SDL_RenderDrawLine(gRenderer, x + size/3, y, x + size/3, y + size);
    SDL_RenderDrawLine(gRenderer, x + size/3*2, y, x + size/3*2, y + size);
    SDL_RenderDrawLine(gRenderer, x, y + size/3, x + size, y + size/3);
    SDL_RenderDrawLine(gRenderer, x, y + size/3*2, x + size, y + size/3*2);

    drawLolz(x + size/3, y, size/3);
    drawLolz(x + size/3*2, y + size/3, size/3);
    drawLolz(x + size/3, y + size/3*2, size/3);
    drawLolz(x, y + size/3, size/3);
}

bool init()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    gWindow = SDL_CreateWindow( "Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }
    bool quit = false;
    SDL_Event e;

    while( !quit ) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        drawLolz(0, 0, SCREEN_WIDTH);

        SDL_RenderPresent(gRenderer);
    }

    close();

    return 0;
}